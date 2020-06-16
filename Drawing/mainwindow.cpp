#include "mainwindow.h"

#include <map>
#include <vector>

#include "Coordinates.h"
#include "FilledPolygon.h"
#include "MultiPoint.h"
#include "Point.h"
#include "SettlementCalculation.h"
#include "ui_mainwindow.h"
using namespace std;

// MAP DATA
MultiPoint *viewPoints = 0;
MultiPoint *recommendation = 0;
MultiFilledPolygon *lakes = 0;
MultiFilledPolygon *bads = 0;
MultiFilledPolygon *swamps = 0;
MultiPoint *dem = 0;
FilledPolygon *protectionObj = 0;
FilledPolygon *awZone = 0;
FilledPolygon *front = 0;
FilledPolygon *zrkZone = 0;
FilledPolygon *targetZone = 0;
SettlementCalculation *sc = 0;
bool flag = false;
bool isShift = false;
/////////
/////////
/// API for DRAWING
void drawRadar(QPainter &painter, Coordinates crd) {
  float x = crd.getX();
  float y = crd.getY();
  QPen linepen4(Qt::black);
  linepen4.setCapStyle(Qt::RoundCap);
  linepen4.setWidth(2);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen4);
  painter.drawLine(x, y, x + 12, y);
  painter.drawLine(x, y, x - 12, y);
  painter.drawLine(x, y, x, y - 25);
  painter.drawLine(x - 12, y, x, y - 25);
  painter.drawLine(x + 12, y, x, y - 25);
  linepen4.setWidth(8);
  painter.setPen(linepen4);
  painter.drawPoint(x, y - 25);
}

void drawRadar(QPainter &painter, Point p) {
  float x = p.getX();
  float y = p.getY();
  QPen linepen4(Qt::black);
  linepen4.setCapStyle(Qt::RoundCap);
  linepen4.setWidth(2);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen4);
  painter.drawLine(x, y, x + 12, y);
  painter.drawLine(x, y, x - 12, y);
  painter.drawLine(x, y, x, y - 25);
  painter.drawLine(x - 12, y, x, y - 25);
  painter.drawLine(x + 12, y, x, y - 25);
  linepen4.setWidth(8);
  painter.setPen(linepen4);
  painter.drawPoint(x, y - 25);
}

void drawPolygon(QPainter &painter, FilledPolygon p, QColor color, int width) {
  QPen linepen4(color);
  linepen4.setCapStyle(Qt::RoundCap);
  linepen4.setWidth(width);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen4);

  float prevX = p.getPoints()[0].getX();
  float prevY = p.getPoints()[0].getY();

  for (size_t i = 1; i < p.getPoints().size(); i++) {
    float curX = p.getPoints()[i].getX();
    float curY = p.getPoints()[i].getY();

    painter.drawLine(prevX, prevY, curX, curY);

    prevX = curX;
    prevY = curY;
  }

  painter.drawLine(p.getStart().getX(), p.getStart().getY(), p.getEnd().getX(),
                   p.getEnd().getY());
}

void drawMultiPolygon(QPainter &painter, MultiFilledPolygon p, QColor color,
                      int width) {
  for (size_t i = 0; i < p.getPolygons().size(); i++) {
    drawPolygon(painter, p.getPolygons()[i], color, width);
  }
}

void drawHeight(QPainter &painter, Point p, QColor color, int width) {
  QPen linepen4(color);
  linepen4.setCapStyle(Qt::RoundCap);
  linepen4.setWidth(width);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen4);
  painter.setFont(QFont("Helvetica", 7, QFont::Bold));

  painter.drawText(QPoint(p.getX() + 5, p.getY() + 5),
                   "  " + QString::fromUtf8(p.getProperty("height").c_str()));
  painter.drawPoint(QPoint(p.getX(), p.getY()));
}

void drawMultiPoint(QPainter &painter, MultiPoint p, QColor color, int width) {
  for (size_t i = 0; i < p.getPoints().size(); i++) {
    drawHeight(painter, p.getPoints()[i], color, width);
  }
}

void drawVisiblePoints(QPainter &painter, MultiPoint p, QColor color,
                       int width) {
  for (size_t i = 0; i < p.getPoints().size(); i++) {
    if (p.getPoints()[i].getProperty("visible").compare("true") == 0) {
      drawHeight(painter, p.getPoints()[i], color, width);
    }
  }
}

////////END
////////EVENTS

void MainWindow::paintEvent(QPaintEvent *event) {
  if (!flag) return;
  QPainter painter(this);
  painter.eraseRect(0, 0, 2000, 2000);

  if (ui->checkBox->checkState() == Qt::Checked) {
    drawMultiPoint(painter, *dem, Qt::black, 4);
  }

  if (ui->checkBox_2->checkState() == Qt::Checked) {
    drawMultiPolygon(painter, *lakes, Qt::blue, 8);
  }

  if (ui->checkBox_3->checkState() == Qt::Checked) {
    drawMultiPolygon(painter, *swamps, Qt::green, 8);
  }

  if (ui->checkBox_4->checkState() == Qt::Checked) {
    drawMultiPolygon(painter, *bads, Qt::black, 8);
  }

  if (ui->checkBox_5->checkState() == Qt::Checked) {
    drawPolygon(painter, *front, Qt::yellow, 10);
  }

  if (ui->checkBox_6->checkState() == Qt::Checked) {
    drawPolygon(painter, *zrkZone, Qt::red, 5);
  }

  if (ui->checkBox_7->checkState() == Qt::Checked) {
    drawPolygon(painter, *targetZone, Qt::black, 5);
  }

  if (ui->checkBox_8->checkState() == Qt::Checked) {
    drawPolygon(painter, *protectionObj, Qt::red, 4);
    drawPolygon(painter, *awZone, Qt::red, 4);
  }

  if (ui->checkBox_9->checkState() == Qt::Checked) {
    drawVisiblePoints(painter, *viewPoints, Qt::red, 10);

    if (recommendation->getPoints().size() == 0) {
      string answear = "|>The target zone is not visible.";
      ui->textEdit_2->clear();
      ui->textEdit_2->setText(QString::fromUtf8(answear.c_str()));
      return;
    }

    for (size_t i = 0; i < recommendation->getPoints().size(); i++) {
      drawRadar(painter, recommendation->getPoints()[i]);
    }
  }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

MultiFilledPolygon *pointsToMFP(vector<FilledPolygon> v) {
  MultiFilledPolygon *rez = new MultiFilledPolygon();

  for (size_t i = 0; i < v.size(); i++) {
    rez->addPolygon(v[i]);
  }
  return rez;
}

MultiPoint *pointsToMP(vector<Point> v) {
  MultiPoint *rez = new MultiPoint();

  for (size_t i = 0; i < v.size(); i++) {
    rez->addPoint(v[i]);
  }

  return rez;
}

MultiPoint *pointsToMP(vector<vector<Point>> v) {
  MultiPoint *rez = new MultiPoint();

  for (size_t j = 0; j < v.size(); j++)
    for (size_t i = 0; i < v[0].size(); i++) {
      rez->addPoint(v[j][i]);
    }

  return rez;
}

FilledPolygon getPolygonFromStr(string str) {
  std::istringstream iss(str);
  std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                   std::istream_iterator<std::string>());

  FilledPolygon fp;

  for (size_t i = 0; i < results.size(); i += 2) {
    if (i < results.size() - 1) {
      fp.addCoordinate(Coordinates(::atof(results[i].c_str()),
                                   ::atof(results[i + 1].c_str())));
    }
  }
  return fp;
}

float floatFromLineEdit(const QLineEdit &line) {
  QString badSoilsQ = line.text();
  std::string badSoils = badSoilsQ.toStdString();

  return ::atof(badSoils.c_str());
}

void MainWindow::on_pushButton_7_clicked() {
  flag = true;

  QString badSoilsQ = ui->lineEdit_12->text();
  std::string badSoils = badSoilsQ.toStdString();

  std::istringstream iss(badSoils);
  std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                   std::istream_iterator<std::string>());

  QString qDem = ui->lineEdit_6->text();
  std::string demPath = qDem.toStdString();

  QString qlenthg = ui->lineEdit_13->text();
  std::string stdlenthg = qlenthg.toStdString();
  size_t demLength = std::stoi(stdlenthg);

  sc = new SettlementCalculation(results[0], results[1], results[2], demPath,
                                 demLength);

  QString qshift = ui->doubleSpinBox->text();
  std::string shift = qshift.toStdString();
  float shiftVal = ::atof(shift.c_str());

  QString objQ = ui->textEdit->toPlainText();
  std::string obj = objQ.toStdString();

  vector<Point> radars = sc->getBestSettlement(
      getPolygonFromStr(obj), floatFromLineEdit(*ui->lineEdit_5),
      floatFromLineEdit(*ui->lineEdit_2), floatFromLineEdit(*ui->lineEdit_3),
      shiftVal, floatFromLineEdit(*ui->lineEdit_7),
      floatFromLineEdit(*ui->lineEdit_4), floatFromLineEdit(*ui->lineEdit_10),
      floatFromLineEdit(*ui->lineEdit_8), floatFromLineEdit(*ui->lineEdit_9),
      floatFromLineEdit(*ui->lineEdit_11), floatFromLineEdit(*ui->lineEdit_14));

  recommendation = pointsToMP(radars);
  dem = pointsToMP(sc->getCore()->getDEM());
  lakes = pointsToMFP(sc->getCore()->getLakes());
  bads = pointsToMFP(sc->getCore()->getBadSoils());
  swamps = pointsToMFP(sc->getCore()->getSwamps());
  protectionObj = new FilledPolygon();
  *protectionObj = sc->getProtectionObj();
  front = new FilledPolygon();
  *front = sc->getFrontView();
  zrkZone = new FilledPolygon();
  *zrkZone = sc->getRadarView();
  targetZone = new FilledPolygon();
  *targetZone = sc->getTCZ();
  viewPoints = pointsToMP(sc->getCoverResult());
  awZone = new FilledPolygon();
  *awZone = sc->getAWZone();

  string log = "";

  for (size_t i = 0; i < radars.size(); i++) {
    log += "\n(";
    std::ostringstream x;
    x << radars[i].getX();
    std::string sX(x.str());
    std::ostringstream y;
    y << radars[i].getY();
    std::string sY(y.str());
    log += sX;
    log += ";";
    log += sY;
    log += ")";
  }

  int delta = floatFromLineEdit(*ui->lineEdit_8) - radars.size();

  if (delta) {
    string answear = "\n|>";

    std::ostringstream osDelta;
    osDelta << delta;
    std::string strDelta(osDelta.str());
    answear += strDelta;
    answear += " radar(s) are not needed.";
    log += answear;
  }
  ui->textEdit_2->clear();
  ui->textEdit_2->setText(QString::fromUtf8(log.c_str()));
  repaint();
}

void MainWindow::on_checkBox_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_2_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_3_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_4_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_5_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_6_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_7_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_8_stateChanged(int arg1) { repaint(); }

void MainWindow::on_checkBox_9_stateChanged(int arg1) { repaint(); }

void scaleAll(float factor, bool isShift) {
  viewPoints->scalingByFactor(factor, isShift);
  recommendation->scalingByFactor(factor, isShift);
  lakes->scalingByFactor(factor, isShift);
  bads->scalingByFactor(factor, isShift);
  swamps->scalingByFactor(factor, isShift);
  dem->scalingByFactor(factor, isShift);
  protectionObj->scalingByFactor(factor, isShift);
  awZone->scalingByFactor(factor, isShift);
  front->scalingByFactor(factor, isShift);
  zrkZone->scalingByFactor(factor, isShift);
  targetZone->scalingByFactor(factor, isShift);
}

void shiftAll(Coordinates delta) {
  viewPoints->minusCoordinates(delta);
  recommendation->minusCoordinates(delta);
  lakes->minusCoordinates(delta);
  bads->minusCoordinates(delta);
  swamps->minusCoordinates(delta);
  dem->minusCoordinates(delta);
  protectionObj->minusCoordinates(delta);
  awZone->minusCoordinates(delta);
  front->minusCoordinates(delta);
  zrkZone->minusCoordinates(delta);
  targetZone->minusCoordinates(delta);
}

void MainWindow::on_pushButton_6_clicked() {
  shiftAll(Coordinates(0, -10));
  repaint();
}

void MainWindow::on_pushButton_5_clicked() {
  shiftAll(Coordinates(0, 10));
  repaint();
}

void MainWindow::on_pushButton_4_clicked() {
  shiftAll(Coordinates(10, 0));
  repaint();
}

void MainWindow::on_pushButton_3_clicked() {
  shiftAll(Coordinates(-10, 0));
  repaint();
  repaint();
}

void MainWindow::on_pushButton_2_clicked() {
  scaleAll(0.8f, isShift);
  repaint();
  repaint();
}

void MainWindow::on_pushButton_clicked() {
  scaleAll(1.2f, isShift);
  repaint();
}

void MainWindow::on_checkBox_10_stateChanged(int arg1) { isShift = !isShift; }

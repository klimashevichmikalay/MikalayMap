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
MultiPoint *recommendation;
MultiPoint *heights;
MultiFilledPolygon *lakes;
MultiFilledPolygon *badSoils;
MultiFilledPolygon *swamps;
FilledPolygon *protectionObj;
FilledPolygon *front;
FilledPolygon *zrkZone;
FilledPolygon *targetZone;
SettlementCalculation *sc;
bool flag = false;
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

////////END
////////

void MainWindow::paintEvent(QPaintEvent *event) {
  if (!flag) return;
  QPainter painter(this);
  painter.eraseRect(0, 0, 2000, 2000);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

MultiFilledPolygon *pointsToMP(vector<FilledPolygon> v) {
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

void MainWindow::on_pushButton_7_clicked() {
  flag = true;

  QString badSoilsQ = ui->lineEdit_12->text();
  std::string badSoils = badSoilsQ.toStdString();

  std::istringstream iss(badSoils);
  std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                   std::istream_iterator<std::string>());

  QString qDem = ui->lineEdit_6->text();
  std::string demPath = badSoilsQ.toStdString();

  QString qlenthg = ui->lineEdit_13->text();
  std::string stdlenthg = qlenthg.toStdString();
  size_t demLength = std::stoi(stdlenthg);

  sc = new SettlementCalculation(results[0], results[1], results[2], demPath,
                                 demLength);

  vector<Point> recommendation = sc->getBestSettlement();

  repaint();

  /*// MAP DATA
MultiPoint *recommendation;
MultiPoint *heights;
MultiFilledPolygon *lakes;
MultiFilledPolygon *badSoils;
MultiFilledPolygon *swamps;
FilledPolygon *protectionObj;
FilledPolygon *front;
FilledPolygon *zrkZone;
FilledPolygon *targetZone;
SettlementCalculation *sc;
bool flag = false;
   */

  /* vector<Point> getBestSettlement(
       FilledPolygon protectionObject, float antennaHeight, float maxAngle,
       float minAngle, float shifAngle, const float flightAltitude,
       const float potentialRange, const float AWRange, size_t radarsNum,
       float ZRKRange, size_t frontWidth, float impactAngle)*/
}

void MainWindow::on_checkBox_stateChanged(int arg1) {}

void MainWindow::on_checkBox_2_stateChanged(int arg1) {}

void MainWindow::on_checkBox_3_stateChanged(int arg1) {}

void MainWindow::on_checkBox_4_stateChanged(int arg1) {}

void MainWindow::on_checkBox_5_stateChanged(int arg1) {}

void MainWindow::on_checkBox_6_stateChanged(int arg1) {}

void MainWindow::on_checkBox_7_stateChanged(int arg1) {}

void MainWindow::on_checkBox_8_stateChanged(int arg1) {}

void MainWindow::on_checkBox_9_stateChanged(int arg1) {}

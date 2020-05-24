#include "mainwindow.h"

#include <vector>

#include "ui_mainwindow.h"

using namespace std;

void drawRadar(QPainter &painter, int x, int y);

void drawHeights(QPainter &painter) {
  painter.setFont(QFont("Helvetica", 7, QFont::Bold));

  for (int j = 0; j < 800; j += 50) {
    for (int i = 0; i < 800; i += 50) {
      if (j >= 200 && j < 300 && i >= 250 && i <= 650) {
        painter.drawText(QPoint(i + 5, j + 5), " " + QString::number(9999));
        continue;
      }

      painter.drawText(QPoint(i + 5, j + 5), " " + QString::number(100));
    }
  }
}

void drawHeightsPoints(QPainter &painter) {
  QPen linepen(Qt::black);
  linepen.setCapStyle(Qt::RoundCap);
  linepen.setWidth(6);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen);

  for (int i = 0; i < 800; i += 50) {
    for (int j = 0; j < 800; j += 50) {
      painter.drawPoint(i, j);
    }
  }
}

void drawH(QPainter &painter) {
  QPen linepen(Qt::black);
  linepen.setCapStyle(Qt::RoundCap);
  linepen.setWidth(6);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen);
  drawHeights(painter);
  drawHeightsPoints(painter);
}

void drawLakes(QPainter &painter) {
  QPen linepen(Qt::blue);
  linepen.setCapStyle(Qt::RoundCap);
  linepen.setWidth(6);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen);
  painter.drawRect(175, 300, 75, 200);
}

void drawSwamps(QPainter &painter) {
  QPen linepen(Qt::green);
  linepen.setCapStyle(Qt::RoundCap);
  linepen.setWidth(6);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen);

  painter.drawLine(700, 0, 650, 50);
  painter.drawLine(650, 50, 600, 100);
  painter.drawLine(600, 100, 650, 200);
  painter.drawLine(650, 200, 700, 0);
}

void drawFront(QPainter &painter) {
  // fromt zone
  QPen linepen1(Qt::yellow);
  linepen1.setCapStyle(Qt::RoundCap);
  linepen1.setWidth(8);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen1);

  painter.drawLine(750, 525, 260, 0);
  painter.drawLine(200, 525, 0, 313);

  painter.drawLine(750, 525, 200, 525);
  // painter.drawLine(0, 313, 260, 0);
}

void drawRadarZone(QPainter &painter) {  // radar zone
  QPen linepen2(Qt::red);
  linepen2.setCapStyle(Qt::RoundCap);
  linepen2.setWidth(3);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen2);

  painter.drawLine(750, 525, 563, 324);
  painter.drawLine(200, 525, 12, 325);

  painter.drawLine(750, 525, 200, 525);
}

void drawCoverage(QPainter &painter) {
  // coverage zone
  QPen linepen3(Qt::black);
  linepen3.setCapStyle(Qt::RoundCap);
  linepen3.setWidth(3);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen3);

  painter.drawLine(563, 324, 260, 0);
  painter.drawLine(12, 324, 0, 313);

  painter.drawLine(563, 324, 12, 324);
  // painter.drawLine(0, 313, 260, 0);

  QPen linepen(Qt::red);
  linepen.setCapStyle(Qt::RoundCap);
  linepen.setWidth(6);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen);
}

void drawAW(QPainter &painter) {
  // AW
  painter.drawEllipse(QPoint(475, 525), 50, 50);

  QPen linepen0(Qt::red);
  linepen0.setCapStyle(Qt::RoundCap);
  linepen0.setWidth(15);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen0);
  painter.drawPoint(475, 525);
}

void drawRadarsPlaces(QPainter &painter) {
  // RADARS
  drawRadar(painter, 50, 350);
  drawRadar(painter, 150, 350);
  drawRadar(painter, 150, 450);
}

void drawVisible(QPainter &painter) {
  QPen linepen4(Qt::red);
  linepen4.setCapStyle(Qt::RoundCap);
  linepen4.setWidth(10);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(linepen4);

  for (int j = 0; j < 16; j++)
    for (int i = 0; i < 16; i++) {
      if (i <= 5 && j == 0) painter.drawPoint(i * 50, j * 50);
      if (i <= 5 && j == 1) painter.drawPoint(i * 50, j * 50);
      if (i <= 6 && j == 2) painter.drawPoint(i * 50, j * 50);
      if (i <= 7 && j == 3) painter.drawPoint(i * 50, j * 50);
      if (i <= 4 && j == 4) painter.drawPoint(i * 50, j * 50);
      if (i <= 4 && j == 5) painter.drawPoint(i * 50, j * 50);
      if (i <= 10 && j == 6) painter.drawPoint(i * 50, j * 50);
    }
}

void drawRadar(QPainter &painter, int x, int y) {
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

void MainWindow::paintEvent(QPaintEvent *event) {
  QPainter mytext(this);
  drawLakes(mytext);
  drawSwamps(mytext);
  drawFront(mytext);
  drawCoverage(mytext);
  drawRadarZone(mytext);
  drawAW(mytext);
  drawRadarsPlaces(mytext);
  drawH(mytext);
  drawVisible(mytext);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

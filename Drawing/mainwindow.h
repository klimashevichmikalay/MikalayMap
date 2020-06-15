#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  virtual void paintEvent(QPaintEvent *event);
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_7_clicked();

  void on_checkBox_stateChanged(int arg1);

  void on_checkBox_2_stateChanged(int arg1);

  void on_checkBox_3_stateChanged(int arg1);

  void on_checkBox_4_stateChanged(int arg1);

  void on_checkBox_5_stateChanged(int arg1);

  void on_checkBox_6_stateChanged(int arg1);

  void on_checkBox_7_stateChanged(int arg1);

  void on_checkBox_8_stateChanged(int arg1);

  void on_checkBox_9_stateChanged(int arg1);

  void on_pushButton_6_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_clicked();

  void on_checkBox_10_stateChanged(int arg1);

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H

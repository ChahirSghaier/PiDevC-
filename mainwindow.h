#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "events.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include <QComboBox>
#include <QPrinter>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:


     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_15_clicked();

     void on_pushButton_14_clicked();

     void on_pushButton_12_clicked();

     void on_pushButton_13_clicked();

     void on_radioButton_clicked();

     void on_radioButton_2_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_8_clicked();

     void on_pushButton_9_clicked();

     void on_comboBox_currentIndexChanged(const QString &arg1);

     void on_pushButton_10_clicked();

     void on_pushButton_51_clicked();

     void on_pushButton_52_clicked();

     void on_pushButton_53_clicked();

     void on_pushButton_55_clicked();

     void on_radioButton_3_clicked();
     void on_radioButton_4_clicked();


     void on_pushButton_16_clicked();

     void on_pushButton_56_clicked();

     void on_radioButton_9_clicked();

     void on_radioButton_10_clicked();

     void on_pushButton_54_clicked();

     void on_tableView_8_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    client tmpclient;
    QSystemTrayIcon *mysystem;
    events tmpevent;
};

#endif // MAINWINDOW_H

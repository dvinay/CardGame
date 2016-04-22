#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rulesdialog.h"
#include <QMainWindow>
#include <QLCDNumber>
#include <QObject>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void reDraw(QWidget *parent=0);
    void cleardeck();
    void timerEvent(QTimerEvent *event);
    ~MainWindow();
    //QLCDNumber *lcd1;

private slots:
    void on_action2X2_triggered();
    void on_action4X2_triggered();
    void on_action6X2_triggered();
    void on_action8X2_triggered();
    void on_action10X2_triggered();
    void on_action13X2_triggered();
    void on_actionMedium_2_triggered();
    void on_actionHard_triggered();
    void on_actionRules_triggered();

private:
    Ui::MainWindow *ui;
    int timerId;
};

#endif // MAINWINDOW_H

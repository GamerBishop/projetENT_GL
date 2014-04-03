#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BDD.h"
#include "ihm_choixprof.h"
#include "ihm_consulterplanning.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(BDD *bdd,QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_return();

private:
    Ui::MainWindow *ui;
    BDD * bdd;
};

#endif // MAINWINDOW_H

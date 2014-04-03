#ifndef CONSULTERRESERVATION2SU_H
#define CONSULTERRESERVATION2SU_H

#include <QMainWindow>
#include "BDD.h"

namespace Ui {
class ConsulterReservation2su;
}

class ConsulterReservation2su : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterReservation2su(QWidget *parent = 0);
    ~ConsulterReservation2su();

private:
    BDD *b;
    QString batiment;
    QString salle;
    Ui::ConsulterReservation2su *ui;



private slots:
    void on_calendar_clicked(const QDate &date);
    //void on_button_suppr_Cours1_clicked();
    //void on_button_suppr_Cours2_clicked();


};

#endif // CONSULTERRESERVATION2SU_H

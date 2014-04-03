#ifndef CONSULTERRESERVATION2SU_H
#define CONSULTERRESERVATION2SU_H

#include <QMainWindow>

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
    Ui::ConsulterReservation2su *ui;



private slots:

};

#endif // CONSULTERRESERVATION2SU_H

#ifndef CONSULTERRESERVATION2ALLUSERS_H
#define CONSULTERRESERVATION2ALLUSERS_H

#include <QMainWindow>
#include "BDD.h"

namespace Ui {
class ConsulterReservation2AllUsers;
}
class ConsulterReservation2AllUsers : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterReservation2AllUsers(BDD *b, QWidget *parent = 0);
    ~ConsulterReservation2AllUsers();

private:
    BDD *b;
    Ui::ConsulterReservation2AllUsers *ui;
};

#endif // CONSULTERRESERVATION2ALLUSERS_H
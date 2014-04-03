#ifndef CREERRESERVATIONSALLESU_H
#define CREERRESERVATIONSALLESU_H

#include <QMainWindow>
#include "BDD.h"
namespace Ui {
class CreerReservationSalleSU;
}

class CreerReservationSalleSU : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreerReservationSalleSU(BDD *bdd,QWidget *parent = 0);
    ~CreerReservationSalleSU();

private:
    Ui::CreerReservationSalleSU *ui;
    BDD * bdd;
};

#endif // CREERRESERVATIONSALLESU_H

#ifndef IHM_CREERRESERVATIONEQUIPEMENTSU_H
#define IHM_CREERRESERVATIONEQUIPEMENTSU_H

#include <QMainWindow>
#include "BDD.h"
namespace Ui {
class IHM_CreerReservationEquipementSU;
}

class IHM_CreerReservationEquipementSU : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationEquipementSU(BDD *bdd,QWidget *parent = 0);
    ~IHM_CreerReservationEquipementSU();

private:
    Ui::IHM_CreerReservationEquipementSU *ui;
    BDD * bdd;
};

#endif // IHM_CREERRESERVATIONEQUIPEMENTSU_H

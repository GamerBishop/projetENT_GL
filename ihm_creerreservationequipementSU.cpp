#include "ihm_creerreservationequipementSU.h"
#include "ui_ihm_creerreservationequipementSU.h"

IHM_CreerReservationEquipementSU::IHM_CreerReservationEquipementSU(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationEquipementSU)
{
    ui->setupUi(this);
    this->bdd=bdd;
}

IHM_CreerReservationEquipementSU::~IHM_CreerReservationEquipementSU()
{
    delete ui;
}

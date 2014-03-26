#include "ihm_creerreservationequipementSU.h"
#include "ui_ihm_creerreservationequipementSU.h"

IHM_CreerReservationEquipementSU::IHM_CreerReservationEquipementSU(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationEquipementSU)
{
    ui->setupUi(this);
}

IHM_CreerReservationEquipementSU::~IHM_CreerReservationEquipementSU()
{
    delete ui;
}

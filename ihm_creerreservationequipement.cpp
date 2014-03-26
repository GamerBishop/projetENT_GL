#include "ihm_creerreservationequipement.h"
#include "ui_ihm_creerreservationequipement.h"

IHM_CreerReservationEquipement::IHM_CreerReservationEquipement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationEquipement)
{
    ui->setupUi(this);
}

IHM_CreerReservationEquipement::~IHM_CreerReservationEquipement()
{
    delete ui;
}

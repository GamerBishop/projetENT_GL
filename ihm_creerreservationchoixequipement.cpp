#include "ihm_creerreservationchoixequipement.h"
#include "ui_ihm_creerreservationchoixequipement.h"

IHM_CreerReservationChoixEquipement::IHM_CreerReservationChoixEquipement(BDD *b,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationChoixEquipement)
{
    ui->setupUi(this);
}

IHM_CreerReservationChoixEquipement::~IHM_CreerReservationChoixEquipement()
{
    delete ui;
}

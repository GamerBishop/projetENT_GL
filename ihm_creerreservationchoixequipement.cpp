#include "ihm_creerreservationchoixequipement.h"
#include "ui_ihm_creerreservationchoixequipement.h"

IHM_CreerReservationChoixEquipement::IHM_CreerReservationChoixEquipement(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationChoixEquipement)
{
    ui->setupUi(this);
    this->bdd=bdd;
    connect(ui->butRetour,SIGNAL(clicked()),this,SLOT(retour()));
}

void IHM_CreerReservationChoixEquipement::retour(){
    emit signalRetour();
    this->destroy();
}


IHM_CreerReservationChoixEquipement::~IHM_CreerReservationChoixEquipement()
{
    delete ui;
}

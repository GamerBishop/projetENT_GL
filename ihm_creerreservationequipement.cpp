#include "ihm_creerreservationequipement.h"
#include "ui_ihm_creerreservationequipement.h"

IHM_CreerReservationEquipement::IHM_CreerReservationEquipement(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationEquipement)
{
    ui->setupUi(this);
    this->bdd=bdd;
    connect(ui->pushButtonRetour,SIGNAL(clicked()),this,SLOT(retour()));
    connect(ui->pushButtonChoisir,SIGNAL(clicked()),this,SLOT(choixEquip()));
}

void IHM_CreerReservationEquipement::retour(){
    emit signalRetour();
    this->destroy();
}

void IHM_CreerReservationEquipement::retourIHMSuivante(){
    this->show();
}

void IHM_CreerReservationEquipement::choixEquip(){
    this->ihm_choixEquip=new IHM_CreerReservationChoixEquipement(bdd,this);

    connect(this->ihm_choixEquip,SIGNAL(signalRetour()),this,SLOT(retourIHMSuivante()));

    this->hide();
    this->ihm_choixEquip->show();
}

IHM_CreerReservationEquipement::~IHM_CreerReservationEquipement()
{
    delete ui;
}

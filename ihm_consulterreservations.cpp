#include "ihm_consulterreservations.h"
#include "ui_ihm_consulterreservations.h"

IHM_ConsulterReservations::IHM_ConsulterReservations(BDD * bdd,bool focusSalle, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_ConsulterReservations)
{
    ui->setupUi(this);
    this->bdd=bdd;
    if(focusSalle){
        ui->tabWidget->setCurrentWidget(ui->tabSalle);
    }
    else ui->tabWidget->setCurrentWidget(ui->tabEquipement);

    connect(ui->pushButtonRetour,SIGNAL(clicked()),this,SLOT(retourSalle()));
    connect(ui->pushButtonRetour_2,SIGNAL(clicked()),this,SLOT(retourEquipement()));
    connect(ui->resSalle,SIGNAL(clicked()),this,SLOT(reserverSalle()));
    connect(ui->resEquipement,SIGNAL(clicked()),this,SLOT(reserverEquipement()));

}

void IHM_ConsulterReservations::retourSalle(){
    emit signalRetour(true);
    this->destroy();
}
void IHM_ConsulterReservations::retourEquipement(){
    emit signalRetour(false);
    this->destroy();
}
void IHM_ConsulterReservations::reserverSalle(){
    this->ihm_resSalle=new CreerReservationSalle(bdd,this);
    //REVOIR SIGNAL ET SLOT !!!
    connect(this->ihm_resSalle,SIGNAL(signalRetour()),this,SLOT(retourIHMSuivante()));
    this->hide();
    this->ihm_resSalle->show();
}
void IHM_ConsulterReservations::reserverEquipement(){
    this->ihm_resEquipement=new IHM_CreerReservationEquipement(bdd,this);
    connect(this->ihm_resEquipement,SIGNAL(signalRetour()),this,SLOT(retourIHMSuivante()));
    this->hide();
    this->ihm_resEquipement->show();
}

void IHM_ConsulterReservations::retourIHMSuivante(){
    this->show();
}

IHM_ConsulterReservations::~IHM_ConsulterReservations()
{
    delete ui;
}

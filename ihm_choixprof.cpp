#include "ihm_choixprof.h"
#include "ui_ihm_choixprof.h"

IHM_ChoixProf::IHM_ChoixProf(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_ChoixProf)
{
    ui->setupUi(this);
    this->bdd=bdd;
    connect(ui->butResTabSalle,SIGNAL(clicked()),this,SLOT(afficherReservationsSalle()));
    connect(ui->butPlaTabSalle,SIGNAL(clicked()),this,SLOT(afficherPlanningSalle()));
    connect(ui->butResTabEquip,SIGNAL(clicked()),this,SLOT(afficherReservationsEquip()));
    connect(ui->butPlaTabEquip,SIGNAL(clicked()),this,SLOT(afficherPlanningEquip()));

}

void IHM_ChoixProf::afficherReservationsSalle(){

    this->consulterReservations=new IHM_ConsulterReservations(bdd,true,this);

    connect(this->consulterReservations,SIGNAL(signalRetour(bool)),this,SLOT(retourIHMSuivante(bool)));

    this->hide();
    this->consulterReservations->show();
}



void IHM_ChoixProf::afficherReservationsEquip(){
    this->consulterReservations=new IHM_ConsulterReservations(bdd,false,this);

    connect(this->consulterReservations,SIGNAL(signalRetour(bool)),this,SLOT(retourIHMSuivante(bool)));

    this->hide();
    this->consulterReservations->show();
}
//CHANGER SLOT retourIHMSuivante !!!
void IHM_ChoixProf::afficherPlanningSalle(){
    this->consulterPlanning=new IHM_ConsulterPlanning(bdd,true,this);

    connect(this->consulterPlanning,SIGNAL(signalRetour(bool)),this,SLOT(retourIHMSuivante(bool)));

    this->hide();
    this->consulterPlanning->show();
}

void IHM_ChoixProf::afficherPlanningEquip(){
    this->consulterPlanning=new IHM_ConsulterPlanning(bdd,false,this);

    connect(this->consulterPlanning,SIGNAL(signalRetour(bool)),this,SLOT(retourIHMSuivante(bool)));

    this->hide();
    this->consulterPlanning->show();
}
void IHM_ChoixProf::retourIHMSuivante(bool salle){
    this->show();
    if(salle){
        ui->tabWidget->setCurrentWidget(ui->tabSalle);
    }
    else ui->tabWidget->setCurrentWidget(ui->tabEquipement);

}

IHM_ChoixProf::~IHM_ChoixProf()
{
    delete ui;
}


void IHM_ChoixProf::on_buttDeconnexion_clicked()
{
    emit signalExtinction();
    this->destroy();
}

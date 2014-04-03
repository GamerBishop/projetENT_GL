#include "creerreservationsalle.h"
#include "ui_creerreservationsalle.h"

CreerReservationSalle::CreerReservationSalle(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreerReservationSalle)
{
    ui->setupUi(this);
    this->bdd=bdd;
    connect(ui->pushButtonRetour,SIGNAL(clicked()),this,SLOT(retour()));
    connect(ui->button_ok,SIGNAL(clicked()),this,SLOT(choixSalle()));
}

void CreerReservationSalle::retour(){
    emit signalRetour();
    this->destroy();
}

void CreerReservationSalle::retourIHMSuivante(){
    this->show();
}

void CreerReservationSalle::choixSalle(){
    this->ihm_choixSalle=new IHM_CreerReservationChoixSalle(bdd,this);

    connect(this->ihm_choixSalle,SIGNAL(signalRetour()),this,SLOT(retourIHMSuivante()));

    this->hide();
    this->ihm_choixSalle->show();
}

CreerReservationSalle::~CreerReservationSalle()
{
    delete ui;
}







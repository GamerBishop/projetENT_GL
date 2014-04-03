#include "ihm_creerreservationchoixsalle.h"
#include "ui_ihm_creerreservationchoixsalle.h"

IHM_CreerReservationChoixSalle::IHM_CreerReservationChoixSalle(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationChoixSalle)
{
    ui->setupUi(this);
    this->bdd=bdd;
    connect(ui->butRetour,SIGNAL(clicked()),this,SLOT(retour()));
    for (int i=0;i<tab.count();i++)
        for(int j=0;j<tab[i].count();j++)
        {
            QTableWidgetItem * item=new QTableWidgetItem(tab[i][j]);
            this->ui->tableWidget->setItem(i,j,item);

        }
}


void IHM_CreerReservationChoixSalle::retour(){
    emit signalRetour();
    this->destroy();
}


IHM_CreerReservationChoixSalle::~IHM_CreerReservationChoixSalle()
{


    delete ui;
}

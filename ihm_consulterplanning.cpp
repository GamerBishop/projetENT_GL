#include "ihm_consulterplanning.h"
#include "ui_ihm_consulterplanning.h"

IHM_ConsulterPlanning::IHM_ConsulterPlanning(BDD * bdd,bool focusSalle, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_ConsulterPlanning)
{
    ui->setupUi(this);
    this->bdd=bdd;
    if(focusSalle){
        ui->tabWidget->setCurrentWidget(ui->tabSalle);
        QList<QList<QString> > tab=bdd->;
        for (int i=0;i<tab.count();i++)
            for(int j=0;j<tab[i].count();j++)
            {
                QTableWidgetItem * item=new QTableWidgetItem(tab[i][j]);
                this->ui->tableSalle->setItem(i,j,item);

            }
    }
    else ui->tabWidget->setCurrentWidget(ui->tabEquipement);

    connect(ui->butRetour,SIGNAL(clicked()),this,SLOT(retourSalle()));
    connect(ui->butRetour_2,SIGNAL(clicked()),this,SLOT(retourEquipement()));
    connect(ui->butPlanningSalle,SIGNAL(clicked()),this,SLOT(planningSalle()));
    connect(ui->butPlanningEquip,SIGNAL(clicked()),this,SLOT(planningEquipement()));
}

void IHM_ConsulterPlanning::retourSalle(){
    emit signalRetour(true);
    this->destroy();
}
void IHM_ConsulterPlanning::retourEquipement(){
    emit signalRetour(false);
    this->destroy();
}
void IHM_ConsulterPlanning::planningSalle(){

}
void IHM_ConsulterPlanning::planningEquipement(){
   /*this->ihm_resEquipement=new IHM_CreerReservationEquipement(this);
    connect(this->ihm_resEquipement,SIGNAL(signalRetour()),this,SLOT(retourIHMResEquip()));
    this->hide();
    this->ihm_resEquipement->show();*/
}


IHM_ConsulterPlanning::~IHM_ConsulterPlanning()
{
    delete ui;
}

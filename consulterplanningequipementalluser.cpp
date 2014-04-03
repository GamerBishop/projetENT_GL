#include "consulterplanningequipementalluser.h"
#include "ui_consulterplanningequipementalluser.h"

ConsulterPlanningEquipementAllUser::ConsulterPlanningEquipementAllUser(BDD *b,QString nomEquipement,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsulterPlanningEquipementAllUser)
{
    this->nomEquipement=nomEquipement;
    ui->setupUi(this);
    this->b=b;
    QDate  today = ui->calendar->selectedDate();
    QDate tomorrow = ui->calendar->selectedDate().addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    ui->label_today->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_today_cours->setText(b->SelectReservationsParDateEtEquipement(this->nomEquipement,today.toString("yyyy-dd-MM")));
    ui->label_demain_cours->setText(b->SelectReservationsParDateEtEquipement(this->nomEquipement,tomorrow.toString("yyyy-dd-MM")));
}

ConsulterPlanningEquipementAllUser::~ConsulterPlanningEquipementAllUser()
{
    delete ui;
}




void ConsulterPlanningEquipementAllUser::on_calendar_clicked(const QDate &date)
{
    QDate  today = date;
    QDate tomorrow = date.addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    ui->label_today->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_today_cours->setText(b->SelectReservationsParDateEtEquipement(this->nomEquipement,today.toString("yyyy-MM-dd")));
    ui->label_demain_cours->setText(b->SelectReservationsParDateEtEquipement(this->nomEquipement,tomorrow.toString("yyyy-MM-dd")));
}


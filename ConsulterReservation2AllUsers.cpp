#include "ConsulterReservation2AllUsers.h"
#include "ui_ConsulterReservation2AllUsers.h"
#include <QString>
using namespace std;

ConsulterReservation2AllUsers::ConsulterReservation2AllUsers(BDD *b, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsulterReservation2AllUsers)
{
    ui->setupUi(this);
    this->b=b;
    QDate  today = ui->calendar->selectedDate();
    QDate tomorrow = ui->calendar->selectedDate().addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    ui->label_today->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_2->setText(b->SelectReservationsParDateEtSalle("Pascal","P136",today.toString("yyyy-dd-MM")));
    ui->label_4->setText(b->SelectReservationsParDateEtSalle("Pascal","P136",tomorrow.toString("yyyy-dd-MM")));

 }

ConsulterReservation2AllUsers::~ConsulterReservation2AllUsers()
{
    delete ui;
}

void ConsulterReservation2AllUsers::on_calendar_clicked(const QDate &date)
{
    QDate  today = date;
    QDate tomorrow = date.addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    ui->label_today->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_2->setText(b->SelectReservationsParDateEtSalle("Pascal","P136",today.toString("yyyy-MM-dd")));
    ui->label_4->setText(b->SelectReservationsParDateEtSalle("Pascal","P136",tomorrow.toString("yyyy-MM-dd")));
}

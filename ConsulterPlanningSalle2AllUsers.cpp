#include "ConsulterPlanningSalle2AllUsers.h"
#include "ui_ConsulterPlanningSalle2AllUsers.h"
#include <QString>
using namespace std;
ConsulterPlanningSalle2AllUsers::ConsulterPlanningSalle2AllUsers(BDD *b,QString salle, QString batiment, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsulterPlanningSalle2AllUsers)
{
    ui->setupUi(this);
    this->b=b;
    this->batiment=batiment;
    this->salle=salle;
    QDate  today = ui->calendar->selectedDate();
    QDate tomorrow = ui->calendar->selectedDate().addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    const char* tod = today_date.toStdString().c_str();
    const char* tom = tomor_date.toStdString().c_str();
    ui->label_today->setText(ui->label_today->text()+" "+tod+" :");
    ui->label_next_day->setText(ui->label_next_day->text()+" "+tom+" :");

}

ConsulterPlanningSalle2AllUsers::~ConsulterPlanningSalle2AllUsers()
{
    delete ui;
}

void ConsulterPlanningSalle2AllUsers::on_calendar_clicked(const QDate &date)
{
    QDate  today = date;
    QDate tomorrow = date.addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    ui->label_today->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_2->setText(b->SelectReservationsParDateEtSalle(this->batiment,this->salle,today.toString("yyyy-MM-dd")));
    ui->label_4->setText(b->SelectReservationsParDateEtSalle(this->batiment,this->salle,tomorrow.toString("yyyy-MM-dd")));
}

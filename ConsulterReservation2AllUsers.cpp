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

    const char* tod = today_date.toStdString().c_str();
    const char* tom = tomor_date.toStdString().c_str();
    ui->label_today->setText(ui->label_today->text()+" "+tod+" :");
    ui->label_next_day->setText(ui->label_next_day->text()+" "+tom+" :");

    ui->label_2->setText(b->SelectReservationsParDateEtSalle("Pascal","P136","2014-04-17"));

 }

ConsulterReservation2AllUsers::~ConsulterReservation2AllUsers()
{
    delete ui;
}

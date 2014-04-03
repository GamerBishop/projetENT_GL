#include "consulterreservation2su.h"
#include "ui_consulterreservation2su.h"

ConsulterReservation2su::ConsulterReservation2su(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsulterReservation2su)
{
    ui->setupUi(this);
    QDate  today = ui->calendar->selectedDate();
    QDate tomorrow = ui->calendar->selectedDate().addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    const char* tod = today_date.toStdString().c_str();
    const char* tom = tomor_date.toStdString().c_str();
    ui->label_today->setText(ui->label_today->text()+" "+tod+" :");
    ui->label_next_day->setText(ui->label_next_day->text()+" "+tom+" :");

}

ConsulterReservation2su::~ConsulterReservation2su()
{
    delete ui;
}

void ConsulterReservation2su::on_calendar_clicked(const QDate &date)
{
    QDate  today = date;
    QDate tomorrow = date.addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    ui->label->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_today_cours>setText(b->SelectReservationsParDateEtSalle(this->batiment,this->salle,today.toString("yyyy-MM-dd")));
    ui->label_demain_cours->setText(b->SelectReservationsParDateEtSalle(this->batiment,this->salle,tomorrow.toString("yyyy-MM-dd")));
}

void ConsulterReservation2su::on_button_suppr_Cours1_clicked()
{
    b->DeleteReservationParDateEtSalle(this->batiment,this->salle,today.toString("yyyy-MM-dd"));
}




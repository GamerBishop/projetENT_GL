#include "consulterreservation2su.h"
#include "ui_consulterreservation2su.h"


ConsulterReservation2SU::ConsulterReservation2SU(BDD *b,QString salle, QString batiment, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsulterReservation2SU)
{
    this->batiment=batiment;
    this->salle=salle;
    ui->setupUi(this);
    today = ui->calendar->selectedDate();
    tomorrow = ui->calendar->selectedDate().addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    const char* tod = today_date.toStdString().c_str();
    const char* tom = tomor_date.toStdString().c_str();
    ui->label_today->setText(ui->label_today->text()+" "+tod+" :");
    ui->label_next_day->setText(ui->label_next_day->text()+" "+tom+" :");
}

ConsulterReservation2SU::~ConsulterReservation2SU()
{
    delete ui;
}

void ConsulterReservation2SU::on_calendar_clicked(const QDate &date)
{
    QDate today_next = date;
    QDate tomorrow_next = date.addDays(1);


    QString today_date =  today_next.toString("ddd d MMMM");
    QString tomor_date =  tomorrow_next.toString("ddd d MMMM");

    ui->label_today->setText("Aujourd'hui : "+today_date+" :");
    ui->label_next_day->setText("Demain : "+tomor_date+" :");

    ui->label_today_cours->setText(b->SelectReservationsParDateEtSalle(this->batiment,this->salle,today.toString("yyyy-MM-dd")));
    ui->label_demain_cours->setText(b->SelectReservationsParDateEtSalle(this->batiment,this->salle,tomorrow.toString("yyyy-MM-dd")));
}




void ConsulterReservation2SU::on_button_suppr_roday_cours_clicked()
{

    b->DeleteReservationParDateEtSalle(batiment,salle,today.toString("yyyy-MM-dd"));
}

void ConsulterReservation2SU::on_button_suppr_demain_cours_clicked()
{

    b->DeleteReservationParDateEtSalle(batiment,salle,tomorrow.toString("yyyy-MM-dd"));

}


void ConsulterReservation2SU::on_button_ajout_clicked()
{
   creerReservSalle = new CreerReservationSalleSU(b,this);

   creerReservSalle->show();
   this->hide();

}

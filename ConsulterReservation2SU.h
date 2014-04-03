#ifndef CONSULTERRESERVATION2SU_H
#define CONSULTERRESERVATION2SU_H

#include <QMainWindow>
#include "BDD.h"
#include "creerreservationsallesu.h"

namespace Ui {
class ConsulterReservation2SU;
}

class ConsulterReservation2SU : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterReservation2SU(BDD *b,QString salle, QString batiment, QWidget *parent=0);
    ~ConsulterReservation2SU();

private slots:
    void on_calendar_clicked(const QDate &date);

    void on_button_suppr_roday_cours_clicked();

    void on_button_suppr_demain_cours_clicked();

    void on_label_today_cours_objectNameChanged(const QString &objectName);

    void on_button_ajout_clicked();

private:
    BDD *b;
    QString batiment;
    QString salle;
    Ui::ConsulterReservation2SU *ui;
    CreerReservationSalleSU*creerReservSalle;
    QDate today;
    QDate tomorrow;
};

#endif // CONSULTERRESERVATION2SU_H

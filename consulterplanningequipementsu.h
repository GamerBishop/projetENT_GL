#ifndef CONSULTERPLANNINGEQUIPEMENTSU_H
#define CONSULTERPLANNINGEQUIPEMENTSU_H

#include <QMainWindow>
#include "BDD.h"
#include "ihm_creerreservationequipementSU.h"

namespace Ui {
class ConsulterPlanningEquipementSU;
}

class ConsulterPlanningEquipementSU : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterPlanningEquipementSU(BDD *b, QString nomEquipement,QWidget *parent=0);
    ~ConsulterPlanningEquipementSU();

private slots:
    void on_calendar_clicked(const QDate &date);

    void on_button_suppr_today_cours_clicked();

    void on_button_suppr_demain_cours_clicked();

    void on_button_ajout_clicked();

private:
    BDD *b;
    QString nomEquipement;
    Ui::ConsulterPlanningEquipementSU *ui;
    IHM_CreerReservationEquipementSU *creerReservEquip;
    QDate today;
    QDate tomorrow;
};

#endif // CONSULTERPLANNINGEQUIPEMENTSU_H

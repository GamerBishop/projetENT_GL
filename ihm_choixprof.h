#ifndef IHM_CHOIXPROF_H
#define IHM_CHOIXPROF_H

#include <QMainWindow>
#include "ihm_consulterreservations.h"
#include "ihm_consulterplanning.h"
#include "BDD.h"

namespace Ui {
class IHM_ChoixProf;
}

class IHM_ChoixProf : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_ChoixProf(BDD *bdd,QWidget *parent = 0);
    IHM_ConsulterReservations *consulterReservations;
    IHM_ConsulterPlanning *consulterPlanning;
    ~IHM_ChoixProf();

private:
    Ui::IHM_ChoixProf *ui;
    BDD * bdd;
signals :
    void signalExtinction();
public slots:
    void afficherReservationsSalle();
    void afficherPlanningSalle();
    void afficherReservationsEquip();
    void afficherPlanningEquip();
    void retourIHMSuivante(bool salle);
private slots:
    void on_buttDeconnexion_clicked();
};

#endif // IHM_CHOIXPROF_H

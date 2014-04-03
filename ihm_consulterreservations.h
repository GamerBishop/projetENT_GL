#ifndef IHM_CONSULTERRESERVATIONS_H
#define IHM_CONSULTERRESERVATIONS_H

#include <QMainWindow>
#include "ihm_creerreservationequipement.h"
#include "creerreservationsalle.h"
#include "BDD.h"
namespace Ui {
class IHM_ConsulterReservations;
}

class IHM_ConsulterReservations : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_ConsulterReservations(BDD *bdd,bool focusSalle,QWidget *parent = 0);
    ~IHM_ConsulterReservations();
    IHM_CreerReservationEquipement * ihm_resEquipement;
    CreerReservationSalle *ihm_resSalle;

private:
    Ui::IHM_ConsulterReservations *ui;
    BDD * bdd;
signals:
    void signalRetour(bool salle);
public slots:
    void reserverEquipement();
    void reserverSalle();
    void retourEquipement();
    void retourSalle();
    void retourIHMSuivante();

private slots:
    void on_button_ok_clicked();
    void on_button_ajout_clicked();
};

#endif // IHM_CONSULTERRESERVATIONS_H

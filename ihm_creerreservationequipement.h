#ifndef IHM_CREERRESERVATIONEQUIPEMENT_H
#define IHM_CREERRESERVATIONEQUIPEMENT_H

#include <QMainWindow>
#include "ihm_creerreservationchoixequipement.h"
#include "BDD.h"
namespace Ui {
class IHM_CreerReservationEquipement;
}

class IHM_CreerReservationEquipement : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationEquipement(BDD *bdd,QWidget *parent = 0);
    ~IHM_CreerReservationEquipement();
    IHM_CreerReservationChoixEquipement *ihm_choixEquip;
private:
    Ui::IHM_CreerReservationEquipement *ui;
    BDD * bdd;
signals:
    void signalRetour();
public slots:
    void retour();
    void choixEquip();
    void retourIHMSuivante();
};

#endif // IHM_CREERRESERVATIONEQUIPEMENT_H

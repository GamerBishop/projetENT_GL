#ifndef IHM_CREERRESERVATIONCHOIXEQUIPEMENT_H
#define IHM_CREERRESERVATIONCHOIXEQUIPEMENT_H

#include <QMainWindow>
#include "BDD.h"

namespace Ui {
class IHM_CreerReservationChoixEquipement;
}

class IHM_CreerReservationChoixEquipement : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationChoixEquipement(BDD *b,QWidget *parent = 0);

    ~IHM_CreerReservationChoixEquipement();

private:
    Ui::IHM_CreerReservationChoixEquipement *ui;
    BDD * bdd;
signals:
    void signalRetour();
public slots:
    void retour();
};

#endif // IHM_CREERRESERVATIONCHOIXEQUIPEMENT_H

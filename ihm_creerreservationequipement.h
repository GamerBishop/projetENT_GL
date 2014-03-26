#ifndef IHM_CREERRESERVATIONEQUIPEMENT_H
#define IHM_CREERRESERVATIONEQUIPEMENT_H

#include <QMainWindow>

namespace Ui {
class IHM_CreerReservationEquipement;
}

class IHM_CreerReservationEquipement : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationEquipement(QWidget *parent = 0);
    ~IHM_CreerReservationEquipement();

private:
    Ui::IHM_CreerReservationEquipement *ui;
};

#endif // IHM_CREERRESERVATIONEQUIPEMENT_H

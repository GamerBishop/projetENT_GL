#ifndef IHM_CREERRESERVATIONEQUIPEMENTSU_H
#define IHM_CREERRESERVATIONEQUIPEMENTSU_H

#include <QMainWindow>

namespace Ui {
class IHM_CreerReservationEquipementSU;
}

class IHM_CreerReservationEquipementSU : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationEquipementSU(QWidget *parent = 0);
    ~IHM_CreerReservationEquipementSU();

private:
    Ui::IHM_CreerReservationEquipementSU *ui;
};

#endif // IHM_CREERRESERVATIONEQUIPEMENTSU_H

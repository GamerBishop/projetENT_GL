#ifndef IHM_CONSULTERRESERVATIONS_H
#define IHM_CONSULTERRESERVATIONS_H

#include <QMainWindow>

namespace Ui {
class IHM_ConsulterReservations;
}

class IHM_ConsulterReservations : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_ConsulterReservations(QWidget *parent = 0);
    ~IHM_ConsulterReservations();

private:
    Ui::IHM_ConsulterReservations *ui;

private slots:
    void on_button_ok_clicked();
    void on_button_ajout_clicked();
};

#endif // IHM_CONSULTERRESERVATIONS_H

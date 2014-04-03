#ifndef CREERRESEVATIONSALLE_H
#define CREERRESEVATIONSALLE_H

#include <QMainWindow>
#include "ihm_creerreservationchoixsalle.h"


namespace Ui {
class CreerResevationSalle;
}

class CreerResevationSalle : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreerResevationSalle(QWidget *parent = 0);
    ~CreerResevationSalle();

private:
    Ui::CreerResevationSalle *ui;
    IHM_CreerReservationChoixSalle *choixSalle;

private slots:
    void afficherCreerResevationChoixSalle();


    void on_combo_type_salle_currentIndexChanged(const QString &arg1);
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_comboBox_3_currentIndexChanged(const QString &arg1);
    void on_combo_type_cours_currentIndexChanged(const QString &arg1);
    void on_combo_ue_currentIndexChanged(const QString &arg1);
    void on_combo_promo_currentIndexChanged(const QString &arg1);
    void on_combo_groupe_currentIndexChanged(const QString &arg1);
    void on_combo_prof_currentIndexChanged(const QString &arg1);
};

#endif // CREERRESEVATIONSALLE_H

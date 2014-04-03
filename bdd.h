#ifndef BDD_H
#define BDD_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVector>
#include <QDateTime>

class BDD:public QObject
{
Q_OBJECT
public:
    explicit BDD();
    QSqlDatabase db;
    bool Connexion(QString login, QString password);
    bool DeleteReservationParDateEtSalle(QString batiment,QString numsalle, QString date);
    QString SelectReservationsParDateEtSalle(QString batiment,QString numsalle, QString date);
    QString SelectReservationsParDateEtEquipement(QString nomEquipement, QString date);
    bool DeleteReservationParDateEtEquipement(QString nomEquipement, QString date);
    QList<QList<QString>> SelectAllReservationsProf();

};

#endif // BDD_H

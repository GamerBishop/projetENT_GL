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
    explicit BDD(QString host, QString nomDB, QString login, QString mdp);
    explicit BDD();
    QSqlDatabase db;
    bool Connexion(QString login, QString password);
    bool DeleteReservationParDateEtSalle(QString batiment,QString numsalle, QString date);
    QString SelectReservationsParDateEtSalle(QString batiment,QString numsalle, QString date);
    QList<QList<QString> > selectSalleVide(QString date,QString typesalle,QString promotion,QString groupe,QString hdebut,QString duree);
    void creerReservationSalle(QString date, QString hdebut, QString duree, QString salleid, QString typecours, QString profNom, QString profPrenom, QString ue, QString groupeid);
    QList<QList<QString> > selectEquipementDispo(QString typeequipement,QString date,QString hdebut,QString duree);
    void creerReservationEquipement(QString date, QString hdebut,QString duree,QString nomequipement,QString nomprof,QString prenomprof);
    QList<QString> selectProfesseur();
    QList<QString> selectGroupe(QString nompromo);
    QList<QString> selectPromotion();
    QList<QString> selectUE();
    QList<QString> selectTypeEquipement();
    QList<QString> selectTypeCours();
    QList<QString> selectTypeSalle();
    QString SelectReservationsParDateEtEquipement(QString nomEquipement, QString date);
    QList<QList<QString> >selectSalle();
    QList<QString>selectEquipement();

    bool isProf();

    QString login;
    bool DeleteReservationParDateEtEquipement(QString nomEquipement, QString date);
    QList<QList<QString>> SelectAllReservationsProf();

};

#endif // BDD_H

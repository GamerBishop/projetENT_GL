#include "BDD.h"





BDD::BDD(QString host, QString nomDB, QString login, QString mdp)
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName(host);
        db.setDatabaseName(nomDB); 
        db.setUserName(login);
        db.setPassword(mdp);

        if(!db.open())
          {
              QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
              exit(1);
          }
    }




bool BDD::Connexion(QString login, QString password)
{
    QSqlQuery requeteur;
    requeteur.prepare("Select login, password "
                     "from Personne"
                      "where login=:login AND mdp=:password");
    requeteur.bindValue(":login",login);
    requeteur.bindValue(":password",password);
    requeteur.exec();
    if(requeteur.size()==0)
        return false;
    return true;
}

QString BDD::SelectReservationsParDateEtSalle(QString batiment,QString numsalle, QString date)
{
    QVector<QVector<QString> > result;
    QVector<QString> idCours;
    QSqlQuery requeteur;

    requeteur.prepare("Select c.heuredebut, c.heuredebut+c.duree as HeureFin, t.libelle, c.id"
                      "from cours c,typecours t, salle s"
                      "Where t.id=c.typecoursid"
                      "And s.batiment = ?"
                      "And s.numsalle = ?"
                      "And c.salleid=s.id"
                      "AND date = ? "
                      "ORDER BY c.heuredebut");
    requeteur.addBindValue(batiment);
    requeteur.addBindValue(numsalle);
    requeteur.addBindValue(date);
    requeteur.exec();

    int i=0;
    while(requeteur.next())
        {

            result[i][0]=requeteur.value(0).toString();
            result[i][1]=requeteur.value(1).toString();
            result[i][2]=requeteur.value(2).toString();
            idCours[i]=requeteur.value(3).toString();
            i++;
        }

        for (i=0;i<idCours.count();i++)
        {
            requeteur.prepare("Select nom from groupe where id=(Select groupeid from cours_groupe where coursid=:id");
            requeteur.bindValue(":id",idCours[i]);
            requeteur.exec();
            while(requeteur.next())
                {
                    result[i][3]=requeteur.value(0).toString() + " " + requeteur.value(1).toString() + " - " ;
                }
            result[i][3].replace( result[i][3].indexOf("-",-1), ' ' );


            requeteur.prepare("Select nom, prenom from personne where id=(Select personneid from prof_cours where coursid=:id");
            requeteur.bindValue(":id",idCours[i]);
            requeteur.exec();
            while(requeteur.next())
                {

                    result[i][4]=requeteur.value(0).toString() + " " + requeteur.value(1).toString() + " - " ;
                }
            result[i][4].replace( result[i][4].indexOf("-",-1), ' ' );

        }

    //result[i][0] = heure de debut
    //result[i][1] = heure de fin
    //result[i][2] = nom du cours
    //result[i][3] = nom DES groupes
    //result[i][5] = nom DES profs

    QString aEnvoyer="";
    for(QVector<QString> vs : result)
    {

        aEnvoyer=aEnvoyer+vs[0]+" - "+vs[1]+"\n"+vs[2] +" - "+vs[3]+ " - "+vs[4]+"\n ------------";
    }
    if(aEnvoyer.isEmpty())

    return aEnvoyer;
}


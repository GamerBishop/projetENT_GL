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

bool BDD::DeleteReservationParDateEtSalle(QString batiment,QString numsalle, QString date)
{
    QSqlQuery requeteur;
    requeteur.prepare("DELETE FROM cours "
                      "Where Date =:date "
                      "And salleid= (Select from salle where numsalle = :numsalle and batiment = :batiment);");
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":salle",numsalle);
    requeteur.bindValue(":batiment",batiment);
    requeteur.exec();
    if(requeteur.size()==0)
        return false;
    return true;
}


QString BDD::SelectReservationsParDateEtSalle(QString batiment,QString numsalle, QString date)
{
    QList<QList<QString> > result;
     QList<QString> tmpList;
    QList<QString> idCours;
    QSqlQuery requeteur;

    requeteur.prepare("Select c.heuredebut, c.heuredebut+c.duree as HeureFin, t.libelle, c.id "
                      "from cours c,typecours t, salle s "
                      "Where t.id=c.typecoursid "
                      "And s.batiment = :batiment "
                      "And s.numsalle = :numsalle "
                      "And c.salleid=s.id "
                      "AND date = :date "
                      "ORDER BY c.heuredebut");
    requeteur.bindValue(":batiment",batiment);
    requeteur.bindValue(":numsalle",numsalle);
    requeteur.bindValue(":date",date);
    requeteur.exec();


    int i=0;
    while(requeteur.next())
        {
            tmpList.clear();
            tmpList.append(requeteur.value(0).toString());
            tmpList.append(requeteur.value(1).toString());
            tmpList.append(requeteur.value(2).toString());
            result.append(tmpList);
            idCours.append(requeteur.value(3).toString());
            i++;
        }

        for (int i=0;i<idCours.length();i++)
        {
            requeteur.clear();
            requeteur.prepare("Select nom from groupe g join cours_groupe c on g.id = c.groupeid Where c.coursid=:id");
            requeteur.bindValue(":id",idCours.at(i));
            requeteur.exec();
            while(requeteur.next())
                {
                   if(result.at(i).length()<4)
                        {
                        result[i].append(requeteur.value(0).toString());

                        }
                    else
                    {
                        result[i].last().append(" - "+requeteur.value(0).toString());
                    }
                }
            requeteur.clear();
            requeteur.prepare("Select nom, prenom from personne p join prof_cours pc on p.id=pc.personneid where coursid=:id");
            requeteur.bindValue(":id",idCours[i]);
            requeteur.exec();
            while(requeteur.next())
                {
                if(result[i].length()<5)
                    result[i].append(requeteur.value(0).toString() + " " + requeteur.value(1).toString());
                else
                    result[i].last().append(" - "+requeteur.value(0).toString() + " " + requeteur.value(1).toString());


                }

        }
    //result[i][0] = heure de debut
    //result[i][1] = heure de fin
    //result[i][2] = nom du cours
    //result[i][3] = nom DES groupes
    //result[i][5] = nom DES profs

    QString aEnvoyer="";
    for(QList<QString> vs : result)
    {

        aEnvoyer=aEnvoyer+vs.at(0)+" - "+vs.at(1)+"\n"+vs.at(2) +" : "+vs.at(3)+ " | " +vs.at(4)+"\n \n";
    }
    return aEnvoyer;
}


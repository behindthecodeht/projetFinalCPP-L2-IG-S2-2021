#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include "config/db.h"

class Employe
{
private:
    int id;
    QString nom;
    QString prenom;
    QString mail;
    QString telephone;
    double salaire;
    QString dateEntry;
    int fonction;
    int service;



public:
    // Constructors
    Employe();
    Employe(QString nom, QString prenom, QString mail, QString telephone,
            double salaire, int fonction, int service);
    Employe(int id, QString nom, QString prenom, QString mail, QString telephone,
            double salaire, int fonction, int service);

    // Getter
    int getId(){ return this->id; }
    QString getNom(){ return this->nom; }
    QString getPrenom(){ return this->prenom; }
    QString getMail(){ return this->mail; }
    QString getTelephone(){ return this->telephone; }
    double getSalaire(){ return this->salaire; }
    QString getDateEntry(){ return this->dateEntry; }
    int getFonctionId(){ return this->fonction; }
    int getServiceId(){ return this->service; }

    // Functions
    bool creer();
    bool modifier();
    bool supprimer();
    static QSqlQueryModel* fetchModel(QSqlQueryModel *model);
    static QSqlQuery fetchAll();
    static QSqlQueryModel* fetchProjetByAffectModel(QSqlQueryModel *model, int id);
};

#endif // EMPLOYE_H

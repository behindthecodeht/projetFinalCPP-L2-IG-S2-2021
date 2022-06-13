#ifndef ADRESSE_H
#define ADRESSE_H

#include <QString>
#include <QSqlQueryModel>
#include "config/db.h"

class Adresse
{
private:
    QString id;
    QString ligne;
    QString departement;
    QString commune;
    QString telephone;

public:
    // Constructors
    Adresse();
    Adresse(QString ligne, QString departement, QString commune, QString telephone);
    Adresse(QString id, QString ligne, QString departement, QString commune, QString telephone);

    // Getters
    QString getId(){ return this->id; }
    QString getLigne(){ return this->ligne; }
    QString getDepartement(){ return this->departement; }
    QString getCommune(){ return this->commune; }
    QString getTelephone(){ return this->telephone; }

    // Functions
    bool creer();
    bool modifier();
    bool supprimer();
    static QSqlQueryModel* fetchModel(QSqlQueryModel *model);
    static QSqlQuery fetchAll();

};

#endif // ADRESSE_H

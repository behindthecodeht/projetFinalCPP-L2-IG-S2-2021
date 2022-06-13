#include "adresse.h"

// Constructors
Adresse::Adresse(){};

Adresse::Adresse(QString ligne, QString departement, QString commune, QString telephone)
{
    this->ligne = ligne;
    this->departement = departement;
    this->commune = commune;
    this->telephone = telephone;
}

Adresse::Adresse(QString id, QString ligne, QString departement, QString commune, QString telephone)
{
    this->id = id;
    this->ligne = ligne;
    this->departement = departement;
    this->commune = commune;
    this->telephone = telephone;
}


// Functions
bool Adresse::creer()
{
    QString sql = "INSERT INTO adresse(ligne, departement, commune, telephone) "
                  "VALUES ('" + this->getLigne() + "', '" + this->getDepartement() + "', '" + this->getCommune() + "', '" + this->getTelephone() +"')";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Adresse::modifier()
{
    QString sql = "UPDATE adresse SET ligne='" + this->getLigne() + "', departement='"
            + this->getDepartement() + "', commune='" + this->getCommune()
            + "', telephone='" + this->getTelephone() +"' WHERE id='" + this->getId() +"'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Adresse::supprimer()
{
    QString sql = "DELETE FROM adresse WHERE id='" + this->getId() + "'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


QSqlQueryModel* Adresse::fetchModel(QSqlQueryModel *model){
    QString sql = "SELECT * FROM adresse";
    return DB::FETCHMODEL(model, sql);
}

QSqlQuery Adresse::fetchAll(){
    QString sql = "SELECT * FROM adresse";
    return DB::REQUEST(sql);
}

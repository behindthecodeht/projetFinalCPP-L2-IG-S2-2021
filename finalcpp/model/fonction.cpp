#include "fonction.h"

// Constructors
Fonction::Fonction(){}

Fonction::Fonction(QString libele)
{
    this->libele = libele;
}

Fonction::Fonction(int id, QString libele)
{
    this->id = id;
    this->libele = libele;
}


// Functions
bool Fonction::creer()
{
    QString sql = "INSERT INTO fonction(libelle) "
                  "VALUES('" + this->getLibele() + "'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}

QSqlQuery Fonction::fetchAll(){
    QString sql = "SELECT * FROM fonction";
    return DB::REQUEST(sql);
}

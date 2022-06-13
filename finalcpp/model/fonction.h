#ifndef FONCTION_H
#define FONCTION_H

#include <QString>
#include "config/db.h"
class Fonction
{

private:
    int id;
    QString libele;

public:

    // Constructors
    Fonction();
    Fonction(QString libele);
    Fonction(int id, QString libele);

    // Getters
    int getId(){ return this->id; }
    QString getLibele(){ return this->libele; }

    // Functions
    bool creer();
//    void modifier();
//    void supprimer();
    static QSqlQuery fetchAll();

};

#endif // FONCTION_H

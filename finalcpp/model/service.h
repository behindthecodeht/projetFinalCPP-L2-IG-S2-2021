#ifndef SERVICE_H
#define SERVICE_H

#include "config/db.h"
#include <QString>

class Service
{
private:
    QString id;
    QString libele;
    QString etat;
    QString idAdresse;

public:
    // Constructors
    Service(QString libele, QString etat, QString addId);
    Service(QString id, QString libele, QString etat, QString addId);

    //Getters
    QString getId(){ return this->id; }
    QString getLibele(){ return this->libele; }
    QString getEtat(){ return this->etat;  }
    QString getIdAdresse(){ return this->idAdresse;  }
    QString getAdresse();

    // Functions
    bool creer();
    bool modifier();
    bool supprimer();
    static QSqlQueryModel* fetchModel(QSqlQueryModel *model);
    static QSqlQuery fetchAll();
};

#endif // SERVICE_H

#include "db.h"

DB::DB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("mds7061LL99#");
    db.setPort(3306);
    db.setDatabaseName("gestion_employe");

    if(db.open())
        qDebug() << "Database Open !!";
    else
        qDebug() << db.lastError().text();

}

DB::~DB()
{
    qDebug() << "Database Close !!";
}

QSqlQuery DB::REQUEST(const QString & sql){
    DB();
    QSqlQuery query;
    if(!query.exec(sql))
        QMessagQMessageBoxeBox::information(NULL, "Rapport d'Erreur", "Une Erreur s'est passe lors de l'execution de la requette ! \n" + query.lastError().text());

    return query;
}

QSqlQueryModel* DB::FETCHMODEL(QSqlQueryModel *model,const  QString &sql){
    DB();
    model->setQuery(sql);
    return model;
}


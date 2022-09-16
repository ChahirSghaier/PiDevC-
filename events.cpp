#include "events.h"
#include "connection.h"
#include <QDebug>
#include <QComboBox>
event::event()
{

nom="";
startevent=QDateTime.currentDateTime();
endevent=startevent.addDays(1);


}
event::event(QString facture,QDateTime startevent,QDateTime endevent )
{
  //this->codeprod=codprod;
  this->nom=nom;
  this->startevent=startevent;
  this->endevent=endevent;
}
int event::get_codecom(){return  code;}
QString event::get_nom(){return nom;}
QDate event::get_startevent(){return startevent;}
QDate event::get_endevent(){return endevent;}



bool event::ajouter()
{
QSqlQuery query;
QString res= QString::number(codecom);
query.prepare("INSERT INTO event (NOM,STARTEVENT,ENDEVENT) "
                    "VALUES ( :nom,:startevent,:endevent)");
query.bindValue(":code", res);
query.bindValue(":nom", nom);
query.bindValue(":startevent", startevent);
query.bindValue(":endevent",endevent);

return    query.exec();
}

QSqlQueryModel * event::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from event");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("STARTEVENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ENDEVENT"));

    return model;
}
bool event::modifier(int codecom)
{QSqlQuery query;
  QString res= QString::number(codecom);
   query.prepare("UPDATE EVENT SET CODE=:code,NOM=:nom,STARTEVENT=:startevent,ENDEVENT:endevent WHERE CODE=:code") ;
   query.bindValue(":code", res);
   query.bindValue(":nom", nom);
   query.bindValue(":startevent",startevent);
   query.addBindValue(":endevent",endevent);

   return    query.exec();

}
bool event::supprimer(int codecom)
{
QSqlQuery query;
query.prepare("Delete from event where code = :code ");
query.bindValue(":code", codecom);
return    query.exec();
}
QSqlQueryModel* event::tri()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM event ORDER BY CODE");
    q->exec();
    model->setQuery(*q);
    return model;
}
QSqlQueryModel* event::tri2()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM event ORDER BY CODE desc");
    q->exec();
    model->setQuery(*q);
    return model;
}
QSqlQueryModel *event::recherche(int codecom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    //QString res= QString::number(id);
     model->setQuery("select * from event where code like '"+codecom+"'  ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("STARTEVENT"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ENDEVENT"));

            return model;

}

#include "magasin.h".h"
#include "connection.h"
#include <QDebug>
#include <QComboBox>
magasin::magasin()
{

type="";
nom="";


}
magasin::magasin(QString type,QString nom,QDate dateevent   )
{

  //this->codeprod=codprod;
  this->type=type;
  this->nom=nom;
  this->dateevent=dateevent;
}
int magasin::get_code(){return  code;}
QString magasin::get_type(){return  type;}
QString magasin::get_nom(){return nom;}
QDate magasin::get_dateevent(){return dateevent;}


bool magasin::ajouter()
{
QSqlQuery query;
QString res= QString::number(codeprod);
query.prepare("INSERT INTO magasin ( TYPE, NOM,DATEEVENT) "
                    "VALUES ( :type, :nom,:dateevent)");
query.bindValue(":code", res);
query.bindValue(":type", type);
query.bindValue(":nom", nom);
query.bindValue(":dateevent", dateevent);

return    query.exec();
}

QSqlQueryModel * magasin::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEEVENT"));

    return model;
}
bool magasin::modifier(int idd)
{QSqlQuery query;
  QString res= QString::number(idd);
   query.prepare("UPDATE MAGASIN SET DATEEVENT=:dateevent,TYPE=:type,NOM=:nom WHERE CODE=:code ") ;
   query.bindValue(":code", res);
   query.bindValue(":type", type);
   query.bindValue(":nom", nom);
   query.bindValue(":dateevent",dateevent);

   return    query.exec();

}
bool magasin::supprimer(int code)
{
QSqlQuery query;
//QString res= QString::number(codeprod);
query.prepare("Delete from magasin where code = :code ");
query.bindValue(":codeprod", code);
return    query.exec();
}

QSqlQueryModel* magasin::tri()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * magasin ORDER BY CODE");
    q->exec();
    model->setQuery(*q);
    return model;
}
QSqlQueryModel* magasin::tri2()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM magasin ORDER BY CODE desc");
    q->exec();
    model->setQuery(*q);
    return model;
}
QSqlQueryModel *magasin::recherche(int code)
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();
    //QString res= QString::number(codeprod);
     model->setQuery("select * from magasin where code like '"+code+"'  ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEPROD"));
            return model;

}

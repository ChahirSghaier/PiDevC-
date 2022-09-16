#include "client.h"
#include "connection.h"
#include <QDebug>
client::client()
{

nom="";
prenom="";
age=0;
mail="";
ville="";
num="";
}
client::client(QString nom,QString prenom,int age ,QString mail ,QString ville, QString num )
{//
  //this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
  this->mail=mail;
  this->ville=ville;
  this->num=num;
}
int client::get_id(){return  id;}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
int client::get_age(){return age;}
QString client::get_mail(){return mail;}
QString client::get_ville(){return ville;}
QString client::get_num(){return num;}


bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO client ( NOM, PRENOM, AGE,MAIL,VILLE, NUM) "
                    "VALUES ( :nom, :prenom,:age,:mail,:ville,:num)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":mail", mail);
query.bindValue(":ville", ville);
query.bindValue(":num", num);

return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("VILLE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM"));

    return model;
}
bool client::modifier(int idd)
{QSqlQuery query;
  QString res= QString::number(idd);
   query.prepare("UPDATE CLIENT SET NOM=:nom,PRENOM=:prenom,AGE=:age,ID=:id,MAIL=:mail,VILLE=:ville,NUM=:num WHERE ID=:id ") ;
   query.bindValue(":id", res);
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":age",age);
   query.bindValue(":mail",mail);
   query.bindValue(":ville",ville);
   query.bindValue(":num",num);

   return    query.exec();

}
bool client::supprimer(int id)
{
QSqlQuery query;
//QString res= QString::number(id);
query.prepare("Delete from CLIENT where id = :id ");
query.bindValue(":id", id);
return    query.exec();
}
QSqlQueryModel* client::tri()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM client ORDER BY ID");
    q->exec();
    model->setQuery(*q);
    return model;
}
QSqlQueryModel* client::tri2()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM client ORDER BY ID desc");
    q->exec();
    model->setQuery(*q);
    return model;
}
QSqlQueryModel *client::recherche(int id)
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();
    //QString res= QString::number(id);
     model->setQuery("select * from client where id like '"+id+"'  ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ville"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("num"));
            return model;

}



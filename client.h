#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPaintEvent>
class client
{
public:
    client();
    client(QString,QString,int,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_age();
    QString get_mail();
    QString get_ville();
    QString get_num();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher_client_trier();
    QSqlQueryModel* tri();
    QSqlQueryModel* tri2();
    QSqlQueryModel * recherche(int);
private:
    QString nom,prenom,mail,ville,num;
    int id,age;
};




#endif // CLIENT_H

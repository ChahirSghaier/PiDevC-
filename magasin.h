#ifndef MAGASIN_H
#define MAGASIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QComboBox>


class magasin
{
public:
    magasin();
    magasin(QString,QString,QDate);
    int get_code();
    QString get_type();
    QString get_nom();
    QDate get_dateprod();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher_magasin_trier();
     QSqlQueryModel* tri();
      QSqlQueryModel* tri2();
      QSqlQueryModel * recherche(int);
private:
    QString type,nom;
    int code;
    QDate date;
};

#endif // MAGASIN_H

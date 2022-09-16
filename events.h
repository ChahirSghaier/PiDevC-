#ifndef EVENTS_H
#define EVENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class events
{
public:
    events();
    events(QString,QDateTime);
    int get_code();
    QString get_event();
    QDateTime get_startevent();
    QDateTime get_endevent();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);

private:
    QString nom;
    int code;
    QDateTime startevent;
    QDateTime endevent;

    QSqlQueryModel * afficher_event_trier();
     QSqlQueryModel* tri();
      QSqlQueryModel* tri2();
      QSqlQueryModel * recherche(int);
};
#endif // EVENTS_H

#ifndef JOBSOBJECT_H
#define JOBSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT JobsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString title;
    QString location;
    QString wage;
    QString shortdescription;
    QDateTime dateposted;
    QDateTime closingdate;
    int industry {0};
    int company {0};

    enum PropertyIndex {
        Id = 0,
        Title,
        Location,
        Wage,
        Shortdescription,
        Dateposted,
        Closingdate,
        Industry,
        Company,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("jobs"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString location READ getlocation WRITE setlocation)
    T_DEFINE_PROPERTY(QString, location)
    Q_PROPERTY(QString wage READ getwage WRITE setwage)
    T_DEFINE_PROPERTY(QString, wage)
    Q_PROPERTY(QString shortdescription READ getshortdescription WRITE setshortdescription)
    T_DEFINE_PROPERTY(QString, shortdescription)
    Q_PROPERTY(QDateTime dateposted READ getdateposted WRITE setdateposted)
    T_DEFINE_PROPERTY(QDateTime, dateposted)
    Q_PROPERTY(QDateTime closingdate READ getclosingdate WRITE setclosingdate)
    T_DEFINE_PROPERTY(QDateTime, closingdate)
    Q_PROPERTY(int industry READ getindustry WRITE setindustry)
    T_DEFINE_PROPERTY(int, industry)
    Q_PROPERTY(int company READ getcompany WRITE setcompany)
    T_DEFINE_PROPERTY(int, company)
};

#endif // JOBSOBJECT_H

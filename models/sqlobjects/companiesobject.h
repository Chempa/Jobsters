#ifndef COMPANIESOBJECT_H
#define COMPANIESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CompaniesObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString name;
    QString email;
    QString website;
    QString imagepath;

    enum PropertyIndex {
        Id = 0,
        Name,
        Email,
        Website,
        Imagepath,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("companies"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString website READ getwebsite WRITE setwebsite)
    T_DEFINE_PROPERTY(QString, website)
    Q_PROPERTY(QString imagepath READ getimagepath WRITE setimagepath)
    T_DEFINE_PROPERTY(QString, imagepath)
};

#endif // COMPANIESOBJECT_H

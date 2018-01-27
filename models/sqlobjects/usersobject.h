#ifndef USERSOBJECT_H
#define USERSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UsersObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString name;
    QString email;
    QString phone;
    QString country;
    QString password;

    enum PropertyIndex {
        Id = 0,
        Name,
        Email,
        Phone,
        Country,
        Password,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("users"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString phone READ getphone WRITE setphone)
    T_DEFINE_PROPERTY(QString, phone)
    Q_PROPERTY(QString country READ getcountry WRITE setcountry)
    T_DEFINE_PROPERTY(QString, country)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
};

#endif // USERSOBJECT_H

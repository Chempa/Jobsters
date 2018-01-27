#ifndef USERS_H
#define USERS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TModelObject;
class UsersObject;
class QJsonArray;


class T_MODEL_EXPORT Users : public TAbstractUser, public TAbstractModel
{
public:
    Users();
    Users(const Users &other);
    Users(const UsersObject &object);
    ~Users();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString email() const;
    void setEmail(const QString &email);
    QString phone() const;
    void setPhone(const QString &phone);
    QString country() const;
    void setCountry(const QString &country);
    QString password() const;
    void setPassword(const QString &password);
    QString identityKey() const { return phone(); }
    Users &operator=(const Users &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Users authenticate(const QString &phone, const QString &password);
    static Users create(const QString &name, const QString &email, const QString &phone, const QString &country, const QString &password);
    static Users create(const QVariantMap &values);
    static Users get(int id);
    static int count();
    static QList<Users> getAll();
    static QJsonArray getAllJson();
    static bool FCexist(QString &email);
    static Users getByIdentityKey(const QString &phone);
    static QStringList getPhonesByCompany(QString companyid);
    static QStringList getPhonesByIndustry(QString industryid);
    
private:
    QSharedDataPointer<UsersObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Users)
Q_DECLARE_METATYPE(QList<Users>)

#endif // USERS_H

#include <TreeFrogModel>
#include "users.h"
#include "usersobject.h"

Users::Users()
    : TAbstractUser(), TAbstractModel(), d(new UsersObject())
{
    d->id = 0;
}

Users::Users(const Users &other)
    : TAbstractUser(), TAbstractModel(), d(new UsersObject(*other.d))
{ }

Users::Users(const UsersObject &object)
    : TAbstractUser(), TAbstractModel(), d(new UsersObject(object))
{ }


Users::~Users()
{
    // If the reference count becomes 0,
    // the shared data object 'UsersObject' is deleted.
}

int Users::id() const
{
    return d->id;
}

QString Users::name() const
{
    return d->name;
}

void Users::setName(const QString &name)
{
    d->name = name;
}

QString Users::email() const
{
    return d->email;
}

void Users::setEmail(const QString &email)
{
    d->email = email;
}

QString Users::phone() const
{
    return d->phone;
}

void Users::setPhone(const QString &phone)
{
    d->phone = phone;
}

QString Users::country() const
{
    return d->country;
}

void Users::setCountry(const QString &country)
{
    d->country = country;
}

QString Users::password() const
{
    return d->password;
}

void Users::setPassword(const QString &password)
{
    d->password = password;
}

Users &Users::operator=(const Users &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Users Users::authenticate(const QString &phone, const QString &password)
{
    if (phone.isEmpty() || password.isEmpty())
        return Users();

    TSqlORMapper<UsersObject> mapper;
    UsersObject obj = mapper.findFirst(TCriteria(UsersObject::Phone, phone));
    if (obj.isNull() || obj.password != password) {
        obj.clear();
    }
    return Users(obj);
}

Users Users::create(const QString &name, const QString &email, const QString &phone, const QString &country, const QString &password)
{
    UsersObject obj;
    obj.name = name;
    obj.email = email;
    obj.phone = phone;
    obj.country = country;
    obj.password = password;
    if (!obj.create()) {
        return Users();
    }
    return Users(obj);
}

Users Users::create(const QVariantMap &values)
{
    Users model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Users Users::get(int id)
{
    TSqlORMapper<UsersObject> mapper;
    return Users(mapper.findByPrimaryKey(id));
}

int Users::count()
{
    TSqlORMapper<UsersObject> mapper;
    return mapper.findCount();
}

QList<Users> Users::getAll()
{
    return tfGetModelListByCriteria<Users, UsersObject>();
}

QJsonArray Users::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UsersObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UsersObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Users(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Users::modelData()
{
    return d.data();
}

const TModelObject *Users::modelData() const
{
    return d.data();
}

bool Users::FCexist(QString &email)
{
    TSqlORMapper<UsersObject> mapper;
    UsersObject obj = mapper.findFirst(TCriteria(UsersObject::Email, email));
    if (obj.isNull()) return false;
    return true;
}
Users Users::getByIdentityKey(const QString &phone)
{
    TSqlORMapper<UsersObject> mapper;
    TCriteria cri(UsersObject::Phone, phone);
    return Users(mapper.findFirst(cri));
}

QStringList Users::getPhonesByCompany(QString companyid){
    TSqlQuery query;
    query.exec("select ucrel.phone from ucrel where ucrel.relcompany = "+companyid+";");
    QStringList lst;
    while(query.next()){
        lst<<query.value(0).toString();
    }
    return lst;
}

QStringList Users::getPhonesByIndustry(QString industryid){
    TSqlQuery query;
    query.exec("select uirel.phone from uirel where uirel.relindustry = "+industryid+";");
    QStringList lst;
    while(query.next()){
        lst<<query.value(0).toString();
    }
    return lst;
}
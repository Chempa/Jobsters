#include <TreeFrogModel>
#include "userscompanies.h"
#include "userscompaniesobject.h"

Userscompanies::Userscompanies()
    : TAbstractModel(), d(new UserscompaniesObject())
{
    d->relphone = 0;
    d->relcompany = 0;
}

Userscompanies::Userscompanies(const Userscompanies &other)
    : TAbstractModel(), d(new UserscompaniesObject(*other.d))
{ }

Userscompanies::Userscompanies(const UserscompaniesObject &object)
    : TAbstractModel(), d(new UserscompaniesObject(object))
{ }

Userscompanies::~Userscompanies()
{
    // If the reference count becomes 0,
    // the shared data object 'UserscompaniesObject' is deleted.
}

int Userscompanies::relphone() const
{
    return d->relphone;
}

void Userscompanies::setRelphone(int relphone)
{
    d->relphone = relphone;
}

int Userscompanies::relcompany() const
{
    return d->relcompany;
}

void Userscompanies::setRelcompany(int relcompany)
{
    d->relcompany = relcompany;
}

Userscompanies &Userscompanies::operator=(const Userscompanies &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Userscompanies Userscompanies::create(int relphone, int relcompany)
{
    UserscompaniesObject obj;
    obj.relphone = relphone;
    obj.relcompany = relcompany;
    if (!obj.create()) {
        return Userscompanies();
    }
    return Userscompanies(obj);
}

Userscompanies Userscompanies::create(const QVariantMap &values)
{
    Userscompanies model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Userscompanies Userscompanies::get(int relphone, int relcompany)
{
    TCriteria cri;
    cri.add(UserscompaniesObject::Relphone, relphone);
    cri.add(UserscompaniesObject::Relcompany, relcompany);
    TSqlORMapper<UserscompaniesObject> mapper;
    return Userscompanies(mapper.findFirst(cri));
}

int Userscompanies::count()
{
    TSqlORMapper<UserscompaniesObject> mapper;
    return mapper.findCount();
}

QList<Userscompanies> Userscompanies::getAll()
{
    return tfGetModelListByCriteria<Userscompanies, UserscompaniesObject>(TCriteria());
}

QJsonArray Userscompanies::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UserscompaniesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UserscompaniesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Userscompanies(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Userscompanies::modelData()
{
    return d.data();
}

const TModelObject *Userscompanies::modelData() const
{
    return d.data();
}
int Userscompanies::removeAll(int phone){
    /*
    TSqlORMapper<UserscompaniesObject> mapper;
    TCriteria crt(UserscompaniesObject::Relphone, phone);
    int a = mapper.removeAll(crt); 
    return a;*/
    TSqlQuery query;
    if(query.exec("delete from Userscompanies where relphone = " + QString::number(phone)))
    return 1;
    return 0;
}
QList<Userscompanies> Userscompanies::getOnCondition(int id){
    TCriteria crt(UserscompaniesObject::Relphone, id);
    return tfGetModelListByCriteria<Userscompanies, UserscompaniesObject>(crt);
}

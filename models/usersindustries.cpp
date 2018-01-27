#include <TreeFrogModel>
#include "usersindustries.h"
#include "usersindustriesobject.h"

Usersindustries::Usersindustries()
    : TAbstractModel(), d(new UsersindustriesObject())
{
    d->relphone = 0;
    d->relindustry = 0;
}

Usersindustries::Usersindustries(const Usersindustries &other)
    : TAbstractModel(), d(new UsersindustriesObject(*other.d))
{ }

Usersindustries::Usersindustries(const UsersindustriesObject &object)
    : TAbstractModel(), d(new UsersindustriesObject(object))
{ }

Usersindustries::~Usersindustries()
{
    // If the reference count becomes 0,
    // the shared data object 'UsersindustriesObject' is deleted.
}

int Usersindustries::relphone() const
{
    return d->relphone;
}

void Usersindustries::setRelphone(int relphone)
{
    d->relphone = relphone;
}

int Usersindustries::relindustry() const
{
    return d->relindustry;
}

void Usersindustries::setRelindustry(int relindustry)
{
    d->relindustry = relindustry;
}

Usersindustries &Usersindustries::operator=(const Usersindustries &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Usersindustries Usersindustries::create(int relphone, int relindustry)
{
    UsersindustriesObject obj;
    obj.relphone = relphone;
    obj.relindustry = relindustry;
    if (!obj.create()) {
        return Usersindustries();
    }
    return Usersindustries(obj);
}

Usersindustries Usersindustries::create(const QVariantMap &values)
{
    Usersindustries model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Usersindustries Usersindustries::get(int relphone, int relindustry)
{
    TCriteria cri;
    cri.add(UsersindustriesObject::Relphone, relphone);
    cri.add(UsersindustriesObject::Relindustry, relindustry);
    TSqlORMapper<UsersindustriesObject> mapper;
    return Usersindustries(mapper.findFirst(cri));
}

int Usersindustries::count()
{
    TSqlORMapper<UsersindustriesObject> mapper;
    return mapper.findCount();
}

QList<Usersindustries> Usersindustries::getAll()
{
    return tfGetModelListByCriteria<Usersindustries, UsersindustriesObject>(TCriteria());
}

QJsonArray Usersindustries::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UsersindustriesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UsersindustriesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Usersindustries(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Usersindustries::modelData()
{
    return d.data();
}

const TModelObject *Usersindustries::modelData() const
{
    return d.data();
}
int Usersindustries::removeAll(int phone){
    /*TSqlORMapper<UsersindustriesObject> mapper;
    TCriteria crt(UsersindustriesObject::Relphone, phone);
    int a = mapper.removeAll(crt); 
    return a;*/
    TSqlQuery query;
    if(query.exec("delete from Usersindustries where relphone = " + QString::number(phone)))
    return 1;
    return 0;
}
QList<Usersindustries> Usersindustries::getOnCondition(int id){
    TCriteria crt(UsersindustriesObject::Relphone, id);
    return tfGetModelListByCriteria<Usersindustries, UsersindustriesObject>(crt);
}
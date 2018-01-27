#include <TreeFrogModel>
#include "industries.h"
#include "industriesobject.h"

Industries::Industries()
    : TAbstractModel(), d(new IndustriesObject())
{
    d->id = 0;
}

Industries::Industries(const Industries &other)
    : TAbstractModel(), d(new IndustriesObject(*other.d))
{ }

Industries::Industries(const IndustriesObject &object)
    : TAbstractModel(), d(new IndustriesObject(object))
{ }

Industries::~Industries()
{
    // If the reference count becomes 0,
    // the shared data object 'IndustriesObject' is deleted.
}

int Industries::id() const
{
    return d->id;
}

QString Industries::name() const
{
    return d->name;
}

void Industries::setName(const QString &name)
{
    d->name = name;
}

Industries &Industries::operator=(const Industries &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Industries Industries::create(const QString &name)
{
    IndustriesObject obj;
    obj.name = name;
    if (!obj.create()) {
        return Industries();
    }
    return Industries(obj);
}

Industries Industries::create(const QVariantMap &values)
{
    Industries model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Industries Industries::get(int id)
{
    TSqlORMapper<IndustriesObject> mapper;
    return Industries(mapper.findByPrimaryKey(id));
}

int Industries::count()
{
    TSqlORMapper<IndustriesObject> mapper;
    return mapper.findCount();
}

QList<Industries> Industries::getAll()
{
    return tfGetModelListByCriteria<Industries, IndustriesObject>(TCriteria());
}

QJsonArray Industries::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<IndustriesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<IndustriesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Industries(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Industries::modelData()
{
    return d.data();
}

const TModelObject *Industries::modelData() const
{
    return d.data();
}

int Industries::getIdByName(QString name){
    /*TSqlORMapper<IndustriesObject> mapper;
    name = "%" + name + "%";
    TCriteria crt(IndustriesObject::Name,TSql::Like, name);
    IndustriesObject industry = mapper.findFirst(crt);
    if ( !industry.isNull() ) {
        return industry.id;
    } else {
        return -1;
    }   */
    name = "%" + name + "%";
    TSqlQuery query;
    query.exec("select Industries.id from Industries where name LIKE '" +name+ "';");
    if(query.next())return query.value(0).toInt();
    return -1;
}


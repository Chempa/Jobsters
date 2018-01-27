#include <TreeFrogModel>
#include "companies.h"
#include "companiesobject.h"

Companies::Companies()
    : TAbstractModel(), d(new CompaniesObject())
{
    d->id = 0;
}

Companies::Companies(const Companies &other)
    : TAbstractModel(), d(new CompaniesObject(*other.d))
{ }

Companies::Companies(const CompaniesObject &object)
    : TAbstractModel(), d(new CompaniesObject(object))
{ }

Companies::~Companies()
{
    // If the reference count becomes 0,
    // the shared data object 'CompaniesObject' is deleted.
}

int Companies::id() const
{
    return d->id;
}

QString Companies::name() const
{
    return d->name;
}

void Companies::setName(const QString &name)
{
    d->name = name;
}

QString Companies::email() const
{
    return d->email;
}

void Companies::setEmail(const QString &email)
{
    d->email = email;
}

QString Companies::website() const
{
    return d->website;
}

void Companies::setWebsite(const QString &website)
{
    d->website = website;
}

QString Companies::imagepath() const
{
    return d->imagepath;
}

void Companies::setImagepath(const QString &imagepath)
{
    d->imagepath = imagepath;
}

Companies &Companies::operator=(const Companies &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Companies Companies::create(const QString &name, const QString &email, const QString &website, const QString &imagepath)
{
    CompaniesObject obj;
    obj.name = name;
    obj.email = email;
    obj.website = website;
    obj.imagepath = imagepath;
    if (!obj.create()) {
        return Companies();
    }
    return Companies(obj);
}

Companies Companies::create(const QVariantMap &values)
{
    Companies model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Companies Companies::get(int id)
{
    TSqlORMapper<CompaniesObject> mapper;
    return Companies(mapper.findByPrimaryKey(id));
}

int Companies::count()
{
    TSqlORMapper<CompaniesObject> mapper;
    return mapper.findCount();
}

QList<Companies> Companies::getAll()
{
    return tfGetModelListByCriteria<Companies, CompaniesObject>(TCriteria());
}

QJsonArray Companies::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<CompaniesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<CompaniesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Companies(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Companies::modelData()
{
    return d.data();
}

const TModelObject *Companies::modelData() const
{
    return d.data();
}

int Companies::getIdByName(QString name){
    /*TSqlORMapper<CompaniesObject> mapper;
    name = "%" + name + "%";
    TCriteria crt(CompaniesObject::Name,TSql::Like, name);
    CompaniesObject company = mapper.findFirst(crt);
    if ( !company.isNull() ) {
        return company.id;
    } else {
        return -1;
    }   */
    name = "%" + name + "%";
    TSqlQuery query;
    query.exec("select Companies.id from Companies where name LIKE '" +name+ "';");
    if(query.next())return query.value(0).toInt();
    return -1;
    
}


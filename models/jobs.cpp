#include <TreeFrogModel>
#include "jobs.h"
#include "jobsobject.h"


Jobs::Jobs()
    : TAbstractModel(), d(new JobsObject())
{
    d->id = 0;
    d->industry = 0;
    d->company = 0;
}

Jobs::Jobs(const Jobs &other)
    : TAbstractModel(), d(new JobsObject(*other.d))
{ }

Jobs::Jobs(const JobsObject &object)
    : TAbstractModel(), d(new JobsObject(object))
{ }

Jobs::~Jobs()
{
    // If the reference count becomes 0,
    // the shared data object 'JobsObject' is deleted.
}

int Jobs::id() const
{
    return d->id;
}

QString Jobs::title() const
{
    return d->title;
}

void Jobs::setTitle(const QString &title)
{
    d->title = title;
}

QString Jobs::location() const
{
    return d->location;
}

void Jobs::setLocation(const QString &location)
{
    d->location = location;
}

QString Jobs::wage() const
{
    return d->wage;
}

void Jobs::setWage(const QString &wage)
{
    d->wage = wage;
}

QString Jobs::shortdescription() const
{
    return d->shortdescription;
}

void Jobs::setShortdescription(const QString &shortdescription)
{
    d->shortdescription = shortdescription;
}

QDateTime Jobs::dateposted() const
{
    return d->dateposted;
}

void Jobs::setDateposted(const QDateTime &dateposted)
{
    d->dateposted = dateposted;
}

QDateTime Jobs::closingdate() const
{
    return d->closingdate;
}

void Jobs::setClosingdate(const QDateTime &closingdate)
{
    d->closingdate = closingdate;
}

int Jobs::industry() const
{
    return d->industry;
}

void Jobs::setIndustry(int industry)
{
    d->industry = industry;
}

int Jobs::company() const
{
    return d->company;
}

void Jobs::setCompany(int company)
{
    d->company = company;
}

Jobs &Jobs::operator=(const Jobs &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Jobs Jobs::create(const QString &title, const QString &location, const QString &wage, const QString &shortdescription, const QDateTime &dateposted, const QDateTime &closingdate, int industry, int company)
{
    JobsObject obj;
    obj.title = title;
    obj.location = location;
    obj.wage = wage;
    obj.shortdescription = shortdescription;
    obj.dateposted = dateposted;
    obj.closingdate = closingdate;
    obj.industry = industry;
    obj.company = company;
    if (!obj.create()) {
        return Jobs();
    }
    return Jobs(obj);
}

Jobs Jobs::create(const QVariantMap &values)
{
    Jobs model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Jobs Jobs::get(int id)
{
    TSqlORMapper<JobsObject> mapper;
    return Jobs(mapper.findByPrimaryKey(id));
}

int Jobs::count()
{
    TSqlORMapper<JobsObject> mapper;
    return mapper.findCount();
}

QList<Jobs> Jobs::getAll()
{
    return tfGetModelListByCriteria<Jobs, JobsObject>(TCriteria());
}

QJsonArray Jobs::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<JobsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<JobsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Jobs(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Jobs::modelData()
{
    return d.data();
}

const TModelObject *Jobs::modelData() const
{
    return d.data();
}

QList<Jobs> Jobs::jobquery(QString jt,QString lt,QString ind,QString com)
{
    if(jt=="" && lt=="" && ind=="" && com==""){
        return tfGetModelListByCriteria<Jobs, JobsObject>(TCriteria());
    }else{
        if(jt=="")jt="INVALID ARGUMENT";
        if(lt=="")lt="INVALID ARGUMENT";
        if(ind=="")ind= "-1";
        if(com=="")com= "-1";
        jt = "%" + jt + "%";
        lt = "%" + lt + "%";
        /*TCriteria crt(JobsObject::Title,TSql::Like,jt);
        crt.addOr(JobsObject::Location,TSql::Like,lt);
        crt.addOr(JobsObject::Industry,TSql::Like,ind.toInt());
        crt.addOr(JobsObject::Company,TSql::Like,com.toInt());
        return tfGetModelListByCriteria<Jobs, JobsObject>(crt);*/
        if(com=="")com="-1";
        if(ind=="")ind="-1";
        TSqlQueryORMapper<JobsObject> mapper;
        mapper.prepare("select Jobs.* from Jobs where title Like '" +jt+ "' OR location Like '" + lt + "' OR industry = " +ind+ " OR company = " + com +";");
        mapper.exec();
        TSqlQueryORMapperIterator<JobsObject> it(mapper);
        QList<Jobs> lst;
        while(it.hasNext()){
            JobsObject itm = it.next();
            lst.append(itm);
        }
        return lst;
    }
} 
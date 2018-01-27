#ifndef JOBS_H
#define JOBS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>
#include "companies.h"
#include "industries.h"


class TModelObject;
class JobsObject;
class QJsonArray;


class T_MODEL_EXPORT Jobs : public TAbstractModel
{
public:
    Jobs();
    Jobs(const Jobs &other);
    Jobs(const JobsObject &object);
    ~Jobs();

    int id() const;
    QString title() const;
    void setTitle(const QString &title);
    QString location() const;
    void setLocation(const QString &location);
    QString wage() const;
    void setWage(const QString &wage);
    QString shortdescription() const;
    void setShortdescription(const QString &shortdescription);
    QDateTime dateposted() const;
    void setDateposted(const QDateTime &dateposted);
    QDateTime closingdate() const;
    void setClosingdate(const QDateTime &closingdate);
    int industry() const;
    void setIndustry(int industry);
    int company() const;
    void setCompany(int company);
    Jobs &operator=(const Jobs &other);
    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Jobs create(const QString &title, const QString &location, const QString &wage, const QString &shortdescription, const QDateTime &dateposted, const QDateTime &closingdate, int industry, int company);
    static Jobs create(const QVariantMap &values);
    static Jobs get(int id);
    static QList<Jobs> jobquery(QString jt,QString lt,QString ind,QString com);
    static int count();
    static QList<Jobs> getAll();
    static QJsonArray getAllJson();
    
private:
    QSharedDataPointer<JobsObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Jobs)
Q_DECLARE_METATYPE(QList<Jobs>)

#endif // JOBS_H

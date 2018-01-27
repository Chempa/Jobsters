#ifndef COMPANIES_H
#define COMPANIES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CompaniesObject;
class QJsonArray;


class T_MODEL_EXPORT Companies : public TAbstractModel
{
public:
    Companies();
    Companies(const Companies &other);
    Companies(const CompaniesObject &object);
    ~Companies();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString email() const;
    void setEmail(const QString &email);
    QString website() const;
    void setWebsite(const QString &website);
    QString imagepath() const;
    void setImagepath(const QString &imagepath);
    Companies &operator=(const Companies &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Companies create(const QString &name, const QString &email, const QString &website, const QString &imagepath);
    static Companies create(const QVariantMap &values);
    static Companies get(int id);
    static int count();
    static QList<Companies> getAll();
    static QJsonArray getAllJson();
    static int getIdByName(QString name);
    

private:
    QSharedDataPointer<CompaniesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Companies)
Q_DECLARE_METATYPE(QList<Companies>)

#endif // COMPANIES_H

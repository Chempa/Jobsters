#ifndef USERSCOMPANIES_H
#define USERSCOMPANIES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserscompaniesObject;
class QJsonArray;


class T_MODEL_EXPORT Userscompanies : public TAbstractModel
{
public:
    Userscompanies();
    Userscompanies(const Userscompanies &other);
    Userscompanies(const UserscompaniesObject &object);
    ~Userscompanies();

    int relphone() const;
    void setRelphone(int relphone);
    int relcompany() const;
    void setRelcompany(int relcompany);
    Userscompanies &operator=(const Userscompanies &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Userscompanies create(int relphone, int relcompany);
    static Userscompanies create(const QVariantMap &values);
    static Userscompanies get(int relphone, int relcompany);
    static int count();
    static QList<Userscompanies> getAll();
    static QJsonArray getAllJson();
    static int removeAll(int phone);
    static QList<Userscompanies> getOnCondition(int id);
private:
    QSharedDataPointer<UserscompaniesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Userscompanies)
Q_DECLARE_METATYPE(QList<Userscompanies>)

#endif // USERSCOMPANIES_H

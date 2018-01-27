#ifndef USERSINDUSTRIES_H
#define USERSINDUSTRIES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UsersindustriesObject;
class QJsonArray;


class T_MODEL_EXPORT Usersindustries : public TAbstractModel
{
public:
    Usersindustries();
    Usersindustries(const Usersindustries &other);
    Usersindustries(const UsersindustriesObject &object);
    ~Usersindustries();

    int relphone() const;
    void setRelphone(int relphone);
    int relindustry() const;
    void setRelindustry(int relindustry);
    Usersindustries &operator=(const Usersindustries &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Usersindustries create(int relphone, int relindustry);
    static Usersindustries create(const QVariantMap &values);
    static Usersindustries get(int relphone, int relindustry);
    static int count();
    static QList<Usersindustries> getAll();
    static QJsonArray getAllJson();
    static int removeAll(int phone);
    static QList<Usersindustries> getOnCondition(int id);

private:
    QSharedDataPointer<UsersindustriesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Usersindustries)
Q_DECLARE_METATYPE(QList<Usersindustries>)

#endif // USERSINDUSTRIES_H

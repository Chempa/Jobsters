#ifndef INDUSTRIES_H
#define INDUSTRIES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class IndustriesObject;
class QJsonArray;


class T_MODEL_EXPORT Industries : public TAbstractModel
{
public:
    Industries();
    Industries(const Industries &other);
    Industries(const IndustriesObject &object);
    ~Industries();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    Industries &operator=(const Industries &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static Industries create(const QString &name);
    static Industries create(const QVariantMap &values);
    static Industries get(int id);
    static int count();
    static QList<Industries> getAll();
    static QJsonArray getAllJson();
    static int getIdByName(QString name);
    

private:
    QSharedDataPointer<IndustriesObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Industries)
Q_DECLARE_METATYPE(QList<Industries>)

#endif // INDUSTRIES_H

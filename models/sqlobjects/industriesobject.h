#ifndef INDUSTRIESOBJECT_H
#define INDUSTRIESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT IndustriesObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString name;

    enum PropertyIndex {
        Id = 0,
        Name,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("industries"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
};

#endif // INDUSTRIESOBJECT_H

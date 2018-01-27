#ifndef USERSINDUSTRIESOBJECT_H
#define USERSINDUSTRIESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UsersindustriesObject : public TSqlObject, public QSharedData
{
public:
    int relphone {0};
    int relindustry {0};

    enum PropertyIndex {
        Relphone = 0,
        Relindustry,
    };

    int primaryKeyIndex() const override { return -1; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("usersindustries"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int relphone READ getrelphone WRITE setrelphone)
    T_DEFINE_PROPERTY(int, relphone)
    Q_PROPERTY(int relindustry READ getrelindustry WRITE setrelindustry)
    T_DEFINE_PROPERTY(int, relindustry)
};

#endif // USERSINDUSTRIESOBJECT_H

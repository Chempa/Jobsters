#ifndef USERSCOMPANIESOBJECT_H
#define USERSCOMPANIESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserscompaniesObject : public TSqlObject, public QSharedData
{
public:
    int relphone {0};
    int relcompany {0};

    enum PropertyIndex {
        Relphone = 0,
        Relcompany,
    };

    int primaryKeyIndex() const override { return -1; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QLatin1String("userscompanies"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int relphone READ getrelphone WRITE setrelphone)
    T_DEFINE_PROPERTY(int, relphone)
    Q_PROPERTY(int relcompany READ getrelcompany WRITE setrelcompany)
    T_DEFINE_PROPERTY(int, relcompany)
};

#endif // USERSCOMPANIESOBJECT_H

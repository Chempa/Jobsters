#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT users_indexView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  users_indexView() : TActionView() { }
  users_indexView(const users_indexView &) : TActionView() { }
  QString toString();
};

QString users_indexView::toString()
{
  responsebody.reserve(1635);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n\r\n<h1>Listing Users</h1>\r\n\r\n");
  echo(linkTo("New entry", urla("create")));
  responsebody += QLatin1String("<br />\r\n<br />\r\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\r\n  <tr>\r\n    <th>ID</th>\r\n    <th>Name</th>\r\n    <th>Phone</th>\r\n    <th>Country</th>\r\n    <th>Password</th>\r\n    <th></th>\r\n  </tr>\r\n  ");
  tfetch(QList<Users>, usersList);
for (const auto &i : usersList) {;
  responsebody += QLatin1String("<tr>\r\n    <td>");
  eh(i.id());
  responsebody += QLatin1String("</td>\r\n    <td>");
  eh(i.name());
  responsebody += QLatin1String("</td>\r\n    <td>");
  eh(i.phone());
  responsebody += QLatin1String("</td>\r\n    <td>");
  eh(i.country());
  responsebody += QLatin1String("</td>\r\n    <td>");
  eh(i.password());
  responsebody += QLatin1String("</td>\r\n    <td>\r\n      ");
  echo(linkTo("Show", urla("show", i.id())));
  responsebody += QLatin1String("\r\n      ");
  echo(linkTo("Edit", urla("save", i.id())));
  responsebody += QLatin1String("\r\n      ");
  echo(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')"));
  responsebody += QLatin1String("\r\n    </td>\r\n  </tr>");
  };
  responsebody += QLatin1String("</table>\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(users_indexView)
T_REGISTER_VIEW(users_indexView)

#include "users_indexView.moc"

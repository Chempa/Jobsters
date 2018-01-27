#include <QtCore>
#include <TreeFrogView>
#include "industries.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT industries_indexView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  industries_indexView() : TActionView() { }
  industries_indexView(const industries_indexView &) : TActionView() { }
  QString toString();
};

QString industries_indexView::toString()
{
  responsebody.reserve(1366);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n\r\n<h1>Listing Industries</h1>\r\n\r\n");
  echo(linkTo("New entry", urla("create")));
  responsebody += QLatin1String("<br />\r\n<br />\r\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\r\n  <tr>\r\n    <th>ID</th>\r\n    <th>Name</th>\r\n    <th></th>\r\n  </tr>\r\n  ");
  tfetch(QList<Industries>, industriesList);
for (const auto &i : industriesList) {;
  responsebody += QLatin1String("<tr>\r\n    <td>");
  eh(i.id());
  responsebody += QLatin1String("</td>\r\n    <td>");
  eh(i.name());
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

Q_DECLARE_METATYPE(industries_indexView)
T_REGISTER_VIEW(industries_indexView)

#include "industries_indexView.moc"

#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT users_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  users_showView() : TActionView() { }
  users_showView(const users_showView &) : TActionView() { }
  QString toString();
};

QString users_showView::toString()
{
  responsebody.reserve(1225);
  tfetch(Users, users);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Showing Users</h1>\r\n<dt>ID</dt><dd>");
  eh(users.id());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Name</dt><dd>");
  eh(users.name());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Phone</dt><dd>");
  eh(users.phone());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Country</dt><dd>");
  eh(users.country());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Password</dt><dd>");
  eh(users.password());
  responsebody += QLatin1String("</dd><br />\r\n\r\n");
  echo(linkTo("Edit", urla("save", users.id())));
  responsebody += QLatin1String(" |\r\n");
  echo(linkTo("Back", urla("index")));
  responsebody += QLatin1String("\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(users_showView)
T_REGISTER_VIEW(users_showView)

#include "users_showView.moc"

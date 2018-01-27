#include <QtCore>
#include <TreeFrogView>
#include "users.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT users_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  users_saveView() : TActionView() { }
  users_saveView(const users_saveView &) : TActionView() { }
  QString toString();
};

QString users_saveView::toString()
{
  responsebody.reserve(3581);
  tfetch(QVariantMap, users);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Editing Users</h1>\r\n\r\n<form ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<form method=\"post\">\r\n  "), (formTag(urla("save", users["id"])))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("<p>\r\n    <label>ID<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("users[id]", users["id"].toString(), a("readonly", "readonly")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Name<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("users[name]", users["name"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Phone<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("users[phone]", users["phone"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Country<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("users[country]", users["country"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Password<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("users[password]", users["password"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <input type=\"submit\" value=\"Update\" />\r\n  </p>\r\n</form>\r\n\r\n<a ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<a href=\"#\">Show"), (linkTo("Show", urla("show", users["id"])))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</a> |\r\n<a ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<a href=\"#\">Back"), (linkTo("Back", urla("index")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</a>\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(users_saveView)
T_REGISTER_VIEW(users_saveView)

#include "users_saveView.moc"

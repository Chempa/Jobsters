#include <QtCore>
#include <TreeFrogView>
#include "companies.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT companies_createView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  companies_createView() : TActionView() { }
  companies_createView(const companies_createView &) : TActionView() { }
  QString toString();
};

QString companies_createView::toString()
{
  responsebody.reserve(2883);
  tfetch(QVariantMap, companies);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>New Companies</h1>\r\n\r\n<form ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<form method=\"post\">\r\n  "), (formTag(urla("create")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("<p>\r\n    <label>Name<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("companies[name]", companies["name"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Email<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("companies[email]", companies["email"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Website<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("companies[website]", companies["website"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Imagepath<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("companies[imagepath]", companies["imagepath"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <input type=\"submit\" value=\"Create\" />\r\n  </p>\r\n</form>\r\n\r\n<a ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<a href=\"#\">Back"), (linkTo("Back", urla("index")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</a>\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(companies_createView)
T_REGISTER_VIEW(companies_createView)

#include "companies_createView.moc"

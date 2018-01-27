#include <QtCore>
#include <TreeFrogView>
#include "industries.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT industries_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  industries_saveView() : TActionView() { }
  industries_saveView(const industries_saveView &) : TActionView() { }
  QString toString();
};

QString industries_saveView::toString()
{
  responsebody.reserve(2463);
  tfetch(QVariantMap, industries);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Editing Industries</h1>\r\n\r\n<form ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<form method=\"post\">\r\n  "), (formTag(urla("save", industries["id"])))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("<p>\r\n    <label>ID<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("industries[id]", industries["id"].toString(), a("readonly", "readonly")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <label>Name<br /><input ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<input />"), (inputTextTag("industries[name]", industries["name"].toString()))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(" />");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</label>\r\n  </p>\r\n  <p>\r\n    <input type=\"submit\" value=\"Update\" />\r\n  </p>\r\n</form>\r\n\r\n<a ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<a href=\"#\">Show"), (linkTo("Show", urla("show", industries["id"])))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</a> |\r\n<a ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<a href=\"#\">Back"), (linkTo("Back", urla("index")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("</a>\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(industries_saveView)
T_REGISTER_VIEW(industries_saveView)

#include "industries_saveView.moc"

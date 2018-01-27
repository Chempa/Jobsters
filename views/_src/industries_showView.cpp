#include <QtCore>
#include <TreeFrogView>
#include "industries.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT industries_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  industries_showView() : TActionView() { }
  industries_showView(const industries_showView &) : TActionView() { }
  QString toString();
};

QString industries_showView::toString()
{
  responsebody.reserve(972);
  tfetch(Industries, industries);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Showing Industries</h1>\r\n<dt>ID</dt><dd>");
  eh(industries.id());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Name</dt><dd>");
  eh(industries.name());
  responsebody += QLatin1String("</dd><br />\r\n\r\n");
  echo(linkTo("Edit", urla("save", industries.id())));
  responsebody += QLatin1String(" |\r\n");
  echo(linkTo("Back", urla("index")));
  responsebody += QLatin1String("\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(industries_showView)
T_REGISTER_VIEW(industries_showView)

#include "industries_showView.moc"

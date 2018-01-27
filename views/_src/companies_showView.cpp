#include <QtCore>
#include <TreeFrogView>
#include "companies.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT companies_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  companies_showView() : TActionView() { }
  companies_showView(const companies_showView &) : TActionView() { }
  QString toString();
};

QString companies_showView::toString()
{
  responsebody.reserve(1263);
  tfetch(Companies, companies);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
    responsebody += QLatin1String("<html>\r\n<head>\r\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\r\n  <title>");
  eh(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\r\n</head>\r\n<body>\r\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\r\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n\r\n<h1>Showing Companies</h1>\r\n<dt>ID</dt><dd>");
  eh(companies.id());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Name</dt><dd>");
  eh(companies.name());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Email</dt><dd>");
  eh(companies.email());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Website</dt><dd>");
  eh(companies.website());
  responsebody += QLatin1String("</dd><br />\r\n<dt>Imagepath</dt><dd>");
  eh(companies.imagepath());
  responsebody += QLatin1String("</dd><br />\r\n\r\n");
  echo(linkTo("Edit", urla("save", companies.id())));
  responsebody += QLatin1String(" |\r\n");
  echo(linkTo("Back", urla("index")));
  responsebody += QLatin1String("\r\n\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(companies_showView)
T_REGISTER_VIEW(companies_showView)

#include "companies_showView.moc"

#include <QtCore>
#include <TreeFrogView>
#include "jobs.h" 
#include "industries.h" 
#include "companies.h" 
#include "users.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT jobs_addjobView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  jobs_addjobView() : TActionView() { }
  jobs_addjobView(const jobs_addjobView &) : TActionView() { }
  QString toString();
};

QString jobs_addjobView::toString()
{
  responsebody.reserve(7595);
  responsebody += QLatin1String("<!DOCTYPE html>\r\n");
          responsebody += QLatin1String("<head>\r\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\r\n    <link rel=\"stylesheet\" href=\"/css/addjob.css\">\r\n    <link rel=\"stylesheet\" href=\"/css/standard.css\">\r\n    <title></title>\r\n\r\n</head>\r\n\r\n<body>\r\n<div id=\"pagewrapper\">\r\n<div id=\"header\">\r\n    <a><h1>Jobsters<sub>infinite jobs</sub></h1></a>\r\n    <hr>\r\n    <ul id=\"navilist\">\r\n        <li>");
  echo(linkTo("Home",url("Jobs","index")));
  responsebody += QLatin1String("</li>\r\n        <li>");
  echo(linkTo("Advertise",url("Jobs","addjob")));
  responsebody += QLatin1String("</li>\r\n        ");
  tfetch(Users,loginUser);
for(int i = 0 ;i<1; i++){
	QString atag = "<li><a href=\"/Account/signup\">Register</a></li><li><a href=\"/Account/login\">Login</a></li>";
	if(!loginUser.isNull()){
		atag = "<li><a href=\"/Account/logout\">Logout</a></li>";
	};
  responsebody += QLatin1String("<span>");
  echo(atag);
  responsebody += QLatin1String("\r\n        </span>");
  };
  responsebody += QLatin1String("        <li><a>About</a></li>\r\n    </ul>\r\n    <hr>\r\n</div>\r\n<div id=\"sidebar\">\r\n    <div id=\"searcher\"><hr><hr>\r\n        <form ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<form method=\"post\" name=\"fm\">\r\n            "), (formTag(url("Jobs","search")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("<input type=\"text\" name=\"jobtitle\" placeholder=\"eg. Programmer\"><br><hr><hr>\r\n            <input type=\"text\" name=\"location\" placeholder=\"eg. Kumasi\"><br><hr><hr><hr>\r\n            <input type=\"text\" name=\"companyname\" placeholder=\"eg.google\"><br><hr><hr>\r\n            <input type=\"text\" name=\"industryname\" placeholder=\"eg. Constructions\"><br><hr><hr>\r\n            <input type=\"number\" name=\"jobid\" placeholder=\"Job id eg. 12\"><br><hr><hr>\r\n            <input id=\"searchbtn\" type=\"submit\" value=\"Search\">\r\n            <br>\r\n           <p id=\"searchmessage\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\r\n            <br><br>\r\n        </form>\r\n    </div>\r\n    \r\n    <div id=\"dashboard\">\r\n        <p>Welcome <span>Guest</span></p><br>\r\n        <form ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<form id=\"userpreference\" method=\"post\">\r\n            "), (formTag(url("Account","userpreference")))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("<input type=\"hidden\" name=\"selfcontroller\" ");
  echo("value=\"" + controller()->name() + "\"");
  responsebody += QLatin1String(">\r\n            <input type=\"hidden\" name=\"selfaction\" ");
  echo("value=\"" + controller()->activeAction() + "\"");
  responsebody += QLatin1String(">\r\n            <div id=\"usercompanies\">\r\n                <label class=\"l1\">My Companies</label><br><hr><hr>\r\n                ");
  tfetch(QList<Companies>, companyList);
tfetch(QStringList,ucrel);
for (const auto &i : companyList) {
	QString checkattrib = "";
	if(ucrel.contains(QString::number(i.id()))){
		checkattrib = "checked";
	};
  responsebody += QLatin1String("<p>\r\n                <input type=\"checkbox\" name=\"mycompanies[]\" onchange=\"modfn(this)\" ");
  echo("value=\"" + QString::number(i.id()) + "\" " + checkattrib);
  responsebody += QLatin1String("><span>");
  eh("  "+ i.name());
  responsebody += QLatin1String("</span><br><br></p>");
  };
  responsebody += QLatin1String("            </div>\r\n        \r\n            <div id=\"userindustries\">\r\n                <label class=\"l1\">My Industries</label><br><hr><hr>\r\n                ");
  tfetch(QList<Industries>, industryList);
tfetch(QStringList,uirel);
for (const auto &i : industryList) {
	QString checkattrib = "";
	if(uirel.contains(QString::number(i.id()))){
		checkattrib = "checked";
	};
  responsebody += QLatin1String("<p>\r\n                <input type=\"checkbox\" name=\"myindustries[]\" onchange=\"modfn(this)\" ");
  echo("value=\"" + QString::number(i.id()) + "\" " + checkattrib);
  responsebody += QLatin1String("><span>");
  eh("  "+i.name());
  responsebody += QLatin1String("</span><br><br><br></p>");
  };
  responsebody += QLatin1String("            </div> \r\n            <br><br>\r\n            \r\n            <br><br>\r\n            <hr><hr><input id=\"updatepreference\" type=\"submit\" value=\"Update\">\r\n\r\n        </form>\r\n\r\n    </div>\r\n</div>\r\n<div id=\"content\">\r\n    <div id=\"formwrapper\">\r\n        <form ");
  do { THtmlParser ___pr = THtmlParser::mergeElements(tr("<form method=\"post\">\r\n        "), (formTag(url("Jobs","addjob"),Tf::Post,true))); echo(___pr.at(1).attributesString());
  responsebody += QLatin1String(">");
  eh(___pr.at(1).text); echo(___pr.childElementsToString(1)); } while (0);
  responsebody += QLatin1String("<p id=\"addjobmessage\"></p>\r\n            <input class=\"input\" type=\"text\" name=\"jobtitle\" placeholder=\"Job Title\"><br>\r\n            <input class=\"input\" type=\"text\" name=\"location\" placeholder=\"Job location\"><br>\r\n            <input class=\"input\" type=\"text\" name=\"wage\" placeholder=\"Wage (per month , per annum)\"><br>\r\n            <textarea name=\"shortdescription\" placeholder=\"Please describe the job and its requirement here ...\"></textarea><br>\r\n            <input class=\"input\" type=\"date\" name=\"closingdate\"><br>\r\n            <select class=\"input\" type=\"text\" name=\"industryname\" placeholder=\"Industry\">\r\n                ");
  tfetch(QList<Industries>, industryList2);
for(const auto &i : industryList2){;
  responsebody += QLatin1String("<span>\r\n                    <option ");
  echo("value=\""+QString::number(i.id())+"\"");
  responsebody += QLatin1String(">\r\n                        <p>");
  eh(i.name());
  responsebody += QLatin1String("</p>\r\n                    </option>\r\n                </span>");
  };
  responsebody += QLatin1String("            </select><br>\r\n            <input list=\"listofcompanies\" class=\"input\" type=\"text\" name=\"companyname\" placeholder=\"Company's name\">\r\n            <datalist id=\"listofcompanies\">\r\n                ");
  tfetch(QList<Companies>, companyList2);
for(const auto &i : companyList2){;
  responsebody += QLatin1String("<span>\r\n                    <option ");
  echo("value=\""+i.name()+"\"");
  responsebody += QLatin1String(">\r\n                        <p>");
  eh(i.name());
  responsebody += QLatin1String("</p>\r\n                    </option>\r\n                </span>");
  };
  responsebody += QLatin1String("<br>\r\n            </datalist>\r\n            <input class=\"input\" type=\"email\" name=\"email\" placeholder=\"eg. admin@jobsters.com\"><br>\r\n            <input class=\"input\" type=\"url\" name=\"website\" placeholder=\"Company's website\"><br>\r\n            <fieldset><legend>Company's Logo</legend>\r\n            <input id=\"file\" type=\"file\" name=\"picture\">\r\n            </fieldset><br>\r\n            <input id=\"submit\" type=\"submit\" value=\"Submit\"><br>\r\n        </form>\r\n    </div>\r\n</div>\r\n\r\n<div id=\"delimiter\"></div>\r\n</div>\r\n<footer>\r\n    All Rights Reserved &copy 2017 Cyrux Mensah\r\n</footer>\r\n</body>\r\n</html>\r\n");

  return responsebody;
}

Q_DECLARE_METATYPE(jobs_addjobView)
T_REGISTER_VIEW(jobs_addjobView)

#include "jobs_addjobView.moc"

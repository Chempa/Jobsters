#include "accountcontroller.h"
#include <QTime>
#include "companies.h"
#include "industries.h"
#include "usersindustries.h"
#include "userscompanies.h"

AccountController::AccountController(const AccountController &)
    : ApplicationController()
{ }
void AccountController::login()
{
    // write code
    switch (httpRequest().method()) {
    case Tf::Get:
        sidebarsetup();
        render();
        break;

    case Tf::Post: {
        QString phone = httpRequest().formItemValue("phone");
    	QString password = httpRequest().formItemValue("password");

    	Users user = Users::authenticate(phone, password);
    	if (!user.isNull()) {
     	    userLogin(&user);
    	    redirect(url("Jobs","index"));
    	} else {
        	QString message = "Login failed";
        	texport(message);
            sidebarsetup();
        	render("form");
    	}
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}
void AccountController::sidebarsetup(){
    QString phone = identityKeyOfLoginUser();
    Users loginUser = Users::getByIdentityKey(phone);

    auto companyList = Companies::getAll();
    texport(companyList);
    auto industryList = Industries::getAll();
    texport(industryList);
    if(!loginUser.isNull()){
        QList<Usersindustries> uirel1 = Usersindustries::getOnCondition(loginUser.id());
        QList<Userscompanies> ucrel1 = Userscompanies::getOnCondition(loginUser.id());
        QStringList uirel;
        for(int i=0;i<uirel1.count();i++){
            Usersindustries itm= uirel1[i];
            uirel<<QString::number(itm.relindustry());
        }
        QStringList ucrel;
        for(int i=0;i<ucrel1.count();i++){
            Userscompanies itm = ucrel1[i];
            ucrel << QString::number(itm.relcompany());
        }
        texport(uirel);
        texport(ucrel);
    }
}
void AccountController::logout()
{
    // write code
    userLogout();
    redirect(urla("login"));

}

void AccountController::signup()
{
    switch (httpRequest().method()) {
    case Tf::Get:{
        
        auto companyList = Companies::getAll();
        texport(companyList);
        auto industryList = Industries::getAll();
        texport(industryList);
        sidebarsetup();
        render();
        break;}

    case Tf::Post: {
        QString fullname = httpRequest().formItemValue("fullname");
    	QString phone = httpRequest().formItemValue("phone");
    	QString country = httpRequest().formItemValue("country");
    	QString password = httpRequest().formItemValue("password");
    	QString email = httpRequest().formItemValue("email");
    	//VALIDATE INPUTS HERE
    	Users user = Users::create(fullname, email, phone, country, password);
    	userLogin(&user);
    	redirect(url("Jobs","index"));
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void AccountController::resetpassword()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        sidebarsetup();
        render();
        break;

    case Tf::Post: {
        QString email = httpRequest().formItemValue("email");
        //VALIDATE INPUTS HERE
        
        if(Users::FCexist(email)){
            srand(QTime::currentTime().second());
            QString token = QString::number(rand());
            session().insert("resetToken",token);
            redirect(urla("resetpasswordphase2"));
            return;
        }else{
            QString emailproblem = "Sorry your E-mail address does not match any account";
            texport(emailproblem);
            sidebarsetup();
            render();
            return;
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void AccountController::resetpasswordphase2(){
    switch (httpRequest().method()) {
    case Tf::Get:
        sidebarsetup();
        render();
        break;

    case Tf::Post: {
        QString token = httpRequest().formItemValue("token");
        if(token!=session().value("resetToken").toString()){
            QString resetTokenWrong="Incorrect token";
            texport(resetTokenWrong);
            sidebarsetup();
            render();
            return;
        }else{
            session().insert("resetToken","0");
            session().insert("permitReset","accept");
            redirect(urla("resetpasswordphase3"));
            sidebarsetup();
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}
void AccountController::resetpasswordphase3(){
    switch (httpRequest().method()) {
    case Tf::Get:
        sidebarsetup();
        render();
        break;

    case Tf::Post: {
        QString password = httpRequest().formItemValue("newpassword");
        QString confirm = httpRequest().formItemValue("confirmpassword");
        if(session().value("permitReset").toString()!="accept"){
            QString sessionexpire="Sorry session expired";
            texport(sessionexpire);
            sidebarsetup();
            render();
            return;
        }else{
            session().insert("permitReset","");
            redirect(url("Jobs","index"));
            sidebarsetup();
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void AccountController::userpreference()
{
    QString phone = identityKeyOfLoginUser();
    Users loginUser = Users::getByIdentityKey(phone);


    switch (httpRequest().method()) {
    case Tf::Post: {
        QString c = httpRequest().formItemValue("selfcontroller");
        QString a = httpRequest().formItemValue("selfaction");
        
        QStringList lst = httpRequest().formItemList("myindustries");
        Usersindustries::removeAll(loginUser.id());
        for(int i=0 ; i<lst.count() ; i++){
            QString itm = lst[i];
            Usersindustries::create(loginUser.id(),itm.toInt());
        }
        int num = lst.count();
        QString notice = loginUser.phone() + " " + QString::number(num) ;
        lst.clear();
        lst = httpRequest().formItemList("mycompanies");
        Userscompanies::removeAll(loginUser.id());
        Userscompanies aa;
        for(int i=0 ; i<lst.count() ; i++){
            QString itm = lst[i];
            aa = Userscompanies::create(loginUser.id(),itm.toInt());
        }
        num = lst.count();
        notice = notice + " " + QString::number(num) ;
        tflash(notice);
        if(aa.isNull())redirect(url("Jobs","index"));
        redirect(url(c,a));
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}
// Don't remove below this line
T_REGISTER_CONTROLLER(accountcontroller)

#include "jobscontroller.h"
#include "jobs.h"
#include <QDateTime>
#include "companies.h"
#include "industries.h"
#include "users.h"
#include "usersindustries.h"
#include "userscompanies.h"

JobsController::JobsController(const JobsController &)
    : ApplicationController()
{}

void JobsController::index()
{
	// write code
    auto companyList = Companies::getAll();
    texport(companyList);
    auto industryList = Industries::getAll();
    texport(industryList);
	auto jobsList = Jobs::getAll();
    texport(jobsList);
    sidebarsetup();
    render();
}
void JobsController::sidebarsetup(){
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
        texport(loginUser);
    }
}
void JobsController::show(const QString &id)
 {   // write code

	if(id.toInt()>0){
        Jobs job = Jobs::get(id.toInt());
        if(job.isNull()){
            redirect(urla("index"));
        }else{
            session().insert("recentshowid",QString::number(job.id()));
            texport(job);
            sidebarsetup();
            render();
        }
    }else{
        redirect(urla("index"));
    }
}
void JobsController::show(){
    redirect(urla("show",session().value("recentshowid").toString()));
}

void JobsController::addjob()
{
    // write code
    switch (httpRequest().method()) {
    case Tf::Get:{
        sidebarsetup();
        auto companyList2 = Companies::getAll();
        texport(companyList2);
        auto industryList2 = Industries::getAll();
        texport(industryList2);
        render();
        return;
        break;}

    case Tf::Post: {
    	QString jobtitle = httpRequest().formItemValue("jobtitle");
    	QString location = httpRequest().formItemValue("location");
    	QString wage = httpRequest().formItemValue("wage");
    	QString shortdescription = httpRequest().formItemValue("shortdescription");
    	QString closingdate = httpRequest().formItemValue("closingdate");
    	QString industryid = httpRequest().formItemValue("industryname");
    	QString companyname = httpRequest().formItemValue("companyname");
    	QString email = httpRequest().formItemValue("email");
    	QString website = httpRequest().formItemValue("website");
    	TMultipartFormData &formdata = httpRequest().multipartFormData();
		QString filename=formdata.originalFileName("picture");
		
        int returnval = Companies::getIdByName(companyname);
        Companies company;
        if(returnval == -1){
            formdata.renameUploadedFile("picture", "public/images/imagesofcompanies/"+ companyname + filename);
            QString imagepath = "/images/imagesofcompanies/"+ companyname + filename;
    		company = Companies::create(companyname, email,website,imagepath);
        }else{
            company = Companies::get(returnval);
        }

		Jobs job = Jobs::create(jobtitle,location,wage,shortdescription, QDateTime::currentDateTime(), QDateTime::fromString(closingdate + " 23-59-59","yyyy-MM-dd hh-mm-ss"),industryid.toInt(),company.id());
		QString message;
        message = filename;
        texport(message);
        sidebarsetup();
        render();

        //
        QString url1 = "http://sms.nasaramobile.com/api?";
        QString apikey = "api_key=";
        QString senderid = "&sender_id=Jobsters";
        QString phone = "&phone=";
        QString sms = "&message=";
        QNetworkAccessManager netwk;

        //THIS PART NEEDS MODIFICATION
        QStringList phone_com = Users::getPhonesByCompany(QString::number(company.id()));
        QStringList phone_ind = Users::getPhonesByIndustry(industryid);
        for(int i = 0 ;i<phone_com.count();i++){
            QString urlstring = url1 + apikey + senderid +phone + phone_com[i] +sms;
            QUrl url(urlstring);
            netwk.get(QNetworkRequest(url));
        }
        for(int i = 0 ;i<phone_ind.count();i++){
            if(phone_com.contains(phone_ind[i]))continue;
            QString urlstring = url1 + apikey + senderid +phone + phone_ind[i] +sms;
            QUrl url(urlstring);
            netwk.get(QNetworkRequest(url));
        }
		return;
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void JobsController::remove(QString &id)
{
    // write code
    if(id==""){
        //ERROR OCURRED HERE
    }else{
    	Jobs job = Jobs::get(id.toInt());
    	if(job.isNull()){
    		redirect(urla("jobremovefailed"));
    		return;
    	}else{
    		if(!job.remove()){
    			redirect(urla("jobremovefailed"));
    		}else{
    			redirect(urla("index"));
    		}
    	}
    }
}
void JobsController::search()
{
    QString jobtitle;
    QString location;
    QString industryname;
    QString companyname;
    switch (httpRequest().method()) {
    case Tf::Get:{
        redirect(urla("index"));
        QList<Jobs> jobsList = Jobs::jobquery(jobtitle,location,industryname,companyname);
        texport(jobsList);
        sidebarsetup();
        render();
        return;
        break;}

    case Tf::Post: {
        jobtitle = httpRequest().formItemValue("jobtitle");
        location = httpRequest().formItemValue("location");
        industryname = httpRequest().formItemValue("industryname");
        companyname = httpRequest().formItemValue("companyname");
        QString jobid = httpRequest().formItemValue("jobid");

        if(jobid!=""){
            redirect(url("Jobs","show",jobid));
            return;
        }
        
        if(industryname!="")
        industryname = QString::number(Industries::getIdByName(industryname));
        if(companyname!="")
        companyname = QString::number(Companies::getIdByName(companyname));        


        QList<Jobs> jobsList = Jobs::jobquery(jobtitle,location,industryname,companyname);
        QString note;
        if(jobsList.count()==0){
            note = "No Results found...";
        }else{
            note = QString::number(jobsList.count()) + " Results Found...";
        }
        texport(note);
        texport(jobsList);
        sidebarsetup();
        render();
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}


// Don't remove below this line
T_REGISTER_CONTROLLER(jobscontroller)

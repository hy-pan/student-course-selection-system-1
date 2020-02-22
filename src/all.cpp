#include"all.h"
#include<string.h>
course::course(int kxh,char klx[],char kmc[],int kxf){
	kxuhao=kxh;
	strcpy(kleixing,klx);
	strcpy(kmincheng,kmc);
	kxuefen=kxf;
}
char *course::klx(){
	return kleixing;
}
char *course::kmc(){
	return kmincheng;
}
int course::kxh(){
	return kxuhao;
}
int course::kxf(){
	return kxuefen;
}


student::student(int sn,char sna[]){
	snum=sn;
	strcpy(sname,sna);

}



UGstudent::UGstudent(int sn,char sna[],char ban[]):student(sn,sna){
	strcpy(banname,ban);
	strcpy(xueli,"本科生");
}
bool UGstudent::chaxunxuehao(int sn1){
	if(sn1==snum){
		return true;
	}
	else{
		return false;
	}
}
char *UGstudent::printname(){
	return sname;
}
char *UGstudent::printban(){
	return banname;
}
char *UGstudent::printxue(){
	return xueli;
}



Gstudent::Gstudent(int sn,char sna[],char ban[]):student(sn,sna){
	strcpy(daoname,ban);
	strcpy(xueli,"研究生");
}
bool Gstudent::chaxunxuehao(int sn1){
	if(sn1==snum){
		return true;
	}
	else{
		return false;
	}
}
char *Gstudent::printname(){
	return sname;
}
char *Gstudent::printdao(){
	return daoname;
}
char *Gstudent::printxue(){
	return xueli;
}
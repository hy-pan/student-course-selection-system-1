class course{
private:
	char kleixing[10];
	char kmincheng[20];
    int kxuhao;
	int kxuefen;
public:
	course(int kxh,char klx[],char kmc[],int kxf);
	char *klx();
	char *kmc();
	int kxh();
	int kxf();
};
class student{
protected:
	int snum;
	char sname[10];
	char xueli[10];
	int smenshu;
public:
	student(int sn,char sna[]);
};
class UGstudent:public student{
private:
	char banname[10];
public:
	UGstudent(int sn,char sna[],char ban[]);
    bool chaxunxuehao(int sn1);
	char *printname();
	char *printban();
	char *printxue();

};
class Gstudent:public student{
private:
	char daoname[10];
public:
	Gstudent(int sn,char sna[],char ban[]);
	bool chaxunxuehao(int sn1);
	char *printname();
	char *printdao();
	char *printxue();
};

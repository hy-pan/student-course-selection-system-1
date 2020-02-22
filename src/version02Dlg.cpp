/*学生选课系统
Developer:AmazingU
Date:2016.4.20
*/

// version02Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "version02.h"
#include "version02Dlg.h"
#include "afxdialogex.h"
#include "all.h"	

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int yixuankrs[12]={0};//这里的变量要在控件之间进行传递，所以直接定义在前面
int yixuanms=0;
int chosexh=0;
int chosehanghao=0;
int tuihanghao=0;

int k=0;//这两个是用来存储已选过课的学号
int yixuannum[45]={0};

UGstudent ugs[]={UGstudent(2014001,"李强","张老师"),UGstudent(2014002,"王娜","李老师"),UGstudent(2014003,"李飞","王老师"),
		UGstudent(2014004,"王小明","张老师"),UGstudent(2014005,"陈小霞","李老师"),UGstudent(2014006,"李玉刚","王老师"),
		UGstudent(2014007,"钟丽丽","张老师"),UGstudent(2014008,"谢飞翔","李老师"),UGstudent(2014009,"吴胜利","王老师"),
		UGstudent(2014010,"程思青","张老师"),UGstudent(2014011,"邹安邦","李老师"),UGstudent(2014012,"曹思青","王老师"),
		UGstudent(2014013,"卢永祥","张老师"),UGstudent(2014014,"王凯","李老师"),UGstudent(2014015,"王胜利","王老师"),
		UGstudent(2014016,"李珊","张老师"),UGstudent(2014017,"魏星","李老师"),UGstudent(2014018,"史东","王老师"),
		UGstudent(2014019,"谢喜莲","张老师"),UGstudent(2014020,"鲁迪","李老师"),UGstudent(2014021,"程长喜","王老师"),
		UGstudent(2014022,"齐莉莉","张老师"),UGstudent(2014023,"何正明","李老师"),UGstudent(2014024,"赵祥海","王老师"),
		UGstudent(2014025,"卢志胜","张老师"),UGstudent(2014026,"谢喜贤","李老师"),UGstudent(2014027,"邹安青","王老师"),
		UGstudent(2014028,"蔡飞翔","张老师"),UGstudent(2014029,"吴东升","李老师"),UGstudent(2014030,"李建军","王老师")};

	Gstudent gs[]={Gstudent(2014101,"李小强","张教授"),Gstudent(2014102,"王妮娜","李教授"),Gstudent(2014103,"李红飞","王教授"),
		Gstudent(2014104,"王大明","张教授"),Gstudent(2014105,"陈飞霞","李教授"),Gstudent(2014106,"李成刚","张教授"),
		Gstudent(2014107,"钟环丽","张教授"),Gstudent(2014108,"谢卫翔","李教授"),Gstudent(2014109,"吴卫国","张教授"),
		Gstudent(2014110,"程思思","张教授"),Gstudent(2014111,"邹爱国","李教授"),Gstudent(2014112,"曹宝清","张教授"),
		Gstudent(2014113,"卢新阳","张教授"),Gstudent(2014114,"王大凯","李教授"),Gstudent(2014115,"王福利","张教授")};

	course c[]={course(1,"学科基础","英语口语",4),course(2,"学科基础","高等数学",2),course(3,"学科基础","大学物理",1),
		course(4,"学科基础","政治经济学",1),course(5,"专业基础","程序设计",2),course(6,"专业基础","数据结构",2),
		course(7,"专业基础","计算机原理",3),course(8,"专业基础","汇编语言",3),course(9,"专业核心","OPP程序设计",2),
		course(10,"专业核心","编译原理",2),course(11,"专业核心","微机原理",3),course(12,"专业核心","计算机网络",3)};


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cversion02Dlg 对话框




Cversion02Dlg::Cversion02Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cversion02Dlg::IDD, pParent)
	, xuehao(0)
	, printmenshu(0)
	, yixuanxf(0)
	, xuefei(0)
	, xuankezrs(0)
	, printxueli(_T(""))
	, inputkmc(_T(""))
	, inputklx(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cversion02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, kexuan);//这些变量都是直接添加在各个控件上的变量
	DDX_Text(pDX, IDC_EDIT1, xuehao);
	DDX_Text(pDX, IDC_EDIT8, printmenshu);
	DDX_Text(pDX, IDC_EDIT9, yixuanxf);
	DDX_Text(pDX, IDC_EDIT10, xuefei);
	DDX_Control(pDX, IDC_LIST2, yixuan);
	DDX_Text(pDX, IDC_EDIT5, xuankezrs);
	DDX_Text(pDX, IDC_EDIT4, printxueli);
	DDX_Text(pDX, IDC_EDIT7, inputkmc);
	DDX_Text(pDX, IDC_EDIT6, inputklx);
}

BEGIN_MESSAGE_MAP(Cversion02Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &Cversion02Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cversion02Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Cversion02Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Cversion02Dlg::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Cversion02Dlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &Cversion02Dlg::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// Cversion02Dlg 消息处理程序

BOOL Cversion02Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CRect rect;  //两个列表的初始化，一个包括五列，一个包括四列
	kexuan.GetClientRect(&rect);
	kexuan.SetExtendedStyle(kexuan.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	kexuan.InsertColumn(0, _T("序号"), LVCFMT_CENTER, rect.Width()/5, 0); 
	kexuan.InsertColumn(1, _T("课程类型"), LVCFMT_CENTER, rect.Width()/5, 1);
	kexuan.InsertColumn(2, _T("课程名称"), LVCFMT_CENTER, rect.Width()/5, 2);
	kexuan.InsertColumn(3, _T("学分"), LVCFMT_CENTER, rect.Width()/5, 3);
	kexuan.InsertColumn(4, _T("已选人数"), LVCFMT_CENTER, rect.Width()/5, 4);

	CRect rect1;
	yixuan.GetClientRect(&rect1);
	yixuan.SetExtendedStyle(yixuan.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	yixuan.InsertColumn(0, _T("序号"), LVCFMT_CENTER, rect1.Width()/4, 0); 
	yixuan.InsertColumn(1, _T("课程类型"), LVCFMT_CENTER, rect1.Width()/4, 1);
	yixuan.InsertColumn(2, _T("课程名称"), LVCFMT_CENTER, rect1.Width()/4, 2);
	yixuan.InsertColumn(3, _T("学分"), LVCFMT_CENTER, rect1.Width()/4, 3);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cversion02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cversion02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cversion02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cversion02Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	while ( kexuan.DeleteItem (0));//首先将kexuan清空，否则后面产生的列表都会加在原来的列表后面。这里只需循环清掉第一行就可以，因为清掉一行下面一行会自动上来

	if(inputkmc.IsEmpty()){//判断输入课程名称是否为空
	int q=0,k=0;
	for(q=0;q<12;q++){
		if(inputklx==c[q].klx()){
			CString kmc,kxh,kxf,krs;//下面SetItemText中参数是CString类型，必须将各个参数转为CString
			kmc=c[q].kmc();
			krs.Format(_T("%d"),yixuankrs[q]); //正常应该写成krs.Format("%d",yixuankrs[q]);但是会报错，前面加上_T就可以了
	        kxh.Format(_T("%d"),c[q].kxh());
	        kxf.Format(_T("%d"),c[q].kxf());
	        kexuan.InsertItem(k,kxh);
	        kexuan.SetItemText(k,1,inputklx);
	        kexuan.SetItemText(k,2,kmc);
	        kexuan.SetItemText(k,3,kxf);
			kexuan.SetItemText(k,4,krs);
			k++;
		}
	}
	if(k==0){
		MessageBox(_T("请输入正确的课程类型"),_T("错误"),MB_OK|MB_ICONERROR);
		for(int p=0;p<12;p++){ //前面已经将列表清空，这里提示错误信息之后，将所有课程显示出来
	  CString klx,kmc,kxh,kxf,krs;
	  klx=c[p].klx();
	  kmc=c[p].kmc();
	  krs.Format(_T("%d"),yixuankrs[p]);
	  kxh.Format(_T("%d"),c[p].kxh());
	  kxf.Format(_T("%d"),c[p].kxf());
	  kexuan.InsertItem(p,kxh);
	  kexuan.SetItemText(p,1,klx);
	  kexuan.SetItemText(p,2,kmc);
	  kexuan.SetItemText(p,3,kxf);
	  kexuan.SetItemText(p,4,krs);
	}
	}
	}
	else if(inputklx.IsEmpty()){//判断输入课程类型是否为空
	int l=0;
	for(l=0;l<12;l++){
		if(inputkmc==c[l].kmc()){
			CString klx,kxh,kxf,krs;
			klx=c[l].klx();
			krs.Format(_T("%d"),yixuankrs[l]);
	        kxh.Format(_T("%d"),c[l].kxh());
	        kxf.Format(_T("%d"),c[l].kxf());
	        kexuan.InsertItem(0,kxh);
	        kexuan.SetItemText(0,1,klx);
	        kexuan.SetItemText(0,2,inputkmc);
	        kexuan.SetItemText(0,3,kxf);
			kexuan.SetItemText(0,4,krs);
			break;
		}
	}
	if(l==12){
		MessageBox(_T("请输入正确的课程名称"),_T("错误"),MB_OK|MB_ICONERROR);
		for(int p=0;p<12;p++){
	  CString klx,kmc,kxh,kxf,krs;
	  klx=c[p].klx();
	  kmc=c[p].kmc();
	  krs.Format(_T("%d"),yixuankrs[p]);
	  kxh.Format(_T("%d"),c[p].kxh()); 
	  kxf.Format(_T("%d"),c[p].kxf());
	  kexuan.InsertItem(p,kxh);
	  kexuan.SetItemText(p,1,klx);
	  kexuan.SetItemText(p,2,kmc);
	  kexuan.SetItemText(p,3,kxf);
	  kexuan.SetItemText(p,4,krs);
	}
	}
	}
	else{
    int m=0;
	for(m=0;m<12;m++){
		if(inputkmc==c[m].kmc()&&inputklx==c[m].klx()){//如果输入课程类型和课程名称都不为空，判断课程类型和课程名称是否匹配
			CString kxh,kxf,krs;
			krs.Format(_T("%d"),yixuankrs[m]);
	        kxh.Format(_T("%d"),c[m].kxh());
	        kxf.Format(_T("%d"),c[m].kxf());
	        kexuan.InsertItem(0,kxh);
	        kexuan.SetItemText(0,1,inputklx);
	        kexuan.SetItemText(0,2,inputkmc);
	        kexuan.SetItemText(0,3,kxf);
			kexuan.SetItemText(0,4,krs);
			break;
		}
	}
	if(m==12){
		MessageBox(_T("请输入正确的课程类型和课程名称"),_T("错误"),MB_OK|MB_ICONERROR);
		for(int p=0;p<12;p++){
	  CString klx,kmc,kxh,kxf,krs;
	  klx=c[p].klx();
	  kmc=c[p].kmc();
	  krs.Format(_T("%d"),yixuankrs[p]);
	  kxh.Format(_T("%d"),c[p].kxh());   
	  kxf.Format(_T("%d"),c[p].kxf());
	  kexuan.InsertItem(p,kxh);
	  kexuan.SetItemText(p,1,klx);
	  kexuan.SetItemText(p,2,kmc);
	  kexuan.SetItemText(p,3,kxf);
	  kexuan.SetItemText(p,4,krs);
	}
	}
	}
	UpdateData(false);
}

void Cversion02Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	printmenshu=0;//将显示的选课门数、已选学分、学费清零
	yixuanxf=0;
	xuefei=0;
	yixuanms=0;//printmenshu是用来显示在MFC上，程序里处理的是yixuanms，最后将yxuanms赋给printmenshu，其实可以不用yixuanms，将yixuanms全部替换为printmenshu也可以
	if(yixuan.GetItemCount()!=0){//如果yixuan列表不为空，则选课总人数加1。
		xuankezrs++;
	}
	while ( yixuan.DeleteItem (0));//yixuan列表清空

	int i=0,j=0;
	for(i=0;i<30;i++){
		if(ugs[i].chaxunxuehao(xuehao)){
			CString edit1,edit2,edit3;
			edit1=ugs[i].printname();
			edit2=ugs[i].printban();
			edit3=ugs[i].printxue();
			SetDlgItemText(IDC_EDIT2,edit1);//这里也可以直接在控件上添加变量，直接赋给它。就像printxueli=edit3
			SetDlgItemText(IDC_EDIT3,edit2);
			//SetDlgItemText(IDC_EDIT3,edit3);
			printxueli=edit3;
			break;
		}
	}
	for(j=0;j<15;j++){
		if(gs[j].chaxunxuehao(xuehao)){
			CString edit1,edit2,edit3;
			edit1=gs[j].printname();
			edit2=gs[j].printdao();
			edit3=gs[j].printxue();
			SetDlgItemText(IDC_EDIT2,edit1);
			SetDlgItemText(IDC_EDIT3,edit2);
			//SetDlgItemText(IDC_EDIT3,edit3);
			printxueli=edit3;
			break;
		}
	}
	if(i==30&&j==15){
		INT_PTR nRes;
		nRes=MessageBox(_T("请输入正确的学号"),_T("错误"),MB_OK|MB_ICONERROR);
		return;  //这里不写return会直接运行下面的程序
	}else{
		yixuannum[k]=xuehao;//将找到的学号存在数组里，用来判断后面输入的学号是否前面输入过
		k++;
	}
	if(k>1){ //这里的k是从1开始的，即当k=1时，只输入了第一个学号，不用判断是否已经选过课
		for(int q=0;q<k-1;q++){ //这里注意q<k-1，当k=2时表示此时的学号是第二次输入的，需判断与第一次输入的学号是否相同，第一次的学号存在yixuannum[0]里
			if(xuehao==yixuannum[q]){
				MessageBox(_T("该学生已经选过课了"),_T("错误"),MB_OK|MB_ICONERROR);
				break;//这里如果写成return，不知道为什么选课总人数不会刷新了
			}
		}
	}
	
	while ( kexuan.DeleteItem (0));

	for(int p=0;p<12;p++){
	  CString klx,kmc,kxh,kxf,krs;
	  klx=c[p].klx();
	  kmc=c[p].kmc();
	  krs.Format(_T("%d"),yixuankrs[p]);
	  kxh.Format(_T("%d"),c[p].kxh()); 
	  kxf.Format(_T("%d"),c[p].kxf());
	  kexuan.InsertItem(p,kxh);
	  kexuan.SetItemText(p,1,klx);
	  kexuan.SetItemText(p,2,kmc);
	  kexuan.SetItemText(p,3,kxf);
	  kexuan.SetItemText(p,4,krs);
	}
    UpdateData(false);
}


void Cversion02Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(yixuanms>0){
	yixuanms--;//点击退课之后，选课门数-1
	CString str,str1,krs;
	int tuixf=0,tuixh=0;
	str=yixuan.GetItemText(tuihanghao,3);
	tuixf=_ttoi(str);//CString转为int
	yixuanxf=yixuanxf-tuixf;//已选学分减掉相应的学分

	str1=yixuan.GetItemText(tuihanghao,0);
	tuixh=_ttoi(str1)-1;//这里要注意课程序号是从1开始的，而对象数组和每门课已选人数数组是从0开始的

	yixuankrs[tuixh]--;//每门课已选人数-1

	if(printxueli=="本科生"&&tuixh>=0&&tuixh<=3){//两个列表控件属性已经设置为只能单选一行，所以点击一次这里只需减一次
				xuefei=xuefei-200*c[tuixh].kxf();
		    }
			else if(printxueli=="本科生"&&tuixh>=4&&tuixh<=7){
				xuefei=xuefei-150*c[tuixh].kxf();
			}
			else if(printxueli=="本科生"&&tuixh>=8&&tuixh<=11){
				xuefei=xuefei-100*c[tuixh].kxf();
			}
			else if(printxueli=="研究生"&&tuixh>=0&&tuixh<=3){
				xuefei=xuefei-200*c[tuixh].kxf();
			}
			else if(printxueli=="研究生"&&tuixh>=4&&tuixh<=7){
				xuefei=xuefei-180*c[tuixh].kxf();
			}
			else if(printxueli=="研究生"&&tuixh>=8&&tuixh<=11){
				xuefei=xuefei-150*c[tuixh].kxf();
			}

	printmenshu=yixuanms;
	yixuan.DeleteItem(tuihanghao);

	while ( kexuan.DeleteItem (0));

	for(int p=0;p<12;p++){
	  CString klx,kmc,kxh,kxf,krs;
	  klx=c[p].klx();
	  kmc=c[p].kmc();
	  krs.Format(_T("%d"),yixuankrs[p]);
	  kxh.Format(_T("%d"),c[p].kxh());    
	  kxf.Format(_T("%d"),c[p].kxf());
	  kexuan.InsertItem(p,kxh);
	  kexuan.SetItemText(p,1,klx);
	  kexuan.SetItemText(p,2,kmc);
	  kexuan.SetItemText(p,3,kxf);
	  kexuan.SetItemText(p,4,krs);
	}	
	}
	else{
        MessageBox(_T("已经退完全部课程"),_T("错误"),MB_OK|MB_ICONERROR);
	}
	UpdateData(false);
}


void Cversion02Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	if(printxueli!="本科生"&&printxueli!="研究生"){//防止没输学号直接点选课导致程序错误
		MessageBox(_T("请选输入学号"),_T("错误"),MB_OK|MB_ICONERROR);
		return;
	}

	if(yixuanms<5){  //yixuanms是从0开始的
    CString krs;
    yixuankrs[chosexh-1]++;//这里不能用chosehanghao，要用chosexh-1。因为如果不经过查询，chosehanghao=chosexh-1，但是如果查询成功之后，这里chosehanghao不一定等于chosexh-1
	krs.Format(_T("%d"),yixuankrs[chosexh-1]);
	kexuan.SetItemText(chosehanghao,4,krs);

	int n=0;
	for(n=0;n<12;n++){ //在这个循环里即使选择的是同一门课也会添加进yixuan，若是想在这里不添加同一门课，不易做到
		if(chosexh==c[n].kxh()){
			CString klx,kmc,kxf,kxh;
			klx=c[n].klx();
			kmc=c[n].kmc();
	        kxf.Format(_T("%d"),c[n].kxf());
			kxh.Format(_T("%d"),chosexh);
	        yixuan.InsertItem(yixuanms,kxh);
	        yixuan.SetItemText(yixuanms,1,klx);
	        yixuan.SetItemText(yixuanms,2,kmc);
	        yixuan.SetItemText(yixuanms,3,kxf);
			yixuanxf=yixuanxf+c[n].kxf();
			if(printxueli=="本科生"&&n>=0&&n<=3){
				xuefei=xuefei+200*c[n].kxf();
		    }
			else if(printxueli=="本科生"&&n>=4&&n<=7){
				xuefei=xuefei+150*c[n].kxf();
			}
			else if(printxueli=="本科生"&&n>=8&&n<=11){
				xuefei=xuefei+100*c[n].kxf();
			}
			else if(printxueli=="研究生"&&n>=0&&n<=3){
				xuefei=xuefei+200*c[n].kxf();
			}
			else if(printxueli=="研究生"&&n>=4&&n<=7){
				xuefei=xuefei+180*c[n].kxf();
			}
			else if(printxueli=="研究生"&&n>=8&&n<=11){
				xuefei=xuefei+150*c[n].kxf();
			}
			yixuanms++;
			break;
			}
		}
	}
	else{
		MessageBox(_T("最多选择5门课"),_T("错误"),MB_OK|MB_ICONERROR);
	}
	for(int i=0;i<=yixuanms;i++){ //在这里判断选择的是否是同一门课，若是同一门课则将其删掉。相应的学分、选课人数和学费也要减掉
		for(int j=i+1;j<=yixuanms;j++){
			if(yixuan.GetItemText(i,0)==yixuan.GetItemText(j,0)){
				CString str,str1,krs;
				int strnum=0,strnum1=0;
				str=yixuan.GetItemText(i,3);
				strnum=_ttoi(str);
				yixuanxf=yixuanxf-strnum;

				str1=yixuan.GetItemText(i,0);
				strnum1=_ttoi(str1)-1;

				yixuankrs[chosexh-1]--;
				krs.Format(_T("%d"),yixuankrs[chosexh-1]);
				kexuan.SetItemText(chosehanghao,4,krs);

				if(printxueli=="本科生"&&strnum1>=0&&strnum1<=3){
				xuefei=xuefei-200*c[strnum1].kxf();
		    }
			else if(printxueli=="本科生"&&strnum1>=4&&strnum1<=7){
				xuefei=xuefei-150*c[strnum1].kxf();
			}
			else if(printxueli=="本科生"&&strnum1>=8&&strnum1<=11){
				xuefei=xuefei-100*c[strnum1].kxf();
			}
			else if(printxueli=="研究生"&&strnum1>=0&&strnum1<=3){
				xuefei=xuefei-200*c[strnum1].kxf();
			}
			else if(printxueli=="研究生"&&strnum1>=4&&strnum1<=7){
				xuefei=xuefei-180*c[strnum1].kxf();
			}
			else if(printxueli=="研究生"&&strnum1>=8&&strnum1<=11){
				xuefei=xuefei-150*c[strnum1].kxf();
			}

				yixuan.DeleteItem(j);
				MessageBox(_T("已经选过该门课"),_T("错误"),MB_OK|MB_ICONERROR);
				yixuanms--;
				break;
			}
		}
	}
	printmenshu=yixuanms;

	while ( kexuan.DeleteItem (0));

	for(int p=0;p<12;p++){
	  CString klx,kmc,kxh,kxf,krs;
	  klx=c[p].klx();
	  kmc=c[p].kmc();
	  krs.Format(_T("%d"),yixuankrs[p]);
	  kxh.Format(_T("%d"),c[p].kxh()); 
	  kxf.Format(_T("%d"),c[p].kxf());
	  kexuan.InsertItem(p,kxh);
	  kexuan.SetItemText(p,1,klx);
	  kexuan.SetItemText(p,2,kmc);
	  kexuan.SetItemText(p,3,kxf);
	  kexuan.SetItemText(p,4,krs);
	}
	UpdateData(false);
}


void Cversion02Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
    {   
        // 获取被选择列表项第一个子项的文本和行号

		CString chosexuhao;
        chosexuhao = kexuan.GetItemText(pNMListView->iItem, 0);
		chosexh=_ttoi(chosexuhao);
		chosehanghao=pNMListView->iItem;
	}
}


void Cversion02Dlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
    {   
        // 获取被选择列表项的行号 
		tuihanghao=pNMListView->iItem;
	}
}

/*ѧ��ѡ��ϵͳ
Developer:AmazingU
Date:2016.4.20
*/

// version02Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "version02.h"
#include "version02Dlg.h"
#include "afxdialogex.h"
#include "all.h"	

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int yixuankrs[12]={0};//����ı���Ҫ�ڿؼ�֮����д��ݣ�����ֱ�Ӷ�����ǰ��
int yixuanms=0;
int chosexh=0;
int chosehanghao=0;
int tuihanghao=0;

int k=0;//�������������洢��ѡ���ε�ѧ��
int yixuannum[45]={0};

UGstudent ugs[]={UGstudent(2014001,"��ǿ","����ʦ"),UGstudent(2014002,"����","����ʦ"),UGstudent(2014003,"���","����ʦ"),
		UGstudent(2014004,"��С��","����ʦ"),UGstudent(2014005,"��Сϼ","����ʦ"),UGstudent(2014006,"�����","����ʦ"),
		UGstudent(2014007,"������","����ʦ"),UGstudent(2014008,"л����","����ʦ"),UGstudent(2014009,"��ʤ��","����ʦ"),
		UGstudent(2014010,"��˼��","����ʦ"),UGstudent(2014011,"�ް���","����ʦ"),UGstudent(2014012,"��˼��","����ʦ"),
		UGstudent(2014013,"¬����","����ʦ"),UGstudent(2014014,"����","����ʦ"),UGstudent(2014015,"��ʤ��","����ʦ"),
		UGstudent(2014016,"��ɺ","����ʦ"),UGstudent(2014017,"κ��","����ʦ"),UGstudent(2014018,"ʷ��","����ʦ"),
		UGstudent(2014019,"лϲ��","����ʦ"),UGstudent(2014020,"³��","����ʦ"),UGstudent(2014021,"�̳�ϲ","����ʦ"),
		UGstudent(2014022,"������","����ʦ"),UGstudent(2014023,"������","����ʦ"),UGstudent(2014024,"���麣","����ʦ"),
		UGstudent(2014025,"¬־ʤ","����ʦ"),UGstudent(2014026,"лϲ��","����ʦ"),UGstudent(2014027,"�ް���","����ʦ"),
		UGstudent(2014028,"�̷���","����ʦ"),UGstudent(2014029,"�ⶫ��","����ʦ"),UGstudent(2014030,"���","����ʦ")};

	Gstudent gs[]={Gstudent(2014101,"��Сǿ","�Ž���"),Gstudent(2014102,"������","�����"),Gstudent(2014103,"����","������"),
		Gstudent(2014104,"������","�Ž���"),Gstudent(2014105,"�·�ϼ","�����"),Gstudent(2014106,"��ɸ�","�Ž���"),
		Gstudent(2014107,"�ӻ���","�Ž���"),Gstudent(2014108,"л����","�����"),Gstudent(2014109,"������","�Ž���"),
		Gstudent(2014110,"��˼˼","�Ž���"),Gstudent(2014111,"�ް���","�����"),Gstudent(2014112,"�ܱ���","�Ž���"),
		Gstudent(2014113,"¬����","�Ž���"),Gstudent(2014114,"����","�����"),Gstudent(2014115,"������","�Ž���")};

	course c[]={course(1,"ѧ�ƻ���","Ӣ�����",4),course(2,"ѧ�ƻ���","�ߵ���ѧ",2),course(3,"ѧ�ƻ���","��ѧ����",1),
		course(4,"ѧ�ƻ���","���ξ���ѧ",1),course(5,"רҵ����","�������",2),course(6,"רҵ����","���ݽṹ",2),
		course(7,"רҵ����","�����ԭ��",3),course(8,"רҵ����","�������",3),course(9,"רҵ����","OPP�������",2),
		course(10,"רҵ����","����ԭ��",2),course(11,"רҵ����","΢��ԭ��",3),course(12,"רҵ����","���������",3)};


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Cversion02Dlg �Ի���




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
	DDX_Control(pDX, IDC_LIST1, kexuan);//��Щ��������ֱ������ڸ����ؼ��ϵı���
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


// Cversion02Dlg ��Ϣ�������

BOOL Cversion02Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	CRect rect;  //�����б�ĳ�ʼ����һ���������У�һ����������
	kexuan.GetClientRect(&rect);
	kexuan.SetExtendedStyle(kexuan.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	kexuan.InsertColumn(0, _T("���"), LVCFMT_CENTER, rect.Width()/5, 0); 
	kexuan.InsertColumn(1, _T("�γ�����"), LVCFMT_CENTER, rect.Width()/5, 1);
	kexuan.InsertColumn(2, _T("�γ�����"), LVCFMT_CENTER, rect.Width()/5, 2);
	kexuan.InsertColumn(3, _T("ѧ��"), LVCFMT_CENTER, rect.Width()/5, 3);
	kexuan.InsertColumn(4, _T("��ѡ����"), LVCFMT_CENTER, rect.Width()/5, 4);

	CRect rect1;
	yixuan.GetClientRect(&rect1);
	yixuan.SetExtendedStyle(yixuan.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	yixuan.InsertColumn(0, _T("���"), LVCFMT_CENTER, rect1.Width()/4, 0); 
	yixuan.InsertColumn(1, _T("�γ�����"), LVCFMT_CENTER, rect1.Width()/4, 1);
	yixuan.InsertColumn(2, _T("�γ�����"), LVCFMT_CENTER, rect1.Width()/4, 2);
	yixuan.InsertColumn(3, _T("ѧ��"), LVCFMT_CENTER, rect1.Width()/4, 3);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cversion02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cversion02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cversion02Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	while ( kexuan.DeleteItem (0));//���Ƚ�kexuan��գ��������������б������ԭ�����б���档����ֻ��ѭ�������һ�оͿ��ԣ���Ϊ���һ������һ�л��Զ�����

	if(inputkmc.IsEmpty()){//�ж�����γ������Ƿ�Ϊ��
	int q=0,k=0;
	for(q=0;q<12;q++){
		if(inputklx==c[q].klx()){
			CString kmc,kxh,kxf,krs;//����SetItemText�в�����CString���ͣ����뽫��������תΪCString
			kmc=c[q].kmc();
			krs.Format(_T("%d"),yixuankrs[q]); //����Ӧ��д��krs.Format("%d",yixuankrs[q]);���ǻᱨ��ǰ�����_T�Ϳ�����
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
		MessageBox(_T("��������ȷ�Ŀγ�����"),_T("����"),MB_OK|MB_ICONERROR);
		for(int p=0;p<12;p++){ //ǰ���Ѿ����б���գ�������ʾ������Ϣ֮�󣬽����пγ���ʾ����
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
	else if(inputklx.IsEmpty()){//�ж�����γ������Ƿ�Ϊ��
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
		MessageBox(_T("��������ȷ�Ŀγ�����"),_T("����"),MB_OK|MB_ICONERROR);
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
		if(inputkmc==c[m].kmc()&&inputklx==c[m].klx()){//�������γ����ͺͿγ����ƶ���Ϊ�գ��жϿγ����ͺͿγ������Ƿ�ƥ��
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
		MessageBox(_T("��������ȷ�Ŀγ����ͺͿγ�����"),_T("����"),MB_OK|MB_ICONERROR);
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
	printmenshu=0;//����ʾ��ѡ����������ѡѧ�֡�ѧ������
	yixuanxf=0;
	xuefei=0;
	yixuanms=0;//printmenshu��������ʾ��MFC�ϣ������ﴦ�����yixuanms�����yxuanms����printmenshu����ʵ���Բ���yixuanms����yixuanmsȫ���滻ΪprintmenshuҲ����
	if(yixuan.GetItemCount()!=0){//���yixuan�б�Ϊ�գ���ѡ����������1��
		xuankezrs++;
	}
	while ( yixuan.DeleteItem (0));//yixuan�б����

	int i=0,j=0;
	for(i=0;i<30;i++){
		if(ugs[i].chaxunxuehao(xuehao)){
			CString edit1,edit2,edit3;
			edit1=ugs[i].printname();
			edit2=ugs[i].printban();
			edit3=ugs[i].printxue();
			SetDlgItemText(IDC_EDIT2,edit1);//����Ҳ����ֱ���ڿؼ�����ӱ�����ֱ�Ӹ�����������printxueli=edit3
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
		nRes=MessageBox(_T("��������ȷ��ѧ��"),_T("����"),MB_OK|MB_ICONERROR);
		return;  //���ﲻдreturn��ֱ����������ĳ���
	}else{
		yixuannum[k]=xuehao;//���ҵ���ѧ�Ŵ�������������жϺ��������ѧ���Ƿ�ǰ�������
		k++;
	}
	if(k>1){ //�����k�Ǵ�1��ʼ�ģ�����k=1ʱ��ֻ�����˵�һ��ѧ�ţ������ж��Ƿ��Ѿ�ѡ����
		for(int q=0;q<k-1;q++){ //����ע��q<k-1����k=2ʱ��ʾ��ʱ��ѧ���ǵڶ�������ģ����ж����һ�������ѧ���Ƿ���ͬ����һ�ε�ѧ�Ŵ���yixuannum[0]��
			if(xuehao==yixuannum[q]){
				MessageBox(_T("��ѧ���Ѿ�ѡ������"),_T("����"),MB_OK|MB_ICONERROR);
				break;//�������д��return����֪��Ϊʲôѡ������������ˢ����
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(yixuanms>0){
	yixuanms--;//����˿�֮��ѡ������-1
	CString str,str1,krs;
	int tuixf=0,tuixh=0;
	str=yixuan.GetItemText(tuihanghao,3);
	tuixf=_ttoi(str);//CStringתΪint
	yixuanxf=yixuanxf-tuixf;//��ѡѧ�ּ�����Ӧ��ѧ��

	str1=yixuan.GetItemText(tuihanghao,0);
	tuixh=_ttoi(str1)-1;//����Ҫע��γ�����Ǵ�1��ʼ�ģ������������ÿ�ſ���ѡ���������Ǵ�0��ʼ��

	yixuankrs[tuixh]--;//ÿ�ſ���ѡ����-1

	if(printxueli=="������"&&tuixh>=0&&tuixh<=3){//�����б�ؼ������Ѿ�����Ϊֻ�ܵ�ѡһ�У����Ե��һ������ֻ���һ��
				xuefei=xuefei-200*c[tuixh].kxf();
		    }
			else if(printxueli=="������"&&tuixh>=4&&tuixh<=7){
				xuefei=xuefei-150*c[tuixh].kxf();
			}
			else if(printxueli=="������"&&tuixh>=8&&tuixh<=11){
				xuefei=xuefei-100*c[tuixh].kxf();
			}
			else if(printxueli=="�о���"&&tuixh>=0&&tuixh<=3){
				xuefei=xuefei-200*c[tuixh].kxf();
			}
			else if(printxueli=="�о���"&&tuixh>=4&&tuixh<=7){
				xuefei=xuefei-180*c[tuixh].kxf();
			}
			else if(printxueli=="�о���"&&tuixh>=8&&tuixh<=11){
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
        MessageBox(_T("�Ѿ�����ȫ���γ�"),_T("����"),MB_OK|MB_ICONERROR);
	}
	UpdateData(false);
}


void Cversion02Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	if(printxueli!="������"&&printxueli!="�о���"){//��ֹû��ѧ��ֱ�ӵ�ѡ�ε��³������
		MessageBox(_T("��ѡ����ѧ��"),_T("����"),MB_OK|MB_ICONERROR);
		return;
	}

	if(yixuanms<5){  //yixuanms�Ǵ�0��ʼ��
    CString krs;
    yixuankrs[chosexh-1]++;//���ﲻ����chosehanghao��Ҫ��chosexh-1����Ϊ�����������ѯ��chosehanghao=chosexh-1�����������ѯ�ɹ�֮������chosehanghao��һ������chosexh-1
	krs.Format(_T("%d"),yixuankrs[chosexh-1]);
	kexuan.SetItemText(chosehanghao,4,krs);

	int n=0;
	for(n=0;n<12;n++){ //�����ѭ���Ｔʹѡ�����ͬһ�ſ�Ҳ����ӽ�yixuan�������������ﲻ���ͬһ�ſΣ���������
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
			if(printxueli=="������"&&n>=0&&n<=3){
				xuefei=xuefei+200*c[n].kxf();
		    }
			else if(printxueli=="������"&&n>=4&&n<=7){
				xuefei=xuefei+150*c[n].kxf();
			}
			else if(printxueli=="������"&&n>=8&&n<=11){
				xuefei=xuefei+100*c[n].kxf();
			}
			else if(printxueli=="�о���"&&n>=0&&n<=3){
				xuefei=xuefei+200*c[n].kxf();
			}
			else if(printxueli=="�о���"&&n>=4&&n<=7){
				xuefei=xuefei+180*c[n].kxf();
			}
			else if(printxueli=="�о���"&&n>=8&&n<=11){
				xuefei=xuefei+150*c[n].kxf();
			}
			yixuanms++;
			break;
			}
		}
	}
	else{
		MessageBox(_T("���ѡ��5�ſ�"),_T("����"),MB_OK|MB_ICONERROR);
	}
	for(int i=0;i<=yixuanms;i++){ //�������ж�ѡ����Ƿ���ͬһ�ſΣ�����ͬһ�ſ�����ɾ������Ӧ��ѧ�֡�ѡ��������ѧ��ҲҪ����
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

				if(printxueli=="������"&&strnum1>=0&&strnum1<=3){
				xuefei=xuefei-200*c[strnum1].kxf();
		    }
			else if(printxueli=="������"&&strnum1>=4&&strnum1<=7){
				xuefei=xuefei-150*c[strnum1].kxf();
			}
			else if(printxueli=="������"&&strnum1>=8&&strnum1<=11){
				xuefei=xuefei-100*c[strnum1].kxf();
			}
			else if(printxueli=="�о���"&&strnum1>=0&&strnum1<=3){
				xuefei=xuefei-200*c[strnum1].kxf();
			}
			else if(printxueli=="�о���"&&strnum1>=4&&strnum1<=7){
				xuefei=xuefei-180*c[strnum1].kxf();
			}
			else if(printxueli=="�о���"&&strnum1>=8&&strnum1<=11){
				xuefei=xuefei-150*c[strnum1].kxf();
			}

				yixuan.DeleteItem(j);
				MessageBox(_T("�Ѿ�ѡ�����ſ�"),_T("����"),MB_OK|MB_ICONERROR);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	if (-1 != pNMListView->iItem)        // ���iItem����-1����˵�����б��ѡ��   
    {   
        // ��ȡ��ѡ���б����һ��������ı����к�

		CString chosexuhao;
        chosexuhao = kexuan.GetItemText(pNMListView->iItem, 0);
		chosexh=_ttoi(chosexuhao);
		chosehanghao=pNMListView->iItem;
	}
}


void Cversion02Dlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	if (-1 != pNMListView->iItem)        // ���iItem����-1����˵�����б��ѡ��   
    {   
        // ��ȡ��ѡ���б�����к� 
		tuihanghao=pNMListView->iItem;
	}
}

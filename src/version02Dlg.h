
// version02Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// Cversion02Dlg �Ի���
class Cversion02Dlg : public CDialogEx
{
// ����
public:
	Cversion02Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VERSION02_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CListCtrl kexuan;
	afx_msg void OnBnClickedButton1();
	int xuehao;
	int printmenshu;
	int yixuanxf;
	int xuefei;
	CListCtrl yixuan;
	int xuankezrs;
	CString printxueli;
	CString inputkmc;
	CString inputklx;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
};


// version02Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// Cversion02Dlg 对话框
class Cversion02Dlg : public CDialogEx
{
// 构造
public:
	Cversion02Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_VERSION02_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

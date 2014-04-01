#pragma once
#include "afxdb.h"


// диалоговое окно User

class User : public CDialogEx
{
	DECLARE_DYNAMIC(User)

public:
	User(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~User();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
//	CDatabase db;
	CDatabase db1;
	CString zapros1;
	void FillList1(CString zapros);
	void FillList2(CString zapros);
	CListCtrl m_list1;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
};

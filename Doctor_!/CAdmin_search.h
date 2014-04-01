#pragma once


// диалоговое окно Admin_search

class Admin_search : public CDialogEx
{
	DECLARE_DYNAMIC(Admin_search)

public:
	Admin_search(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~Admin_search();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
//	CButton m_radio;
	CString m_admin_search;
	int m_radio;
	afx_msg void OnBnClickedCancel();
};

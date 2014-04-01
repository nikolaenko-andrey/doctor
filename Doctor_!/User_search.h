#pragma once


// диалоговое окно User_search

class User_search : public CDialogEx
{
	DECLARE_DYNAMIC(User_search)

public:
	User_search(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~User_search();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_search;
	afx_msg void OnBnClickedOk();
	int m_radio;
};

#pragma once


// диалоговое окно Zapis

class Zapis : public CDialogEx
{
	DECLARE_DYNAMIC(Zapis)

public:
	Zapis(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~Zapis();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_e6;
	CString m_e7;
	CString m_e8;
	CString m_e9;
	CString m_e10;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
//	virtual BOOL OnInitDialog();
	CString m_e11;
};

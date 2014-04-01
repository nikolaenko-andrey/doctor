#pragma once


// диалоговое окно About_program

class About_program : public CDialogEx
{
	DECLARE_DYNAMIC(About_program)

public:
	About_program(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~About_program();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};

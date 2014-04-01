// Add.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "Add.h"
#include "afxdialogex.h"


// диалоговое окно Add

IMPLEMENT_DYNAMIC(Add, CDialogEx)

Add::Add(CWnd* pParent /*=NULL*/)
	: CDialogEx(Add::IDD, pParent)
{

	m_e1 = _T("");
	m_e2 = _T("");
	m_e3 = _T("");
	m_e4 = _T("");
	m_e5 = _T("");
}

Add::~Add()
{
}

void Add::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_e1);
	DDX_Text(pDX, IDC_EDIT2, m_e2);
	DDX_Text(pDX, IDC_EDIT3, m_e3);
	DDX_Text(pDX, IDC_EDIT4, m_e4);
	DDX_Text(pDX, IDC_EDIT5, m_e5);
}


BEGIN_MESSAGE_MAP(Add, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений Add


void Add::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}

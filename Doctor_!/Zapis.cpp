// Zapis.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "Zapis.h"
#include <time.h>
#include "afxdialogex.h"


// диалоговое окно Zapis

IMPLEMENT_DYNAMIC(Zapis, CDialogEx)

Zapis::Zapis(CWnd* pParent /*=NULL*/)
	: CDialogEx(Zapis::IDD, pParent)
{

	m_e6 = _T("");
	m_e7 = _T("00.00.00/00:00");
	m_e8 = _T("");
	m_e9 = _T("");
	m_e10 = _T("");
	m_e11 = _T("");
}

Zapis::~Zapis()
{
}

void Zapis::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_e6);
	DDX_Text(pDX, IDC_EDIT2, m_e7);
	DDX_Text(pDX, IDC_EDIT3, m_e8);
	DDX_Text(pDX, IDC_EDIT4, m_e9);
	DDX_Text(pDX, IDC_EDIT5, m_e10);
	DDX_Text(pDX, IDC_EDIT6, m_e11);
}


BEGIN_MESSAGE_MAP(Zapis, CDialogEx)
	ON_BN_CLICKED(IDOK, &Zapis::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Zapis::OnBnClickedCancel)
END_MESSAGE_MAP()


// обработчики сообщений Zapis


void Zapis::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void Zapis::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}


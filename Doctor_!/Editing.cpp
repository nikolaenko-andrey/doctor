// Editing.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "Editing.h"
#include "afxdialogex.h"


// диалоговое окно Editing

IMPLEMENT_DYNAMIC(Editing, CDialogEx)

Editing::Editing(CWnd* pParent /*=NULL*/)
	: CDialogEx(Editing::IDD, pParent)
{

	m_e6 = _T("");
	m_e7 = _T("");
	m_e8 = _T("");
	//  m_e10 = _T("");
	//  m_9 = _T("");
	m_e9 = _T("");
	m_e10 = _T("");
}

Editing::~Editing()
{
}

void Editing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_e6);
	DDX_Text(pDX, IDC_EDIT1, m_e6);
	DDX_Text(pDX, IDC_EDIT2, m_e7);
	DDX_Text(pDX, IDC_EDIT3, m_e8);
	//  DDX_Text(pDX, IDC_EDIT4, m_e10);
	//  D//  DX_Text(p//  DX, I//  DC_E//  DIT4, m_9);
	DDX_Text(pDX, IDC_EDIT4, m_e9);
	DDX_Text(pDX, IDC_EDIT5, m_e10);
}


BEGIN_MESSAGE_MAP(Editing, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Editing::OnBnClickedCancel)
END_MESSAGE_MAP()


// обработчики сообщений Editing


void Editing::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}

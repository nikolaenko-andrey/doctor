// User_search.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "User_search.h"
#include "afxdialogex.h"


// диалоговое окно User_search

IMPLEMENT_DYNAMIC(User_search, CDialogEx)

User_search::User_search(CWnd* pParent /*=NULL*/)
	: CDialogEx(User_search::IDD, pParent)
{

	m_search = _T("");
	m_radio = 0;
}

User_search::~User_search()
{
}

void User_search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_search);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
}


BEGIN_MESSAGE_MAP(User_search, CDialogEx)
	ON_BN_CLICKED(IDOK, &User_search::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений User_search


void User_search::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}

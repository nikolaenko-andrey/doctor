// CAdmin_search.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "CAdmin_search.h"
#include "afxdialogex.h"


// диалоговое окно Admin_search

IMPLEMENT_DYNAMIC(Admin_search, CDialogEx)

Admin_search::Admin_search(CWnd* pParent /*=NULL*/)
	: CDialogEx(Admin_search::IDD, pParent)
{

	m_admin_search = _T("");
	m_radio = 0;
}

Admin_search::~Admin_search()
{
}

void Admin_search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, m_radio);
	DDX_Text(pDX, IDC_EDIT2, m_admin_search);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
}


BEGIN_MESSAGE_MAP(Admin_search, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений Admin_search

// User.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "User.h"
#include "afxdialogex.h"
#include "User_search.h"
#include "About_program.h"
#include "Zapis.h"
#include <afxdb.h>



// диалоговое окно User

IMPLEMENT_DYNAMIC(User, CDialogEx)

User::User(CWnd* pParent /*=NULL*/)
	: CDialogEx(User::IDD, pParent)
	, zapros1(_T(""))
{

}

User::~User()
{
}

void User::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(User, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &User::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &User::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &User::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL, &User::OnBnClickedCancel)
	ON_COMMAND(ID_32776, &User::On32776)
	ON_COMMAND(ID_32777, &User::On32777)
	ON_BN_CLICKED(IDC_BUTTON1, &User::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &User::OnBnClickedButton5)
END_MESSAGE_MAP()


// обработчики сообщений User


void User::OnBnClickedButton2()
{
	db1.Open(L"Basa09");
	zapros1=L"SELECT * FROM doctor";
	FillList1(zapros1);
}

void User::FillList1(CString zapros)
{
	int n,i;
	m_list1.DeleteAllItems();
	n=m_list1.GetHeaderCtrl()->GetItemCount();
	for(i=n-1;i>-1;i--)
	{
		m_list1.DeleteColumn(i);
	}
	//m_list.SetTextColor(125); установка цвета
	CRecordset rec(&db1);
	rec.Open(CRecordset::snapshot, zapros);
	int count=rec.GetODBCFieldCount();
	CRect rc;
	m_list1.GetWindowRect(&rc);
	m_list1.InsertColumn(0, _T("Номер"), 0, rc.Width() / 11);
	m_list1.InsertColumn(1, _T("ПІП доктора"), 0, rc.Width() / 5); 
	m_list1.InsertColumn(2, _T("Спеціалізація"), 0, rc.Width() / 6);
	m_list1.InsertColumn(3, _T("Початок роботи"), 0, rc.Width() / 6);
	m_list1.InsertColumn(4, _T("Категорія"), 0, rc.Width() / 5);
	m_list1.InsertColumn(5, _T("Направлення"), 0, rc.Width() / 5);
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	
	
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);
			if(j == 0)
				m_list1.InsertItem(i, buff);
			else
				m_list1.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}

void User::FillList2(CString zapros)
{
	int n,i;
	m_list1.DeleteAllItems();
	n=m_list1.GetHeaderCtrl()->GetItemCount();
	for(i=n-1;i>-1;i--)
	{
		m_list1.DeleteColumn(i);
	}
	//m_list.SetTextColor(125); установка цвета
	CRecordset rec(&db1);
	rec.Open(CRecordset::snapshot, zapros);
	int count=rec.GetODBCFieldCount();
	CRect rc;
	m_list1.GetWindowRect(&rc);
	m_list1.InsertColumn(0, _T("Номер"), 0, rc.Width() / 12);
	m_list1.InsertColumn(1, _T("ПІП хворого"), 0, rc.Width() / 4); 
	m_list1.InsertColumn(2, _T("Дата та час запису"), 0, rc.Width() / 5);
	m_list1.InsertColumn(3, _T("Симптомы"), 0, rc.Width() / 5);
	m_list1.InsertColumn(4, _T("ПІП лікаря"), 0, rc.Width() / 5);
	m_list1.InsertColumn(5, _T("Спеціалізація"), 0, rc.Width() / 5);
	m_list1.InsertColumn(6, _T("Направлення"), 0, rc.Width() / 6);
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	
	
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);
			if(j == 0)
				m_list1.InsertItem(i, buff);
			else
				m_list1.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}

void User::OnBnClickedOk()
{
	 User_search search;
	if(search.DoModal()==IDOK)
	{
		if(search.m_radio==0)
		{			
			CString zapros,str;
			CWnd::UpdateData(true);
			str=search.m_search;
			if(str=="")
				{
					zapros = "select * from doctor";
					FillList1( zapros);
				}
			else
				{
					zapros.Format(_T("Select * from doctor where Nomer=%s"),str);			
					FillList1(zapros);
				}
			CWnd::UpdateData(false);
		}
		
		if(search.m_radio==1)
		{					
			CString zapros,str;
			CWnd::UpdateData(true);
			str=search.m_search;
			if(str=="")
				{
					zapros = "select * from doctor";
					FillList1( zapros);
				}
			else
			{
				zapros=_T("SELECT * FROM doctor WHERE Name LIKE '%")+str+_T("%';");
				db1.ExecuteSQL(zapros);			
				FillList1(zapros);
			}
			CWnd::UpdateData(false);
		}

		if(search.m_radio==2)
		{					
			CString zapros,str;
			CWnd::UpdateData(true);
			str=search.m_search;
			if(str=="")
				{
					zapros = "select * from doctor";
					FillList1( zapros);
				}
			else
			{
				zapros=_T("SELECT * FROM doctor WHERE Specializacia LIKE '%")+str+_T("%';");
				db1.ExecuteSQL(zapros);			
				FillList1(zapros);
			}
			CWnd::UpdateData(false);
		}

		if(search.m_radio==3)
		{					
			CString zapros,str;
			CWnd::UpdateData(true);
			str=search.m_search;
			if(str=="")
				{
					zapros = "select * from doctor";
					FillList1( zapros);
				}
			else
			{
				zapros=_T("SELECT * FROM doctor WHERE Napravlenie LIKE '%")+str+_T("%';");
				db1.ExecuteSQL(zapros);			
				FillList1(zapros);
			}
			CWnd::UpdateData(false);
		}
	}	
}


void User::OnBnClickedButton3()
{
	if(db1.IsOpen())
	{
		CString s=L"Select * From doctor";
		FillList1(s);
	}
	else
		AfxMessageBox(L"base not opened");
}




BOOL User::OnInitDialog()
{
	CDialogEx::OnInitDialog();	
	CString connectionString(_T("Driver={Driver do Microsoft Access (*.mdb)};"));
	CFileDialog dlg(TRUE, _T(".mdb"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,  _T("Microsoft Access Files (*.mdb)|*.mdb"));
	if(dlg.DoModal() == IDOK)
	{
		POSITION pos = dlg.GetStartPosition();
		CString path  = dlg.GetNextPathName(pos);
		connectionString+=_T("dbq=")+path+_T(";driverid=25;fil=MS Access;maxbuffersize=2048;	maxscanrows=8;pagetimeout=5;safetransactions=0;threads=3;uid=admin;usercommitsync=Yes;");
	}	
	else
	{
		TCHAR szBuffer[MAX_PATH];
		GetModuleFileName(NULL, szBuffer, MAX_PATH);
		CString path(szBuffer);
		path = path.Left(path.ReverseFind(_T('\\')));
		connectionString+=_T("dbq=")+path+_T("\\Database.mdb;driverid=25;fil=MS Access;maxbuffersize=2048;	maxscanrows=8;pagetimeout=5;safetransactions=0;threads=3;uid=admin;usercommitsync=Yes;");
	}
	if(!db1.Open(NULL, 0, 0, connectionString))
	{
		MessageBox(_T("Невозможно установить соединение с базой данних"), _T("Ошибка"), MB_ICONERROR);
		exit(1);
	}
	else
	{
		CString zapros=_T("Select * from doctor");
		FillList1(zapros);
		zapros.Format(_T("Select *From doctor Order By Nomer"));
		FillList1(zapros);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}



void User::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}


void User::On32776()
{
	db1.Open(L"Basa09");
	zapros1=L"SELECT * FROM doctor";
	FillList1(zapros1);
}


void User::On32777()
{
	About_program dlg;
	dlg.DoModal();
}


void User::OnBnClickedButton1()
{
	Zapis dlg2;
	CString st;
	st= m_list1.GetItemText(m_list1.GetSelectionMark(),0);
	CString s,s1,s2, s0,s3, s4, s5;
	s.Format(L"SELECT * FROM doctor WHERE Nomer = %s",st);
	db1.ExecuteSQL(s);
	CRecordset rec(&db1);

	rec.Open(NULL,s);
	//передаемо значення полям із рядків
	rec.GetFieldValue(1,s3);
	rec.GetFieldValue(2,s4);
	rec.GetFieldValue(5,s5);
	
	//передаемо в едіти наші рядки
	dlg2.m_e8=s3;
	dlg2.m_e9=s4;
	dlg2.m_e10=s5;
	rec.Close();
	dlg2.DoModal();
	

	CWnd::UpdateData (true);
	if(dlg2.DoModal()==IDOK)
	{
		CString s;
		s.Format(L"INSERT INTO doctor_user (Name_user, data_zapis, Name, symptoms, Specializacia, Napravlenie) VALUES('%s','%s','%s','%s','%s','%s')",dlg2.m_e6, dlg2.m_e7, dlg2.m_e8, dlg2.m_e11, dlg2.m_e9, dlg2.m_e10 );
		db1.ExecuteSQL(s);
		AfxMessageBox(_T("Запис добавлена в список"));
		s=L"SELECT * FROM doctor_user";
		FillList2(s);
	}
	else if (dlg2.DoModal()==IDCANCEL)
	{
		AfxMessageBox(_T("Запис не добавлена в список"));

	}

	CWnd::UpdateData (false);
}





void User::OnBnClickedButton5()
{
	if(db1.IsOpen())
	{
		CString s=L"Select * From doctor_user";
		FillList2(s);
	}
	else
		AfxMessageBox(L"base not opened");
}

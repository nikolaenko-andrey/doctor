// Admin.cpp: файл реализации
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "Admin.h"
#include "afxdialogex.h"
#include "CAdmin_search.h"
#include "Add.h"
#include "Editing.h"
#include "About_program.h"
#include <afxdb.h>


// диалоговое окно Admin

IMPLEMENT_DYNAMIC(Admin, CDialogEx)

Admin::Admin(CWnd* pParent /*=NULL*/)
	: CDialogEx(Admin::IDD, pParent)
	, zapros(_T(""))
{

}

Admin::~Admin()
{
}

void Admin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Admin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &Admin::OnBnClickedButton4)
	ON_BN_CLICKED(IDOK, &Admin::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Admin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Admin::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Admin::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Admin::OnBnClickedButton5)
//	ON_COMMAND(IDR_MENU1, &Admin::OnIdrMenu1)
ON_COMMAND(ID_32772, &Admin::On32772)
//ON_COMMAND(ID_32773, &Admin::On32773)
ON_COMMAND(ID_32774, &Admin::On32774)
ON_COMMAND(ID_32775, &Admin::On32775)
ON_BN_CLICKED(IDC_BUTTON6, &Admin::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON8, &Admin::OnBnClickedButton8)
ON_BN_CLICKED(IDCANCEL, &Admin::OnBnClickedCancel)
END_MESSAGE_MAP()


// обработчики сообщений Admin


void Admin::OnBnClickedButton4()
{
	db.Open(L"Basa09");
	zapros=L"SELECT * FROM doctor";
	FillList(zapros);
}

void Admin::FillList(CString zapros)
{
	int n,i;
	m_list.DeleteAllItems();
	n=m_list.GetHeaderCtrl()->GetItemCount();
	for(i=n-1;i>-1;i--)
	{
		m_list.DeleteColumn(i);
	}
	//m_list.SetTextColor(125); установка цвета
	CRecordset rec(&db);
	rec.Open(CRecordset::snapshot, zapros);
	int count=rec.GetODBCFieldCount();
	CRect rc;
	m_list.GetWindowRect(&rc);
	m_list.InsertColumn(0, _T("Номер"), 0, rc.Width() / 11);
	m_list.InsertColumn(1, _T("ФИО доктора"), 0, rc.Width() / 5); 
	m_list.InsertColumn(2, _T("Специализация"), 0, rc.Width() / 6);
	m_list.InsertColumn(3, _T("Начало работи"), 0, rc.Width() / 6);
	m_list.InsertColumn(4, _T("Категория"), 0, rc.Width() / 5);
	m_list.InsertColumn(5, _T("Направление"), 0, rc.Width() / 5);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	
	//встановлення розмірів та назв колонок

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);
			if(j == 0)
				m_list.InsertItem(i, buff);
			else
				m_list.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}

void Admin::FillList2(CString zapros)
{
	int n,i;
	m_list.DeleteAllItems();
	n=m_list.GetHeaderCtrl()->GetItemCount();
	for(i=n-1;i>-1;i--)
	{
		m_list.DeleteColumn(i);
	}
	//m_list.SetTextColor(125); установка цвета
	CRecordset rec(&db);
	rec.Open(CRecordset::snapshot, zapros);
	int count=rec.GetODBCFieldCount();
	CRect rc;
	m_list.GetWindowRect(&rc);
	m_list.InsertColumn(0, _T("Номер"), 0, rc.Width() / 11);
	m_list.InsertColumn(1, _T("ФИО больного"), 0, rc.Width() / 7); 
	m_list.InsertColumn(2, _T("Дата та время записи"), 0, rc.Width() / 5);
	m_list.InsertColumn(3, _T("Симптомы"), 0, rc.Width() / 5);
	m_list.InsertColumn(4, _T("ФИО доктора"), 0, rc.Width() / 5);
	m_list.InsertColumn(5, _T("Специализация"), 0, rc.Width() / 5);
	m_list.InsertColumn(6, _T("Направление"), 0, rc.Width() / 6);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	
	
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);
			if(j == 0)
				m_list.InsertItem(i, buff);
			else
				m_list.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}

void Admin::OnBnClickedOk()
{
	Admin_search search;
	if(search.DoModal()==IDOK)
	{
		if(search.m_radio==0)
		{			
			CString zapros,str;
			CWnd::UpdateData(true);
			str=search.m_admin_search;
			if(str=="")
				{
					zapros = "select * from doctor_user";
					FillList2( zapros);
				}
			else
				{
					zapros.Format(_T("Select * from doctor_user where Nomer=%s"),str);			
					FillList2(zapros);
				}
			CWnd::UpdateData(false);
		}
		
		if(search.m_radio==1)
		{					
			CString zapros,str;
			CWnd::UpdateData(true);
			str=search.m_admin_search;
			if(str=="")
				{
					zapros = "select * from doctor_user";
					FillList2( zapros);
				}
			else
			{
				zapros=_T("SELECT * FROM doctor_user WHERE Name_user LIKE '%")+str+_T("%';");
				db.ExecuteSQL(zapros);			
				FillList2(zapros);
			}

			CWnd::UpdateData(false);
		}		
	}	
}



void Admin::OnBnClickedButton1()
{
	Add dlg;//створюємо об’єкт класу Add
	CWnd::UpdateData (true);
	if(dlg.DoModal()==IDOK)
	{
		CString s;
		s.Format(L"INSERT INTO doctor (Name, Specializacia, Nacalorobotu, Kategoria, Napravlenie) VALUES('%s','%s','%s','%s','%s')",dlg.m_e1, dlg.m_e2, dlg.m_e3, dlg.m_e4, dlg.m_e5 );
		db.ExecuteSQL(s);
		AfxMessageBox(_T("Лікар добавлений в список"));
		s=L"SELECT * FROM doctor";
		FillList(s);
}
	CWnd::UpdateData (false);
}


void Admin::OnBnClickedButton2()
{
	{
	int m_e1;
	CString str_Nomer, zapros;
	m_e1=m_list.GetSelectedCount();
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	int npos;
	while(pos)
	{
		npos=m_list.GetNextSelectedItem(pos);	
		str_Nomer=m_list.GetItemText(npos,0);
		zapros.Format(L"DELETE * FROM doctor WHERE Nomer = %s",str_Nomer);
		db.ExecuteSQL(zapros);
		AfxMessageBox(_T("Лікар видалений зі списку"));
		zapros = "Select * from doctor";
		FillList(zapros);
		zapros.Format(_T("Select *From doctor Order By Nomer"));
		FillList( zapros);
	}	
}

}


void Admin::OnBnClickedButton3()
{
	Editing dlg2;
	CString st;
	st= m_list.GetItemText(m_list.GetSelectionMark(),0);
	CString s, s1, s2, s3, s4, s5;
	s.Format(L"SELECT * FROM doctor WHERE Nomer = %s",st);
	db.ExecuteSQL(s);
	CRecordset rec(&db);

	rec.Open(NULL,s);
	rec.GetFieldValue(1,s1);//передаемо значення полям із рядків
	rec.GetFieldValue(2,s2);
	rec.GetFieldValue(3,s3);
	rec.GetFieldValue(4,s4);
	rec.GetFieldValue(5,s5);
	

	dlg2.m_e6=s1;//передаемо в едіти наші рядки
	dlg2.m_e7=s2;
	dlg2.m_e8=s3;
	dlg2.m_e9=s4;
	dlg2.m_e10=s5;
	rec.Close();
	dlg2.DoModal();

	s.Format(L"UPDATE doctor SET  doctor.Name=\'%s\', doctor.Specializacia=\'%s\', doctor.Nacalorobotu=\'%s\', doctor.Kategoria=\'%s\', doctor.Napravlenie=\'%s\' WHERE Nomer=%s",dlg2.m_e6,dlg2.m_e7,dlg2.m_e8,dlg2.m_e9,dlg2.m_e10,st);
	db.ExecuteSQL(s);
	s=L"SELECT * FROM doctor";
	FillList(s);
}


void Admin::OnBnClickedButton5()
{
	if(db.IsOpen())
	{
		CString s=L"Select * From doctor";
		FillList(s);
	}
	else
		AfxMessageBox(L"base not opened");
}


BOOL Admin::OnInitDialog()
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
	if(!db.Open(NULL, 0, 0, connectionString))
	{
		MessageBox(_T("Невозможно установить соединение с базой данних"), _T("Ошибка"), MB_ICONERROR);
		exit(1);
	}
	else
	{
		CString zapros=_T("Select * from doctor_user");
		FillList2(zapros);
		zapros.Format(_T("Select *From doctor_user Order By Nomer"));
		FillList2(zapros);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}



void Admin::On32772()
{
	db.Open(L"Basa09");
	zapros=L"SELECT * FROM doctor";
	FillList(zapros);
	
}


void Admin::On32774()
{
	if(db.IsOpen())
	{
		CString s=L"Select * From doctor_user";
		FillList2(s);
	}
	else
		AfxMessageBox(L"base not opened");
	
}


void Admin::On32775()
{
	About_program dlg;
	dlg.DoModal();
}


void Admin::OnBnClickedButton6()
{
	if(db.IsOpen())
	{
		CString s=L"Select * From doctor_user";
		FillList2(s);
	}
	else
		AfxMessageBox(L"base not opened");
}


void Admin::OnBnClickedButton8()
{
	
	int m_e1;
	CString str_Nomer, zapros;
	m_e1=m_list.GetSelectedCount();
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	int npos;
	while(pos)
	{
		npos=m_list.GetNextSelectedItem(pos);	
		str_Nomer=m_list.GetItemText(npos,0);
		zapros.Format(L"DELETE * FROM doctor_user WHERE Nomer = %s",str_Nomer);
		db.ExecuteSQL(zapros);
		AfxMessageBox(_T("Хворого зі списку видалено"));
		zapros = "Select * from doctor_user";
		FillList2(zapros);
		zapros.Format(_T("Select *From doctor_user Order By Nomer"));
		FillList2( zapros);
	}	
}

void Admin::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}

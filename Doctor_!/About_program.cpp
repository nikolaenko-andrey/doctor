// About_program.cpp: ���� ����������
//

#include "stdafx.h"
#include "Doctor_!.h"
#include "About_program.h"
#include "afxdialogex.h"


// ���������� ���� About_program

IMPLEMENT_DYNAMIC(About_program, CDialogEx)

About_program::About_program(CWnd* pParent /*=NULL*/)
	: CDialogEx(About_program::IDD, pParent)
{

}

About_program::~About_program()
{
}

void About_program::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(About_program, CDialogEx)
END_MESSAGE_MAP()


// ����������� ��������� About_program

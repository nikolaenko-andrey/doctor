#pragma once


// ���������� ���� About_program

class About_program : public CDialogEx
{
	DECLARE_DYNAMIC(About_program)

public:
	About_program(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~About_program();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
};

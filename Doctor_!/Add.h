#pragma once


// ���������� ���� Add

class Add : public CDialogEx
{
	DECLARE_DYNAMIC(Add)

public:
	Add(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~Add();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_e1;
	CString m_e2;
	CString m_e3;
	CString m_e4;
	CString m_e5;
	afx_msg void OnBnClickedOk();
};

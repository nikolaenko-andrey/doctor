#pragma once


// ���������� ���� Editing

class Editing : public CDialogEx
{
	DECLARE_DYNAMIC(Editing)

public:
	Editing(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~Editing();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_e6;
	CString m_e6;
	CString m_e7;
	CString m_e8;
//	CString m_e10;
//	CString m_9;
	CString m_e9;
	CString m_e10;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

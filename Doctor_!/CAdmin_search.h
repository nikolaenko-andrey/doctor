#pragma once


// ���������� ���� Admin_search

class Admin_search : public CDialogEx
{
	DECLARE_DYNAMIC(Admin_search)

public:
	Admin_search(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~Admin_search();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
//	CButton m_radio;
	CString m_admin_search;
	int m_radio;
	afx_msg void OnBnClickedCancel();
};


// Doctor_!Dlg.h : ���� ���������
//

#pragma once


// ���������� ���� CDoctor_Dlg
class CDoctor_Dlg : public CDialogEx
{
// ��������
public:
	CDoctor_Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_DOCTOR__DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CString m_login;
	CString m_password;
	afx_msg void OnBnClickedCancel();
};


// Doctor_!.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CDoctor_App:
// � ���������� ������� ������ ��. Doctor_!.cpp
//

class CDoctor_App : public CWinApp
{
public:
	CDoctor_App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CDoctor_App theApp;
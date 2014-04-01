
// Doctor_!.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CDoctor_App:
// О реализации данного класса см. Doctor_!.cpp
//

class CDoctor_App : public CWinApp
{
public:
	CDoctor_App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CDoctor_App theApp;

// L_system_draw.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CL_system_drawApp:
// О реализации данного класса см. L_system_draw.cpp
//

class CL_system_drawApp : public CWinApp
{
public:
	CL_system_drawApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CL_system_drawApp theApp;
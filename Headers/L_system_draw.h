
// L_system_draw.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CL_system_drawApp:
// � ���������� ������� ������ ��. L_system_draw.cpp
//

class CL_system_drawApp : public CWinApp
{
public:
	CL_system_drawApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CL_system_drawApp theApp;
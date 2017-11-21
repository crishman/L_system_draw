#ifndef L_SYSTEM_DRAW_DLG_H
#define L_SYSTEM_DRAW_DLG_H
// L_system_drawDlg.h : файл заголовка
//

#include "afxwin.h"
#include "MakeFractal.h"


// диалоговое окно CL_system_drawDlg
class CL_system_drawDlg : public CDialogEx
{
// Создание
public:
	CL_system_drawDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_L_system_draw_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	int m_RecNum;
	fractal_lines::_draw_line_mode m_DrawLineMode;
	afx_msg void OnBnClickedDownLevel();
	afx_msg void OnBnClickedUpLevel();
	afx_msg void OnBnClickedLookCurLine();
	afx_msg void OnCbnSelchangeLineCombo();
	CComboBox m_LineComboBox;
	BOOL UpdateData(BOOL bSaveAndValidate = TRUE);

protected:
	BOOL CheckBeforeDraw() const;
public:
	afx_msg void OnBnClickedLeftWingL();
	afx_msg void OnBnClickedRightWingL();
	afx_msg void OnBnClickedLeftWingR();
	afx_msg void OnBnClickedRightWingR();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#endif
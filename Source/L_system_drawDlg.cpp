
// L_system_drawDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "../Headers/L_system_draw.h"
#include "../Headers/L_system_drawDlg.h"
#include "afxdialogex.h"
#include "../Headers/BaseLine.h"
#include "../Headers/HilbertLine.h"
#include "../Headers/SierpinskiLine.h"
#include "../Headers/KochLine.h"
#include "../Headers/PifagorTreeLine.h"
#include "../Headers/DragonLine.h"
#include "../Headers/HosperLine.h"
#include "../Headers/LeviLine.h"
#include "../Headers/MinkovskiyLine.h"
#include <thread>
#include "../Headers/AddFunctions.h"
#include <memory>
#include <mutex>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

std::mutex draw_lock;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CL_system_drawDlg



CL_system_drawDlg::CL_system_drawDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_L_system_draw_DIALOG, pParent)
	, m_RecNum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_DrawLineMode = DRAW_LINE_DISABLED;
}

void CL_system_drawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_REC_NUM, m_RecNum);
	DDX_Check(pDX, IDC_LOOK_CUR_LINE, g_bCheckLookCurLine);
	DDX_Control(pDX, IDC_LINE_COMBO, m_LineComboBox);
}

BEGIN_MESSAGE_MAP(CL_system_drawDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_DOWN_LEVEL, &CL_system_drawDlg::OnBnClickedDownLevel)
	ON_BN_CLICKED(IDC_UP_LEVEL, &CL_system_drawDlg::OnBnClickedUpLevel)
	ON_BN_CLICKED(IDC_LOOK_CUR_LINE, &CL_system_drawDlg::OnBnClickedLookCurLine)
	ON_CBN_SELCHANGE(IDC_LINE_COMBO, &CL_system_drawDlg::OnCbnSelchangeLineCombo)
	ON_BN_CLICKED(IDC_LEFT_WING_L, &CL_system_drawDlg::OnBnClickedLeftWingL)
	ON_BN_CLICKED(IDC_RIGHT_WING_L, &CL_system_drawDlg::OnBnClickedRightWingL)
	ON_BN_CLICKED(IDC_LEFT_WING_R, &CL_system_drawDlg::OnBnClickedLeftWingR)
	ON_BN_CLICKED(IDC_RIGHT_WING_R, &CL_system_drawDlg::OnBnClickedRightWingR)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// обработчики сообщений CL_system_drawDlg

BOOL CL_system_drawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	auto add_line = m_LineComboBox.AddString(_T("Кривая Гильберта"));
	m_LineComboBox.SetItemData(add_line, HILBERT_LINE);
	add_line = m_LineComboBox.AddString(_T("Кривая Серпинского"));
	m_LineComboBox.SetItemData(add_line, SIERPINSKI_LINE);
	add_line = m_LineComboBox.AddString(_T("Кривая Коха"));
	m_LineComboBox.SetItemData(add_line, KOCH_LINE);
	add_line = m_LineComboBox.AddString(_T("Обнаженное дерево Пифагора"));
	m_LineComboBox.SetItemData(add_line, NAKED_PIFAGORE_TREE);
	add_line = m_LineComboBox.AddString(_T("Снежинка Коха"));
	m_LineComboBox.SetItemData(add_line, KOCH_STAR);
	add_line = m_LineComboBox.AddString(_T("Дракон Хартера — Хейтуэя"));
	m_LineComboBox.SetItemData(add_line, DRAGON_LINE);
	add_line = m_LineComboBox.AddString(_T("Классическое дерево Пифагора"));
	m_LineComboBox.SetItemData(add_line, PIFAGORE_TREE);		
	add_line = m_LineComboBox.AddString(_T("Кривая Госпера"));
	m_LineComboBox.SetItemData(add_line, HOSPER_LINE);	
	add_line = m_LineComboBox.AddString(_T("Кривая Серпинского 2"));
	m_LineComboBox.SetItemData(add_line, SIERPINSKI_LINE_2);
	add_line = m_LineComboBox.AddString(_T("Кривая Леви"));
	m_LineComboBox.SetItemData(add_line, LEVI_LINE);
	add_line = m_LineComboBox.AddString(_T("Кривая Минковского"));
	m_LineComboBox.SetItemData(add_line, MINKOVSKIY_LINE);	

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CL_system_drawDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CL_system_drawDlg::OnPaint()
{	
	std::shared_ptr<CPaintDC> dc(new CPaintDC(this));

	std::thread draw_thr([=]() {
		draw_lock.lock();

		std::shared_ptr<BaseLine> fractal_line;

		switch (m_DrawLineMode)
		{
		case HILBERT_LINE:
			fractal_line.reset(new HilbertLine());
			break;
		case SIERPINSKI_LINE:
			fractal_line.reset(new SierpinskiLine());
			break;
		case KOCH_LINE:
			fractal_line.reset(new KochLine());
			break;
		case NAKED_PIFAGORE_TREE:
			fractal_line.reset(new NakedPifagorTree());
			break;
		case PIFAGORE_TREE:
			fractal_line.reset(new PifagorTree());
			break;
		case KOCH_STAR:
			fractal_line.reset(new KochStarLine());
			break;
		case DRAGON_LINE:
			fractal_line.reset(new DragonLine());
			break;
		case HOSPER_LINE:
			fractal_line.reset(new HosperLine());
			break;
		case SIERPINSKI_LINE_2:
			fractal_line.reset(new SierpinskiLine2());
			break;
		case LEVI_LINE:
			fractal_line.reset(new LeviLine());
			break;
		case MINKOVSKIY_LINE:
			fractal_line.reset(new MinkovskiyLine());
			break;
		default:
			break;
		}

		if (fractal_line != NULL) {
			std::shared_ptr<CRect> rect(new CRect());
			GetClientRect(*rect);

			fractal_line->SetPaintDC(dc);
			fractal_line->SetRect(rect);
			try {
				fractal_line->Draw(m_RecNum);
			}
			catch (const TooDeepRecursionException &ex) {
				AfxMessageBox(_T("Глубина рекурсивной прорисовки для данной кривой при текущем приближении больше чем установленное ограничение(2^16)!"));
			}
		}

		draw_lock.unlock();
	});
		
	draw_thr.join();	

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc->GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc->DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CL_system_drawDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CL_system_drawDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CRect drawing_area;
	GetClientRect(&drawing_area);

	CBrush brush_back_ground(RGB(0, 0, 0));

	pDC->FillRect(&drawing_area, &brush_back_ground);

	//return CDialogEx::OnEraseBkgnd(pDC);
	return TRUE;
}

void CL_system_drawDlg::OnBnClickedDownLevel()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	m_RecNum--;
	if (CheckBeforeDraw() == FALSE)
		return;	
	UpdateData(FALSE);
	RedrawWindow();
}


void CL_system_drawDlg::OnBnClickedUpLevel()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	m_RecNum++;
	if (CheckBeforeDraw() == FALSE)
		return;	
	UpdateData(FALSE);
	RedrawWindow();
}


void CL_system_drawDlg::OnBnClickedLookCurLine()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData();
	RedrawWindow();
}

void CL_system_drawDlg::OnCbnSelchangeLineCombo()
{
	// TODO: добавьте свой код обработчика уведомлений
	
	UpdateData();

	switch (m_LineComboBox.GetItemData(m_LineComboBox.GetCurSel()))
	{
	case CL_system_drawDlg::DRAW_LINE_DISABLED:
		break;
	case CL_system_drawDlg::HILBERT_LINE:
		m_DrawLineMode = HILBERT_LINE;
		break;
	case CL_system_drawDlg::SIERPINSKI_LINE:
		m_DrawLineMode = SIERPINSKI_LINE;
		break;
	case CL_system_drawDlg::KOCH_LINE:
		m_DrawLineMode = KOCH_LINE;
		break;
	case CL_system_drawDlg::NAKED_PIFAGORE_TREE:
		m_DrawLineMode = NAKED_PIFAGORE_TREE;		
		break;
	case CL_system_drawDlg::PIFAGORE_TREE:
		m_DrawLineMode = PIFAGORE_TREE;
		break;
	case CL_system_drawDlg::KOCH_STAR:
		m_DrawLineMode = KOCH_STAR;
		break;
	case CL_system_drawDlg::DRAGON_LINE:
		m_DrawLineMode = DRAGON_LINE;
		break;		
	case CL_system_drawDlg::HOSPER_LINE:
		m_DrawLineMode = HOSPER_LINE;
		break;
	case CL_system_drawDlg::SIERPINSKI_LINE_2:
		m_DrawLineMode = SIERPINSKI_LINE_2;
		break;
	case CL_system_drawDlg::LEVI_LINE:
		m_DrawLineMode = LEVI_LINE;
		break;
	case CL_system_drawDlg::MINKOVSKIY_LINE:
		m_DrawLineMode = MINKOVSKIY_LINE;
		break;
	default:
		break;
	}

	if (CheckBeforeDraw() == FALSE)
		return;
	UpdateData(FALSE);

	RedrawWindow();
}

BOOL CL_system_drawDlg::CheckBeforeDraw() {
	auto res = TRUE;

	if (m_RecNum <= 0) {
		AfxMessageBox(_T("Выберите уровень приблежения!"));
		res = FALSE;
	}

	return res;
}

BOOL CL_system_drawDlg::UpdateData(BOOL bSaveAndValidate) {
	if (bSaveAndValidate) {

	}
	else {
		if (m_DrawLineMode == NAKED_PIFAGORE_TREE || m_DrawLineMode == PIFAGORE_TREE) {
			GetDlgItem(IDC_RIGHT_WING_L)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_LEFT_WING_L)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_WING_L_STATIC)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_RIGHT_WING_R)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_LEFT_WING_R)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_WING_R_STATIC)->ShowWindow(SW_SHOW);
			left_delta = 0;
			right_delta = 0;
		}
		else {
			GetDlgItem(IDC_RIGHT_WING_L)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_LEFT_WING_L)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_WING_L_STATIC)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_RIGHT_WING_R)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_LEFT_WING_R)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_WING_R_STATIC)->ShowWindow(SW_HIDE);
			left_delta = 0;
			right_delta = 0;
		}
	}

	return CDialog::UpdateData(bSaveAndValidate);
}

void CL_system_drawDlg::OnBnClickedLeftWingL()
{
	left_delta++;
	RedrawWindow();
}


void CL_system_drawDlg::OnBnClickedRightWingL()
{
	left_delta--;
	RedrawWindow();
}


void CL_system_drawDlg::OnBnClickedLeftWingR()
{
	right_delta++;
	RedrawWindow();
}


void CL_system_drawDlg::OnBnClickedRightWingR()
{
	right_delta--;
	RedrawWindow();
}


void CL_system_drawDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDblClk(nFlags, point);
}

// MyGerberDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MyGerber.h"
#include "MyGerberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyGerberDlg 대화 상자



CMyGerberDlg::CMyGerberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MYGERBER_DIALOG, pParent)
{
	m_bActivated = FALSE;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDc = NULL;

	m_pOpengl = NULL;
	m_p274X = NULL;

	m_pDlgProgress = NULL; m_bDlgProgress = FALSE;
	m_sDlgProgressCaption = _T("");

	m_bProc = FALSE; m_bProcFunc = FALSE;
	ThreadStart();
	//m_pCamMaster = NULL;
	//m_pOpenGLView = NULL;
	//m_pOpenGLDraw = NULL;
}


CMyGerberDlg::~CMyGerberDlg()
{
	//if (m_pCamMaster)
	//{
	//	delete m_pCamMaster;
	//	m_pCamMaster = NULL;
	//}
	//
	//if (m_pOpenGLDraw)
	//{
	//	delete m_pOpenGLDraw;
	//	m_pOpenGLDraw = NULL;
	//}
	//
	//if (m_pOpenGLView)
	//{
	//	delete m_pOpenGLView;
	//	m_pOpenGLView = NULL;
	//}
	ProgressClose();

	ThreadStop();
	while (m_bProc)
	{
		Sleep(30);
	}
	t.join();

	if (m_p274X)
	{
		delete m_p274X;
		m_p274X = NULL;
	}

	if (m_pOpengl)
	{
		delete m_pOpengl;
		m_pOpengl = NULL;
	}

	if (m_pDlgProgress != NULL)
	{
		delete m_pDlgProgress;
		m_pDlgProgress = NULL;
	}

	if (m_pDc)
	{
		::ReleaseDC(m_hWnd, m_pDc->GetSafeHdc());
		delete m_pDc;
		m_pDc = NULL;
	}
}

void CMyGerberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyGerberDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OPEN_GERB, &CMyGerberDlg::OnBnClickedBtnOpenGerb)
	ON_MESSAGE(WM_PROC_FUNC_0, &CMyGerberDlg::ProcFunc)
	ON_WM_TIMER()
END_MESSAGE_MAP()


void CMyGerberDlg::ThreadActivate(BOOL bRun)
{
	m_bProcFunc = bRun;
}

BOOL CMyGerberDlg::ThreadIsActivate()
{
	return m_bProcFunc;
}

BOOL CMyGerberDlg::ThreadIsAlive()
{
	return m_bProc;
}

BOOL CMyGerberDlg::ThreadIsStop()
{
	return m_bThreadAlive;
}

void CMyGerberDlg::ProcThrd(const LPVOID lpContext)
{
	CMyGerberDlg* pMyGerberDlg = reinterpret_cast<CMyGerberDlg*>(lpContext);

	pMyGerberDlg->m_bProc = TRUE;
	while (pMyGerberDlg->ThreadIsStop())
	{
		if (!pMyGerberDlg->Proc())
			break;
	}
	pMyGerberDlg->m_bProc = FALSE;
}

BOOL CMyGerberDlg::Proc()
{
	if (m_bProc)
	{
		if (m_bProcFunc)
		{
			::PostMessage(m_hWnd, WM_PROC_FUNC_0, 0, 0);
		}
	}
	Sleep(100);
	return TRUE;
}

LRESULT CMyGerberDlg::ProcFunc(WPARAM wPara, LPARAM lPara)
{
	if (!m_bProcFunc)	return 0L;

	return 0L;
}

void CMyGerberDlg::ThreadStart()
{
	m_bThreadAlive = TRUE;
	t = std::thread(ProcThrd, this);
}

void CMyGerberDlg::ThreadStop()
{
	m_bThreadAlive = FALSE;
	MSG message;
	const DWORD dwTimeOut = 1000 * 60 * 3; // 3 Minute
	DWORD dwStartTick = GetTickCount();
	Sleep(30);
}

// CMyGerberDlg 메시지 처리기

BOOL CMyGerberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	InitOpengl();
	Init274X();

	SetTimer(0, 100, NULL);
	//InitCamMaster();
	//InitGLViewer();

	m_bActivated = TRUE;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMyGerberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMyGerberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyGerberDlg::ProgressActivate(BOOL bRun)
{
	if (!m_bActivated) return;
	if (m_pDlgProgress != NULL)
	{
		m_pDlgProgress->ThreadActivate(bRun);

		if (bRun)
		{
			if (!m_pDlgProgress->IsWindowVisible())
				m_pDlgProgress->ShowWindow(SW_SHOW);
		}
		else
		{
			if (m_pDlgProgress->IsWindowVisible())
				m_pDlgProgress->ShowWindow(SW_HIDE);
		}
	}
}

void CMyGerberDlg::ProgressSet(int nPos, int nMin, int nMax)
{
	if (!m_bActivated) return;
	if (!m_pDlgProgress)
	{
		m_pDlgProgress = new CDlgProgress(this);
		if (m_pDlgProgress->GetSafeHwnd() == 0)
		{
			//if (!m_bDlgProgress)
			m_bDlgProgress = m_pDlgProgress->Create(m_sDlgProgressCaption);

			//if (nMin < 0 || nMax < 0)
			//	m_pDlgProgress->SetRange(0, 100);
			//else
			//{
			//	m_pDlgProgress->SetRange(nMin, nMax);
			//}
			//m_pDlgProgress->SetStep(1);
			//m_pDlgProgress->ThreadActivate(TRUE);

			//m_pDlgProgress->SetPos(nPos);
			//if (!m_pDlgProgress->IsWindowVisible())
			//	m_pDlgProgress->ShowWindow(SW_SHOW);
		}
	}
	else
	{
		//if (nMin < 0 || nMax < 0)
		//	m_pDlgProgress->SetRange(0, 100);
		//else
		//	m_pDlgProgress->SetRange(nMin, nMax);

		//m_pDlgProgress->SetStep(1);
		//m_pDlgProgress->ThreadActivate(TRUE);
		//m_pDlgProgress->SetPos(nPos);
		//if (!m_pDlgProgress->IsWindowVisible())
		//	m_pDlgProgress->ShowWindow(SW_SHOW);
	}

	if (nMin < 0 || nMax < 0)
		m_pDlgProgress->SetRange(0, 100);
	else
	{
		m_pDlgProgress->SetRange(nMin, nMax);
	}
	m_pDlgProgress->SetStep(1);
	m_pDlgProgress->ThreadActivate(TRUE);

	m_pDlgProgress->SetPos(nPos);
	if (!m_pDlgProgress->IsWindowVisible())
		m_pDlgProgress->ShowWindow(SW_SHOW);

	//m_pDlgProgress->ShowWindow(SW_SHOW);
}

void CMyGerberDlg::ProgressClose()
{
	if (!m_bActivated) return;
	if (m_pDlgProgress != NULL)
	{
		m_pDlgProgress = NULL;
		//m_pDlgProgress->ThreadActivate(FALSE);
		//m_pDlgProgress->ThreadStop();
		//while (m_pDlgProgress->ThreadIsAlive())
		//{
		//	Sleep(30);
		//}
		//m_pDlgProgress->Free();
		//m_pDlgProgress->DestroyWindow();
		////delete m_pDlgProgress;
		//m_pDlgProgress = NULL;
	}
}

int CMyGerberDlg::ProgressGet()
{
	if (!m_bActivated) return 0;
	int nPos = 0;
	if (!m_pDlgProgress) return nPos;
	nPos = m_pDlgProgress->GetPos();
	return nPos;
}

void CMyGerberDlg::ProgressSetDlgCaption(CString sCaption)
{
	if (!m_bActivated) return;
	m_sDlgProgressCaption = sCaption;
	if (m_pDlgProgress)
		m_pDlgProgress->SetWindowText(sCaption);
}


BOOL CMyGerberDlg::InitOpengl()
{
	if (m_pOpengl)
	{
		delete m_pOpengl;
		m_pOpengl = NULL;
	}
	m_pOpengl = new CSimpleOpengl(this);

	HWND hWnd = GetDlgItem(IDC_STATIC_OPENGL)->GetSafeHwnd();
	m_pOpengl->SubclassDlgItem(IDC_STATIC_OPENGL, this);
	m_pOpengl->SetHwnd(hWnd, this);
	m_pOpengl->SetFont(_T("굴림체"), 12, TRUE);

	return TRUE;
}

BOOL CMyGerberDlg::Init274X()
{
	if (m_p274X)
	{
		delete m_p274X;
		m_p274X = NULL;
	}
	m_p274X = new CSimple274X(this);

	HWND hWnd = GetDlgItem(IDC_STATIC_OPENGL)->GetSafeHwnd();
	m_p274X->SetHwnd(hWnd);

	return TRUE;
}

void CMyGerberDlg::OnBnClickedBtnOpenGerb()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString sPath;
	if (!FileBrowse(sPath))
		return;
	GetDlgItem(IDC_STATIC_PATH_GERB)->SetWindowText(sPath);
	LoadGerbFile(sPath);
	DispGerbFile();
	//if (m_pCamMaster)
	//	m_pCamMaster->LoadGerbFile(sPath);
}

BOOL CMyGerberDlg::FileBrowse(CString& sPath)
{
	sPath = _T("");

	/* Load from file */
	CString FilePath;
	CFileFind finder;
	CString SrchPath, strTitleMsg, strErrMsg;

	CWaitCursor mCursor;

	CString DirPath[10];
	CString strWorkDir;
	BOOL bResult;

	CString strMcNum;
	int nAoiMachineNum = 0;

	// File Open Filter 
	static TCHAR BASED_CODE szFilter[] = _T("Gerber Files (*.gbr;*.m00)|*.gbr;*.m00|All Files (*.*)|*.*||");

	// CFileDialog 
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);

	// Win2k Style FileDialog Box
	dlg.m_ofn.lStructSize = sizeof(OPENFILENAME) + 12; // +12를 Win2k Style로 다이얼로그 박스가 Open됨.

													   // Open Directory
	TCHAR strPrevDir[MAX_PATH];
	DWORD dwLength = GetCurrentDirectory(MAX_PATH, strPrevDir);
	strWorkDir = strPrevDir;
	dlg.m_ofn.lpstrInitialDir = strWorkDir;

	bResult = 0;

	// Dialog Open
	if (dlg.DoModal() == IDOK)
	{
		sPath = FilePath = dlg.GetPathName();
		return TRUE;
	}

	return FALSE;
}

void CMyGerberDlg::LoadGerbFile(CString sPath)
{
	if (m_p274X)
		m_p274X->LoadGerbFile(sPath);
}

void CMyGerberDlg::DispGerbFile()
{
	if (m_p274X)
		m_p274X->DrawGerbFile();
	if (m_pOpengl)
		m_pOpengl->SetDraw();
}

LPLAYER_INFORM_RS274X CMyGerberDlg::GetLayerInfo()
{
	if (m_p274X)
		return m_p274X->GetLayerInfo();
	return NULL;
}

void CMyGerberDlg::Draw274X()
{
	if (m_p274X)
		return m_p274X->Draw274X();
}

void CMyGerberDlg::DrawBegin(int nMode, int nSize, COLORREF color)
{
	if (m_pOpengl)
		m_pOpengl->DrawBegin(nMode, nSize, color);
}

void CMyGerberDlg::DrawEnd()
{
	if (m_pOpengl)
		m_pOpengl->DrawEnd();
}

void CMyGerberDlg::DrawDisp()
{
	if (m_pOpengl)
		m_pOpengl->DrawDisp();
}

void CMyGerberDlg::SetForeColor(COLORREF crColor)
{
	if (m_pOpengl)
		m_pOpengl->SetForeColor(crColor);
}

void CMyGerberDlg::MyLineList(float X1, float Y1, float X2, float Y2, int nListNum)
{
	if (m_pOpengl)
	{
		int nSizeLine = 1;
		DrawBegin(Opengl::modLine, nSizeLine, RGB_BLUE);
		m_pOpengl->MyLineList(X1, Y1, X2, Y2, nListNum);
		DrawEnd();
	}
}

void CMyGerberDlg::MyCallApertureList(float fx, float fy, int nListNum)
{
	if (m_pOpengl)
		m_pOpengl->MyCallApertureList(fx, fy, nListNum);
}


void CMyGerberDlg::StencilBegin()
{
	if (m_pOpengl)
		m_pOpengl->StencilBegin();
}

void CMyGerberDlg::StencilSet(BOOL bStencil)
{
	if (m_pOpengl)
		m_pOpengl->StencilSet(bStencil);
}

void CMyGerberDlg::StencilClear(BOOL bStencil)
{
	if (m_pOpengl)
		m_pOpengl->StencilClear(bStencil);
}

void CMyGerberDlg::StencilBitRev(const vector <FPOINTC> &vecVertics, int nNumOfVertex)
{
	if (m_pOpengl)
		m_pOpengl->StencilBitRev(vecVertics, nNumOfVertex);
}

void CMyGerberDlg::StencilReverse(const vector <FPOINTC> &vecVertics, int nNumOfVertex)
{
	if (m_pOpengl)
		m_pOpengl->StencilReverse(vecVertics, nNumOfVertex);
}

void CMyGerberDlg::StencilEnd()
{
	if (m_pOpengl)
		m_pOpengl->StencilEnd();
}

void CMyGerberDlg::DrawConvexPolygon(const vector <FPOINTC> &fPoint)
{
	if (m_pOpengl)
		m_pOpengl->DrawConvexPolygon(fPoint);
}

void CMyGerberDlg::DrawConvexPolygon(const FPOINTC *fPoint, int nNumberOfVertex)
{
	if (m_pOpengl)
		m_pOpengl->DrawConvexPolygon(fPoint, nNumberOfVertex);
}

void CMyGerberDlg::DrawPolygonLine(const vector <FPOINTC> &vecPt, int nLineWidth)
{
	if (m_pOpengl)
		m_pOpengl->DrawPolygonLine(vecPt, nLineWidth);
}

void CMyGerberDlg::DrawLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight)
{
	if (m_pOpengl)
		m_pOpengl->DrawLineRect(fSx, fSy, fEx, fEy, fLineWidth, fLineHeight);
}

void CMyGerberDlg::DrawConcavePolygon(const vector <FPOINTC> &fPoint)
{
	if (m_pOpengl)
		m_pOpengl->DrawConcavePolygon(fPoint);
}

void CMyGerberDlg::DrawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, int fill)
{
	int nSizeLine = 1;
	//GLfloat fLeft = 10000.0, fTop = 10000.0, fRight = -10000.0, fBottom = -10000.0;
	//if (fLeft > x1) fLeft = x1; if (fLeft > x2) fLeft = x2;if (fLeft > x3) fLeft = x3; if (fLeft > x4) fLeft = x4;
	//if (fTop > y1) fTop = y1; if (fTop > y2) fTop = y2; if (fTop > y3) fTop = y3; if (fTop > y4) fTop = y4;
	//if (fRight < x1) fRight = x1; if (fRight < x2) fRight = x2; if (fRight < x3) fRight = x3; if (fRight < x4) fLeft = x4;
	//if (fBottom < y1) fBottom = y1; if (fBottom < y2) fBottom = y2; if (fBottom < y3) fBottom = y3; if (fBottom < y4) fBottom = y4;
	//x1 = fLeft; x2 = fLeft; x3 = fRight; x4 = fRight;
	//y1 = fTop; y2 = fBottom; y3 = fBottom; y4 = fTop;
	if (m_pOpengl)
	{
		if (fill)
			DrawBegin(Opengl::modRectF, nSizeLine, RGB_SKYBLUE);
		else
			DrawBegin(Opengl::modCircleE, nSizeLine, RGB_GREEN);
		m_pOpengl->DrawQuad(x1, y1, x2, y2, x3, y3, x4, y4, fill);
		DrawEnd();
		//DrawDisp();
	}
}
/*
if (fill)
glBegin(GL_QUADS); // filled quad
else
glBegin(GL_LINE_LOOP); // hollow quad

*/
void CMyGerberDlg::DrawRect(const CfPoint3D &fptStart, const CfPoint3D &fptEnd, int width, int fill)
{
	if (m_pOpengl)
	{
		int nSizeLine = 1;
		if (fill)
			DrawBegin(Opengl::modRectF, nSizeLine, RGB_YELLOW);
		else
		{
			if (width != 0)
			{
				DrawBegin(Opengl::modCircleE, width, RGB_BLUE);
			}
			else
			{
				DrawBegin(Opengl::modCircleE, nSizeLine, RGB_BLUE);
			}
		}
		m_pOpengl->DrawRect(fptStart, fptEnd, width, fill);
		DrawEnd();
	}
}
/*
if (fill)
{
	glBegin(GL_QUADS); // filled quad
}
else
{
	if (width != 0)
	{
		glGetFloatv(GL_LINE_WIDTH, &lineWidth);
		glLineWidth(width);
		glBegin(GL_LINE_LOOP); // hollow quad
	}
	else
	{
		glBegin(GL_LINE_LOOP); // hollow quad
	}
}

*/
void CMyGerberDlg::DrawDonut(float fCx, float fCy, float fDmo, float fDmi)
{
	int nSizeLine = 1;
	if (m_pOpengl)
	{
		m_pOpengl->DrawDonut(fCx, fCy, fDmo, fDmi);
	}
}

void CMyGerberDlg::SetDrawResolution(float fResolution)
{
	if (m_pOpengl)
		m_pOpengl->SetDrawResolution(fResolution);
}

void CMyGerberDlg::DrawCircle(GLfloat cx, GLfloat cy, GLfloat r, int fill)
{
	if (m_pOpengl)
	{
		int nSizeLine = 1;
		if (fill)
			DrawBegin(Opengl::modCircleF, nSizeLine, RGB_YELLOW);
		else
			DrawBegin(Opengl::modCircleE, nSizeLine, RGB_YELLOW);
		m_pOpengl->DrawCircle(cx, cy, r, fill);
		DrawEnd();
	}
}


FRECTC CMyGerberDlg::GetLayerMaxExtent()
{
	FRECTC fRect;
	fRect.X1 = 0.0; fRect.Y1 = 0.0; fRect.X2 = 0.0; fRect.Y2 = 0.0;
	if (m_p274X)
		fRect = m_p274X->GetLayerMaxExtent();
	return fRect;
}

COLORREF CMyGerberDlg::GetObjectColorCurrent()
{
	COLORREF color = RGB_WHITE;
	if (m_p274X)
		color = m_p274X->GetObjectColorCurrent();
	return color;
}


double CMyGerberDlg::GetScaleOfScreen()
{
	double dScale;
	dScale = 1.0;
	if (m_p274X)
		dScale = m_p274X->GetScaleOfScreen();
	return dScale;
}

//BOOL CMyGerberDlg::InitCamMaster()
//{
//	if (m_pCamMaster)
//	{
//		delete m_pCamMaster;
//		m_pCamMaster = NULL;
//	}
//	m_pCamMaster = new CCamMaster(this);
//
//	return TRUE;
//}

//BOOL CMyGerberDlg::InitGLViewer()
//{
//	CRect rect;
//	CString strCamDataFilePath;
//	CString strSize;
//	FRECTC FrameExtent;
//	FRECTC InspectionRegion;
//
//	if (m_pOpenGLDraw)
//		delete m_pOpenGLDraw;
//
//	if (m_pOpenGLView)
//		delete m_pOpenGLView;
//
//	m_pOpenGLView = new COpenGLView();
//	m_pOpenGLDraw = new COpenGLDraw();
//
//	GetDlgItem(IDC_STATIC_OPENGL)->GetWindowRect(rect);
//	ScreenToClient(rect);
//	int nWorldW = rect.right - rect.left;
//	int nWorldH = rect.bottom - rect.top;
//
//	m_pOpenGLView->Create(NULL, NULL, WS_OVERLAPPED | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE, rect, this, 0);
//	m_pOpenGLView->SetHandleID(IDC_STATIC_OPENGL);
//	m_pOpenGLView->SetCoordinate(CfSize(nWorldW, nWorldH), CfPoint(0, 0));
//	//m_pOpenGLView->SetCoordinate(CfSize(1000, 1000), CfPoint(0, 0));
//	m_pOpenGLView->SetBackGroundColor(BLACK);
//	m_pOpenGLView->SetMouseCursor();
//
//	return TRUE;
//}
//
//LRESULT  CMyGerberDlg::OnGlRedrawCam(WPARAM wPara, LPARAM lPara)
//{
//	m_cs.Lock();
//	m_pOpenGLView->Refresh();
//	m_cs.Unlock();
//
//	return 0L;
//}


void CMyGerberDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0)
	{
		KillTimer(nIDEvent);
	}

	CDialog::OnTimer(nIDEvent);
}

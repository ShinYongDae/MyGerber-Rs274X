// SimpleOpengl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyGerber.h"
#include "MyGerberDlg.h"
#include "SimpleOpengl.h"


// CSimpleOpengl

IMPLEMENT_DYNAMIC(CSimpleOpengl, CWnd)

CSimpleOpengl::CSimpleOpengl(CWnd* pParent/* = NULL*/)
{
	m_pParent = pParent;
	m_hCtrl = NULL;
	m_hDc = NULL;
	m_pDc = NULL;

	cameraposmap[0] = 0.0f;
	cameraposmap[1] = 0.0f;
	cameraposmap[2] = 7000.0f;
	Angle[0] = 0.0f;
	Angle[1] = 0.0f;
	Angle[2] = 0.0f;
	m_bInit = FALSE;
	m_bFont = FALSE; 
	m_crText = RGB_WHITE;

	m_pMenu = NULL;

	m_bDraw = FALSE;
	m_bDrawText = FALSE;
	m_bDrawClear = FALSE;
	m_bDrawClearColor = FALSE;

	m_dPixelResolution = 10.0;
	m_fDrawResolution = 1.0;

	ThreadStart();
}

CSimpleOpengl::CSimpleOpengl(HWND& hCtrl, CWnd* pParent/*=NULL*/)
{
	m_pParent = pParent;
	if (pParent)
		m_hParent = pParent->GetSafeHwnd();
	m_hCtrl = hCtrl;
	m_pDc = NULL;
	m_bInit = FALSE;
	m_bFont = FALSE;
	m_crText = RGB_WHITE;

	m_pMenu = NULL;

	m_bDraw = FALSE;
	m_bDrawText = FALSE;
	m_bDrawClear = FALSE;
	m_bDrawClearColor = FALSE;

	m_pDc = new CClientDC(FromHandle(hCtrl));
	CreateWndForm(WS_CHILD | WS_OVERLAPPED);
	ThreadStart();
}

CSimpleOpengl::~CSimpleOpengl()
{
	ThreadStop();
	Sleep(30);
	t1.join();

	RemoveAllLine();
	RemoveAllText();

	if (m_bFont)
	{
		if (m_Font.DeleteObject())
			m_bFont = FALSE;
	}

	if (m_hRC)
	{
		wglDeleteContext(m_hRC);
		m_hRC = NULL;
	}

	if (m_pDc)
	{
		::ReleaseDC(m_hWnd, m_pDc->GetSafeHdc());
		delete m_pDc;
		m_pDc = NULL;
	}

	if (m_pMenu)
	{
		delete m_pMenu;
		m_pMenu = NULL;
	}
}


BEGIN_MESSAGE_MAP(CSimpleOpengl, CWnd)
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CSimpleOpengl 메시지 처리기입니다.

void CSimpleOpengl::SetDrawResolution(float fResolution)
{
	m_fDrawResolution = fResolution;
}

void CSimpleOpengl::RemoveAllLine()
{
	int nTotal = m_arLine.GetCount();
	if (nTotal > 0)
	{
		m_arLine.RemoveAll();
	}
}

void CSimpleOpengl::RemoveAllText()
{
	int nTotal = m_arText.GetCount();
	if (nTotal > 0)
	{
		m_arText.RemoveAll();
	}
}

BOOL CSimpleOpengl::CreateWndForm(DWORD dwStyle)
{
	//if (!Create(NULL, _T("CSimpleOpengl"), dwStyle, CRect(0, 0, 0, 0), m_pParent, (UINT)this))
	//{
	//	AfxMessageBox(_T("CSimpleOpengl::Create() Failed!!!"));
	//	return FALSE;
	//}
	//if (!Create(_T("CSimpleOpengl"), WS_CHILD | WS_OVERLAPPED, CRect(0, 0, 0, 0), m_pParent, (UINT)this))
	//{
	//	AfxMessageBox(_T("CSimpleOpengl::Create() Failed!!!"));
	//	return FALSE;
	//}

	return TRUE;
}

/*
// 그리기 표면의 픽셀 형식을 설명
typedef struct tagPIXELFORMATDESCRIPTOR {
	WORD  nSize;
	WORD  nVersion;
	DWORD dwFlags;
	BYTE  iPixelType;
	BYTE  cColorBits;
	BYTE  cRedBits;
	BYTE  cRedShift;
	BYTE  cGreenBits;
	BYTE  cGreenShift;
	BYTE  cBlueBits;
	BYTE  cBlueShift;
	BYTE  cAlphaBits;
	BYTE  cAlphaShift;
	BYTE  cAccumBits;
	BYTE  cAccumRedBits;
	BYTE  cAccumGreenBits;
	BYTE  cAccumBlueBits;
	BYTE  cAccumAlphaBits;
	BYTE  cDepthBits;
	BYTE  cStencilBits;
	BYTE  cAuxBuffers;
	BYTE  iLayerType;
	BYTE  bReserved;
	DWORD dwLayerMask;
	DWORD dwVisibleMask;
	DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR, *LPPIXELFORMATDESCRIPTOR;

[dwFlags]
=================================================================================================================================================
값										의미
=================================================================================================================================================
PFD_DRAW_TO_WINDOW						버퍼는 창 또는 디바이스 화면에 그릴 수 있습니다.
0x00000004

PFD_DRAW_TO_BITMAP						버퍼는 메모리 비트맵에 그릴 수 있습니다.
0x00000008

PFD_SUPPORT_GDI							버퍼는 GDI 그리기를 지원합니다. 이 플래그 및 PFD_DOUBLEBUFFER 현재 제네릭 구현에서 상호 배타적입니다.
0x00000010

PFD_SUPPORT_OPENGL						버퍼는 OpenGL 그리기를 지원합니다.
0x00000020

PFD_GENERIC_ACCELERATED					픽셀 형식은 제네릭 구현을 가속화하는 디바이스 드라이버에서 지원됩니다. 이 플래그가 명확하고 PFD_GENERIC_FORMAT 플래그가 설정된 경우 픽셀 형식은 제네릭 구현에서만 지원됩니다.
0x00001000

PFD_GENERIC_FORMAT						픽셀 형식은 제네릭 구현이라고도 하는 GDI 소프트웨어 구현에서 지원됩니다. 이 비트가 명확한 경우 픽셀 형식은 디바이스 드라이버 또는 하드웨어에서 지원됩니다.
0x00000040

PFD_NEED_PALETTE						버퍼는 팔레트 관리 디바이스에서 RGBA 픽셀을 사용합니다. 이 픽셀 형식에 대한 최상의 결과를 얻으려면 논리적 팔레트가 필요합니다. 색상표의 색은 cRedBits, cRedShift, cGreenBits, cGreenShift, cBluebits 및 cBlueShift 멤버의 값에 따라 지정되어야 합니다. wglMakeCurrent를 호출하기 전에 디바이스 컨텍스트에서 팔레트를 만들고 실현해야 합니다.
0x00000080

PFD_NEED_SYSTEM_PALETTE					256색 모드에서만 하나의 하드웨어 팔레트를 지원하는 하드웨어의 픽셀 형식 설명자에 정의됩니다. 이러한 시스템에서 하드웨어 가속을 사용하려면 RGBA 모드에서 하드웨어 팔레트가 고정 순서(예: 3-3-2)이거나 색 인덱스 모드일 때 논리 팔레트와 일치해야 합니다. 이 플래그가 설정되면 프로그램에서 SetSystemPaletteUse 를 호출하여 논리 팔레트와 시스템 팔레트의 일대일 매핑을 강제해야 합니다. OpenGL 하드웨어가 여러 하드웨어 팔레트를 지원하고 디바이스 드라이버가 OpenGL에 예비 하드웨어 팔레트를 할당할 수 있는 경우 이 플래그는 일반적으로 명확합니다.
0x00000100								이 플래그는 제네릭 픽셀 형식으로 설정되지 않습니다.

PFD_DOUBLEBUFFER						버퍼가 이중 버퍼링됩니다. 이 플래그 및 PFD_SUPPORT_GDI 현재 제네릭 구현에서 상호 배타적입니다.
0x00000001

PFD_STEREO								버퍼는 입체입니다. 이 플래그는 현재 제네릭 구현에서 지원되지 않습니다.
0x00000002

PFD_SWAP_LAYER_BUFFERS					디바이스가 이중 버퍼링 오버레이 또는 언더레이 평면을 포함하는 픽셀 형식으로 개별 레이어 평면을 교환할 수 있는지 여부를 나타냅니다. 그렇지 않으면 모든 레이어 평면이 그룹으로 함께 교환됩니다. 이 플래그가 설정되면 wglSwapLayerBuffers 가 지원됩니다.
0x00000800
=================================================================================================================================================
*/
void CSimpleOpengl::Init()
{
	if (!m_bInit)
	{
		m_bInit = TRUE;
		static PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW	|
			PFD_SUPPORT_OPENGL	|
			PFD_SUPPORT_GDI		|
			PFD_DOUBLEBUFFER,				// 더블 버퍼 윈도우 (default: 싱글 버퍼 윈도우)
			//PFD_DOUBLEBUFFER_DONTCARE,
			PFD_TYPE_RGBA,					// RGBA 모드 (default)
			24,
			0,0,0,0,0,0,
			0,0,
			0,0,0,0,0,
			32,
			0,//1,
			0,
			PFD_MAIN_PLANE,
			0,
			0,0,0
		};

		int nPixelFormat = ChoosePixelFormat(m_hDc, &pfd);	// DC가 지원하는 주어진 픽셀 포맷 사양과 일치하는 적절한 픽셀 포맷을 찾는다.
		VERIFY(SetPixelFormat(m_hDc, nPixelFormat, &pfd));	// HGLRC(GL Rendering Context Handle)와 DC를 연결

		m_hRC = wglCreateContext(m_hDc);					// Rendering Context 생성
		VERIFY(wglMakeCurrent(m_hDc, m_hRC));				// 현재 스레드에 Rendering Context 설정

		int argc = 1;
		char *argv[1] = { (char*)"Something" };
		glutInit(&argc, argv);								// Window OS와 Session 연결 / GLUT Library를 초기화

		//SetupLight();
		//glDisable(GL_LIGHTING);

		CRect rtDispCtrl;
		::GetClientRect(m_hCtrl, &rtDispCtrl);
		//::GetWindowRect(m_hCtrl, &rtDispCtrl);
		m_rtDispCtrl = rtDispCtrl;
		m_nWorldW = rtDispCtrl.right - rtDispCtrl.left;
		m_nWorldH = rtDispCtrl.bottom - rtDispCtrl.top;
		SetupResize(m_nWorldW, m_nWorldH);
		//SetupCamera(cameraposmap, nWorldW, nWorldH, Angle);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glFlush();											// 그림이 다 그렸졌다는 걸 알려줌.
		SwapBuffers(m_hDc);								// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
	}
}

void CSimpleOpengl::PopupMenu(UINT nFlags, CPoint point)
{
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenu(MF_STRING, (UINT)10001, _T("지표최적화"));
	menu.AppendMenu(MF_STRING, (UINT)10002, _T("시간최적화"));
	menu.AppendMenu(MF_STRING, (UINT)10003, _T("변수최적화"));
	//CRect rect;
	//::GetClientRect(m_hCtrl, &rect);
	CPoint ptMenu = point;
	ClientToScreen(&ptMenu);   //스크린 기준으로 좌표 변환
	UINT nFlagsForMenu = TPM_LEFTALIGN | TPM_RIGHTBUTTON | TPM_RETURNCMD;
	//UINT nFlagsForMenu = TPM_LEFTALIGN | TPM_RIGHTBUTTON | TPM_NONOTIFY | TPM_RETURNCMD;
	/*
	=======================================================================================================
	nFlags:
	=======================================================================================================
	TPM_CENTERALIGN		지정한 위치의 중앙에 오게한다.
	TPM_LEFTALIGN		지정한 위치의 좌측 정렬
	TPM_RIGHTALIGN		지정한 위치의 오른족 정렬
	TPM_BOTTOMALIGN		지정한 위치의 바닥에 정렬.
	TPM_TOPALIGN		지정한 위치의 위쪽에 정렬.
	TPM_VCENTERALIGN	지정한 위치의 수직중앙 정렬.
	TPM_LEFTBUTTON		마우스 왼쪽 버튼을 눌러 팝업메뉴를 선택한다.
	TPM_RIGHTBUTTON		마우스 오른쪽 버튼을 눌러 팝업메뉴를 선택한다.
	TPM_RETURNCMD		TrackPopupMenu 함수가 반환하는 자료형은 BOOL 형이므로 내부적으로 int형 처리된다.
						그러므로 TPM_RETURNCMD를 설정한경우 int형으로 어떤메뉴를 선택했는지 확인할수있다.
	=======================================================================================================
	*/
	int nRetValue = menu.TrackPopupMenu(nFlagsForMenu, ptMenu.x, ptMenu.y, this);
	if (!nRetValue) return;
	menu.DestroyMenu();

	CString sName = _T("Empty");
	switch (nRetValue) 
	{
	case 10001:
		sName = _T("IndexOptimizer");
		break;
	case 10002:
		sName = _T("TimeOptimizer");
		break;
	case 10003:
		sName = _T("VariableOptimizer");
		break;
	}

	AfxMessageBox(sName);
}

void CSimpleOpengl::SetHwnd(HWND hCtrlWnd, CWnd* pParent/*=NULL*/)
{
	m_pParent = pParent;
	if (pParent)
		m_hParent = pParent->GetSafeHwnd();

	m_hCtrl = hCtrlWnd;
	m_pDc = new CClientDC(FromHandle(hCtrlWnd));
	//m_pDc = pDc;
	m_hDc = m_pDc->GetSafeHdc();
	//m_hDc = ::GetDC(hCtrlWnd);
	//m_hDc = ::GetDC(this->GetSafeHwnd());

	//Init();
}

void CSimpleOpengl::Refresh()
{
	RedrawWindow();
}

BOOL CSimpleOpengl::IsDraw()
{
	return m_bDraw;
}

void CSimpleOpengl::ProcThrd(const LPVOID lpContext)
{
	CSimpleOpengl* pSimpleOpengl = reinterpret_cast<CSimpleOpengl*>(lpContext);

	while (pSimpleOpengl->ThreadIsAlive())
	{
		if (!pSimpleOpengl->ProcOpengl())
			break;
		Sleep(30);
	}

	pSimpleOpengl->ThreadEnd();
}

BOOL CSimpleOpengl::ProcOpengl()
{
	if (m_bDraw)
	{
		m_bDraw = FALSE;
		Init();
		DrawClear();
		Draw();
		Draw274X();
	}
	else if (m_bDrawText)
	{
		m_bDrawText = FALSE;
		DrawTxt();
	}
	else if (m_bDrawClear)
	{
		m_bDrawClear = FALSE;
		DrawClear();
	}
	else if (m_bDrawClearColor)
	{
		m_bDrawClearColor = FALSE;
		stColor color = { 0.0, 0.0, 1.0, 1.0 }; // BLUE
		DrawClearColor(color);
	}
	return TRUE;
}

void CSimpleOpengl::ThreadStart()
{
	m_bThreadStateEnd = FALSE;
	m_bThreadAlive = TRUE;
	t1 = std::thread(ProcThrd, this);
}

void CSimpleOpengl::ThreadStop()
{
	m_bThreadAlive = FALSE;
	MSG message;
	const DWORD dwTimeOut = 1000 * 60 * 3; // 3 Minute
	DWORD dwStartTick = GetTickCount();
	Sleep(30);
	while (!m_bThreadStateEnd)
	{
		if (GetTickCount() >= (dwStartTick + dwTimeOut))
		{
			AfxMessageBox(_T("WaitUntilThreadEnd() Time Out!!!", NULL, MB_OK | MB_ICONSTOP));
			return;
		}
		if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&message);
			::DispatchMessage(&message);
		}
		Sleep(30);
	}
}

void CSimpleOpengl::ThreadEnd()
{
	//HWND hWnd = this->GetSafeHwnd();
	//if(!hWnd)
	m_bThreadStateEnd = TRUE;
}

BOOL CSimpleOpengl::ThreadIsAlive()
{
	return m_bThreadAlive;
}

//void CSimpleOpengl::SetupLight(GLfloat R, GLfloat G, GLfloat B, GLfloat A, BOOL CirclePoint)
//{
//	glClearColor(R, G, B, A);
//
//	glEnable(GL_DEPTH_TEST);							//깊이값표현 하기위해사용
//	glEnable(GL_LIGHTING);								//조명을 킨다는뜻
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);			//light0에  자연광을 넣고
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);			//light0에 반사광넣고
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);				//light0에 자연광 위치넣고
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);		//light0반짝임 (재질넣고)
//
//	glEnable(GL_LIGHT0);								//light0를 작동시킴
//
//	if (CirclePoint)glEnable(GL_POINT_SMOOTH);
//
//	glEnable(GL_COLOR_MATERIAL);						//재질 파트
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//재질파트
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specreff);		//재질파트
//	glMateriali(GL_FRONT, GL_SHININESS, 128);
//}

void CSimpleOpengl::SetupResize(int width, int height)
{
	GLfloat fAspect;
	if (height == 0)
		height = 1;

	// OpenGL은 오른손 좌표계임. (default: 화면 중앙이 원점, 좌표계 범위는 [-1.0 ~ 1.0])
	glViewport(0, 0, width, height);								// OpenGL좌표 (0, 0)-좌하단에서 width, height 영역에만 뷰잉을 함. : Viewport = Screen
	
	glMatrixMode(GL_PROJECTION);									// 현재의 행렬 모드를 설정.
	glLoadIdentity();												// 현재의 변환 행렬을 단위행렬로 설정. (모델 좌표계 = 전역 좌표계 = 시점 좌표계) : 행렬처리가 이루어 지기 전에 좌표계를 초기화 함.

	glOrtho(0.0, width, 0.0, height, -2, 2);						// Viewport 좌표계의 범위를 설정 (min_x, max_x, min_y, max_y, near, far) : (left, right, bottom, top, near, far)
	//glOrtho(0.0, width, height, 0.0, -2, 2);						// Viewport 좌표계의 범위를 설정 (min_x, max_x, min_y, max_y, near, far) : (left, right, bottom, top, near, far)

	//glOrtho(-0.5 * cx, 0.5 * cx, -0.5 * cy, 0.5 * cy, -2, 2);
	//glOrtho(0.0, cx, 0.0, cy, -2, 2);								// Viewport 좌표계의 범위를 설정 (min_x, max_x, min_y, max_y, near, far) : (left, right, bottom, top, near, far)
	
	
	/*
	=============================================================================
	GLenum mode
	=============================================================================
	GL_MODELVIEW	:	모델링 및 뷰잉 변환 모드 (물체 이동 시)
						디폴트 모드로 GL_MODELVIEW 로 설정됨.
	GL_PROJECTION	:	투영 변환 모드 (클리핑 공갂 정의)
	GL_TEXTURE		:	텍스처 매핑 모드 (텍스처 매핑 정의)
	=============================================================================
	*/
	glMatrixMode(GL_MODELVIEW);										// 현재의 행렬 모드를 설정.
	glLoadIdentity();												// 현재의 변환 행렬을 단위행렬로 설정. (모델 좌표계 = 전역 좌표계 = 시점 좌표계) : 행렬처리가 이루어 지기 전에 좌표계를 초기화 함.

	gluPerspective(0.0, 1.0, 1.0, 1.0);							// 원근 투영을 사용하는 경우: fovy: 수직 방향의 보이는 각도 (y축 방향) , aspect: 종횡비 (앞쪽의 클리핑 평면의 폭(w)을 높이(h)로 나눈 값), zNear, zFar
	//gluLookAt(-100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);			// 관측 변환: 카메라의 위치 설정 (필요한 경우, 다른 곳에 설정 가능)
	//glTranslated(100.0, 0.0, 0.0);
	/*
	void glLoadMatrixd ( const GLdouble * m);	// m: 4*4 행렬 값 (16개의 연속된 값) - 행렬은 열 우선 벡터를 사용
	void glLoadMatrixf ( const GLfloat * m);	// 현재의 행렬 (CTM, Current Transformation Matrix)을 m의 값으로 바꾼다.

	void glMultMatrixf (const GLfloat *m);		// 현재 행렬에 행렬 m을 곱한다.
	void glMultMatrixd (const Gldouble *m);		

	void glLoadTransposeMatrix{fd} (…);			// 행 우선 행렬 사용
	void glMultTransposeMatrix{fd} (…);

	GL함수 호출(좌표계 변환) 순서에 역순으로 물체 변환이 이루어짐.
	
	모델링 변환 (이동, 회전, 신축)
	glTranslated (GLdouble x, GLdouble y, GLdouble z);	// (x, y, z)로 이동
	glTranslatef (GLfloat x, GLfloat y, GLfloat z);		// 

	glRotated (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);	// 원점과 (x, y, z)을 지나는 선을 축으로 angle만큼 회전
	glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);		// Angle: 도 (degree)단위

	glScaled (GLdouble x, GLdouble y, GLdouble z);		// (x, y, z) 축으로 (x, y, z) 배 만큼 신축
	glScalef (GLfloat x, GLfloat y, GLfloat z);			//

	void glPushMatrix ()	: 스택에 행렬을 저장한다.(현재 좌표축 저장)
	void glPopMatrix ()		: 스택의 행렬을 꺼낸다. (변환전의 좌표축으로 복구)
	*/
/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fAspect = (GLfloat)cx / (GLfloat)cy;
	gluPerspective(45.0f, fAspect, 1.0f, -1.0f);					// (시야각, 종횡비 (W/H), Front_z, Back_z)
	//GLfloat f_w = (GLfloat)cx / (GLfloat)_WINDOW_WIDTH;
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -2, 2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
}

//void CSimpleOpengl::SetupCamera(GLfloat *cameraposmap, int W, int H, GLfloat *Angle)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glRotatef(Angle[2], 0.0f, 0.0f, 1.0f);
//
//	glTranslatef(cameraposmap[0], cameraposmap[1], cameraposmap[2]);
//
//	glRotatef(Angle[0], 1.0f, 0.0f, 0.0f);
//	glRotatef(Angle[1], 0.0f, 1.0f, 0.0f);
//}

void CSimpleOpengl::DrawDisp()
{
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌. 모든 명령어를 실행되게 함.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
}

void CSimpleOpengl::DrawBegin(int nMode, int nSize, COLORREF color)
{
	if (nMode < Opengl::modPoint || nMode > Opengl::modCircleF)
		return;

	glPushMatrix();										// Martrix상태를 스택에 넣는다.
	GLfloat red = GetRValue(color) / 255.0;
	GLfloat green = GetGValue(color) / 255.0;
	GLfloat blue = GetBValue(color) / 255.0;
	GLfloat alpa = 0.0;
	glColor4f(red, green, blue, alpa);		// drawing color를 설정한다.

	/* glBegin ~ glEnd 블록 사이에 위치만을 가지는 정점만을 정의함
	모드				설명
	============================================================
	GL_POINTS			독립적인 점
	GL_LINE_STRIP		연결된 선분
	GL_LINE_LOOP		시작점과 끝점을 이은 선분
	GL_LINES			두개의 정점들을 이은 선분
	GL_TRIANGLES		세개씩 연결한 삼각형
	GL_TRIANGLE_STRIP	연결된 삼각형
	GL_TRIANGLE_FAN		중심을 공유하는 삼각형
	GL_QUADS			정점 4개씩을 연결하여 사각형을 그린다.
	GL_QUAD_STRIP		연결된 사각형
	GL_POLYGON			연결된 볼록 다각형
	============================================================*/
	
	switch (nMode)
	{
	case Opengl::modPoint:
		glPointSize(nSize);				// nSize : 점의 크기 (0.5부터 10.0까지 지정, 설정 간격은 0.125 이상, default : 1.0) - glBegin() - glEnd() 밖에서 사용
		glBegin(GL_POINTS);
		break;
	case Opengl::modLine:
	case Opengl::modRectE:
	case Opengl::modCross:
	case Opengl::modCrossX:
		glLineWidth(nSize);				// nSize : 선의 굵기 (0.5에서 10.0까지 지정, 설정 간격은 0.125 이상, default : 1.0) - PointSize/LineWidth 0.0보다 커야함.
		glBegin(GL_LINES);
		break;
	case Opengl::modRectF:
		glLineWidth(nSize);
		glBegin(GL_QUADS);
		break;
	case Opengl::modCircleE:
		glLineWidth(nSize);
		glBegin(GL_LINE_LOOP);
		break;
	case Opengl::modCircleF:
		glLineWidth(nSize);
		glBegin(GL_POLYGON);			// 꼭지점을 반시계 방향으로 그린 쪽이 앞면
		break;
	// glLineStipple (factor, pattern);	// 스티플링: 점선이나 쇄선의 모양[pattern is 16bits], (3, 0x5555) -> ( 1bit is 3pixel, 0x5555 is 0101(5)0101(5)0101(5)0101(5) ) 뒤에서부터 (5)1010 : 선 공백 선 공백 으로 표시
	}
}

void CSimpleOpengl::DrawEnd()
{
	glEnd();
	glPopMatrix();	// Martrix상태를 스택에서 꺼낸다
}

void CSimpleOpengl::DrawRect(stVertex V1, stVertex V2)
{
	float X1 = V1.x; float Y1 = V1.y; 
	float X2 = V2.x; float Y2 = V2.y;
	AdjustToScreen(X1, Y1, X2, Y2);

	glVertex3f(X1, Y1, V1.z);
	glVertex3f(X2, Y1, V2.z);

	glVertex3f(X2, Y1, V2.z);
	glVertex3f(X2, Y2, V2.z);

	glVertex3f(X2, Y2, V2.z);
	glVertex3f(X1, Y2, V1.z);

	glVertex3f(X1, Y2, V1.z);
	glVertex3f(X1, Y1, V1.z);

	//glVertex3f(V1.x, V1.y, V1.z);
	//glVertex3f(V2.x, V1.y, V2.z);
	//
	//glVertex3f(V2.x, V1.y, V2.z);
	//glVertex3f(V2.x, V2.y, V2.z);
	//
	//glVertex3f(V2.x, V2.y, V2.z);
	//glVertex3f(V1.x, V2.y, V1.z);
	//
	//glVertex3f(V1.x, V2.y, V1.z);
	//glVertex3f(V1.x, V1.y, V1.z);
}

void CSimpleOpengl::DrawLine(stVertex V1, stVertex V2)
{
	float X1 = V1.x; float Y1 = V1.y;
	float X2 = V2.x; float Y2 = V2.y;
	AdjustToScreen(X1, Y1, X2, Y2);
	glVertex3f(X1, Y1, V1.z);
	glVertex3f(X2, Y2, V2.z);
	//glVertex3f(V1.x, V1.y, V1.z);
	//glVertex3f(V2.x, V2.y, V2.z);
}

void CSimpleOpengl::SetTextOpenGL(CString str, stVertex pos, int size, stColor color, int line_width) //  Text
{
	int nLen = str.GetLength();
	char* pData = new char[nLen + 1]; // for '\0'
	StringToChar(str, pData);

	char *c;
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glLineWidth(line_width);
	glColor3f(color.R, color.G, color.B);			// 색을 선택하는 함수로써 불투명도는 지정하지 않는다.
	glScalef(0.01f*size, 0.01f*size, 0.01f*size);

	for (c = pData; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();

	delete pData;
}


HBRUSH CSimpleOpengl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (CTLCOLOR_STATIC == nCtlColor)
	{
		//Draw(pDC);
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}

void CSimpleOpengl::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (CTLCOLOR_STATIC == nIDCtl)
	{
		//CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
		//CRect rect = lpDrawItemStruct->rcItem;
		////UINT state = lpDrawItemStruct->itemState;

		//DrawText(pDC, rect);
	}

	CStatic::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CSimpleOpengl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.

	//DrawText();

	//Draw();
	m_bDraw = TRUE;
	//m_bDrawText = TRUE;
}

void CSimpleOpengl::StringToChar(CString str, char* szStr)  // char* returned must be deleted... 
{
	int nLen = str.GetLength();
	strcpy(szStr, CT2A(str));
	szStr[nLen] = _T('\0');
}

void CSimpleOpengl::AddLine(stVertex v1, stVertex v2)
{
	stLine _line;
	_line.v1 = v1;
	_line.v2 = v2;
	m_arLine.Add(_line);
}

void CSimpleOpengl::AddText(CString str, CPoint pos, COLORREF color)
{
	stText _text;
	_text.str = str;
	_text.pos = pos;
	_text.color = color;
	m_arText.Add(_text);
}

//void CSimpleOpengl::Draw()
//{
//	stVertex v1, v2;
//	stColor color;
//
//	v1.x = m_nWorldW/2; v1.y = m_nWorldH/2; v1.z = 0.0;
//	SetTextOpenGL(_T("Shin Yong Dae"), v1);
//
//	v1.x = 1; v1.y = 1; v1.z = 0.0;
//	v2.x = m_nWorldW; v2.y = m_nWorldH; v2.z = 0.0;
//	color.R = 1.0; color.G = 0.0; color.B = 0.0; color.A = 0.0;
//	DrawBegin(Opengl::modLine, 1, color);
//	DrawRect(v1, v2);
//	DrawEnd();
//
//	v1.x = 0.25*m_nWorldW; v1.y = 0.25*m_nWorldH; v1.z = 0.0;
//	v2.x = 0.75*m_nWorldW; v2.y = 0.75*m_nWorldH; v2.z = 0.0;
//	color.R = 0.0; color.G = 1.0; color.B = 0.0; color.A = 0.0;
//	DrawBegin(Opengl::modLine, 1, color);
//	DrawRect(v1, v2);
//	DrawEnd();
//
//	glFlush();				// 그림이 다 그렸졌다는 걸 알려줌.
//	SwapBuffers(m_hDc);		// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
//}

void CSimpleOpengl::Draw()
{
	int i, nTotal;
	stLine _line;
	//stColor color;

	nTotal = m_arLine.GetCount();

	if (nTotal <= 0)	return;

	//color.R = 1.0; color.G = 0.0; color.B = 0.0; color.A = 0.0;
	DrawBegin(Opengl::modLine, 1, RGB_BLUE);//color

	for (i = 0; i < nTotal; i++)
	{
		_line = m_arLine.GetAt(i);
		DrawLine(_line.v1, _line.v2);
	}

	DrawEnd();
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌. 모든 명령어를 실행되게 함.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용

	//m_arLine.RemoveAll();
}

void CSimpleOpengl::DrawClear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 컬러 버퍼: GL_COLOR_BUFFER_BIT, 깊이 버퍼: GL_DEPTH_BUFFER_BIT, 누적 버퍼: GL_ACCUM_BUFFER_BIT, 스텐실 버퍼: GL_STENCIL_BUFFER_BIT
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 컬러 버퍼: GL_COLOR_BUFFER_BIT, 깊이 버퍼: GL_DEPTH_BUFFER_BIT, 누적 버퍼: GL_ACCUM_BUFFER_BIT, 스텐실 버퍼: GL_STENCIL_BUFFER_BIT
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
}

void CSimpleOpengl::DrawClearColor(stColor color)
{
	glClearColor(color.R, color.G, color.B, 1.0);	// 바탕색을 지정, alpha 값 (1.0값으로 고정)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
	
	glClearColor(color.R, color.G, color.B, 1.0);	// 바탕색을 지정, alpha 값 (1.0값으로 고정)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
}

void CSimpleOpengl::DrawTxt()
{
	// Draw the text
	CRect rect;
	::GetClientRect(m_hCtrl, &rect);
	CDC* pDC = m_pDc;
	CString strWnd, strText, strPars, strRem;
	GetWindowText(strWnd);
	strWnd = _T("OpenGL Test");
	strText = _T("OpenGL Test");

	//if (m_nTxtDispSt < 0)
	//{
	//	if (m_chkState & DFCS_PUSHED)
	//	{
	//		if (!m_strDn.IsEmpty())
	//			strText = m_strDn;
	//		else
	//			strText = strWnd;
	//	}
	//	else
	//	{
	//		if (!m_strUp.IsEmpty())
	//			strText = m_strUp;
	//		else
	//			strText = strWnd;
	//	}
	//}
	//else
	//{
	//	if (m_nTxtDispSt == BTN_UP)
	//	{
	//		if (!m_strUp.IsEmpty())
	//			strText = m_strUp;
	//		else
	//			strText = strWnd;
	//	}
	//	else if (m_nTxtDispSt == BTN_DN)
	//	{
	//		if (!m_strDn.IsEmpty())
	//			strText = m_strDn;
	//		else
	//			strText = strWnd;
	//	}
	//}

	//if (!strText.IsEmpty())
	{
		HFONT hOldFont = NULL;
		//Sets the font
		if (m_Font.GetSafeHandle() != NULL)
		{
			hOldFont = (HFONT)pDC->SelectObject(m_Font.GetSafeHandle());
		}

		CPoint pt;
		CSize Extent = pDC->GetTextExtent(strText);
		//  	CPoint pt( rect.CenterPoint().x - Extent.cx/2, rect.CenterPoint().y - Extent.cy/2 );
		/*
		if((m_style & BS_CENTER) == BS_CENTER)
		{
		pt.x = rect.CenterPoint().x - Extent.cx/2;
		pt.y = rect.CenterPoint().y - Extent.cy/2;
		}
		else if((m_style & BS_RIGHT) == BS_RIGHT)
		{
		pt.x = rect.right - Extent.cx;
		pt.y = rect.CenterPoint().y - Extent.cy/2;
		}
		else if((m_style & BS_LEFT) == BS_LEFT)
		{
		pt.x = 0;
		pt.y = rect.CenterPoint().y - Extent.cy/2;
		}
		*/
		pt.y = rect.CenterPoint().y - Extent.cy / 2;

		// 		if (state & ODS_SELECTED) 
		//             pt.Offset(1,1);

		int nMode = pDC->SetBkMode(TRANSPARENT);
		COLORREF crTextOld = pDC->SetTextColor(m_crText);

		// 		if (state & ODS_DISABLED)
		// 			pDC->DrawState(pt, Extent, strText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
		// 		else 
		{
			int nPos, nLine = 0;
			CString strLineText[MAX_LINE];
			CPoint LinePos[MAX_LINE];

			nLine++;

			do
			{
				nPos = strText.Find(_T("_"), 0);
				if (nPos == 0)
				{
					strText.SetAt(nPos, _T(' '));
				}

				nPos = strText.Find(_T("&&"), 0);
				if (nPos >= 0)
					strText.Delete(nPos);

				nPos = strText.Find(_T("\\r"), 0);
				if (nPos > 0)
				{
					strPars = strText.Left(nPos);
					strRem = strText.Right(strText.GetLength() - nPos - 2);
					strLineText[nLine - 1] = strPars;
					strText = strRem;
					nLine++;
				}
				else
				{
					nPos = strText.Find(_T("\r"), 0);
					if (nPos > 0)
					{
						strPars = strText.Left(nPos);
						strRem = strText.Right(strText.GetLength() - nPos - 1);
						strLineText[nLine - 1] = strPars;
						strText = strRem;
						nLine++;
					}
				}

			} while (nPos > 0);

			strLineText[nLine - 1] = strText;
			LinePos[0].y = pt.y - (Extent.cy / 2 * (nLine - 1)) - (LINE_SPACE * (nLine - 1) / 2);

			//if (state & ODS_SELECTED || m_nImgBk == BTN_IMG_DN)
			//	LinePos[0].y++;

			for (int nL = 0; nL<nLine; nL++)
			{
				Extent = pDC->GetTextExtent(strLineText[nL]);
				//  					LinePos[nL].x = rect.CenterPoint().x - Extent.cx/2;
				// 					LinePos[nL].x = pt.x;

				//if ((m_style & BS_CENTER) == BS_CENTER)
				//{
				//	LinePos[nL].x = rect.CenterPoint().x - Extent.cx / 2;
				//}
				//else if ((m_style & BS_RIGHT) == BS_RIGHT)
				//{
				//	LinePos[nL].x = rect.right - Extent.cx;
				//}
				//else if ((m_style & BS_LEFT) == BS_LEFT)
				//{
				//	LinePos[nL].x = 0;
				//}
				//else
				{
					LinePos[nL].x = rect.CenterPoint().x - Extent.cx / 2;
				}

				//if (state & ODS_SELECTED || m_nImgBk == BTN_IMG_DN)
				//	LinePos[nL].x++;

				if (nL>0)
					LinePos[nL].y = LinePos[nL - 1].y + Extent.cy + LINE_SPACE;

				pDC->TextOut(LinePos[nL].x, LinePos[nL].y, strLineText[nL]);
			}
		}

		pDC->SetBkMode(nMode);

		//Reset the old font
		if (hOldFont != NULL)
		{
			pDC->SelectObject(hOldFont);
		}
	}

}

void CSimpleOpengl::SetClear()
{
	m_bDrawClear = TRUE;
}

void CSimpleOpengl::SetClearColor()
{
	m_bDrawClearColor = TRUE;
}

void CSimpleOpengl::SetDraw()
{
	m_bDraw = TRUE;
	//m_bDrawText = TRUE;
}

void CSimpleOpengl::SetFont(CString srtFntName, int nSize, BOOL bBold)
{
	if (m_bFont)
	{
		if (m_Font.DeleteObject())
			m_bFont = FALSE;
	}

	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 0;

	lfCtrl.lfHeight = nSize;
	lfCtrl.lfWeight = bBold ? FW_BOLD : FW_NORMAL;

	lfCtrl.lfItalic = FALSE;
	lfCtrl.lfUnderline = FALSE;
	lfCtrl.lfStrikeOut = FALSE;

	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	_tcscpy(lfCtrl.lfFaceName, srtFntName);

	if (!m_bFont)
	{
		BOOL bCr = m_Font.CreateFontIndirect(&lfCtrl);
		if (bCr)
			m_bFont = TRUE;
	}
}


void CSimpleOpengl::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PopupMenu(nFlags, point);

	CStatic::OnRButtonDown(nFlags, point);
}


// Draw274X

void CSimpleOpengl::Draw274X()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	pParent->Draw274X();
	glFlush();											// 그림이 다 그렸졌다는 걸 알려줌. 모든 명령어를 실행되게 함.
	SwapBuffers(m_hDc);									// OpenGL이 완료한 그림을 새롭게 화면에 그린다 - 현재 buffer에 그려진 것과 Frame에 그려진 것을 swap(Double buffer), 그리기 함수에서 glFlush 대신 사용
}

//void CSimpleOpengl::Drawing_0()
//{
//	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
//	LPLAYER_INFORM_RS274X pLayerInfo = pParent->GetLayerInfo();
//}



void CSimpleOpengl::SetPixelResolution(double dPixelResolution)
{
	m_dPixelResolution = dPixelResolution;
}

BOOL CSimpleOpengl::DrawObject(UINT nObjIndex)	//MyObjEntity
{
	
	return FALSE; 
}

void CSimpleOpengl::SetForeColor(COLORREF crColor)
{
	float R, G, B;

	R = (GetRValue(crColor) / 255.0f);
	G = (GetGValue(crColor) / 255.0f);
	B = (GetBValue(crColor) / 255.0f);
	float currentColor[4];
	glGetFloatv(GL_CURRENT_COLOR, currentColor);
	if (currentColor[0] != R || currentColor[1] != G || currentColor[2] != B)
		glColor3f(R, G, B);
}

void CSimpleOpengl::MyLineList(float X1, float Y1, float X2, float Y2, int nListNum)
{
	AdjustToScreen(X1, Y1, X2, Y2);

	stVertex V1, V2;
	V1.x = X1; V1.y = Y1; V1.z = 0.0;
	V2.x = X2; V2.y = Y2; V2.z = 0.0;
	glVertex3f(V1.x, V1.y, V1.z);
	glVertex3f(V2.x, V2.y, V2.z);
}
//void CSimpleOpengl::MyLineList(float X1, float Y1, float X2, float Y2, int nListNum)
//{
//	float Xc,Yc;
//
//	Xc=((X2+X1)/2);
//	Yc=((Y1+Y2)/2);
//
//	float fAngleRad = atan2(Y1-Y2,X1-X2);
//	float fRotate = RAD2DEG*fAngleRad;
//	
//	glPushMatrix();
//	glTranslatef(Xc,Yc,0);
//	glRotatef(fRotate,0.0f, 0.0f, 1.0f);
//	 	
//	glCallList(nListNum);
//	glPopMatrix();
//}

void CSimpleOpengl::DrawConvexPolygon(const vector <FPOINTC> &fPoint)
{
	glPushMatrix();										// Martrix상태를 스택에 넣는다.
	glBegin(GL_POLYGON);
	int i, nNumOfVertex;
	nNumOfVertex = fPoint.size();
	for (i = 0; i < nNumOfVertex; i++)
	{
		float X1 = fPoint.at(i).x; float Y1 = fPoint.at(i).y;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(fPoint.at(i).x, fPoint.at(i).y);
	}
	glEnd();
	glPopMatrix();										// Martrix상태를 스택에서 뺀다.
}

void CSimpleOpengl::DrawConvexPolygon(const FPOINTC *fPoint, int nNumberOfVertex)
{
	glPushMatrix();										// Martrix상태를 스택에 넣는다.
	glBegin(GL_POLYGON);
	int i;
	for (i = 0; i < nNumberOfVertex; i++)
	{
		float X1 = fPoint[i].x; float Y1 = fPoint[i].y;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(fPoint[i].x, fPoint[i].y);
	}
	glEnd();
	glPopMatrix();										// Martrix상태를 스택에서 뺀다.
}


COLORREF CSimpleOpengl::GetObjectColorCurrent()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	COLORREF color = RGB_WHITE;
	if (pParent)
		color = pParent->GetObjectColorCurrent();
	return color;
}

void CSimpleOpengl::DrawConcavePolygon(const vector <FPOINTC> &fPoint)
{
	//return;
	float X1, Y1;

	COLORREF color = GetObjectColorCurrent();
	glPushMatrix();										// Martrix상태를 스택에 넣는다.
	GLfloat red = GetRValue(color) / 255.0;
	GLfloat green = GetGValue(color) / 255.0;
	GLfloat blue = GetBValue(color) / 255.0;
	GLfloat alpa = 0.0;
	glColor4f(red, green, blue, alpa);		// drawing color를 설정한다.

	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_NEVER, 0, 1); // 항상 실패, 기준값 0, 마스크값은 1
	glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT); // 스텐실 테스트 실패 시 동작: 비트 반전, 스텐실 테스트는 통과했지만 깊이 테스트 실패 시 동작: 비트 반전, 스텐실 테스트와 깊이 테스트 모두 통과 시 동작: 비트 반전

	glBegin(GL_TRIANGLE_FAN);
	//glBegin(GL_POLYGON);
	int i, nNumOfVertex;
	nNumOfVertex = fPoint.size();
	for (i = 0; i < nNumOfVertex; i++)
	{
		X1 = fPoint.at(i).x; Y1 = fPoint.at(i).y;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(fPoint.at(i).x, fPoint.at(i).y);
	}
	//X1 = fPoint.at(0).x; Y1 = fPoint.at(0).y;
	//AdjustToScreen(X1, Y1);
	//glVertex2f(X1, Y1);
	glEnd();


	glStencilFunc(GL_EQUAL, 1, 1); // 스텐실 값이 기준 값과 같을 때 통과, 기준값 1, 마스크값은 1
	glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO); // 스텐실 테스트 실패 시 동작: 0으로 변경, 스텐실 테스트는 통과했지만 깊이 테스트 실패 시 동작: 0으로 변경, 스텐실 테스트와 깊이 테스트 모두 통과 시 동작: 0으로 변경

	glBegin(GL_TRIANGLE_FAN);
	//glBegin(GL_POLYGON);
	for (i = 0; i < nNumOfVertex; i++)
	{
		X1 = fPoint.at(i).x; Y1 = fPoint.at(i).y;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(fPoint.at(i).x, fPoint.at(i).y);
	}
	//X1 = fPoint.at(0).x; Y1 = fPoint.at(0).y;
	//AdjustToScreen(X1, Y1);
	//glVertex2f(X1, Y1);
	glEnd();

	glDisable(GL_STENCIL_TEST);
	glPopMatrix();										// Martrix상태를 스택에서 뺀다.
}

void CSimpleOpengl::DrawPolygonLine(const vector <FPOINTC> &vecPt, int nLineWidth)
{
	GLfloat lineWidth;
	int i, nNumOfVertex;
	nNumOfVertex = vecPt.size();

	glPushMatrix();										// Martrix상태를 스택에 넣는다.
	if (nLineWidth != 0)
	{
		glGetFloatv(GL_LINE_WIDTH, &lineWidth);
		glLineWidth(nLineWidth);
		glBegin(GL_LINE_LOOP);
		for (i = 0; i < nNumOfVertex; i++)
		{
			float X1 = vecPt.at(i).x; float Y1 = vecPt.at(i).y;
			AdjustToScreen(X1, Y1);
			glVertex2f(X1, Y1);
			//glVertex2f(vecPt.at(i).x, vecPt.at(i).y);
		}
		glEnd();
		glLineWidth(lineWidth);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
		for (i = 0; i < nNumOfVertex; i++)
		{
			float X1 = vecPt.at(i).x; float Y1 = vecPt.at(i).y;
			AdjustToScreen(X1, Y1);
			glVertex2f(X1, Y1);
			//glVertex2f(vecPt.at(i).x, vecPt.at(i).y);
		}
		glEnd();
	}
	glPopMatrix();										// Martrix상태를 스택에서 뺀다.
}

void CSimpleOpengl::DrawLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight)
{
	float ww, hh, a, b;
	FPOINTC pp[6];

	ww = fLineWidth / 2;
	hh = fLineHeight / 2;

	if (fSx != fEx && fSy != fEy)
	{
		if (fEx > fSx)
		{
			if (fEy > fSy)
			{
				pp[0].x = (fSx - ww);
				pp[0].y = (fSy - hh);
				pp[1].x = (fSx - ww);
				pp[1].y = (fSy + hh);
				pp[2].x = (fEx - ww);
				pp[2].y = (fEy + hh);
				pp[3].x = (fEx + ww);
				pp[3].y = (fEy + hh);
				pp[4].x = (fEx + ww);
				pp[4].y = (fEy - hh);
				pp[5].x = (fSx + ww);
				pp[5].y = (fSy - hh);
			}
			else
			{
				pp[0].x = (fSx - ww);
				pp[0].y = (fSy - hh);
				pp[1].x = (fSx - ww);
				pp[1].y = (fSy + hh);
				pp[2].x = (fSx + ww);
				pp[2].y = (fSy + hh);
				pp[3].x = (fEx + ww);
				pp[3].y = (fEy + hh);
				pp[4].x = (fEx + ww);
				pp[4].y = (fEy - hh);
				pp[5].x = (fEx - ww);
				pp[5].y = (fEy - hh);
			}
		}
		else
		{
			if (fSy > fEy)
			{
				pp[0].x = (fEx - ww);
				pp[0].y = (fEy - hh);
				pp[1].x = (fEx - ww);
				pp[1].y = (fEy + hh);
				pp[2].x = (fSx - ww);
				pp[2].y = (fSy + hh);
				pp[3].x = (fSx + ww);
				pp[3].y = (fSy + hh);
				pp[4].x = (fSx + ww);
				pp[4].y = (fSy - hh);
				pp[5].x = (fEx + ww);
				pp[5].y = (fEy - hh);
			}
			else
			{
				pp[0].x = (fEx - ww);
				pp[0].y = (fEy - hh);
				pp[1].x = (fEx - ww);
				pp[1].y = (fEy + hh);
				pp[2].x = (fEx + ww);
				pp[2].y = (fEy + hh);
				pp[3].x = (fSx + ww);
				pp[3].y = (fSy + hh);
				pp[4].x = (fSx + ww);
				pp[4].y = (fSy - hh);
				pp[5].x = (fSx - ww);
				pp[5].y = (fSy - hh);
			}
		}

		DrawConvexPolygon(pp, 6);
	}
	else
	{
		FPOINTC pp[4];
		if (fSx == fEx && fSy == fEy)
		{
			pp[0].x = (fSx - ww);     //  '좌하
			pp[0].y = (fSy - hh);     //
			pp[1].x = (fSx + ww);     //  '우하
			pp[1].y = (fSy - hh);     //

			pp[2].x = (fEx + ww);     //  '우상
			pp[2].y = (fEy + hh);     //
			pp[3].x = (fEx - ww);     //  '좌상
			pp[3].y = (fEy + hh);     //
		}
		else if (fSx == fEx)
		{
			if (fSy > fEy)//  'b > a가 되게
			{
				a = fEy;
				b = fSy;
			}
			else
			{
				a = fSy;
				b = fEy;
			}
			pp[0].x = (fSx - ww);     //  '좌하
			pp[0].y = (a - hh);      //
			pp[1].x = (fSx + ww);     //  '우하
			pp[1].y = (a - hh);      //

			pp[2].x = (fEx + ww);     //  '우상
			pp[2].y = (b + hh);      //
			pp[3].x = (fEx - ww);    //   '좌상
			pp[3].y = (b + hh);     // 
		}
		else
		{
			if (fSx > fEx)
			{
				a = fEx;
				b = fSx;
			}
			else
			{
				a = fSx;
				b = fEx;
			}
			pp[0].x = (a - ww);      //  '좌하
			pp[0].y = (fSy - hh);     //
			pp[1].x = (b + ww);      //  '우하
			pp[1].y = (fSy - hh);    // 

			pp[2].x = (b + ww);      //  '우상
			pp[2].y = (fEy + hh);     //
			pp[3].x = (a - ww);     //   '좌상
			pp[3].y = (fEy + hh);    // 
		}
		DrawConvexPolygon(pp, 4);
	}
}

void CSimpleOpengl::DrawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, int fill)
{
	//if (fill)
	//	glBegin(GL_QUADS); // filled quad
	//else
	//	glBegin(GL_LINE_LOOP); // hollow quad
	AdjustToScreen(x1, y1, x2, y2);
	AdjustToScreen(x3, y3, x4, y4);

	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	//glEnd();
}

void CSimpleOpengl::DrawRect(const CfPoint3D &fptStart, const CfPoint3D &fptEnd, int width, int fill)
{
	float X1 = fptStart.x; float Y1 = fptStart.y; float Z1 = fptStart.z;
	float X2 = fptEnd.x; float Y2 = fptEnd.y; float Z2 = fptEnd.z;
	AdjustToScreen(X1, Y1, X2, Y2);

	GLfloat lineWidth;
	if (fill)
	{
		glVertex3f(X1, Y1, fptStart.z);
		glVertex3f(X1, Y2, fptStart.z);
		glVertex3f(X2, Y2, fptStart.z);
		glVertex3f(X2, Y1, fptStart.z);
		//glBegin(GL_QUADS); // filled quad
		//glVertex3f(fptStart.x, fptStart.y, fptStart.z);
		//glVertex3f(fptStart.x, fptEnd.y, fptStart.z);
		//glVertex3f(fptEnd.x, fptEnd.y, fptStart.z);
		//glVertex3f(fptEnd.x, fptStart.y, fptStart.z);
		//glEnd();
	}
	else
	{
		if (width != 0)
		{
			glVertex3f(X1, Y1, fptStart.z);
			glVertex3f(X1, Y2, fptStart.z);
			glVertex3f(X2, Y2, fptStart.z);
			glVertex3f(X2, Y1, fptStart.z);
			//glGetFloatv(GL_LINE_WIDTH, &lineWidth);
			//glLineWidth(width);
			//glBegin(GL_LINE_LOOP); // hollow quad
			//glVertex3f(fptStart.x, fptStart.y, fptStart.z);
			//glVertex3f(fptStart.x, fptEnd.y, fptStart.z);
			//glVertex3f(fptEnd.x, fptEnd.y, fptStart.z);
			//glVertex3f(fptEnd.x, fptStart.y, fptStart.z);
			//glEnd();
			//glLineWidth(lineWidth);
		}
		else
		{
			glVertex3f(X1, Y1, fptStart.z);
			glVertex3f(X1, Y2, fptStart.z);
			glVertex3f(X2, Y2, fptStart.z);
			glVertex3f(X2, Y1, fptStart.z);
			//glBegin(GL_LINE_LOOP); // hollow quad
			//glVertex3f(fptStart.x, fptStart.y, fptStart.z);
			//glVertex3f(fptStart.x, fptEnd.y, fptStart.z);
			//glVertex3f(fptEnd.x, fptEnd.y, fptStart.z);
			//glVertex3f(fptEnd.x, fptStart.y, fptStart.z);
			//glEnd();
		}
	}
}

void CSimpleOpengl::DrawDonut(float fCx, float fCy, float fDmo, float fDmi)
{
	glPushMatrix();
	COLORREF color = RGB_YELLOW;
	GLfloat red = GetRValue(color) / 255.0;
	GLfloat green = GetGValue(color) / 255.0;
	GLfloat blue = GetBValue(color) / 255.0;
	GLfloat alpa = 0.0;
	glColor4f(red, green, blue, alpa);		// drawing color를 설정한다.
	glLineWidth(1);

	float w = (fDmo - fDmi) / 2;
	int segments = GetArcSegment(fDmo / 2);
	float theta = 2 * PI / float(segments);
	float tangetial_factor = tanf(theta);
	float radial_factor = 1 - cosf(theta);
	float x1 = fCx + (fDmo / 2);
	float y1 = fCy;
	float x2 = fCx + (fDmi / 2);
	float y2 = fCy;
	float tx, ty, rx, ry;

	int i;
	glEnable(GL_STENCIL_TEST);
	StencilSet(FALSE);

	glBegin(GL_POLYGON);
	for (i = 0; i < segments + 1; i++)
	{
		float X1 = x2; float Y1 = y2;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(x2, y2);
		tx = -(y2 - fCy);
		ty = x2 - fCx;
		x2 += tx * tangetial_factor;
		y2 += ty * tangetial_factor;
		rx = fCx - x2;
		ry = fCy - y2;
		x2 += rx * radial_factor;
		y2 += ry * radial_factor;
	}
	glEnd();
	StencilSet(TRUE);
	glBegin(GL_POLYGON);
	for (i = 0; i < segments + 1; i++)
	{
		float X1 = x1; float Y1 = y1;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(x1, y1);
		tx = -(y1 - fCy);
		ty = x1 - fCx;
		x1 += tx * tangetial_factor;
		y1 += ty * tangetial_factor;
		rx = fCx - x1;
		ry = fCy - y1;
		x1 += rx * radial_factor;
		y1 += ry * radial_factor;
	}
	glEnd();
	StencilClear(TRUE);
	glDisable(GL_STENCIL_TEST);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < segments + 1; i++)
	{
		float X1 = x2; float Y1 = y2;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(x2, y2);
		tx = -(y2 - fCy);
		ty = x2 - fCx;
		x2 += tx * tangetial_factor;
		y2 += ty * tangetial_factor;
		rx = fCx - x2;
		ry = fCy - y2;
		x2 += rx * radial_factor;
		y2 += ry * radial_factor;
	}
	glEnd();
	glPopMatrix();	// Martrix상태를 스택에서 꺼낸다
}


void CSimpleOpengl::StencilBegin()
{

}

void CSimpleOpengl::StencilSet(BOOL bStencil)
{
	if (bStencil == STENCIL_DARK)
	{
		glStencilFunc(GL_EQUAL, 0, 15); // 스텐실 값이 기준 값과 같을 때 통과, 기준값 0, 마스크값은 0x0F
		glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO); // 스텐실 테스트 실패 시 동작: 0으로 변경, 스텐실 테스트는 통과했지만 깊이 테스트 실패 시 동작: 0으로 변경, 스텐실 테스트와 깊이 테스트 모두 통과 시 동작: 0으로 변경
	}
	else if (bStencil == STENCIL_CLEAR)   //clear
	{
		glStencilFunc(GL_NEVER, 1, 1); // 항상 실패, 기준값 1, 마스크값은 0x01
		glStencilOp(GL_INCR, GL_INCR, GL_INCR); // 스텐실 테스트 실패 시 동작: 값 증가, 스텐실 테스트는 통과했지만 깊이 테스트 실패 시 동작: 값 증가, 스텐실 테스트와 깊이 테스트 모두 통과 시 동작: 값 증가
	}
}

void CSimpleOpengl::StencilBitRev(const vector <FPOINTC> &vecVertics, int nNumOfVertex)
{
	glStencilFunc(GL_NEVER, 0, 1); // 항상 실패, 기준값 0, 마스크값은 0x01
	glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT); // 스텐실 테스트 실패 시 동작: 비트 반전, 스텐실 테스트는 통과했지만 깊이 테스트 실패 시 동작: 비트 반전, 스텐실 테스트와 깊이 테스트 모두 통과 시 동작: 비트 반전
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < nNumOfVertex; i++)
	{
		float X1 = vecVertics.at(i).x; float Y1 = vecVertics.at(i).y;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(vecVertics.at(i).x, vecVertics.at(i).y);
	}
	glEnd();
}

void CSimpleOpengl::StencilReverse(const vector <FPOINTC> &vecVertics, int nNumOfVertex)
{
	glStencilFunc(GL_EQUAL, 1, 1); // 스텐실 값이 기준 값과 같을 때 통과, 기준값 1, 마스크값은 0x01
	glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO); // 스텐실 테스트 실패 시 동작: 0으로 변경, 스텐실 테스트는 통과했지만 깊이 테스트 실패 시 동작: 0으로 변경, 스텐실 테스트와 깊이 테스트 모두 통과 시 동작: 0으로 변경
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < nNumOfVertex; i++)
	{
		float X1 = vecVertics.at(i).x; float Y1 = vecVertics.at(i).y;
		AdjustToScreen(X1, Y1);
		glVertex2f(X1, Y1);
		//glVertex2f(vecVertics.at(i).x, vecVertics.at(i).y);
	}
	glEnd();
}

void CSimpleOpengl::StencilClear(BOOL bStencil)
{
	if (bStencil == STENCIL_DARK)
	{
		glClear(GL_STENCIL_BUFFER_BIT);
	}
}

void CSimpleOpengl::StencilEnd()
{
	glDisable(GL_STENCIL_TEST);
}

void CSimpleOpengl::MyCallApertureList(float fx, float fy, int nListNum)
{
	glPushMatrix();
	glTranslatef(fx, fy, 0);
	glCallList(nListNum);
	if (!glIsList(nListNum))
		AfxMessageBox(_T("list error"));
	glPopMatrix();

}

int CSimpleOpengl::GetArcSegment(float fRadius, float fAngle)
{
	if (fAngle < 0)
		fAngle = -fAngle;

	double fOptSeg = 100 * sqrt(fRadius);
	fOptSeg *= (fAngle / 360.0);

	double fResSeg = (2.0*PI*fRadius) / m_fDrawResolution;
	fResSeg *= (fAngle / 360.0);

	double fMinSeg = max(2.0, fAngle / 60.0);
	double fSeg = max(fMinSeg, min(fOptSeg, fResSeg));
	int nSeg = ceil(fSeg);

	return nSeg;
}

void CSimpleOpengl::DrawCircle(GLfloat cx, GLfloat cy, GLfloat r, int fill)
{
	int ii;
	int num_segments = GetArcSegment(r);

	GLfloat circle_length = (2.0 * PI * r);


	GLfloat theta = 2.0 * PI / GLfloat(num_segments); //theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	GLfloat tangetial_factor = tanf(theta);
	GLfloat radial_factor = cosf(theta);
	GLfloat x = r;
	GLfloat y = 0;
	GLfloat tx, ty;

	//if (fill)
	//	glBegin(GL_POLYGON); // filled circle
	//else
	//	glBegin(GL_LINE_LOOP);// hollow circle since the circle is a closed curve, this is a loop now

	for (ii = 0; ii < num_segments; ii++)
	{
		float X1 = x + cx; float Y1 = y + cy;
		AdjustToScreen(X1, Y1);
		glVertex3f(X1, Y1, 0.0f);
		//glVertex3f(x + cx, y + cy, 0.0f);

		tx = -y;
		ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	//glEnd();
}

FRECTC CSimpleOpengl::GetLayerMaxExtent()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	FRECTC fRect;
	fRect.X1 = 0.0; fRect.Y1 = 0.0; fRect.X2 = 0.0; fRect.Y2 = 0.0;
	if (pParent)
		fRect = pParent->GetLayerMaxExtent();
	return fRect;
}

double  CSimpleOpengl::GetScaleOfScreen()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	double dScale = 1.0;
	if (pParent)
		dScale = pParent->GetScaleOfScreen();
	return dScale;
}

void CSimpleOpengl::AdjustToScreen(float& X1, float& Y1)
{
	FRECTC rtFrame = GetLayerMaxExtent();
	double dScale = GetScaleOfScreen();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / dScale; fptOrigin.y = 10.0 / dScale; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= dScale; Y1 *= dScale;
	// if (X1 < 0.0 || X1 > m_nWorldW)
	if (X1 + 1.0 < fptOrigin.x * dScale || X1 - 1.0 > (rtFrame.X2 + fptOriginOffset.x) * dScale)
	{
		int kkk = 0;
		return;
	}
}

void CSimpleOpengl::AdjustToScreen(float& X1, float& Y1, float& X2, float& Y2)
{
	FRECTC rtFrame = GetLayerMaxExtent();
	double dScale = GetScaleOfScreen();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / dScale; fptOrigin.y = 10.0 / dScale; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= dScale; Y1 *= dScale;
	X2 += fptOriginOffset.x; Y2 += fptOriginOffset.y;
	X2 *= dScale; Y2 *= dScale;
	if (X1 < 0.0 || X1 > m_nWorldW)
	{
		int kkk = 0;
		return;
	}
}

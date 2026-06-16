
// MyGerberDlg.h : 헤더 파일
//

#pragma once
//#include "CamMaster.h"

#include "SimpleOpengl.h"
#include "Simple274X.h"


// CMyGerberDlg 대화 상자
class CMyGerberDlg : public CDialog
{
	CDC* m_pDc;
	BOOL FileBrowse(CString& sPath);
	void LoadGerbFile(CString sPath);
	void DispGerbFile();

	CSimpleOpengl* m_pOpengl;
	BOOL InitOpengl();

	CSimple274X *m_p274X;
	BOOL Init274X();


	CCriticalSection m_cs;
	//CCamMaster *m_pCamMaster;
	//BOOL InitCamMaster();
	//BOOL InitGLViewer();

// 생성입니다.
public:
	CMyGerberDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	~CMyGerberDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYGERBER_DIALOG };
#endif

public:
	//COpenGLView *m_pOpenGLView;
	//COpenGLDraw *m_pOpenGLDraw;

	LPLAYER_INFORM_RS274X GetLayerInfo();
	void SetDrawResolution(float fResolution);
	void SetForeColor(COLORREF crColor);
	void Draw274X();
	void DrawBegin(int nMode, int nSize, COLORREF color);
	void DrawEnd();
	void DrawDisp();
	void DrawConvexPolygon(const vector <FPOINTC> &fPoint);
	void DrawConvexPolygon(const FPOINTC *fPoint, int nNumberOfVertex);
	void DrawPolygonLine(const vector <FPOINTC> &vecPt, int nLineWidth = 0);
	void DrawLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight);
	void DrawConcavePolygon(const vector <FPOINTC> &fPoint);
	void DrawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, int fill = TRUE);
	void DrawRect(const CfPoint3D &fptStart, const CfPoint3D &fptEnd, int width = 0, int fill = TRUE);
	void DrawDonut(float fCx, float fCy, float fDmo, float fDmi);
	void DrawCircle(GLfloat cx, GLfloat cy, GLfloat r, int fill = TRUE);
	void StencilBegin();
	void StencilSet(BOOL bStencil);
	void StencilClear(BOOL bStencil);
	void StencilBitRev(const vector <FPOINTC> &vecVertics, int nNumOfVertex);
	void StencilReverse(const vector <FPOINTC> &vecVertics, int nNumOfVertex);
	void StencilEnd();
	void MyLineList(float X1, float Y1, float X2, float Y2, int nListNum);
	void MyCallApertureList(float fx, float fy, int nListNum);

	FRECTC GetLayerMaxExtent();
	double GetScaleOfScreen();
	COLORREF GetObjectColorCurrent();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg LRESULT  OnGlRedrawCam(WPARAM wPara, LPARAM lPara);
	afx_msg void OnBnClickedBtnOpenGerb();
};

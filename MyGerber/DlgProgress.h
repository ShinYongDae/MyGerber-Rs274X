#pragma once
#include <thread>
#include "afxcmn.h"

#define MAX_RANGE_PROGRESS		32767

#define WM_PROC_FUNC		(WM_USER+10)

// CDlgProgress 대화 상자입니다.

class CDlgProgress : public CDialog
{
	DECLARE_DYNAMIC(CDlgProgress)

	CWnd* m_pParent;
	CString m_sCaption;
	int m_nLower;	// 하한
	int m_nUpper;	// 상한
	int m_nStep;	// 단계
	int m_nPos;		// 현재 진행량.
	int m_nPosPrev;	// 이전 진행량.
	double m_dDevide;

	BOOL UpdatePercent(int nNewPos);

private:
	BOOL m_bThreadAlive;// , m_bThreadStateEnd;
	std::thread t0;
	BOOL m_bProc, m_bProcFunc;
	void ThreadStart();

protected:
	BOOL Proc();
	BOOL ThreadIsStop();

public:
	static void ProcThrd(const LPVOID lpContext);
	afx_msg LRESULT ProcFunc(WPARAM wPara, LPARAM lPara);
	void ThreadActivate(BOOL bRun);
	BOOL ThreadIsActivate();
	BOOL ThreadIsAlive();
	void ThreadStop();

public:
	CDlgProgress(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgProgress();

public:
	BOOL Create(CString sCaption = _T("On working"));
	void SetCaption(CString sCaption);
	int SetStep(int nStep);
	void SetRange(int nLower, int nUpper);
	void SetPos();
	void SetPos(int nPos);
	int GetPos();

// 대화 상자 데이터입니다.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PROGRESS };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_ctrlProgress;
	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

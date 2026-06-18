// DlgProgress.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyGerber.h"
#include "DlgProgress.h"
#include "afxdialogex.h"


// CDlgProgress 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgProgress, CDialog)

CDlgProgress::CDlgProgress(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_PROGRESS, pParent)
{
	m_pParent = pParent;
	m_bProc = FALSE;
	m_bProcFunc = FALSE;

	m_sCaption = _T("");
	m_nLower = 0;
	m_nUpper = 100;
	m_dDevide = 1.0;
	m_nStep = 1;
	m_nPos = 0; m_nPosPrev = 0;

	m_bDlgProgress = FALSE;
}

CDlgProgress::~CDlgProgress()
{
	ThreadStop();
	while (m_bProc)
	{
		Sleep(30);
	}
	t0.join();
	m_bDlgProgress = FALSE;
}

void CDlgProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PROGRESS, m_ctrlProgress);
}


BEGIN_MESSAGE_MAP(CDlgProgress, CDialog)
	ON_WM_SHOWWINDOW()
	ON_MESSAGE(WM_PROC_FUNC, &CDlgProgress::ProcFunc)
END_MESSAGE_MAP()


// CDlgProgress 메시지 처리기입니다.

void CDlgProgress::ThreadActivate(BOOL bRun)
{
	m_bProcFunc = bRun;
}

BOOL CDlgProgress::ThreadIsActivate()
{
	return m_bProcFunc;
}

BOOL CDlgProgress::ThreadIsAlive()
{
	return m_bProc;
}

BOOL CDlgProgress::ThreadIsStop()
{
	return !m_bThreadAlive;
}

void CDlgProgress::ProcThrd(const LPVOID lpContext)
{
	CDlgProgress* pDlgProgress = reinterpret_cast<CDlgProgress*>(lpContext);

	pDlgProgress->m_bProc = TRUE;
	while (!pDlgProgress->ThreadIsStop())
	{
		if (!pDlgProgress->Proc())
			break;
		Sleep(30);
	}
	pDlgProgress->m_bProc = FALSE;
}

LRESULT CDlgProgress::ProcFunc(WPARAM wPara, LPARAM lPara)
{
	if (!m_bProcFunc)	return 0L;

	if (m_nPos != m_nPosPrev)
	{
		SetPos();
		UpdatePercent(m_nPos);
	}

	return 0L;
}

BOOL CDlgProgress::Proc()
{
	if (m_bProc)
	{
		if (m_bProcFunc)
			::PostMessage(m_hWnd, WM_PROC_FUNC, 0, 0); //ProcFunc(0, 0);
	}
	
	Sleep(30);
	return TRUE;
}

void CDlgProgress::ThreadStart()
{
	m_bThreadAlive = TRUE;
	t0 = std::thread(ProcThrd, this);
}

void CDlgProgress::ThreadStop()
{	
	m_bThreadAlive = FALSE;
	MSG message;
	const DWORD dwTimeOut = 1000 * 60 * 3; // 3 Minute
	DWORD dwStartTick = GetTickCount();
	Sleep(30);
}

BOOL CDlgProgress::Create(CString sCaption)
{
	m_sCaption = sCaption;

	BOOL bRtn = TRUE;
	if (!m_bDlgProgress)
		bRtn = CDialog::Create(CDlgProgress::IDD, m_pParent);
	//BOOL bRtn = CDialog::Create(_T("1"), m_pParent);
	if (!bRtn)
	{
		AfxMessageBox(_T("Faile to Create DlgProgress."));
	}
	return bRtn;
}


BOOL CDlgProgress::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetCaption(m_sCaption);
	//m_ctrlProgress.SetRange(m_nLower, m_nUpper);
	//m_ctrlProgress.SetStep(m_nStep);
	//m_ctrlProgress.SetPos(m_nLower);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgProgress::SetCaption(CString sCaption)
{
	m_sCaption = sCaption;
	SetWindowText(sCaption);
}

void CDlgProgress::SetPos(int nPos)
{
	m_nPos = nPos;
}

void CDlgProgress::SetPos()
{
	//if (m_nPos != nPos)
	//{
	//	m_nPos = nPos;
	//	m_bProcFunc = TRUE;
	//}
	CProgressCtrl* pWndProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS);
	int nPos = m_nPos;

	if (m_nPos != m_nPosPrev)
	{
		m_nPosPrev = m_nPos;
		nPos /= m_dDevide;
		int iResult = pWndProgress->SetPos(nPos);
		//int iResult = m_ctrlProgress.SetPos(nPos);
		UpdatePercent(m_nPos);
		//if (!UpdatePercent(m_nPos))
		//	OnOK();
	}
}

int CDlgProgress::GetPos()
{
	return m_nPos;
}

void CDlgProgress::SetRange(int nLower, int nUpper)
{
	CProgressCtrl* pWndProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS);
	m_nLower = nLower;
	m_nUpper = nUpper;
	if (nUpper > MAX_RANGE_PROGRESS)
	{
		m_dDevide = (double)nUpper / (double)MAX_RANGE_PROGRESS;
		nUpper = MAX_RANGE_PROGRESS;
	}
	else
	{
		m_dDevide = 1.0;
	}
	pWndProgress->SetRange(nLower, nUpper);
	//m_ctrlProgress.SetRange(nLower, nUpper);

	if (!m_bDlgProgress)
	{
		m_bDlgProgress = TRUE;
		ThreadStart();
	}
}

int CDlgProgress::SetStep(int nStep)
{
	CProgressCtrl* pWndProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS);
	m_nStep = nStep; // Store for later use in calculating percentage
	nStep /= m_dDevide;
	return pWndProgress->SetStep(nStep);
	//return m_ctrlProgress.SetStep(nStep);
}

BOOL CDlgProgress::UpdatePercent(int nNewPos)
{
	CWnd *pWndPercent = GetDlgItem(IDC_STATUS);
	int nPercent;

	int nDivisor = m_nUpper - m_nLower;
	ASSERT(nDivisor > 0);  // m_nLower should be smaller than m_nUpper

	int nDividend = (nNewPos - m_nLower);
	ASSERT(nDividend >= 0);   // Current position should be greater than m_nLower

	nPercent = (int)(((double)nDividend / (double)nDivisor) * 100.0);

	// Since the Progress Control wraps, we will wrap the percentage
	// along with it. However, don't reset 100% back to 0%
	if (nPercent < 100)
		nPercent %= 100;
	else
		nPercent = 100;

	// Display the percentage
	CString strBuf;
	strBuf.Format(_T("%d%c"), nPercent, _T('%'));

	if (nPercent < 0)
	{
		int kkk = 0;
	}

	CString strCur; // get current percentage
	pWndPercent->GetWindowText(strCur);

	if (strCur != strBuf)
		pWndPercent->SetWindowText(strBuf);

	if (nPercent == 100)
		return FALSE;
	return TRUE;
}


void CDlgProgress::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (bShow)
	{
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);
		CRect* pRect = new CRect;
		this->GetWindowRect(pRect);
		int nWidth = pRect->Width();
		int nHeight = pRect->Height();
		pRect->top = (screenHeight - nHeight) / 2;
		pRect->bottom = pRect->top + nHeight;
		pRect->left = (screenWidth - nWidth) / 2;;
		pRect->right = pRect->left + nWidth;
		this->MoveWindow(pRect, TRUE);
		delete pRect;
	}
}

void CDlgProgress::Free()
{
	//CProgressCtrl* pWndProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS);
	//CStatic* pWndPercent = (CStatic*)GetDlgItem(IDC_STATUS);
	//pWndProgress->DestroyWindow();
	//pWndPercent->DestroyWindow();
	////delete pWndProgress;
	////delete pWndPercent;
}

void CDlgProgress::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;
	CDialog::PostNcDestroy();
}

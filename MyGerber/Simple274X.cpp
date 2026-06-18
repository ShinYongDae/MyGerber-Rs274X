// Simple274X.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyGerber.h"
#include "MyGerberDlg.h"
#include "Simple274X.h"

#include <algorithm>
#include <iterator>
#include <tchar.h>

#ifndef SQR
#define SQR(X) ((X)*(X))
#endif

// CfPoint3D Start
//CfPoint3D::CfPoint3D()
//{
//	/* random filled */
//}
//
//CfPoint3D::CfPoint3D(double initfX, double initfY, double initfZ)
//{
//	x = initfX;
//	y = initfY;
//	z = initfZ;
//}
//
//CfPoint3D::CfPoint3D(FPOINT3D initfPt)
//{
//	*(FPOINT3D*)this = initfPt;
//}
//
//CfPoint3D::~CfPoint3D()
//{
//
//}
//
//void CfPoint3D::Offset(double fXOffset, double fYOffset, double fZOffset)
//{
//	x += fXOffset;
//	y += fYOffset;
//	z += fZOffset;
//}
//
//void CfPoint3D::Offset(FPOINT3D fPoint)
//{
//	x += fPoint.x;
//	y += fPoint.y;
//	z += fPoint.z;
//}
//
//CfPoint3D CfPoint3D::Round(CfPoint3D fPoint, int nPos)
//{
//	CfPoint3D fTemp;
//	fTemp.x = fPoint.x * pow(10.0, nPos);
//	fTemp.x = floor(fTemp.x + 0.5);
//	fTemp.x *= pow(10.0, -nPos);
//
//	fTemp.y = fPoint.y * pow(10.0, nPos);
//	fTemp.y = floor(fTemp.y + 0.5);
//	fTemp.y *= pow(10.0, -nPos);
//
//	fTemp.z = fPoint.z * pow(10.0, nPos);
//	fTemp.z = floor(fTemp.z + 0.5);
//	fTemp.z *= pow(10.0, -nPos);
//
//
//	return fTemp;
//}
//
//BOOL CfPoint3D::operator ==(FPOINT3D fPoint)
//{
//	return (x == fPoint.x && y == fPoint.y && z == fPoint.z);
//}
//
//BOOL CfPoint3D::operator !=(FPOINT3D fPoint)
//{
//	return (x != fPoint.x || y != fPoint.y || z != fPoint.z);
//}
//
//void CfPoint3D::operator +=(FPOINT3D fPoint)
//{
//	x += fPoint.x; y += fPoint.y; z += fPoint.z;
//}
//
//void CfPoint3D::operator -=(FPOINT3D fPoint)
//{
//	x -= fPoint.x; y -= fPoint.y; z -= fPoint.z;
//}
//
//CfPoint3D CfPoint3D::operator +(FPOINT3D fPoint) const
//{
//	return CfPoint3D(x + fPoint.x, y + fPoint.y, z + fPoint.z);
//}
//
//CfPoint3D CfPoint3D::operator -(FPOINT3D fPoint) const
//{
//	return CfPoint3D(x - fPoint.x, y - fPoint.y, z - fPoint.z);
//}
//
//CfPoint3D::CfPoint3D(CfPoint3D& vt)
//{
//	x = vt.x;
//	y = vt.y;
//	z = vt.z;
//
//	//	r = vt.r;
//	//	g = vt.g;
//	//	b = vt.b;
//}
//
//CfPoint3D CfPoint3D::operator + (CfPoint3D& fPoint)
//{
//	CfPoint3D sum;
//	sum.x = x + fPoint.x;
//	sum.y = y + fPoint.y;
//	sum.z = z + fPoint.z;
//	return sum;
//}
//
//void CfPoint3D:: operator = (CfPoint3D& fPoint)
//{
//	x = fPoint.x;
//	y = fPoint.y;
//	z = fPoint.z;
//
//	// 
//	// 	r = fPoint.r;
//	// 	g = fPoint.g;
//	//	b = fPoint.b;
//}
//
//CfPoint3D CfPoint3D::operator - (CfPoint3D& fPoint)
//{
//	CfPoint3D sum;
//	sum.x = x - fPoint.x;
//	sum.y = y - fPoint.y;
//	sum.z = z - fPoint.z;
//	return sum;
//}
//
//CfPoint3D CfPoint3D::operator / (float div)
//{
//	CfPoint3D fDivison;
//
//	if (div == 0.0)
//	{
//		fDivison.x = 0.0;
//		fDivison.y = 0.0;
//		fDivison.z = 0.0;
//	}
//	else
//	{
//
//		fDivison.x = x / div;
//		fDivison.y = y / div;
//		fDivison.z = z / div;
//	}
//
//	return fDivison;
//}
//
//CfPoint3D CfPoint3D::operator *(CfPoint3D& fDivison)
//{
//	CfPoint3D fMultiPly;
//
//	fMultiPly.x = y*fDivison.z - z*fDivison.y;
//	fMultiPly.y = z*fDivison.x - x*fDivison.z;
//	fMultiPly.z = x*fDivison.y - y*fDivison.x;
//
//	return fMultiPly;
//}
//
//CfPoint3D CfPoint3D::operator * (double dDivison)
//{
//	CfPoint3D fMultiPly;
//
//	if (dDivison = 0.0)
//	{
//		fMultiPly.x = 0.0;
//		fMultiPly.y = 0.0;
//		fMultiPly.z = 0.0;
//	}
//	else
//	{
//		fMultiPly.x = x *dDivison;
//		fMultiPly.y = y *dDivison;
//		fMultiPly.z = z *dDivison;
//	}
//
//	return fMultiPly;
//}
//
//void CfPoint3D::Normalize()
//{
//	double mag = Magnitude();
//
//	if (mag != 0.)
//	{
//		x /= (float)mag;
//		y /= (float)mag;
//		z /= (float)mag;
//	}
//
//}
//
//double CfPoint3D::Magnitude()
//{
//	return sqrt(SQR(x) + SQR(y) + SQR(z));
//}
//
//// CfPoint3D END



// CSimple274X
#define EOB _T('*')

#define	ASCII_STX		(0x02)
#define	ASCII_ETX		(0x03)
#define	ASCII_ENQ		(0x05)
#define	ASCII_LF		(0x0a)
#define	ASCII_CR		(0x0d)
#define	ASCII_XON		(0x11)
#define	ASCII_XOFF		(0x13)
#define ASCII_SPACE		(0x20)

#define INCHTOMM	25.4


IMPLEMENT_DYNAMIC(CSimple274X, CWnd)

CSimple274X::CSimple274X(CWnd* pParent/*=NULL*/)
{
	m_pParent = pParent;
	m_hCtrl = NULL;
	m_bEnableDraw = FALSE;
	m_pLayerInfo = NULL;
	m_dScaleX = 1.0;
	m_dScaleY = 1.0;
	m_fDividerX = 1.0;
	m_fDividerY = 1.0;

	m_dDetZero = 0.000001;
	m_nMaxLineTemplate = 1000000;
	m_vecLineTemplate.reserve(m_nMaxLineTemplate);

	InitVal();
	SetActionCode(0);

	// Draw274X
	m_dPixelResolution = 10.0;
	m_nListLines = 0;

}

CSimple274X::~CSimple274X()
{
	m_bEnableDraw = FALSE;

	DeleteLayerInfo();

	int nSizeLayerInform = m_ArLayerInform.GetSize();
	if (nSizeLayerInform > 0)
		m_ArLayerInform.RemoveAll();
	int nSizeLayerStruct = m_ArLayerStruct.GetSize();
	if (nSizeLayerStruct > 0)
		m_ArLayerStruct.RemoveAll();
	int nSizeLineTemplate = m_vecLineTemplate.size();
	if (nSizeLineTemplate > 0)
		m_vecLineTemplate.clear();
}


BEGIN_MESSAGE_MAP(CSimple274X, CWnd)
END_MESSAGE_MAP()



// CSimple274X 메시지 처리기입니다.
void CSimple274X::InitVal()
{
	float fMaxData = pow(2.0, 31.0);
	m_MaxFrameExtent.X1 = fMaxData;
	m_MaxFrameExtent.X2 = -fMaxData;
	m_MaxFrameExtent.Y1 = fMaxData;
	m_MaxFrameExtent.Y2 = -fMaxData;

	m_nNumOfSnRObject = 0;
	m_nNumOfLineObject = 0;
	m_nNumOfLineTemplate = 0;

	// <Drawing>
	m_crObjColor = RGB_GREEN;
	m_bDisplayBackgroundImg = TRUE;
	m_bCheckDraw = FALSE;
	m_fExtentStartPos = CfPoint3D(0, 0, 0);
	m_fExtentEndPos = CfPoint3D(0, 0, 0);
}

void CSimple274X::SetActionCode(int nActionCode)
{
	//////////////////////
	// nActionCode
	// 0: None
	// 1: L-R Mirror	
	// 2: T-B Mirror	
	// 3: CCW 180 Rotate
	// 4: CCW 90, CW 270 Rotate
	// 5: CCW 270, CW 90 Rotate

	m_nActionCode = nActionCode;
	switch (nActionCode)
	{
	case 3:	// CCW180
		m_fCosine = -1.0;
		m_fSine = 0.0;
		break;
	case 4: //'CCW 90
	case 14:
	case 24:
	case 41:
	case 42:
		m_fCosine = 0.0;
		m_fSine = 1.0;
		break;
	case 5: // 'CCW270 or CW 90
	case 15:
	case 25:
	case 51:
	case 52:
		m_fCosine = 0.0;
		m_fSine = -1.0;
		break;
	default: // 'CW 0
		m_fCosine = 1.0;
		m_fSine = 0.0;
		break;
	}
}

LPLAYER_INFORM_RS274X CSimple274X::GetLayerInfo()
{
	return m_pLayerInfo;
}

void CSimple274X::DeleteLayerInfo()
{
	//if (m_pLayerInfo)
	//{
	//	delete m_pLayerInfo;
	//	m_pLayerInfo = NULL;
	//}
	int i, k, nKey;
	LPLAYER_INFORM_RS274X pLayerInfo;
	LPAPERTURE_DEF pAptDef;

	POSITION pos = NULL;

	int nLayerSize = m_ArLayerInform.GetSize();
	for (i = 0; i < nLayerSize; i++)
	{
		pLayerInfo = m_ArLayerInform.GetAt(i);
		if (pLayerInfo != NULL)
		{
			if (pLayerInfo->vecObjCoord.size() > 0)
				pLayerInfo->vecObjCoord.clear();
			if (pLayerInfo->listObj.size() > 0)
				pLayerInfo->listObj.clear();

			int nNumOfAperture = pLayerInfo->mapAptList.GetCount();
			if (nNumOfAperture > 0)
			{
				pos = pLayerInfo->mapAptList.GetStartPosition();
				while (pos != NULL)
				{
					pLayerInfo->mapAptList.GetNextAssoc(pos, nKey, pAptDef);
					if (pAptDef != NULL)
					{
						int nNumOfParam = pAptDef->Param.size();
						for (k = 0; k < nNumOfParam; k++)
							pAptDef->Param.at(k).fParam.clear();
						pAptDef->Param.clear();
						delete pAptDef;
						pAptDef = NULL;
					}
				}
				pLayerInfo->mapAptList.RemoveAll();
			}

			int nNumOfObjColor = pLayerInfo->mapObjColor.GetCount();
			if (nNumOfObjColor > 0)
				pLayerInfo->mapObjColor.RemoveAll();

			delete pLayerInfo;
		}
	}
}

void CSimple274X::StringToChar(CString str, char* szStr)  // char* returned must be deleted... 
{
	int nLen = str.GetLength();
	strcpy(szStr, CT2A(str));
	szStr[nLen] = _T('\0');
}

CString CSimple274X::CharToString(const char *szStr)
{
	CString strRet;

	int nLen = strlen(szStr) + sizeof(char);
	wchar_t *tszTemp = NULL;
	tszTemp = new WCHAR[nLen];

	MultiByteToWideChar(CP_ACP, 0, szStr, -1, tszTemp, nLen * sizeof(WCHAR));

	strRet.Format(_T("%s"), (CString)tszTemp);
	if (tszTemp)
	{
		delete[] tszTemp;
		tszTemp = NULL;
	}
	return strRet;
}
BOOL CSimple274X::LoadGerbFile(CString sPath)
{
	if (sPath.IsEmpty())
		return FALSE;

	CFileFind ff;
	if (!ff.FindFile(sPath))
	{
		AfxMessageBox(_T("Not exist Gerber File."));
		return FALSE;
	}

	CString sFileData = Load(sPath);
	if (sFileData.IsEmpty())
	{
		AfxMessageBox(_T("Failed Load File."));
		return FALSE;
	}

	if (!Decode(sFileData))
		return FALSE;

	// AllocateGLList();
	// SetCoordinate(CfSize(FrameExtent.X2-FrameExtent.X1,FrameExtent.Y2-FrameExtent.Y1),CfPoint(FrameExtent.X1,FrameExtent.Y1),CfPoint(InspectionRegion.X1,InspectionRegion.Y2));

	return TRUE;
}

void CSimple274X::DrawGerbFile()
{
	DecodeDraw();
}

CString CSimple274X::Load(CString sPath)
{
	char FileD[MAX_PATH];
	char *FileData;
	CString DsipMsg = _T(""), sData = _T("");
	int nFileSize, nRSize, i;	//, nSizeTemp	
	FILE *fp;

	m_sPathFile = _T("");

	CString sFile = _T(""), sTempPath = sPath;
	int nPos = sTempPath.ReverseFind('\\');
	if (nPos != -1)
	{
		sFile = sTempPath.Right(sTempPath.GetLength() - nPos - 1);
		sTempPath.Delete(nPos, sPath.GetLength() - nPos);
	}

	double dRatio = 0.0;
	CString sVal;
	// 	CDlgProgress dlg;
	// 	sVal.Format("On loading [%s]", sFile);
	// 	dlg.Create(sVal);

	//파일을 불러옴. 
	int nLen = sPath.GetLength();
	char* pData = new char[nLen + 1]; // for '\0'
	StringToChar(sPath, pData);
	strcpy(FileD, pData);
	delete pData;

	if ((fp = fopen(FileD, "r")) != NULL)
	{
		fseek(fp, 0, SEEK_END);
		nFileSize = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		// Allocate space for a path name
		FileData = (char*)calloc(nFileSize + 1, sizeof(char));
		nRSize = fread(FileData, sizeof(char), nFileSize, fp);

		//nRSize = 0;
		//for (i = 0; i < nFileSize; i++)
		//{
		//	if (feof(fp) != 0)
		//		break;
		//	FileData[i] = fgetc(fp);
		//	if (FileData[i] == '\n')
		//	{
		//		if (FileData[i - 1] != '\r')
		//		{
		//			nFileSize++;
		//			FileData = (char*)realloc(FileData, nFileSize);
		//			FileData[i] = '\r';
		//			i++;
		//			nRSize++;
		//			FileData[i] = '\n';
		//		}
		//	}
		//	nRSize++;
		//}
		//sData.Format(_T("%s"), FileData);

		fclose(fp);
		sData = CharToString(FileData);

		free(FileData);
	}
	else
	{
		DsipMsg.Format(_T("파일이 존재하지 않습니다.\r\n%s"), sPath);
		AfxMessageBox(DsipMsg);
	}

	// 	dlg.DestroyWindow();

	m_sPathFile = sPath;

	return sData;
}

void CSimple274X::DecodeDraw()
{
	int nLayer;

	m_nNumOfLayer = m_ArLayerInform.GetSize();

	////////////////////////////////////////////////////////////////////////
	FRECTC fRect = GetLayerExtent(0);
	for (nLayer = 1; nLayer < GetNumOfLayer(); nLayer++)
	{
		FRECTC rect = GetLayerExtent(nLayer);
		AdjustExtentByRect(fRect, rect);
	}
	SetFrameExtent(fRect);
	SetDrawArcResolution(0.005);

	AllocDrawList();

	m_bEnableDraw = TRUE;
}

BOOL CSimple274X::Decode(CString sFileData)
{
	int nLen = sFileData.GetLength();
	char* pData = new char[nLen + 1]; // for '\0'
	StringToChar(sFileData, pData);
	//delete pData;

	CString strErrMsg;
	char* pLine = pData;
	int nIdx = 0;

	m_bEnableDraw = FALSE;

	//DeleteLayerInfo();
	m_pLayerInfo = new LAYER_INFORM_RS274X;
	m_nLayer = 0;
	// 	m_nNumOfObject = m_ArLayerStruct.GetAt(m_nLayer).nObject;
	//	m_nNumOfCoord = m_ArLayerStruct.GetAt(m_nLayer).nCoord;
	//	m_pLayerInfo->listObj.reserve(m_nNumOfObject+1); // n*36byte
	m_pLayerInfo->nFormat = CAM_DATA::RS274X;
	m_pLayerInfo->strFilePath = m_sPathFile;


	m_nNumOfDataBlock = 0;
	m_nNumOfTextLine = 1;
	m_nNumOfObjCoord = 0;
	m_nStartMirrorObj = 0;
	m_nEndMirrorObj = 0;

	m_fptPrevPos.x = 0;
	m_fptPrevPos.y = 0;

	m_vecTemp.reserve(m_nMaxLineTemplate);

	m_bParsingXYFlag = FALSE;
	m_bParsingIJFlag = FALSE;
	m_bParsingGCodeFlag = FALSE;
	m_bParsingdCodeFlag = FALSE;
	m_bPolygonFlag = FALSE;
	m_bImplicitFlag = FALSE;

	m_nObj = 0;
	m_nPrevDCode = -1;

	m_fCanvasPixelResolution = 1.0;
	m_fDrawResolution = 1.0;
	m_nIRAngle = 0; // Image Rotation angle

	m_bLastFrame = FALSE;

	ResetData();
	ResetDataObject(m_gObj);

	Decoding(pData, pLine); // Load Gerber File and upload at m_gObj...


	m_bParsingXYFlag = FALSE;
	m_bParsingIJFlag = FALSE;
	m_bParsingGCodeFlag = FALSE;
	m_bParsingdCodeFlag = FALSE;

	// Add Dummy Object
	m_gObj.Type.nType = DRAW_TYPE::FLASH;
	m_gObj.Type.nAttr = DRAW_TYPE::NONE;
	m_gObj.nStPnt = m_nNumOfObjCoord;

	m_pLayerInfo->listObj.push_back(m_gObj);


	m_nNumOfLineTemplate = m_vecLineTemplate.size();
	if (m_nNumOfLineTemplate > 0)
	{
		sort(m_vecLineTemplate.begin(), m_vecLineTemplate.end());
		m_vecTemp.clear();
		std::unique_copy(m_vecLineTemplate.begin(), m_vecLineTemplate.end(), std::back_inserter(m_vecTemp));
		(m_vecLineTemplate).swap(m_vecTemp);
		//i = m_vecLineTemplate.size();
		//i = m_vecLineTemplate.capacity();
		m_nNumOfLineTemplate = m_vecLineTemplate.size();

	}
	m_vecTemp.clear();
	vector <UINT64>(m_vecTemp.begin(), m_vecTemp.end()).swap(m_vecTemp);

	m_mapAMMacro.RemoveAll();


	m_pLayerInfo->Extent = GetLayerMaxExtent();//rectBound;
	m_pLayerInfo->bUnit = m_Unit;
	m_pLayerInfo->nLayerGroupID = m_nLayerGroupID;

	if (m_nIRAngle != 0)
	{
		double cX, cY;

		cX = (m_pLayerInfo->Extent.X1 + m_pLayerInfo->Extent.X2) / 2.0;
		cY = (m_pLayerInfo->Extent.X1 + m_pLayerInfo->Extent.X2) / 2.0;

		ApplyIROptionGRB(m_pLayerInfo, 0, 0, -m_nIRAngle);
	}

	m_ArLayerInform.Add(m_pLayerInfo);

	delete pData;
	return TRUE;
}

BOOL CSimple274X::Decoding(char* pFile, char* pLine)
{
	int nLen = 0, nLenFirst = 0;
	CString strErrMsg;

	DWORD CurTimer, StartTimer;
	StartTimer = GetTickCount();

	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	MSG message;
	if (pParent)
	{
		nLenFirst = strlen(pFile);
		pParent->ProgressSetDlgCaption(_T("On Loading Gerber File..."));
		pParent->ProgressSet(0, 0, nLenFirst);
	}

	while (!m_bLastFrame)
	{
		CurTimer = GetTickCount();
		BOOL bTrig = !(int(CurTimer - StartTimer) % 100); // 100mSec간격으로 ProgressBar 진행.
		if (bTrig)
		{
			nLen = strlen(pFile);
			if (pParent)
			{
				pParent->ProgressSet(nLenFirst - nLen);
				if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
				{
					::TranslateMessage(&message);
					::DispatchMessage(&message);
				}
			}
		}

		DecodingParsingFlag();

		if (DecodingIgnore(&pFile, &pLine))
			continue;
		if (DecodingCoordinate(&pFile))
			continue;
		if (DecodingFunction(&pFile))
			continue;
		if (DecodingParameter(&pFile))
			continue;

		strErrMsg.Format(_T("RS274X parameter block parsing error: syntax error"));
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
	}

	if (pParent)
	{
		pParent->ProgressSet(nLenFirst);
		pParent->ProgressActivate(FALSE);//pParent->ProgressClose();
	}

	return TRUE;
}

void CSimple274X::DecodingParsingFlag()
{
	DRAW_TYPE::TYPE dType;
	TEMPLATE_KEY Key;
	float dX, dY;
	float fWidthOfLine;
	LINE_INFO sttLineInfo;


	if (!m_bParsingXYFlag && !m_bParsingIJFlag && !m_bPolygonFlag)
		return;

	if (m_bPolygonFlag)
	{
		if (m_gObj.nStPnt == m_nNumOfObjCoord)
		{
			m_nPrevDCode = m_nDCode;
			if (m_nDCode != 2)
			{
				m_pLayerInfo->vecObjCoord.push_back(m_fptPrevPos);
				m_nNumOfObjCoord++;
			}
		}

		if (m_bParsingIJFlag)
		{
			FPOINTC fpt;
			if (m_nGCode == 2)
			{
				fpt.x = DetGcode;
				fpt.y = DetGcode;
				dType = DRAW_TYPE::ARC_CW;
			}
			else
			{
				fpt.x = -DetGcode;
				fpt.y = -DetGcode;
				dType = DRAW_TYPE::ARC_CCW;
			}
			m_pLayerInfo->vecObjCoord.push_back(fpt);
			m_nNumOfObjCoord++;
			m_pLayerInfo->vecObjCoord.push_back(m_fptCoord);

			m_nNumOfObjCoord++;
			m_pLayerInfo->vecObjCoord.push_back(m_fptOpt);
			m_nNumOfObjCoord++;

			fpt.x = m_fptPrevPos.x + m_fptOpt.x;
			fpt.y = m_fptPrevPos.y + m_fptOpt.y;

			FRECTC MnMxTemp = MinMaxArcInPolygonGRB(dType, m_fptPrevPos, m_fptCoord, fpt);
			AdjustExtentByRect(m_gObj.Extent, MnMxTemp);
			SetLayerMaxExtent(m_gObj.Extent);

		}
		else
		{
			AdjustExtentByPoint(m_gObj.Extent, m_fptCoord);
			SetLayerMaxExtent(m_gObj.Extent);
			m_pLayerInfo->vecObjCoord.push_back(m_fptCoord);
			m_nNumOfObjCoord++;
		}
	}
	else
	{
		if (m_bParsingdCodeFlag)
		{
			if (!(m_nDCode == m_nPrevDCode && m_nADCode == m_nPrevADCode && m_fptCoord.x == m_fptPrevPos.x && m_fptCoord.y == m_fptPrevPos.y))
			{
				m_nPrevADCode = m_nADCode;
				switch (m_nDCode)//   'Draw Mode
				{
				case 1:
					m_pLayerInfo->vecObjCoord.push_back(m_fptCoord);

					m_nNumOfObjCoord++;
					m_pLayerInfo->vecObjCoord.push_back(m_fptPrevPos);

					m_nNumOfObjCoord++;
					m_gObj.dCode = m_nADCode;

					if (m_bParsingGCodeFlag)
					{
						if (m_nGCode > 2)
							m_gObj.Type.nType = DRAW_TYPE::ARC_CCW;
						else
							m_gObj.Type.nType = DRAW_TYPE::ARC_CW;

						m_fptOpt.x += m_fptPrevPos.x;
						m_fptOpt.y += m_fptPrevPos.y;
						m_pLayerInfo->vecObjCoord.push_back(m_fptOpt);
						m_nNumOfObjCoord++;
						m_gObj.Extent = MinMaxArcGRB((DRAW_TYPE::TYPE)m_gObj.Type.nType, m_fptPrevPos, m_fptCoord, m_fptOpt, m_CurMinMax);
					}
					else
					{
						if (m_bParsingIJFlag)
						{
							if (m_nGCode > 2)
								m_gObj.Type.nType = DRAW_TYPE::ARC_CCW;
							else
								m_gObj.Type.nType = DRAW_TYPE::ARC_CW;

							m_fptOpt.x += m_fptPrevPos.x;
							m_fptOpt.y += m_fptPrevPos.y;

							m_pLayerInfo->vecObjCoord.push_back(m_fptOpt);
							m_nNumOfObjCoord++;
							m_gObj.Extent = MinMaxArcGRB((DRAW_TYPE::TYPE)m_gObj.Type.nType, m_fptPrevPos, m_fptCoord, m_fptOpt, m_CurMinMax);

						}
						else
						{
							// Linear interpolation
							if (m_fptCoord.x == m_fptPrevPos.x && m_fptCoord.y == m_fptPrevPos.y) //   ' Flash로 변환
								m_gObj.Type.nType = DRAW_TYPE::FLASH;
							else
							{
								m_gObj.Type.nType = DRAW_TYPE::LINE;

								m_pLayerInfo->mapAptList.Lookup(m_gObj.dCode, m_rAptDef);
								if (m_rAptDef->chStdAptType == _T('C'))
								{
									m_nNumOfLineObject++; // count up line object
									m_nNumOfLineTemplate = m_vecLineTemplate.size();
									if (m_nNumOfLineTemplate > m_nMaxLineTemplate - 2)
									{
										sort(m_vecLineTemplate.begin(), m_vecLineTemplate.end());
										m_vecTemp.clear();
										std::unique_copy(m_vecLineTemplate.begin(), m_vecLineTemplate.end(), std::back_inserter(m_vecTemp));
										(m_vecLineTemplate).swap(m_vecTemp);
									}

									dX = (m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt + 1).x - m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt).x);
									dY = (m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt + 1).y - m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt).y);

									Key.Param[0] = (dX*dX + dY*dY); // length
									Key.Param[1] = m_rAptDef->Param.at(0).fParam.at(0); // line width

									m_vecLineTemplate.push_back(Key.key);

									fWidthOfLine = m_rAptDef->Param.at(0).fParam.at(0);
									if (m_mapLineInfo.Lookup(fWidthOfLine, sttLineInfo))
									{
										sttLineInfo.nNumOfLine++;
									}
									else
									{
										sttLineInfo.nNumOfLine = 1;
									}
									m_mapLineInfo.SetAt(fWidthOfLine, sttLineInfo);
								}
							}

							if (m_fptCoord.x < m_fptPrevPos.x)
							{
								m_gObj.Extent.X1 = m_fptCoord.x + m_CurMinMax.X1;
								m_gObj.Extent.X2 = m_fptPrevPos.x + m_CurMinMax.X2;
							}
							else
							{
								m_gObj.Extent.X1 = m_fptPrevPos.x + m_CurMinMax.X1;
								m_gObj.Extent.X2 = m_fptCoord.x + m_CurMinMax.X2;
							}
							if (m_fptCoord.y < m_fptPrevPos.y)
							{
								m_gObj.Extent.Y1 = m_fptCoord.y + m_CurMinMax.Y1;
								m_gObj.Extent.Y2 = m_fptPrevPos.y + m_CurMinMax.Y2;
							}
							else
							{
								m_gObj.Extent.Y1 = m_fptPrevPos.y + m_CurMinMax.Y1;
								m_gObj.Extent.Y2 = m_fptCoord.y + m_CurMinMax.Y2;
							}
						}
					}
					SetLayerMaxExtent(m_gObj.Extent);
					if (m_paramIP.bLayerPolarity == LAYER_TYPE::NEGATIVE)
						m_gObj.Type.nPolarity = DRAW_TYPE::NEGATIVE;
					else
						m_gObj.Type.nPolarity = DRAW_TYPE::POSITIVE;

					m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;


					m_pLayerInfo->listObj.push_back(m_gObj);
					ClearDataObject(m_gObj);
					m_gObj.nStPnt = m_nNumOfObjCoord;

					m_nObj++;

					//					fptPrevPos = fptCoord;          

					break;
				case 2:
					//					fptPrevPos = fptCoord; 
					break;
				case 3:
					m_gObj.dCode = m_nADCode;

					m_gObj.Type.nType = DRAW_TYPE::FLASH;

					m_pLayerInfo->vecObjCoord.push_back(m_fptCoord);
					m_nNumOfObjCoord++;

					m_gObj.Extent.X1 = m_fptCoord.x + m_CurMinMax.X1;
					m_gObj.Extent.X2 = m_fptCoord.x + m_CurMinMax.X2;
					m_gObj.Extent.Y1 = m_fptCoord.y + m_CurMinMax.Y1;
					m_gObj.Extent.Y2 = m_fptCoord.y + m_CurMinMax.Y2;
					SetLayerMaxExtent(m_gObj.Extent);

					if (m_paramIP.bLayerPolarity == LAYER_TYPE::NEGATIVE)
						m_gObj.Type.nPolarity = DRAW_TYPE::NEGATIVE;
					else
						m_gObj.Type.nPolarity = DRAW_TYPE::POSITIVE;

					m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;


					m_pLayerInfo->listObj.push_back(m_gObj);
					ClearDataObject(m_gObj);
					m_gObj.nStPnt = m_nNumOfObjCoord;

					m_nObj++;
					//					fptPrevPos = fptCoord;
					break;
				default:
					//					fptPrevPos = fptCoord;

					if (m_nDCode >= 10)
					{
						m_nADCode = m_nDCode;
						m_pLayerInfo->mapAptList.Lookup(m_nADCode, m_rAptDef);
						m_CurMinMax = m_rAptDef->minmax;
					}
					break;
				}
			}
			else
			{
				//fptPrevPos = fptCoord;

				if (m_nDCode >= 10)
				{
					m_nADCode = m_nDCode;
					m_pLayerInfo->mapAptList.Lookup(m_nADCode, m_rAptDef);
					m_CurMinMax = m_rAptDef->minmax;
				}
			}
		}
		else
		{
			if (!(m_nDCode == m_nPrevDCode && m_nADCode == m_nPrevADCode && m_fptCoord.x == m_fptPrevPos.x && m_fptCoord.y == m_fptPrevPos.y))
			{
				m_nPrevADCode = m_nADCode;
				switch (m_nDCode)
				{
				case 1:
					m_pLayerInfo->vecObjCoord.push_back(m_fptCoord);
					m_nNumOfObjCoord++;
					m_pLayerInfo->vecObjCoord.push_back(m_fptPrevPos);
					m_nNumOfObjCoord++;

					m_gObj.dCode = m_nADCode;

					if (m_bParsingGCodeFlag)
					{
						if (m_nGCode > 2)
							m_gObj.Type.nType = DRAW_TYPE::ARC_CCW;
						else
							m_gObj.Type.nType = DRAW_TYPE::ARC_CW;

						m_fptOpt.x += m_fptPrevPos.x;
						m_fptOpt.y += m_fptPrevPos.y;

						m_gObj.Extent = MinMaxArcGRB((DRAW_TYPE::TYPE)m_gObj.Type.nType, m_fptPrevPos, m_fptCoord, m_fptOpt, m_CurMinMax);

						m_pLayerInfo->vecObjCoord.push_back(m_fptOpt);
						m_nNumOfObjCoord++;
					}
					else
					{
						if (m_bParsingIJFlag)
						{
							if (m_nGCode > 2)
								m_gObj.Type.nType = DRAW_TYPE::ARC_CCW;
							else
								m_gObj.Type.nType = DRAW_TYPE::ARC_CW;

							m_fptOpt.x += m_fptPrevPos.x;
							m_fptOpt.y += m_fptPrevPos.y;

							m_pLayerInfo->vecObjCoord.push_back(m_fptOpt);
							m_nNumOfObjCoord++;
							m_gObj.Extent = MinMaxArcGRB((DRAW_TYPE::TYPE)m_gObj.Type.nType, m_fptPrevPos, m_fptCoord, m_fptOpt, m_CurMinMax);
						}
						else
						{
							if (m_fptCoord.x == m_fptPrevPos.x && m_fptCoord.y == m_fptPrevPos.y) //   ' Flash로 변환
								m_gObj.Type.nType = DRAW_TYPE::FLASH;
							else
							{
								m_gObj.Type.nType = DRAW_TYPE::LINE;
								m_pLayerInfo->mapAptList.Lookup(m_gObj.dCode, m_rAptDef);
								if (m_rAptDef->chStdAptType == _T('C'))
								{
									m_nNumOfLineObject++; // count up line object
									m_nNumOfLineTemplate = m_vecLineTemplate.size();
									if (m_nNumOfLineTemplate > m_nMaxLineTemplate - 2)
									{
										sort(m_vecLineTemplate.begin(), m_vecLineTemplate.end());
										m_vecTemp.clear();
										std::unique_copy(m_vecLineTemplate.begin(), m_vecLineTemplate.end(), std::back_inserter(m_vecTemp));
										(m_vecLineTemplate).swap(m_vecTemp);
									}

									dX = (m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt + 1).x - m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt).x);
									dY = (m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt + 1).y - m_pLayerInfo->vecObjCoord.at(m_gObj.nStPnt).y);

									Key.Param[0] = (dX*dX + dY*dY); // length
									Key.Param[1] = m_rAptDef->Param.at(0).fParam.at(0); // line width

									m_vecLineTemplate.push_back(Key.key);
									fWidthOfLine = m_rAptDef->Param.at(0).fParam.at(0);
									if (m_mapLineInfo.Lookup(fWidthOfLine, sttLineInfo))
									{
										sttLineInfo.nNumOfLine++;
									}
									else
									{
										sttLineInfo.nNumOfLine = 1;
									}
									m_mapLineInfo.SetAt(fWidthOfLine, sttLineInfo);
								}
							}

							if (m_fptCoord.x < m_fptPrevPos.x)
							{
								m_gObj.Extent.X1 = m_fptCoord.x + m_CurMinMax.X1;
								m_gObj.Extent.X2 = m_fptPrevPos.x + m_CurMinMax.X2;
							}
							else
							{
								m_gObj.Extent.X1 = m_fptPrevPos.x + m_CurMinMax.X1;
								m_gObj.Extent.X2 = m_fptCoord.x + m_CurMinMax.X2;
							}
							if (m_fptCoord.y < m_fptPrevPos.y)
							{
								m_gObj.Extent.Y1 = m_fptCoord.y + m_CurMinMax.Y1;
								m_gObj.Extent.Y2 = m_fptPrevPos.y + m_CurMinMax.Y2;
							}
							else
							{
								m_gObj.Extent.Y1 = m_fptPrevPos.y + m_CurMinMax.Y1;
								m_gObj.Extent.Y2 = m_fptCoord.y + m_CurMinMax.Y2;
							}
						}
					}
					SetLayerMaxExtent(m_gObj.Extent);

					if (m_paramIP.bLayerPolarity == LAYER_TYPE::NEGATIVE)
						m_gObj.Type.nPolarity = DRAW_TYPE::NEGATIVE;
					else
						m_gObj.Type.nPolarity = DRAW_TYPE::POSITIVE;

					m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;


					m_pLayerInfo->listObj.push_back(m_gObj);
					ClearDataObject(m_gObj);
					m_gObj.nStPnt = m_nNumOfObjCoord;

					m_nObj++;
					//fptPrevPos = fptCoord;          
					break;
				case 2:
					//fptPrevPos = fptCoord;
					break;
				case 3:
					m_gObj.dCode = m_nADCode;

					m_gObj.Type.nType = DRAW_TYPE::FLASH;

					m_pLayerInfo->vecObjCoord.push_back(m_fptCoord);
					m_nNumOfObjCoord++;

					m_gObj.Extent.X1 = m_fptCoord.x + m_CurMinMax.X1;
					m_gObj.Extent.X2 = m_fptCoord.x + m_CurMinMax.X2;
					m_gObj.Extent.Y1 = m_fptCoord.y + m_CurMinMax.Y1;
					m_gObj.Extent.Y2 = m_fptCoord.y + m_CurMinMax.Y2;
					SetLayerMaxExtent(m_gObj.Extent);

					if (m_paramIP.bLayerPolarity == LAYER_TYPE::NEGATIVE)
						m_gObj.Type.nPolarity = DRAW_TYPE::NEGATIVE;
					else
						m_gObj.Type.nPolarity = DRAW_TYPE::POSITIVE;

					m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;


					m_pLayerInfo->listObj.push_back(m_gObj);
					ClearDataObject(m_gObj);
					m_gObj.nStPnt = m_nNumOfObjCoord;

					m_nObj++;
					//fptPrevPos = fptCoord;
					break;
				default:
					if (m_nDCode >= 10)
					{
						m_nADCode = m_nDCode;
						m_pLayerInfo->mapAptList.Lookup(m_nADCode, m_rAptDef);
						m_CurMinMax = m_rAptDef->minmax;
					}
					break;
				}
			}
			else
			{
				//fptPrevPos = fptCoord;
			}
		}
	}
	m_fptPrevPos = m_fptCoord;

	m_bParsingXYFlag = FALSE;
	m_bParsingIJFlag = FALSE;
	m_bParsingGCodeFlag = FALSE;
	m_bParsingdCodeFlag = FALSE;
}

BOOL CSimple274X::DecodingIgnore(char** pFile, char** pLine)
{
	switch (**pFile)
	{
	case TCHAR(EOB):
		(*pFile)++;
		m_nNumOfDataBlock++; // data block counter in file
		return TRUE;
	case TCHAR(ASCII_CR):
		(*pFile)++;
		return TRUE;
	case TCHAR(ASCII_LF):
		(*pFile)++;
		m_nNumOfTextLine++;	// line counter in file
		pLine = pFile;
		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::DecodingCoordinate(char** pFile)
{
	CString strErrMsg;

	switch (**pFile)
	{
	case _T('X'):
		m_bParsingXYFlag = TRUE;
		m_fptCoord.x = GetDataCoordX(&(++(*pFile)));
		if (**pFile == _T('Y')) // Y coordinate of line endpoint
		{
			m_fptCoord.y = GetDataCoordY(&(++(*pFile)));
		}
		if (**pFile == _T('I')) // Y coordinate of line endpoint
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.x = GetDataCoordX(&(++(*pFile)));
		}
		else
			m_fptOpt.x = 0.0;
		if (**pFile == _T('J')) // Y coordinate of line endpoint
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.y = GetDataCoordY(&(++(*pFile)));
		}
		else
			m_fptOpt.y = 0.0;
		if (**pFile == _T('D'))// Exposure
		{
			m_bParsingdCodeFlag = TRUE;
			m_nPrevDCode = m_nDCode;
			m_nDCode = GetDataInteger(&(++(*pFile)));
			switch (m_nDCode)
			{
			case 1: // Exposure On
				break;
			case 2: // Exposure Off
				break;
			case 3: // Flash On ?
				break;
			default:
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), m_nDCode);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}
		return TRUE;
	case _T('Y'):
		m_bParsingXYFlag = TRUE;
		m_fptCoord.y = GetDataCoordY(&(++(*pFile)));
		if (**pFile == _T('I')) // Y coordinate of line endpoint
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.x = GetDataCoordX(&(++(*pFile)));
		}
		else
			m_fptOpt.x = 0.0;

		if (**pFile == _T('J')) // Y coordinate of line endpoint
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.y = GetDataCoordY(&(++(*pFile)));
		}
		else
			m_fptOpt.y = 0.0;

		if (**pFile == _T('D'))// Exposure
		{
			m_bParsingdCodeFlag = TRUE;
			m_nPrevDCode = m_nDCode;
			m_nDCode = GetDataInteger(&(++(*pFile)));
			switch (m_nDCode)
			{
			case 1: // Exposure On
				break;
			case 2: // Exposure Off
				break;
			case 3: // Flash On ?
				break;
			default:
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), m_nDCode);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}
		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::DecodingFunction(char** pFile)
{
	int nData;
	CString strMsg, strErrMsg;

	switch (**pFile)
	{
	case _T('D'):	// fetch numeric code:D-Code
		if (FunctionDCode(pFile))
			return TRUE;
		break;
	case _T('G'):	// fetch numeric code:G-Code		
		if (FunctionGCode(pFile))
		{
			if (**pFile == EOB)
				(*pFile)++;
			return TRUE;
		}
		break;
	case _T('M'):	// fetch numeric code:M-Code		
		if (FunctionMCode(pFile))
			return TRUE;
		break;
	}

	return FALSE;
}

BOOL CSimple274X::DecodingParameter(char** pFile)
{
	CString strErrMsg;

	if (**pFile == _T('%'))
	{
		(*pFile)++;

		while (**pFile != _T('%'))
		{
			if (ParameterFS(pFile))
				continue;
			if (ParameterAperture(pFile))
				continue;
			if (ParameterBkMode(pFile))
				continue;
			if (ParameterDashLine(pFile))
				continue;
			if (ParameterKnockOut(pFile))
				continue;
			if (ParameterSequence(pFile))
				continue;
			if (ParameterRotate(pFile))
				continue;
			if (ParameterTranslation(pFile))
				continue;
			if (ParameterVelocity(pFile))
				continue;
			if (ParameterWindowSpec(pFile))
				continue;
			if (ParameterI(pFile))
				continue;
			if (ParameterL(pFile))
				continue;
			if (ParameterM(pFile))
				continue;
			if (ParameterO(pFile))
				continue;
			if (ParameterP(pFile))
				continue;
			if (ParameterS(pFile))
				continue;

			if (**pFile == EOB)
				(*pFile)++;
			else if (**pFile == TCHAR(ASCII_CR))
				(*pFile)++;
			else if (**pFile == TCHAR(ASCII_LF))
			{
				(*pFile)++;
				m_nNumOfTextLine++;
			}
			else
			{
				strErrMsg.Format(_T("RS274X parameter block parsing error:%c"), **pFile);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}

		(*pFile)++;  // erase end '%'
		return TRUE;
	}

	return FALSE;
}


BOOL CSimple274X::FunctionDCode(char** pFile)
{
	int nData;
	CString strMsg, strErrMsg;

	// fetch numeric code:D-Code
	nData = GetDataInteger(&(++(*pFile)));

	switch (nData)
	{
	case 1: // Exposure and Draw mode on
		m_bParsingXYFlag = TRUE;
		m_bParsingdCodeFlag = TRUE;
		m_fptCoord = m_fptPrevPos;
		m_fptOpt = FPOINTC(0.0, 0.0);
		m_nPrevDCode = m_nDCode;
		m_nDCode = nData;
		break;
	case 2: // Exposure and Draw mode off
		m_bParsingXYFlag = TRUE;
		m_bParsingdCodeFlag = TRUE;
		m_fptCoord = m_fptPrevPos;
		m_fptOpt = FPOINTC(0.0, 0.0);
		m_nPrevDCode = m_nDCode;
		m_nDCode = nData;
		break;
	case 3: // Set flash mode
		m_bParsingXYFlag = TRUE;
		m_bParsingdCodeFlag = TRUE;
		m_fptCoord = m_fptPrevPos;
		m_fptOpt = FPOINTC(0.0, 0.0);
		m_nPrevDCode = m_nDCode;
		m_nDCode = nData;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 0:
		while (**pFile != EOB)  // D00, D04-D09 ignore data block
			(*pFile)++;
		break;
	default: // Select an aperture defined by an AD parameter
		if (m_nDCode < 0 || m_nDCode > 999)
		{
			strMsg.Format(_T("Unsupported D-Code:%d"), m_nDCode);
			AfxMessageBox(strMsg, MB_OK);
		}
		else
		{
			m_nADCode = nData;
			m_pLayerInfo->mapAptList.Lookup(m_nADCode, m_rAptDef);
			m_CurMinMax = m_rAptDef->minmax;
		}
		break;
	}

	return TRUE;
}

BOOL CSimple274X::FunctionGCode(char** pFile)
{
	int nData;
	CString strMsg, strErrMsg;
	BOOL bRtn = FALSE;

	m_nGCode = GetDataInteger(&(++(*pFile)));
	switch (m_nGCode)
	{
	case 1: // G01(G1) Linear Interpolation
		if (**pFile == _T('X')) // X coordinate of line endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.x = GetDataCoordX(&(++(*pFile)));
		}
		if (**pFile == _T('Y')) // Y coordinate of line endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.y = GetDataCoordY(&(++(*pFile)));
		}
		if (**pFile == _T('D'))// Exposure
		{
			m_bParsingdCodeFlag = TRUE;
			m_nPrevDCode = m_nDCode;
			m_nDCode = GetDataInteger(&(++(*pFile)));
			switch (m_nDCode)
			{
			case 1: // Exposure On
				break;
			case 2: // Exposure Off
				break;
			case 3: // Flash On ?
				break;
			default:
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), m_nDCode);
				AfxMessageBox(strMsg, MB_OK);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}
		break;
	case 2: // Clockwise circular Interpolation : Single Quadrant mode
		m_bParsingGCodeFlag = TRUE;

		if (**pFile == _T('X')) // X coordinate of arc endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.x = GetDataCoordX(&(++(*pFile)));
		}
		if (**pFile == _T('Y')) // Y coordinate of arc endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.y = GetDataCoordY(&(++(*pFile)));
		}
		if (**pFile == _T('I'))	// The offset between the arc start point and the center paralled to the X aixs. The value is always positive.
								// A sign is not allowed. The direction to the center is determined implicitly.
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.x = GetDataCoordX(&(++(*pFile)));
		}
		else
			m_fptOpt.x = 0.0;

		if (**pFile == _T('J')) // The offset between the arc start point and the center paralled to the Y aixs. The value is always positive.
								// A sign is not allowed. The direction to the center is determined implicitly.
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.y = GetDataCoordY(&(++(*pFile)));
		}
		else
			m_fptOpt.y = 0.0;

		if (**pFile == _T('D')) // Exposure
		{
			m_bParsingdCodeFlag = TRUE;
			m_nPrevDCode = m_nDCode;
			m_nDCode = GetDataInteger(&(++(*pFile)));
			switch (m_nDCode)
			{
			case 1: // Exposure On
				break;
			case 2: // Exposure Off
				break;
			case 3: // Flash On ?
				break;
			default:
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), m_nDCode);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}
		break;
	case 3: // Counterclockwise circular Interpolation : Single Quadrant mode
		m_bParsingGCodeFlag = TRUE;

		if (**pFile == _T('X')) // X coordinate of arc endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.x = GetDataCoordX(&(++(*pFile)));
		}
		if (**pFile == _T('Y')) // Y coordinate of arc endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.y = GetDataCoordY(&(++(*pFile)));
		}
		if (**pFile == _T('I'))	// The offset between the arc start point and the center paralled to the X aixs. The value is always positive.
								// A sign is not allowed. The direction to the center is determined implicitly.
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.x = GetDataCoordX(&(++(*pFile)));
		}
		else
			m_fptOpt.x = 0.0;

		if (**pFile == _T('J')) // The offset between the arc start point and the center paralled to the Y aixs. The value is always positive.
								// A sign is not allowed. The direction to the center is determined implicitly.
		{
			m_bParsingIJFlag = TRUE;
			m_fptOpt.y = GetDataCoordY(&(++(*pFile)));
		}
		else
			m_fptOpt.y = 0.0;

		if (**pFile == _T('D')) // Exposure
		{
			m_bParsingdCodeFlag = TRUE;
			m_nPrevDCode = m_nDCode;
			m_nDCode = GetDataInteger(&(++(*pFile)));
			switch (m_nDCode)
			{
			case 1: // Exposure On
				break;
			case 2: // Exposure Off
				break;
			case 3: // Flash On ?
				break;
			default:
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), m_nDCode);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}
		break;
		// The G74,G75 command allow switching between the two modes. A data block becomming G75 enables multi quadrent mode.
		// Every block following it will be interpolated as multi quadrant. until cancelled by a G74
		// A data block containing G74 code turns off multi quadrant mode. reverting to single quadrant mode.
	case 74: // Set single quadrant mode(default)
		m_bImplicitFlag = TRUE;
		break;
	case 75: // Set multi quadrant mode
		m_bImplicitFlag = FALSE;
		break;
	case 4: // G04 ignore data block
		while (**pFile != EOB)
			(*pFile)++;
		break;
	case 36: // outline fill  turn on
		m_gObj.dCode = 0;
		m_nADCode = 0;
		m_bPolygonFlag = TRUE;
		if (m_bImplicitFlag)
			m_gObj.Type.nType = DRAW_TYPE::POLYGON_SQ;   //'G74
		else
			m_gObj.Type.nType = DRAW_TYPE::POLYGON_MQ;   //'G75

		m_gObj.Extent = m_MaxFrameExtent;
		break;
	case 37: // outline fill  turn off
		if (m_bPolygonFlag) // ==============> Polygon Flag ==========>
		{
			if (m_gObj.nStPnt < m_nNumOfObjCoord)
			{
				if (m_paramIP.bLayerPolarity == LAYER_TYPE::NEGATIVE)
					m_gObj.Type.nPolarity = DRAW_TYPE::NEGATIVE;
				else
					m_gObj.Type.nPolarity = DRAW_TYPE::POSITIVE;

				m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;


				m_pLayerInfo->listObj.push_back(m_gObj);

				ClearDataObject(m_gObj);
				m_gObj.nStPnt = m_nNumOfObjCoord;

				m_nObj++;
				m_bPolygonFlag = FALSE;
			}
			else
				m_bPolygonFlag = FALSE;
		}
		break;
	case 54: // select aperture, this historic code optionally precedes an aperture D-code. It is superfluous and deprecated
		if (**pFile == _T('D'))// Exposure
		{
			m_nADCode = GetDataInteger(&(++(*pFile)));
			if (m_nADCode < 10)
			{
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), nData);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
			else
			{
				m_pLayerInfo->mapAptList.Lookup(m_nADCode, m_rAptDef);
				m_CurMinMax = m_rAptDef->minmax;
			}
		}
		break;
	case 55:
		if (**pFile == _T('X')) // X coordinate of line endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.x = GetDataCoordX(&(++(*pFile)));
		}
		if (**pFile == _T('Y')) // Y coordinate of line endpoint
		{
			m_bParsingXYFlag = TRUE;
			m_fptCoord.y = GetDataCoordY(&(++(*pFile)));
		}
		if (**pFile == _T('D'))// Exposure
		{
			m_bParsingdCodeFlag = TRUE;
			m_nPrevDCode = m_nDCode;
			m_nDCode = GetDataInteger(&(++(*pFile)));
			switch (m_nDCode)
			{
			case 3: // Flash On ?
				break;
			default:
				strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code D%02d"), m_nDCode);
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
		}
		break;
	case 70: // Specify inches
		break;
	case 71: // Specify millimeters
		break;
	case 90: // Specify absolute format
		break;
	case 91: // Specify incremental format
		break;
	default:
		strErrMsg.Format(_T("RS274X parameter block parsing error: invalid G-Code G%02d"), m_nGCode);
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
		return TRUE;
	}

	if (**pFile == EOB)
		(*pFile)++;

	return TRUE;
}

BOOL CSimple274X::FunctionMCode(char** pFile)
{
	int nData, i;
	CString strMsg, strErrMsg;

	m_nMCode = GetDataInteger(&(++(*pFile)));
	switch (m_nMCode)
	{
	case 0: // Program stop. This historic code has no effect on the image. It is deprecated.
		break;
	case 1: // Optional Stop. This historic code has no effect on the image. It is deprecated.
		break;
	case 2: // End of program. Ends image generation. Every file must end in a M02
		if ((m_paramMI.bMirrorX || m_paramMI.bMirrorY) && m_nStartMirrorObj == 0)
			InitLayerMaxExtent();

		Mirror();
		StepAndRepeating(m_MnMxSnR, FALSE);
		m_bLastFrame = TRUE;
		return TRUE;
	default:
		strErrMsg.Format(_T("RS274X parameter block parsing error: invalid M-Code M%02d"), m_nMCode);
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
		return TRUE;
	}

	return TRUE;
}


BOOL CSimple274X::ParameterFS(char** pFile)
{
	int peRepeat;
	int nLN, i, nCoord;
	int	 nDataFormatX, nDataFormatY;
	CString strErrMsg;

	nLN = 0;

	if (**pFile == _T('F'))
	{
		(*pFile)++;

		if (**pFile == _T('S'))
		{
			if (nLN > 0)
			{
				if ((m_paramMI.bMirrorX || m_paramMI.bMirrorY) && m_nStartMirrorObj == 0)
					InitLayerMaxExtent();

				if (m_paramMI.bMirrorX)
				{
					m_nEndMirrorObj = m_pLayerInfo->listObj.size();
					for (i = m_nStartMirrorObj; i < m_nEndMirrorObj; i++)
					{
						if (i == m_nEndMirrorObj - 1)
							nCoord = m_pLayerInfo->vecObjCoord.size() - m_pLayerInfo->listObj[i].nStPnt;
						else
							nCoord = m_pLayerInfo->listObj[i + 1].nStPnt - m_pLayerInfo->listObj[i].nStPnt;

						MirrorVerticalObject(m_pLayerInfo, &m_pLayerInfo->listObj.at(i), nCoord, 0.0);
						SetLayerMaxExtent(m_pLayerInfo->listObj.at(i).Extent);
					}

					m_paramMI.bMirrorX = FALSE;
				}
				if (m_paramMI.bMirrorY)
				{
					m_nEndMirrorObj = m_pLayerInfo->listObj.size();
					for (i = m_nStartMirrorObj; i < m_nEndMirrorObj; i++)
					{
						if (i == m_nEndMirrorObj - 1)
							nCoord = m_pLayerInfo->vecObjCoord.size() - m_pLayerInfo->listObj.at(i).nStPnt;
						else
							nCoord = m_pLayerInfo->listObj.at(i + 1).nStPnt - m_pLayerInfo->listObj.at(i).nStPnt;

						MirrorHorizontalObject(m_pLayerInfo, &m_pLayerInfo->listObj.at(i), nCoord, 0.0);
						SetLayerMaxExtent(m_pLayerInfo->listObj.at(i).Extent);
					}

					m_paramMI.bMirrorY = FALSE;
				}
				m_nStartMirrorObj = 0;

				StepAndRepeating(m_MnMxSnR);

				m_paramSR.nXRepeat = 0;
				m_paramSR.nYRepeat = 0;
				m_paramSR.psRepeat = 0;
				peRepeat = 0;
				m_fStepX = 0;
				m_fStepY = 0;

				m_mapAMMacro.RemoveAll();

				// Add Dummy Object
				m_gObj.Type.nType = DRAW_TYPE::FLASH;
				m_gObj.Type.nAttr = DRAW_TYPE::NONE;
				m_gObj.nStPnt = m_nNumOfObjCoord;

				m_pLayerInfo->listObj.push_back(m_gObj);
				// <===================================


				//m_nNumOfLineObject += nNumOfLineObject;

				m_nNumOfLineTemplate = m_vecLineTemplate.size();
				if (m_nNumOfLineTemplate > 0)
				{
					sort(m_vecLineTemplate.begin(), m_vecLineTemplate.end());
					m_vecTemp.clear();
					std::unique_copy(m_vecLineTemplate.begin(), m_vecLineTemplate.end(), std::back_inserter(m_vecTemp));
					(m_vecLineTemplate).swap(m_vecTemp);
					m_nNumOfLineTemplate = m_vecLineTemplate.size();
				}
				m_vecTemp.clear();


				m_pLayerInfo->Extent = GetLayerMaxExtent();
				m_pLayerInfo->bUnit = m_Unit;
				m_pLayerInfo->nLayerGroupID = m_nLayerGroupID;

				if (m_nIRAngle != 0)
				{
					double cX, cY;

					cX = (m_pLayerInfo->Extent.X1 + m_pLayerInfo->Extent.X2) / 2.0;
					cY = (m_pLayerInfo->Extent.X1 + m_pLayerInfo->Extent.X2) / 2.0;

					ApplyIROptionGRB(m_pLayerInfo, cX, cY, -m_nIRAngle);
				}

				ClearDataObject(m_gObj);
				m_ArLayerInform.Add(m_pLayerInfo);

				m_nNumOfObjCoord = 0;
				m_gObj.nStPnt = 0;
				m_pLayerInfo = new LAYER_INFORM_RS274X;
				m_nLayer++;
				if (m_nLayer == 14)
					m_nLayer = 14;
				m_nNumOfObject = m_ArLayerStruct.GetAt(m_nLayer).nObject;
				m_nNumOfCoord = m_ArLayerStruct.GetAt(m_nLayer).nCoord;
				m_pLayerInfo->listObj.reserve(m_nNumOfObject + 1);
				i = m_pLayerInfo->listObj.capacity();

				m_pLayerInfo->nFormat = CAM_DATA::RS274X;
				m_pLayerInfo->strFilePath = m_sPathFile;
				m_pLayerInfo->vecObjCoord.reserve(m_nNumOfCoord);

				m_nObj = 0;
				m_fLayerScaleX = 1.0;
				m_fLayerScaleY = 1.0;
				InitLayerMaxExtent();
			}
			(*pFile)++;
			if (*(*pFile)++ == _T('L'))// 'L' or 'T':  Use L to leading zeros, Use T to omit trailing zeros
				m_paramFS.bSuppress = FALSE; //  'Leading Zero omitted
			else
				m_paramFS.bSuppress = TRUE;

			if (*(*pFile)++ == _T('A')) // 'A' or 'I':  Use A for absolute coordinate values, Use I for incremental coordinate values
				m_paramFS.bAbsolute = TRUE;
			else
				m_paramFS.bAbsolute = FALSE;

			if (*(*pFile) == _T('X'))
			{
				nDataFormatX = ParseIntegerData(&(++(*pFile))); // Xnm Enter X the number of n integer and m decimal places in the coordinate data for X axis 

				m_lDataFormatX = ldiv(nDataFormatX, 10);
				m_fDividerX = pow(10.0, m_lDataFormatX.rem);
				m_optionFormat.Format(_T("%d%d"), m_lDataFormatX.quot, m_lDataFormatX.rem);
			}

			if (*(*pFile) == _T('Y'))
			{
				nDataFormatY = ParseIntegerData(&(++(*pFile))); // Ynm Enter Y the number of n integer and m decimal places in the coordinate data for Y axis 
				m_lDataFormatY = ldiv(nDataFormatY, 10);
				m_fDividerY = pow(10.0, m_lDataFormatY.rem);
				m_optionFormat.Format(_T("%d%d"), m_lDataFormatY.quot, m_lDataFormatY.rem);
			}

			if (**pFile == EOB) (*pFile)++;

			return TRUE;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:F%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CSimple274X::ParameterAperture(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	TCHAR szAMName[MAX_PATH];
	int i, nData, nLength;
	CString strAMContent;
	CString strErrMsg;

	if (**pFile == _T('A'))
	{
		(*pFile)++;
		switch (**pFile)
		{
		case _T('A'):	// Aperture Assignment - ignored, vector photoplotter command
		case _T('F'):	// Auto Focus - ignored, vector photoplotter command
		case _T('P'):	// Aperture Offset - ignored, vector photoplotter command
		case _T('R'):	// Aperture Record - ignored, vector photoplotter command
		case _T('V'):	// Aperture vVelocity - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		case _T('S'):	// Axis select - warning, should not impact appearance
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		case _T('D'):	// Aperature definition , %ADD<D-code number><aperture type>,<modifier>[X<modifier>]*%
			(*pFile)++;
			if (ApertureDefinition(pFile))
				return TRUE;
			break;
		case _T('M'):	// Aperature macro
			(*pFile)++;
			i = 0;
			while (**pFile != EOB && i < MAX_PATH)
				szAMName[i++] = *(*pFile)++;
			szAMName[i] = NULL;

			if (**pFile == EOB)
				(*pFile)++; // LF,'*'
			while (**pFile == TCHAR(ASCII_LF) || **pFile == TCHAR(ASCII_CR))
				(*pFile)++; // ignore CR,LF

			nLength = strpbrk(*pFile, "%") - *pFile;

			char *pAMParam;
			pAMParam = new char[nLength + 1];

			strncpy(pAMParam, *pFile, nLength);
			//strncpy_s(pAMParam, nLength + 1, pFile, nLength);

			*(pAMParam + nLength) = NULL;
			strAMContent = (CString)pAMParam;
			delete[]pAMParam;
			m_mapAMMacro.SetAt(szAMName, strAMContent);

			(*pFile) += nLength;

			break;

		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:A%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterBkMode(char** pFile)
{
	TCHAR szAMName[MAX_PATH];
	int i;
	CString strErrMsg;

	if (**pFile == _T('B'))
	{
		(*pFile)++;

		if (**pFile == _T('G')) // Background Mode - warning, should not impact appearance
		{
			(*pFile)++;
			i = 0;
			while (**pFile != EOB && i < MAX_PATH) szAMName[i++] = *(*pFile)++;
			szAMName[i] = NULL;
			return TRUE;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:A%c"), **pFile);
			m_bLastFrame = TRUE;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CSimple274X::ParameterDashLine(char** pFile)
{
	CString strErrMsg;

	if (**pFile == _T('D'))
	{
		(*pFile)++;
		if (**pFile == _T('L')) // Dash Line specification, ignored, vector photoplotter command
		{
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			return TRUE;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:A%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CSimple274X::ParameterKnockOut(char** pFile)
{
	CString strErrMsg;

	if (**pFile == _T('K')) // KnockOut - supported if SF = scale factors in A and B must be 1.0 and MI = mirror values A and B must be 0
	{
		(*pFile)++;

		if (**pFile == _T('O'))	// Knockout
		{
			(*pFile)++;
			return TRUE;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:K%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CSimple274X::ParameterRotate(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i;

	if (**pFile == _T('R'))
	{
		(*pFile)++;

		switch (**pFile)
		{
		case _T('C'): // Rotate Symbol - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		case _T('O'): // Rotate Position Data - supported if SF = scale factors in A and B must be 1.0 and MI = mirror values A and B must be 0
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:R%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterTranslation(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i;

	if (**pFile == _T('T'))
	{
		(*pFile)++;

		if (**pFile == _T('R')) // Translation - ignored, vector photoplotter command
		{
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:T%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterWindowSpec(char** pFile)
{
	CString strErrMsg;

	if (**pFile == _T('W'))
	{
		(*pFile)++;

		if (**pFile == _T('I')) // Window Specification - ignored, vector photoplotter command
		{
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:W%c"), **pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterI(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i, nData;
	float fData;

	if (**pFile == _T('I'))
	{
		(*pFile)++;

		switch (**pFile)
		{
		case _T('C'): // Input Code - warning, should not impact appearance
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH) szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		case _T('D'): // Input Display - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		case _T('F'): // Include File
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			strErrMsg.Format(_T("RS274X parameter block parsing error: IF command Not supported by gigavis"));
			AfxMessageBox(strErrMsg);
			break;
		case _T('J'): // Image Justify - warning, should not impact appearance
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)	szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		case _T('N'): // Image Name - warning, should not impact appearance
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH) szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		case _T('O'): // Image Offset - warning, should not impact appearance
			(*pFile)++;
			if (**pFile == _T('A'))
				fData = ParseFloatData(&(++(*pFile)), TRUE);
			if (**pFile == _T('B'))
				fData = ParseFloatData(&(++(*pFile)), TRUE);
			break;
		case _T('P'): // Image polarity supported if SF = scale factors in A and B must be 1.0 and MI = mirror values A and B must be 0
			(*pFile)++;
			szTemp[0] = *(*pFile)++;
			szTemp[1] = *(*pFile)++;
			szTemp[2] = *(*pFile)++;
			szTemp[3] = NULL;
			if (!_tcsncmp(szTemp, _T("POS"), 3))
			{
				m_paramIP.PolChangeFlag = FALSE;
				m_paramIP.bLayerPolarity = LAYER_TYPE::POSITIVE;
				nData = 0; // Positive
			}
			else
			{
				m_paramIP.PolChangeFlag = TRUE;
				m_paramIP.bLayerPolarity = LAYER_TYPE::NEGATIVE;
				nData = 1; // Negative	
			}
			break;
		case _T('R'): // Image rotation
			m_nIRAngle = ParseIntegerData(&(++(*pFile)));
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:I%c"), **pFile);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		if (**pFile == EOB)
			(*pFile)++;

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterVelocity(char** pFile)
{
	CString strErrMsg;

	if (**pFile == _T('V'))
	{
		(*pFile)++;

		if (**pFile == _T('L')) // Velocity Limit - ignored, vector photoplotter command
		{
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:V%c"), **pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterSequence(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i;

	if (**pFile == _T('N'))
	{
		(*pFile)++;
		if (**pFile == _T('F') || **pFile == _T('S')) // Sequence Number - warning, should not impact appearance
		{
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;

			return TRUE;
		}
		else
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error:M%c"), *pFile);
			m_bLastFrame = TRUE;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CSimple274X::ParameterL(char** pFile)
{
	CHAR szLayerName[MAX_PATH];
	CString strErrMsg;
	int i, nLN = 0;
	BOOL bCheckLNFlag;

	nLN = 0;

	if (**pFile == _T('L'))
	{
		(*pFile)++;

		switch (**pFile)
		{
		case _T('N'):	// Layer name
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szLayerName[i++] = *(*pFile)++;
			szLayerName[i] = NULL;

			m_pLayerInfo->strName = (CString)szLayerName;

			bCheckLNFlag = TRUE;
			nLN += 1000;

			(*pFile)++;
			break;
		case _T('P'):	// Layer polarity
			TCHAR chLayerPolarity;
			(*pFile)++;
			chLayerPolarity = *(*pFile)++;

			if (m_paramIP.PolChangeFlag) //   '이미지 극성 변환
			{
				if (chLayerPolarity == _T('D'))
					m_paramIP.bLayerPolarity = LAYER_TYPE::NEGATIVE;
				else
					m_paramIP.bLayerPolarity = LAYER_TYPE::POSITIVE;
			}
			else
			{
				if (chLayerPolarity == _T('D'))
					m_paramIP.bLayerPolarity = LAYER_TYPE::POSITIVE;
				else
					m_paramIP.bLayerPolarity = LAYER_TYPE::NEGATIVE;
			}

			if (**pFile == EOB)
				(*pFile)++;
			else
			{
				strErrMsg.Format(_T("RS274X parameter block parsing error:LP%c%c"), chLayerPolarity, **pFile);
				m_bLastFrame = TRUE;
				return TRUE;
			}
			break;
		case _T('S'): // Load Symbol - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:L%c"), **pFile);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterM(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i, nCoord;

	if (**pFile == _T('M'))
	{
		(*pFile)++;
		switch (**pFile)
		{
		case _T('I'):	// Mirror image
			if ((m_paramMI.bMirrorX || m_paramMI.bMirrorY) && m_nStartMirrorObj == 0)
				InitLayerMaxExtent();

			if (m_paramMI.bMirrorX)
			{
				m_nEndMirrorObj = m_pLayerInfo->listObj.size();
				for (i = m_nStartMirrorObj; i < m_nEndMirrorObj; i++)
				{
					if (i == m_nEndMirrorObj - 1)
						nCoord = m_pLayerInfo->vecObjCoord.size() - m_pLayerInfo->listObj[i].nStPnt;
					else
						nCoord = m_pLayerInfo->listObj[i + 1].nStPnt - m_pLayerInfo->listObj[i].nStPnt;

					MirrorVerticalObject(m_pLayerInfo, &m_pLayerInfo->listObj.at(i), nCoord, 0.0);
					SetLayerMaxExtent(m_pLayerInfo->listObj.at(i).Extent);
				}

				m_paramMI.bMirrorX = FALSE;
			}
			if (m_paramMI.bMirrorY)
			{
				m_nEndMirrorObj = m_pLayerInfo->listObj.size();
				for (i = m_nStartMirrorObj; i < m_nEndMirrorObj; i++)
				{
					if (i == m_nEndMirrorObj - 1)
						nCoord = m_pLayerInfo->vecObjCoord.size() - m_pLayerInfo->listObj.at(i).nStPnt;
					else
						nCoord = m_pLayerInfo->listObj.at(i + 1).nStPnt - m_pLayerInfo->listObj.at(i).nStPnt;

					MirrorHorizontalObject(m_pLayerInfo, &m_pLayerInfo->listObj.at(i), nCoord, 0.0);
					SetLayerMaxExtent(m_pLayerInfo->listObj.at(i).Extent);
				}

				m_paramMI.bMirrorY = FALSE;
			}
			m_nStartMirrorObj = 0;

			(*pFile)++;
			if (**pFile == _T('A')) // 'A' or 'B':  Use A0 to disable mirroring, A1 to invert the A-axis. The image will be flipped over tbe B-axis
			{
				(*pFile)++;
				if (*(*pFile)++ == _T('0'))
					m_paramMI.bMirrorX = FALSE;
				else
				{
					m_paramMI.bMirrorX = TRUE;
					m_nStartMirrorObj = m_nObj;
				}
			}

			if (**pFile == _T('B'))// 'A' or 'B':  Use A0 to disable mirroring, A1 to invert the A-axis. The image will be flipped over tbe B-axis
			{
				(*pFile)++;
				if (*(*pFile)++ == _T('0'))
					m_paramMI.bMirrorY = FALSE;
				else
				{
					m_paramMI.bMirrorY = TRUE;
					m_nStartMirrorObj = m_nObj;
				}
			}
			break;
		case _T('O'):	// Mode(Inch or millimiter units)
			(*pFile)++;
			szTemp[0] = *(*pFile)++;
			szTemp[1] = *(*pFile)++;
			szTemp[2] = NULL;
			if (!_tcsncmp(szTemp, _T("IN"), 2))
				m_Unit = LAYER_TYPE::INCH;
			else
				m_Unit = LAYER_TYPE::METRIC; // millimeter
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:M%c"), *pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		if (**pFile == EOB)
			(*pFile)++;

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterO(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i;
	float fData = 0.0;

	if (**pFile == _T('O'))
	{
		(*pFile)++;
		switch (**pFile)
		{
		case _T('F'):	// Offset - warning, should not impact appearance
			(*pFile)++;
			if (**pFile == _T('A'))
			{
				fData = ParseFloatData(&(++(*pFile)), TRUE); // the offset along the output device A axis
			}

			if (**pFile == _T('B'))
			{
				fData = ParseFloatData(&(++(*pFile)), TRUE); // the offset along the output device B axis
			}
			break;
		case _T('P'): // Option Stop - supported if SF = scale factors in A and B must be 1.0 and MI = mirror values A and B must be 0
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:O%c"), **pFile);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterP(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	CString strErrMsg;
	int i;
	float fData = 0.0;

	if (**pFile == _T('P'))
	{
		(*pFile)++;
		switch (**pFile)
		{
		case _T('D'): // Plotter Destination - warning, should not impact appearance
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		case _T('E'): // Perspective - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		case _T('F'): // Film Type - warning, should not impact appearance
			i = 0;
			(*pFile)++;
			while (**pFile != EOB && i < MAX_PATH)
				szTemp[i++] = *(*pFile)++;
			szTemp[i] = NULL;
			break;
		case _T('K'): // Park - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		case _T('O'): // Pen Offset - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:P%c"), **pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CSimple274X::ParameterS(char** pFile)
{
	CString strErrMsg;
	int nData, peRepeat, i;
	float fData;

	if (**pFile == _T('S'))
	{
		(*pFile)++;
		switch (**pFile)
		{
		case _T('C'): // Single Step mode - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		case _T('F'):	// Scale factor
			(*pFile)++;
			if (**pFile == _T('A'))
			{
				fData = ParseScaleData(&(++(*pFile)), TRUE); // the offset along the output device A axis
				m_pLayerInfo->fScaleX = fData;
			}

			if (**pFile == _T('B'))
			{
				fData = ParseScaleData(&(++(*pFile)), TRUE); // the offset along the output device B axis
				m_pLayerInfo->fScaleY = fData;
			}

			m_fLayerScaleX = m_pLayerInfo->fScaleX;
			m_fLayerScaleY = m_pLayerInfo->fScaleY;
			break;
		case _T('M'):	// Symbol Mirroring
			(*pFile)++;
			if (**pFile == _T('A'))
			{
				nData = ParseIntegerData(&(++(*pFile))); // the offset along the output device A axis
			}
			if (**pFile == _T('B'))
			{
				nData = ParseIntegerData(&(++(*pFile))); // the offset along the output device B axis
			}
			break;

		case _T('R'):	// Step and Repeat
			if (m_paramSR.nXRepeat > 1 || m_paramSR.nYRepeat > 1)
			{
				FPOINTC fPt;
				peRepeat = m_pLayerInfo->listObj.size() - 1;

				ClearDataObject(m_gObj);

				m_MnMxSnR = m_MaxFrameExtent;
				for (i = m_paramSR.psRepeat; i <= peRepeat; i++)
				{
					AdjustExtentByRect(m_MnMxSnR, m_pLayerInfo->listObj.at(i).Extent);
				}

				m_gObj.dCode = 0;
				m_gObj.Type.nType = DRAW_TYPE::SNR;

				m_gObj.Extent.Y1 = m_MnMxSnR.Y1;
				m_gObj.Extent.Y2 = m_MnMxSnR.Y2;
				m_gObj.Extent.X1 = m_MnMxSnR.X1;
				m_gObj.Extent.X2 = m_MnMxSnR.X2;

				fPt.x = m_paramSR.psRepeat;
				fPt.y = peRepeat;
				m_pLayerInfo->vecObjCoord.push_back(fPt);
				m_nNumOfObjCoord++;

				fPt.x = m_paramSR.nXRepeat;
				fPt.y = m_paramSR.nYRepeat;
				m_pLayerInfo->vecObjCoord.push_back(fPt);
				m_nNumOfObjCoord++;

				fPt.x = m_fStepX;
				fPt.y = m_fStepY;
				m_pLayerInfo->vecObjCoord.push_back(fPt);
				m_nNumOfObjCoord++;

				m_MnMxSnR = GetLayerMaxExtent();
				if ((m_paramSR.nXRepeat - 1) * m_fStepX > 0)
				{
					if (m_gObj.Extent.X1 < m_MnMxSnR.X1) m_MnMxSnR.X1 = m_gObj.Extent.X1;
					if (m_gObj.Extent.X2 + (m_paramSR.nXRepeat - 1) * m_fStepX > m_MnMxSnR.X2) m_MnMxSnR.X2 = m_gObj.Extent.X2 + (m_paramSR.nXRepeat - 1) * m_fStepX;
				}
				else
				{
					if (m_gObj.Extent.X1 + (m_paramSR.nXRepeat - 1) * m_fStepX < m_MnMxSnR.X1) m_MnMxSnR.X1 = m_gObj.Extent.X1 + (m_paramSR.nXRepeat - 1) * m_fStepX;
					if (m_gObj.Extent.X2 > m_MnMxSnR.X2) m_MnMxSnR.X2 = m_gObj.Extent.X2;
				}

				if ((m_paramSR.nYRepeat - 1) * m_fStepY > 0)
				{
					if (m_gObj.Extent.Y1 < m_MnMxSnR.Y1) m_MnMxSnR.Y1 = m_gObj.Extent.Y1;
					if (m_gObj.Extent.Y2 + (m_paramSR.nYRepeat - 1) * m_fStepY > m_MnMxSnR.Y2) m_MnMxSnR.Y2 = m_gObj.Extent.Y2 + (m_paramSR.nYRepeat - 1) * m_fStepY;
				}
				else
				{
					if (m_gObj.Extent.Y1 + (m_paramSR.nYRepeat - 1) * m_fStepY < m_MnMxSnR.Y1) m_MnMxSnR.Y1 = m_gObj.Extent.Y1 + (m_paramSR.nYRepeat - 1) * m_fStepY;
					if (m_gObj.Extent.Y2 > m_MnMxSnR.Y2) m_MnMxSnR.Y2 = m_gObj.Extent.Y2;
				}

				SetLayerMaxExtent(m_MnMxSnR);

				m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;
				m_pLayerInfo->listObj.push_back(m_gObj);

				m_nNumOfSnRObject++;

				ClearDataObject(m_gObj);
				m_gObj.nStPnt = m_nNumOfObjCoord;

				m_nObj++;
			}
			m_paramSR.psRepeat = m_nObj;

			(*pFile)++;
			if (**pFile != _T('X'))
			{
				strErrMsg.Format(_T("274X file parsing error: X not found in SR"));
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
			m_paramSR.nXRepeat = ParseIntegerData(&(++(*pFile))); // The number of times the data is repeated along X-axis

			if (**pFile != _T('Y'))
			{
				strErrMsg.Format(_T("274X file parsing error: Y not found in SR"));
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
			m_paramSR.nYRepeat = ParseIntegerData(&(++(*pFile))); // The number of times the data is repeated along Y-axis

			if (**pFile != _T('I'))
			{
				strErrMsg.Format(_T("274X file parsing error: I not found in SR"));
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
			m_fStepX = ParseFloatData(&(++(*pFile))); // The step between the repeats along X-axis
			m_fStepX *= m_fLayerScaleX;

			if (**pFile != _T('J'))
			{
				strErrMsg.Format(_T("274X file parsing error: J not found in SR"));
				AfxMessageBox(strErrMsg);
				m_bLastFrame = TRUE;
				return TRUE;
			}
			m_fStepY = ParseFloatData(&(++(*pFile))); // The step between the repeats along X-axis
			m_fStepY *= m_fLayerScaleY;

			break;

		case _T('S'): // Single Step mode - ignored, vector photoplotter command
			(*pFile)++;
			while (**pFile != EOB) (*pFile)++;
			break;
		default:
			strErrMsg.Format(_T("RS274X parameter block parsing error:S%c"), **pFile);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}
		if (**pFile == EOB)
			(*pFile)++;

		return TRUE;
	}

	return FALSE;
}


BOOL CSimple274X::ApertureDefinition(char** pFile)
{
	TCHAR szTemp[MAX_PATH];
	TCHAR szAMName[MAX_PATH];
	int i, nData;
	CString strErrMsg;
	int nPrimitive, nLength;
	CString strAMContent;
	FRECTC fRect;

	if (**pFile != _T('D'))
	{
		strErrMsg.Format(_T("RS274X parameter block parsing error:AD%c"), *pFile);
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
		return TRUE;
	}
	else
	{
		// fetch numeric code:D-Code
		(*pFile)++;
		i = 0;
		while (_istdigit(**pFile) && i < MAX_PATH)
			szTemp[i++] = *(*pFile)++;
		szTemp[i] = NULL;
		m_nDCode = _ttoi(szTemp);

		if (!CheckDCodeValue(m_nDCode)) // D00, D04-D09 ignore data block
		{
			strErrMsg.Format(_T("RS274X parameter block parsing error: not allowable decode %d"), m_nDCode);
			AfxMessageBox(strErrMsg);
			m_bLastFrame = TRUE;
			return TRUE;
		}

		i = 0;
		while (**pFile != _T(',') && **pFile != EOB && i < MAX_PATH)
			szAMName[i++] = *(*pFile)++;
		szAMName[i] = NULL;

		if (m_pLayerInfo->mapAptList.Lookup(m_nDCode, m_rAptDef))
		{
			POSITION pos;
			pos = m_pLayerInfo->mapAptList.GetStartPosition();
			while (pos != NULL)
			{
				m_pLayerInfo->mapAptList.GetNextAssoc(pos, nData, m_rAptDef);
				if (nData == m_nDCode)
				{
					m_pLayerInfo->mapAptList.RemoveKey(nData);
					break;
				}
			}
		}


		m_pAptDef = new APERTURE_DEF;
		m_pAptDef->Param.clear();

		if (i != 1 || (szAMName[0] != _T('C') && szAMName[0] != _T('R') && szAMName[0] != _T('O') && szAMName[0] != _T('P')))
		{
			m_pAptDef->chStdAptType = NULL;
			m_pAptDef->strAptName = (CString)szAMName;

			// a special aperature described by aperature macro ??? defined previously by an aperature macro
			m_mapAMMacro.Lookup(szAMName, strAMContent);
			if (**pFile == _T(','))
			{
				if (!ParseApertureMacro(&(++(*pFile)), strAMContent))
				{
					strErrMsg.Format(_T("RS274X parameter block parsing error: not allowable Aperture Macro")); // 내용 정리
					AfxMessageBox(strErrMsg);
					m_bLastFrame = TRUE;
					return TRUE;
				}
			}
			else
			{
				while (**pFile == TCHAR(EOB) || **pFile == TCHAR(ASCII_CR) || **pFile == TCHAR(ASCII_LF))
					(*pFile)++; // ignore CR,LF

								// prohibit large memory allocation
				strAMContent.Remove(TCHAR(ASCII_CR)); // ignore CR
				m_nNumOfTextLine += strAMContent.Remove(TCHAR(ASCII_LF)); // ignore LF
			}

			char *pTemp, *pPrevTemp;

#ifdef UNICODE												
			wchar_t *wc;

			wc = strAMContent.GetBuffer(strAMContent.GetLength());
			nLength = WideCharToMultiByte(CP_ACP, 0, wc, -1, NULL, 0, NULL, NULL);

			pPrevTemp = pTemp = new char[nLength];
			int mmmm = strAMContent.GetLength();
			WideCharToMultiByte(CP_ACP, 0, wc, -1, pTemp, nLength, 0, 0);
			strAMContent.ReleaseBuffer();
#else
			pTemp = strAMContent.GetBuffer(strAMContent.GetLength());
			pPrevTemp = pTemp;
#endif
			m_AptPrimi.fParam.clear();
			do {
				nPrimitive = ParseIntegerData(&pTemp);

				switch (nPrimitive)
				{
				case 1: // circle
					ApertureCircle(pTemp);
					break;
				case 2: // line(vector)
				case 20:
					ApertureLineV(pTemp);
					break;
				case 21: // line(center)
					ApertureLineC(pTemp);
					break;
				case 22: // line(lower left)
					ApertureLineL(pTemp);
					break;
				case 4: //  outline
					ApertureOutLine(pTemp);
					break;
				case 5: // polygon
					AperturePolygon(pTemp);
					break;
				case 6: // moire
					ApertureMoire(pTemp);
					break;
				case 7: // thermal
					ApertureThermal(pTemp);
					break;
				default:
					while (*pTemp != EOB && *pTemp != EOF) // unsupported primitive, ignore block
						pTemp++; // ignore to until ','
					;
				}

				if (nPrimitive > 0)
				{
					m_AptPrimi.nPriNum = nPrimitive;
					m_pAptDef->Param.push_back(m_AptPrimi);
					m_AptPrimi.fParam.clear();
				}

				if (*pTemp == TCHAR(EOB))
					pTemp++;

			} while (*pTemp != NULL);// && *pTemp > 0);
#ifdef UNICODE
			delete pPrevTemp;
#endif												
			m_pAptDef->minmax = m_MaxFrameExtent;
			for (i = 0; i < m_pAptDef->Param.size(); i++)
			{
				fRect = m_pAptDef->Param.at(i).minmax;

				if (m_pAptDef->minmax.X1 > fRect.X1) m_pAptDef->minmax.X1 = fRect.X1;
				if (m_pAptDef->minmax.Y1 > fRect.Y1) m_pAptDef->minmax.Y1 = fRect.Y1;
				if (m_pAptDef->minmax.X2 < fRect.X2) m_pAptDef->minmax.X2 = fRect.X2;
				if (m_pAptDef->minmax.Y2 < fRect.Y2) m_pAptDef->minmax.Y2 = fRect.Y2;
			}

			m_pLayerInfo->mapAptList.SetAt(m_nDCode, m_pAptDef);
			m_nNumOfAperture++;

		}
		else
		{
			m_pAptDef->chStdAptType = szAMName[0];
			// fetch aperture type
			switch (szAMName[0])
			{
			case _T('C'):	// circle
				if (FetchApertureCircle(pFile))
					return TRUE;
				break;
			case _T('R'):	// rectangle or square
				if (FetchApertureRect(pFile))
					return TRUE;
				break;
			case _T('O'):	// oval, obround
				if (FetchApertureObround(pFile))
					return TRUE;
				break;
			case _T('P'):	// regular polygon
				if (FetchAperturePolygon(pFile))
					return TRUE;
				break;
			default:
				;
			}

			m_AptPrimi.nPriNum = 0;
			m_pAptDef->minmax = m_AptPrimi.minmax;
			m_pAptDef->Param.push_back(m_AptPrimi);
			m_AptPrimi.fParam.clear();

			m_pLayerInfo->mapAptList.SetAt(m_nDCode, m_pAptDef);
			m_nNumOfAperture++;
		}
		if (**pFile == EOB)
			(*pFile)++;

		return TRUE;
	}

	return FALSE;
}

void CSimple274X::ApertureThermal(char *pTemp)
{
	float fTemp[3], fData, fRotAngle;
	int nData;

	fData = ParseFloatData(&pTemp, TRUE);// $1 X center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE);// $2 Y center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE);// $3 outer diameter 
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE);// $4 inner diameter
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE);// $5 Gap thickness
	m_AptPrimi.fParam.push_back(fData);
	fRotAngle = ParseRotationData(&pTemp, TRUE);// $6 Rotationangle around the origin
	m_AptPrimi.fParam.push_back(fRotAngle);

	fTemp[0] = m_AptPrimi.fParam.at(0);
	fTemp[1] = m_AptPrimi.fParam.at(1);
	fTemp[2] = m_AptPrimi.fParam.at(2);
	fData = fTemp[2] / 2.0;

	m_AptPrimi.minmax.X1 = fTemp[0] - fData;
	m_AptPrimi.minmax.Y1 = fTemp[1] - fData;
	m_AptPrimi.minmax.X2 = fTemp[0] + fData;
	m_AptPrimi.minmax.Y2 = fTemp[1] + fData;
}

void CSimple274X::ApertureMoire(char *pTemp)
{
	float fTemp[8], fData, fRotAngle;
	int nData;

	fData = ParseFloatData(&pTemp, TRUE); // $1 X center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $2 Y center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $3 outer diameter
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $4 ring thickness
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $5 Gap between rings
	m_AptPrimi.fParam.push_back(fData);
	nData = ParseIntegerData(&pTemp, TRUE); // $6 Maximum number of ring
	m_AptPrimi.fParam.push_back((float)nData + 0.1);
	fData = ParseFloatData(&pTemp, TRUE); // $7 Cross hair thickness
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $8 Cross hair length
	m_AptPrimi.fParam.push_back(fData);
	fRotAngle = ParseRotationData(&pTemp, TRUE); // $9 Rotationangle around the origin	
	m_AptPrimi.fParam.push_back(fRotAngle);

	fTemp[0] = m_AptPrimi.fParam.at(0);
	fTemp[1] = m_AptPrimi.fParam.at(1);
	fTemp[2] = m_AptPrimi.fParam.at(2);
	fTemp[7] = m_AptPrimi.fParam.at(7);
	if (fTemp[2] > fTemp[7])
	{
		fData = fTemp[2] / 2.0;
		m_AptPrimi.minmax.X1 = fTemp[0] - fData;
		m_AptPrimi.minmax.Y1 = fTemp[1] - fData;
		m_AptPrimi.minmax.X2 = fTemp[0] + fData;
		m_AptPrimi.minmax.Y2 = fTemp[1] + fData;
	}
	else
	{
		fData = fTemp[7] / 2.0;
		m_AptPrimi.minmax.X1 = fTemp[0] - fData;
		m_AptPrimi.minmax.Y1 = fTemp[1] - fData;
		m_AptPrimi.minmax.X2 = fTemp[0] + fData;
		m_AptPrimi.minmax.Y2 = fTemp[1] + fData;
	}
}

void CSimple274X::AperturePolygon(char *pTemp)
{
	float fTemp[4], fData, fRotAngle;
	int nData;

	m_paramAD.bExposureMode = ParseIntegerData(&pTemp, TRUE);// $1 Exposure on/off toggle
	m_AptPrimi.fParam.push_back((float)m_paramAD.bExposureMode + 0.1);
	nData = ParseIntegerData(&pTemp, TRUE);// $2 Number of sides
	m_AptPrimi.fParam.push_back((float)nData + 0.1);
	fData = ParseFloatData(&pTemp, TRUE);// $3 X center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE);// $4 Y center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE);// $5 outer diamter
	m_AptPrimi.fParam.push_back(fData);
	fRotAngle = ParseRotationData(&pTemp, TRUE);// $6 Rotationangle around the origin
	m_AptPrimi.fParam.push_back(fRotAngle);

	fTemp[2] = m_AptPrimi.fParam.at(2);
	fTemp[3] = m_AptPrimi.fParam.at(3);
	fData = m_AptPrimi.fParam.at(4) / 2.0;

	m_AptPrimi.minmax.X1 = fTemp[2] - fData;
	m_AptPrimi.minmax.Y1 = fTemp[3] - fData;
	m_AptPrimi.minmax.X2 = fTemp[2] + fData;
	m_AptPrimi.minmax.Y2 = fTemp[3] + fData;
}

void CSimple274X::ApertureOutLine(char *pTemp)
{
	int nNumOfSbusequentPoint, i;
	float fData, fRotAngle, cV, sV, xR;
	FPOINTC fptPos;

	m_paramAD.bExposureMode = ParseIntegerData(&pTemp, TRUE);// $1 Exposure on/off toggle
	m_AptPrimi.fParam.push_back((float)m_paramAD.bExposureMode + 0.1);
	nNumOfSbusequentPoint = ParseIntegerData(&pTemp, TRUE); // $2 Num Of Sbusequent Point
	m_AptPrimi.fParam.push_back((float)nNumOfSbusequentPoint*2.0 + 0.1);

	m_AptPrimi.minmax = m_MaxFrameExtent;
	for (i = 0; i < nNumOfSbusequentPoint * 2; i++)
	{
		fData = ParseFloatData(&pTemp, TRUE);
		m_AptPrimi.fParam.push_back(fData);

		if (i % 2 == 0)
		{
			if (m_AptPrimi.minmax.X1 > fData)	m_AptPrimi.minmax.X1 = fData;
			if (m_AptPrimi.minmax.X2 < fData)	m_AptPrimi.minmax.X2 = fData;
		}
		else
		{
			if (m_AptPrimi.minmax.Y1 > fData)	m_AptPrimi.minmax.Y1 = fData;
			if (m_AptPrimi.minmax.Y2 < fData)	m_AptPrimi.minmax.Y2 = fData;
		}
	}

	fData = ParseFloatData(&pTemp, TRUE);		// Dummy Data Start Point
	fData = ParseFloatData(&pTemp, TRUE);		// Dummy Data Start Point

	fRotAngle = ParseRotationData(&pTemp, TRUE);
	m_AptPrimi.fParam.push_back(fRotAngle);

	if (fRotAngle != 0)
	{
		m_AptPrimi.minmax = m_MaxFrameExtent;

		GetCosineSineValue(fRotAngle, &cV, &sV);
		for (i = 2; i <= nNumOfSbusequentPoint * 2; i += 2)
		{

			xR = m_AptPrimi.fParam.at(i);
			fptPos.y = m_AptPrimi.fParam.at(i + 1);

			fptPos.x = (xR * cV) - (fptPos.y * sV);
			fptPos.y = (xR * sV) + (fptPos.y * cV);

			if (m_AptPrimi.minmax.X1 > fptPos.x)	m_AptPrimi.minmax.X1 = fptPos.x;
			if (m_AptPrimi.minmax.Y1 > fptPos.y)	m_AptPrimi.minmax.Y1 = fptPos.y;
			if (m_AptPrimi.minmax.X2 < fptPos.x)	m_AptPrimi.minmax.X2 = fptPos.x;
			if (m_AptPrimi.minmax.Y2 < fptPos.y)	m_AptPrimi.minmax.Y2 = fptPos.y;

			m_AptPrimi.fParam.at(i) = fptPos.x;
			m_AptPrimi.fParam.at(i + 1) = fptPos.y;
		}
	}
}

void CSimple274X::ApertureLineL(char *pTemp)
{
	float fData, fRotAngle;
	float fTemp[5];

	m_paramAD.bExposureMode = ParseIntegerData(&pTemp, TRUE);// $1 Exposure on/off toggle
	m_AptPrimi.fParam.push_back((float)m_paramAD.bExposureMode + 0.1);
	fData = ParseFloatData(&pTemp, TRUE); // $2 width
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $3 height
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $4 X lower left point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $5 Y lower left point
	m_AptPrimi.fParam.push_back(fData);
	fRotAngle = ParseRotationData(&pTemp, TRUE); // $6 Rotationangle around the origin	
	m_AptPrimi.fParam.push_back(fRotAngle);

	if (m_AptPrimi.fParam.at(5) == 0)
	{
		fTemp[1] = m_AptPrimi.fParam.at(1);
		fTemp[2] = m_AptPrimi.fParam.at(2);
		fTemp[3] = m_AptPrimi.fParam.at(3);
		fTemp[4] = m_AptPrimi.fParam.at(4);

		m_AptPrimi.minmax.X1 = fTemp[3];
		m_AptPrimi.minmax.Y1 = fTemp[4];
		m_AptPrimi.minmax.X2 = fTemp[3] + fTemp[1];
		m_AptPrimi.minmax.Y2 = fTemp[4] + fTemp[2];
	}
	else
	{
		m_AptPrimi.minmax = MinMaxRectLowerLeftGRB(m_AptPrimi.fParam.at(3), m_AptPrimi.fParam.at(4), m_AptPrimi.fParam.at(1), m_AptPrimi.fParam.at(2), m_AptPrimi.fParam.at(5));
	}
}

void CSimple274X::ApertureLineC(char *pTemp)
{
	float fData, fRotAngle;
	float fTemp[5];

	m_paramAD.bExposureMode = ParseIntegerData(&pTemp, TRUE);// $1 Exposure on/off toggle
	m_AptPrimi.fParam.push_back((float)m_paramAD.bExposureMode + 0.1);
	fData = ParseFloatData(&pTemp, TRUE); // $2 rectangle width
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $3 rectangle height
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $4 X center point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $5 Y center point
	m_AptPrimi.fParam.push_back(fData);
	fRotAngle = ParseRotationData(&pTemp, TRUE); // $6 Rotationangle around the origin
	m_AptPrimi.fParam.push_back(fRotAngle);

	if (m_AptPrimi.fParam.at(5) == 0)
	{
		fTemp[1] = m_AptPrimi.fParam.at(1) / 2.0;
		fTemp[2] = m_AptPrimi.fParam.at(2) / 2.0;
		fTemp[3] = m_AptPrimi.fParam.at(3);
		fTemp[4] = m_AptPrimi.fParam.at(4);

		m_AptPrimi.minmax.X1 = fTemp[3] - fTemp[1];
		m_AptPrimi.minmax.Y1 = fTemp[4] - fTemp[2];
		m_AptPrimi.minmax.X2 = fTemp[3] + fTemp[1];
		m_AptPrimi.minmax.Y2 = fTemp[4] + fTemp[2];
	}
	else
	{
		m_AptPrimi.minmax = MinMaxRectCenterGRB(m_AptPrimi.fParam.at(3), m_AptPrimi.fParam.at(4), m_AptPrimi.fParam.at(1), m_AptPrimi.fParam.at(2), m_AptPrimi.fParam.at(5));
	}
}

void CSimple274X::ApertureLineV(char *pTemp)
{
	float fData, fRotAngle;

	m_paramAD.bExposureMode = ParseIntegerData(&pTemp, TRUE);// $1 Exposure on/off toggle
	m_AptPrimi.fParam.push_back((float)m_paramAD.bExposureMode + 0.1);
	fData = ParseFloatData(&pTemp, TRUE); // $2 line width
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $3 X start point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $4 Y start point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $5 X end point
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $6 Y end point
	m_AptPrimi.fParam.push_back(fData);
	fRotAngle = ParseRotationData(&pTemp, TRUE); // Rotationangle around the origin
	m_AptPrimi.fParam.push_back(fRotAngle);

	m_AptPrimi.minmax = MinMaxRectVectorGRB(m_AptPrimi.fParam.at(2), m_AptPrimi.fParam.at(3), m_AptPrimi.fParam.at(4), m_AptPrimi.fParam.at(5), m_AptPrimi.fParam.at(1), m_AptPrimi.fParam.at(6));
}

void CSimple274X::ApertureCircle(char *pTemp)
{
	float fData;
	float fTemp[4];

	// $1 Exposure on/off toggle
	m_paramAD.bExposureMode = ParseIntegerData(&pTemp, TRUE);// $1 Exposure on/off toggle
	m_AptPrimi.fParam.push_back((float)m_paramAD.bExposureMode + 0.1);
	fData = ParseFloatData(&pTemp, TRUE); // $2 diameter
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $3 X center position
	m_AptPrimi.fParam.push_back(fData);
	fData = ParseFloatData(&pTemp, TRUE); // $4 Y center position
	m_AptPrimi.fParam.push_back(fData);

	fTemp[2] = m_AptPrimi.fParam.at(2);
	fTemp[3] = m_AptPrimi.fParam.at(3);
	fData = m_AptPrimi.fParam.at(1) / 2.0;
	m_AptPrimi.minmax.X1 = fTemp[2] - fData;
	m_AptPrimi.minmax.Y1 = fTemp[3] - fData;
	m_AptPrimi.minmax.X2 = fTemp[2] + fData;
	m_AptPrimi.minmax.Y2 = fTemp[3] + fData;
}


BOOL CSimple274X::FetchAperturePolygon(char** pFile)
{
	float fData;
	int nData;
	CString strErrMsg;

	(*pFile)++;
	fData = ParseFloatData(&(*pFile)); //outer diameter
	m_AptPrimi.fParam.push_back(fData);
	if (**pFile != _T('X'))
	{
		strErrMsg.Format(_T("RS274X parameter block parsing error:AD P,%c"), **pFile);
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
		return TRUE;
	}
	else
	{
		nData = ParseIntegerData(&(++(*pFile))); // number of sides
		m_AptPrimi.fParam.push_back((float)nData);
		if (**pFile == _T('X'))
		{
			fData = ParseFloatData(&(++(*pFile))); // degree of rotation
			m_AptPrimi.fParam.push_back(fData);
			if (**pFile == _T('X'))
			{
				fData = ParseFloatData(&(++(*pFile))); // X-axis hole diameter
				m_AptPrimi.fParam.push_back(fData);
				if (**pFile == _T('X'))
				{
					fData = ParseFloatData(&(++(*pFile))); // Y-axis hole diameter
					m_AptPrimi.fParam.push_back(fData);
				}
			}
		}
	}

	if (m_AptPrimi.fParam.size() < 3)
		m_AptPrimi.fParam.push_back(0.0);

	fData = m_AptPrimi.fParam.at(0) / 2.0;

	m_AptPrimi.minmax.X1 = -fData;
	m_AptPrimi.minmax.Y1 = -fData;
	m_AptPrimi.minmax.X2 = fData;
	m_AptPrimi.minmax.Y2 = fData;

	return FALSE;
}

BOOL CSimple274X::FetchApertureObround(char** pFile)
{
	float fData;
	float fTemp[2];
	CString strErrMsg;

	(*pFile)++;
	fData = ParseFloatData(&(*pFile)); // X-axis dimension
	m_AptPrimi.fParam.push_back(fData);
	if (**pFile != _T('X'))
	{
		strErrMsg.Format(_T("RS274X parameter block parsing error:AD O,%c"), **pFile);
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
		return TRUE;
	}
	else
	{
		fData = ParseFloatData(&(++(*pFile))); // Y-axis dimension
		m_AptPrimi.fParam.push_back(fData);
		if (**pFile == _T('X'))
		{
			fData = ParseFloatData(&(++(*pFile))); // round hole dimension
			m_AptPrimi.fParam.push_back(fData);
			if (**pFile == _T('X'))
			{
				fData = ParseFloatData(&(++(*pFile))); // rectanle hole dimension
				m_AptPrimi.fParam.push_back(fData);
			}
		}
	}

	fTemp[0] = m_AptPrimi.fParam.at(0) / 2.0;
	fTemp[1] = m_AptPrimi.fParam.at(1) / 2.0;

	m_AptPrimi.minmax.X1 = -fTemp[0];
	m_AptPrimi.minmax.Y1 = -fTemp[1];
	m_AptPrimi.minmax.X2 = fTemp[0];
	m_AptPrimi.minmax.Y2 = fTemp[1];

	return FALSE;
}

BOOL CSimple274X::FetchApertureRect(char** pFile)
{
	float fData;
	float fTemp[2];
	CString strErrMsg;

	(*pFile)++;
	fData = ParseFloatData(&(*pFile)); // X-axis dimension
	m_AptPrimi.fParam.push_back(fData);
	if (**pFile != _T('X'))
	{
		strErrMsg.Format(_T("RS274X parameter block parsing error:AD R,%c"), **pFile);
		AfxMessageBox(strErrMsg);
		m_bLastFrame = TRUE;
		return TRUE;
	}
	else
	{
		fData = ParseFloatData(&(++(*pFile))); // Y-axis dimension
		m_AptPrimi.fParam.push_back(fData);
		if (**pFile == _T('X'))
		{
			fData = ParseFloatData(&(++(*pFile))); // round hole dimension
			m_AptPrimi.fParam.push_back(fData);
			if (**pFile == _T('X'))
			{
				fData = ParseFloatData(&(++(*pFile))); // rectanle hole dimension
				m_AptPrimi.fParam.push_back(fData);
			}
		}
	}
	fTemp[0] = m_AptPrimi.fParam.at(0) / 2.0;
	fTemp[1] = m_AptPrimi.fParam.at(1) / 2.0;
	m_AptPrimi.minmax.X1 = -fTemp[0];
	m_AptPrimi.minmax.Y1 = -fTemp[1];
	m_AptPrimi.minmax.X2 = fTemp[0];
	m_AptPrimi.minmax.Y2 = fTemp[1];

	return FALSE;
}

BOOL CSimple274X::FetchApertureCircle(char** pFile)
{
	float fData;

	(*pFile)++;
	fData = ParseFloatData(&(*pFile)); // radius
	m_AptPrimi.fParam.push_back(fData);
	if (**pFile == _T('X'))
	{
		fData = ParseFloatData(&(++(*pFile))); // round hole dimension
		m_AptPrimi.fParam.push_back(fData);

		if (**pFile == _T('X'))
		{
			fData = ParseFloatData(&(++(*pFile))); // round hole dimension
			m_AptPrimi.fParam.push_back(fData);
		}
	}
	fData = m_AptPrimi.fParam.at(0) / 2.0;
	m_AptPrimi.minmax.X1 = -fData;
	m_AptPrimi.minmax.Y1 = -fData;
	m_AptPrimi.minmax.X2 = fData;
	m_AptPrimi.minmax.Y2 = fData;

	return FALSE;
}


float CSimple274X::ParseScaleData(char **pFile, BOOL bArithmetic)
{
	TCHAR szData[MAX_PATH];
	int nIndex, nNumOfData;
	float fData = 1.0;
	nNumOfData = 0;
	nIndex = 0;

	// signed bit 
	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}

	while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}
	szData[nIndex] = NULL;
	nNumOfData++;

	if (bArithmetic)
	{
		while (CheckArithmeticOperator(**pFile))
		{
			if (**pFile == _T('X'))
				szData[nIndex++] = _T('*');
			else
				szData[nIndex++] = **pFile;
			(*pFile)++;

			while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
			{
				szData[nIndex++] = **pFile;
				(*pFile)++;
			}


			szData[nIndex] = NULL;
			nNumOfData++;
		}
	}

	if (nNumOfData == 1)
		fData = _tcstod(szData, NULL);
	else
		fData = m_PostfixCalc.Calc(szData);

	if (**pFile == _T(','))
		(*pFile)++;


	return fData;
}

float CSimple274X::ParseFloatData(char **pFile, BOOL bArithmetic)
{
	TCHAR szData[MAX_PATH];
	int nIndex, nNumOfData;
	float fData = 0.0;
	nNumOfData = 0;
	nIndex = 0;

	// signed bit 
	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}

	while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}
	szData[nIndex] = NULL;
	nNumOfData++;

	if (bArithmetic)
	{
		while (CheckArithmeticOperator(**pFile))
		{
			if (**pFile == _T('X'))
				szData[nIndex++] = _T('*');
			else
				szData[nIndex++] = **pFile;
			(*pFile)++;

			while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
			{
				szData[nIndex++] = **pFile;
				(*pFile)++;
			}


			szData[nIndex] = NULL;
			nNumOfData++;
		}
	}

	if (nNumOfData == 1)
		fData = _tcstod(szData, NULL);
	else
		fData = m_PostfixCalc.Calc(szData);
	if (m_Unit == LAYER_TYPE::INCH)
		fData *= INCHTOMM;

	if (**pFile == _T(','))
		(*pFile)++;


	return fData;
}

int	CSimple274X::ParseIntegerData(char **pFile, BOOL bArithmetic)
{
	TCHAR szData[MAX_PATH];
	float fData = 0.0;
	int nData = 0;
	int nIndex, nNumOfData;

	nNumOfData = 0;
	nIndex = 0;

	nNumOfData = 0;
	nIndex = 0;

	// signed bit 
	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}

	while (_istdigit(**pFile) && nIndex < MAX_PATH)
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}
	szData[nIndex] = NULL;
	nNumOfData++;

	if (bArithmetic)
	{
		while (CheckArithmeticOperator(**pFile))
		{
			if (**pFile == _T('X'))
				szData[nIndex++] = _T('*');
			else
				szData[nIndex++] = **pFile;
			(*pFile)++;


			while (_istdigit(**pFile) || **pFile == _T('.'))
			{
				szData[nIndex++] = **pFile;
				(*pFile)++;
			}


			szData[nIndex] = NULL;
			nNumOfData++;
		}
	}

	if (nNumOfData == 1)
		nData = _ttoi(szData);
	else
		nData = m_PostfixCalc.Calc(szData);

	if (**pFile == _T(','))
		(*pFile)++;

	return nData;
}

float CSimple274X::ParseRotationData(char **pFile, BOOL bArithmetic)
{
	TCHAR szData[MAX_PATH];
	int nIndex, nNumOfData;
	float fData = 0.0;
	nNumOfData = 0;
	nIndex = 0;

	// signed bit 
	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}

	while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}
	szData[nIndex] = NULL;
	nNumOfData++;

	if (bArithmetic)
	{
		while (CheckArithmeticOperator(**pFile))
		{
			if (**pFile == _T('X'))
				szData[nIndex++] = _T('*');
			else
				szData[nIndex++] = **pFile;
			(*pFile)++;

			while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
			{
				szData[nIndex++] = **pFile;
				(*pFile)++;
			}


			szData[nIndex] = NULL;
			nNumOfData++;
		}
	}

	if (nNumOfData == 1)
		fData = _tcstod(szData, NULL);
	else
		fData = m_PostfixCalc.Calc(szData);

	if (**pFile == _T(','))
		(*pFile)++;

	return fData;
}

BOOL CSimple274X::ParseApertureMacro(char **pFile, CString &strApertureMacro)
{
	int i;
	int nIndex;
	TCHAR szData[MAX_PATH];

	i = 0;
	nIndex = 0;

	char *pLine = *pFile;

	CStringArray Param;
	while (**pFile != _T('*'))
	{
		nIndex = 0;
		while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
		{
			szData[nIndex++] = **pFile;
			(*pFile)++;
			i++;
		}
		szData[nIndex] = NULL;
		Param.Add((CString)szData);
		if (**pFile == _T('X'))
			(*pFile)++;
		i++;
	}


	char ch;
	CString strParser;
	CString strData;

	TCHAR *szTemp;
	TCHAR *pszContents;


	strApertureMacro.Remove(TCHAR(ASCII_CR)); // ignore CR
	strApertureMacro.Remove(TCHAR(ASCII_LF)); // ignore LF

	szTemp = strParser.GetBuffer(i + strApertureMacro.GetLength() + MAX_PATH);
	pszContents = strApertureMacro.GetBuffer(strApertureMacro.GetLength() + MAX_PATH);

	// preprocessing for ignore primitive '0'
	while (*pszContents == _T('0'))
	{
		pszContents++;
		while (*pszContents != TCHAR(EOB))
			pszContents++;
		pszContents++;
	}

	do
	{
		ch = *pszContents;
		switch (ch)
		{
		case TCHAR(EOB):
			*szTemp++ = *pszContents++;
			while (*pszContents == _T('0'))
			{
				pszContents++;
				while (*pszContents != TCHAR(EOB))
					pszContents++;
			}
			break;
		case _T('$'):
			pszContents++;
			i = 0;
			do {
				ch = *pszContents++;
				szData[i++] = ch;
			} while (_istdigit(ch));
			szData[i] = NULL;

			nIndex = _ttoi(szData);

			if (nIndex <= Param.GetSize())
			{
				strData = Param.GetAt(nIndex - 1);

				_tcsncpy(szTemp, strData, strData.GetLength());
				szTemp += strData.GetLength();

				*szTemp++ = ch;
			}
			else
			{
				if (ch == _T('='))
				{
					CString strTemp;
					int nIndexSub;
					float fData;
					strTemp.Empty();

					for (i = Param.GetSize(); i < nIndex; i++)
						Param.Add(_T("0"));

					while (*pszContents != _T('*'))
					{
						if (*pszContents == _T('$'))
						{
							pszContents++;

							i = 0;
							do {
								ch = *pszContents;
								if (_istdigit(ch))
								{
									szData[i++] = ch;
									pszContents++;
								}
								else
									break;
							} while (1);
							szData[i] = NULL;

							nIndexSub = _ttoi(szData);
							if (nIndexSub <= Param.GetSize())
							{
								strTemp += Param.GetAt(nIndexSub - 1);
							}
							else
							{
								AfxMessageBox(_T("Aperture Macro Error"));
								return FALSE;
							}
						}
						else
						{
							strTemp += *pszContents++;
						}
					}
					pszContents++;
					fData = m_PostfixCalc.Calc(strTemp);
					strTemp.Format(_T("%f"), fData);
					Param.SetAt(nIndex - 1, strTemp);

				}
				else
				{
					AfxMessageBox(_T("Aperture Macro Error"));
					return FALSE;
				}
			}
			break;
		default:
			*szTemp++ = *pszContents++;
		}
	} while (ch != NULL);

	*szTemp = NULL;
	strApertureMacro.GetBuffer(strParser.GetLength() + 1);
	strApertureMacro.Format(_T("%s"), strParser);
	return TRUE;
}


FRECTC CSimple274X::MinMaxArcInPolygonGRB(DRAW_TYPE::TYPE dType, FPOINTC P1, FPOINTC P2, FPOINTC PC)
{
	FRECTC r;
	double R, vX1, vX2, vY1, vY2, vK, vD, Ang1, Ang2;

	//'dType:  cW:m_pTrUtil->m_bType(2), ccW:m_pTrUtil->m_bType(3)

	if (P1.x < P2.x)
	{
		r.X1 = P1.x;
		r.X2 = P2.x;
	}
	else
	{
		r.X1 = P2.x;
		r.X2 = P1.x;
	}

	if (P1.y < P2.y)
	{
		r.Y1 = P1.y;
		r.Y2 = P2.y;
	}
	else
	{
		r.Y1 = P2.y;
		r.Y2 = P1.y;
	}

	R = sqrt((P1.x - PC.x) * (P1.x - PC.x) + (P1.y - PC.y) * (P1.y - PC.y));

	vX1 = P1.x - PC.x;
	vY1 = P1.y - PC.y;
	vX2 = P2.x - PC.x;
	vY2 = P2.y - PC.y;
	vK = (vX1 * vY2) - (vY1 * vX2);
	vD = (vX1 * vX2) + (vY1 * vY2);

	if (fabs(vK) < m_dDetZero && vD > 0)
	{
		r.X1 = PC.x - R; // '+ CurMinMax.X1
		r.X2 = PC.x + R; //  '+ CurMinMax.X2
		r.Y1 = PC.y - R; //  '+ CurMinMax.Y1
		r.Y2 = PC.y + R; //  '+ CurMinMax.Y2

		return r;
	}

	if (fabs((P1.x - PC.x)) < m_dDetZero)
	{
		if (P1.y > PC.y)
			Ang1 = PI * 0.5; //  '90도
		else
			Ang1 = PI * 1.5; //  '270도
	}
	else if (fabs((P1.y - PC.y)) < m_dDetZero)
	{
		if (P1.x > PC.x)
			Ang1 = 0; //         '0도
		else
			Ang1 = PI; //        '180도
	}
	else
	{
		Ang1 = atan((P1.y - PC.y) / (P1.x - PC.x));
		if (Ang1 > 0)
		{
			if (P1.x < PC.x) Ang1 = Ang1 + PI; //     ' 3사분면
		}
		else
		{
			if (P1.x < PC.x)
				Ang1 = Ang1 + PI; //     ' 2사분면
			else
				Ang1 = Ang1 + PI + PI; //    ' 4사분면
		}
	}

	if (fabs((P2.x - PC.x)) < m_dDetZero)
	{
		if (P2.y > PC.y)
			Ang2 = PI * 0.5; //  '90도
		else
			Ang2 = PI * 1.5; //  '270도
	}
	else if (fabs((P2.y - PC.y)) < m_dDetZero)
	{
		if (P2.x > PC.x)
			Ang2 = 0; //         '0도
		else
			Ang2 = PI; //        '180도
	}
	else
	{
		Ang2 = atan((P2.y - PC.y) / (P2.x - PC.x));
		if (Ang2 > 0)
		{
			if (P2.x < PC.x) Ang2 = Ang2 + PI; //     ' 3사분면
		}
		else
		{
			if (P2.x < PC.x)
				Ang2 = Ang2 + PI; //     ' 2사분면
			else
				Ang2 = Ang2 + PI + PI; //    ' 4사분면
		}
	}

	if (CheckAngleGRB(0.5 * PI, Ang1, Ang2, dType)) r.Y2 = PC.y + R;
	if (CheckAngleGRB(PI, Ang1, Ang2, dType)) r.X1 = PC.x - R;
	if (CheckAngleGRB(1.5 * PI, Ang1, Ang2, dType)) r.Y1 = PC.y - R;
	if (CheckAngleGRB(0, Ang1, Ang2, dType)) r.X2 = PC.x + R;


	//    r.X1 = r.X1 '+ CurMinMax.X1
	//    r.X2 = r.X2 '+ CurMinMax.X2
	//    r.Y1 = r.Y1 '+ CurMinMax.Y1
	//    r.Y2 = r.Y2 '+ CurMinMax.Y2

	return r;
}

FRECTC CSimple274X::MinMaxArcGRB(DRAW_TYPE::TYPE dType, FPOINTC P1, FPOINTC P2, FPOINTC PC, FRECTC CurMinMax)
{
	FRECTC r;

	double R, vX1, vX2, vY1, vY2, vK, vD, Ang1, Ang2;

	if (P1.x < P2.x)
	{
		r.X1 = P1.x;
		r.X2 = P2.x;
	}
	else
	{
		r.X1 = P2.x;
		r.X2 = P1.x;
	}

	if (P1.y < P2.y)
	{
		r.Y1 = P1.y;
		r.Y2 = P2.y;
	}
	else
	{
		r.Y1 = P2.y;
		r.Y2 = P1.y;
	}

	R = sqrt((P1.x - PC.x) * (P1.x - PC.x) + (P1.y - PC.y) * (P1.y - PC.y));

	vX1 = P1.x - PC.x;
	vY1 = P1.y - PC.y;
	vX2 = P2.x - PC.x;
	vY2 = P2.y - PC.y;
	vK = (vX1 * vY2) - (vY1 * vX2);
	vD = (vX1 * vX2) + (vY1 * vY2);

	if (fabs(vK) < m_dDetZero && vD > 0)
	{
		r.X1 = PC.x - R + CurMinMax.X1;
		r.X2 = PC.x + R + CurMinMax.X2;
		r.Y1 = PC.y - R + CurMinMax.Y1;
		r.Y2 = PC.y + R + CurMinMax.Y2;

		return r;
	}

	if (fabs((P1.x - PC.x)) < m_dDetZero)
	{
		if (P1.y > PC.y)
			Ang1 = PI * 0.5;	// '90도
		else
			Ang1 = PI * 1.5;	// '270도
	}
	else if (fabs((P1.y - PC.y)) < m_dDetZero)
	{
		if (P1.x > PC.x)
			Ang1 = 0;	//        '0도
		else
			Ang1 = PI;	//       '180도
	}
	else
	{
		Ang1 = atan((P1.y - PC.y) / (P1.x - PC.x));
		if (Ang1 > 0)
		{
			if (P1.x < PC.x) Ang1 = Ang1 + PI;	//    ' 3사분면
		}
		else
		{
			if (P1.x < PC.x)
				Ang1 = Ang1 + PI; //    ' 2사분면
			else
				Ang1 = Ang1 + PI + PI; //   ' 4사분면
		}
	}

	if (fabs((P2.x - PC.x)) < m_dDetZero)
	{
		if (P2.y > PC.y)
			Ang2 = PI * 0.5; // '90도
		else
			Ang2 = PI * 1.5; // '270도
	}
	else if (fabs((P2.y - PC.y)) < m_dDetZero)
	{
		if (P2.x > PC.x)
			Ang2 = 0; //        '0도
		else
			Ang2 = PI; //       '180도
	}
	else
	{
		Ang2 = atan((P2.y - PC.y) / (P2.x - PC.x));
		if (Ang2 > 0)
		{
			if (P2.x < PC.x) Ang2 = Ang2 + PI; //    ' 3사분면
		}
		else
		{
			if (P2.x < PC.x)
				Ang2 = Ang2 + PI; //    ' 2사분면
			else
				Ang2 = Ang2 + PI + PI; //   ' 4사분면
		}
	}

	if (CheckAngleGRB(0.5 * PI, Ang1, Ang2, dType)) r.Y2 = PC.y + R;
	if (CheckAngleGRB(PI, Ang1, Ang2, dType)) r.X1 = PC.x - R;
	if (CheckAngleGRB(1.5 * PI, Ang1, Ang2, dType)) r.Y1 = PC.y - R;
	if (CheckAngleGRB(0, Ang1, Ang2, dType)) r.X2 = PC.x + R;

	r.X1 = r.X1 + CurMinMax.X1;
	r.X2 = r.X2 + CurMinMax.X2;
	r.Y1 = r.Y1 + CurMinMax.Y1;
	r.Y2 = r.Y2 + CurMinMax.Y2;

	return r;
}

FRECTC CSimple274X::MinMaxRectVectorGRB(double X1, double Y1, double X2, double Y2, double w, double ang)
{
	FPOINTC pp[4], cp;
	double cV, sV, tX, tY, hh, ww, d;
	FRECTC rect = m_MaxFrameExtent;

	cV = cos(ang * DEG2RAD);
	sV = sin(ang * DEG2RAD);

	pp[0].x = X1;
	pp[0].y = Y1;
	pp[1].x = X2;
	pp[1].y = Y2;

	X1 = (pp[0].x * cV) - (pp[0].y * sV);
	Y1 = (pp[0].x * sV) + (pp[0].y * cV);
	X2 = (pp[1].x * cV) - (pp[1].y * sV);
	Y2 = (pp[1].x * sV) + (pp[1].y * cV);

	d = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));

	hh = Y2 - Y1;
	ww = X2 - X1;
	tY = w / 2 * ww / d;
	tX = w / 2 * hh / d;

	pp[0].x = X1 + tX;
	pp[0].y = Y1 - tY;
	pp[1].x = X2 + tX;
	pp[1].y = Y2 - tY;
	pp[2].x = X2 - tX;
	pp[2].y = Y2 + tY;
	pp[3].x = X1 - tX;
	pp[3].y = Y1 + tY;

	for (int i = 0; i < 4; i++)
	{
		AdjustExtentByPoint(rect, pp[i]);
	}
	return rect;
}

FRECTC CSimple274X::MinMaxRectLowerLeftGRB(double x, double y, double w, double h, double ang)
{
	FPOINTC pp[4], cp;
	double cV, sV, XX, YY;
	FRECTC rect;

	cp.x = x + w / 2;
	cp.y = y + h / 2;

	rect = m_MaxFrameExtent;

	if (ang != 0)
	{
		cV = cos(ang * DEG2RAD);
		sV = sin(ang * DEG2RAD);

		XX = -w / 2;
		YY = -h / 2;
		pp[0].x = (XX * cV) - (YY * sV) + cp.x;
		pp[0].y = (XX * sV) + (YY * cV) + cp.y;
		//        '우하
		XX = w / 2;
		YY = -h / 2;
		pp[1].x = (XX * cV) - (YY * sV) + cp.x;
		pp[1].y = (XX * sV) + (YY * cV) + cp.y;
		//        '우상
		XX = w / 2;
		YY = h / 2;
		pp[2].x = (XX * cV) - (YY * sV) + cp.x;
		pp[2].y = (XX * sV) + (YY * cV) + cp.y;
		//        '좌상
		XX = -w / 2;
		YY = h / 2;
		pp[3].x = (XX * cV) - (YY * sV) + cp.x;
		pp[3].y = (XX * sV) + (YY * cV) + cp.y;

		for (int i = 0; i < 4; i++)
		{
			AdjustExtentByPoint(rect, pp[i]);
		}
	}
	else
	{
		rect.X1 = x;
		rect.X2 = x + w;
		rect.Y1 = y;
		rect.Y2 = y + h;
	}
	return rect;

}

FRECTC CSimple274X::MinMaxRectCenterGRB(double x, double y, double w, double h, double ang)
{
	FPOINTC pp[4], cp;
	double cV, sV, XX, YY;
	FRECTC r;

	r = m_MaxFrameExtent;

	cV = cos(ang * DEG2RAD);
	sV = sin(ang * DEG2RAD);

	//    '좌하
	XX = -w / 2;
	YY = -h / 2;
	pp[0].x = (XX * cV) - (YY * sV) + x;
	pp[0].y = (XX * sV) + (YY * cV) + y;
	//    '우하
	XX = w / 2;
	YY = -h / 2;
	pp[1].x = (XX * cV) - (YY * sV) + x;
	pp[1].y = (XX * sV) + (YY * cV) + y;
	//    '우상
	XX = w / 2;
	YY = h / 2;
	pp[2].x = (XX * cV) - (YY * sV) + x;
	pp[2].y = (XX * sV) + (YY * cV) + y;
	//    '좌상
	XX = -w / 2;
	YY = h / 2;
	pp[3].x = (XX * cV) - (YY * sV) + x;
	pp[3].y = (XX * sV) + (YY * cV) + y;

	for (int i = 0; i < 4; i++)
	{
		AdjustExtentByPoint(r, pp[i]);
	}
	return r;
}

BOOL CSimple274X::CheckPointInRect(FRECTC &fRect, float x, float y)
{
	if (fRect.X1 <= x && x <= fRect.X2 && fRect.Y1 <= y && y <= fRect.Y2)
		return TRUE;
	else
		return FALSE;
}

BOOL CSimple274X::CheckAngleGRB(double AngP, double Ang1, double Ang2, DRAW_TYPE::TYPE dType)
{
	BOOL rFlag = TRUE;

	if (Ang1 > Ang2)
	{
		if (dType == DRAW_TYPE::ARC_CCW)    //ccW
		{
			if (AngP < Ang1 && AngP > Ang2)
				rFlag = FALSE;
		}
		else
		{
			if (AngP > Ang1 || AngP < Ang2)
				rFlag = FALSE;
		}
	}
	else
	{
		if (dType == DRAW_TYPE::ARC_CCW)
		{
			if (AngP < Ang1 || AngP > Ang2)
				rFlag = FALSE;
		}
		else
		{
			if (AngP > Ang1 && AngP < Ang2)
				rFlag = FALSE;
		}
	}

	return(rFlag);
}

BOOL CSimple274X::CheckArithmeticOperator(char ch)
{
	if (ch == _T('+') || ch == _T('-') || ch == _T('/') || ch == _T('X') || ch == _T('='))
		return TRUE;
	return FALSE;
}

BOOL CSimple274X::CheckGCodeValue(int nGCode)
{
	switch (nGCode)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 36:
	case 37:
	case 54:
	case 70:
	case 71:
	case 74:
	case 75:
	case 90:
	case 91:
		return TRUE;
	}
	return FALSE;
}

BOOL CSimple274X::CheckDCodeValue(int nDCode)
{
	if (nDCode < 1 || (nDCode > 3 && nDCode < 10)) // D00, D04-D09 ignore data block
		return FALSE;
	return TRUE;
}

BOOL CSimple274X::CheckMCodeValue(int nMCode)
{
	if (nMCode < 0 || nMCode > 2) // allowable M-Coce M00, M01, M03 
		return FALSE;
	return TRUE;
}


void CSimple274X::AdjustExtentByPoint(FRECTC &Extent, const FPOINTC &pt)
{
	if (pt.x < Extent.X1)
		Extent.X1 = pt.x;
	if (pt.y < Extent.Y1)
		Extent.Y1 = pt.y;
	if (pt.x > Extent.X2)
		Extent.X2 = pt.x;
	if (pt.y > Extent.Y2)
		Extent.Y2 = pt.y;
}

void CSimple274X::AdjustExtentByRect(FRECTC &Extent, const FRECTC &rect)
{
	if (Extent.X1 > rect.X1)
		Extent.X1 = rect.X1;
	if (Extent.X2 < rect.X2)
		Extent.X2 = rect.X2;
	if (Extent.Y1 > rect.Y1)
		Extent.Y1 = rect.Y1;
	if (Extent.Y2 < rect.Y2)
		Extent.Y2 = rect.Y2;
}


void CSimple274X::SetLayerMaxExtent(FRECTC &rect)
{
	if (m_rectLayerExtent.X1 > rect.X1)
		m_rectLayerExtent.X1 = rect.X1;
	if (m_rectLayerExtent.X2 < rect.X2)
		m_rectLayerExtent.X2 = rect.X2;
	if (m_rectLayerExtent.Y1 > rect.Y1)
		m_rectLayerExtent.Y1 = rect.Y1;
	if (m_rectLayerExtent.Y2 < rect.Y2)
		m_rectLayerExtent.Y2 = rect.Y2;
}

void CSimple274X::SetFrameExtent(FRECTC fRect)
{
	m_FrameExtent = fRect;
}

FRECTC CSimple274X::GetFrameExtent()
{
	// frame extent by gerber file
	return 	m_FrameExtent;
}

float CSimple274X::GetDataCoordX(char **pFile)
{
	TCHAR szData[MAX_PATH];
	float fData = 0.0;
	int i = 0, n = 0;
	BOOL bDotFlag = FALSE;

	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[i++] = **pFile;
		(*pFile)++;
		n++;
	}

	while ((_istdigit(**pFile) || (**pFile == _T('.'))) && i < MAX_PATH)
	{
		if (**pFile == _T('.'))
			bDotFlag = TRUE;

		if (!bDotFlag)
		{
			if (m_paramFS.bSuppress) // Trailing zero option
				if (i - n == m_lDataFormatX.quot)
					szData[i++] = _T('.');
		}

		szData[i++] = **pFile;
		(*pFile)++;
	}

	if (!bDotFlag)
	{
		if (m_paramFS.bSuppress) // Trailing zero option
		{
			if (i < m_lDataFormatX.quot)
			{
				for (; i < m_lDataFormatX.quot; i++)
					szData[i] = _T('0');
			}

			szData[i] = NULL;
			fData = _tcstod(szData, NULL);
		}
		else
		{
			szData[i] = NULL;
			fData = _ttoi(szData);
			fData = (float)fData / m_fDividerX;
		}
	}
	else
	{
		szData[i] = NULL;
		fData = _tcstod(szData, NULL);
	}

	if (m_Unit == LAYER_TYPE::INCH)
		fData *= INCHTOMM;

	fData *= m_fLayerScaleX;

	return fData;
}

float CSimple274X::GetDataCoordY(char **pFile)
{
	TCHAR szData[MAX_PATH];
	float fData = 0.0;
	int i = 0, n = 0;
	BOOL bDotFlag = FALSE;


	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[i++] = **pFile;
		(*pFile)++;
		n++;
	}

	while ((_istdigit(**pFile) || (**pFile == _T('.'))) && i < MAX_PATH)
	{
		if (**pFile == _T('.'))
			bDotFlag = TRUE;

		if (!bDotFlag)
		{
			if (m_paramFS.bSuppress) // Trailing zero option
				if (i - n == m_lDataFormatY.quot)
					szData[i++] = _T('.');
		}
		szData[i++] = **pFile;
		(*pFile)++;
	}

	if (!bDotFlag)
	{
		if (m_paramFS.bSuppress) // Trailing zero option
		{
			if (i < m_lDataFormatX.quot)
			{
				for (; i < m_lDataFormatY.quot; i++)
					szData[i] = _T('0');
			}

			szData[i] = NULL;
			fData = _tcstod(szData, NULL);
		}
		else
		{
			szData[i] = NULL;
			fData = _ttoi(szData);

			fData = (float)fData / m_fDividerY;
		}
	}
	else
	{
		szData[i] = NULL;
		fData = _tcstod(szData, NULL);
	}

	if (m_Unit == LAYER_TYPE::INCH)
		fData *= INCHTOMM;

	fData *= m_fLayerScaleY;

	return fData;
}

int	CSimple274X::GetDataInteger(char **pFile)
{
	TCHAR szData[MAX_PATH];
	int nIndex;
	int nData = 0;

	nIndex = 0;

	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit
	if (**pFile == _T('-'))
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}

	while (_istdigit(**pFile) && nIndex < MAX_PATH)
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}
	szData[nIndex] = NULL;

	nData = _ttoi(szData);

	return nData;
}

float CSimple274X::GetDataFloat(char **pFile)
{
	TCHAR szData[MAX_PATH];
	int nIndex;
	float fData = 0.0;

	nIndex = 0;

	if (**pFile == _T('+'))
		(*pFile)++; // ignore '+' sign bit

	if (**pFile == _T('-'))
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}

	while ((_istdigit(**pFile) || **pFile == _T('.')) && nIndex < MAX_PATH)
	{
		szData[nIndex++] = **pFile;
		(*pFile)++;
	}
	szData[nIndex] = NULL;

	fData = _tcstod(szData, NULL);

	return fData;
}

void CSimple274X::GetCosineSineValue(float Ang, float *cV, float *sV)
{
	switch (int(Ang))	//     'CCW
	{
	case 0:
	case 360:
	case -360:
		*cV = 1;
		*sV = 0;
		break;

	case 90:
	case -270:
		*cV = 0;
		*sV = 1;
		break;
	case 180:
	case -180:
		*cV = -1;
		*sV = 0;
		break;

	case 270:
	case -90:
		*cV = 0;
		*sV = -1;
		break;

	default:
		*cV = cos(Ang * DEG2RAD);
		*sV = sin(Ang * DEG2RAD);
		break;
	}
}


int CSimple274X::GetNumOfLayer()
{
	m_nNumOfLayer = m_ArLayerInform.GetSize();
	return m_nNumOfLayer;
}

int	CSimple274X::GetNumOfAperture()
{
	return m_nNumOfAperture;
}

int	CSimple274X::GetNumOfLineTemplate()
{
	return m_nNumOfLineTemplate;
}

int	CSimple274X::GetNumOfSnR()
{
	return m_nNumOfSnRObject;
}


void CSimple274X::ResetData()
{
	CString strMsg;

	////Initialize Storage Variable
	//int i, k, nKey;
	//LPLAYER_INFORM_RS274X pLayerInfo;
	//LPAPERTURE_DEF pAptDef;

	//POSITION pos = NULL;

	//int nLayerSize = m_ArLayerInform.GetSize();
	//for (i = 0; i < nLayerSize; i++)
	//{
	//	pLayerInfo = m_ArLayerInform.GetAt(i);
	//	if (pLayerInfo != NULL)
	//	{
	//		if(pLayerInfo->vecObjCoord.size() > 0)
	//			pLayerInfo->vecObjCoord.clear();
	//		if(pLayerInfo->listObj.size() > 0)
	//			pLayerInfo->listObj.clear();
	//
	//		int nNumOfAperture = pLayerInfo->mapAptList.GetCount();
	//		if (nNumOfAperture > 0)
	//		{
	//			pos = pLayerInfo->mapAptList.GetStartPosition();
	//			while (pos != NULL)
	//			{
	//				pLayerInfo->mapAptList.GetNextAssoc(pos, nKey, pAptDef);
	//				if (pAptDef != NULL)
	//				{
	//					int nNumOfParam = pAptDef->Param.size();
	//					for (k = 0; k < nNumOfParam; k++)
	//						pAptDef->Param.at(k).fParam.clear();
	//					pAptDef->Param.clear();
	//					delete pAptDef;
	//					pAptDef = NULL;
	//				}
	//			}
	//			pLayerInfo->mapAptList.RemoveAll();
	//		}
	//
	//		int nNumOfObjColor = pLayerInfo->mapObjColor.GetCount();
	//		if (nNumOfObjColor > 0)
	//			pLayerInfo->mapObjColor.RemoveAll();
	//
	//		delete pLayerInfo;
	//	}
	//}

	DeleteLayerInfo();

	int nSizeLayerInform = m_ArLayerInform.GetSize();
	if(nSizeLayerInform > 0)
		m_ArLayerInform.RemoveAll();
	int nSizeLayerStruct = m_ArLayerStruct.GetSize();
	if(nSizeLayerStruct > 0)
		m_ArLayerStruct.RemoveAll();
	int nSizeLineTemplate = m_vecLineTemplate.size();
	if (nSizeLineTemplate > 0)
		m_vecLineTemplate.clear();

	// 	m_vecObjExtent.clear();
	// 	m_vecObjCoord.clear();

	//Initialize member variable

	// 	m_nMaxValueOfAptCode = 0;
	// 	m_dwReleaseTime = m_dwPreParsingTime = m_dwParsingTime = 0;
	// 	m_nDrawOrder = 0; 
	m_nNumOfAperture = 0;
	m_nNumOfSnRObject = 0;

	m_nNumOfObject = 0;
	m_nNumOfLineObject = 0;
	m_nNumOfLineTemplate = 0;

	// Maximun number of graphic object
	// 	m_nNumOfMaxObj = 25000000;

	// must be initialize
	m_fLayerScaleX = 1.0;
	m_fLayerScaleY = 1.0;

	float fMaxData = pow(2.0, 31.0);
	m_MaxFrameExtent.X1 = fMaxData;
	m_MaxFrameExtent.X2 = -fMaxData;
	m_MaxFrameExtent.Y1 = fMaxData;
	m_MaxFrameExtent.Y2 = -fMaxData;

	InitLayerMaxExtent();

	m_dDetZero = 0.000001;
	// 	m_fFiducialDrillSize = 1.5;
	// 	m_nDrillSuppress = 0;
	// 	m_nFormatDrill = 4;
	// 	m_nDrillUnit = LAYER_TYPE::INCH;

	// 	m_bFindLineObjPickingMode = FALSE;
	m_bImageSave = FALSE;

	m_fptCoord.x = 0.0; m_fptCoord.y = 0.0; 
}

void CSimple274X::ResetDataObject(GraphObj &gObj)
{
	gObj.dCode = 0;
	gObj.Type.nType = 0;
	gObj.Type.nAttr = 0;
	gObj.Type.nPolarity = 0;
	gObj.Type.nOrient = 0;
	gObj.Type.nReserve1 = 0;
	gObj.Type.nReserve2 = 0;
	gObj.Type.nParentid = 0;
	gObj.nValue = 0;
	gObj.dCode = 0;
	gObj.dAttrListCode = 0;
	gObj.nStPnt = 0;
	gObj.Extent = m_MaxFrameExtent;
}

void CSimple274X::ClearDataObject(GraphObj &gObj)
{
	gObj.dCode = 0;
	gObj.Type.nType = 0;
	gObj.Type.nAttr = 0;
	gObj.Type.nPolarity = 0;
	gObj.Type.nOrient = 0;
	// 	gObj.Type.nReserve1 = 0;
	// 	gObj.Type.nReserve2 = 0;
	// 	gObj.Type.nParentid = 0;
	// 	gObj.nValue = 0;
	// 	gObj.dCode = 0;
	// 	gObj.dAttrListCode = 0;
	// 	gObj.nStPnt = 0;
	gObj.Extent = m_MaxFrameExtent;
}

void CSimple274X::InitLayerMaxExtent()
{
	m_rectLayerExtent.X1 = 999999999.0;
	m_rectLayerExtent.Y1 = 999999999.0;
	m_rectLayerExtent.X2 = -999999999.0;
	m_rectLayerExtent.Y2 = -999999999.0;
}


void CSimple274X::StepAndRepeating(FRECTC &Extent, BOOL bClearObjectData)
{
	if (m_paramSR.nXRepeat <= 1 && m_paramSR.nYRepeat <= 1)
		return;

	int i, peRepeat;
	FPOINTC fPt;

	if (bClearObjectData)
		ClearDataObject(m_gObj);
	else
		m_gObj.nStPnt = m_nNumOfObjCoord;

	peRepeat = m_pLayerInfo->listObj.size() - 1;

	m_MnMxSnR = m_MaxFrameExtent;
	for (i = m_paramSR.psRepeat; i <= peRepeat; i++)
	{
		AdjustExtentByRect(m_MnMxSnR, m_pLayerInfo->listObj.at(i).Extent);
	}

	m_gObj.dCode = 0;
	m_gObj.Type.nType = DRAW_TYPE::SNR;

	m_gObj.Extent.Y1 = m_MnMxSnR.Y1;
	m_gObj.Extent.Y2 = m_MnMxSnR.Y2;
	m_gObj.Extent.X1 = m_MnMxSnR.X1;
	m_gObj.Extent.X2 = m_MnMxSnR.X2;

	fPt.x = m_paramSR.psRepeat;
	fPt.y = peRepeat;
	m_pLayerInfo->vecObjCoord.push_back(fPt);
	m_nNumOfObjCoord++;

	fPt.x = m_paramSR.nXRepeat;
	fPt.y = m_paramSR.nYRepeat;
	m_pLayerInfo->vecObjCoord.push_back(fPt);
	m_nNumOfObjCoord++;

	fPt.x = m_fStepX;
	fPt.y = m_fStepY;
	m_pLayerInfo->vecObjCoord.push_back(fPt);
	m_nNumOfObjCoord++;

	m_MnMxSnR = GetLayerMaxExtent();
	if ((m_paramSR.nXRepeat - 1) * m_fStepX > 0)
	{
		if (m_gObj.Extent.X1 < m_MnMxSnR.X1) m_MnMxSnR.X1 = m_gObj.Extent.X1;
		if (m_gObj.Extent.X2 + (m_paramSR.nXRepeat - 1) * m_fStepX > m_MnMxSnR.X2) m_MnMxSnR.X2 = m_gObj.Extent.X2 + (m_paramSR.nXRepeat - 1) * m_fStepX;
	}
	else
	{
		if (m_gObj.Extent.X1 + (m_paramSR.nXRepeat - 1) * m_fStepX < m_MnMxSnR.X1) m_MnMxSnR.X1 = m_gObj.Extent.X1 + (m_paramSR.nXRepeat - 1) * m_fStepX;
		if (m_gObj.Extent.X2 > m_MnMxSnR.X2) m_MnMxSnR.X2 = m_gObj.Extent.X2;
	}

	if ((m_paramSR.nYRepeat - 1) * m_fStepY > 0)
	{
		if (m_gObj.Extent.Y1 < m_MnMxSnR.Y1) m_MnMxSnR.Y1 = m_gObj.Extent.Y1;
		if (m_gObj.Extent.Y2 + (m_paramSR.nYRepeat - 1) * m_fStepY > m_MnMxSnR.Y2) m_MnMxSnR.Y2 = m_gObj.Extent.Y2 + (m_paramSR.nYRepeat - 1) * m_fStepY;
	}
	else
	{
		if (m_gObj.Extent.Y1 + (m_paramSR.nYRepeat - 1) * m_fStepY < m_MnMxSnR.Y1) m_MnMxSnR.Y1 = m_gObj.Extent.Y1 + (m_paramSR.nYRepeat - 1) * m_fStepY;
		if (m_gObj.Extent.Y2 > m_MnMxSnR.Y2) m_MnMxSnR.Y2 = m_gObj.Extent.Y2;
	}

	SetLayerMaxExtent(m_MnMxSnR);

	m_gObj.Type.nAttr = DRAW_TYPE::PATTERN;
	m_pLayerInfo->listObj.push_back(m_gObj);

	m_nNumOfSnRObject++;

	m_gObj.nStPnt = m_nNumOfObjCoord;
	ClearDataObject(m_gObj);

	m_nObj++;
}

void CSimple274X::ApplyIROptionGRB(LAYER_INFORM_RS274X *pLayerInfo, double cX, double cY, double fAng)
{
	int i, nObj;
	CString temp;
	FPOINTC fC = FPOINTC(cX, cY);

	i = 0;
	nObj = 0;
	nObj = pLayerInfo->listObj.size();
	for (i = 0; i < nObj - 1; i++)	//for (i=0 ; i < nObj ; i++)
	{
		RotateTransObject(pLayerInfo, &pLayerInfo->listObj[i], &pLayerInfo->listObj[i + 1], fC, fAng, 0.0, 0.0);
	}
	RotateRect(pLayerInfo->Extent, fC, fAng);
}

void CSimple274X::RotateTransObject(LAYER_INFORM_RS274X *pLayerInfo, GraphObj *obj, GraphObj *Nextobj, FPOINTC fC, double fAng, double tX, double tY)
{
	byte dType;
	FPOINTC p = FPOINTC(0.0, 0.0);
	int k = 0, nSize = 0;
	float cV = 1.0, sV = 0.0;
	double XX = 0.0;

	nSize = Nextobj->nStPnt - obj->nStPnt;
	dType = obj->Type.nType;


	switch (dType)
	{
	case DRAW_TYPE::LINE: //' Line: m_pTrUtil->m_bType[0]============================================================>
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], tX, tY);
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + 1], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + 1], tX, tY);
		break;
	case DRAW_TYPE::FLASH: // 'Flash : m_pTrUtil->m_bType[1]
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], tX, tY);
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ: // m_pTrUtil->m_bType[5], m_pTrUtil->m_bType[6] 'PolygonFill with G74, G75
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], tX, tY);
		for (k = 1; k < nSize; k++)
		{
			if (fabs(pLayerInfo->vecObjCoord.at(k + obj->nStPnt).x) == DetGcode && fabs(pLayerInfo->vecObjCoord.at(k + obj->nStPnt).y) == DetGcode)
			{
				k++;
				RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + k], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + k], tX, tY);

				k++;
				RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + k], FPOINTC(0.0, 0.0), fAng);
			}
			else
			{
				RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + k], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + k], tX, tY);
			}
		}
		break;
	case DRAW_TYPE::ARC_CW:
	case DRAW_TYPE::ARC_CCW: // dType == TYPE_CW
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt], tX, tY);
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + 1], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + 1], tX, tY);
		RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + 2], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + 2], tX, tY);
		break;
	case DRAW_TYPE::SNR:

		cVsV(fAng, &cV, &sV);

		XX = pLayerInfo->vecObjCoord[obj->nStPnt + 2].x;

		pLayerInfo->vecObjCoord[obj->nStPnt + 2].x = cV * pLayerInfo->vecObjCoord[obj->nStPnt + 2].x - sV * pLayerInfo->vecObjCoord[obj->nStPnt + 2].y;
		pLayerInfo->vecObjCoord[obj->nStPnt + 2].y = sV * XX + cV * pLayerInfo->vecObjCoord[obj->nStPnt + 2].y;

		if (nSize > 5)
		{
			RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2], tX, tY);
			RotatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1], fC, fAng); TranslatePoint(pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1], tX, tY);

			if (pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2].x > pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1].x)
			{
				XX = pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2].x;
				pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2].x = pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1].x;
				pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1].x = XX;
			}
			if (pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2].y > pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1].y)
			{
				XX = pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2].y;
				pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 2].y = pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1].y;
				pLayerInfo->vecObjCoord[obj->nStPnt + nSize - 1].y = XX;
			}
		}

		if (fAng == 90 || fAng == -90)
		{
			k = pLayerInfo->vecObjCoord[obj->nStPnt + 1].x;
			pLayerInfo->vecObjCoord[obj->nStPnt + 1].x = pLayerInfo->vecObjCoord[obj->nStPnt + 1].y;
			pLayerInfo->vecObjCoord[obj->nStPnt + 1].y = k;
		}
		break;
	}
	RotateRect(obj->Extent, fC, fAng);
	TranslateRect(obj->Extent, tX, tY);

}


void CSimple274X::Mirror()
{
	int i, nCoord;

	if (m_paramMI.bMirrorX)
	{
		m_nEndMirrorObj = m_pLayerInfo->listObj.size();
		for (i = m_nStartMirrorObj; i < m_nEndMirrorObj; i++)
		{
			if (i == m_nEndMirrorObj - 1)
				nCoord = m_pLayerInfo->vecObjCoord.size() - m_pLayerInfo->listObj[i].nStPnt;
			else
				nCoord = m_pLayerInfo->listObj[i + 1].nStPnt - m_pLayerInfo->listObj[i].nStPnt;

			MirrorVerticalObject(m_pLayerInfo, &m_pLayerInfo->listObj.at(i), nCoord, 0.0);
			SetLayerMaxExtent(m_pLayerInfo->listObj.at(i).Extent);
		}

		m_paramMI.bMirrorX = FALSE;
	}
	if (m_paramMI.bMirrorY)
	{
		m_nEndMirrorObj = m_pLayerInfo->listObj.size();
		for (i = m_nStartMirrorObj; i < m_nEndMirrorObj; i++)
		{
			if (i == m_nEndMirrorObj - 1)
				nCoord = m_pLayerInfo->vecObjCoord.size() - m_pLayerInfo->listObj.at(i).nStPnt;
			else
				nCoord = m_pLayerInfo->listObj.at(i + 1).nStPnt - m_pLayerInfo->listObj.at(i).nStPnt;

			MirrorHorizontalObject(m_pLayerInfo, &m_pLayerInfo->listObj.at(i), nCoord, 0.0);
			SetLayerMaxExtent(m_pLayerInfo->listObj.at(i).Extent);
		}

		m_paramMI.bMirrorY = FALSE;
	}
	m_nStartMirrorObj = 0;

}

void CSimple274X::MirrorVerticalObject(vector<FPOINTC> &vecCoord, GraphObj *obj, double vAxis)  //'좌우미러링
{
	int k, nCoord;
	byte dType;
	double XX;

	dType = obj->Type.nType;

	nCoord = 0;

	switch (dType)
	{
	case DRAW_TYPE::LINE:
		vecCoord[0].x = -(vecCoord[0].x - vAxis) + vAxis;
		vecCoord[1].x = -(vecCoord[1].x - vAxis) + vAxis;
		break;
	case DRAW_TYPE::FLASH:
		vecCoord[0].x = -(vecCoord[0].x - vAxis) + vAxis;
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ:
		nCoord = vecCoord.size();
		vecCoord[0].x = -(vecCoord[0].x - vAxis) + vAxis;
		for (k = 1; k < nCoord; k++)
		{
			if ((vecCoord[k].x == DetGcode && vecCoord[0 + k].y == DetGcode) ||
				(vecCoord[k].x == -DetGcode && vecCoord[0 + k].y == -DetGcode))
			{
				vecCoord[k].x = -vecCoord[k].x;
				vecCoord[k].y = -vecCoord[k].y;
				k++;
				vecCoord[k].x = -(vecCoord[k].x - vAxis) + vAxis;
				k++;
				vecCoord[k].x = -vecCoord[k].x;
			}
			else
				vecCoord[k].x = -(vecCoord[k].x - vAxis) + vAxis;
		}
		break;
	case DRAW_TYPE::ARC_CW:
	case DRAW_TYPE::ARC_CCW:
		if (dType == DRAW_TYPE::ARC_CW)
			obj->Type.nType = DRAW_TYPE::ARC_CCW;
		else
			obj->Type.nType = DRAW_TYPE::ARC_CW;
		vecCoord[0].x = -(vecCoord[0].x - vAxis) + vAxis;
		vecCoord[1].x = -(vecCoord[1].x - vAxis) + vAxis;
		vecCoord[2].x = -(vecCoord[2].x - vAxis) + vAxis;
		break;
	case DRAW_TYPE::SNR:
		vecCoord[2].x = -vecCoord[2].x;
		break;
	}

	XX = obj->Extent.X2;
	obj->Extent.X2 = -(obj->Extent.X1 - vAxis) + vAxis;
	obj->Extent.X1 = -(XX - vAxis) + vAxis;
}

void CSimple274X::MirrorHorizontalObject(vector<FPOINTC> &vecCoord, GraphObj *obj, double hAxis)
{
	int k, nCoord;
	byte dType;
	double YY;

	dType = obj->Type.nType;

	switch (dType)
	{
	case DRAW_TYPE::LINE:
		vecCoord[0].y = -(vecCoord[0].y - hAxis) + hAxis;
		vecCoord[1].y = -(vecCoord[1].y - hAxis) + hAxis;
		break;
	case DRAW_TYPE::FLASH:
		vecCoord[0].y = -(vecCoord[0].y - hAxis) + hAxis;
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ:
		nCoord = vecCoord.size();
		vecCoord[0].y = -(vecCoord[0].y - hAxis) + hAxis;
		for (k = 1; k < nCoord; k++)
		{
			if ((vecCoord[k].x == DetGcode && vecCoord[k].y == DetGcode) ||
				(vecCoord[k].x == -DetGcode && vecCoord[k].y == -DetGcode))
			{
				vecCoord[k].x = -vecCoord[k].x;
				vecCoord[k].y = -vecCoord[k].y;
				k++;
				vecCoord[k].y = -(vecCoord[k].y - hAxis) + hAxis;
				k++;
				vecCoord[k].y = -vecCoord[k].y;
			}
			else
				vecCoord[k].y = -(vecCoord[k].y - hAxis) + hAxis;
		}
		break;
	case DRAW_TYPE::ARC_CW:
	case DRAW_TYPE::ARC_CCW:
		if (dType == DRAW_TYPE::ARC_CW)
			obj->Type.nType = DRAW_TYPE::ARC_CCW;
		else
			obj->Type.nType = DRAW_TYPE::ARC_CW;
		vecCoord[0].y = -(vecCoord[0].y - hAxis) + hAxis;
		vecCoord[1].y = -(vecCoord[1].y - hAxis) + hAxis;
		vecCoord[2].y = -(vecCoord[2].y - hAxis) + hAxis;
		break;
	case DRAW_TYPE::SNR:
		vecCoord[2].y = -vecCoord[2].y;
		if (vecCoord.size() > 3)
			vecCoord[3].y = -vecCoord[3].y;
		break;
	}

	YY = obj->Extent.Y2;
	obj->Extent.Y2 = -(obj->Extent.Y1 - hAxis) + hAxis;
	obj->Extent.Y1 = -(YY - hAxis) + hAxis;
}

void CSimple274X::MirrorHorizontalObject(LAYER_INFORM_RS274X *pLayerInfo, GraphObj *obj, int nCoord, double hAxis)  //'좌우미러링
{
	int k;
	byte dType;
	double YY;

	dType = obj->Type.nType;

	switch (dType)
	{
	case DRAW_TYPE::LINE:
		pLayerInfo->vecObjCoord[obj->nStPnt].y = -(pLayerInfo->vecObjCoord[obj->nStPnt].y - hAxis) + hAxis;
		pLayerInfo->vecObjCoord[obj->nStPnt + 1].y = -(pLayerInfo->vecObjCoord[obj->nStPnt + 1].y - hAxis) + hAxis;
		break;
	case DRAW_TYPE::FLASH:
		pLayerInfo->vecObjCoord[obj->nStPnt].y = -(pLayerInfo->vecObjCoord[obj->nStPnt].y - hAxis) + hAxis;
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ:
		pLayerInfo->vecObjCoord[obj->nStPnt].y = -(pLayerInfo->vecObjCoord[obj->nStPnt].y - hAxis) + hAxis;
		for (k = 1; k < nCoord; k++)
		{
			if ((pLayerInfo->vecObjCoord[obj->nStPnt + k].x == DetGcode && pLayerInfo->vecObjCoord[obj->nStPnt + k].y == DetGcode) ||
				(pLayerInfo->vecObjCoord[obj->nStPnt + k].x == -DetGcode && pLayerInfo->vecObjCoord[obj->nStPnt + k].y == -DetGcode))
			{
				pLayerInfo->vecObjCoord[obj->nStPnt + k].x = -pLayerInfo->vecObjCoord[obj->nStPnt + k].x;
				pLayerInfo->vecObjCoord[obj->nStPnt + k].y = -pLayerInfo->vecObjCoord[obj->nStPnt + k].y;
				k++;
				pLayerInfo->vecObjCoord[obj->nStPnt + k].y = -(pLayerInfo->vecObjCoord[obj->nStPnt + k].y - hAxis) + hAxis;
				k++;
				pLayerInfo->vecObjCoord[obj->nStPnt + k].y = -pLayerInfo->vecObjCoord[obj->nStPnt + k].y;
			}
			else
				pLayerInfo->vecObjCoord[obj->nStPnt + k].y = -(pLayerInfo->vecObjCoord[obj->nStPnt + k].y - hAxis) + hAxis;
		}
		break;
	case DRAW_TYPE::ARC_CW:
	case DRAW_TYPE::ARC_CCW:
		if (dType == DRAW_TYPE::ARC_CW)
			obj->Type.nType = DRAW_TYPE::ARC_CCW;
		else
			obj->Type.nType = DRAW_TYPE::ARC_CW;
		pLayerInfo->vecObjCoord[obj->nStPnt + 0].y = -(pLayerInfo->vecObjCoord[obj->nStPnt + 0].y - hAxis) + hAxis;
		pLayerInfo->vecObjCoord[obj->nStPnt + 1].y = -(pLayerInfo->vecObjCoord[obj->nStPnt + 1].y - hAxis) + hAxis;
		pLayerInfo->vecObjCoord[obj->nStPnt + 2].y = -(pLayerInfo->vecObjCoord[obj->nStPnt + 2].y - hAxis) + hAxis;
		break;
	case DRAW_TYPE::SNR:
		pLayerInfo->vecObjCoord[obj->nStPnt + 2].y = -pLayerInfo->vecObjCoord[obj->nStPnt + 2].y;
		break;
	}

	YY = obj->Extent.Y2;
	obj->Extent.Y2 = -(obj->Extent.Y1 - hAxis) + hAxis;
	obj->Extent.Y1 = -(YY - hAxis) + hAxis;

	if (obj->Extent.Y1 > obj->Extent.Y2)
	{
		YY = obj->Extent.Y1;
		obj->Extent.Y1 = obj->Extent.Y2;
		obj->Extent.Y2 = YY;
	}
}

void CSimple274X::MirrorVerticalObject(LAYER_INFORM_RS274X *pLayerInfo, GraphObj *obj, int nCoord, double vAxis)  //'좌우미러링
{
	int k;
	byte dType;
	double XX;

	dType = obj->Type.nType;

	switch (dType)
	{
	case DRAW_TYPE::LINE:
		pLayerInfo->vecObjCoord[obj->nStPnt].x = -(pLayerInfo->vecObjCoord[obj->nStPnt].x - vAxis) + vAxis;
		pLayerInfo->vecObjCoord[obj->nStPnt + 1].x = -(pLayerInfo->vecObjCoord[obj->nStPnt + 1].x - vAxis) + vAxis;
		break;
	case DRAW_TYPE::FLASH:
		pLayerInfo->vecObjCoord[obj->nStPnt].x = -(pLayerInfo->vecObjCoord[obj->nStPnt].x - vAxis) + vAxis;
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ:
		pLayerInfo->vecObjCoord[obj->nStPnt].x = -(pLayerInfo->vecObjCoord[obj->nStPnt].x - vAxis) + vAxis;
		for (k = 1; k < nCoord; k++)
		{
			if ((pLayerInfo->vecObjCoord[obj->nStPnt + k].x == DetGcode && pLayerInfo->vecObjCoord[obj->nStPnt + k].y == DetGcode) ||
				(pLayerInfo->vecObjCoord[obj->nStPnt + k].x == -DetGcode && pLayerInfo->vecObjCoord[obj->nStPnt + k].y == -DetGcode))
			{
				pLayerInfo->vecObjCoord[obj->nStPnt + k].x = -pLayerInfo->vecObjCoord[obj->nStPnt + k].x;
				pLayerInfo->vecObjCoord[obj->nStPnt + k].y = -pLayerInfo->vecObjCoord[obj->nStPnt + k].y;
				k++;
				pLayerInfo->vecObjCoord[obj->nStPnt + k].x = -(pLayerInfo->vecObjCoord[obj->nStPnt + k].x - vAxis) + vAxis;
				k++;
				pLayerInfo->vecObjCoord[obj->nStPnt + k].x = -pLayerInfo->vecObjCoord[obj->nStPnt + k].x;
			}
			else
				pLayerInfo->vecObjCoord[obj->nStPnt + k].x = -(pLayerInfo->vecObjCoord[obj->nStPnt + k].x - vAxis) + vAxis;
		}
		break;
	case DRAW_TYPE::ARC_CW:
	case DRAW_TYPE::ARC_CCW:
		if (dType == DRAW_TYPE::ARC_CW)
			obj->Type.nType = DRAW_TYPE::ARC_CCW;
		else
			obj->Type.nType = DRAW_TYPE::ARC_CW;
		pLayerInfo->vecObjCoord[obj->nStPnt + 0].x = -(pLayerInfo->vecObjCoord[obj->nStPnt + 0].x - vAxis) + vAxis;
		pLayerInfo->vecObjCoord[obj->nStPnt + 1].x = -(pLayerInfo->vecObjCoord[obj->nStPnt + 1].x - vAxis) + vAxis;
		pLayerInfo->vecObjCoord[obj->nStPnt + 2].x = -(pLayerInfo->vecObjCoord[obj->nStPnt + 2].x - vAxis) + vAxis;
		break;
	case DRAW_TYPE::SNR:
		pLayerInfo->vecObjCoord[obj->nStPnt + 2].x = -pLayerInfo->vecObjCoord[obj->nStPnt + 2].x;
		break;
	}

	XX = obj->Extent.X2;
	obj->Extent.X2 = -(obj->Extent.X1 - vAxis) + vAxis;
	obj->Extent.X1 = -(XX - vAxis) + vAxis;

	if (obj->Extent.X1 > obj->Extent.X2)
	{
		XX = obj->Extent.X1;
		obj->Extent.X1 = obj->Extent.X2;
		obj->Extent.X2 = XX;
	}
}


void CSimple274X::RotateRect(FRECTC &fRect, FPOINTC &fCenter, double fAng)
{
	double X1, Y1, X2, Y2;
	FRECTC rRect;
	float cV, sV;

	switch ((int)fAng)
	{
	case 90:
		RotateRect90(fRect, fCenter);
		break;
	case 180:
		RotateRect180(fRect, fCenter);
		break;
	case 270:
		RotateRect270(fRect, fCenter);
		break;
	default:
		cV = cos(fAng * DEG2RAD);
		sV = sin(fAng * DEG2RAD);

		// rotate left-bottom and right top point
		X1 = ((fRect.X1 - fCenter.x) * cV) - ((fRect.Y1 - fCenter.y) * sV) + fCenter.x;
		Y1 = ((fRect.X1 - fCenter.x) * sV) + ((fRect.Y1 - fCenter.y) * cV) + fCenter.y;
		X2 = ((fRect.X2 - fCenter.x) * cV) - ((fRect.Y2 - fCenter.y) * sV) + fCenter.x;
		Y2 = ((fRect.X2 - fCenter.x) * sV) + ((fRect.Y2 - fCenter.y) * cV) + fCenter.y;

		if (X1 < X2)
		{
			rRect.X1 = X1;
			rRect.X2 = X2;
		}
		else
		{
			rRect.X1 = X2;
			rRect.X2 = X1;
		}

		if (Y1 < Y2)
		{
			rRect.Y1 = Y1;
			rRect.Y2 = Y2;
		}
		else
		{
			rRect.Y1 = Y2;
			rRect.Y2 = Y1;
		}
		// rotate left-top and right bottom point
		X1 = ((fRect.X1 - fCenter.x) * cV) - ((fRect.Y2 - fCenter.y) * sV) + fCenter.x;
		Y1 = ((fRect.X1 - fCenter.x) * sV) + ((fRect.Y2 - fCenter.y) * cV) + fCenter.y;
		X2 = ((fRect.X2 - fCenter.x) * cV) - ((fRect.Y1 - fCenter.y) * sV) + fCenter.x;
		Y2 = ((fRect.X2 - fCenter.x) * sV) + ((fRect.Y1 - fCenter.y) * cV) + fCenter.y;

		if (X1 < X2)
		{
			fRect.X1 = X1;
			fRect.X2 = X2;
		}
		else
		{
			fRect.X1 = X2;
			fRect.X2 = X1;
		}

		if (Y1 < Y2)
		{
			fRect.Y1 = Y1;
			fRect.Y2 = Y2;
		}
		else
		{
			fRect.Y1 = Y2;
			fRect.Y2 = Y1;
		}

		if (fRect.X1 > rRect.X1)	fRect.X1 = rRect.X1;
		if (fRect.Y1 > rRect.Y1)	fRect.Y1 = rRect.Y1;
		if (fRect.X2 < rRect.X2)	fRect.X2 = rRect.X2;
		if (fRect.Y2 < rRect.Y2)	fRect.Y2 = rRect.Y2;
	}
}

void CSimple274X::RotateRect90(FRECTC &fRect, FPOINTC &fpt)
{
	double X1, Y1, X2, Y2;

	X1 = -fRect.Y1 + fpt.y + fpt.x;
	Y1 = fRect.X1 - fpt.x + fpt.y;
	X2 = -fRect.Y2 + fpt.y + fpt.x;
	Y2 = fRect.X2 - fpt.x + fpt.y;

	if (X1 < X2)
	{
		fRect.X1 = X1;
		fRect.X2 = X2;
	}
	else
	{
		fRect.X1 = X2;
		fRect.X2 = X1;
	}

	if (Y1 < Y2)
	{
		fRect.Y1 = Y1;
		fRect.Y2 = Y2;
	}
	else
	{
		fRect.Y1 = Y2;
		fRect.Y2 = Y1;
	}
}

void CSimple274X::RotateRect180(FRECTC &fRect, FPOINTC &fpt)
{
	double X1, Y1, X2, Y2;

	X1 = -fRect.X1 + fpt.x + fpt.x;
	Y1 = -fRect.Y1 + fpt.y + fpt.y;
	X2 = -fRect.X2 + fpt.x + fpt.x;
	Y2 = -fRect.Y2 + fpt.y + fpt.y;

	if (X1 < X2)
	{
		fRect.X1 = X1;
		fRect.X2 = X2;
	}
	else
	{
		fRect.X1 = X2;
		fRect.X2 = X1;
	}

	if (Y1 < Y2)
	{
		fRect.Y1 = Y1;
		fRect.Y2 = Y2;
	}
	else
	{
		fRect.Y1 = Y2;
		fRect.Y2 = Y1;
	}
}

void CSimple274X::RotateRect270(FRECTC &fRect, FPOINTC &fpt)
{
	double X1, Y1, X2, Y2;

	X1 = ((fRect.Y1 - fpt.y)) + fpt.x;
	Y1 = -((fRect.X1 - fpt.x)) + fpt.y;
	X2 = ((fRect.Y2 - fpt.y)) + fpt.x;
	Y2 = -((fRect.X2 - fpt.x)) + fpt.y;

	if (X1 < X2)
	{
		fRect.X1 = X1;
		fRect.X2 = X2;
	}
	else
	{
		fRect.X1 = X2;
		fRect.X2 = X1;
	}

	if (Y1 < Y2)
	{
		fRect.Y1 = Y1;
		fRect.Y2 = Y2;
	}
	else
	{
		fRect.Y1 = Y2;
		fRect.Y2 = Y1;
	}
}

void CSimple274X::RotatePoint(FPOINTC &p, double cV, double sV, double cX, double cY)
{
	FPOINTC pt(((p.x - cX) * cV) - ((p.y - cY) * sV) + cX, ((p.x - cX) * sV) + ((p.y - cY) * cV) + cY);
	p = pt;
}

void CSimple274X::RotatePoint(FPOINTC &fpt, FPOINTC &fCenter, double fAng)
{
	float cV, sV;
	switch ((int)fAng)
	{
	case 90:
		RotatePoint90(fpt, fCenter);
		break;
	case 180:
		RotatePoint180(fpt, fCenter);
		break;
	case 270:
		RotatePoint270(fpt, fCenter);
		break;
	default:
		cV = cos(fAng * DEG2RAD);
		sV = sin(fAng * DEG2RAD);
		FPOINTC pt(((fpt.x - fCenter.x) * cV) - ((fpt.y - fCenter.y) * sV) + fCenter.x,
			((fpt.x - fCenter.x) * sV) + ((fpt.y - fCenter.y) * cV) + fCenter.y);
		fpt = pt;
	}
}

void CSimple274X::RotatePoint(FPOINTC &fpt, FPOINTC &fCenter)
{
	FPOINTC pt(((fpt.x - fCenter.x) * m_fCosine) - ((fpt.y - fCenter.y) * m_fSine) + fCenter.x,
		((fpt.x - fCenter.x) * m_fSine) + ((fpt.y - fCenter.y) * m_fCosine) + fCenter.y);
	fpt = pt;
}

void CSimple274X::RotatePoint90(FPOINTC &fpt, FPOINTC &fCenter)
{
	FPOINTC pt(-fpt.y + fCenter.y + fCenter.x, fpt.x - fCenter.x + fCenter.y);
	fpt = pt;
}

void CSimple274X::RotatePoint180(FPOINTC &fpt, FPOINTC &fCenter)
{
	FPOINTC pt(-fpt.x + fCenter.x + fCenter.x, -fpt.y + fCenter.y + fCenter.y);
	fpt = pt;
}

void CSimple274X::RotatePoint270(FPOINTC &fpt, FPOINTC &fCenter)
{
	FPOINTC pt(fpt.y - fCenter.y + fCenter.x, -fpt.x + fCenter.x + fCenter.y);
	fpt = pt;
}

void CSimple274X::RotateTranslateExtent(FRECTC &Extent, double cV, double sV, double cX, double cY, double dX, double dY)
{
	double X1, Y1, X2, Y2;
	FRECTC rRect;

	X1 = ((Extent.X1 - cX) * cV) - ((Extent.Y1 - cY) * sV) + cX + dX;
	Y1 = ((Extent.X1 - cX) * sV) + ((Extent.Y1 - cY) * cV) + cY + dY;
	X2 = ((Extent.X2 - cX) * cV) - ((Extent.Y2 - cY) * sV) + cX + dX;
	Y2 = ((Extent.X2 - cX) * sV) + ((Extent.Y2 - cY) * cV) + cY + dY;

	if (X1 < X2)
	{
		rRect.X1 = X1;
		rRect.X2 = X2;
	}
	else
	{
		rRect.X1 = X2;
		rRect.X2 = X1;
	}

	if (Y1 < Y2)
	{
		rRect.Y1 = Y1;
		rRect.Y2 = Y2;
	}
	else
	{
		rRect.Y1 = Y2;
		rRect.Y2 = Y1;
	}
	Extent = rRect;
}

void CSimple274X::RotateObject90(vector<FPOINTC> &vecCoord, GraphObj *obj, FPOINTC fC)
{
	byte dType;
	FPOINTC p;
	int k, nSize;
	//	, double ang, double cV, double sV
	nSize = vecCoord.size();
	dType = obj->Type.nType;


	if (dType == DRAW_TYPE::LINE) //' Line: m_pTrUtil->m_bType[0]============================================================>
	{
		//RotateTranslatePoint(vecCoord[0], cV, sV, cX,cY, 0, 0);
		//RotateTranslatePoint(vecCoord[1], cV, sV, cX,cY, 0, 0);
		RotatePoint90(vecCoord[0], fC);
		RotatePoint90(vecCoord[1], fC);

	}
	else if (dType == DRAW_TYPE::FLASH) // 'Flash : m_pTrUtil->m_bType[1]
	{
		//RotateTranslatePoint(vecCoord[0], cV, sV, cX,cY, 0, 0);
		RotatePoint90(vecCoord[0], fC);
	}
	else if (dType == DRAW_TYPE::POLYGON_SQ || dType == DRAW_TYPE::POLYGON_MQ) // m_pTrUtil->m_bType[5], m_pTrUtil->m_bType[6] 'PolygonFill with G74, G75
	{
		RotatePoint90(vecCoord[0], fC);
		for (k = 1; k < nSize; k++)
		{
			if (fabs(vecCoord[k].x) == DetGcode && fabs(vecCoord[k].y) == DetGcode)
			{
				k++;
				RotatePoint90(vecCoord[k], fC);

				k++;
				RotatePoint90(vecCoord[k], fC);

			}
			else
			{
				RotatePoint90(vecCoord[k], fC);
			}
		}
	}
	else if (dType == DRAW_TYPE::ARC_CW || dType == DRAW_TYPE::ARC_CCW) // dType == TYPE_CW
	{
		RotatePoint90(vecCoord[0], fC);
		RotatePoint90(vecCoord[1], fC);
		RotatePoint90(vecCoord[2], fC);
	}
	else if (dType == DRAW_TYPE::SNR)
	{
		double XX = vecCoord[obj->nStPnt + 2].x;
		vecCoord[2].x = -vecCoord[2].y;
		vecCoord[2].y = XX;

		XX = vecCoord[1].x;
		vecCoord[1].x = vecCoord[1].y;
		vecCoord[1].y = XX;
	}

	RotateRect90(obj->Extent, fC);
}
void CSimple274X::TranslateCoordbyActionCode(vector <FPOINTC> &vecCoord, GraphObj &gObj, FPOINTC fptCenter)
{
	int i, nNumOfCoord;
	float cV, sV, XX, YY;

	ldiv_t Rem = ldiv(m_nActionCode, 10);

	nNumOfCoord = vecCoord.size();
	if (Rem.quot > 0)
	{
		for (i = 0; i < nNumOfCoord; i++)
		{
			switch (Rem.quot)
			{
			case TRANSFORM_DATA::MIRROR_V:
				vecCoord.at(i).x = -(vecCoord.at(i).x - fptCenter.x) + fptCenter.x;
				break;
			case TRANSFORM_DATA::MIRROR_H:
				vecCoord.at(i).y = -(vecCoord.at(i).y - fptCenter.y) + fptCenter.y;
				break;
			case TRANSFORM_DATA::ROTATE_180:
				//m_pTrUtil->cVsV(180, &cV, &sV);
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint180(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CCW:
				//m_pTrUtil->cVsV(90, &cV, &sV);							// CCW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint90(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CW:
				//m_pTrUtil->cVsV(-90, &cV, &sV);							// CW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint270(vecCoord.at(i), fptCenter);
				break;
			}
		}

		switch (Rem.quot)
		{
		case TRANSFORM_DATA::MIRROR_V:
			gObj.Extent.X1 = -(gObj.Extent.X1 - fptCenter.x) + fptCenter.x;
			gObj.Extent.X2 = -(gObj.Extent.X2 - fptCenter.x) + fptCenter.x;
			if (gObj.Extent.X1 > gObj.Extent.X2)
			{
				XX = gObj.Extent.X1;
				gObj.Extent.X1 = gObj.Extent.X2;
				gObj.Extent.X2 = XX;
			}
			break;
		case TRANSFORM_DATA::MIRROR_H:
			gObj.Extent.Y1 = -(gObj.Extent.Y1 - fptCenter.y) + fptCenter.y;
			gObj.Extent.Y2 = -(gObj.Extent.Y2 - fptCenter.y) + fptCenter.y;
			if (gObj.Extent.Y1 > gObj.Extent.Y2)
			{
				YY = gObj.Extent.Y1;
				gObj.Extent.Y1 = gObj.Extent.Y2;
				gObj.Extent.Y2 = YY;
			}
			break;
		case TRANSFORM_DATA::ROTATE_180:
			//m_pTrUtil->cVsV(180, &cV, &sV);
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			RotateRect180(gObj.Extent, fptCenter);
			RotatePoint180(fptCenter, fptCenter);
			break;
		case TRANSFORM_DATA::ROTATE_CCW:
			//m_pTrUtil->cVsV(90, &cV, &sV);							// CCW Rotate
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			RotateRect90(gObj.Extent, fptCenter);
			RotatePoint90(fptCenter, fptCenter);
			break;
		case TRANSFORM_DATA::ROTATE_CW:
			//m_pTrUtil->cVsV(-90, &cV, &sV);							// CW Rotate
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);		
			RotateRect270(gObj.Extent, fptCenter);
			RotatePoint270(fptCenter, fptCenter);
			break;
		}
	}

	if (Rem.rem > 0)
	{
		for (i = 0; i < nNumOfCoord; i++)
		{
			switch (Rem.rem)
			{
			case TRANSFORM_DATA::MIRROR_V:
				vecCoord.at(i).x = -(vecCoord.at(i).x - fptCenter.x) + fptCenter.x;
				break;
			case TRANSFORM_DATA::MIRROR_H:
				vecCoord.at(i).y = -(vecCoord.at(i).y - fptCenter.y) + fptCenter.y;
				break;
			case TRANSFORM_DATA::ROTATE_180:
				//m_pTrUtil->cVsV(180, &cV, &sV);
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint180(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CCW:
				//m_pTrUtil->cVsV(90, &cV, &sV);							// CCW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint90(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CW:
				//m_pTrUtil->cVsV(-90, &cV, &sV);							// CW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);		
				RotatePoint270(vecCoord.at(i), fptCenter);
				break;
			}
		}

		switch (Rem.rem)
		{
		case TRANSFORM_DATA::MIRROR_V:
			gObj.Extent.X1 = -(gObj.Extent.X1 - fptCenter.x) + fptCenter.x;
			gObj.Extent.X2 = -(gObj.Extent.X2 - fptCenter.x) + fptCenter.x;
			if (gObj.Extent.X1 > gObj.Extent.X2)
			{
				XX = gObj.Extent.X1;
				gObj.Extent.X1 = gObj.Extent.X2;
				gObj.Extent.X2 = XX;
			}
			break;
		case TRANSFORM_DATA::MIRROR_H:
			gObj.Extent.Y1 = -(gObj.Extent.Y1 - fptCenter.y) + fptCenter.y;
			gObj.Extent.Y2 = -(gObj.Extent.Y2 - fptCenter.y) + fptCenter.y;
			if (gObj.Extent.Y1 > gObj.Extent.Y2)
			{
				YY = gObj.Extent.Y1;
				gObj.Extent.Y1 = gObj.Extent.Y2;
				gObj.Extent.Y2 = YY;
			}
			break;
		case TRANSFORM_DATA::ROTATE_180:
			cVsV(180, &cV, &sV);
			RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			break;
		case TRANSFORM_DATA::ROTATE_CCW:
			cVsV(90, &cV, &sV);							// CCW Rotate
			RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			break;
		case TRANSFORM_DATA::ROTATE_CW:
			cVsV(-90, &cV, &sV);							// CW Rotate
			RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			break;
		}
	}
}

void CSimple274X::TranslatePoint(FPOINTC &p, double dX, double dY)
{
	//	FPOINTC pt(p.x + dX,p.y + dY);
	//	p = pt;
	p.x += dX;
	p.y += dY;
}

void CSimple274X::TranslateRect(FRECTC &R, double dX, double dY)
{
	//	FRECTC mn( R.X1 + dX, R.Y1 + dY, R.X2 + dX, R.Y2 + dY);
	//	R = mn;
	R.X1 += dX;
	R.Y1 += dY;
	R.X2 += dX;
	R.Y2 += dY;
}

void CSimple274X::cVsV(float fAng, float *cV, float *sV) // Get Rotate parameter, cosine and sine value
{
	int nAng = fmod(fAng + 360.0, 360.0); // normalize angle
	switch (nAng) // 'CCW
	{
	case 0:
		*cV = 1.0;
		*sV = 0.0;
		break;
	case 90:
		*cV = 0.0;
		*sV = 1.0;
		break;
	case 180:
		*cV = -1.0;
		*sV = 0.0;
		break;
	case 270:
		*cV = 0.0;
		*sV = -1.0;
		break;
	default:
		*cV = cos(fAng * DEG2RAD);
		*sV = sin(fAng * DEG2RAD);
		break;
	}
}


FRECTC CSimple274X::GetLayerExtent(int nLayer)
{
	return m_ArLayerInform[nLayer]->Extent;
}

FRECTC CSimple274X::GetLayerMaxExtent()
{
	return m_rectLayerExtent;
}

double CSimple274X::GetScaleOfScreen()
{
	return m_dScaleX;
}


void CSimple274X::SetDrawArcResolution(float fResolution)
{
	m_fDrawArcResolution = fResolution;
}

void CSimple274X::SetDrawResolution(float fResolution)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->SetDrawResolution(fResolution);

	m_fDrawResolution = fResolution;
}

void CSimple274X::AllocDrawList()
{
	// 	m_bDrawFirst=TRUE;
	AllocCamDrawStruct();
	SetDrawResolution(m_fDrawArcResolution);
	// 	int nAperturecnt = MakeApertureList();
	//	SetDrawResolution(m_fDrawArcResolution); // 1/10 of Monitor Pixel resolution
	//	int nLineCnt = MakeLineTemplateList();
	// 	int nSnRObject = MakeSnRObjectList();
}

void CSimple274X::AllocCamDrawStruct()
{
	m_nNumOfAperture = GetNumOfAperture();
	// 	if(m_nNumOfAperture>0)
	// 		m_nListAperture = glGenLists(m_nNumOfAperture);

	m_nNumOfLineTemplate = GetNumOfLineTemplate();
	// 	if(m_nNumOfLineTemplate>0)
	// 		m_glListLines=glGenLists(m_nNumOfLineTemplate);     //Line List

	m_nNumOfSnRObject = GetNumOfSnR();
	// 	if(m_nNumOfSnRObject>0)
	// 		m_glListSnR = glGenLists(m_nNumOfSnRObject);

	//	m_nGLListIndex = 0;
	m_nListIndex = 0;
}


// Draw274X
void CSimple274X::SetHwnd(HWND hCtrlWnd)
{
	m_hCtrl = hCtrlWnd;
}

void CSimple274X::Draw274X()
{
	int i, nLayer;
	CfRect cfExtent;
	int nNumOfLayer = GetNumOfLayer();
	if (nNumOfLayer < 0) return;
	FRECTC rtFrame = GetLayerMaxExtent();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0; fptOrigin.y = 10.0;
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	CRect rtDispCtrl;
	::GetClientRect(m_hCtrl, &rtDispCtrl);
	//::GetWindowRect(m_hCtrl, &rtDispCtrl);
	m_rtDispCtrl = rtDispCtrl;
	m_nWorldW = rtDispCtrl.right - rtDispCtrl.left - 2.0 * fptOrigin.x;
	m_nWorldH = rtDispCtrl.bottom - rtDispCtrl.top - 2.0 * fptOrigin.y;

	int nRealW = rtFrame.X2 - rtFrame.X1;
	int nRealH = rtFrame.Y2 - rtFrame.Y1;

	if (nRealW == 0.0) nRealW = m_nWorldW;
	if (nRealH == 0.0) nRealH = m_nWorldH;

	int nNeedX, nNeedY;
	if ((m_nWorldW - nRealW) < 0.0)
		nNeedX = nRealW - m_nWorldW;
	else
		nNeedX = m_nWorldW - nRealW;
	m_dScaleX = (double)((double)m_nWorldW / (double)nRealW);

	if ((m_nWorldH - nRealH) < 0.0)
		nNeedY = nRealH - m_nWorldH;
	else
		nNeedY = m_nWorldH - nRealH;
	m_dScaleY = (double)((double)m_nWorldH / (double)nRealH);

	if (m_dScaleY > m_dScaleX)
		m_dScaleY = m_dScaleX;
	else
		m_dScaleX = m_dScaleY;

	for (nLayer = 0; nLayer < nNumOfLayer; nLayer++)
	{
		//m_nLayerID = nLayer;
		m_pLayerInfo = m_ArLayerInform.GetAt(nLayer);

		if (m_ArLayerInform[nLayer]->bView)
		{
			//if (nLayer == 0)
			//{
			//	if (nNumOfLayer > 0 && m_ArLayerInform.GetAt(0)->bView && m_ArLayerInform.GetAt(0)->bPolarity == LAYER_TYPE::NEGATIVE)
			//	{
			//		if (m_bDisplayBackgroundImg)
			//		{
			//			cfExtent.left = m_frtDrawFrameExtent.X1;
			//			cfExtent.right = m_frtDrawFrameExtent.X2;
			//			cfExtent.top = m_frtDrawFrameExtent.Y2;
			//			cfExtent.bottom = m_frtDrawFrameExtent.Y1;
			//			SetForeColor(GREY99);
			//			DrawRect(cfExtent, 0, TRUE);
			//		}
			//	}
			//}
			//for (i = 0; i < 4; i++)
			//{
			//	if (m_pThreadDrawing[i])
			//	{
			//		m_pThreadDrawing[i]->Stop();
			//		Sleep(100);
			//		delete m_pThreadDrawing[i];
			//	}
			//	m_pThreadDrawing[i] = new CThreadTask;
			//}
			//m_nPrevAttribute = 16;
			//m_nPrevPolarity = 3;

			Drawing_0();
		}
	}
	m_bCheckDraw = TRUE;
	
}

void CSimple274X::Drawing_0()
{
	int nObjIndex;
	int nNumOfObj, nSt, nDevide;
	GraphObj gObj;
	nNumOfObj = m_pLayerInfo->listObj.size();
	//nNumOfObj = m_pLayerInfo->listObj.size()-1;
	nDevide = int(double(nNumOfObj) / 4.0);
	nSt = nDevide * 0;
	//nNumOfObj = nSt+nDevide;
	//nNumOfObj = nNumOfObj / 2;

 	//m_nPrevAttribute = 16;
 	//m_nPrevPolarity = 3;
	//CDrawRs274X m_DrawRs274X(this);



	DWORD CurTimer, StartTimer;
	StartTimer = GetTickCount();

	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	MSG message;
	if (pParent)
	{
		pParent->ProgressSetDlgCaption(_T("On Drawing Gerber File..."));
		pParent->ProgressSet(0, 0, nNumOfObj);
	}



	SetPixelResolution(m_dPixelResolution);

	for (nObjIndex = nSt; nObjIndex < nNumOfObj; nObjIndex++)
	{
		CurTimer = GetTickCount();
		BOOL bTrig = !(int(CurTimer - StartTimer) % 100); // 100mSec간격으로 ProgressBar 진행.
		if (bTrig)
		{
			if (pParent)
			{
				pParent->ProgressSet(nObjIndex);
				if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
				{
					::TranslateMessage(&message);
					::DispatchMessage(&message);
				}
			}
		}


		gObj = m_pLayerInfo->listObj.at(nObjIndex);

		if (m_bCheckDraw && gObj.Type.nType != DRAW_TYPE::SNR)
		{
			if (gObj.Type.nAttr != DRAW_TYPE::NONE)
			{
				//if (CheckDrawAllow(nObjIndex))
				{
					if (gObj.dCode > 0)
					{
						m_pLayerInfo->mapAptList.Lookup(gObj.dCode, m_pAptDef);
					}
					DrawObject(nObjIndex);
					//DrawObject_0(nObjIndex);//MyObjEntity(nObjIndex,bCheck);
				}
			}
		}
		else
		{
			if (gObj.dCode > 0)
			{
				m_pLayerInfo->mapAptList.Lookup(gObj.dCode, m_pAptDef);
			}
			DrawObject(nObjIndex);
			//DrawObject_0(nObjIndex);//MyObjEntity(nObjIndex, bCheck);
		}
	}


	if (pParent)
	{
		pParent->ProgressSet(nNumOfObj);
		pParent->ProgressActivate(FALSE);//pParent->ProgressClose();
	}

	//m_DrawRs274X.CallApertureList();
	//m_DrawRs274X.CallLineTemplateList();
	//m_DrawRs274X.CallSnRObjectList();
	
}

void CSimple274X::SetPixelResolution(double dPixelResolution)
{
	m_dPixelResolution = dPixelResolution;
}

BOOL CSimple274X::DrawObject(int nObjIndex)
{
	byte dType;
	float  dX, dY, fRadius;
	FPOINTC fptCenter;

	vector <FPOINTC> vecCoord;

	int pNum = 0, i;
	int nID = 0, nIndex = 0;
	TEMPLATE_KEY Key;

	float *fParam;
	FPOINTC *fptCoord;

	GraphObj gObj = m_pLayerInfo->listObj.at(nObjIndex);

	dType = gObj.Type.nType;

	if (m_nPrevAttribute != gObj.Type.nAttr || m_nPrevPolarity != gObj.Type.nPolarity ||
		dType == DRAW_TYPE::POLYGON_SQ || dType == DRAW_TYPE::POLYGON_MQ)
	{
		m_crObjColor = GetObjectColor(gObj);
		SetForeColor(m_crObjColor);
	}

	m_nApertureListIndex = -1;

	float X1, Y1, X2, Y2, X3, Y3; int nListNum;
	switch (dType)
	{
	case DRAW_TYPE::LINE:
		fParam = &m_pAptDef->Param.at(0).fParam[0];


		if (m_pAptDef->chStdAptType == _T('C')) // Then		
		{
			dX = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x - m_pLayerInfo->vecObjCoord[gObj.nStPnt].x;
			dY = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y - m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
			Key.Param[0] = (dX*dX + dY*dY); //length
			Key.Param[1] = m_pAptDef->Param.at(0).fParam[0];// line width

			if (m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
			{
				nID = SearchLineTemplate(Key.key);
				if (nID > -1)
				{
					nID += m_nListLines;//m_glListLines;
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1, X2, Y2);
					X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x; Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//X2 *= m_dScaleX; Y2 *= m_dScaleY;
					//int nSizeLine = 1;
					//DrawBegin(Opengl::modLine, nSizeLine, RGB_RED);
					MyLineList(X1, Y1, X2, Y2, nID);
					//DrawEnd();
					m_nListLines++;
				}
				else
				{
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1, X2, Y2);
					X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x; Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//X2 *= m_dScaleX; Y2 *= m_dScaleY;
					DrawLineRound(X1, Y1, X2, Y2, fParam[0]);
				}
			}
			else
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1, X2, Y2);
				X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x; Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//X2 *= m_dScaleX; Y2 *= m_dScaleY;
				DrawLineRound(X1, Y1, X2, Y2, fParam[0]);
			}
		}
		else if (m_pAptDef->chStdAptType == _T('R')) // Then
		{
			//nIndex = gObj.nStPnt;
			//AdjustToScreen(nIndex, X1, Y1, X2, Y2);
			//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
			//X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x; Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;
			//X1 *= m_dScaleX; Y1 *= m_dScaleY;
			//X2 *= m_dScaleX; Y2 *= m_dScaleY;
			//DrawLineRect(X1, Y1, X2, Y2, fParam[0], fParam[1]);
			DrawLineRect(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y, fParam[0], fParam[1]);
		}
		else if (m_pAptDef->strAptName.GetLength() > 0)
		{
			if (m_pLayerInfo->vecObjCoord[gObj.nStPnt].x == m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x && m_pLayerInfo->vecObjCoord[gObj.nStPnt].y == m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y)
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyMacro(m_pAptDef, X1, Y1, gObj.Type.nPolarity);
				MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, gObj.Type.nPolarity);
			}
			else
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1, X2, Y2);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x; Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//X2 *= m_dScaleX; Y2 *= m_dScaleY;
				//MyMacro(m_pAptDef, X1, Y1, gObj.Type.nPolarity);
				//MyLineMacro(X1, Y1, X2, Y2, m_pAptDef->minmax);
				//MyMacro(m_pAptDef, X2, Y2, gObj.Type.nPolarity);
				MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, gObj.Type.nPolarity);
				MyLineMacro(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y, m_pAptDef->minmax);
				MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y, gObj.Type.nPolarity);
			}
		}
		break;
	case DRAW_TYPE::FLASH: // 'Flash : bType[1]
		m_nApertureListIndex = m_pAptDef->nGlListIndex;

		fParam = &m_pAptDef->Param.at(0).fParam[0];

		if (m_nApertureListIndex > 0)
		{
			if (m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyCallApertureList(X1, Y1, m_nApertureListIndex);
				MyCallApertureList(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, m_nApertureListIndex);
 				////m_csDrawing.Unlock();
				return FALSE;
			}
		}

		pNum = m_pAptDef->Param.at(0).fParam.size();

		if (m_pAptDef->chStdAptType == _T('C'))	//    ' Circle
		{
			if (pNum == 1)
			{
				fRadius = fParam[0] / 2.0; fRadius *= m_dScaleX;
				if (fRadius < 0.0) fRadius = 1.0;
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//DrawCircle(X1, Y1, fRadius);
				DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fRadius);
			}
			else if (pNum == 2)
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//DrawDonut(X1, Y1, fParam[0], fParam[1]);
				DrawDonut(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[1]);
			}
			else if (pNum > 2 && pNum < 5)
			{
				fRadius = fParam[0] / 2.0; fRadius *= m_dScaleX;
				if (fRadius < 0.0) fRadius = 1.0;
				StencilBegin();
 				//glClear(GL_STENCIL_BUFFER_BIT);
 				//glEnable(GL_STENCIL_TEST);
				StencilSet(FALSE);

				if (pNum == 3)
				{
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//MyRectCenter(X1, Y1, fParam[1], fParam[2], 0);
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[1], fParam[2], 0);
				}
				else if (pNum == 4)
				{
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//MyRectCenter(X1, Y1, fParam[1], fParam[2], fParam[3]);
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[1], fParam[2], fParam[3]);
				}
				StencilSet(TRUE);
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//DrawCircle(X1, Y1, fRadius);
				DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fRadius);
				StencilEnd();//glDisable(GL_STENCIL_TEST);
			}
		}
		else if (m_pAptDef->chStdAptType == _T('R'))	//    ' Rectangle
		{
			if (pNum < 3)
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyRectCenter(X1, Y1, fParam[0], fParam[1], 0);
				MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[1], 0);
			}
			else if (pNum < 5)
			{
				StencilBegin();
				//glClear(GL_STENCIL_BUFFER_BIT);
				//glEnable(GL_STENCIL_TEST);
				StencilSet(FALSE);

				if (pNum == 3)
				{
					fRadius = fParam[2] / 2.0; fRadius *= m_dScaleX;
					if (fRadius < 0.0) fRadius = 1.0;
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//DrawCircle(X1, Y1, fRadius);
					DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fRadius);
				}
				else if (pNum == 4)
				{
					nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//MyRectCenter(X1, Y1, fParam[2], fParam[3], 0);
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[2], fParam[3], 0);
				}
				StencilSet(TRUE);
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyRectCenter(X1, Y1, fParam[0], fParam[1], 0);
				MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[1], 0);
				StencilEnd();//glDisable(GL_STENCIL_TEST);
			}
		}
		else if (m_pAptDef->chStdAptType == _T('O'))	//    ' Oval
		{
			if (pNum < 3)
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyOval(X1, Y1, fParam[0], fParam[1]);
				MyOval(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[1]);
			}
			else if (pNum < 5)
			{
				StencilBegin();
				//glClear(GL_STENCIL_BUFFER_BIT);
				//glEnable(GL_STENCIL_TEST);
				StencilSet(FALSE);

				if (pNum == 3)
				{
					fRadius = fParam[2] / 2.0; fRadius *= m_dScaleX;
					if (fRadius < 0.0) fRadius = 1.0;
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//DrawCircle(X1, Y1, fParam[0], fRadius);
					DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fRadius);
				}
				else if (pNum == 4)
				{
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//MyRectCenter(X1, Y1, fParam[2], fParam[3], 0);
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[2], fParam[3], 0);
				}
				StencilSet(TRUE);
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyOval(X1, Y1, fParam[0], fParam[1]);
				MyOval(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[1]);
				StencilEnd();//glDisable(GL_STENCIL_TEST);
			}
		}
		else if (m_pAptDef->chStdAptType == _T('P'))	//    ' Polygon
		{
			int nSide = fParam[1];
			if (pNum < 4)
			{
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyPolygonNSide(nSide, X1, Y1, fParam[0], fParam[2]);
				MyPolygonNSide(nSide, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[2]);
			}
			else
			{
				StencilBegin();
 				//glClear(GL_STENCIL_BUFFER_BIT);
 				//glEnable(GL_STENCIL_TEST);
 				StencilSet(FALSE);

				if (pNum == 4)
				{
					fRadius = fParam[3] / 2.0; fRadius *= m_dScaleX;
					if (fRadius < 0.0) fRadius = 1.0;
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//DrawCircle(X1, Y1, fParam[0], fRadius);
					DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fRadius);
				}
				else if (pNum >= 5)
				{
					//nIndex = gObj.nStPnt;
					//AdjustToScreen(nIndex, X1, Y1);
					//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
					//X1 *= m_dScaleX; Y1 *= m_dScaleY;
					//MyRectCenter(X1, Y1, fParam[0], fParam[3], fParam[4], 0);
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[3], fParam[4], 0);
				}
				StencilSet(TRUE);
				//nIndex = gObj.nStPnt;
				//AdjustToScreen(nIndex, X1, Y1);
				//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
				//X1 *= m_dScaleX; Y1 *= m_dScaleY;
				//MyPolygonNSide(nSide, X1, Y1, fParam[0], fParam[2]);
				MyPolygonNSide(nSide, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, fParam[0], fParam[2]);
				StencilEnd();//glDisable(GL_STENCIL_TEST);
			}
		}
		else //    ' Userdefined Apperture
		{
			//nIndex = gObj.nStPnt;
			//AdjustToScreen(nIndex, X1, Y1);
			//X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x; Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
			//X1 *= m_dScaleX; Y1 *= m_dScaleY;
			//MyMacro(m_pAptDef, X1, Y1, gObj.Type.nPolarity);
			MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, gObj.Type.nPolarity);
			////if(m_nApertureListIndex< 1)
			////{
			//// 	MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y, gObj.Type.nPolarity);		
			////}
			////else
			////{
			//// 	CallList(m_nApertureListIndex);
			//// 	glPushMatrix();
			//// 	glTranslatef(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y,0);
			//// 	glCallList(m_nApertureListIndex);
			//// 	glPopMatrix();	
			////}
		}
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ: // bType[5], bType[6] 'PolygonFill with G74, G75
		MyQuadrantPolygon(&gObj, &m_pLayerInfo->listObj.at(nObjIndex + 1));
		break;
	case DRAW_TYPE::SNR:	// bType[7]
		MySnRObjList(gObj, nObjIndex, 0, 0);
		break;
	case DRAW_TYPE::ARC_CW: // dType == TYPE_CW
		fParam = &m_pAptDef->Param.at(0).fParam[0];
		//nIndex = gObj.nStPnt;
		//AdjustToScreen(nIndex, X1, Y1, X2, Y2, X3, Y3);
		//MyArc(X2, Y2, X1, Y1, X3, Y3, fParam[0], CW);
		MyArc(m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y,
			fParam[0], CW);
		break;
	case DRAW_TYPE::ARC_CCW: // dType == TYPE_CCW
		fParam = &m_pAptDef->Param.at(0).fParam[0];
		//nIndex = gObj.nStPnt;
		//AdjustToScreen(nIndex, X1, Y1, X2, Y2, X3, Y3);
		//MyArc(X2, Y2, X1, Y1, X3, Y3, fParam[0], CCW);
		MyArc(m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y,
			fParam[0], CCW);
		break;
	case DRAW_TYPE::TEXT:
		fParam = &m_pAptDef->Param.at(0).fParam[0];
		//nIndex = gObj.nStPnt;
		//AdjustToScreen(nIndex, X1, Y1);
		//fptCenter.x = X1; fptCenter.y = Y1;
		fptCenter = m_pLayerInfo->vecObjCoord[gObj.nStPnt];
		GetCannedText(m_pAptDef->strAptName, fptCenter, fParam[0] * 1.2, vecCoord);

		m_nApertureListIndex = m_pAptDef->nGlListIndex;
		nIndex = m_pAptDef->Param.at(0).nPriNum;

		if (m_nApertureListIndex > 0)
		{
			fptCoord = &vecCoord[0];
			for (i = 0; i < vecCoord.size(); i++)
			{
				if (nIndex == 98)
					RotatePoint(fptCoord[i], 0.0, 1.0, fptCenter.x, fptCenter.y);
				//X1 = fptCoord[i].x; Y1 = fptCoord[i].y;
				//AdjustToScreen(X1, Y1);
				//MyCallApertureList(X1, Y1, m_nApertureListIndex);
				MyCallApertureList(fptCoord[i].x, fptCoord[i].y, m_nApertureListIndex);
			}
			//m_csDrawing.Unlock();
			return FALSE;
		}
		break;
	}

	return FALSE;
}

COLORREF CSimple274X::GetObjectColorCurrent()
{
	return m_crObjColor;
}

COLORREF CSimple274X::GetObjectColor(GraphObj &obj)
{
	COLORREF crColor;

	m_nPrevAttribute = obj.Type.nAttr;
	m_nPrevPolarity = obj.Type.nPolarity;

	m_pLayerInfo->mapObjColor.Lookup((DRAW_TYPE::ATTRIBUTE)obj.Type.nAttr, crColor);
	if (m_pLayerInfo->bPolarity == LAYER_TYPE::POSITIVE)
	{
		if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
			return GREY99;// WHITE;
		else
			return BLACK;
	}
	else
	{
		if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
			return BLACK;
		else
			return GREY99;// WHITE;
	}

	return BLACK;
}

void CSimple274X::SetForeColor(COLORREF crColor)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->SetForeColor(crColor);
}

int CSimple274X::SearchLineTemplate(UINT64 nVal)
{
	vector <UINT64>::iterator iter;
	iter = std::lower_bound(m_vecLineTemplate.begin(), m_vecLineTemplate.end(), nVal);

	if (iter != m_vecLineTemplate.end() && *iter == nVal)
		return(iter - m_vecLineTemplate.begin());

	return -1;
}

void CSimple274X::MyLineList(float X1, float Y1, float X2, float Y2, int nListNum)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->MyLineList(X1, Y1, X2, Y2, nListNum);
}

void CSimple274X::AdjustToScreen(float& X1, float& Y1)
{
	FRECTC rtFrame = GetLayerMaxExtent();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / m_dScaleX; fptOrigin.y = 10.0 / m_dScaleY; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= m_dScaleX; Y1 *= m_dScaleY;
	if (X1 < 0.0 || X1 > m_nWorldW)
	{
		int kkk = 0;
		return;
	}
}

void CSimple274X::AdjustToScreen(float& X1, float& Y1, float& X2, float& Y2)
{
	FRECTC rtFrame = GetLayerMaxExtent();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / m_dScaleX; fptOrigin.y = 10.0 / m_dScaleY; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= m_dScaleX; Y1 *= m_dScaleY;
	X2 += fptOriginOffset.x; Y2 += fptOriginOffset.y;
	X2 *= m_dScaleX; Y2 *= m_dScaleY;
	if (X1 < 0.0 || X1 > m_nWorldW)
	{
		int kkk = 0;
		return;
	}
}

void CSimple274X::AdjustToScreen(int nIndex, float& X1, float& Y1)
{
	X1 = m_pLayerInfo->vecObjCoord[nIndex].x; Y1 = m_pLayerInfo->vecObjCoord[nIndex].y;
	FRECTC rtFrame = GetLayerMaxExtent();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / m_dScaleX; fptOrigin.y = 10.0 / m_dScaleY; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= m_dScaleX; Y1 *= m_dScaleY;
	if (X1 < 0.0 || X1 > m_nWorldW)
	{
		int kkk = 0;
		return;
	}
}

void CSimple274X::AdjustToScreen(int nIndex, float& X1, float& Y1, float& X2, float& Y2)
{
	X1 = m_pLayerInfo->vecObjCoord[nIndex].x; Y1 = m_pLayerInfo->vecObjCoord[nIndex].y;
	X2 = m_pLayerInfo->vecObjCoord[nIndex + 1].x; Y2 = m_pLayerInfo->vecObjCoord[nIndex + 1].y;
	FRECTC rtFrame = GetLayerMaxExtent();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / m_dScaleX; fptOrigin.y = 10.0 / m_dScaleY; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= m_dScaleX; Y1 *= m_dScaleY;
	X2 += fptOriginOffset.x; Y2 += fptOriginOffset.y;
	X2 *= m_dScaleX; Y2 *= m_dScaleY;
	if (X1 < 0.0 || X2 < 0.0 || X1 > m_nWorldW || X2 > m_nWorldW)
	{
		int kkk = 0;
		return;
	}
}

void CSimple274X::AdjustToScreen(int nIndex, float& X1, float& Y1, float& X2, float& Y2, float& X3, float& Y3)
{
	X1 = m_pLayerInfo->vecObjCoord[nIndex].x; Y1 = m_pLayerInfo->vecObjCoord[nIndex].y;
	X2 = m_pLayerInfo->vecObjCoord[nIndex + 1].x; Y2 = m_pLayerInfo->vecObjCoord[nIndex + 1].y;
	X3 = m_pLayerInfo->vecObjCoord[nIndex + 2].x; Y3 = m_pLayerInfo->vecObjCoord[nIndex + 2].y;
	FRECTC rtFrame = GetLayerMaxExtent();
	FPOINTC fptOrigin, fptOriginOffset; // Screen Pixel
	fptOrigin.x = 10.0 / m_dScaleX; fptOrigin.y = 10.0 / m_dScaleY; // mm
	fptOriginOffset.x = fptOrigin.x - rtFrame.X1; fptOriginOffset.y = fptOrigin.y - rtFrame.Y1;
	X1 += fptOriginOffset.x; Y1 += fptOriginOffset.y;
	X1 *= m_dScaleX; Y1 *= m_dScaleY;
	X2 += fptOriginOffset.x; Y2 += fptOriginOffset.y;
	X2 *= m_dScaleX; Y2 *= m_dScaleY;
	X3 += fptOriginOffset.x; Y3 += fptOriginOffset.y;
	X3 *= m_dScaleX; Y3 *= m_dScaleY;
	if (X1 < 0.0 || X2 < 0.0 || X3 < 0.0 || X1 > m_nWorldW || X2 > m_nWorldW || X3 > m_nWorldW)
	{
		int kkk = 0;
		return;
	}
}
//void CSimple274X::DrawLineRound(float fSx, float fSy, float fEx, float fEy, float fLineWidth, BOOL bFill)
//{
//	vector <FPOINTC> vecVertics;
//	FPOINTC bufPt;
//
//	vecVertics.clear();
//	//vecVertics.clear();
//
//	bufPt.x = fSx;
//	bufPt.y = fSy;
//	float fLineAngle = atan2(fSy - fEy, fSx - fEx);
//	float fBufAngle;
//	float fRadius = fLineWidth / 2.0;
//	fBufAngle = fLineAngle - PI / 2.0;
//	if (fBufAngle < 0)
//		fBufAngle += 2.0*PI;
//
//	GetArcVertices(vecVertics, bufPt, fRadius, fBufAngle, PI, CCW);
//	//GetArcVertices(vecVertics,bufPt,fRadius,fBufAngle,PI,CCW);
//	bufPt.x = fEx;
//	bufPt.y = fEy;
//	fBufAngle += PI;
//	if (fBufAngle > 2.0*PI)
//		fBufAngle -= 2.0*PI;
//
//	GetArcVertices(vecVertics, bufPt, fRadius, fBufAngle, PI, CCW);
//	//GetArcVertices(vecVertics,bufPt,fRadius,fBufAngle,PI,CCW);
//	if (bFill)
//	{
//		DrawConvexPolygon(vecVertics);
//		//DrawConvexPolygon(vecVertics);
//	}
//	else
//	{
//		DrawPolygonLine(vecVertics);
//		//DrawPolygonLine(vecVertics);
//	}
//}

COLORREF CSimple274X::GetSnRObjectColor(GraphObj &obj)
{
	COLORREF crColor;
	m_nPrevAttribute = obj.Type.nAttr;
	m_nPrevPolarity = obj.Type.nPolarity;

	m_pLayerInfo->mapObjColor.Lookup((DRAW_TYPE::ATTRIBUTE)obj.Type.nAttr, crColor);
	if (m_pLayerInfo->bPolarity == LAYER_TYPE::POSITIVE)
	{
		if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
		{
			if (m_bImageSave)
			{
				return crColor;
			}
			else
			{
				return GREY99;
			}
		}
		else
			return BLACK;
	}
	else
	{
		if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
			return BLACK;
		else
		{
			if (m_bImageSave)
			{
				return crColor;
			}
			else
			{
				return GREY99;
			}
		}
	}

	return BLACK;
}

void CSimple274X::GetArcVertices(vector<FPOINTC> &vecPt, const FPOINTC &ptCenter, float radius, float start_angle, float arc_angle, int dir)
{
	float theta, tangetial_factor, radial_factor;
	float x, y, tx, ty;
	FPOINTC BufPt;

	int ii;
	int num_segments = GetArcSegment(radius, arc_angle*RAD2DEG);

	theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	tangetial_factor = tanf(theta);

	radial_factor = cosf(theta);

	x = radius * cosf(start_angle);//we now start at the start angle
	y = radius * sinf(start_angle);


	for (ii = 0; ii < num_segments; ii++)
	{
		BufPt.x = x + ptCenter.x;
		BufPt.y = y + ptCenter.y;
		vecPt.push_back(BufPt);

		if (dir == CW) //cw direction
		{
			tx = y;
			ty = -x;
		}
		else // ccw direction
		{
			tx = -y;
			ty = x;
		}

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
}

int CSimple274X::GetArcSegment(float fRadius, float fAngle)
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

void CSimple274X::DrawConvexPolygon(const vector <FPOINTC> &fPoint)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawConvexPolygon(fPoint);
}

void CSimple274X::DrawConvexPolygon(const FPOINTC *fPoint, int nNumberOfVertex)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawConvexPolygon(fPoint, nNumberOfVertex);
}

void CSimple274X::DrawPolygonLine(const vector <FPOINTC> &vecPt, int nLineWidth)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawPolygonLine(vecPt, nLineWidth);
}

void CSimple274X::DrawLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawLineRect(fSx, fSy, fEx, fEy, fLineWidth, fLineHeight);
}

//BOOL CSimple274X::MyExcellonObjShift(const vector<FPOINTC> &vecObjCoord, GraphObj &gObj, int nObjIndex, float dX, float dY, BOOL bCheck)
//{
//	float dX1, dY1;
//	float fRadius;
//
//	int pNum = 0, i;
//	int nID = 0, nIndex = 0;
//	TEMPLATE_KEY Key;
//
//	float *fParam;
//
//	FPOINTC fptCenter;
//	vector <FPOINTC> vecCoord;
//	FPOINTC *fptCoord;
//	byte dType = gObj.Type.nType;
//
//	LPAPERTURE_DEF pAptDef;
//	m_pLayerInfo->mapAptList.Lookup(gObj.dCode, pAptDef);
//
//	if (m_nPrevAttribute != gObj.Type.nAttr || m_nPrevPolarity != gObj.Type.nPolarity)
//	{
//		m_crObjColor = GetSnRObjectColor(gObj);
//		SetForeColor(m_crObjColor);
//	}
//
//	switch (dType)
//	{
//	case DRAW_TYPE::LINE:
//		fParam = &pAptDef->Param.at(0).fParam[0];
//
//		if (pAptDef->chStdAptType == _T('C')) // Then
//		{
//			if (bCheck)
//			{
//				if (CheckPointInMyLineRound(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, vecObjCoord[1].x + dX, vecObjCoord[1].y + dY, fParam[0], m_fptPickObject.x, m_fptPickObject.y))
//					return TRUE;
//			}
//			else
//			{
//				dX1 = vecObjCoord[1].x - vecObjCoord[0].x;
//				dY1 = vecObjCoord[1].y - vecObjCoord[0].y;
//
//				Key.Param[0] = (dX1*dX1 + dY1*dY1); // thickness
//				Key.Param[1] = pAptDef->Param.at(0).fParam[0];// line width
//
//				if (m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
//				{
//					nID = SearchLineTemplate(Key.key);
//					if (nID > 0)
//					{
//						nID += m_nListLines;
//						MyLineList(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, vecObjCoord[1].x + dX, vecObjCoord[1].y + dY, nID);
//					}
//					else
//						DrawLineRound(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, vecObjCoord[1].x + dX, vecObjCoord[1].y + dY, fParam[0]);
//				}
//				else
//					DrawLineRound(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, vecObjCoord[1].x + dX, vecObjCoord[1].y + dY, fParam[0]);
//
//			}
//		}
//		else if (pAptDef->chStdAptType == _T('R')) // Then
//		{
//			if (bCheck)
//			{
//				if (CheckPointInMyLineRect(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, vecObjCoord[1].x + dX, vecObjCoord[1].y + dY,
//					fParam[0], fParam[1], m_fptPickObject.x, m_fptPickObject.y))
//					return TRUE;
//			}
//			else
//				DrawLineRect(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, vecObjCoord[1].x + dX, vecObjCoord[1].y + dY, fParam[0], fParam[1]);
//		}
//		break;
//
//	case DRAW_TYPE::FLASH:
//		fParam = &pAptDef->Param.at(0).fParam[0];
//
//
//		pNum = pAptDef->Param.at(0).fParam.size();
//
//		m_nApertureListIndex = pAptDef->nGlListIndex;
//		if (m_nApertureListIndex > 0 && !bCheck)
//		{
//			if (m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
//			{
//				MyCallApertureList(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, m_nApertureListIndex);
//				return FALSE;
//			}
//		}
//
//		if (pAptDef->chStdAptType == _T('C'))	//    ' Circle
//		{
//
//			if (pNum == 1)
//			{
//				fRadius = fParam[0] / 2.0;
//				if (bCheck)
//				{
//					if (CheckPointInCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius, m_fptPickObject.x, m_fptPickObject.y))
//						return TRUE;
//				}
//				else
//					DrawCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius);
//			}
//			else if (pNum == 2)
//			{
//				if (bCheck)
//				{
//					if (CheckPointInMyDonut(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1], m_fptPickObject.x, m_fptPickObject.y))
//						return TRUE;
//				}
//				else
//				{
//					DrawDonut(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1]);
//				}
//
//			}
//			else if (pNum < 5)
//			{
//				fRadius = fParam[0] / 2.0;
//				if (bCheck)
//				{
//					if (pNum == 3)
//					{
//						if (MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[1], fParam[2], 0, TRUE))
//							return FALSE;
//					}
//					else if (pNum == 4)
//					{
//						if (MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[1], fParam[2], fParam[3], TRUE))
//							return FALSE;
//					}
//					if (CheckPointInCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius, m_fptPickObject.x, m_fptPickObject.y))
//						return TRUE;
//				}
//				else
//				{
//					StencilBegin();
//					//glClear(GL_STENCIL_BUFFER_BIT);
//					//glEnable(GL_STENCIL_TEST);
//					StencilSet(FALSE);
//
//					if (pNum == 3)
//					{
//						MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[1], fParam[2], 0);
//					}
//					else if (pNum == 4)
//					{
//						MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[1], fParam[2], fParam[3]);
//					}
//					StencilSet(TRUE);
//					DrawCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius);
//					StencilEnd();//glDisable(GL_STENCIL_TEST);
//				}
//			}
//		}
//		else if (pAptDef->chStdAptType == _T('R'))	//    ' Rectangle
//		{
//			if (bCheck)
//			{
//				if (pNum == 3)
//				{
//					fRadius = fParam[2] / 2.0;
//					if (CheckPointInCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius, m_fptPickObject.x, m_fptPickObject.y))
//						return FALSE;
//				}
//				else if (pNum == 4)
//				{
//					if (MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[2], fParam[3], 0, TRUE))
//						return FALSE;
//				}
//				if (MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1], 0, TRUE))
//					return TRUE;
//			}
//			else
//			{
//				if (pNum < 3)
//				{
//					MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1], 0);
//				}
//				else if (pNum < 5)
//				{
//					StencilBegin();
//					//glClear(GL_STENCIL_BUFFER_BIT);
//					//glEnable(GL_STENCIL_TEST);
//					StencilSet(FALSE);
//
//					if (pNum == 3)
//					{
//						fRadius = fParam[2] / 2.0;
//						DrawCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius);
//					}
//					else if (pNum == 4)
//					{
//						MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[2], fParam[3], 0);
//					}
//					StencilSet(TRUE);
//					MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1], 0);
//					StencilEnd();//glDisable(GL_STENCIL_TEST);
//				}
//			}
//		}
//		else if (pAptDef->chStdAptType == _T('O')) //    ' Oval
//		{
//			if (bCheck)
//			{
//				if (pNum == 3)
//				{
//					fRadius = fParam[2] / 2.0;
//					if (CheckPointInCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius, m_fptPickObject.x, m_fptPickObject.y))
//						return FALSE;
//				}
//				else if (pNum == 4)
//				{
//					if (MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[2], fParam[3], 0, bCheck))
//						return FALSE;
//				}
//				if (MyOval(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1], TRUE))
//					return TRUE;
//			}
//			else
//			{
//				if (pNum < 3)
//				{
//					MyOval(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1]);
//				}
//				else if (pNum < 5)
//				{
//					StencilBegin();
//					//glClear(GL_STENCIL_BUFFER_BIT);
//					//glEnable(GL_STENCIL_TEST);
//					StencilSet(FALSE);
//
//					if (pNum == 3)
//					{
//						fRadius = fParam[2] / 2.0;
//						DrawCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius);
//					}
//					else if (pNum == 4)
//					{
//						MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1], 0);
//					}
//					StencilSet(TRUE);
//					MyOval(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[1]);
//					StencilEnd();//glDisable(GL_STENCIL_TEST);
//				}
//			}
//		}
//		else if (pAptDef->chStdAptType == _T('P'))
//		{
//			int nSide = fParam[1];
//
//			if (bCheck)
//			{
//				if (pNum == 4)
//				{
//					fRadius = fParam[3] / 2.0;
//					if (CheckPointInCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius, m_fptPickObject.x, m_fptPickObject.y))
//						return FALSE;
//				}
//				else if (pNum >= 5)
//				{
//					if (MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[3], fParam[4], 0, bCheck))
//						return FALSE;
//				}
//				if (MyPolygonNSide(nSide, vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[2], bCheck))
//					return TRUE;
//			}
//			else
//			{
//				if (pNum < 4)
//				{
//					MyPolygonNSide(nSide, vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[2]);
//				}
//				else
//				{
//					StencilBegin();
//					//glClear(GL_STENCIL_BUFFER_BIT);
//					//glEnable(GL_STENCIL_TEST);
//					StencilSet(FALSE);
//
//					if (pNum == 4)
//					{
//						fRadius = fParam[3] / 2.0;
//						DrawCircle(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fRadius);
//					}
//					else if (pNum >= 5)
//					{
//						MyRectCenter(vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[3], fParam[4], 0);
//					}
//					StencilSet(TRUE);
//					MyPolygonNSide(nSide, vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, fParam[0], fParam[2]);
//					StencilEnd();//glDisable(GL_STENCIL_TEST);
//				}
//			}
//		}
//		else    //    ' Userdefined Apperture
//		{
//			if (bCheck)
//			{
//				if (MyMacro(pAptDef, vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, gObj.Type.nPolarity, bCheck))
//					return TRUE;
//			}
//			else
//				MyMacro(pAptDef, vecObjCoord[0].x + dX, vecObjCoord[0].y + dY, gObj.Type.nPolarity, FALSE);
//		}
//		break;
//	case DRAW_TYPE::POLYGON_SQ:
//	case DRAW_TYPE::POLYGON_MQ:
//		if (bCheck)
//		{
//			if (MyQuadrantPolygonShift(&gObj, &m_pLayerInfo->listObj.at(nObjIndex + 1), dX, dY, bCheck))
//				return TRUE;
//		}
//		else
//			MyQuadrantPolygonShift(&gObj, &m_pLayerInfo->listObj.at(nObjIndex + 1), dX, dY, FALSE);
//		break;
//	case DRAW_TYPE::ARC_CW: // dType == TYPE_CW
//		fParam = &pAptDef->Param.at(0).fParam[0];
//
//
//		if (bCheck)
//		{
//			if (MyArc(vecObjCoord[1].x + dX, vecObjCoord[1].y + dY,
//				vecObjCoord[0].x + dX, vecObjCoord[0].y + dY,
//				vecObjCoord[2].x + dX, vecObjCoord[2].y + dY,
//				fParam[0], CW, bCheck))
//				return TRUE;
//		}
//		else
//		{
//			MyArc(vecObjCoord[1].x + dX, vecObjCoord[1].y + dY,
//				vecObjCoord[0].x + dX, vecObjCoord[0].y + dY,
//				vecObjCoord[2].x + dX, vecObjCoord[2].y + dY,
//				fParam[0], CW, FALSE);
//		}
//		break;
//	case DRAW_TYPE::ARC_CCW: // dType == TYPE_CCW
//		fParam = &pAptDef->Param.at(0).fParam[0];
//
//
//		if (bCheck)
//		{
//			if (MyArc(vecObjCoord[1].x + dX, vecObjCoord[1].y + dY,
//				vecObjCoord[0].x + dX, vecObjCoord[0].y + dY,
//				vecObjCoord[2].x + dX, vecObjCoord[2].y + dY,
//				fParam[0], CCW, bCheck))
//				return TRUE;
//		}
//		else
//		{
//			MyArc(vecObjCoord[1].x + dX, vecObjCoord[1].y + dY,
//				vecObjCoord[0].x + dX, vecObjCoord[0].y + dY,
//				vecObjCoord[2].x + dX, vecObjCoord[2].y + dY,
//				fParam[0], CCW, bCheck);
//		}
//		break;
//	case DRAW_TYPE::TEXT:
//		fParam = &m_pAptDef->Param.at(0).fParam[0];
//		fptCenter = vecObjCoord[0];
//
//		m_pCamData->GetCannedText(m_pAptDef->strAptName, fptCenter, fParam[0] * 1.2, vecCoord);
//
//		m_nApertureListIndex = m_pAptDef->nGlListIndex;
//
//		nIndex = m_pAptDef->Param.at(0).nPriNum;
//		if (m_nApertureListIndex > 0 && !bCheck)
//		{
//			fptCoord = &vecCoord[0];
//			for (i = 0; i < vecCoord.size(); i++)
//			{
//				if (nIndex == 98)
//					m_pTrUtil->RotatePoint(fptCoord[i], 0.0, 1.0, fptCenter.x, fptCenter.y);
//				MyCallApertureList(fptCoord[i].x, fptCoord[i].y, m_nApertureListIndex);
//			}
//			return FALSE;
//		}
//		break;
//	case DRAW_TYPE::SNR:
//		MySnRObjList(gObj, nObjIndex, dX, dY, bCheck);
//		break;
//	}
//
//	return FALSE;
//}

BOOL CSimple274X::MyArc(float fSx, float fSy, float fEx, float fEy, float fCX, float fCY, float fWidth, int nDir, BOOL bCheck)
{
	GLfloat fRadius = GetDistance(CfPoint(fSx, fSy), CfPoint(fCX, fCY));
	if (fSx == fEx && fSy == fEy && (fSx != fCX || fSy != fCY))
	{
		GLfloat fDiameter = fRadius * 2.0;
		if (bCheck)
		{
			if (CheckPointInMyDonut(fCX, fCY, fDiameter + fWidth, fDiameter - fWidth, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
			DrawDonut(fCX, fCY, fDiameter + fWidth, fDiameter - fWidth);
	}
	else
	{
		// Gcd: CW=2, CCW=3
		GLfloat fStartAngle = atan2(fSy - fCY, fSx - fCX);
		GLfloat fEndAngle = atan2(fEy - fCY, fEx - fCX);
		GLfloat fArcAngle;
		if (nDir == CCW)
		{
			if (fEndAngle > fStartAngle)
			{
				fArcAngle = fEndAngle - fStartAngle;
			}
			else
			{
				fArcAngle = 2 * PI - fStartAngle + fEndAngle;
			}
		}
		else
		{
			if (fEndAngle > fStartAngle)
			{
				fArcAngle = 2 * PI - fEndAngle + fStartAngle;
			}
			else
			{
				fArcAngle = fStartAngle - fEndAngle;
			}
		}
		if (bCheck)
		{
			if (CheckArcRound(fCX, fCY, fRadius, fStartAngle, fArcAngle, fWidth, nDir, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
			DrawArcRound(fCX, fCY, fRadius, fStartAngle, fArcAngle, fWidth, nDir);

	}
	return FALSE;
}

BOOL CSimple274X::MyQuadrantPolygonShift(GraphObj *obj, GraphObj *Nextobj, float dX, float dY, BOOL bCheck)
{
	vector <FPOINTC> vecVertics;
	int i, npp, nDir;
	double	fRadius, fStartAngle, fEndAngle, fArcAngle;
	FPOINTC pPre, pPos, pIJ, fPt;

	vecVertics.clear();

	npp = Nextobj->nStPnt - obj->nStPnt - 1;

	pPre = m_pLayerInfo->vecObjCoord[obj->nStPnt];
	pPre.x += dX;
	pPre.y += dY;

	if (npp == 1) //     'Circular Area Fill
	{
		fPt = m_pLayerInfo->vecObjCoord[obj->nStPnt + 1];    //' Center Point
		fRadius = sqrt((pPre.x - fPt.x) * (pPre.x - fPt.x) + (pPre.y - fPt.y) * (pPre.y - fPt.y));
		DrawCircle(fPt.x, fPt.y, fRadius);
	}
	else if (npp >= 2)
	{
		for (i = 1; i <= npp; i++)
		{
			fPt = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
			if (fabs(fPt.x) == DetGcode && fabs(fPt.y) == DetGcode)
			{
				if (fPt.x > 0)	//+DetGCode
					nDir = 1;
				else
					nDir = -1;

				i++;
				pPos = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
				pPos.x += dX;
				pPos.y += dY;

				i++;
				pIJ = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
				pIJ.x += pPre.x;
				pIJ.y += pPre.y;

				fRadius = sqrt((pPos.x - pIJ.x) * (pPos.x - pIJ.x) + (pPos.y - pIJ.y) * (pPos.y - pIJ.y));

				fStartAngle = atan2(pPre.y - pIJ.y, pPre.x - pIJ.x);
				fEndAngle = atan2(pPos.y - pIJ.y, pPos.x - pIJ.x);

				if (nDir == -1)
				{
					if (fEndAngle > fStartAngle)
						fArcAngle = fEndAngle - fStartAngle;
					else
						fArcAngle = 2 * PI - fStartAngle + fEndAngle;
				}
				else
				{
					if (fEndAngle > fStartAngle)
						fArcAngle = 2 * PI - fEndAngle + fStartAngle;
					else
						fArcAngle = fStartAngle - fEndAngle;
				}

				if (fArcAngle == 0)
					fArcAngle = 2 * PI;

				GetArcVertices(vecVertics, pIJ, fRadius, fStartAngle, fArcAngle, nDir);

				fPt = vecVertics.at(vecVertics.size() - 1);

				if (fPt.x != pPos.x || fPt.y != pPos.y)
					vecVertics.push_back(pPos);

			}
			else
			{
				pPos = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
				pPos.x += dX;
				pPos.y += dY;

				vecVertics.push_back(pPos);
			}
			pPre = pPos;
		}
		if (bCheck)
		{
			if (CheckPointInMyConcavePolygon(vecVertics, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
		{
			DrawConcavePolygon(vecVertics);
		}
	}
	return FALSE;
}

BOOL CSimple274X::MySnRObjList(GraphObj &gObj, int nObjIndex, float ddX, float ddY)
{
	int nStObj, nEdObj, nXRepeat, nYRepeat;
	float dX, dY;
	FRECTC  cBoundRect;
	FRECTC  frtObjExtent, fExtent;
	FRECTC frtCurrentExtent;

	BOOL bFind = FALSE, bFoundPickingObj;
	SNR_LIST_INDEX stSnrListIndex;
	int i, j, k, kk, nCoord;
	int nListIndex;

	GraphObj obj;
	vector <FPOINTC> vecObjCoord;
	FPOINTC fptOffset, fptCenter;
	dX = 0;
	dY = 0;

	frtCurrentExtent = m_FrameExtent;//GetFrameExtent();

	nStObj = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x;
	nEdObj = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;

	nXRepeat = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x;
	nYRepeat = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;


	if (gObj.dCode > 0 && m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
	{
		nListIndex = gObj.dCode;

		for (i = 0; i < nXRepeat; i++)
		{
			for (j = 0; j < nYRepeat; j++)
			{
				if (i != 0 || j != 0)
				{
					dX = i*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + ddX;
					dY = j*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + ddY;

					cBoundRect.X1 = gObj.Extent.X1 + dX;
					cBoundRect.Y1 = gObj.Extent.Y1 + dY;
					cBoundRect.X2 = gObj.Extent.X2 + dX;
					cBoundRect.Y2 = gObj.Extent.Y2 + dY;

					//if (CheckDrawAllow(cBoundRect))
					//	CallList(nListIndex);
 					//{			
 					//	glPushMatrix();
 					//	glTranslatef(dX,dY,0.0f);
 					//	glCallList(nListIndex);
 					//	glPopMatrix();					
 					//}
 					//else
 					//{
 					//	int ttt=0;
 					//}
				}
			}
		}
	}
	else
	{
		for (i = 0; i < nXRepeat; i++)
		{
			for (j = 0; j < nYRepeat; j++)
			{
				dX = i*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + ddX;
				dY = j*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + ddY;

				if (i != 0 || j != 0)
				{
					for (int k = nStObj; k <= nEdObj; k++)
					{
						cBoundRect.X1 = gObj.Extent.X1 + dX;
						cBoundRect.Y1 = gObj.Extent.Y1 + dY;
						cBoundRect.X2 = gObj.Extent.X2 + dX;
						cBoundRect.Y2 = gObj.Extent.Y2 + dY;

						if (CheckDrawAllow(cBoundRect))
						{
							MyObjEntityShift(k, dX, dY);
						}
					}
				}
			}
		}
	}

	return bFind;
}

//BOOL CSimple274X::MySnRObjList(GraphObj &gObj, int nObjIndex, float ddX, float ddY, BOOL bCheck)
//{
//	int nStObj, nEdObj, nXRepeat, nYRepeat;
//	float dX, dY;
//	FRECTC  cBoundRect;
//	FRECTC  frtObjExtent, fExtent;
//	FRECTC frtCurrentExtent;
//
//	BOOL bFind = FALSE, bFoundPickingObj;
//	SNR_LIST_INDEX stSnrListIndex;
//	int i, j, k, kk, nCoord;
//	int nListIndex;
//
//	GraphObj obj;
//	vector <FPOINTC> vecObjCoord;
//	FPOINTC fptOffset, fptCenter;
//	dX = 0;
//	dY = 0;
//
//	frtCurrentExtent = GetFrameExtent();
//
//	nStObj = m_pLayerInfo->vecObjCoord[gObj.nStPnt].x;
//	nEdObj = m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;
//
//	nXRepeat = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x;
//	nYRepeat = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y;
//
//	if (m_pLayerInfo->nFormat == CAM_DATA::EXCELLON)
//	{
//		if (nXRepeat == 0)
//			nXRepeat = 1;
//
//		nCoord = m_pLayerInfo->listObj.at(nObjIndex + 1).nStPnt - gObj.nStPnt;
//		fptOffset = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 3];
//
//		frtObjExtent.X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 2].x;
//		frtObjExtent.Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 2].y;
//		frtObjExtent.X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 1].x;
//		frtObjExtent.Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 1].y;
//	}
//
//	if (bCheck)
//	{
//		//if (m_pLayerInfo->nFormat == CAM_DATA::EXCELLON)
//		//{
//		//	dX = ddX;
//		//	dY = ddY;
//		//
//		//	dX += m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x;
//		//	dY += m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y;
//		//
//		//	for (k = nStObj; k <= nEdObj; k++)
//		//	{
//		//		obj = m_pLayerInfo->listObj.at(k);
//		//		vecObjCoord.clear();
//		//
//		//		for (kk = obj.nStPnt; kk < m_pLayerInfo->listObj.at(k + 1).nStPnt; kk++)
//		//		{
//		//			vecObjCoord.push_back(m_pLayerInfo->vecObjCoord[kk]);
//		//		}
//		//		if (nCoord > 6)
//		//		{
//		//			if (m_nActionCode != 0)
//		//				fptCenter = OriginTranslateCoord(vecObjCoord, obj, frtCurrentExtent);
//		//
//		//			for (i = 4; i < nCoord; i++)
//		//			{
//		//				j = (int)m_pLayerInfo->vecObjCoord[gObj.nStPnt + i].x;
//		//				switch (j)
//		//				{
//		//				case 70:
//		//					MirrorHorizontalObject(vecObjCoord, &obj, fptOffset.y);
//		//					RotateObject90(vecObjCoord, &obj, fptOffset);
//		//					break;
//		//				case 80:
//		//					MirrorVerticalObject(vecObjCoord, &obj, fptOffset.x);
//		//					break;
//		//				case 90:
//		//					MirrorHorizontalObject(vecObjCoord, &obj, fptOffset.y);
//		//					break;
//		//				}
//		//			}
//		//			if (m_nActionCode != 0)
//		//				TranslateCoordbyActionCode(vecObjCoord, obj, fptCenter);
//		//		}
//		//
//		//		cBoundRect.X1 = obj.Extent.X1 + dX;
//		//		cBoundRect.Y1 = obj.Extent.Y1 + dY;
//		//		cBoundRect.X2 = obj.Extent.X2 + dX;
//		//		cBoundRect.Y2 = obj.Extent.Y2 + dY;
//		//
//		//		if (obj.Type.nType != DRAW_TYPE::SNR)
//		//		{
//		//			//if (m_bFindObjExtentPickingMode)
//		//			//{
//		//			//	if (m_pTrUtil->CheckRectInRect(&cBoundRect, &m_frtLimitExtent))
//		//			//	{
//		//			//		if (m_pLayerInfo->bPolarity == LAYER_TYPE::POSITIVE)
//		//			//		{
//		//			//			if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
//		//			//				m_nFindObjPolarity = 1;
//		//			//		}
//		//			//		else
//		//			//		{
//		//			//			if (obj.Type.nPolarity == DRAW_TYPE::NEGATIVE)
//		//			//				m_nFindObjPolarity = 1;
//		//			//		}
//		//			//
//		//			//		if (m_frtFindObjExtent.X1 > cBoundRect.X1)	m_frtFindObjExtent.X1 = cBoundRect.X1;
//		//			//		if (m_frtFindObjExtent.Y1 > cBoundRect.Y1)	m_frtFindObjExtent.Y1 = cBoundRect.Y1;
//		//			//		if (m_frtFindObjExtent.X2 < cBoundRect.X2)	m_frtFindObjExtent.X2 = cBoundRect.X2;
//		//			//		if (m_frtFindObjExtent.Y2 < cBoundRect.Y2)	m_frtFindObjExtent.Y2 = cBoundRect.Y2;
//		//			//	}
//		//			//	continue;
//		//			//}
//		//
//		//			if (CheckPointInRect(cBoundRect, m_fptPickObject.x, m_fptPickObject.y))
//		//			{
//		//				if (MyExcellonObjShift(vecObjCoord, obj, k, dX, dY, TRUE))
//		//				{
//		//					bFoundPickingObj = FALSE;
//		//					if (m_pLayerInfo->bPolarity == LAYER_TYPE::POSITIVE)
//		//					{
//		//						if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
//		//						{
//		//							bFoundPickingObj = TRUE;
//		//						}
//		//					}
//		//					else
//		//					{
//		//						if (obj.Type.nPolarity == DRAW_TYPE::NEGATIVE)
//		//						{
//		//							bFoundPickingObj = TRUE;
//		//						}
//		//					}
//		//					if (bFoundPickingObj)
//		//					{
//		//						bFind = TRUE;
//		//						PICKING_OBJ_INFORM stPickObjInfo;
//		//
//		//						stPickObjInfo.gObj = gObj;
//		//
//		//						stPickObjInfo.nObjID = nObjIndex;
//		//						stPickObjInfo.vecDrawObjIDList.push_back(k);
//		//						stPickObjInfo.nLayerID = m_nLayerID;
//		//
//		//						stPickObjInfo.dX = dX;
//		//						stPickObjInfo.dY = dY;
//		//
//		//						m_vecPickingObjInform.push_back(stPickObjInfo);
//		//					}
//		//				}
//		//			}
//		//		}
//		//		else
//		//			MyExcellonObjShift(vecObjCoord, obj, k, dX, dY, TRUE);
//		//	}
//		//}
//		//else
//		{
//			for (i = 0; i < nXRepeat; i++)
//			{
//				for (j = 0; j < nYRepeat; j++)
//				{
//					dX = i*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + ddX;
//					dY = j*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + ddY;
//
//					if (i != 0 || j != 0)
//					{
//						for (int k = nStObj; k <= nEdObj; k++)
//						{
//							cBoundRect.X1 = gObj.Extent.X1 + dX;
//							cBoundRect.Y1 = gObj.Extent.Y1 + dY;
//							cBoundRect.X2 = gObj.Extent.X2 + dX;
//							cBoundRect.Y2 = gObj.Extent.Y2 + dY;
//
//							if (CheckPointInRect(cBoundRect, m_fptPickObject.x, m_fptPickObject.y))
//							{
//								if (MyObjEntityShift(k, dX, dY, TRUE))
//								{
//									obj = m_pLayerInfo->listObj.at(k);
//									bFoundPickingObj = FALSE;
//
//									//if (m_bFindObjExtentPickingMode)
//									//{
//									//	fExtent.X1 = obj.Extent.X1 + dX;
//									//	fExtent.Y1 = obj.Extent.Y1 + dY;
//									//	fExtent.X1 = obj.Extent.X1 + dX;
//									//	fExtent.Y1 = obj.Extent.Y1 + dY;
//									//	if (m_pTrUtil->CheckRectInRect(&fExtent, &m_frtLimitExtent))
//									//	{
//									//		if (m_pLayerInfo->bPolarity == LAYER_TYPE::POSITIVE)
//									//		{
//									//			if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
//									//				m_nFindObjPolarity = 1;
//									//		}
//									//		else
//									//		{
//									//			if (obj.Type.nPolarity == DRAW_TYPE::NEGATIVE)
//									//				m_nFindObjPolarity = 1;
//									//		}
//									//
//									//		if (m_frtFindObjExtent.X1 > fExtent.X1)	m_frtFindObjExtent.X1 = fExtent.X1;
//									//		if (m_frtFindObjExtent.Y1 > fExtent.Y1)	m_frtFindObjExtent.Y1 = fExtent.Y1;
//									//		if (m_frtFindObjExtent.X2 < fExtent.X2)	m_frtFindObjExtent.X2 = fExtent.X2;
//									//		if (m_frtFindObjExtent.Y2 < fExtent.Y2)	m_frtFindObjExtent.Y2 = fExtent.Y2;
//									//	}
//									//	continue;
//									//}
//
//									if (m_pLayerInfo->bPolarity == LAYER_TYPE::POSITIVE)
//									{
//										if (obj.Type.nPolarity == DRAW_TYPE::POSITIVE)
//										{
//											bFoundPickingObj = TRUE;
//										}
//									}
//									else
//									{
//										if (obj.Type.nPolarity == DRAW_TYPE::NEGATIVE)
//										{
//											bFoundPickingObj = TRUE;
//										}
//									}
//									if (bFoundPickingObj)
//									{
//										bFind = TRUE;
//										PICKING_OBJ_INFORM stPickObjInfo;
//
//										stPickObjInfo.gObj = gObj;
//
//										stPickObjInfo.nObjID = nObjIndex;
//										stPickObjInfo.vecDrawObjIDList.push_back(k);
//										stPickObjInfo.nLayerID = m_nLayerID;
//
//										stPickObjInfo.dX = dX;
//										stPickObjInfo.dY = dY;
//
//										m_vecPickingObjInform.push_back(stPickObjInfo);
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	else
//	{
//		if (gObj.dCode > 0 && m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
//		{
//			nListIndex = gObj.dCode;
//			if (m_pLayerInfo->nFormat == CAM_DATA::EXCELLON)
//			{
//				dX = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + ddX;
//				dY = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + ddY;
//
//				nCoord = m_pLayerInfo->listObj.at(nObjIndex + 1).nStPnt - gObj.nStPnt;
//
//				cBoundRect.X1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 2].x;
//				cBoundRect.Y1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 2].y;
//				cBoundRect.X2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 1].x;
//				cBoundRect.Y2 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + nCoord - 1].y;
//
//
//				if (CheckDrawAllow(cBoundRect))
//				{
//					glPushMatrix();
//					glTranslatef(dX, dY, 0.0f);
//					glCallList(nListIndex);
//					glPopMatrix();
//				}
//			}
//			else
//			{
//				for (i = 0; i < nXRepeat; i++)
//				{
//					for (j = 0; j < nYRepeat; j++)
//					{
//						if (i != 0 || j != 0)
//						{
//							dX = i*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + ddX;
//							dY = j*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + ddY;
//
//							cBoundRect.X1 = gObj.Extent.X1 + dX;
//							cBoundRect.Y1 = gObj.Extent.Y1 + dY;
//							cBoundRect.X2 = gObj.Extent.X2 + dX;
//							cBoundRect.Y2 = gObj.Extent.Y2 + dY;
//
//							if (CheckDrawAllow(cBoundRect))
//							{
//								glPushMatrix();
//								glTranslatef(dX, dY, 0.0f);
//								glCallList(nListIndex);
//								glPopMatrix();
//							}
//							else
//							{
//								int ttt = 0;
//							}
//						}
//					}
//				}
//			}
//		}
//		else
//		{
//			if (m_pLayerInfo->nFormat == CAM_DATA::EXCELLON)
//			{
//				dX = ddX;
//				dY = ddY;
//
//				dX += m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x;
//				dY += m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y;
//
//				for (k = nStObj; k <= nEdObj; k++)
//				{
//					obj = m_pLayerInfo->listObj.at(k);
//					if (obj.Type.nAttr == DRAW_TYPE::NONE)
//						continue;
//
//					vecObjCoord.clear();
//					for (kk = obj.nStPnt; kk < m_pLayerInfo->listObj.at(k + 1).nStPnt; kk++)
//					{
//						vecObjCoord.push_back(m_pLayerInfo->vecObjCoord[kk]);
//					}
//					if (nCoord > 6)
//					{
//						if (m_nActionCode != 0)
//							fptCenter = OriginTranslateCoord(vecObjCoord, obj, frtCurrentExtent);
//
//						for (i = 4; i < nCoord; i++)
//						{
//							j = (int)m_pLayerInfo->vecObjCoord[gObj.nStPnt + i].x;
//							switch (j)
//							{
//							case 70:
//								m_pCamData->MirrorHorizontalObject(vecObjCoord, &obj, fptOffset.y);
//								m_pCamData->RotateObject90(vecObjCoord, &obj, fptOffset);
//								break;
//							case 80:
//								m_pCamData->MirrorVerticalObject(vecObjCoord, &obj, fptOffset.x);
//								break;
//							case 90:
//								m_pCamData->MirrorHorizontalObject(vecObjCoord, &obj, fptOffset.y);
//								break;
//							}
//						}
//						if (m_nActionCode != 0)
//							TranslateCoordbyActionCode(vecObjCoord, obj, fptCenter);
//					}
//					cBoundRect.X1 = obj.Extent.X1 + dX;
//					cBoundRect.Y1 = obj.Extent.Y1 + dY;
//					cBoundRect.X2 = obj.Extent.X2 + dX;
//					cBoundRect.Y2 = obj.Extent.Y2 + dY;
//
//					if (obj.Type.nType != DRAW_TYPE::SNR)
//					{
//						if (CheckDrawAllow(cBoundRect))
//						{
//							MyExcellonObjShift(vecObjCoord, obj, k, dX, dY, FALSE);
//						}
//					}
//					else
//						MyExcellonObjShift(vecObjCoord, obj, k, dX, dY, FALSE);
//				}
//			}
//			else
//			{
//				for (i = 0; i < nXRepeat; i++)
//				{
//					for (j = 0; j < nYRepeat; j++)
//					{
//						dX = i*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + ddX;
//						dY = j*m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + ddY;
//
//						if (i != 0 || j != 0)
//						{
//							for (int k = nStObj; k <= nEdObj; k++)
//							{
//								cBoundRect.X1 = gObj.Extent.X1 + dX;
//								cBoundRect.Y1 = gObj.Extent.Y1 + dY;
//								cBoundRect.X2 = gObj.Extent.X2 + dX;
//								cBoundRect.Y2 = gObj.Extent.Y2 + dY;
//
//								if (CheckDrawAllow(cBoundRect))
//								{
//									MyObjEntityShift(k, dX, dY, FALSE);
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return bFind;
//}

FPOINTC CSimple274X::OriginTranslateCoord(vector <FPOINTC> &vecCoord, GraphObj &gObj, FRECTC fExtent)
{
	int i, nNumOfCoord;
	float XX, YY;
	FPOINTC fptCenter;

	ldiv_t Rem = ldiv(m_nActionCode, 10);

	fptCenter.x = (fExtent.X1 + fExtent.X2) / 2.0;
	fptCenter.y = (fExtent.Y1 + fExtent.Y2) / 2.0;

	nNumOfCoord = vecCoord.size();
	if (Rem.rem > 0)
	{
		for (i = 0; i < nNumOfCoord; i++)
		{
			switch (Rem.rem)
			{
			case TRANSFORM_DATA::MIRROR_V:
				vecCoord.at(i).x = -(vecCoord.at(i).x - fptCenter.x) + fptCenter.x;
				break;
			case TRANSFORM_DATA::MIRROR_H:
				vecCoord.at(i).y = -(vecCoord.at(i).y - fptCenter.y) + fptCenter.y;
				break;
			case TRANSFORM_DATA::ROTATE_180:
				//m_pTrUtil->cVsV(180, &cV, &sV);
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint180(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CCW:
				//m_pTrUtil->cVsV(-90, &cV, &sV);							// CW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint270(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CW:
				//m_pTrUtil->cVsV(90, &cV, &sV);							// CCW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint90(vecCoord.at(i), fptCenter);

				break;
			}
		}

		switch (Rem.rem)
		{
		case TRANSFORM_DATA::MIRROR_V:
			gObj.Extent.X1 = -(gObj.Extent.X1 - fptCenter.x) + fptCenter.x;
			gObj.Extent.X2 = -(gObj.Extent.X2 - fptCenter.x) + fptCenter.x;
			if (gObj.Extent.X1 > gObj.Extent.X2)
			{
				XX = gObj.Extent.X1;
				gObj.Extent.X1 = gObj.Extent.X2;
				gObj.Extent.X2 = XX;
			}
			break;
		case TRANSFORM_DATA::MIRROR_H:
			gObj.Extent.Y1 = -(gObj.Extent.Y1 - fptCenter.y) + fptCenter.y;
			gObj.Extent.Y2 = -(gObj.Extent.Y2 - fptCenter.y) + fptCenter.y;
			if (gObj.Extent.Y1 > gObj.Extent.Y2)
			{
				YY = gObj.Extent.Y1;
				gObj.Extent.Y1 = gObj.Extent.Y2;
				gObj.Extent.Y2 = YY;
			}
			break;
		case TRANSFORM_DATA::ROTATE_180:
			//m_pTrUtil->cVsV(180, &cV, &sV);
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			RotateRect180(gObj.Extent, fptCenter);
			RotatePoint180(fptCenter, fptCenter);
			break;
		case TRANSFORM_DATA::ROTATE_CCW:
 		//	m_pTrUtil->cVsV(-90, &cV, &sV);		
 		//	m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);// CW Rotate
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			RotateRect270(gObj.Extent, fptCenter);
			RotatePoint270(fptCenter, fptCenter);
			break;
		case TRANSFORM_DATA::ROTATE_CW:
			//m_pTrUtil->cVsV(90, &cV, &sV);
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);// CCW Rotate
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);		
			RotateRect270(gObj.Extent, fptCenter);
			RotatePoint90(fptCenter, fptCenter);
			break;
		}
	}

	if (Rem.quot > 0)
	{
		for (i = 0; i < nNumOfCoord; i++)
		{
			switch (Rem.quot)
			{
			case TRANSFORM_DATA::MIRROR_V:
				vecCoord.at(i).x = -(vecCoord.at(i).x - fptCenter.x) + fptCenter.x;
				break;
			case TRANSFORM_DATA::MIRROR_H:
				vecCoord.at(i).y = -(vecCoord.at(i).y - fptCenter.y) + fptCenter.y;
				break;
			case TRANSFORM_DATA::ROTATE_180:
				//m_pTrUtil->cVsV(180, &cV, &sV);
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint180(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CCW:
				//m_pTrUtil->cVsV(-90, &cV, &sV);							// CW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint270(vecCoord.at(i), fptCenter);
				break;
			case TRANSFORM_DATA::ROTATE_CW:
				//m_pTrUtil->cVsV(90, &cV, &sV);							// CCW Rotate
				//m_pCamData->RotateTranslatePoint(vecCoord.at(i), cV, sV, fptCenter.x, fptCenter.y, 0, 0);
				RotatePoint90(vecCoord.at(i), fptCenter);
				break;
			}
		}

		switch (Rem.quot)
		{
		case TRANSFORM_DATA::MIRROR_V:
			gObj.Extent.X1 = -(gObj.Extent.X1 - fptCenter.x) + fptCenter.x;
			gObj.Extent.X2 = -(gObj.Extent.X2 - fptCenter.x) + fptCenter.x;
			if (gObj.Extent.X1 > gObj.Extent.X2)
			{
				XX = gObj.Extent.X1;
				gObj.Extent.X1 = gObj.Extent.X2;
				gObj.Extent.X2 = XX;
			}
			break;
		case TRANSFORM_DATA::MIRROR_H:
			gObj.Extent.Y1 = -(gObj.Extent.Y1 - fptCenter.y) + fptCenter.y;
			gObj.Extent.Y2 = -(gObj.Extent.Y2 - fptCenter.y) + fptCenter.y;
			if (gObj.Extent.Y1 > gObj.Extent.Y2)
			{
				YY = gObj.Extent.Y1;
				gObj.Extent.Y1 = gObj.Extent.Y2;
				gObj.Extent.Y2 = YY;
			}
			break;
		case TRANSFORM_DATA::ROTATE_180:
			//m_pTrUtil->cVsV(180, &cV, &sV);
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			RotateRect180(gObj.Extent, fptCenter);
			RotatePoint180(fptCenter, fptCenter);
			break;
		case TRANSFORM_DATA::ROTATE_CCW:
			//m_pTrUtil->cVsV(-90, &cV, &sV);			// CW Rotate
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			RotateRect270(gObj.Extent, fptCenter);
			RotatePoint270(fptCenter, fptCenter);
			break;
		case TRANSFORM_DATA::ROTATE_CW:
			//m_pTrUtil->cVsV(90, &cV, &sV);							// CCW Rotate
			//m_pCamData->RotateTranslateExtent(gObj.Extent, cV, sV, fptCenter.x, fptCenter.y, 0, 0);
			//m_pCamData->RotateTranslatePoint(fptCenter, cV, sV, fptCenter.x, fptCenter.y, 0, 0);		
			RotateRect90(gObj.Extent, fptCenter);
			RotatePoint90(fptCenter, fptCenter);
			break;
		}
	}

	return fptCenter;
}

BOOL CSimple274X::MyQuadrantPolygon(GraphObj *obj, GraphObj *NextObj, BOOL bCheck)
{
	vector <FPOINTC> vecVertics;

	int i, npp, nDir;
	double	fRadius, fStartAngle, fEndAngle, fArcAngle;
	FPOINTC pPre, pPos, pIJ, fPt;

	vecVertics.clear();
	npp = NextObj->nStPnt - obj->nStPnt - 1;

	pPre = m_pLayerInfo->vecObjCoord[obj->nStPnt];

	if (npp == 1) //     'Circular Area Fill
	{
		fPt = m_pLayerInfo->vecObjCoord[obj->nStPnt + 1];    //' Center Point
		fRadius = sqrt((pPre.x - fPt.x) * (pPre.x - fPt.x) + (pPre.y - fPt.y) * (pPre.y - fPt.y));
		if (bCheck)
		{
			if (CheckPointInCircle(fPt.x, fPt.y, fRadius, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
			DrawCircle(fPt.x, fPt.y, fRadius);
	}
	else if (npp >= 2)
	{
		for (i = 1; i <= npp; i++)
		{
			fPt = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
			if (fabs(fPt.x) == DetGcode && fabs(fPt.y) == DetGcode)
			{
				if (fPt.x > 0)	//+DetGCode
					nDir = 1;
				else
					nDir = -1;

				i++;
				pPos = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];

				i++;
				pIJ = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
				pIJ.x += pPre.x;
				pIJ.y += pPre.y;

				fRadius = sqrt((pPos.x - pIJ.x) * (pPos.x - pIJ.x) + (pPos.y - pIJ.y) * (pPos.y - pIJ.y));

				fStartAngle = atan2(pPre.y - pIJ.y, pPre.x - pIJ.x);
				fEndAngle = atan2(pPos.y - pIJ.y, pPos.x - pIJ.x);

				if (nDir == -1)
				{
					if (fEndAngle > fStartAngle)
						fArcAngle = fEndAngle - fStartAngle;
					else
						fArcAngle = 2 * PI - fStartAngle + fEndAngle;
				}
				else
				{
					if (fEndAngle > fStartAngle)
						fArcAngle = 2 * PI - fEndAngle + fStartAngle;
					else
						fArcAngle = fStartAngle - fEndAngle;
				}

				if (fArcAngle == 0)
					fArcAngle = 2 * PI;

				GetArcVertices(vecVertics, pIJ, fRadius, fStartAngle, fArcAngle, nDir);

				fPt = vecVertics.at(vecVertics.size() - 1);

				if (fPt.x != pPos.x || fPt.y != pPos.y)
					vecVertics.push_back(pPos);
			}
			else
			{
				pPos = m_pLayerInfo->vecObjCoord[obj->nStPnt + i];
				if (pPre.x != pPos.x || pPre.y != pPos.y)
					vecVertics.push_back(pPos);
				//vecVertics.push_back(pPos);
			}

			pPre = pPos;
		}


		if (bCheck)
		{
			if (CheckPointInMyConcavePolygon(vecVertics, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
		{
			DrawConcavePolygon(vecVertics);
		}
	}
	return FALSE;
}

BOOL CSimple274X::MyOval(float fCx, float fCy, float fWidth, float fHeight, BOOL bCheck)
{
	float  X1, Y1, X2, Y2, d, ww;

	if (fWidth > fHeight)
	{
		ww = fHeight;
		d = (fWidth - ww) / 2;
		X1 = fCx - d;
		Y1 = fCy;
		X2 = fCx + d;
		Y2 = fCy;
	}
	else
	{
		ww = fWidth;
		d = (fHeight - ww) / 2;
		X1 = fCx;
		Y1 = fCy - d;
		X2 = fCx;
		Y2 = fCy + d;
	}
	if (bCheck)
	{
		if (CheckPointInMyLineRound(X1, Y1, X2, Y2, ww, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
		DrawLineRound(X1, Y1, X2, Y2, ww);
	return FALSE;
}

BOOL CSimple274X::MyLineMacro(float fSx, float fSy, float fEx, float fEy, FRECTC fExtent, BOOL bCheck)
{
	vector <FPOINTC> vecVertics;

	float fWidth, fHeight, fTheta;
	FPOINTC fptCoord;

	fWidth = (fExtent.X2 - fExtent.X1) / 2.0;
	fHeight = (fExtent.Y2 - fExtent.Y1) / 2.0;

	vecVertics.clear();

	if (fSx != fEx && fSy != fEy)
	{
		fTheta = atan2(fabs(fEy - fSy), fabs(fEx - fSx));
		fWidth = fWidth * cos(fTheta);
		fHeight = fHeight * sin(fTheta);
	}

	if (fSx == fEx)
	{
		fptCoord.x = fSx - fWidth;
		fptCoord.y = fSy;
		vecVertics.push_back(fptCoord);
		fptCoord.x = fSx + fWidth;
		fptCoord.y = fSy;
		vecVertics.push_back(fptCoord);
		fptCoord.x = fEx + fWidth;
		fptCoord.y = fEy;
		vecVertics.push_back(fptCoord);
		fptCoord.x = fEx - fWidth;
		fptCoord.y = fEy;
		vecVertics.push_back(fptCoord);
	}
	else if (fEx > fSx)
	{
		if (fSy == fEy)
		{
			fptCoord.x = fSx;
			fptCoord.y = fSy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fSx;
			fptCoord.y = fSy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx;
			fptCoord.y = fEy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx;
			fptCoord.y = fEy - fHeight;
			vecVertics.push_back(fptCoord);
		}
		else if (fEy > fSy)
		{
			fptCoord.x = fSx + fWidth;
			fptCoord.y = fSy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fSx - fWidth;
			fptCoord.y = fSy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx - fWidth;
			fptCoord.y = fEy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx + fWidth;
			fptCoord.y = fEy - fHeight;
			vecVertics.push_back(fptCoord);
		}
		else
		{
			fptCoord.x = fSx - fWidth;
			fptCoord.y = fSy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fSx + fWidth;
			fptCoord.y = fSy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx + fWidth;
			fptCoord.y = fEy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx - fWidth;
			fptCoord.y = fEy - fHeight;
			vecVertics.push_back(fptCoord);
		}
	}
	else
	{
		if (fSy == fEy)
		{
			fptCoord.x = fSx;
			fptCoord.y = fSy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fSx;
			fptCoord.y = fSy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx;
			fptCoord.y = fEy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx;
			fptCoord.y = fEy + fHeight;
			vecVertics.push_back(fptCoord);
		}
		else if (fEy > fSy)
		{
			fptCoord.x = fSx + fWidth;
			fptCoord.y = fSy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fSx - fWidth;
			fptCoord.y = fSy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx - fWidth;
			fptCoord.y = fEy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx + fWidth;
			fptCoord.y = fEy + fHeight;
			vecVertics.push_back(fptCoord);
		}
		else
		{
			fptCoord.x = fSx - fWidth;
			fptCoord.y = fSy + fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fSx + fWidth;
			fptCoord.y = fSy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx + fWidth;
			fptCoord.y = fEy - fHeight;
			vecVertics.push_back(fptCoord);
			fptCoord.x = fEx - fWidth;
			fptCoord.y = fEy + fHeight;
			vecVertics.push_back(fptCoord);
		}
	}

	if (bCheck)
	{
		if (CheckPointInMyConcavePolygon(vecVertics, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
	{
		DrawConcavePolygon(vecVertics);
	}

	return FALSE;
}

BOOL CSimple274X::MyObjEntityShift(int k, float dX, float dY)
{
	float dX1, dY1;
	float fRadius;

	int pNum = 0;
	int nID = 0, nIndex = 0;
	TEMPLATE_KEY Key;

	float *fParam;

	GraphObj gObj = m_pLayerInfo->listObj.at(k);

	if (gObj.Type.nAttr == DRAW_TYPE::NONE)
		return FALSE;

	// 	if(m_bFindLineObjPickingMode)
	// 	{
	// 		if(gObj.Type.nType != DRAW_TYPE::LINE)
	// 			return FALSE;
	// 	}


	byte dType = gObj.Type.nType;

	LPAPERTURE_DEF pAptDef;
	m_pLayerInfo->mapAptList.Lookup(gObj.dCode, pAptDef);


	if (m_nPrevAttribute != gObj.Type.nAttr || m_nPrevPolarity != gObj.Type.nPolarity)
	{
		m_crObjColor = GetSnRObjectColor(gObj);
		SetForeColor(m_crObjColor);
	}

	switch (dType)
	{
	case DRAW_TYPE::LINE:
		fParam = &pAptDef->Param.at(0).fParam[0];

		if (pAptDef->chStdAptType == _T('C')) // Then
		{
			dX1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x - m_pLayerInfo->vecObjCoord[gObj.nStPnt].x;
			dY1 = m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y - m_pLayerInfo->vecObjCoord[gObj.nStPnt].y;

			Key.Param[0] = (dX1*dX1 + dY1*dY1); // thickness
			Key.Param[1] = pAptDef->Param.at(0).fParam[0];// line width

			if (m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
			{
				nID = SearchLineTemplate(Key.key);
				if (nID > 0)
				{
					nID += m_nListLines;//m_glListLines;										
					MyLineList(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY, nID);
				}
				else
					DrawLineRound(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY, fParam[0]);
			}
			else
				DrawLineRound(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY, fParam[0]);
		}
		else if (pAptDef->chStdAptType == _T('R')) // Then
		{
			DrawLineRect(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY, fParam[0], fParam[1]);
		}
		else if (m_pAptDef->strAptName.GetLength() > 0)
		{
			if (m_pLayerInfo->vecObjCoord[gObj.nStPnt].x == m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x && m_pLayerInfo->vecObjCoord[gObj.nStPnt].y == m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y)
			{
				MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, gObj.Type.nPolarity);
			}
			else
			{
				MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, gObj.Type.nPolarity);
				MyLineMacro(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY, m_pAptDef->minmax);
				MyMacro(m_pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY, gObj.Type.nPolarity);
			}
		}
		break;

	case DRAW_TYPE::FLASH:
		fParam = &pAptDef->Param.at(0).fParam[0];

		pNum = pAptDef->Param.at(0).fParam.size();

		m_nApertureListIndex = pAptDef->nGlListIndex;
		if (m_nApertureListIndex > 0)
		{
			if (m_fCanvasPixelResolution > m_fDrawArcResolution) // 1/10 of Monitor Pixel resolution
			{
				MyCallApertureList(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, m_nApertureListIndex);
				return FALSE;
			}
		}

		if (pAptDef->chStdAptType == _T('C'))	//    ' Circle
		{

			if (pNum == 1)
			{
				fRadius = fParam[0] / 2.0; fRadius *= m_dScaleX;
				if (fRadius < 0.0) fRadius = 1.0;
				DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fRadius);
			}
			else if (pNum == 2)
			{
				DrawDonut(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[1]);
			}
			else if (pNum < 5)
			{
				fRadius = fParam[0] / 2.0; fRadius *= m_dScaleX;
				if (fRadius < 0.0) fRadius = 1.0;
				//glClear(GL_STENCIL_BUFFER_BIT);
				//glEnable(GL_STENCIL_TEST);
				//SetStencil(FALSE);

				if (pNum == 3)
				{
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[1], fParam[2], 0);
				}
				else if (pNum == 4)
				{
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[1], fParam[2], fParam[3]);
				}
				//SetStencil(TRUE);
				DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fRadius);
				//glDisable(GL_STENCIL_TEST);
			}
		}
		else if (pAptDef->chStdAptType == _T('R'))	//    ' Rectangle
		{
			if (pNum < 3)
			{
				MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[1], 0);
			}
			else if (pNum < 5)
			{
				//glClear(GL_STENCIL_BUFFER_BIT);
				//glEnable(GL_STENCIL_TEST);
				//SetStencil(FALSE);

				if (pNum == 3)
				{
					fRadius = fParam[2] / 2.0; fRadius *= m_dScaleX;
					if (fRadius < 0.0) fRadius = 1.0;
					DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fRadius);
				}
				else if (pNum == 4)
				{
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[2], fParam[3], 0);
				}
				//SetStencil(TRUE);
				MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[1], 0);
				//glDisable(GL_STENCIL_TEST);
			}
		}
		else if (pAptDef->chStdAptType == _T('O')) //    ' Oval
		{
			if (pNum < 3)
			{
				MyOval(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[1]);
			}
			else if (pNum < 5)
			{
				//glClear(GL_STENCIL_BUFFER_BIT);
				//glEnable(GL_STENCIL_TEST);
				//SetStencil(FALSE);

				if (pNum == 3)
				{
					fRadius = fParam[2] / 2.0; fRadius *= m_dScaleX;
					if (fRadius < 0.0) fRadius = 1.0;
					DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fRadius);
				}
				else if (pNum == 4)
				{
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[1], 0);
				}
				//SetStencil(TRUE);
				MyOval(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[1]);
				//glDisable(GL_STENCIL_TEST);
			}
		}
		else if (pAptDef->chStdAptType == _T('P'))
		{
			int nSide = fParam[1];

			if (pNum < 4)
			{
				MyPolygonNSide(nSide, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[2]);
			}
			else
			{
				//glClear(GL_STENCIL_BUFFER_BIT);
				//glEnable(GL_STENCIL_TEST);
				//m_GLDraw.SetStencil(FALSE);

				if (pNum == 4)
				{
					fRadius = fParam[3] / 2.0; fRadius *= m_dScaleX;
					if (fRadius < 0.0) fRadius = 1.0;
					DrawCircle(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fRadius);
				}
				else if (pNum >= 5)
				{
					MyRectCenter(m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[3], fParam[4], 0);
				}
				//SetStencil(TRUE);
				MyPolygonNSide(nSide, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, fParam[0], fParam[2]);
				//glDisable(GL_STENCIL_TEST);
			}
		}
		else    //    ' Userdefined Apperture
		{
			MyMacro(pAptDef, m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY, gObj.Type.nPolarity);
		}
		break;
	case DRAW_TYPE::POLYGON_SQ:
	case DRAW_TYPE::POLYGON_MQ:
		MyQuadrantPolygonShift(&gObj, &m_pLayerInfo->listObj.at(k + 1), dX, dY);
		break;
	case DRAW_TYPE::ARC_CW: // dType == TYPE_CW
		fParam = &pAptDef->Param.at(0).fParam[0];

		MyArc(m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + dY,
			fParam[0], CW);
		break;
	case DRAW_TYPE::ARC_CCW: // dType == TYPE_CCW
		fParam = &pAptDef->Param.at(0).fParam[0];

		MyArc(m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 1].y + dY,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt].y + dY,
			m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].x + dX, m_pLayerInfo->vecObjCoord[gObj.nStPnt + 2].y + dY,
			fParam[0], CCW);
		break;
	}

	return FALSE;
}

BOOL CSimple274X::MyMacro(const LPAPERTURE_DEF &pAptDef, float x, float y, byte Pol, BOOL bCheck)
{
	vector <FPOINTC> vecVertics;

	BOOL bOnOff;
	int i, j, kk, nNumOfVertex;
	FPOINTC fpt;
	BOOL bClearDataObject = FALSE;
	float cV, sV, fAng, X1, Y1, X2, Y2, fRadius;

	float *fParam;


	APERTURE_PRIMITIVE AptPrim;
	int nParam = pAptDef->Param.size();

	if (bCheck)
	{
		for (j = nParam - 1; j >= 0; j--)  //nParam
		{
			AptPrim = pAptDef->Param.at(j);
			fParam = &AptPrim.fParam[0];

			if (AptPrim.nPriNum != 6 && AptPrim.nPriNum != 7)
			{
				bOnOff = fParam[0];
			}

			switch (AptPrim.nPriNum)
			{
			case 1:
			{
				fRadius = fParam[1] / 2.0; fRadius *= m_dScaleX;
				if (fRadius < 0.0) fRadius = 1.0;
				if (CheckPointInCircle(fParam[2] + x, fParam[3] + y, fRadius, m_fptPickObject.x, m_fptPickObject.y))
					return bOnOff;
			}
			break;
			case 21:
			{
				if (MyRectCenter(fParam[3] + x, fParam[4] + y, fParam[1], fParam[2], fParam[5], TRUE))
					return bOnOff;
			}
			break;
			case 4:
			{
				vecVertics.clear();
				nNumOfVertex = fParam[1] / 2;

				kk = 2;
				for (i = 0; i < nNumOfVertex; i++)
				{
					fpt.x = fParam[kk] + x;
					kk++;
					fpt.y = fParam[kk] + y;
					kk++;

					vecVertics.push_back(fpt);
				}
				if (CheckPointInMyConcavePolygon(vecVertics, m_fptPickObject.x, m_fptPickObject.y))
					return bOnOff;
			}
			break;
			case 5:
			{
				if (MyPolygonNSide(fParam[1], fParam[2] + x, fParam[3] + y, fParam[4], fParam[5], TRUE))
					return bOnOff;
			}
			break;
			case 6:
			{
				if (MyMoire(fParam[0] + x, fParam[1] + y, fParam[2], fParam[3], fParam[4], fParam[5], fParam[6], fParam[7], fParam[8], TRUE))
					return TRUE;
			}
			break;  //need
			case 7:
			{
				if (MyThermal(fParam[0] + x, fParam[1] + y, fParam[2], fParam[3], fParam[5], 4, fParam[4], 0, TRUE))
					return TRUE;
			}
			break;
			case 2:
			case 20:
				fAng = fParam[6];
				X1 = fParam[2];
				Y1 = fParam[3];
				X2 = fParam[4];
				Y2 = fParam[5];
				if (fAng != 0)
				{
					cV = cos(fAng * DEG2RAD);
					sV = sin(fAng * DEG2RAD);

					X1 = fParam[2] * cV - fParam[3] * sV;
					Y1 = fParam[2] * sV + fParam[3] * cV;
					X2 = fParam[4] * cV - fParam[5] * sV;
					Y2 = fParam[4] * sV + fParam[5] * cV;
				}
				//X1 += x; Y1 += y; X2 += x; Y2 += y;
				//AdjustToScreen(X1, Y1, X2, Y2);
				//if (MyLine(X1, Y1, X2, Y2, fParam[1], TRUE))
				//	return bOnOff;
				if (MyLine(X1 + x, Y1 + y, X2 + x, Y2 + y, fParam[1], TRUE))
					return bOnOff;

				break;
			case 22:   //need
			{
				if (MyRectLowerLeft(fParam[3] + x, fParam[4] + y, fParam[1], fParam[2], fParam[5], TRUE))
					return bOnOff;
			}
			break;
			}
		}
	}
	else
	{
		StencilBegin();
		//glClear(GL_STENCIL_BUFFER_BIT);
		//glEnable(GL_STENCIL_TEST);

		for (j = nParam - 1; j >= 0; j--)  //nParam
		{
			AptPrim = pAptDef->Param.at(j);
			fParam = &AptPrim.fParam[0];

			if (AptPrim.nPriNum != 6 && AptPrim.nPriNum != 7)
			{
				bOnOff = fParam[0];
			}

			switch (AptPrim.nPriNum)
			{
			case 1:
				StencilSet(bOnOff);
				fRadius = fParam[1] / 2.0; fRadius *= m_dScaleX;
				if (fRadius < 0.0) fRadius = 1.0;
				DrawCircle(fParam[2] + x, fParam[3] + y, fRadius);	 //onoff 1 =dark 2=clear
				break;
			case 21:
				StencilSet(bOnOff);
				MyRectCenter(fParam[3] + x, fParam[4] + y, fParam[1], fParam[2], fParam[5]); //onoff 1 =dark 2=clear
				break;
			case 4:
				vecVertics.clear();
				nNumOfVertex = fParam[1] / 2;

				kk = 2;
				for (i = 0; i < nNumOfVertex; i++)
				{
					fpt.x = fParam[kk] + x;
					kk++;
					fpt.y = fParam[kk] + y;
					kk++;

					vecVertics.push_back(fpt);
				}
				StencilBitRev(vecVertics, nNumOfVertex);
				//glStencilFunc(GL_NEVER, 0, 1);
				//glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT);
				//glBegin(GL_TRIANGLE_FAN);
				//for (i = 0; i < nNumOfVertex; i++)
				//{
				//	glVertex2f(vecVertics.at(i).x, vecVertics.at(i).y);
				//}
				//glEnd();
				break;
			case 5:
				StencilEnd();//glDisable(GL_STENCIL_TEST);				
				MyPolygonNSide(fParam[1], fParam[2] + x, fParam[3] + y, fParam[4], fParam[5]);
				break;
			case 6:				
				StencilEnd();//glDisable(GL_STENCIL_TEST);
				MyMoire(fParam[0] + x, fParam[1] + y, fParam[2], fParam[3], fParam[4], fParam[5], fParam[6], fParam[7], fParam[8]);
				break;  //need
			case 7:
				StencilEnd();//glDisable(GL_STENCIL_TEST);
				MyThermal(fParam[0] + x, fParam[1] + y, fParam[2], fParam[3], fParam[5], 4, fParam[4], 0);
				break;
			case 2:
			case 20:
				StencilSet(bOnOff);
				fAng = fParam[6];
				X1 = fParam[2];
				Y1 = fParam[3];
				X2 = fParam[4];
				Y2 = fParam[5];
				if (fAng != 0)
				{
					cV = cos(fAng * DEG2RAD);
					sV = sin(fAng * DEG2RAD);

					X1 = fParam[2] * cV - fParam[3] * sV;
					Y1 = fParam[2] * sV + fParam[3] * cV;
					X2 = fParam[4] * cV - fParam[5] * sV;
					Y2 = fParam[4] * sV + fParam[5] * cV;
				}
				//X1 += x; Y1 += y; X2 += x; Y2 += y;
				//AdjustToScreen(X1, Y1, X2, Y2);
				//MyLine(X1, Y1, X2, Y2, fParam[1]);
				MyLine(X1 + x, Y1 + y, X2 + x, Y2 + y, fParam[1]);
				break;
			case 22:   //need
				StencilSet(bOnOff);
				MyRectLowerLeft(fParam[3] + x, fParam[4] + y, fParam[1], fParam[2], fParam[5]);
				break;
			}
		}

		for (j = 0; j < nParam; j++)  //nParam
		{
			AptPrim = pAptDef->Param.at(j);
			fParam = &AptPrim.fParam[0];
			switch (AptPrim.nPriNum)
			{
			case 4:
				vecVertics.clear();
				nNumOfVertex = fParam[1] / 2;

				kk = 2;
				for (i = 0; i < nNumOfVertex; i++)
				{
					fpt.x = fParam[kk] + x;
					kk++;
					fpt.y = fParam[kk] + y;
					kk++;

					vecVertics.push_back(fpt);
				}
				StencilReverse(vecVertics, nNumOfVertex);
				//glStencilFunc(GL_EQUAL, 1, 1);
				//glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO);
				//glBegin(GL_TRIANGLE_FAN);
				//for (i = 0; i < nNumOfVertex; i++)
				//{
				//	glVertex2f(vecVertics.at(i).x, vecVertics.at(i).y);
				//}
				//glEnd();

				break;
			}
		}
		StencilEnd();//glDisable(GL_STENCIL_TEST);
	}

	return FALSE;
}

BOOL CSimple274X::MyRectLowerLeft(float fSx, float fSy, float fLineWidth, float fLineHeight, float fAngle, BOOL bCheck)
{
	FPOINTC cp;
	FPOINTC pp[4];
	float XX, YY, cV, sV;

	if (fAngle)
	{
		cV = cos(fAngle * DEG2RAD);
		sV = sin(fAngle * DEG2RAD);

		cp.x = fSx + fLineWidth / 2;
		cp.y = fSy + fLineHeight / 2;

		XX = -fLineWidth / 2;
		YY = -fLineHeight / 2;
		pp[0].x = (XX * cV) - (YY * sV) + cp.x;
		pp[0].y = (XX * sV) + (YY * cV) + cp.y;
		//        '우하
		XX = fLineWidth / 2;
		YY = -fLineHeight / 2;
		pp[1].x = (XX * cV) - (YY * sV) + cp.x;
		pp[1].y = (XX * sV) + (YY * cV) + cp.y;
		//        '우상
		XX = fLineWidth / 2;
		YY = fLineHeight / 2;
		pp[2].x = (XX * cV) - (YY * sV) + cp.x;
		pp[2].y = (XX * sV) + (YY * cV) + cp.y;
		//        '좌상
		XX = -fLineWidth / 2;
		YY = fLineHeight / 2;
		pp[3].x = (XX * cV) - (YY * sV) + cp.x;
		pp[3].y = (XX * sV) + (YY * cV) + cp.y;

	}
	else
	{
		pp[0].x = fSx;
		pp[0].y = fSy;
		pp[1].x = fSx + fLineWidth;
		pp[1].y = fSy;

		pp[2].x = fSx + fLineWidth;
		pp[2].y = fSy + fLineHeight;
		pp[3].x = fSx;
		pp[3].y = fSy + fLineHeight;
	}
	if (bCheck)
	{
		if (CheckPointInQuad(pp[0].x, pp[0].y, pp[1].x, pp[1].y, pp[2].x, pp[2].y, pp[3].x, pp[3].y, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
	{
		DrawQuad(pp[0].x, pp[0].y, pp[1].x, pp[1].y, pp[2].x, pp[2].y, pp[3].x, pp[3].y, TRUE);
	}

	return FALSE;
}

BOOL CSimple274X::MyLine(float fSx, float fSy, float fEx, float fEy, float fLineWidth, BOOL bCheck)
{
	double fLength, fHeight, fWidth, fTx, fTy;
	FPOINTC fp1, fp2, fp3, fp4;

	fLength = sqrt((fEx - fSx) * (fEx - fSx) + (fEy - fSy) * (fEy - fSy));

	if (fLineWidth * m_dScaleX < 1.0)
		fLineWidth = 1.0 / m_dScaleX;

	if (fLength < 0.000001)
	{
		fp1.x = fSx - fLineWidth / 2.0;
		fp1.y = fSy - fLineWidth / 2.0;
		fp2.x = fSx - fLineWidth / 2.0;
		fp2.y = fSy + fLineWidth / 2.0;
		fp3.x = fSx + fLineWidth / 2.0;
		fp3.y = fSy + fLineWidth / 2.0;
		fp4.x = fSx + fLineWidth / 2.0;
		fp4.y = fSy - fLineWidth / 2.0;
	}
	else
	{
		fHeight = fEy - fSy;
		fWidth = fEx - fSx;

		fTy = fLineWidth / 2.0 * fWidth / fLength;
		fTx = fLineWidth / 2.0 * fHeight / fLength;

		//fp1.x = fSx - fTx;
		//fp1.y = fSy - fTy;
		//fp2.x = fSx - fTx;
		//fp2.y = fSy + fTy;
		//fp3.x = fEx + fTx;
		//fp3.y = fEy + fTy;
		//fp4.x = fEx + fTx;
		//fp4.y = fEy - fTy;

		fp1.x = fSx + fTx;
		fp1.y = fSy - fTy;
		fp2.x = fEx + fTx;
		fp2.y = fEy - fTy;
		fp3.x = fEx - fTx;
		fp3.y = fEy + fTy;
		fp4.x = fSx - fTx;
		fp4.y = fSy + fTy;
	}
	if (bCheck)
	{
		if (CheckPointInQuad(fp1.x, fp1.y, fp2.x, fp2.y, fp3.x, fp3.y, fp4.x, fp4.y, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
		DrawQuad(fp1.x, fp1.y, fp2.x, fp2.y, fp3.x, fp3.y, fp4.x, fp4.y, TRUE);
	return FALSE;
}

BOOL CSimple274X::MyThermal(float x, float y, float Dmo, float Dmi, float Ang, int num, float gap, float angle, BOOL bCheck)
{
	float   Ro, Ri, Theta1, Theta2, t, cV1, cV2, sV1, sV2;
	FPOINTC pp[9];
	int i;
	FPOINTC fpt = FPOINTC(x, y);

	if (bCheck)
	{

		Ro = Dmo / 2;
		Ri = Dmi / 2;
		t = gap / 2;
		Ang = Ang * DEG2RAD;

		Theta1 = atan(t / sqrt(Ri * Ri - t * t));
		cV1 = cos(Ang + Theta1);
		sV1 = sin(Ang + Theta1);

		Theta2 = atan(t / sqrt(Ro * Ro - t * t));
		cV2 = cos(Ang + Theta2);
		sV2 = sin(Ang + Theta2);

		pp[0].x = x + Ri * cV1;
		pp[0].y = y + Ri * sV1;
		pp[1].x = x + Ro * cV2;
		pp[1].y = y + Ro * sV2;

		pp[2].x = -DetGcode;  //'CCW
		pp[2].y = -DetGcode;

		cV1 = cos(Ang + PI / 2 - Theta1);
		sV1 = sin(Ang + PI / 2 - Theta1);
		cV2 = cos(Ang + PI / 2 - Theta2);
		sV2 = sin(Ang + PI / 2 - Theta2);

		pp[3].x = x + Ro * cV2;
		pp[3].y = y + Ro * sV2;
		pp[4].x = x; //     'Center X
		pp[4].y = y; //     'Center Y

		pp[5].x = x + Ri * cV1;
		pp[5].y = y + Ri * sV1;

		pp[6].x = DetGcode;
		pp[6].y = DetGcode;
		pp[7] = pp[0];

		pp[8] = pp[4];


		if (MyPolygon(pp, 9, TRUE))
			return TRUE;

		for (i = 1; i < num; i++)
		{
			RotatePoint90(pp[0], fpt);
			RotatePoint90(pp[1], fpt);
			RotatePoint90(pp[3], fpt);
			RotatePoint90(pp[5], fpt);

 			//m_pCamData->RotateTranslatePoint(pp[0], 0.0, 1.0, x, y);
 			//m_pCamData->RotateTranslatePoint(pp[1], 0.0, 1.0, x, y);
 			//m_pCamData->RotateTranslatePoint(pp[3], 0.0, 1.0, x, y);
 			//m_pCamData->RotateTranslatePoint(pp[5], 0.0, 1.0, x, y);
			pp[7] = pp[0];

			if (MyPolygon(pp, 9, TRUE))
				return TRUE;
		}

	}
	else
	{
		if (m_nApertureListIndex == -1)
		{
			Ro = Dmo / 2;
			Ri = Dmi / 2;
			t = gap / 2;
			Ang = Ang * DEG2RAD;

			Theta1 = atan(t / sqrt(Ri * Ri - t * t));
			cV1 = cos(Ang + Theta1);
			sV1 = sin(Ang + Theta1);

			Theta2 = atan(t / sqrt(Ro * Ro - t * t));
			cV2 = cos(Ang + Theta2);
			sV2 = sin(Ang + Theta2);

			pp[0].x = x + Ri * cV1;
			pp[0].y = y + Ri * sV1;
			pp[1].x = x + Ro * cV2;
			pp[1].y = y + Ro * sV2;

			pp[2].x = -DetGcode;  //'CCW
			pp[2].y = -DetGcode;

			cV1 = cos(Ang + PI / 2 - Theta1);
			sV1 = sin(Ang + PI / 2 - Theta1);
			cV2 = cos(Ang + PI / 2 - Theta2);
			sV2 = sin(Ang + PI / 2 - Theta2);

			pp[3].x = x + Ro * cV2;
			pp[3].y = y + Ro * sV2;
			pp[4].x = x; //     'Center X
			pp[4].y = y; //     'Center Y

			pp[5].x = x + Ri * cV1;
			pp[5].y = y + Ri * sV1;

			pp[6].x = DetGcode;
			pp[6].y = DetGcode;
			pp[7] = pp[0];

			pp[8] = pp[4];

			MyPolygon(pp, 9);

			for (i = 1; i < num; i++)
			{
				RotatePoint90(pp[0], fpt);
				RotatePoint90(pp[1], fpt);
				RotatePoint90(pp[3], fpt);
				RotatePoint90(pp[5], fpt);

 				//m_pCamData->RotateTranslatePoint(pp[0], 0.0, 1.0, x, y);
 				//m_pCamData->RotateTranslatePoint(pp[1], 0.0, 1.0, x, y);
 				//m_pCamData->RotateTranslatePoint(pp[3], 0.0, 1.0, x, y);
 				//m_pCamData->RotateTranslatePoint(pp[5], 0.0, 1.0, x, y);
				pp[7] = pp[0];

				MyPolygon(pp, 9);
			}
		}
		else
		{
			glPushMatrix();
			glTranslatef(x, y, 0.0);
			glCallList(m_nApertureListIndex);
			glPopMatrix();
		}
	}
	return FALSE;
}

BOOL CSimple274X::MyPolygon(const FPOINTC *fCoord, int nVertex, BOOL bCheck)
{
	vector <FPOINTC> vecVertics;
	int i, npp, nDir;
	double	fRadius, fStartAngle, fEndAngle, fArcAngle;
	FPOINTC pPre, pPos, pIJ, fPt;

	vecVertics.clear();

	npp = nVertex - 1;

	pPre = fCoord[0];
	vecVertics.push_back(pPre);

	for (i = 1; i <= npp; i++)
	{
		fPt = fCoord[i];
		if (fabs(fPt.x) == DetGcode && fabs(fPt.y) == DetGcode)
		{
			if (fPt.x > 0)	//+DetGCode
				nDir = 1;
			else
				nDir = -1;

			i++;
			pPos = fCoord[i];
			i++;
			pIJ = fCoord[i];

			fRadius = sqrt((pPos.x - pIJ.x) * (pPos.x - pIJ.x) + (pPos.y - pIJ.y) * (pPos.y - pIJ.y));

			fStartAngle = atan2(pPre.y - pIJ.y, pPre.x - pIJ.x);
			fEndAngle = atan2(pPos.y - pIJ.y, pPos.x - pIJ.x);

			if (nDir == -1)
			{
				if (fEndAngle > fStartAngle)
					fArcAngle = fEndAngle - fStartAngle;
				else
					fArcAngle = 2 * PI - fStartAngle + fEndAngle;
			}
			else
			{
				if (fEndAngle > fStartAngle)
					fArcAngle = 2 * PI - fEndAngle + fStartAngle;
				else
					fArcAngle = fStartAngle - fEndAngle;
			}

			if (fArcAngle == 0)
				fArcAngle = 2 * PI;

			GetArcVertices(vecVertics, pIJ, fRadius, fStartAngle, fArcAngle, nDir);

			fPt = vecVertics.at(vecVertics.size() - 1);

			if (fPt.x != pPos.x || fPt.y != pPos.y)
				vecVertics.push_back(pPos);

		}
		else
		{
			pPos = fCoord[i];

			vecVertics.push_back(pPos);
		}
		pPre = pPos;
	}
	if (bCheck)
	{
		if (CheckPointInMyConcavePolygon(vecVertics, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
	{
		DrawConcavePolygon(vecVertics);
	}

	return FALSE;
}

BOOL CSimple274X::MyMoire(float x, float y, float fOutDiameter, float fRingWidth, float fGap, int nCircle, float fLineWidth, float fLineLegth, float Ang, BOOL bCheck)
{
	float X1, X2, Y1, Y2, cV, sV, XX;
	float fInDia;

	for (int i = 0; i < nCircle; i++)
	{
		fInDia = (fOutDiameter - 2.0 * fRingWidth);
		if (bCheck)
		{
			if (CheckPointInMyDonut(x, y, fOutDiameter, fInDia, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
		{
			DrawDonut(x, y, fOutDiameter, fInDia);
		}


		fOutDiameter = fOutDiameter - (fRingWidth + fGap) * 2;
	}

	X1 = 0;
	Y1 = -0.5 * fLineLegth;
	X2 = 0;
	Y2 = 0.5 * fLineLegth;
	if (Ang != 0)
	{
		cV = cos(Ang * DEG2RAD);
		sV = sin(Ang * DEG2RAD);
		XX = X1 * cV - Y1 * sV;
		Y1 = X1 * sV + Y1 * cV;
		X1 = XX;
		XX = X2 * cV - Y2 * sV;
		Y2 = X2 * sV + Y2 * cV;
		X2 = XX;
	}
	if (bCheck)
	{
		if (CheckPointInMyLineRound(X1 + x, Y1 + y, X2 + x, Y2 + y, fLineWidth, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
	{
		DrawLineRound(X1 + x, Y1 + y, X2 + x, Y2 + y, fLineWidth);
	}


	X1 = -0.5 * fLineLegth;
	Y1 = 0;
	X2 = 0.5 * fLineLegth;
	Y2 = 0;
	if (Ang != 0)
	{
		cV = cos(Ang * DEG2RAD);
		sV = sin(Ang * DEG2RAD);
		XX = X1 * cV - Y1 * sV;
		Y1 = X1 * sV + Y1 * cV;
		X1 = XX;
		XX = X2 * cV - Y2 * sV;
		Y2 = X2 * sV + Y2 * cV;
		X2 = XX;
	}
	if (bCheck)
	{
		if (CheckPointInMyLineRound(X1 + x, Y1 + y, X2 + x, Y2 + y, fLineWidth, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
		DrawLineRound(X1 + x, Y1 + y, X2 + x, Y2 + y, fLineWidth);
	return FALSE;
}

BOOL CSimple274X::CheckDrawAllow(const FRECTC &fObjExtent)
{
	const double fMargin = 0.5;
	BOOL nDrawShow = 1;


	if (m_fExtentStartPos.x - fMargin > fObjExtent.X2 || m_fExtentEndPos.x + fMargin<fObjExtent.X1 ||
		m_fExtentStartPos.y - fMargin>fObjExtent.Y2 || m_fExtentEndPos.y + fMargin < fObjExtent.Y1)
	{
		nDrawShow = 0;
	}

	return  nDrawShow;
}

BOOL CSimple274X::CheckPointInMyDonut(float fCx, float fCy, float fDmo, float fDmi, double x, double y)
{
	double distance = GetDistance(CfPoint(fCx, fCy), CfPoint(x, y));
	if (distance <= fDmo / 2.0 && distance >= fDmi / 2)
		return TRUE;
	else
		return FALSE;
}

BOOL CSimple274X::CheckArcRound(GLfloat cx, GLfloat cy, GLfloat r, GLfloat start_angle, GLfloat arc_angle, GLfloat width, int dir, float x, float y)
{
	GLfloat halfWidth = width / 2.0;
	FPOINTC bufPt;
	if (dir == CW)
	{
		if (CheckPointInArc(cx, cy, r - halfWidth, start_angle - arc_angle, start_angle, x, y))
			return FALSE;
		bufPt.x = cx + r*cos(start_angle - arc_angle);
		bufPt.y = cy + r*sin(start_angle - arc_angle);
		if (CheckPointInArc(bufPt.x, bufPt.y, halfWidth, start_angle - arc_angle + PI, start_angle - arc_angle + 2 * PI, x, y))
			return TRUE;
		if (CheckPointInArc(cx, cy, r + halfWidth, start_angle - arc_angle, start_angle, x, y))
			return TRUE;
		bufPt.x = cx + r*cos(start_angle);
		bufPt.y = cy + r*sin(start_angle);
		if (CheckPointInArc(bufPt.x, bufPt.y, halfWidth, start_angle, start_angle + PI, x, y))
			return TRUE;
	}
	else if (dir == CCW)
	{
		if (CheckPointInArc(cx, cy, r - halfWidth, start_angle, start_angle + PI, x, y))
			return FALSE;
		bufPt.x = cx + r*cos(start_angle + arc_angle);
		bufPt.y = cy + r*sin(start_angle + arc_angle);
		if (CheckPointInArc(bufPt.x, bufPt.y, halfWidth, start_angle + arc_angle, start_angle + arc_angle + PI, x, y))
			return TRUE;
		if (CheckPointInArc(cx, cy, r + halfWidth, start_angle, start_angle + arc_angle, x, y))
			return TRUE;
		bufPt.x = cx + r*cos(start_angle);
		bufPt.y = cy + r*sin(start_angle);
		if (CheckPointInArc(bufPt.x, bufPt.y, halfWidth, start_angle - PI, start_angle, x, y))
			return TRUE;
	}
	return FALSE;
}

BOOL CSimple274X::CheckPointInMyLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight, double x, double y)
{
	float ww, hh, a, b, a1, b1, a2, b2;
	vector<FPOINTC> vecpt;
	FPOINTC pp;
	vecpt.clear();
	ww = fLineWidth / 2;
	hh = fLineHeight / 2;

	if (fSx != fEx && fSy != fEy)
	{

		if (fEx > fSx)
		{
			if (fEy > fSy)
			{
				pp.x = (fSx - ww);
				pp.y = (fSy - hh);
				vecpt.push_back(pp);
				pp.x = (fSx - ww);
				pp.y = (fSy + hh);
				vecpt.push_back(pp);
				pp.x = (fEx - ww);
				pp.y = (fEy + hh);
				vecpt.push_back(pp);
				pp.x = (fEx + ww);
				pp.y = (fEy + hh);
				vecpt.push_back(pp);
				pp.x = (fEx + ww);
				pp.y = (fEy - hh);
				vecpt.push_back(pp);
				pp.x = (fSx + ww);
				pp.y = (fSy - hh);
				vecpt.push_back(pp);
			}
			else
			{
				pp.x = (fSx - ww);
				pp.y = (fSy - hh);
				vecpt.push_back(pp);
				pp.x = (fSx - ww);
				pp.y = (fSy + hh);
				vecpt.push_back(pp);
				pp.x = (fSx + ww);
				pp.y = (fSy + hh);
				vecpt.push_back(pp);
				pp.x = (fEx + ww);
				pp.y = (fEy + hh);
				vecpt.push_back(pp);
				pp.x = (fEx + ww);
				pp.y = (fEy - hh);
				vecpt.push_back(pp);
				pp.x = (fEx - ww);
				pp.y = (fEy - hh);
				vecpt.push_back(pp);
			}
		}
		else
		{
			a1 = fEx;
			a2 = fSx;
			b1 = fEy;
			b2 = fSy;
			if (b2 > b1)
			{
				pp.x = (a1 - ww);
				pp.y = (b1 - hh);
				vecpt.push_back(pp);
				pp.x = (a1 - ww);
				pp.y = (b1 + hh);
				vecpt.push_back(pp);
				pp.x = (a2 - ww);
				pp.y = (b2 + hh);
				vecpt.push_back(pp);
				pp.x = (a2 + ww);
				pp.y = (b2 + hh);
				vecpt.push_back(pp);
				pp.x = (a2 + ww);
				pp.y = (b2 - hh);
				vecpt.push_back(pp);
				pp.x = (a1 + ww);
				pp.y = (b1 - hh);
				vecpt.push_back(pp);
			}
			else
			{
				pp.x = (a1 - ww);
				pp.y = (b1 - hh);
				vecpt.push_back(pp);
				pp.x = (a1 - ww);
				pp.y = (b1 + hh);
				vecpt.push_back(pp);
				pp.x = (a1 + ww);
				pp.y = (b1 + hh);
				vecpt.push_back(pp);
				pp.x = (a2 + ww);
				pp.y = (b2 + hh);
				vecpt.push_back(pp);
				pp.x = (a2 + ww);
				pp.y = (b2 - hh);
				vecpt.push_back(pp);
				pp.x = (a2 - ww);
				pp.y = (b2 - hh);
				vecpt.push_back(pp);
			}
		}

		return CheckPointInPolygonEx(vecpt, x, y);
	}

	if (fSx == fEx && fSy == fEy)
	{
		pp.x = (fSx - ww);     //  '좌하
		pp.y = (fSy - hh);     //
		vecpt.push_back(pp);
		pp.x = (fSx + ww);     //  '우하
		pp.y = (fSy - hh);
		vecpt.push_back(pp);

		pp.x = (fEx + ww);     //  '우상
		pp.y = (fEy + hh);     //
		vecpt.push_back(pp);
		pp.x = (fEx - ww);     //  '좌상
		pp.y = (fEy + hh);     //
		vecpt.push_back(pp);
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
		pp.x = (fSx - ww);     //  '좌하
		pp.y = (a - hh);      //
		vecpt.push_back(pp);
		pp.x = (fSx + ww);     //  '우하
		pp.y = (a - hh);      //
		vecpt.push_back(pp);
		pp.x = (fEx + ww);     //  '우상
		pp.y = (b + hh);      //
		vecpt.push_back(pp);
		pp.x = (fEx - ww);    //   '좌상
		pp.y = (b + hh);     // 
		vecpt.push_back(pp);
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
		pp.x = (a - ww);      //  '좌하
		pp.y = (fSy - hh);     //
		vecpt.push_back(pp);
		pp.x = (b + ww);      //  '우하
		pp.y = (fSy - hh);    // 
		vecpt.push_back(pp);

		pp.x = (b + ww);      //  '우상
		pp.y = (fEy + hh);     //
		vecpt.push_back(pp);
		pp.x = (a - ww);     //   '좌상
		pp.y = (fEy + hh);    // 
		vecpt.push_back(pp);
	}
	return CheckPointInQuad(vecpt[0].x, vecpt[0].y, vecpt[1].x, vecpt[1].y, vecpt[2].x, vecpt[2].y, vecpt[3].x, vecpt[3].y, x, y);
}

BOOL CSimple274X::CheckPointInCircle(double cx, double cy, double radius, double x, double y)
{
	if (radius >= GetDistance(CfPoint(cx, cy), CfPoint(x, y)))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

double CSimple274X::GetDistance(CfPoint FirstPoint, CfPoint SecondPoint)
{
	return sqrt(pow(SecondPoint.x - FirstPoint.x, 2) + pow(SecondPoint.y - FirstPoint.y, 2));
}

BOOL CSimple274X::MyRectCenter(float fSx, float fSy, float fLineWidth, float fLineHeight, float fAngle, BOOL bCheck)
{
	FPOINTC pp[4];
	float cV, sV, X1, Y1, X2, Y2;

	GLfloat LineWidth;

	LineWidth = fLineWidth;

	fLineWidth = fLineWidth / 2;
	fLineHeight = fLineHeight / 2;

	if (fAngle != 0)
	{
		cV = cos(fAngle * DEG2RAD);
		sV = sin(fAngle * DEG2RAD);
		X1 = (fSx - fLineWidth * cV);
		Y1 = (fSy - fLineWidth * sV);
		X2 = (fSx + fLineWidth * cV);
		Y2 = (fSy + fLineWidth * sV);
		cV = fLineHeight * cV;
		sV = fLineHeight * sV;
	}

	if (fAngle != 0)
	{
		if (bCheck)
		{
			if (CheckPointInQuad((X1 - sV), (Y1 + cV), (X1 + sV), (Y1 - cV), (X2 + sV), (Y2 - cV), (X2 - sV), (Y2 + cV), m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
			DrawQuad((X1 - sV), (Y1 + cV), (X1 + sV), (Y1 - cV), (X2 + sV), (Y2 - cV), (X2 - sV), (Y2 + cV), TRUE);
	}
	else
	{
		if (bCheck)
		{
			if (CheckPointInMyRect(fSx - fLineWidth, fSy - fLineHeight, fSx + fLineWidth, fSy + fLineHeight, m_fptPickObject.x, m_fptPickObject.y))
				return TRUE;
		}
		else
			DrawRect(CfPoint3D((fSx - fLineWidth), (fSy - fLineHeight), 0.0), CfPoint3D((fSx + fLineWidth), (fSy + fLineHeight), 0.0));
	}
	return FALSE;

}

BOOL CSimple274X::CheckPointInMyRect(float fSx, float fSy, float fEx, float fEy, double x, double y)
{
	return CheckPointInQuad(fSx, fSy, fSx, fEy, fEx, fEy, fEx, fSy, x, y);
}

BOOL CSimple274X::CheckPointInQuad(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x, double y)
{
	double angle_123;
	double angle_12x;
	double angle_234;
	double angle_23x;
	double angle_341;
	double angle_34x;
	double angle_412;
	double angle_41x;
	BOOL inside;

	// This will only handle convex quadrilaterals.
	inside = FALSE;

	angle_12x = GetInteriorAngle(x1, y1, x2, y2, x, y);
	angle_123 = GetInteriorAngle(x1, y1, x2, y2, x3, y3);

	if (angle_12x > angle_123)
		return FALSE;

	angle_23x = GetInteriorAngle(x2, y2, x3, y3, x, y);
	angle_234 = GetInteriorAngle(x2, y2, x3, y3, x4, y4);

	if (angle_23x > angle_234)
		return FALSE;

	angle_34x = GetInteriorAngle(x3, y3, x4, y4, x, y);
	angle_341 = GetInteriorAngle(x3, y3, x4, y4, x1, y1);

	if (angle_34x > angle_341)
		return FALSE;

	angle_41x = GetInteriorAngle(x4, y4, x1, y1, x, y);
	angle_412 = GetInteriorAngle(x4, y4, x1, y1, x2, y2);

	if (angle_41x > angle_412)
		return FALSE;

	return TRUE;
}

/////////////////////////////////////
// GetInteriorAngle returns the interior angle in radians between two rays in 2D.
// Modified:
// 19 April 1999
// Author:
// John Burkardt
// Parameters:
// Input, double X1, Y1, X2, Y2, X3, Y3, define the rays
// (X1-X2,Y1-Y2) and (X3-X2,Y3-Y2) which in turn define the angle.
// Output, the angle swept out by the rays, measured in radians.
// This value satisfies 0 <= ANGLEI_RAD_2D 
// ray is of zero length, then ANGLEI_RAD_2D is returned as 0.
double CSimple274X::GetInteriorAngle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double fAngleRad;
	double x;
	double y;

	x = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2);
	y = (x1 - x2) * (y3 - y2) - (y1 - y2) * (x3 - x2);

	if (x == 0.0 && y == 0.0)
		fAngleRad = 0.0;
	else
	{
		fAngleRad = atan2(y, x);
		if (fAngleRad < 0.0)
			fAngleRad = fAngleRad + 2.0 * PI;
	}

	if (GetVectorDir(x1, y1, x2, y2, x3, y3) == 1)
		fAngleRad = 2.0 * PI - fAngleRad;

	return fAngleRad / PI*180.; //  Degree단위로 
}

// 두선분의 벡터 방향을 나타낸다.
// 시계방향일 경우 (1)을 반시계 방향일경우 (-1)을  리턴한다.
// 두선분이 동일한 방향이라면 0를 리턴한다.
int CSimple274X::GetVectorDir(double ax, double ay, double bx, double by, double cx, double cy)
{
	double temp;
	temp = bx*cy - ay*bx - ax*cy - by*cx + ax*by + ay*cx;
	if (temp > 0.0)
		return CW;
	else if (temp < 0.0)
		return CCW;
	else
		return PARALLEL;
}

void CSimple274X::GetDrillIndex(FPOINTC fptStart, int* arIndex, int nCount, vector<FPOINTC> &vecPt, float fDistance)
{
	FPOINTC fptBuf;
	int nIndex;
	int i, nCol, nRow;
	for (i = 0; i < nCount; i++)
	{
		nIndex = arIndex[i];
		nCol = nIndex % 7;
		nRow = nIndex / 7;
		fptBuf.x = fptStart.x + nCol*fDistance*0.5;
		fptBuf.y = fptStart.y + (6 - nRow)*fDistance;
		vecPt.push_back(fptBuf);
	}
	return;
}

BOOL CSimple274X::GetDrillPoints(char ch, FPOINTC fptStart, vector<FPOINTC> &vecPt, float fDistance)
{
	/////////////////////////
	////Drill Point Index
	////0  1  2  3  4  5  6
	////7  8  9  10 11 12 13
	////14 15 16 17 18 19 20
	////21 22 23 24 25 26 27
	////28 29 30 31 32 33 34
	////35 36 37 38 39 40 41
	////42 43 44 45 46 47 48
	/////////////////////////
	BOOL bState = FALSE;
	int *pIndex = NULL;
	int nCount;
	vecPt.clear();
	switch (ch)
	{
	case ',':
		bState = TRUE;
		break;
	case 'A':
		nCount = 16;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 23;
		pIndex[8] = 25;
		pIndex[9] = 27;
		pIndex[10] = 28;
		pIndex[11] = 34;
		pIndex[12] = 35;
		pIndex[13] = 41;
		pIndex[14] = 42;
		pIndex[15] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'B':
		nCount = 17;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 7;
		pIndex[4] = 13;
		pIndex[5] = 14;
		pIndex[6] = 20;
		pIndex[7] = 21;
		pIndex[8] = 23;
		pIndex[9] = 25;
		pIndex[10] = 28;
		pIndex[11] = 34;
		pIndex[12] = 35;
		pIndex[13] = 41;
		pIndex[14] = 42;
		pIndex[15] = 44;
		pIndex[16] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'C':
		nCount = 11;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 21;
		pIndex[6] = 28;
		pIndex[7] = 35;
		pIndex[8] = 41;
		pIndex[9] = 44;
		pIndex[10] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'D':
		nCount = 16;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 7;
		pIndex[4] = 13;
		pIndex[5] = 14;
		pIndex[6] = 20;
		pIndex[7] = 21;
		pIndex[8] = 27;
		pIndex[9] = 28;
		pIndex[10] = 34;
		pIndex[11] = 35;
		pIndex[12] = 41;
		pIndex[13] = 42;
		pIndex[14] = 44;
		pIndex[15] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'E':
		nCount = 15;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 6;
		pIndex[4] = 7;
		pIndex[5] = 14;
		pIndex[6] = 21;
		pIndex[7] = 23;
		pIndex[8] = 25;
		pIndex[9] = 28;
		pIndex[10] = 35;
		pIndex[11] = 42;
		pIndex[12] = 44;
		pIndex[13] = 46;
		pIndex[14] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'F':
		nCount = 12;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 6;
		pIndex[4] = 7;
		pIndex[5] = 14;
		pIndex[6] = 21;
		pIndex[7] = 23;
		pIndex[8] = 25;
		pIndex[9] = 28;
		pIndex[10] = 35;
		pIndex[11] = 42;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'G':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 21;
		pIndex[6] = 28;
		pIndex[7] = 32;
		pIndex[8] = 34;
		pIndex[9] = 35;
		pIndex[10] = 41;
		pIndex[11] = 44;
		pIndex[12] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'H':
		nCount = 16;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 23;
		pIndex[8] = 25;
		pIndex[9] = 27;
		pIndex[10] = 28;
		pIndex[11] = 34;
		pIndex[12] = 35;
		pIndex[13] = 41;
		pIndex[14] = 42;
		pIndex[15] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'I':
		nCount = 11;
		pIndex = new int[nCount];
		pIndex[0] = 1;
		pIndex[1] = 3;
		pIndex[2] = 5;
		pIndex[3] = 10;
		pIndex[4] = 17;
		pIndex[5] = 24;
		pIndex[6] = 31;
		pIndex[7] = 38;
		pIndex[8] = 43;
		pIndex[9] = 45;
		pIndex[10] = 47;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'J':
		nCount = 9;
		pIndex = new int[nCount];
		pIndex[0] = 6;
		pIndex[1] = 13;
		pIndex[2] = 20;
		pIndex[3] = 27;
		pIndex[4] = 34;
		pIndex[5] = 35;
		pIndex[6] = 41;
		pIndex[7] = 44;
		pIndex[8] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'K':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 7;
		pIndex[3] = 11;
		pIndex[4] = 14;
		pIndex[5] = 16;
		pIndex[6] = 21;
		pIndex[7] = 28;
		pIndex[8] = 30;
		pIndex[9] = 35;
		pIndex[10] = 39;
		pIndex[11] = 42;
		pIndex[12] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'L':
		nCount = 10;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 7;
		pIndex[2] = 14;
		pIndex[3] = 21;
		pIndex[4] = 28;
		pIndex[5] = 35;
		pIndex[6] = 42;
		pIndex[7] = 44;
		pIndex[8] = 46;
		pIndex[9] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'M':
		nCount = 17;
		pIndex = new int[nCount];
		pIndex[0] = 1;
		pIndex[1] = 5;
		pIndex[2] = 7;
		pIndex[3] = 9;
		pIndex[4] = 11;
		pIndex[5] = 13;
		pIndex[6] = 14;
		pIndex[7] = 17;
		pIndex[8] = 20;
		pIndex[9] = 21;
		pIndex[10] = 27;
		pIndex[11] = 28;
		pIndex[12] = 34;
		pIndex[13] = 35;
		pIndex[14] = 41;
		pIndex[15] = 42;
		pIndex[16] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'N':
		nCount = 17;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 16;
		pIndex[6] = 20;
		pIndex[7] = 21;
		pIndex[8] = 24;
		pIndex[9] = 27;
		pIndex[10] = 28;
		pIndex[11] = 32;
		pIndex[12] = 34;
		pIndex[13] = 35;
		pIndex[14] = 41;
		pIndex[15] = 42;
		pIndex[16] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'O':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 27;
		pIndex[8] = 28;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 41;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'P':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 7;
		pIndex[4] = 13;
		pIndex[5] = 14;
		pIndex[6] = 20;
		pIndex[7] = 21;
		pIndex[8] = 23;
		pIndex[9] = 25;
		pIndex[10] = 28;
		pIndex[11] = 35;
		pIndex[12] = 42;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'Q':
		nCount = 16;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 27;
		pIndex[8] = 28;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 39;
		pIndex[12] = 41;
		pIndex[13] = 44;
		pIndex[14] = 46;
		pIndex[15] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'R':
		nCount = 16;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 7;
		pIndex[4] = 13;
		pIndex[5] = 14;
		pIndex[6] = 20;
		pIndex[7] = 21;
		pIndex[8] = 23;
		pIndex[9] = 25;
		pIndex[10] = 28;
		pIndex[11] = 32;
		pIndex[12] = 35;
		pIndex[13] = 40;
		pIndex[14] = 42;
		pIndex[15] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'S':
		nCount = 12;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 23;
		pIndex[6] = 25;
		pIndex[7] = 34;
		pIndex[8] = 35;
		pIndex[9] = 41;
		pIndex[10] = 44;
		pIndex[11] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'T':
		nCount = 10;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 6;
		pIndex[4] = 10;
		pIndex[5] = 17;
		pIndex[6] = 24;
		pIndex[7] = 31;
		pIndex[8] = 38;
		pIndex[9] = 45;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'U':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 27;
		pIndex[8] = 28;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 41;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'V':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 27;
		pIndex[8] = 29;
		pIndex[9] = 33;
		pIndex[10] = 37;
		pIndex[11] = 39;
		pIndex[12] = 45;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'W':
		nCount = 17;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 27;
		pIndex[8] = 28;
		pIndex[9] = 31;
		pIndex[10] = 34;
		pIndex[11] = 35;
		pIndex[12] = 37;
		pIndex[13] = 39;
		pIndex[14] = 41;
		pIndex[15] = 43;
		pIndex[16] = 47;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'X':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 8;
		pIndex[3] = 12;
		pIndex[4] = 16;
		pIndex[5] = 18;
		pIndex[6] = 24;
		pIndex[7] = 30;
		pIndex[8] = 32;
		pIndex[9] = 36;
		pIndex[10] = 40;
		pIndex[11] = 42;
		pIndex[12] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'Y':
		nCount = 10;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 6;
		pIndex[2] = 8;
		pIndex[3] = 12;
		pIndex[4] = 16;
		pIndex[5] = 18;
		pIndex[6] = 24;
		pIndex[7] = 31;
		pIndex[8] = 38;
		pIndex[9] = 45;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case 'Z':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 6;
		pIndex[4] = 12;
		pIndex[5] = 18;
		pIndex[6] = 24;
		pIndex[7] = 30;
		pIndex[8] = 36;
		pIndex[9] = 42;
		pIndex[10] = 44;
		pIndex[11] = 46;
		pIndex[12] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '0':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 8;
		pIndex[3] = 12;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 21;
		pIndex[7] = 27;
		pIndex[8] = 28;
		pIndex[9] = 34;
		pIndex[10] = 36;
		pIndex[11] = 40;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '1':
		nCount = 10;
		pIndex = new int[nCount];
		pIndex[0] = 3;
		pIndex[1] = 8;
		pIndex[2] = 10;
		pIndex[3] = 17;
		pIndex[4] = 24;
		pIndex[5] = 31;
		pIndex[6] = 38;
		pIndex[7] = 43;
		pIndex[8] = 45;
		pIndex[9] = 47;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '2':
		nCount = 12;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 20;
		pIndex[5] = 25;
		pIndex[6] = 30;
		pIndex[7] = 35;
		pIndex[8] = 42;
		pIndex[9] = 44;
		pIndex[10] = 46;
		pIndex[11] = 48;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '3':
		nCount = 12;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 20;
		pIndex[5] = 23;
		pIndex[6] = 25;
		pIndex[7] = 34;
		pIndex[8] = 35;
		pIndex[9] = 41;
		pIndex[10] = 44;
		pIndex[11] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '4':
		nCount = 13;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 11;
		pIndex[4] = 14;
		pIndex[5] = 18;
		pIndex[6] = 21;
		pIndex[7] = 23;
		pIndex[8] = 25;
		pIndex[9] = 27;
		pIndex[10] = 32;
		pIndex[11] = 39;
		pIndex[12] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '5':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 6;
		pIndex[4] = 7;
		pIndex[5] = 14;
		pIndex[6] = 16;
		pIndex[7] = 18;
		pIndex[8] = 27;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 41;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '6':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 21;
		pIndex[6] = 23;
		pIndex[7] = 25;
		pIndex[8] = 28;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 41;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '7':
		nCount = 11;
		pIndex = new int[nCount];
		pIndex[0] = 0;
		pIndex[1] = 2;
		pIndex[2] = 4;
		pIndex[3] = 6;
		pIndex[4] = 7;
		pIndex[5] = 12;
		pIndex[6] = 18;
		pIndex[7] = 24;
		pIndex[8] = 30;
		pIndex[9] = 36;
		pIndex[10] = 42;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '8':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 23;
		pIndex[7] = 25;
		pIndex[8] = 28;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 41;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '9':
		nCount = 14;
		pIndex = new int[nCount];
		pIndex[0] = 2;
		pIndex[1] = 4;
		pIndex[2] = 7;
		pIndex[3] = 13;
		pIndex[4] = 14;
		pIndex[5] = 20;
		pIndex[6] = 23;
		pIndex[7] = 25;
		pIndex[8] = 27;
		pIndex[9] = 34;
		pIndex[10] = 35;
		pIndex[11] = 41;
		pIndex[12] = 44;
		pIndex[13] = 46;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '+':
		nCount = 5;
		pIndex = new int[nCount];
		pIndex[0] = 17;
		pIndex[1] = 22;
		pIndex[2] = 24;
		pIndex[3] = 26;
		pIndex[4] = 31;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '-':
		nCount = 3;
		pIndex = new int[nCount];
		pIndex[0] = 22;
		pIndex[1] = 24;
		pIndex[2] = 26;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '/':
		nCount = 7;
		pIndex = new int[nCount];
		pIndex[0] = 6;
		pIndex[1] = 12;
		pIndex[2] = 18;
		pIndex[3] = 24;
		pIndex[4] = 30;
		pIndex[5] = 36;
		pIndex[6] = 42;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	case '*':
		nCount = 12;
		pIndex = new int[nCount];
		pIndex[0] = 7;
		pIndex[1] = 13;
		pIndex[2] = 16;
		pIndex[3] = 18;
		pIndex[4] = 21;
		pIndex[5] = 23;
		pIndex[6] = 25;
		pIndex[7] = 27;
		pIndex[8] = 30;
		pIndex[9] = 32;
		pIndex[10] = 35;
		pIndex[11] = 41;
		GetDrillIndex(fptStart, pIndex, nCount, vecPt, fDistance);
		bState = TRUE;
		break;
	default:
		break;
	}
	if (pIndex)
	{
		delete pIndex;
		pIndex = NULL;
	}
	return bState;
}

void CSimple274X::GetCannedText(CString strCannedText, FPOINTC fptStart, float fDistance, vector <FPOINTC> &vecCoord)
{
	vector<FPOINTC> vecBuf;
	int i, j, nLen;

	char    pText[256] = { 0, };
	nLen = WideCharToMultiByte(CP_ACP, 0, strCannedText, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, strCannedText, -1, pText, nLen, NULL, NULL);

	for (i = 0; i < nLen; i++)
	{
		if (GetDrillPoints(pText[i], fptStart, vecBuf, fDistance))
		{
			for (j = 0; j < vecBuf.size(); j++)
			{
				vecCoord.push_back(vecBuf[j]);
			}
			fptStart.x += 5.0*fDistance;
		}
	}
}

int CSimple274X::GetVectorDir(FPOINT start, FPOINT middle, FPOINT end)
{
	double temp;
	temp = middle.x*end.y - start.y*middle.x - start.x*end.y - middle.y*end.x
		+ start.x*middle.y + start.y*end.x;
	if (temp > 0.0)
		return CW;
	else if (temp < 0.0)
		return CCW;
	else
		return PARALLEL;
}

BOOL CSimple274X::CheckPointInMyConcavePolygon(vector <FPOINTC> fPoint, double x, double y)
{
	return CheckPointInPolygonEx(fPoint, x, y);
}

BOOL CSimple274X::CheckPointInPolygonEx(vector<FPOINTC> vecTest, double x, double y)
{
	int  i, j = 0;
	BOOL inpoly = FALSE;

	// The following code is by Randolph Franklin
	for (i = 0, j = vecTest.size() - 1; i < vecTest.size(); j = i++)
	{
		if ((((vecTest[i].y <= y) && (y < vecTest[j].y)) || ((vecTest[j].y <= y) && (y < vecTest[i].y))) &&
			(x < (vecTest[j].x - vecTest[i].x) * (y - vecTest[i].y) / (vecTest[j].y - vecTest[i].y) + vecTest[i].x))
			inpoly = !inpoly;
	}
	return inpoly;
}

// an n-sided regular polygon
BOOL CSimple274X::MyPolygonNSide(int n, float cX, float cY, float d, float ang, BOOL bCheck)
{
	vector <FPOINTC> vecVertics;
	float cV, sV, sTheta, cTheta, XX, YY, R, X1, Y1, Theta;
	int i;

	FPOINTC fpt;
	if (n < 3) return FALSE;

	vecVertics.clear();

	cV = cos(ang * DEG2RAD);
	sV = sin(ang * DEG2RAD);
	R = d / 2;

	Theta = 2 * PI / n;
	X1 = R;
	Y1 = 0;

	for (i = 0; i < n; i++)
	{
		sTheta = sin(i * Theta);
		cTheta = cos(i * Theta);
		XX = X1 * cTheta - Y1 * sTheta;
		YY = X1 * sTheta + Y1 * cTheta;

		fpt.x = (XX * cV - YY * sV) + cX;
		fpt.y = (XX * sV + YY * cV) + cY;
		vecVertics.push_back(fpt);
	}

	if (bCheck)
	{
		if (CheckPointInMyConcavePolygon(vecVertics, m_fptPickObject.x, m_fptPickObject.y))
			return TRUE;
	}
	else
	{
		if (m_nApertureListIndex == -1)
		{
			DrawConcavePolygon(vecVertics);
		}
		else
		{
			glPushMatrix();
			glTranslatef(cX, cY, 0);
			glCallList(m_nApertureListIndex);
			glPopMatrix();
		}
	}
	return FALSE;
}

void CSimple274X::MyCallApertureList(float fx, float fy, int nListNum)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->MyCallApertureList(fx, fy, nListNum);
}

void CSimple274X::DrawConcavePolygon(const vector <FPOINTC> &fPoint)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawConcavePolygon(fPoint);
}

void CSimple274X::DrawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, int fill)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawQuad(x1, y1, x2, y2, x3, y3, x4, y4, fill);
}

void CSimple274X::DrawRect(const CfPoint3D &fptStart, const CfPoint3D &fptEnd, int width, int fill)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawRect(fptStart, fptEnd, width, fill);
}

void CSimple274X::DrawDonut(float fCx, float fCy, float fDmo, float fDmi)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawDonut(fCx, fCy, fDmo, fDmi);
}

BOOL CSimple274X::CheckPointInMyLineRound(float fSx, float fSy, float fEx, float fEy, float fLineWidth, double x, double y)
{
	float fRadius = fLineWidth / 2.0;
	GLfloat fArcLenth = PI * fRadius;
	CfPoint fbuf;
	CfPoint fStart, fEnd;
	float fLineAngle;
	FPOINTC fp1, fp2, fp3, fp4;
	fStart = CfPoint(fEx, fEy);
	fEnd = CfPoint(fSx, fSy);
	if (fStart.x > fEnd.x)
	{
		fbuf = fStart;
		fStart = fEnd;
		fEnd = fbuf;
	}

	float fdifferx = fEnd.x - fStart.x;
	float fdiffery = fEnd.y - fStart.y;
	if (fdifferx == 0)
	{
		fLineAngle = PI / 2;
		if (fStart.y > fEnd.y)
		{
			fbuf = fStart;
			fStart = fEnd;
			fEnd = fbuf;
		}
	}
	else
	{
		//fLineAngle = atan(fdiffery/fdifferx);//kjc
		fLineAngle = atan2(fdiffery, fdifferx);
		if (fLineAngle < 0)
		{
			fLineAngle += 2.0*PI;
		}
	}
	fp1.x = fEnd.x + fRadius*cos(fLineAngle - PI / 2.0);
	fp1.y = fEnd.y + fRadius*sin(fLineAngle - PI / 2.0);
	fp2.x = fEnd.x + fRadius*cos(fLineAngle + PI / 2.0);
	fp2.y = fEnd.y + fRadius*sin(fLineAngle + PI / 2.0);
	fp3.x = fStart.x + fRadius*cos(fLineAngle + PI / 2.0);
	fp3.y = fStart.y + fRadius*sin(fLineAngle + PI / 2.0);
	fp4.x = fStart.x + fRadius*cos(fLineAngle - PI / 2.0);
	fp4.y = fStart.y + fRadius*sin(fLineAngle - PI / 2.0);

	if (CheckPointInQuad(fp1.x, fp1.y, fp2.x, fp2.y, fp3.x, fp3.y, fp4.x, fp4.y, x, y))
		return TRUE;
	else
	{
		if (CheckPointInArc(fEnd.x, fEnd.y, fRadius, fLineAngle - PI / 2.0, fLineAngle + PI / 2.0, x, y))
			return TRUE;
		else
		{
			if (CheckPointInArc(fStart.x, fStart.y, fRadius, fLineAngle + PI / 2.0, fLineAngle - PI / 2.0, x, y))
				return TRUE;
			else
				return FALSE;
		}
	}
}

BOOL CSimple274X::CheckPointInArc(double cx, double cy, double radius, double startAngle, double endAngle, double x, double y)
{
	if (startAngle < 0)
		startAngle += 2.0*PI;
	if (startAngle > 2.0*PI)
		startAngle -= 2.0*PI;
	if (endAngle < 0)
		endAngle += 2.0*PI;
	if (endAngle > 2.0*PI)
		endAngle -= 2.0*PI;
	double angleRad;
	angleRad = atan2(y - cy, x - cx);
	if (angleRad < 0)
		angleRad += 2.0*PI;
	if (startAngle <= endAngle)
	{
		if (startAngle <= angleRad && endAngle >= angleRad)
		{
			if (CheckPointInCircle(cx, cy, radius, x, y))
				return TRUE;
			else
				return FALSE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		if (startAngle <= angleRad || endAngle >= angleRad)
		{
			if (CheckPointInCircle(cx, cy, radius, x, y))
				return TRUE;
			else
				return FALSE;
		}
		else
		{
			return FALSE;
		}
	}
}

void CSimple274X::DrawArcRound(GLfloat cx, GLfloat cy, GLfloat r, GLfloat start_angle, GLfloat arc_angle, GLfloat width, int dir, int fill)
{
	vector <FPOINTC> vecVertics;
	GLfloat halfWidth = width / 2.0;
	FPOINTC bufPt;

	vecVertics.clear();
	if (dir == CW)
	{
		GetArcVertices(vecVertics, FPOINTC(cx, cy), r - halfWidth, start_angle, arc_angle, CW);
		bufPt.x = cx + r*cos(start_angle - arc_angle);
		bufPt.y = cy + r*sin(start_angle - arc_angle);
		if (start_angle - arc_angle - PI < 0)
		{
			GetArcVertices(vecVertics, bufPt, halfWidth, start_angle - arc_angle + PI, PI, CCW);
		}
		else
		{
			GetArcVertices(vecVertics, bufPt, halfWidth, start_angle - arc_angle - PI, PI, CCW);
		}
		if (start_angle - arc_angle < 0)
		{
			GetArcVertices(vecVertics, FPOINTC(cx, cy), r + halfWidth, start_angle - arc_angle + 2.0*PI, arc_angle, CCW);
		}
		else
		{
			GetArcVertices(vecVertics, FPOINTC(cx, cy), r + halfWidth, start_angle - arc_angle, arc_angle, CCW);
		}


		bufPt.x = cx + r*cos(start_angle);
		bufPt.y = cy + r*sin(start_angle);
		GetArcVertices(vecVertics, bufPt, halfWidth, start_angle, PI, CCW);
	}
	else if (dir == CCW)
	{
		GetArcVertices(vecVertics, FPOINTC(cx, cy), r - halfWidth, start_angle, arc_angle, CCW);
		bufPt.x = cx + r*cos(start_angle + arc_angle);
		bufPt.y = cy + r*sin(start_angle + arc_angle);
		if (start_angle + arc_angle + PI > 2.0*PI)
		{
			GetArcVertices(vecVertics, bufPt, halfWidth, start_angle + arc_angle - PI, PI, CW);
		}
		else
		{
			GetArcVertices(vecVertics, bufPt, halfWidth, start_angle + arc_angle + PI, PI, CW);
		}
		if (start_angle + arc_angle > 2.0*PI)
		{
			GetArcVertices(vecVertics, FPOINTC(cx, cy), r + halfWidth, start_angle + arc_angle - 2.0*PI, arc_angle, CW);
		}
		else
		{
			GetArcVertices(vecVertics, FPOINTC(cx, cy), r + halfWidth, start_angle + arc_angle, arc_angle, CW);
		}


		bufPt.x = cx + r*cos(start_angle);
		bufPt.y = cy + r*sin(start_angle);
		GetArcVertices(vecVertics, bufPt, halfWidth, start_angle, PI, CW);
	}
	//	pView->m_pGalvano->ArcDataWrite(pView->m_pGalvano->m_nArcIndex, cx, cy, r, RAD2DEG*start_angle, RAD2DEG*arc_angle, dir);

	if (fill)
		DrawConcavePolygon(vecVertics);
	else
		DrawPolygonLine(vecVertics);
	return;
}

void CSimple274X::DrawLineRound(float fSx, float fSy, float fEx, float fEy, float fLineWidth, BOOL bFill)
{
	vector <FPOINTC> vecVertics;
	FPOINTC bufPt;

	vecVertics.clear();

	bufPt.x = fSx;
	bufPt.y = fSy;
	float fLineAngle = atan2(fSy - fEy, fSx - fEx);
	float fBufAngle;
	float fRadius = fLineWidth / 2.0;
	fBufAngle = fLineAngle - PI / 2.0;
	if (fBufAngle < 0)
		fBufAngle += 2.0*PI;

	GetArcVertices(vecVertics, bufPt, fRadius, fBufAngle, PI, CCW);
	bufPt.x = fEx;
	bufPt.y = fEy;
	fBufAngle += PI;
	if (fBufAngle > 2.0*PI)
		fBufAngle -= 2.0*PI;

	GetArcVertices(vecVertics, bufPt, fRadius, fBufAngle, PI, CCW);
	if (bFill)
	{
		DrawConvexPolygon(vecVertics);
	}
	else
	{
		DrawPolygonLine(vecVertics);
	}

	// 	pView->m_pGalvano->LineDataWrite(pView->m_pGalvano->m_nLineIndex, fSx, fSy, fEx, fEy);
}

void CSimple274X::DrawCircle(GLfloat cx, GLfloat cy, GLfloat r, int fill)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawCircle(cx, cy, r, fill);
}


void CSimple274X::StencilBegin()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->StencilBegin();
}

void CSimple274X::StencilSet(BOOL bStencil)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->StencilSet(bStencil);
}

void CSimple274X::StencilClear(BOOL bStencil)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->StencilClear(bStencil);
}

void CSimple274X::StencilBitRev(const vector <FPOINTC> &vecVertics, int nNumOfVertex)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->StencilBitRev(vecVertics, nNumOfVertex);
}

void CSimple274X::StencilReverse(const vector <FPOINTC> &vecVertics, int nNumOfVertex)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->StencilReverse(vecVertics, nNumOfVertex);
}

void CSimple274X::StencilEnd()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->StencilEnd();
}
void CSimple274X::DrawBegin(int nMode, int nSize, COLORREF color)
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawBegin(nMode, nSize, color);
}

void CSimple274X::DrawEnd()
{
	CMyGerberDlg* pParent = (CMyGerberDlg*)m_pParent;
	if (pParent)
		pParent->DrawEnd();
}

#pragma once
#include "DefineColor.h"
#include "PostfixCalc.h"
#include "SimpleType.h"

#include <vector>
using namespace std;

// CSimple274X

#ifndef PI
#define PI 3.141592653589793f
#endif

#ifndef DEG2RAD
const double DEG2RAD = PI / 180.0;
#endif

#ifndef RAD2DEG
const double RAD2DEG = 180.0 / PI;
#endif


#ifndef DetGcode
#define DetGcode 99999
#endif


union TEMPLATE_KEY {
	float Param[2];
	UINT64 key;
};


typedef struct tagLineInfo {
	tagLineInfo()
	{
		nNumOfLine = 0;
		dCode = 0;
		nLayerID = 0;
		nStepID = 0;
	}
	int nNumOfLine;
	int dCode;
	int nLayerID;
	int nStepID;
}LINE_INFO, LPLINE_INFO;
typedef CMap <float, float, LINE_INFO, LINE_INFO> CMapLineInfo;

typedef CMap <CString, LPCTSTR, CString, LPCTSTR> CMapAMMacro;


namespace LAYER_TYPE
{
	enum STEP
	{
		PIECE,
		STRIP,
		PANEL
	};

	enum TYPE
	{
		PATTERN = 0,
		THROUGH_HOLE = 1,
		VIA_HOLE = 2,
		PAD = 3,
		SOLDER_REGIST = 4,
		INSPECTION_AREA = 5,
		MASK = 6,
		MASK_FREE = 7,
		ANOTHER_LAYER_DRILL = 8,	//LIQUID_PHOTO_RESIST= 8,
		VIRTUAL_DRILL = 9,
		ROUTER = 10,
		GROUND = 11,
		FILLED_VIA = 12,
		UNDER_LAYER = 13,
		COVERLAY = 14,
		LEAD = 15,
		NETLIST = 16
	};

	enum POLARITY
	{
		POSITIVE,
		NEGATIVE,
	};

	enum UNIT
	{
		METRIC,
		INCH,
	};
};

namespace CAM_DATA
{
	enum FORMAT
	{
		RS274X = 0,
		RS274D,		// rect zoom
		ODB,
		DXF,
		DPF,
		EXCELLON,
		GDS2,
		UNKNOWN
	};
};

namespace TRANSFORM_DATA
{
	enum TYPE
	{
		NONE,
		MIRROR_V,		// rect zoom
		MIRROR_H,
		ROTATE_180,
		ROTATE_CCW,
		ROTATE_CW
	};
};

struct GraphObj
{
	// Constructor.
	// Parameters: see member variables.
	GraphObj()
	{
		dCode = 0;
		dAttrListCode = 0;
		Type.nType = 0;
		Type.nAttr = 0;
		Type.nPolarity = 0;
		Type.nOrient = 0;
		Type.nReserve1 = 0;
		Type.nReserve2 = 0;
		Type.nParentid = 0;
		nStPnt = 0;
	}
	union
	{
		struct TYPE
		{
			UINT16 nType : 4;		// allocation 4 bit, max 16 : Line arc Polygon 
			UINT16 nAttr : 6;		// allocation 5 bit, max 64 Drill or Pattern
			UINT16 nPolarity : 1;	// allocation 1 bit, Positive or Negative
			UINT16 nOrient : 3;	// allocation 3 bit, max 8
			UINT16 nReserve1 : 1;	// allocation 1 bit, max 2
			UINT16 nReserve2 : 1;	// allocation 1 bit, max 2
			UINT16 nParentid : 16;	// allocation 16 bit, max 65535
		};
		TYPE Type;
		UINT nValue;
	};

	UINT dCode;	 // Specifies the Pointer to the Standard Symbol of the Object.
	UINT dAttrListCode;				 // (Specifies the number of vertexes if the object is surface type)
	int nStPnt;		 // Start Point
	FRECTC Extent;   // Specifies the minmax area of an Object

};
typedef CArray<GraphObj, GraphObj> CArGraphObj;

namespace DRAW_TYPE
{
	enum TYPE
	{
		LINE,
		ARC_CW,
		ARC_CCW,
		POLYGON,
		SURFACE,
		POLYGON_SQ, // Single quadrant arc for RS274X
		POLYGON_MQ, // Multi quadrant arc for RS274X
		FLASH,
		TEXT,
		SNR
	};

	enum ATTRIBUTE
	{
		PATTERN,
		THROUGH_HOLE,
		VIA_HOLE,
		LEAD,
		DUMMY,
		VIRTUAL_DRILL,
		FINE_PAD,
		FILLED_VIA,
		GROUND,
		FIDUCIAL,
		ROUTE,
		INSPECTION,
		RESERVE1,
		ASD_DRILL,
		RESERVE2,
		NONE
	};

	enum POLARITY
	{
		POSITIVE,
		NEGATIVE
	};

	enum ORIENT
	{
		DEGREE_0 = 0,
		DEGREE_90 = 1,
		DEGREE_180 = 2,
		DEGREE_270 = 3,
		MIRROR_D0 = 4,
		MIRROR_D90 = 5,
		MIRROR_D180 = 6,
		MIRROR_D270 = 7
	};

	enum TEXT_VERSION
	{
		PREVIOUS = 0,
		CURRENT = 1
	};
}

typedef struct tagAptPrimitive
{
	tagAptPrimitive()
	{
		nPriNum = 0;
		fParam.clear();
		minmax = FRECTC();
	}
	BYTE nPriNum;
	vector <float> fParam;
	FRECTC minmax;
}APERTURE_PRIMITIVE, *LPAPERTURE_PRIMITIVE;

typedef struct tagApertureDef
{
	tagApertureDef()
	{
		nGlListIndex = 0;
		chStdAptType = NULL;
		strAptName.Empty();
		Param.clear();
		minmax = FRECTC();
	}
	UINT	nGlListIndex;
	TCHAR	chStdAptType;	// 'C' 'R' 'O' 'P
	CString strAptName;
	vector <APERTURE_PRIMITIVE> Param;
	FRECTC minmax;
}APERTURE_DEF, *LPAPERTURE_DEF;


typedef struct tagLayerInform_RS274X
{
	BOOL bView;
	int Exterior;
	int nLayerGroupID;
	int nOrder;

	CString strFilePath;
	CString strName; // fetch layer name from gerber file

	LAYER_TYPE::TYPE Type;
	LAYER_TYPE::POLARITY  bPolarity;
	LAYER_TYPE::UNIT bUnit; // Metric Or Inch	
	LAYER_TYPE::STEP Step;
	CAM_DATA::FORMAT nFormat;

	float fScaleX;		// X axis scale factor from gerber file analysis
	float fScaleY;		// Y axis scale factor from gerber file analysis

	float fAdjScaleX;	// scaling X by external cam operation
	float fAdjScaleY;	// scaling X by external cam operation
	float fAdjOffsetX;	// translate X by external cam operation
	float fAdjOffsetY;	// translate X by external cam operation

	FRECTC Extent;
	//	vector <UINT64> vecDrawTemplateList;
	vector <GraphObj> listObj;
	vector <FPOINTC> vecObjCoord;
	vector <FRECTC> vecObjExtent;
	CMap <DRAW_TYPE::ATTRIBUTE, DRAW_TYPE::ATTRIBUTE, COLORREF, COLORREF> mapObjColor;
	CMap <int, int, LPAPERTURE_DEF, LPAPERTURE_DEF> mapAptList;

	tagLayerInform_RS274X()
	{
		strName.Empty();
		strFilePath.Empty();

		Type = LAYER_TYPE::TYPE::PATTERN;
		bPolarity = LAYER_TYPE::POLARITY::POSITIVE;
		bUnit = LAYER_TYPE::UNIT::METRIC;
		Step = LAYER_TYPE::STEP::PANEL;
		nFormat = CAM_DATA::FORMAT::RS274X;

		fScaleX = 1.0;
		fScaleY = 1.0;

		fAdjScaleX = 1.0;
		fAdjScaleY = 1.0;
		fAdjOffsetX = 0.0;
		fAdjOffsetY = 0.0;

		bView = TRUE;
		Extent = FRECTC();
		Exterior = 0;
		nOrder = 0;

		nLayerGroupID = 0;
		vecObjCoord.clear();
		vecObjExtent.clear();
	}

}LAYER_INFORM_RS274X, LAYER_INFORM_EXCELLON, *LPLAYER_INFORM_RS274X, *LPLAYER_INFORM_EXCELLON;
typedef CArray <LPLAYER_INFORM_RS274X, LPLAYER_INFORM_RS274X> CArLayerInform_RS274X;

typedef struct tagLayerStruct
{
	UINT nObject;
	UINT nCoord;
}LAYER_STRUCT, *LPLAYER_STRUCT;
typedef CArray <LAYER_STRUCT, LAYER_STRUCT> CArLayerStruct_RS274X;

typedef struct tag_SNR_LIST_INDEX {
	GLuint     nObjectIndex;
	GLuint     nListIndex;
	FRECTC	   frtBoundingBox;
} SNR_LIST_INDEX, *PSNR_LIST_INDEX;

struct ParamIP	// Parameter 'IP'(Image Polarity) data structure
{
	ParamIP()
	{
		PolChangeFlag = FALSE;
		bLayerPolarity = LAYER_TYPE::POSITIVE;
	}

	BOOL PolChangeFlag;
	BOOL bLayerPolarity;
};

struct ParamFS	// Parameter 'FS'(Format Statement) data structure
{
	ParamFS()
	{
		bSuppress = FALSE;
		bAbsolute = TRUE;
	}
	BOOL bSuppress; //  (FALSE) : 'Leading Zero omitted , (TRUE) : 'Trailing Zero omitted
	BOOL bAbsolute; // 'A' or 'I':  Use A for absolute coordinate values, Use I for incremental coordinate values
};

struct ParamMI	// Parameter 'MI'(Mirror Image) data structure
{
	ParamMI()
	{
		bMirrorX = FALSE;
		bMirrorY = FALSE;
	}

	BOOL bMirrorX, bMirrorY;
};

struct ParamSR	// Parameter 'SR'(Step & Repeat) data structure
{
	ParamSR()
	{
		nXRepeat = 0;
		nYRepeat = 0;
		psRepeat = 0;
	}
	int nXRepeat, nYRepeat;
	int psRepeat;
};

struct ParamAD	// Parameter 'AD'(Aperture Discription) data structure
{
	ParamAD()
	{
		bExposureMode = FALSE;
	}
	BOOL bExposureMode;
};


class CSimple274X : public CWnd
{
	DECLARE_DYNAMIC(CSimple274X)

	enum VectDir { CCW = -1, PARALLEL, CW };

	CWnd* m_pParent;
	HWND m_hCtrl;
	CRect m_rtDispCtrl;
	int m_nWorldW, m_nWorldH;
	double m_dScaleX, m_dScaleY;

	CPostfixCalc m_PostfixCalc;
	//stSpecLayer m_stSpecLayer;
	CString m_sPathFile;
	BOOL m_bEnableDraw;
	//BOOL m_bFindObjExtentPickingMode;
	double m_fCosine, m_fSine; // matrix calculation factor for translate or ratate 

	LPAPERTURE_DEF m_pAptDef, m_rAptDef;
	FPOINTC m_fptPickObject;

	int m_nLayer;
	int m_nApertureListIndex;
	int m_nActionCode;

	LPLAYER_INFORM_RS274X m_pLayerInfo;
	APERTURE_PRIMITIVE m_AptPrimi;

	vector <UINT64> m_vecTemp;
	GraphObj m_gObj;
	COLORREF m_crObjColor;
	BOOL m_bDisplayBackgroundImg;
	BOOL m_bCheckDraw;
	BOOL m_bParsingXYFlag, m_bParsingIJFlag;
	BOOL m_bParsingGCodeFlag, m_bParsingdCodeFlag;
	BOOL m_bPolygonFlag, m_bImplicitFlag;
	BOOL m_bLastFrame;
	UINT m_nNumOfLayer;
	UINT m_nNumOfLineObject;
	UINT m_nNumOfAperture;
	UINT m_nNumOfLineTemplate;
	UINT m_nNumOfSnRObject;
	int m_nLayerGroupID;
	int m_nNumOfObjCoord;
	int  m_nNumOfDataBlock;
	int  m_nNumOfTextLine;
	int m_nStartMirrorObj, m_nEndMirrorObj;
	int m_nMaxLineTemplate;
	int m_nObj;
	int m_nNumOfObject, m_nNumOfCoord;
	int m_nPrevDCode, m_nPrevADCode;
	int m_nDCode, m_nGCode, m_nMCode, m_nADCode;
	int m_nIRAngle; // Image Rotation angle
	float m_fLayerScaleX;
	float m_fLayerScaleY;
	float m_dDetZero;
	float m_fStepX, m_fStepY;
	double m_fDividerX, m_fDividerY;
	CfPoint3D m_fExtentStartPos;
	CfPoint3D m_fExtentEndPos;
	FRECTC m_MaxFrameExtent;
	FRECTC m_rectLayerExtent;
	FPOINTC m_fptPrevPos;
	FPOINTC m_fptCoord, m_fptOpt;
	FRECTC m_MnMxSnR, m_CurMinMax;
	ldiv_t m_lDataFormatX, m_lDataFormatY;
	CString m_optionUnit, m_optionFormat;

	LAYER_TYPE::UNIT m_Unit;
	ParamIP m_paramIP;
	ParamFS m_paramFS;
	ParamMI m_paramMI;
	ParamSR m_paramSR;
	ParamAD m_paramAD;


	CArLayerInform_RS274X m_ArLayerInform; // typedef CArray <LPLAYER_INFORM_RS274X, LPLAYER_INFORM_RS274X> CArLayerInform_RS274X;
	CArLayerStruct_RS274X m_ArLayerStruct; // typedef CArray <LAYER_STRUCT, LAYER_STRUCT> CArLayerStruct_RS274X;
	vector <UINT64> m_vecLineTemplate;
	CMapLineInfo m_mapLineInfo;
	CMapAMMacro m_mapAMMacro;

	FRECTC m_FrameExtent;
	FRECTC GetFrameExtent();
	void SetFrameExtent(FRECTC fRect);

	void InitLayerMaxExtent();
	void DeleteLayerInfo();
	FRECTC GetLayerExtent(int nLayer);
	void SetLayerMaxExtent(FRECTC &rect);

	void InitVal();
	void SetActionCode(int nActionCode);

	void StringToChar(CString str, char* szStr);  // char* returned must be deleted... 
	CString CharToString(const char *szStr);

	CString Load(CString sPath);
	void ResetData();
	void ResetDataObject(GraphObj &gObj);
	void ClearDataObject(GraphObj &gObj);

	BOOL Decode(CString sFileData);
	BOOL Decoding(char* pFile, char* pLine);
	BOOL DecodingIgnore(char** pFile, char** pLine);
	BOOL DecodingCoordinate(char** pFile);
	BOOL DecodingFunction(char** pFile);
	BOOL DecodingParameter(char** pFile);
	void DecodingParsingFlag();
	void DecodeDraw();

	FRECTC MinMaxArcInPolygonGRB(DRAW_TYPE::TYPE dType, FPOINTC p1, FPOINTC p2, FPOINTC pC);
	FRECTC MinMaxArcGRB(DRAW_TYPE::TYPE dType, FPOINTC P1, FPOINTC P2, FPOINTC PC, FRECTC CurMinMax);
	FRECTC MinMaxRectVectorGRB(double X1, double Y1, double X2, double Y2, double w, double ang);
	FRECTC MinMaxRectLowerLeftGRB(double X, double Y, double w, double h, double ang);
	FRECTC MinMaxRectCenterGRB(double x, double y, double w, double h, double ang);

	void AdjustExtentByRect(FRECTC &Extent, const FRECTC &rect);
	void AdjustExtentByPoint(FRECTC &Extent, const FPOINTC &pt);

	BOOL CheckPointInRect(FRECTC &fRect, float x, float y);
	BOOL CheckAngleGRB(double AngP, double Ang1, double Ang2, DRAW_TYPE::TYPE dType);
	BOOL CheckArithmeticOperator(char ch);
	BOOL CheckDCodeValue(int nDCode);
	BOOL CheckGCodeValue(int nGCode);
	BOOL CheckMCodeValue(int nMCode);


	float GetDataCoordX(char **pFile);
	float GetDataCoordY(char **pFile);
	int	GetDataInteger(char **pFile);
	float GetDataFloat(char **pFile);
	void GetCosineSineValue(float Ang, float *cV, float *sV);
	
	int GetNumOfLayer();
	int	GetNumOfAperture();
	int	GetNumOfLineTemplate();
	int	GetNumOfSnR();

	BOOL FunctionDCode(char** pFile);
	BOOL FunctionGCode(char** pFile);
	BOOL FunctionMCode(char** pFile);

	BOOL ParameterFS(char** pFile);
	BOOL ParameterAperture(char** pFile);
	BOOL ParameterBkMode(char** pFile);
	BOOL ParameterDashLine(char** pFile);
	BOOL ParameterKnockOut(char** pFile);
	BOOL ParameterSequence(char** pFile);
	BOOL ParameterRotate(char** pFile);
	BOOL ParameterTranslation(char** pFile);
	BOOL ParameterVelocity(char** pFile);
	BOOL ParameterWindowSpec(char** pFile);
	BOOL ParameterI(char** pFile);
	BOOL ParameterL(char** pFile);
	BOOL ParameterM(char** pFile);
	BOOL ParameterO(char** pFile);
	BOOL ParameterP(char** pFile);
	BOOL ParameterS(char** pFile);

	BOOL ApertureDefinition(char** pFile);
	void ApertureCircle(char *pTemp);
	void ApertureLineV(char *pTemp);
	void ApertureLineC(char *pTemp);
	void ApertureLineL(char *pTemp);
	void ApertureOutLine(char *pTemp);
	void AperturePolygon(char *pTemp);
	void ApertureMoire(char *pTemp);
	void ApertureThermal(char *pTemp);

	BOOL FetchApertureCircle(char** pFile);
	BOOL FetchApertureRect(char** pFile);
	BOOL FetchApertureObround(char** pFile);
	BOOL FetchAperturePolygon(char** pFile);

	void StepAndRepeating(FRECTC &Extent, BOOL bClearObjectData = TRUE);
	void ApplyIROptionGRB(LAYER_INFORM_RS274X *pLayerInfo, double cX, double cY, double ang);
	void RotateTransObject(LAYER_INFORM_RS274X *pLayerInfo, GraphObj *obj, GraphObj *Nextobj, FPOINTC fC, double fAng, double tX, double tY);

	float ParseScaleData(char **pFile, BOOL bArithmetic = FALSE);
	float ParseFloatData(char **pFile, BOOL bArithmetic = FALSE);
	int	ParseIntegerData(char **pFile, BOOL bArithmetic = FALSE);
	float ParseRotationData(char **pFile, BOOL bArithmetic = FALSE);
	BOOL ParseApertureMacro(char **pFile, CString &strApertureMacro);

	void Mirror();
	void MirrorVerticalObject(LAYER_INFORM_RS274X *pLayerInfo, GraphObj *obj, int nCoord, double vAxis);  //'좌우미러링
	void MirrorHorizontalObject(vector<FPOINTC> &vecCoord, GraphObj *obj, double hAxis);  //'상하미러링
	void MirrorHorizontalObject(LAYER_INFORM_RS274X *pLayerInfo, GraphObj *obj, int nCoord, double hAxis);  //'상하미러링
	void MirrorVerticalObject(vector<FPOINTC> &vecCoord, GraphObj *obj, double vAxis);  //'좌우미러링
	void RotateRect(FRECTC &fRect, FPOINTC &fCenter, double fAng);
	void RotateRect90(FRECTC &fExtent, FPOINTC &fpt = FPOINTC(0, 0));
	void RotateRect180(FRECTC &fExtent, FPOINTC &fpt = FPOINTC(0, 0));
	void RotateRect270(FRECTC &fExtent, FPOINTC &fpt = FPOINTC(0, 0));
	void RotatePoint(FPOINTC &fpt, FPOINTC &fCenter);
	void RotatePoint(FPOINTC &fpt, FPOINTC &fCenter, double fAng);
	void RotatePoint(FPOINTC &p, double cV, double sV, double cX, double cY);
	void RotatePoint90(FPOINTC &fpt, FPOINTC &fCenter);
	void RotatePoint180(FPOINTC &fpt, FPOINTC &fCenter);
	void RotatePoint270(FPOINTC &fpt, FPOINTC &fCenter);
	void RotateObject90(vector<FPOINTC> &vecCoord, GraphObj *obj, FPOINTC fC);
	void RotateTranslateExtent(FRECTC &Extent, double cV, double sV, double cX, double cY, double dX, double dY);
	void TranslateCoordbyActionCode(vector <FPOINTC> &vecCoord, GraphObj &gObj, FPOINTC fptCenter);
	void TranslatePoint(FPOINTC &p, double dX, double dY);
	void TranslateRect(FRECTC &R, double dX, double dY);
	void cVsV(float Ang, float *cV, float *sV); // Get Rotate parameter, cosine and sine value


	int m_nListIndex; // m_nGLListIndex
	//int m_nListAperture; // m_glListAperture
	//int m_nListLines; // m_glListLines
	//int m_nListSnR; // m_glListSnR

	float m_fCanvasPixelResolution, m_fDrawArcResolution;
	float m_fDrawResolution;

	void SetDrawArcResolution(float fResolution);
	void SetDrawResolution(float fResolution);
	void AllocDrawList();
	void AllocCamDrawStruct();

	// Draw274X
	double m_dPixelResolution;
	int m_nListLines;
	BOOL m_bImageSave;

	UINT16 m_nPrevAttribute;
	UINT16 m_nPrevPolarity;
	void AdjustToScreen(float& X1, float& Y1);
	void AdjustToScreen(float& X1, float& Y1, float& X2, float& Y2);
	void AdjustToScreen(int nIndex, float& X1, float& Y1);
	void AdjustToScreen(int nIndex, float& X1, float& Y1, float& X2, float& Y2);
	void AdjustToScreen(int nIndex, float& X1, float& Y1, float& X2, float& Y2, float& X3, float& Y3);
	COLORREF GetObjectColor(GraphObj &obj);
	COLORREF GetSnRObjectColor(GraphObj &obj);
	void GetArcVertices(vector<FPOINTC> &vecPt, const FPOINTC &ptCenter, float radius, float start_angle, float arc_angle, int dir);
	int GetArcSegment(float fRadius, float fAngle = 360.0);
	double GetDistance(CfPoint FirstPoint, CfPoint SecondPoint);
	double GetInteriorAngle(double x1, double y1, double x2, double y2, double x3, double y3);
	int GetVectorDir(FPOINT start, FPOINT middle, FPOINT end);
	void GetCannedText(CString strCannedText, FPOINTC fptStart, float fDistance, vector <FPOINTC> &vecCoord);
	BOOL GetDrillPoints(char ch, FPOINTC fptStart, vector<FPOINTC> &vecPt, float fDistance);
	void GetDrillIndex(FPOINTC fptStart, int* arIndex, int nCount, vector<FPOINTC> &vecPt, float fDistance);
	int GetVectorDir(double ax, double ay, double bx, double by, double cx, double cy);
	void SetPixelResolution(double dPixelResolution);
	void SetForeColor(COLORREF crColor);
	int SearchLineTemplate(UINT64 nVal);
	BOOL CheckDrawAllow(const FRECTC &FMinMax);
	BOOL CheckArcRound(GLfloat cx, GLfloat cy, GLfloat r, GLfloat start_angle, GLfloat arc_angle, GLfloat width, int dir, float x, float y);
	BOOL CheckPointInMyLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight, double x, double y);
	BOOL CheckPointInCircle(double cx, double cy, double radius, double x, double y);
	BOOL CheckPointInQuad(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x, double y);
	BOOL CheckPointInMyConcavePolygon(vector <FPOINTC> fPoint, double x, double y);
	BOOL CheckPointInPolygonEx(vector<FPOINTC> vecTest, double x, double y);
	BOOL CheckPointInMyRect(float fSx, float fSy, float fEx, float fEy, double x, double y);
	BOOL CheckPointInMyDonut(float fCx, float fCy, float fDmo, float fDmi, double x, double y);
	BOOL CheckPointInMyLineRound(float fSx, float fSy, float fEx, float fEy, float fLineWidth, double x, double y);
	BOOL CheckPointInArc(double cx, double cy, double radius, double startAngle, double endAngle, double x, double y);
	void Draw274X();
	void DrawBegin(int nMode, int nSize, COLORREF color);
	void DrawEnd();
	void Drawing_0();
	BOOL DrawObject(int nObjIndex);
	void DrawConvexPolygon(const vector <FPOINTC> &fPoint);
	void DrawConvexPolygon(const FPOINTC *fPoint, int nNumberOfVertex);
	void DrawPolygonLine(const vector <FPOINTC> &vecPt, int nLineWidth = 0);
	void DrawLineRect(float fSx, float fSy, float fEx, float fEy, float fLineWidth, float fLineHeight);
	void DrawConcavePolygon(const vector <FPOINTC> &fPoint);
	void DrawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, int fill = TRUE);
	void DrawRect(const CfPoint3D &fptStart, const CfPoint3D &fptEnd, int width = 0, int fill = TRUE);
	void DrawDonut(float fCx, float fCy, float fDmo, float fDmi);
	void DrawArcRound(GLfloat cx, GLfloat cy, GLfloat r, GLfloat start_angle, GLfloat arc_angle, GLfloat width, int dir, int fill = TRUE);
	void DrawLineRound(float fSx, float fSy, float fEx, float fEy, float fLineWidth, BOOL bFill = TRUE);
	void DrawCircle(GLfloat cx, GLfloat cy, GLfloat r, int fill = TRUE);
	void StencilBegin();
	void StencilSet(BOOL bStencil);
	void StencilClear(BOOL bStencil);
	void StencilBitRev(const vector <FPOINTC> &vecVertics, int nNumOfVertex);
	void StencilReverse(const vector <FPOINTC> &vecVertics, int nNumOfVertex);
	void StencilEnd();
	BOOL MyObjEntityShift(int k, float dX, float dY);
	BOOL MyMacro(const LPAPERTURE_DEF &pAptDef, float x, float y, byte Pol, BOOL bCheck = FALSE);
	void MyLineList(float X1, float Y1, float X2, float Y2, int nListNum);
	BOOL MyRectCenter(float fSx, float fSy, float fLineWidth, float fLineHeight, float fAngle, BOOL bCheck = FALSE);
	BOOL MyPolygonNSide(int n, float cX, float cY, float d, float Ang, BOOL bCheck = FALSE);
	BOOL MyThermal(float x, float y, float Dmo, float Dmi, float Ang, int num, float gap, float Angle, BOOL bCheck = FALSE);
	BOOL MyPolygon(const FPOINTC *fCoord, int nVertex, BOOL bCheck = FALSE);
	BOOL MyLine(float fSx, float fSy, float fEx, float fEy, float fLineWidth, BOOL bCheck = FALSE);
	BOOL MyRectLowerLeft(float fSx, float fSy, float fLineWidth, float fLineHeight, float fAngle, BOOL bCheck = FALSE);
	BOOL MyMoire(float x, float y, float fOutDiameter, float fRingWidth, float fGap, int nCircle, float fLineWidth, float fLineLegth, float Ang, BOOL bCheck = FALSE);
	BOOL MyLineMacro(float fSx, float fSy, float fEx, float fEy, FRECTC fExtent, BOOL bCheck = FALSE);
	void MyCallApertureList(float fx, float fy, int nListNum);
	BOOL MyOval(float fCx, float fCy, float fWidth, float fHeight, BOOL bCheck = FALSE);
	BOOL MyQuadrantPolygon(GraphObj *obj, GraphObj *NextObj, BOOL bCheck = FALSE);
	BOOL MyQuadrantPolygonShift(GraphObj *obj, GraphObj *Nextobj, float dX, float dY, BOOL bCheck = FALSE);
	BOOL MySnRObjList(GraphObj &gObj, int nObjIndex, float ddX, float ddY);
	//BOOL MySnRObjList(GraphObj &gObj, int nObjIndex, float ddX, float ddY, BOOL bCheck = FALSE);
	BOOL MyArc(float fSx, float fSy, float fEx, float fEy, float fCX, float fCY, float fWidth, int nDir, BOOL bCheck = FALSE);
	FPOINTC OriginTranslateCoord(vector <FPOINTC> &vecCoord, GraphObj &gObj, FRECTC fExtent);

	//BOOL MyExcellonObjShift(const vector<FPOINTC> &vecObjCoord, GraphObj &gObj, int nObjIndex, float dX, float dY, BOOL bCheck = FALSE);

public:
	CSimple274X(CWnd* pParent=NULL);
	virtual ~CSimple274X();

public:
	void SetHwnd(HWND hCtrlWnd); // Static Windows for Drawing.
	BOOL LoadGerbFile(CString sPath);
	void DrawGerbFile();
	FRECTC GetLayerMaxExtent();
	double GetScaleOfScreen();
	LPLAYER_INFORM_RS274X GetLayerInfo();
	COLORREF GetObjectColorCurrent();

protected:
	DECLARE_MESSAGE_MAP()
};



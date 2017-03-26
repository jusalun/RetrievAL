#pragma once

#include <windows.h>
#include "bcb6_std_vector.h"
#include "bcb6_std_string.h"
#include "TDrawGrid.h"
#include "TSSGScriptStruct.h"
#include "TSSGCtrl.h"
#include "TCalcImage.h"
#include "TGuideForm.h"

typedef struct
{
	LPVOID           *VTable;
	BYTE             padding1[748];
	LPVOID           MainMenu1;
	LPVOID           M_File;
	LPVOID           M_Exit;
	LPVOID           Splitter;
	LPVOID           N1;
	LPVOID           M_TitleSelect;
	LPVOID           M_Memory;
	LPVOID           M_MemorySetting;
	LPVOID           M_View;
	LPVOID           M_Customize;
	LPVOID           N2;
	LPVOID           M_AlwaysOnTop;
	LPVOID           N4;
	LPVOID           M_FindName;
	LPVOID           M_SSGReFind;
	LPVOID           M_Help;
	LPVOID           M_UseHelp;
	LPVOID           M_SSGHelp;
	LPVOID           M_CLDHelp;
	LPVOID           N3;
	LPVOID           M_Version;
	LPVOID           M_Creator;
	LPVOID           M_HomePage;
	LPVOID           M_OnMostTop;
	LPVOID           M_ProcessAdd;
	LPVOID           ListPMenu;
	LPVOID           P_AllNonCheck;
	LPVOID           P_AllCheck;
	LPVOID           M_UnLockWrite;
	LPVOID           P_SelectCheck;
	LPVOID           P_NonSelectCheck;
	LPVOID           P_OnlyNonSelectCheck;
	LPVOID           P_OnlySelectCheck;
	LPVOID           N5;
	LPVOID           N8;
	LPVOID           M_Address;
	LPVOID           M_ClearSelectAdjustAttribute;
	LPVOID           M_ClearAllAdjustAttribute;
	LPVOID           M_AutoDialogAdjustment;
	LPVOID           N6;
	LPVOID           N10;
	LPVOID           M_SaveSubjectStatus;
	LPVOID           M_LoadSubjectStatus;
	LPVOID           M_SearchAdjustment;
	LPVOID           N9;
	TDrawGrid        *DGrid;
	LPVOID           M_UserMode;
	LPVOID           M_BegginerMode;
	LPVOID           M_NormalMode;
	LPVOID           M_CreatorMode;
	LPVOID           M_DebaggerMode;
	LPVOID           M_SystemCheck;
	LPVOID           HotKeyEdit;
	LPVOID           PageCtrl;
	LPVOID           CtrlTabS;
	LPVOID           PanelImage;
	LPVOID           LockCBox;
	LPVOID           StringNowValEdit;
	LPVOID           StringNewValEdit;
	LPVOID           ToggleCBox;
	LPVOID           StringEnterBtn;
	LPVOID           MultiLBox;
	LPVOID           ListLBox;
	LPVOID           InfoTabS;
	LPVOID           NoteREdit;
	LPVOID           ScriptInfoPanel;
	LPVOID           Label2;
	LPVOID           Label1;
	LPVOID           CreatorEdit;
	LPVOID           MakerEdit;
	LPVOID           CautionTabS;
	LPVOID           CautionREdit;
	COLORREF         titleColor;
	COLORREF         dirColor;
	COLORREF         calcColor;
	COLORREF         toggleColor;
	COLORREF         listColor;
	COLORREF         bitListColor;
	COLORREF         stringColor;
	COLORREF         backColor;
	COLORREF         traceColor;
	COLORREF         panelBackColor;
	long             shadowColor;
	long             shadowMode;
	long             shadowOffset;
	BOOLEAN          isAutoSaveAdjustVal;
	BOOLEAN          isNowValueDraw;
	long             userMode;
	LPVOID           panelG;
	LPVOID           backG;
	BYTE             padding2[4];
	bcb6_std_string  backGPath;
	bcb6_std_string  panelGPath;
	bcb6_std_string  calcFreeName;
	bcb6_std_string  calcPushName;
	bcb6_std_string  splashPath;
	BOOLEAN          isCalcHex;
	BOOLEAN          isBackGUse;
	BOOLEAN          isPanelGUse;
	BOOLEAN          isSplashUse;
	BYTE             greatTopModeKey;
	BYTE             padding3[3];
	TSSGScriptStruct selectScript;
	LPVOID           treeBackScreen;
	LPVOID           invertImage;
	LPVOID           mostTopImage;
	TSSGSubject      *selectSubject;
	TCalcImage       *calcImage;
	BYTE             listCheckedVec[36];
	long             treeFontWidth;
	int              nowSelectSubjectIndex;
	int              invertGridRow;
	long             nowPanelType;
	long             maxNameLength;
	LPVOID           findNameForm;
	LPVOID           searchForm;
	TGuideForm       *guideForm;
	long             guideFormLeft;
	long             guideFormTop;
	long             guideFormWidth;
	long             guideFormHeight;
	long             searchFormLeft;
	long             searchFormTop;
	long             searchFormWidth;
	long             searchFormHeight;
	long             findFormLeft;
	long             findFormTop;
	long             findFormWidth;
	long             findFormHeight;
	long             lastTitleIndex;
	long             lastKeyIndex;
	long             titleFindHeight;
	long             titleSelectWindowWidth;
	long             titleSelectWindowHeight;
	BOOLEAN          isTitleFindUp;
	BOOLEAN          isAdjustGuideUse;
	bcb6_std_string  sortKey;
	BOOLEAN          nowAdjusting;
	BOOLEAN          canChange;
	long             wheelDeltaCount;
	BYTE             topManager[8];
	BYTE             topManagerListner[168];
	BYTE             ssgActionListner[16];
	BYTE             adjustmentListner[16];
	BYTE             strD[144];
	TSSGCtrl         ssgCtrl;
	bcb6_std_string  exeDir;
	BYTE             searchMode;
	BYTE             padding4[7];
	bcb6_std_vector  keyToIndexMap;
	bcb6_std_vector  scriptVec;
	bcb6_std_vector  toScriptVec;
	bcb6_std_vector  treeSubjectVec;
} TMainForm;

#define MainForm (*(TMainForm **)0x0064CE2C)

typedef void(__cdecl *LPFN_TMAINFORM_DRAWTREECELL)(TMainForm *_this, LPVOID DestCanvas, int ARow, RECT *Rect);
#define TMainForm_DrawTreeCell ((LPFN_TMAINFORM_DRAWTREECELL)0x00444848)

#if 0
typedef void(__cdecl *LPFN_TMAINFORM_DRAWTREE)(TMainForm *_this, LPVOID DestCanvas, long LeftOffset, long TopOffset);
#define TMainForm_DrawTree ((LPFN_TMAINFORM_DRAWTREE)0x00446448)
#else
EXTERN_C void __stdcall TMainForm_DrawTree(TMainForm *_this, LPVOID DestCanvas, long LeftOffset, long TopOffset, BOOL IgnoreDebug);
#endif

EXTERN_C void __fastcall _TMainForm_FormMouseWheel(TMainForm *_this, LPVOID Sender, int Shift, BOOLEAN *Handled, POINT *MousePos, int WheelDelta);
#define TMainForm_FormMouseWheel(_this, Sender, Shift, Handled, MousePos, WheelDelta) TMainForm_FormMouseWheel(_this, Sender, Shift, WheelDelta, MousePos, Handled)

#if 0
typedef void(__cdecl *LPFN_TMAINFORM_CHECKTREESIZE)(TMainForm *_this, BOOLEAN AllWidthCheck);
#define TMainForm_CheckTreeSize ((LPFN_TMAINFORM_CHECKTREESIZE)0x00446E88)
#else
EXTERN_C void __cdecl TMainForm_CheckTreeSize(TMainForm *_this, BOOLEAN AllWidthCheck);
#endif

EXTERN_C void __fastcall TMainForm_HotKeyEditKeyDown(TMainForm *_this, LPVOID Sender, WORD *Key, int Shift);

EXTERN_C void __stdcall TMainForm_Guide(const char *Mes, BOOLEAN IsClear);

EXTERN_C void __fastcall _TMainForm_DGridSelectCell(TMainForm *_this, LPVOID Sender, int ACol, BOOLEAN *CanSelect, int ARow);
#define TMainForm_DGridSelectCell(_this, Sender, ACol, ARow, CanSelect) _TMainForm_DGridSelectCell(_this, Sender, ACol, CanSelect, ARow)

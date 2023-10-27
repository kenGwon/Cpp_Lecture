
// MFC1View.cpp: CMFC1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC1.h"
#endif

#include "MFC1Doc.h"
#include "MFC1View.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1View

IMPLEMENT_DYNCREATE(CMFC1View, CView)

BEGIN_MESSAGE_MAP(CMFC1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDC_BUTTON1, &CMFC1View::OnButton1)
END_MESSAGE_MAP()

// CMFC1View 생성/소멸

CMFC1View::CMFC1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC1View::~CMFC1View()
{
}

BOOL CMFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC1View 그리기

//void CMFC1View::OnDraw(CDC* /*pDC*/) // kenGwon: 원래 이 상태였음
void CMFC1View::OnDraw(CDC* pDC)
{
	CMFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.




	// 폰트를 바꾸자
	CFont cFont, * oldFont;
	//폰트를 만든다.
	cFont.CreateFont(24, 12,//v,h size // 원래 글씨는 16*8으로 줘야 이쁘게 보이는데, 10*10으로 줘서 짜브라진것처럼 보인다.
		0, 0,//angle
		FW_DONTCARE,//bold
		FALSE,//italic // 여기다가 true값을 주면 이탤릭체가 적용된다.
		FALSE,//under line
		FALSE,//STRIKEOUT pulg
		DEFAULT_CHARSET,//CHAR SET
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH, _T("궁서체")); // 이 서체는 윈도우시스템 디렉토리에 폰트 디렉토리에 있는 폰트만 가져올 수 있다.
	//oldFont backup
	oldFont = pDC->SelectObject(&cFont);

	CString test = _T("hello MFC SDI GDI interface test!!"); // 자료형 타입을 C스트링으로 줬다는게 중요
	pDC->TextOut(0, 0, test);

	//// 왜 CString을 써야 하는지에 대한 예제 코드
	//char temp[80];
	//sprintf_s(temp, "안녕하세요 MFC 테스트입니다.");
	////pDC->TextOut(10, 10, temp, strlen(temp)); // 구버전ok, 현재버전X
	//pDC->TextOut(0, 30, (LPCUWSTR)temp, strlen(temp)); // 이렇게 해도 글씨가 깨짐

	test.Format(_T("HORZRES(가로크기)=%d"),
		pDC->GetDeviceCaps(HORZRES));
	pDC->TextOut(0, 20, test);

	test.Format(_T("VERTRES(세로크기)=%d"),
		pDC->GetDeviceCaps(VERTRES));
	pDC->TextOut(0, 40, test);

	// 가운데 정렬
	test = _T("DrawText Example");
	// 가운데 정렬을 적용할 가상의 박스를 선언해놓는다.
	CRect rect = CRect(0, 60, 400, 100);
	pDC->DrawText(test, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);


	test = _T("ExtTextOut Example"); //foreground color is blue
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->SetBkColor(RGB(255, 255, 0)); // background color is yellow
	pDC->ExtTextOut(0, 120, ETO_CLIPPED | ETO_OPAQUE, CRect(0, 120, 400, 200), test, NULL);




}


// CMFC1View 인쇄

BOOL CMFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC1View 진단

#ifdef _DEBUG
void CMFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1Doc* CMFC1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1Doc)));
	return (CMFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1View 메시지 처리기


void CMFC1View::OnButton1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

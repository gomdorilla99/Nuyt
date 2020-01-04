
// NyutView.cpp: CNyutView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Nyut.h"
#endif

#include "NyutDoc.h"
#include "NyutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNyutView

IMPLEMENT_DYNCREATE(CNyutView, CView)

BEGIN_MESSAGE_MAP(CNyutView, CView)
	// 표준 인쇄 명령입니다.
	ON_WM_LBUTTONDOWN(WM_LBUTTONDOWN, &CNyutView::OnLButtonDown)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()




// CNyutView 생성/소멸
CNyutView::CNyutView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	//SetTimer(1, 30, NULL);
	int number;
	mbBitmapPrepare = false;
}
int CNyutView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(0, 25, NULL);  // 타이머 설정
}

CNyutView::~CNyutView()
{
}

void CNyutView::OnTimer(UINT_PTR nIDEven)
{
	Invalidate(false);
	CView::OnTimer( nIDEven);
}

BOOL CNyutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CNyutView 그리기

void CNyutView::OnDraw(CDC* pDC)
{
	CNyutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	if(mbBitmapPrepare == false)
	{ 
		m_Bitmap.CreateCompatibleBitmap(pDC, 2000, 2000);
		mMemDC.CreateCompatibleDC(pDC);
		mMemDC.SelectObject(&m_Bitmap);
		mbBitmapPrepare = true;
	}
	game.Draw(&mMemDC);
	game.DrawMal(&mMemDC);
	pDC->BitBlt(0, 0, 2000, 2000, &mMemDC, 0, 0, SRCCOPY);
	

}


// CNyutView 인쇄

BOOL CNyutView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CNyutView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다. 
}

void CNyutView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CNyutView 진단

#ifdef _DEBUG
void CNyutView::AssertValid() const
{
	CView::AssertValid();
}

void CNyutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNyutDoc* CNyutView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNyutDoc)));
	return (CNyutDoc*)m_pDocument;
}
#endif //_DEBUG


// CNyutView 메시지 처리기

void CNyutView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	game.Run();

	Invalidate(false);


	//AfxMessageBox(Message);

}




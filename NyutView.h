
// NyutView.h: CNyutView 클래스의 인터페이스
//

#pragma once
#include "Session.h"
#include "Player.h"

class Game;

class CNyutView : public CView
{
protected: // serialization에서만 만들어집니다.
	CNyutView() noexcept;
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_DYNCREATE(CNyutView)

// 특성입니다.
public:
	CNyutDoc* GetDocument() const;

// 작업입니다.
public:
	CString DebugMessage;
	CBitmap  m_Bitmap;
	CDC mMemDC; //메모리DC
	bool mbBitmapPrepare;
// 재정의입니다.
public:
	virtual void OnTimer(UINT_PTR nIDEven);
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo); 
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CNyutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
		
	
	Session game;
	


// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // NyutView.cpp의 디버그 버전
inline CNyutDoc* CNyutView::GetDocument() const
   { return reinterpret_cast<CNyutDoc*>(m_pDocument); }
#endif


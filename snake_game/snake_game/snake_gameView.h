
// snake_gameView.h : interface of the Csnake_gameView class
//

#pragma once

#define	 FILED_WIDTH	30
#define	 FILED_HEIGHT	30

class Csnake_gameView : public CView
{
protected: // create from serialization only
	Csnake_gameView();
	DECLARE_DYNCREATE(Csnake_gameView)

// Attributes
public:
	Csnake_gameDoc* GetDocument() const;

// Operations
public:
	CSize size;
	COLORREF fruit_color;
	int Speed;
	CString view_strName;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Csnake_gameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEntername();
	afx_msg void OnGamerule();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnInitialUpdate();
	void MakeSnake(void);
	void SnakeFood(void);
	afx_msg void OnApple();
	afx_msg void OnPlum();
	afx_msg void OnGrape();
	afx_msg void OnUpdateApple(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePlum(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGrape(CCmdUI *pCmdUI);
	afx_msg void Onlevel1();
	afx_msg void Onlevel2();
	afx_msg void Onlevel3();
	afx_msg void Onlevel4();
	afx_msg void Onlevel5();
	afx_msg void OnUpdatelevel1(CCmdUI *pCmdUI);
	afx_msg void OnUpdatelevel2(CCmdUI *pCmdUI);
	afx_msg void OnUpdatelevel3(CCmdUI *pCmdUI);
	afx_msg void OnUpdatelevel4(CCmdUI *pCmdUI);
	afx_msg void OnUpdatelevel5(CCmdUI *pCmdUI);
	int AddScore(int s);
};

#ifndef _DEBUG  // debug version in snake_gameView.cpp
inline Csnake_gameDoc* Csnake_gameView::GetDocument() const
   { return reinterpret_cast<Csnake_gameDoc*>(m_pDocument); }
#endif


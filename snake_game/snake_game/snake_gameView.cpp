
// snake_gameView.cpp : implementation of the Csnake_gameView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "snake_game.h"
#endif

#include "snake_gameDoc.h"
#include "snake_gameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct Snake
{
	int x,y;
	int len;
	int direct;
}Snake[50];

struct Food
{
	int x;
	int y;
	int isfood;
}Food;

static int score = 10;


// Csnake_gameView

IMPLEMENT_DYNCREATE(Csnake_gameView, CView)

BEGIN_MESSAGE_MAP(Csnake_gameView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Csnake_gameView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_COMMAND(ID_EnterName, &Csnake_gameView::OnEntername)
	ON_COMMAND(ID_GameRule, &Csnake_gameView::OnGamerule)
	ON_WM_TIMER()
	ON_COMMAND(ID_Apple, &Csnake_gameView::OnApple)
	ON_COMMAND(ID_Plum, &Csnake_gameView::OnPlum)
	ON_COMMAND(ID_Grape, &Csnake_gameView::OnGrape)
	ON_WM_KEYDOWN()
	ON_UPDATE_COMMAND_UI(ID_Apple, &Csnake_gameView::OnUpdateApple)
	ON_UPDATE_COMMAND_UI(ID_Plum, &Csnake_gameView::OnUpdatePlum)
	ON_UPDATE_COMMAND_UI(ID_Grape, &Csnake_gameView::OnUpdateGrape)
	ON_COMMAND(ID_level1, &Csnake_gameView::Onlevel1)
	ON_COMMAND(ID_level2, &Csnake_gameView::Onlevel2)
	ON_COMMAND(ID_level3, &Csnake_gameView::Onlevel3)
	ON_COMMAND(ID_level4, &Csnake_gameView::Onlevel4)
	ON_COMMAND(ID_level5, &Csnake_gameView::Onlevel5)
	ON_UPDATE_COMMAND_UI(ID_level1, &Csnake_gameView::OnUpdatelevel1)
	ON_UPDATE_COMMAND_UI(ID_level2, &Csnake_gameView::OnUpdatelevel2)
	ON_UPDATE_COMMAND_UI(ID_level3, &Csnake_gameView::OnUpdatelevel3)
	ON_UPDATE_COMMAND_UI(ID_level4, &Csnake_gameView::OnUpdatelevel4)
	ON_UPDATE_COMMAND_UI(ID_level5, &Csnake_gameView::OnUpdatelevel5)
END_MESSAGE_MAP()

// Csnake_gameView construction/destruction

Csnake_gameView::Csnake_gameView()
{
	// TODO: add construction code here
	
	fruit_color = RGB(0, 0, 0);
	Speed = 200;
	
	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=10;
	Snake[2].x=12;
	Snake[2].y=10;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;
}

Csnake_gameView::~Csnake_gameView()
{
}

BOOL Csnake_gameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying


	return CView::PreCreateWindow(cs);
}

// Csnake_gameView drawing

void Csnake_gameView::OnDraw(CDC* pDC)
{
	Csnake_gameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString strMsg;
	strMsg.Format(_T("User Name : %s"), view_strName);
	pDC->TextOutW(20, 20, strMsg);

	pDC->TextOutW(220, 20, _T("Score : "));

	switch(Speed){
		case 200:pDC->TextOutW(560, 20, _T("level 1"));break;
		case 170:pDC->TextOutW(560, 20, _T("level 2"));break;
		case 140:pDC->TextOutW(560, 20, _T("level 3"));break;
		case 120:pDC->TextOutW(560, 20, _T("level 4"));break;
		case 90:pDC->TextOutW(560, 20, _T("level 5"));break;
	}

	int i, j;

	CPen myPen, *pOldPen;
	CBrush myBrush, *pOldBrush;

	myPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	myBrush.CreateSolidBrush(RGB(50, 50, 50));

	pOldPen = pDC->SelectObject(&myPen);
	pOldBrush = pDC->SelectObject(&myBrush);

	for(i = 0; i < FILED_HEIGHT; i++)
		{
			for(j = 0; j < FILED_WIDTH; j++)
			{
				if(i == 0 || i == FILED_HEIGHT - 1  || j == 0 || j == FILED_WIDTH  - 1){
					pDC->Rectangle(j * 20 + 20, i * 20 + 60, j * 20 + 40, i * 20 + 80);
				}
			}
		}
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	myPen.DeleteObject();
	myBrush.DeleteObject();

	// TODO: add draw code for native data here
}


// Csnake_gameView printing


void Csnake_gameView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Csnake_gameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Csnake_gameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Csnake_gameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Csnake_gameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Csnake_gameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Csnake_gameView diagnostics

#ifdef _DEBUG
void Csnake_gameView::AssertValid() const
{
	CView::AssertValid();
}

void Csnake_gameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csnake_gameDoc* Csnake_gameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csnake_gameDoc)));
	return (Csnake_gameDoc*)m_pDocument;
}
#endif //_DEBUG


// Csnake_gameView message handlers
//******************************************************************************************


void Csnake_gameView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	size.cx = cx;
	size.cy = cy;

	// TODO: Add your message handler code here
}

#include "DlgName.h"

void Csnake_gameView::OnEntername()
{
	// TODO: Add your command handler code here
	CDlgName dlg;
	dlg.strName = view_strName;
	if(dlg.DoModal()==IDOK){
		OnInitialUpdate();
		SetTimer(0, Speed, NULL);
	}
	else return;

	view_strName = dlg.strName;

	Invalidate();
}

#include "DlgRule.h"

void Csnake_gameView::OnGamerule()
{
	// TODO: Add your command handler code here
	CDlgRule dlg;
	if(dlg.DoModal()==IDOK){
		OnEntername();
	}
}

void Csnake_gameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	switch(nChar)
	{
		case VK_UP:if(Snake[0].direct!=2)Snake[0].direct=1;break; 
		case VK_DOWN:if(Snake[0].direct!=1)Snake[0].direct=2;break;
		case VK_LEFT:if(Snake[0].direct!=4)Snake[0].direct=3;break;  
		case VK_RIGHT:if(Snake[0].direct!=3)Snake[0].direct=4;break;  
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void Csnake_gameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	MakeSnake();
	SnakeFood();
	AddScore(10);

	if((Snake[0].x*20 < 40)||(Snake[0].y*20 < 80)||((Snake[0].x+1)*20 > 600)||((Snake[0].y+1)*20 > 640))
	{
		KillTimer(0);
		
		CString strMsg;
		strMsg.Format(_T(":: 게임 오버 :: \n  점수 : %d"), score-=10);
		MessageBox(strMsg, _T("Game Over"), MB_OK);
	}	
	
	CView::OnTimer(nIDEvent);
}

void Csnake_gameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=10;
	Snake[2].x=12;
	Snake[2].y=10;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;
	score = 10;

	// TODO: Add your specialized code here and/or call the base class
}


void Csnake_gameView::MakeSnake(void)
{
		CDC *pDC=GetDC();
		
	    pDC->SelectStockObject(WHITE_PEN);
		//Snake[2].x * 20 = 240
		//Snake[2].y * 20 = 200
		//(Snake[2].x + 1) * 20 = 13*20 = 260
		//(Snake[2].y + 1) * 20 = 11*20 = 220
		//Rectangle(240, 200, 260, 220)
		pDC->Rectangle(Snake[Snake[0].len-1].x*20,Snake[Snake[0].len-1].y*20,(Snake[Snake[0].len-1].x+1)*20,(Snake[Snake[0].len-1].y+1)*20);
	    
		//i = 2 1
		//Snake[2].x = Snake[1].x
		//Snake[2].y = Snake[1].y
		//Snake[1].x = Snake[0].x
		//Snake[1].y = Snake[0].y
		for(int i=Snake[0].len-1;i>0;i--)
		{   
			Snake[i].x=Snake[i-1].x;
			Snake[i].y=Snake[i-1].y;
		}
		
		if(Snake[0].direct==1)Snake[0].y--;//↑
		if(Snake[0].direct==2)Snake[0].y++;//↓
		if(Snake[0].direct==3)Snake[0].x--;//←
		if(Snake[0].direct==4)Snake[0].x++;//→

		CBrush DrawBrush=RGB(0,0,0);
		CBrush *pDrawBrush = pDC->SelectObject(&DrawBrush);
		//Snake[0].x * 20 = 200
		//Snake[0].y * 20 = 200
		//Snake[0].x + 1 = 11*20 = 220
		//Snake[0].y + 1 = 11*20 = 220
		//Rectangle(200, 200, 220, 220)
	    pDC->Rectangle(Snake[0].x*20,Snake[0].y*20,(Snake[0].x+1)*20,(Snake[0].y+1)*20);
}


void Csnake_gameView::SnakeFood(void)
{	
		CDC *pDC=GetDC();

		//Snake[0].x * 20 = 200 같음 Food.x * 20
		//and
		//Snake[0].y * 20 = 200 같음 Food.y * 20
		if(Snake[0].x*20==Food.x*20 && Snake[0].y*20==Food.y*20)
		{	
			Snake[0].len++;
			Food.isfood = 1;
		}
		
		if(Food.isfood==1)
		{
		    srand((unsigned)time(NULL));
			do
			{   
				        Food.x = rand() % (FILED_WIDTH - 4) + 2;
					    Food.y = rand() % (FILED_HEIGHT - 4) + 4;
						//isfo = 2 1 0
						/*for(int isfo=Snake[0].len-1;isfo>=0;isfo--)
						{
							if(Food.x*20==Snake[isfo].x*20 && Food.y*20==Snake[isfo].y*20)
							{
								Food.x=rand()% (FILED_WIDTH - 4) + 2;
								Food.y=rand()% (FILED_HEIGHT - 4) + 4;
							}
						}*/
			}
			while(Food.x*20<0 || Food.y*20<0 || Food.x*20>1000 || Food.y*20>1000);
			
			pDC->SelectStockObject(WHITE_PEN);
			
			CBrush DrawBrush = fruit_color;
			CBrush *pDrawBrush = pDC->SelectObject(&DrawBrush);
			pDC->Rectangle(Food.x*20,Food.y*20,(Food.x+1)*20,(Food.y+1)*20);

		    Food.isfood=0;
		}
}

int Csnake_gameView::AddScore(int s)
{
	CDC *pDC=GetDC();

	CString strMsg2;
	strMsg2.Format(_T("%d"), score);
	pDC->TextOutW(300, 20, strMsg2);

	score+=10;
	
	return score;
	
}


//****************************************************************************************************

void Csnake_gameView::OnApple()
{
	// TODO: Add your command handler code here
	fruit_color = RGB(255, 0, 0);
}


void Csnake_gameView::OnPlum()
{
	// TODO: Add your command handler code here
	fruit_color = RGB(255, 0, 255);
}


void Csnake_gameView::OnGrape()
{
	// TODO: Add your command handler code here
	fruit_color = RGB(0, 255, 0);
}

void Csnake_gameView::OnUpdateApple(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(fruit_color == RGB(255, 0, 0));
}


void Csnake_gameView::OnUpdatePlum(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(fruit_color == RGB(255, 0, 255));
}


void Csnake_gameView::OnUpdateGrape(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(fruit_color == RGB(0, 255, 0));
}


void Csnake_gameView::Onlevel1()
{
	// TODO: Add your command handler code here
	Speed = 200;
}


void Csnake_gameView::Onlevel2()
{
	// TODO: Add your command handler code here
	Speed = 170;
}


void Csnake_gameView::Onlevel3()
{
	// TODO: Add your command handler code here
	Speed = 140;
}


void Csnake_gameView::Onlevel4()
{
	// TODO: Add your command handler code here
	Speed = 120;
}


void Csnake_gameView::Onlevel5()
{
	// TODO: Add your command handler code here
	Speed = 90;
}


void Csnake_gameView::OnUpdatelevel1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Speed == 200);
}


void Csnake_gameView::OnUpdatelevel2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Speed == 170);
}


void Csnake_gameView::OnUpdatelevel3(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Speed == 140);
}


void Csnake_gameView::OnUpdatelevel4(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Speed == 120);
}


void Csnake_gameView::OnUpdatelevel5(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Speed == 90);
}


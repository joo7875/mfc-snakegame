// DlgName.cpp : implementation file
//

#include "stdafx.h"
#include "snake_game.h"
#include "DlgName.h"
#include "afxdialogex.h"


// CDlgName dialog

IMPLEMENT_DYNAMIC(CDlgName, CDialogEx)

CDlgName::CDlgName(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgName::IDD, pParent)
	, strName(_T(""))
{

}

CDlgName::~CDlgName()
{
}

void CDlgName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, strName);
}


BEGIN_MESSAGE_MAP(CDlgName, CDialogEx)
	ON_EN_CHANGE(IDC_NAME, &CDlgName::OnEnChangeName)
END_MESSAGE_MAP()


// CDlgName message handlers


void CDlgName::OnEnChangeName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

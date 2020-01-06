#pragma once


// CDlgRule dialog

class CDlgRule : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRule)

public:
	CDlgRule(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRule();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

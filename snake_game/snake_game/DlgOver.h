#pragma once


// DlgOver dialog

class DlgOver : public CDialogEx
{
	DECLARE_DYNAMIC(DlgOver)

public:
	DlgOver(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgOver();

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

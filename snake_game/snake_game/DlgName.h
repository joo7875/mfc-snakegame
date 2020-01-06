#pragma once


// CDlgName dialog

class CDlgName : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgName)

public:
	CDlgName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgName();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString strName;
	afx_msg void OnEnChangeName();
};

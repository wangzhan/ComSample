
// ProcOutTextDlg.h : header file
//

#pragma once
#ifdef DEBUG
#import "..\ProcOut\Debug\ProcOut.tlb" no_namespace
#endif // DEBUG


// CProcOutTextDlg dialog
class CProcOutTextDlg : public CDialogEx
{
// Construction
public:
	CProcOutTextDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PROCOUTTEXT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	long m_lVariable;
	long m_lSum;
	afx_msg void OnBnClickedButtonProduce();
	afx_msg void OnBnClickedButtonConsume();

private:
	IModuPtr  m_IObject;
};

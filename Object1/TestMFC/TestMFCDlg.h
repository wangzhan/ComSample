
// TestMFCDlg.h : header file
//

#pragma once


// CTestMFCDlg dialog
class CTestMFCDlg : public CDialogEx
{
// Construction
public:
	CTestMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTMFC_DIALOG };

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
	long m_lInput1;
	long m_lInput2;
	long m_lOutput;
	CString m_csInput1;
	CString m_csInput2;
	CString m_csOutput;
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnBnClickedButtonRun2();
	afx_msg void OnBnClickedButtonRuncomptr();
	afx_msg void OnBnClickedButtonRuncomptr2();
};

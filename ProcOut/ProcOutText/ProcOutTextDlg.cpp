
// ProcOutTextDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProcOutText.h"
#include "ProcOutTextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProcOutTextDlg dialog



CProcOutTextDlg::CProcOutTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProcOutTextDlg::IDD, pParent)
	, m_lVariable(0)
	, m_lSum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcOutTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_lVariable);
	DDX_Text(pDX, IDC_EDIT2, m_lSum);
}

BEGIN_MESSAGE_MAP(CProcOutTextDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PRODUCE, &CProcOutTextDlg::OnBnClickedButtonProduce)
	ON_BN_CLICKED(IDC_BUTTON_CONSUME, &CProcOutTextDlg::OnBnClickedButtonConsume)
END_MESSAGE_MAP()


// CProcOutTextDlg message handlers

BOOL CProcOutTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	HRESULT hr = m_IObject.CreateInstance(L"ProcOut.Modu");
	if (FAILED(hr))
	{
		MessageBox(L"�����ӿ�ʵ��ʧ��!");
		return FALSE;
	}
	m_IObject->put_CurrentNum(100);//��ʼ������Ϊ100
	m_IObject->get_CurrentNum(&m_lSum);

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProcOutTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProcOutTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProcOutTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProcOutTextDlg::OnBnClickedButtonProduce()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_IObject->Produce(m_lVariable);
	m_IObject->get_CurrentNum(&m_lSum);
	UpdateData(FALSE);
}


void CProcOutTextDlg::OnBnClickedButtonConsume()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_IObject->Customer(m_lVariable);
	m_IObject->get_CurrentNum(&m_lSum);
	UpdateData(FALSE);
}

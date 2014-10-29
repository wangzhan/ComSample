
// TestMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"
#include "afxdialogex.h"
#include "..\Object1\Object1_i.h"
#include "..\Object1\Object1_i.c"

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


// CTestMFCDlg dialog



CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestMFCDlg::IDD, pParent)
	, m_lInput1(0)
	, m_lInput2(0)
	, m_lOutput(0)
	, m_csInput1(_T(""))
	, m_csInput2(_T(""))
	, m_csOutput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_lInput1);
	DDX_Text(pDX, IDC_EDIT2, m_lInput2);
	DDX_Text(pDX, IDC_EDIT3, m_lOutput);
	DDX_Text(pDX, IDC_EDIT4, m_csInput1);
	DDX_Text(pDX, IDC_EDIT5, m_csInput2);
	DDX_Text(pDX, IDC_EDIT6, m_csOutput);
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CTestMFCDlg::OnBnClickedButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_RUN2, &CTestMFCDlg::OnBnClickedButtonRun2)
	ON_BN_CLICKED(IDC_BUTTON_RUNCOMPTR, &CTestMFCDlg::OnBnClickedButtonRuncomptr)
	ON_BN_CLICKED(IDC_BUTTON_RUNCOMPTR2, &CTestMFCDlg::OnBnClickedButtonRuncomptr2)
END_MESSAGE_MAP()


// CTestMFCDlg message handlers

BOOL CTestMFCDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestMFCDlg::OnPaint()
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
HCURSOR CTestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMFCDlg::OnBnClickedButtonRun()
{
	// TODO: Add your control notification handler code here
	::CoInitialize(NULL);
	UpdateData(TRUE);
	IFunc* pFun = NULL;
	IUnknown* pUn = NULL;
	try
	{
		HRESULT hr = ::CoCreateInstance(
			CLSID_Func,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_IUnknown,
			(LPVOID*)&pUn
			);
		if (FAILED(hr))
		{
			MessageBox(L"请您注册组件");
			return;
		}
		hr = pUn->QueryInterface(IID_IFunc, (LPVOID*)&pFun);
		if (FAILED(hr))
		{
			MessageBox(L"检查接口是否存在");
			return;
		}
		pFun->Add(m_lInput1, m_lInput2, &m_lOutput);
		BSTR  bstr1 = m_csInput1.AllocSysString();
		BSTR  bstr2 = m_csInput2.AllocSysString();
		BSTR  bstr3;
		pFun->CatString(bstr1, bstr2, &bstr3);
		m_csOutput = bstr3;
		UpdateData(FALSE);

	}
	catch (LPCTSTR lpErr)
	{
		AfxMessageBox(lpErr);
	}
	pUn->Release();  //释放接口
	pFun->Release();  //释放接口
	::CoUninitialize();
}


void CTestMFCDlg::OnBnClickedButtonRun2()
{
	// TODO: Add your control notification handler code here
	::CoInitialize(NULL);
	UpdateData(TRUE);
	IFunc* pFun = NULL;
	try
	{
		HRESULT hr = ::CoCreateInstance(
			CLSID_Func,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_IFunc,
			(LPVOID*)&pFun
			);
		if (FAILED(hr))
		{
			MessageBox(L"请您注册组件 或 检查接口是否存在");
			return;
		}

		pFun->Add(m_lInput1, m_lInput2, &m_lOutput);
		BSTR  bstr1 = m_csInput1.AllocSysString();
		BSTR  bstr2 = m_csInput2.AllocSysString();
		BSTR  bstr3;
		pFun->CatString(bstr1, bstr2, &bstr3);
		m_csOutput = bstr3;
		UpdateData(FALSE);

	}
	catch (LPCTSTR lpErr)
	{
		AfxMessageBox(lpErr);
	}
	pFun->Release();  //释放接口
	::CoUninitialize();
}


void CTestMFCDlg::OnBnClickedButtonRuncomptr()
{
	// TODO: Add your control notification handler code here
	::CoInitialize(NULL);
	UpdateData(TRUE);
	CComPtr<IUnknown>  spUnk;     //定义IUnknown的智能指针
	CComPtr<IFunc> spFun;      //定义IFun的智能指针
	try
	{
		HRESULT hr = spUnk.CoCreateInstance(CLSID_Func, NULL,
			CLSCTX_INPROC_SERVER);    //启动组件
		if (FAILED(hr))
		{
			MessageBox(L"组件没有注册！");
			return;
		}
		hr = spUnk.QueryInterface(&spFun);  //查找IFun的接口
		if (FAILED(hr))
		{
			MessageBox(L"没有接口IFun");
			return;
		}
		spFun->Add(m_lInput1, m_lInput2, &m_lOutput);
		CComBSTR s1(m_csInput1);
		CComBSTR s2(m_csInput2);
		CComBSTR s3;
		spFun->CatString(s1, s2, &s3);
		m_csOutput = s3.m_str;     //将BSTR转换为CString 同上
	}
	catch (LPCTSTR str)
	{
		MessageBox(str);
	}
	UpdateData(FALSE);
	::CoUninitialize();
}


void CTestMFCDlg::OnBnClickedButtonRuncomptr2()
{
	// TODO: Add your control notification handler code here
	CoInitialize(NULL);
	UpdateData(TRUE);
	CComPtr<IUnknown>  spUnk;     //定义IUnknown的智能指针
	CComQIPtr<IFunc, &IID_IFunc> spFun;      //定义IFun的智能指针
	try
	{
		HRESULT hr = spUnk.CoCreateInstance(CLSID_Func, NULL,
			CLSCTX_INPROC_SERVER);    //启动组件
		if (FAILED(hr))
		{
			MessageBox(L"组件没有注册！");
			return;
		}
		spFun = spUnk;      //会自动调用QueryInterface查找接口
		if (spFun == NULL)
		{
			MessageBox(L"没有接口！");
			return;
		}
		spFun->Add(m_lInput1, m_lInput2, &m_lOutput);
		CComBSTR s1(m_csInput1);
		CComBSTR s2(m_csInput2);
		CComBSTR s3;
		spFun->CatString(s1, s2, &s3);
		m_csOutput = s3.m_str;
	}
	catch (LPCTSTR str)
	{
		MessageBox(str);
	}
	UpdateData(FALSE);
	CoUninitialize();
}

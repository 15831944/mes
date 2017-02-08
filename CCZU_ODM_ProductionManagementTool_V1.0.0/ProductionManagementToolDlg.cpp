// ProductionManagementToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProductionManagementTool.h"
#include "ProductionManagementToolDlg.h"
#include "Splash.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolDlg dialog

CProductionManagementToolDlg::CProductionManagementToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProductionManagementToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProductionManagementToolDlg)
	m_csMachine = _T("");
	m_csDatabase = _T("");
	m_csOrder = _T("");
	m_csProduct = _T("");
	m_csCartonWeigh = _T("");
	m_csCheckIMEIS1 = _T("");
	m_csCheckIMEIS2 = _T("");
	m_csCheckOrder = _T("");
	m_csColorBox = _T("");
	m_csColorBoxWeigh = _T("");
	m_csCreateProduct = _T("");
	m_csPack = _T("");
	m_csPallet = _T("");
	m_csWriteTool = _T("");
	m_csSqlPsw = _T("");
	m_csSqlUser = _T("");
	m_csProductionDataQuery = _T("");
	m_csLoginName = _T("");
	m_csLoginPSW = _T("");
	m_csSNScan = _T("");
	m_csRework = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProductionManagementToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProductionManagementToolDlg)
	DDX_Control(pDX, IDC_EDIT_REWORK, m_ctrRework);
	DDX_Control(pDX, IDC_EDIT_SNSCAN, m_ctrSNScan);
	DDX_Control(pDX, IDC_EDIT_LOGINPSW, m_ctrLoginPSW);
	DDX_Control(pDX, IDC_EDIT_LOGINNAME, m_ctrLoginName);
	DDX_Control(pDX, IDC_EDIT_PRODUCTIONDATAQUERY, m_ctrProductionDataQuery);
	DDX_Control(pDX, IDC_EDIT_SQLUSER, m_ctrSqlUser);
	DDX_Control(pDX, IDC_EDIT_SQLPSW, m_ctrSqlPsw);
	DDX_Control(pDX, IDC_EDIT_WRITETOOL, m_ctrWriteTool);
	DDX_Control(pDX, IDC_EDIT_PALLET, m_ctrPallet);
	DDX_Control(pDX, IDC_EDIT_PACK, m_ctrPack);
	DDX_Control(pDX, IDC_EDIT_CREATEPRODUCT, m_ctrCreateProduct);
	DDX_Control(pDX, IDC_EDIT_COLORBOXWEIGH, m_ctrColorBoxWeigh);
	DDX_Control(pDX, IDC_EDIT_COLORBOX, m_ctrColorBox);
	DDX_Control(pDX, IDC_EDIT_CHECKORDER, m_ctrCheckOrder);
	DDX_Control(pDX, IDC_EDIT_CHECKIMEIS2, m_ctrCheckIMEIS2);
	DDX_Control(pDX, IDC_EDIT_CHECKIMEIS1, m_ctrCheckIMEIS1);
	DDX_Control(pDX, IDC_EDIT_CARTONWEIGH, m_ctrCartonWeigh);
	DDX_Control(pDX, IDC_EDIT_PRODUCT, m_ctrProduct);
	DDX_Control(pDX, IDC_EDIT_ORDER, m_ctrOrder);
	DDX_Control(pDX, IDC_EDIT_DATABASE, m_ctrDatabase);
	DDX_Control(pDX, IDC_EDIT_MACHINE, m_ctrMachine);
	DDX_Text(pDX, IDC_EDIT_MACHINE, m_csMachine);
	DDX_Text(pDX, IDC_EDIT_DATABASE, m_csDatabase);
	DDX_Text(pDX, IDC_EDIT_ORDER, m_csOrder);
	DDX_Text(pDX, IDC_EDIT_PRODUCT, m_csProduct);
	DDX_Text(pDX, IDC_EDIT_CARTONWEIGH, m_csCartonWeigh);
	DDX_Text(pDX, IDC_EDIT_CHECKIMEIS1, m_csCheckIMEIS1);
	DDX_Text(pDX, IDC_EDIT_CHECKIMEIS2, m_csCheckIMEIS2);
	DDX_Text(pDX, IDC_EDIT_CHECKORDER, m_csCheckOrder);
	DDX_Text(pDX, IDC_EDIT_COLORBOX, m_csColorBox);
	DDX_Text(pDX, IDC_EDIT_COLORBOXWEIGH, m_csColorBoxWeigh);
	DDX_Text(pDX, IDC_EDIT_CREATEPRODUCT, m_csCreateProduct);
	DDX_Text(pDX, IDC_EDIT_PACK, m_csPack);
	DDX_Text(pDX, IDC_EDIT_PALLET, m_csPallet);
	DDX_Text(pDX, IDC_EDIT_WRITETOOL, m_csWriteTool);
	DDX_Text(pDX, IDC_EDIT_SQLPSW, m_csSqlPsw);
	DDX_Text(pDX, IDC_EDIT_SQLUSER, m_csSqlUser);
	DDX_Text(pDX, IDC_EDIT_PRODUCTIONDATAQUERY, m_csProductionDataQuery);
	DDX_Text(pDX, IDC_EDIT_LOGINNAME, m_csLoginName);
	DDX_Text(pDX, IDC_EDIT_LOGINPSW, m_csLoginPSW);
	DDX_Text(pDX, IDC_EDIT_SNSCAN, m_csSNScan);
	DDX_Text(pDX, IDC_EDIT_REWORK, m_csRework);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProductionManagementToolDlg, CDialog)
	//{{AFX_MSG_MAP(CProductionManagementToolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATE_ORDER, OnCreateOrder)
	ON_BN_CLICKED(IDC_ADDUSER, OnAdduser)
	ON_BN_CLICKED(IDC_DELETEUSER, OnDeleteuser)
	ON_BN_CLICKED(IDC_CHANGEPASSWORD, OnChangepassword)
	ON_BN_CLICKED(IDC_TOOLVERSION, OnToolversion)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SQL, OnSql)
	ON_BN_CLICKED(IDC_CHANGESQLPASSWORD, OnChangesqlpassword)
	ON_BN_CLICKED(IDC_CONNECTSQL, OnConnectsql)
	ON_BN_CLICKED(IDC_ALTERSETTING, OnAltersetting)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProductionManagementToolDlg message handlers

BOOL CProductionManagementToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	SCROLLINFO vinfo1,vinfo2;

	//��ֱ������
	vinfo1.cbSize=sizeof(vinfo1);
	vinfo1.fMask=SIF_ALL;
	vinfo1.nPage=50;//����������ĳ��̣�ͨ�������¹�ϵ���䳤��/���������ȣ���������ͷ��=nPage/(nMax+2)��  
	//����nPageȡֵ-1ʱ���������᲻���ˡ�  
	vinfo1.nMax=150;//���������ܹ��������ֵ  
	vinfo1.nMin=0;//���������ܹ�������Сֵ
	vinfo1.nPos = 0;
	SetScrollInfo(SB_VERT,&vinfo1);//��ʹ��������һ������ʹ�ô������Ҳ������ʾ������
/*
	//ˮƽ������
	vinfo2.cbSize=sizeof(vinfo2);
	vinfo2.fMask=SIF_ALL;
	vinfo2.nPage=1000;//����������ĳ��̣�ͨ�������¹�ϵ���䳤��/���������ȣ���������ͷ��=nPage/(nMax+2)��  
	//����nPageȡֵ-1ʱ���������᲻���ˡ�  
	vinfo2.nMax=1500;//���������ܹ��������ֵ  
	vinfo2.nMin=0;//���������ܹ�������Сֵ
	vinfo2.nPos = 0;
	SetScrollInfo(SB_HORZ,&vinfo2);//��ʹ��������һ������ʹ�ô������Ҳ������ʾ������
*/

	//��ȡconfig.ini
	m_Config.InitConfigPath();
	m_Config.ReadConfig();

	this->m_csMachine = this->m_Config.m_csServer;
	this->m_csDatabase = this->m_Config.m_csDatabaseName;
	this->m_csSqlUser = this->m_Config.m_csUserName;
	this->m_csSqlPsw = this->m_Config.m_csPassword;
	this->m_csLoginName = this->m_Config.m_csLoginName;
	this->m_csLoginPSW = this->m_Config.m_csLoginPSW;


	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProductionManagementToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProductionManagementToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProductionManagementToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}




void CProductionManagementToolDlg::OnCreateOrder()
{
	UpdateData();
	
	//�����Ŀ���ơ������Ų���Ϊ��
	if(this->m_csProduct.IsEmpty() || this->m_csOrder.IsEmpty())
	{
		MessageBox("��Ŀ���ƻ򶩵��Ų���Ϊ��!","Error",MB_OK);
		return;
	}

	//��������Ƿ�ΪA-Z��a-z��0-9��_
	if(!CheckProductName(0) || !CheckOrderName(0))
	{
		MessageBox("�Ƿ���Ŀ���ƻ򶩵����ƣ�����ֻ�ܰ���\'A-Z\'�� \'a-z\'��\'0-9\' ��\'_\'!","Error",MB_OK);
		return;
	}

	//���SQL productList ���Ƿ����ظ���Ʒ
	if(!CheckSQLRepeat(0))
	{
		MessageBox("������ݿ����Ƿ����ظ���Ŀ����ʧ��!","Error",MB_OK);
		return;
	}

	//¼����Ŀ����
	if(!InputProductOrder(0))
	{
		MessageBox("¼����Ŀ����ʧ��!","Error",MB_OK);
		return;
	}
	else
	{
		MessageBox("¼����Ŀ�����ɹ�!","OK",MB_OK);
	}
}


void CProductionManagementToolDlg::OnAltersetting() 
{
	UpdateData();

	CAlterSetting dlg;
	dlg.m_bCheckPCBA = 0;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


void CProductionManagementToolDlg::OnToolversion()
{
	UpdateData();

	//��⹤�߰汾����Ϊ��
	if(this->m_csCreateProduct.IsEmpty() || this->m_csWriteTool.IsEmpty() || this->m_csCheckIMEIS1.IsEmpty() \
		|| this->m_csColorBox.IsEmpty() || this->m_csCheckIMEIS2.IsEmpty() || this->m_csColorBoxWeigh.IsEmpty() \
		|| this->m_csPack.IsEmpty() || this->m_csCartonWeigh.IsEmpty() || this->m_csPallet.IsEmpty() || this->m_csRework.IsEmpty()\
		|| this->m_csCheckOrder.IsEmpty() || this->m_csProductionDataQuery.IsEmpty() || m_csSNScan.IsEmpty())
	{
		MessageBox("���߰汾����Ϊ��!","Error",MB_OK);
		return;
	}

	//¼��MES���߰汾
	if(!InputToolVersion())
	{
		MessageBox("¼��MES���߰汾ʧ��!","Error",MB_OK);
		return;
	}
	else
	{
		MessageBox("¼��MES���߰汾�ɹ�!","OK",MB_OK);
	}
}


void CProductionManagementToolDlg::OnAdduser() 
{
	CAddUserDlg dlg;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


void CProductionManagementToolDlg::OnDeleteuser() 
{
	CDeleteUserDlg dlg;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


void CProductionManagementToolDlg::OnChangepassword() 
{
	CChangePasswordDlg dlg;
	if(dlg.DoModal()!=IDOK)
	{
		return;
	}
}


BOOL CProductionManagementToolDlg::CheckProductName(int iflag) 
{
	char   ch;
	BOOL   bHz=FALSE;
	CString csProduct;

	csProduct = m_csProduct;
	
	for(int i=0;i<csProduct.GetLength();i++)   
	{   
		ch=csProduct.GetAt(i);   
		if(ch>=48 && ch<=57)
		{    
			continue;   
		}
		else
		{
			if(ch>=65 && ch<=90)
			{
				continue;
			}
			else
			{
				if(ch>=97 && ch<=122)
				{
					continue;
				}
				else
				{
					if(ch=='_')
					{
						continue;
					}
					else
					{
						bHz=TRUE;
						break;
					}
				}
			}
		}
	}
	
	if(!bHz)   
		return TRUE;
	else   
		return FALSE;
}


BOOL CProductionManagementToolDlg::CheckOrderName(int iflag) 
{
	char   ch;   
	BOOL   bHz=FALSE;   
	CString csOrder;

	csOrder = m_csOrder;

	for(int i=0;i<csOrder.GetLength();i++)   
	{   
		ch=csOrder.GetAt(i);   
		if(ch>=48 && ch<=57)    
		{    
			continue;
		}
		else
		{
			if(ch>=65 && ch<=90)
			{
				continue;
			}
			else
			{
				if(ch>=97 && ch<=122)
				{
					continue;
				}
				else
				{
					if(ch=='_')
					{
						continue;
					}
					else
					{
						bHz=TRUE;
						break;
					}
				}
			}
		}
	}
	
	if(!bHz)   
		return TRUE;
	else
		return FALSE;
}


BOOL CProductionManagementToolDlg::CheckSQLRepeat(int iflag)
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("select * from ProductList where OrderName='%s'",m_csOrder);

	//�����Ŀ�����Ƿ���ProductList���ظ�
	try
	{	
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		
		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			return FALSE;
		}
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}


BOOL CProductionManagementToolDlg::InputProductOrder(int iflag)
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("INSERT INTO ProductList (ProductName, OrderName, Enable) VALUES ('%s','%s',%d)",m_csProduct,m_csOrder,2);

	try
	{
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}


BOOL CProductionManagementToolDlg::GetToolVersion()
{
	CString temp;
	_variant_t var;
	CString sql;

	try
	{
		sql.Format("select * from ToolVersionList where Enable=1");
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	
		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CreateProductTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCreateProduct= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("SNScanTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csSNScan= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("WriteIMEITool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csWriteTool= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CheckIMEIS1Tool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCheckIMEIS1= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csColorBox= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CheckIMEIS2Tool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCheckIMEIS2= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeighTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csColorBoxWeigh= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csPack= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CartonBoxWeighTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCartonWeigh= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("PalletTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csPallet= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("CheckOrderTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csCheckOrder= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ProductionDataQueryTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csProductionDataQuery= temp;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("ReworkTool");
			temp=(LPCTSTR)(_bstr_t)var;
			this->m_csRework= temp;
		}
		
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		CString sErr = "��ToolVersionList���ȡ�汾��Ϣʧ�ܣ�ԭ��:" + (CString)((LPCTSTR)e.Description());
		MessageBox(sErr, "����");
		return FALSE;
	}

	return TRUE;
}


BOOL CProductionManagementToolDlg::InputToolVersion()
{
	CString temp;
	_variant_t var;
	CString sql;

	sql.Format("UPDATE ToolVersionList SET CreateProductTool='%s', SNScanTool='%s', WriteIMEITool='%s', \
		CheckIMEIS1Tool='%s', ColorBoxTool='%s', CheckIMEIS2Tool='%s', ColorBoxWeighTool='%s', \
		CartonBoxTool='%s', CartonBoxWeighTool='%s', PalletTool='%s', CheckOrderTool='%s', \
		ProductionDataQueryTool='%s',ReworkTool='%s' \
		WHERE Enable=1",m_csCreateProduct,m_csSNScan,m_csWriteTool,m_csCheckIMEIS1,m_csColorBox,m_csCheckIMEIS2,\
		m_csColorBoxWeigh,m_csPack,m_csCartonWeigh,m_csPallet,m_csCheckOrder,m_csProductionDataQuery,m_csRework);
 
	try
	{
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}

int CProductionManagementToolDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	CSplashWnd::ShowSplashScreen(this);

	return 0;
}

void CProductionManagementToolDlg::OnSql() 
{
	UpdateData();
	this->m_Config.m_csServer         = this->m_csMachine;
	this->m_Config.m_csDatabaseName   = this->m_csDatabase;
	this->m_Config.m_csUserName       = this->m_csSqlUser;
	this->m_Config.m_csPassword       = this->m_csSqlPsw;
	this->m_Config.m_csLoginName      = this->m_csLoginName;
	this->m_Config.m_csLoginPSW       = this->m_csLoginPSW;
	this->m_Config.SaveConfig();
		
	MessageBox("�޸�Config�����ݿ���Ϣ�ɹ�!",MB_OK);
}


BOOL CProductionManagementToolDlg::ConnectMDBDatabase()
{
	CString temp;
	_variant_t var;
	CString sql;
	sql.Format("driver={SQL Server};Server=%s;DATABASE=%s;UID=%s;PWD=%s",this->m_Config.m_csServer,this->m_Config.m_csDatabaseName,this->m_Config.m_csUserName,this->m_Config.m_csPassword);
	
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->ConnectionTimeout=15;
		((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Open((char*)(LPCTSTR)sql,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	return TRUE;
}

void CProductionManagementToolDlg::OnChangesqlpassword()
{
	CString temp;
	_variant_t var;
	CString sql;

	UpdateData();

	sql.Format("EXEC sp_password '%s','%s'",this->m_Config.m_csPassword,this->m_csSqlPsw);
	
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst = ((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		MessageBox("�������ݿ�����ɹ�!",MB_OK);
	}
	catch(_com_error e)
	{
		MessageBox("�������ݿ�����ʧ��!","Error",MB_OK);
		return;
	}
}

void CProductionManagementToolDlg::OnConnectsql()
{

	CPassword dlg;
	dlg.ilevel = 1;   //�賬��Ȩ����֤

	//��ʼ��AOD
	if(!((CProductionManagementToolApp *)AfxGetApp())->InitADO())
	{
		MessageBox("��ʼ��ADOʧ��","Error",MB_OK);
		return;
	}
	        
	//�������ݿ�
	if(!ConnectMDBDatabase())
	{
		MessageBox("�������ݿ�ʧ��","Error",MB_OK);
		return;
	}

	if(dlg.DoModal()!=IDOK)
	{
		((CProductionManagementToolApp *)AfxGetApp())->UninitADO();
		return;
	}
	
	if(!GetToolVersion())
	{
		MessageBox("��ȡMES���߰汾ʧ��","Error",MB_OK);
		exit(0);
	}

	UpdateData(FALSE);
}


void CProductionManagementToolDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	SCROLLINFO vinfo;
	GetScrollInfo(SB_HORZ,&vinfo,SIF_ALL);
	
	switch (nSBCode)  
	{  
	case SB_THUMBTRACK://�϶�������  
		ScrollWindow(-(nPos-vinfo.nPos),0);
		SetScrollPos(SB_HORZ,nPos);  
		break;  
	case SB_LINELEFT://�������ͷ
		if(vinfo.nPos!=0)
		{
			ScrollWindow(1,0);
			SetScrollPos(SB_HORZ,vinfo.nPos-1);
		}
		break;  
	case SB_LINERIGHT: //�����Ҽ�ͷ 
		if(vinfo.nPos+vinfo.nPage<=vinfo.nMax)
		{
			SetScrollPos(SB_HORZ,vinfo.nPos+1);
			ScrollWindow(-1,0);
		}
		break;  
	case SB_PAGELEFT:  //�ڹ������󷽿հ׹������򵥻� 
		if (vinfo.nPos>=vinfo.nPage)
		{
			ScrollWindow(vinfo.nPage,0);
			SetScrollPos(SB_HORZ,vinfo.nPos-vinfo.nPage);
		}  
		else
		{
			ScrollWindow(vinfo.nPos,0);
			SetScrollPos(SB_HORZ,vinfo.nPos-vinfo.nPage);
		}
		break;  
	case SB_PAGERIGHT: //�ڹ������ҷ��հ׹������򵥻� 
		if (vinfo.nPos+vinfo.nPage<=vinfo.nMax-vinfo.nPage)  
		{  
			ScrollWindow(-vinfo.nPage,0);
			SetScrollPos(SB_HORZ,vinfo.nPos+vinfo.nPage);
		}  
		else
		{
			ScrollWindow(-(vinfo.nMax-(vinfo.nPos+vinfo.nPage)),0);
			SetScrollPos(SB_HORZ,vinfo.nMax-vinfo.nPage);
		}  
		break;
	}
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CProductionManagementToolDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	SCROLLINFO scrollinfo;  
	GetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
	
	switch (nSBCode)
	{  
	case SB_BOTTOM: //�����������ײ�  
		ScrollWindow(0,(scrollinfo.nPos-scrollinfo.nMax)*10); //������Ļ  
		scrollinfo.nPos = scrollinfo.nMax; //�趨������λ��  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL); //���»���λ��  
		break;  
	case SB_TOP: //������������
		ScrollWindow(0,(scrollinfo.nPos-scrollinfo.nMin)*10);  
		scrollinfo.nPos = scrollinfo.nMin;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		break;  
	case SB_LINEUP: //�����ϼ�ͷ  
		scrollinfo.nPos -= 1;  
		if (scrollinfo.nPos<scrollinfo.nMin)  
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,10);  
		break;  
	case SB_LINEDOWN: //�����¼�ͷ  
		scrollinfo.nPos += 1;  
		if (scrollinfo.nPos>scrollinfo.nMax)  
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		ScrollWindow(0,-10);  
		break;  
	case SB_PAGEUP: //���������Ϸ��հ�����  
		scrollinfo.nPos -= 5;  
		if (scrollinfo.nPos<scrollinfo.nMin)  
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		ScrollWindow(0,10*5);
		break;
	case SB_PAGEDOWN: //���������·��հ�����  
		scrollinfo.nPos += 5;  
		if (scrollinfo.nPos>scrollinfo.nMax)  
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,-10*5);  
		break;  
	case SB_ENDSCROLL: //����뿪���飬���������϶�  
		// MessageBox("SB_ENDSCROLL");  
		break;  
	case SB_THUMBPOSITION:  
		// ScrollWindow(0,(scrollinfo.nPos-nPos)*10);  
		// scrollinfo.nPos = nPos;  
		// SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		break;  
	case SB_THUMBTRACK: //�϶�����  
		ScrollWindow(0,(scrollinfo.nPos-nPos)*10);  
		scrollinfo.nPos = nPos;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		break;  
	}

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

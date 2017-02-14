// Password.cpp : implementation file
//

#include "stdafx.h"
#include "FullWrite.h"
#include "Password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassword dialog


CPassword::CPassword(CWnd* pParent /*=NULL*/)
	: CDialog(CPassword::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPassword)
	m_csPassword = _T("");
	m_csUserName = _T("");
	//}}AFX_DATA_INIT
}


void CPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassword)
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_ctrPassword);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csPassword);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_csUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassword, CDialog)
	//{{AFX_MSG_MAP(CPassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassword message handlers

void CPassword::OnOK() 
{
	UpdateData();

	CString temp,states;
	_variant_t var;
	CString sql;
	int ileveltemp,iTooltemp1,iTooltemp2;

	sql.Format("select * from PermissionControl where UserName='%s' and Password='%s'",this->m_csUserName,this->m_csPassword);
	try
	{
		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
		((CFullWriteApp *)AfxGetApp())->m_pRst=((CFullWriteApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

		if(!((CFullWriteApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//���ݿ����м�¼
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("PermissionLevel");
			ileveltemp=var.intVal;

			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("WriteIMEITool");
			iTooltemp1=var.intVal;
			
			var = ((CFullWriteApp *)AfxGetApp())->m_pRst->GetCollect("AllTool");
			iTooltemp2=var.intVal;
		}
		else
		{
			//���ݿ����޼�¼
			MessageBox("User Or Password Error,Please Input Again!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}

		if(((CFullWriteApp *)AfxGetApp())->m_pRst->State)
			((CFullWriteApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		this->m_csUserName.Empty();
		this->m_csPassword.Empty();
		UpdateData(FALSE);
		this->m_ctrUserName.SetFocus();
		return;
	}

	//ilevel:����Ȩ�� 0����ͨȨ�ޣ�1������Ȩ��
	//ileveltemp:�û�ʵ��Ȩ�� 0����ͨȨ�ޣ�1������Ȩ��
	if (ilevel == 0)
	{
		if (ileveltemp != 0 && ileveltemp != 1)
		{
			MessageBox("Sorry��Your Password Error!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}
	}
	else if (ilevel == 1)
	{
		if (ileveltemp != 1)
		{
			MessageBox("Sorry��Your Password Error!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}
	}

	//����Ȩ�ޣ���������ҪдIMEI�Ź���Ȩ�� �� ���й���Ȩ��
	if (iTooltemp1 != 1 && iTooltemp2 != 1)
	{
		MessageBox("Sorry��Your Password Error!","Error",MB_ICONERROR);
		this->m_csUserName.Empty();
		this->m_csPassword.Empty();
		UpdateData(FALSE);
		this->m_ctrUserName.SetFocus();
		return;
	}
	
	CDialog::OnOK();
}

BOOL CPassword::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrUserName.SetFocus();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

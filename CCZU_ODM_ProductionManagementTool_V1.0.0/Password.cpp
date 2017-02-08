// Password.cpp : implementation file
//

#include "stdafx.h"
#include "productionmanagementtool.h"
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
	m_csUserName = _T("");
	m_csPassword = _T("");
	//}}AFX_DATA_INIT
}


void CPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassword)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_ctrPassword);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_csUserName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csPassword);
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
	int ileveltemp,iTooltemp;

	sql.Format("select * from PermissionControl where UserName='%s' and Password='%s'",this->m_csUserName,this->m_csPassword);
	try
	{
		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
		((CProductionManagementToolApp *)AfxGetApp())->m_pRst=((CProductionManagementToolApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);

		if(!((CProductionManagementToolApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			//���ݿ����м�¼
			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("PermissionLevel");
			ileveltemp=var.intVal;

			var = ((CProductionManagementToolApp *)AfxGetApp())->m_pRst->GetCollect("AllTool");
			iTooltemp=var.intVal;
		}
		else
		{
			//���ݿ����޼�¼
			MessageBox("�û����������������������!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}

		if(((CProductionManagementToolApp *)AfxGetApp())->m_pRst->State)
			((CProductionManagementToolApp *)AfxGetApp())->m_pRst->Close();
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
			MessageBox("�Բ�������Ȩ�޵ȼ�����!","Error",MB_ICONERROR);
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
			MessageBox("�Բ�������Ȩ�޲���!","Error",MB_ICONERROR);
			this->m_csUserName.Empty();
			this->m_csPassword.Empty();
			UpdateData(FALSE);
			this->m_ctrUserName.SetFocus();
			return;
		}
	}

	//����Ȩ�ޣ���������ҪȨ��Ϊ15--���й���Ȩ��
	if (iTooltemp != 1)
	{
		MessageBox("�Բ�����û�иù��ߵ�Ȩ��!","Error",MB_ICONERROR);
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
	
	// TODO: Add extra initialization here
	m_ctrUserName.SetFocus();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

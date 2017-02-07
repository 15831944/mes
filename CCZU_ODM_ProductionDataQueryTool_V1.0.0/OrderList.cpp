// OrderList.cpp : implementation file
//

#include "stdafx.h"
#include "PACK.h"
#include "OrderList.h"
#include "Query.h"
#include "excel.h"
#include "OrderQuery.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OrderList dialog


OrderList::OrderList(CWnd* pParent /*=NULL*/)
	: CDialog(OrderList::IDD, pParent)
{
	//{{AFX_DATA_INIT(OrderList)
	m_iComboxType = -1;
	m_iCustomer = -1;
	//}}AFX_DATA_INIT
}


void OrderList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(OrderList)
	DDX_Control(pDX, IDC_COMBO_CUSTOMER, m_ctrCustomer);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_ctrComboxType);
	DDX_Control(pDX, IDC_BTN_PRINT, m_ctrPrint);
	DDX_Control(pDX, IDC_BTN_UNUSEDIMEI, m_ctrUnusedIMEI);
	DDX_Control(pDX, IDC_BTN_IMEIQUERY, m_ctrIMEIQuery);
	DDX_Control(pDX, IDC_QUERYFLEX, m_OrderFlex);
	DDX_CBIndex(pDX, IDC_COMBO_TYPE, m_iComboxType);
	DDX_CBIndex(pDX, IDC_COMBO_CUSTOMER, m_iCustomer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(OrderList, CDialog)
	//{{AFX_MSG_MAP(OrderList)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_UNUSEDIMEI, OnBtnUnusedimei)
	ON_BN_CLICKED(IDC_BTN_IMEIQUERY, OnBtnImeiquery)
	ON_BN_CLICKED(IDC_BTN_PRINT, OnBtnPrint)
	ON_CBN_CLOSEUP(IDC_COMBO_TYPE, OnCloseupComboType)
	ON_BN_CLICKED(IDC_BTN_CARTON, OnBtnCarton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OrderList message handlers

void OrderList::SetRowCol(int rows,int cols)
{
	m_OrderFlex.SetRows(rows);
	m_OrderFlex.SetCols(cols); 
  
	m_OrderFlex.SetColWidth(0,900);
	m_OrderFlex.SetColWidth(1,950);
	m_OrderFlex.SetColWidth(2,1800);
	for (int i=3;i<cols;i++)
	{
		m_OrderFlex.SetColWidth(i,950); 
	}
	
	for (int j=0;j<rows;j++)
	{
		m_OrderFlex.SetRowHeight(j,480);
	}
}


void OrderList::SetNumText(int rows,int cols)
{
	//����FLEX����
	for(int row=0;row<rows;row++)
	{
		for (int col=0;col<cols;col++)
		{
			m_OrderFlex.SetRow(row);
			m_OrderFlex.SetCol(col);
			m_OrderFlex.SetCellAlignment(1);
		}
	}
	
	m_OrderFlex.SetTextMatrix(0,0,"����");
	m_OrderFlex.SetTextMatrix(0,1,"�ͻ�");
	m_OrderFlex.SetTextMatrix(0,2,"����");
	m_OrderFlex.SetTextMatrix(0,3,"��ɫ");
	m_OrderFlex.SetTextMatrix(0,4,"��������");
	m_OrderFlex.SetTextMatrix(0,5,"�ۼ�Ͷ��");
	m_OrderFlex.SetTextMatrix(0,6,"��Ʒ�������");
	m_OrderFlex.SetTextMatrix(0,7,"�ѳ�������");
	m_OrderFlex.SetTextMatrix(0,8,"δ��������");
	m_OrderFlex.SetTextMatrix(0,9,"δ������Ʒ");
	m_OrderFlex.SetTextMatrix(0,10,"����Ͷ��");
	m_OrderFlex.SetTextMatrix(0,11,"������װ");
	m_OrderFlex.SetTextMatrix(0,12,"���հ�װ");
	m_OrderFlex.SetTextMatrix(0,13,"��װUPH");

}

BOOL OrderList::OnInitDialog() 
{
	CDialog::OnInitDialog();

//	CMainFrame *pFrame=(CMainFrame*)GetParentFrame();

	int iloop;
	CString temp;

	csaType.RemoveAll();
	csaCustomer.RemoveAll();
	csaOrder.RemoveAll();
	csaColor.RemoveAll();
	csaTotal.RemoveAll();
	csaPut.RemoveAll();
	csaDone.RemoveAll();
	csaShipping.RemoveAll();
	csaNShipping.RemoveAll();
	csaNSDone.RemoveAll();
	csaTPut.RemoveAll();
	csaTComplete.RemoveAll();
	csaTPackage.RemoveAll();
	csaUPH.RemoveAll();

	//��ȡ����
	if(!this->GetOrderInfo())
	{
		MessageBox("��ȡ��������ʧ��!","Error",MB_ICONERROR);
		exit(0);
	}

	m_irow = csaType.GetSize()+1;
	m_icol = 14;
	SetRowCol(m_irow,m_icol);
	SetNumText(m_irow,m_icol);
	for (iloop=1; iloop<m_irow; iloop++)
	{
		m_OrderFlex.SetTextMatrix(iloop,0,csaType[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,1,csaCustomer[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,2,csaOrder[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,3,csaColor[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,4,csaTotal[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,5,csaPut[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,6,csaDone[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,7,csaShipping[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,8,csaNShipping[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,9,csaNSDone[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,10,csaTPut[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,11,csaTComplete[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,12,csaTPackage[iloop-1]);
		m_OrderFlex.SetTextMatrix(iloop,13,csaUPH[iloop-1]);
	}

	UpdateData(FALSE);

	this->SetTimer(1,60000,NULL);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CString OrderList::VariantToCString(VARIANT   var)   
{   
	CString strValue;   
	_variant_t var_t;   
	_bstr_t bst_t;   
	//time_t cur_time;   
	CTime time_value;   
	COleCurrency var_currency; 
	COleDateTime cur_time;
    
	switch(var.vt)   
	{   
	case   VT_EMPTY:   
		strValue   =   _T("");   
		break;   
	case   VT_UI1:   
		strValue.Format("%d",var.bVal);   
		break;   
	case   VT_I2:   
		strValue.Format("%d",var.iVal);   
		break;   
	case   VT_I4:   
		strValue.Format("%d",var.lVal);   
		break;   
	case   VT_R4:   
		strValue.Format("%f",var.fltVal);   
		break;   
	case   VT_R8:   
		strValue.Format("%f",var.dblVal);   
		break;   
	case   VT_CY:   
		var_currency   =   var;   
		strValue   =   var_currency.Format(0);   
		break;   
	case   VT_BSTR:   
		var_t   =   var;   
		bst_t   =   var_t;   
		strValue.Format   ("%s",(const   char*)bst_t);   
		break;   
	case   VT_NULL:   
		strValue   =   _T("");   
		break;   
	case   VT_DATE:   
		//cur_time   =   (long)var.date;   
		// time_value   =   cur_time;   
		// strValue   =   time_value.Format("%Y-%m-%d");  
		cur_time   =   var; 
		strValue   =   cur_time.Format("%Y-%m-%d"); 
		break;   
	case   VT_BOOL:   
		strValue.Format("%d",var.boolVal   );   
		break;   
	default:     
		strValue   =   _T("");   
		break;   
	}   
	
	return   strValue;   
}

BOOL OrderList::GetOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	CStringArray csaCartonNum;
	CStringArray csaPalletNum;
	int count;

	int m_iEnable;
	if(m_iOrderType==0)
	{
		m_iEnable = 1;
	}
	else if(m_iOrderType==1)
	{
		m_iEnable = 0;
	}
	else
	{
		m_iEnable = 3; 
	}

	SYSTEMTIME st;
	GetLocalTime(&st);

	//��ȡIMEI��������
	sql.Format("select * from ProductList WHERE Enable=%d",m_iEnable);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductName");
			temp=VariantToCString(var);
			csaType.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CustomerNo");
			temp=VariantToCString(var);
			csaCustomer.Add(temp);
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("OrderName");
			temp=VariantToCString(var);
			csaOrder.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			csaColor.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PlannedOutput");
			temp=VariantToCString(var);
			csaTotal.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonMaxCount");
			temp=VariantToCString(var);
			csaCartonNum.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletMaxCount");
			temp=VariantToCString(var);
			csaPalletNum.Add(temp);
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	
	for (int i=0;i<csaType.GetSize();i++)
	{
		//�������ݿ�������SNTemp����ȡ�ۼ����Ͷ����
		sql.Format("select count(*) as COUNT from %s_%s_SNTemp",csaType[i],csaOrder[i]);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				temp=VariantToCString(var);
				csaPut.Add(temp);
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
 
		//�������ݿ�������SNTemp����ȡ�������Ͷ����
		sql.Format("select count(*) as COUNT from %s_%s_SNTemp where datetime>'%4d-%2d-%2d'",csaType[i],csaOrder[i],st.wYear,st.wMonth,st.wDay);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				temp=VariantToCString(var);
				csaTPut.Add(temp);
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		//�������ݿ�������CartonBox����ȡ��Ʒ�������
		sql.Format("select count(*) as COUNT from %s_%s_CartonBox where Status=2 or Status=3",csaType[i],csaOrder[i]);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				count = var.intVal * _ttoi(csaCartonNum[i]);
				temp.Format("%d",count);
				csaDone.Add(temp);
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		//�������ݿ�������Pallet����ȡ�ѳ��� δ��������
		sql.Format("select count(*) as COUNT from %s_%s_Pallet where Status=3",csaType[i],csaOrder[i]);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				count = var.intVal * _ttoi(csaCartonNum[i]) * _ttoi(csaPalletNum[i]);
				temp.Format("%d",count);
				csaShipping.Add(temp);	//�ѳ���

				temp.Format("%d",_ttoi(csaTotal[i])-count);
				csaNShipping.Add(temp);	//δ��������

				temp.Format("%d",_ttoi(csaDone[i])-count);
				csaNSDone.Add(temp);	//δ������Ʒ��
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		//�������ݿ�������ColorBox����ȡ������װ����
		sql.Format("select count(*) as COUNT from %s_%s_ColorBox where Status!=0 AND datetime>'%4d-%2d-%2d'",csaType[i],csaOrder[i],st.wYear,st.wMonth,st.wDay);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				temp=VariantToCString(var);
				csaTComplete.Add(temp);

				float time=0.0;
				time = st.wHour-8 + st.wMinute/60.0;
				temp.Format("%.0f",var.intVal/time);//UPH=������װ����/��ǰ��ʱ
				csaUPH.Add(temp);

			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}

		//�������ݿ�������CartonBox����ȡ���հ�װ����
		sql.Format("select count(*) as COUNT from %s_%s_CartonBox where Status!=0 AND Status!=1 AND datetime>'%4d-%2d-%2d'",csaType[i],csaOrder[i],st.wYear,st.wMonth,st.wDay);
		try
		{
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
			((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
			
			if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
			{
				var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("COUNT");
				temp=VariantToCString(var);
				csaTPackage.Add(temp);
			}
			if(((CPACKApp *)AfxGetApp())->m_pRst->State)
				((CPACKApp *)AfxGetApp())->m_pRst->Close();
		}
		catch(_com_error e)
		{
			return FALSE;
		}
	}

	return TRUE;
}


void OrderList::OnTimer(UINT nIDEvent)
{
	int iloop;
	CString temp;
	switch(nIDEvent) 
	{
	case 1:
//		this->KillTimer(1);
	
		CDialog::OnTimer(nIDEvent);

		csaType.RemoveAll();
		csaCustomer.RemoveAll();
		csaOrder.RemoveAll();
		csaColor.RemoveAll();
		csaTotal.RemoveAll();
		csaPut.RemoveAll();
		csaDone.RemoveAll();
		csaShipping.RemoveAll();
		csaNShipping.RemoveAll();
		csaNSDone.RemoveAll();
		csaTPut.RemoveAll();
		csaTComplete.RemoveAll();
		csaTPackage.RemoveAll();
		csaUPH.RemoveAll();
		
		//��ȡ�ϻ�����
		if(!this->GetOrderInfo())
		{
			MessageBox("��ȡ��������ʧ��!","Error",MB_ICONERROR);
			exit(0);
		}
		
		m_irow = csaType.GetSize()+1;
		m_icol = 14;
		SetRowCol(m_irow,m_icol);
		SetNumText(m_irow,m_icol);
		for (iloop=1; iloop<m_irow; iloop++)
		{
			m_OrderFlex.SetTextMatrix(iloop,0,csaType[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,1,csaCustomer[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,2,csaOrder[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,3,csaColor[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,4,csaTotal[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,5,csaPut[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,6,csaDone[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,7,csaShipping[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,8,csaNShipping[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,9,csaNSDone[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,10,csaTPut[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,11,csaTComplete[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,12,csaTPackage[iloop-1]);
			m_OrderFlex.SetTextMatrix(iloop,13,csaUPH[iloop-1]);
		}
		UpdateData(FALSE);

		break;
	default:
		break;
	}
}


void OrderList::OnBtnImeiquery() 
{
	m_csCurrentProduct = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),0);
	m_csCurrentOrder = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),2);
	if(this->m_csCurrentProduct.IsEmpty() || this->m_csCurrentOrder.IsEmpty())
	{
		MessageBox("δѡ����Ŀ����","Error",MB_ICONERROR);
	}
	CQuery dlg;
	dlg.m_iOperateType = 1;
	dlg.m_csProduction = this->m_csCurrentProduct;
	dlg.m_csOrder = this->m_csCurrentOrder;
	dlg.DoModal();
}



void OrderList::OnBtnUnusedimei() 
{
	m_csCurrentProduct = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),0);
	m_csCurrentOrder = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),2);
	if(this->m_csCurrentProduct.IsEmpty() || this->m_csCurrentOrder.IsEmpty())
	{
		MessageBox("δѡ����Ŀ����","Error",MB_ICONERROR);
	}
	CQuery dlg;
	dlg.m_iOperateType = 2;
	dlg.m_csProduction = this->m_csCurrentProduct;
	dlg.m_csOrder = this->m_csCurrentOrder;
	dlg.DoModal();
}
 
void OrderList::OnBtnCarton()
{
	m_csCurrentProduct = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),0);
	m_csCurrentOrder = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),2);
	if(this->m_csCurrentProduct.IsEmpty() || this->m_csCurrentOrder.IsEmpty())
	{
		MessageBox("δѡ����Ŀ����","Error",MB_ICONERROR);
	}
	CQuery dlg;
	dlg.m_iOperateType = 3;
	dlg.m_csProduction = this->m_csCurrentProduct;
	dlg.m_csOrder = this->m_csCurrentOrder;
	dlg.DoModal();
}



void OrderList::OnBtnPrint() 
{
	UpdateData();

	//excel
	CString      m_excel_path;
	_Application m_ExlApp;
	_Workbook    m_ExlBook;
	_Worksheet   m_ExlSheet;
	Workbooks    m_ExlBooks;
	Worksheets   m_ExlSheets;
	Range        m_ExlRge;

	m_csCurrentProduct = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),0);
	m_csCurrentOrder = m_OrderFlex.GetTextMatrix(m_OrderFlex.GetRowSel(),2);
	if(this->m_csCurrentProduct.IsEmpty() || this->m_csCurrentOrder.IsEmpty())
	{
		MessageBox("δѡ����Ŀ����","Error",MB_ICONERROR);
	}

	CString temp;
	_variant_t var;
	CString sql;
	COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	int index;

	index=this->m_ctrComboxType.GetCurSel();
	if(index==-1)
		return;

	//��ȡ��Ŀ�б�
	if(!this->GetProductOrderInfo())
	{
		MessageBox("��ȡ������Ϣʧ��","Error",MB_ICONERROR);
		return;
	}

	//reset
	m_csaIMEI1.RemoveAll();
	m_csaIMEI2.RemoveAll();
	m_csaIMEI3.RemoveAll();
	m_csaNetCode.RemoveAll();
	m_csaSN.RemoveAll();
	m_csaBoxID.RemoveAll();
	m_csaPalletID.RemoveAll();
	m_csaCartonNametemp.RemoveAll();
	m_csaPalletNametemp.RemoveAll();
	m_csaShippingDate.RemoveAll();
	m_csaColorBoxWeigh.RemoveAll();
	m_csaCartonBoxWeigh.RemoveAll();
	m_csaMACAddr.RemoveAll();
	m_csaBTAddr.RemoveAll();
	
	//��ȡ��ǰ·��
	char csPath[MAX_PATH];
	CString PathSource,PathDest;
   	GetCurrentDirectory(MAX_PATH, csPath);
	
	//��ȡģ���ļ�·��
	PathSource=CString(csPath)+"\\Template.xls";

	//����EXCEL����
	if(!m_ExlApp.CreateDispatch("Excel.Application",NULL))
	{
		AfxMessageBox("����EXCEL����ʧ��!");
		return;
	}
	
	m_ExlBooks.AttachDispatch(m_ExlApp.GetWorkbooks(),TRUE);
	
	//����EXCELģ��
	m_ExlBook.AttachDispatch(m_ExlBooks.Add((_variant_t)PathSource),TRUE);
	
	//����sheetҳ��
	//m_ExlSheets.AttachDispatch(m_ExlBook.GetSheets(),TRUE);
	
	//��ȡWorksheets
	m_ExlSheets.AttachDispatch(m_ExlBook.GetWorksheets(),true);
	
	//��ȡsheet1
	m_ExlSheet.AttachDispatch(m_ExlSheets.GetItem(_variant_t("sheet1")),true);
	
	//�������е�Ԫ��
	m_ExlRge.AttachDispatch(m_ExlSheet.GetCells(),TRUE);
	
	if (index == 0)
	{
		//����Ŀ���ļ�·��
		PathDest=CString(csPath)+"\\��������\\"+this->m_csCurrentProduct+"_"+this->m_csCurrentOrder+"_�ʺг���.xls";
		
		//InsertListInfo("���ڵ����ʺг������ݣ���ȴ�...",0);
		
		//��ȡ��������
		if(!GetColorBoxWeighData())
		{
			//InsertListInfo("��ȡ�ʺг�������ʧ��...",2);
			MessageBox("��ȡ�ʺг�������ʧ��","Error",MB_ICONERROR);
			return;
		}
		
		//���EXCEL�������
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("Seq"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("IMEI_1"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("ColorBoxWeigh"));
		
		for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
		{
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->m_csaColorBoxWeigh.GetAt(j-2)));
		}
	}
	else if (index == 1)
	{
		//����Ŀ���ļ�·��
		PathDest=CString(csPath)+"\\��������\\"+this->m_csCurrentProduct+"_"+this->m_csCurrentOrder+"_��ͨ�����.xls";
		
		//InsertListInfo("���ڵ�����ͨ��������ݣ���ȴ�...",0);
		
		//��ȡ��������
		if(!GetCartonBoxWeighData())
		{
			//InsertListInfo("��ȡ��ͨ���������ʧ��...",2);
			MessageBox("��ȡ��ͨ���������ʧ��","Error",MB_ICONERROR);
			return;
		}
		
		//���EXCEL�������
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("Seq"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("CartonBoxID"));
		m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("CartonBoxWeigh"));
		
		for (int j=2;j<(this->m_csaBoxID.GetSize())+2;j++)
		{
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csaBoxID.GetAt(j-2)));
			m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->m_csaCartonBoxWeigh.GetAt(j-2)));
		}
	}
	else if (index == 2)
	{
		if (m_iCustomer == -1)
		{
			return;
		}

		//����Ŀ���ļ�·��
		PathDest=CString(csPath)+"\\��������\\"+this->m_csCurrentProduct+"_"+this->m_csCurrentOrder+".xls";
		
		//InsertListInfo("���ڵ����������ݣ���ȴ�...",0);
		
		//��ȡ��������
		if(!GetShippingData())
		{
			//InsertListInfo("��ȡ��������ʧ��...",2);
			MessageBox("��ȡ��������ʧ��","Error",MB_ICONERROR);
			return;
		}

		if (m_iCustomer == 0)
		{
			//���EXCEL�������
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("Seq"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("ModelName"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("Color"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("Batch No"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("PalletID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)6),_variant_t("BoxID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)7),_variant_t("IMEI_1"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)8),_variant_t("IMEI_2"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)9),_variant_t("IMEI_3"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)10),_variant_t("NetCode"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)11),_variant_t("SN"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)12),_variant_t("BTAddress"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)13),_variant_t("WIFIMAC"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)14),_variant_t("ShippingDate"));

			
			for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
			{
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t((long)(j-1)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csCurrentOrder));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)3),_variant_t(this->m_csCurrentColor));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)4),_variant_t(this->m_csCustomerNo+this->m_csaShippingDate.GetAt(j-2).Mid(2,2)+this->m_csaShippingDate.GetAt(j-2).Mid(5,2)+this->m_csaShippingDate.GetAt(j-2).Right(2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->m_csaPalletID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)6),_variant_t(this->m_csaBoxID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)7),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)8),_variant_t(this->m_csaIMEI2.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)9),_variant_t(this->m_csaIMEI3.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)10),_variant_t(this->m_csaNetCode.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)11),_variant_t(this->m_csaSN.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)12),_variant_t(this->m_csaBTAddr.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)13),_variant_t(this->m_csaMACAddr.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)14),_variant_t(this->m_csaShippingDate.GetAt(j-2)));
			}
		}
		else if (m_iCustomer == 1)
		{
			//���EXCEL�������
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("PALLET ID Number"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("CARTON ID Number"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("Product Number"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("HARDWARE VERSION"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("IMEI SIM:1"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)6),_variant_t("IMEI SIM:2"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)7),_variant_t("SERIAL Number"));
			
			for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
			{
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t(this->m_csaPalletID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csaBoxID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)6),_variant_t(this->m_csaIMEI2.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)7),_variant_t(this->m_csaSN.GetAt(j-2)));
			}
		}
		else if (m_iCustomer == 2)
		{
			//���EXCEL�������
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)1),_variant_t("DEWAV MODEL"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)2),_variant_t("Q-MOBILE MODEL"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)3),_variant_t("INVOICE NO."));//�˹���д
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)4),_variant_t("COLOR"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)5),_variant_t("DATE OF SHIPMENT"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)6),_variant_t("PALLET ID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)7),_variant_t("FULL PALLETS GROSS WEIGHT"));//�˹���д
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)8),_variant_t("CARTON ID"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)9),_variant_t("FULL CARTON BOX GROSS WEIGHT"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)10),_variant_t("MAIN IMEI NUMBER"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)11),_variant_t("SLAVE IMEI NUMBER"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)12),_variant_t("FULL GIFTBOX GROSS WEIGHT"));
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)13),_variant_t("BATTERY AND CHARGER CODING"));//�˹���д
			m_ExlRge.SetItem(_variant_t((long)1),_variant_t((long)14),_variant_t("SERIAL NUMBER"));
			
			for (int j=2;j<(this->m_csaIMEI1.GetSize())+2;j++)
			{
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)1),_variant_t(this->m_csDWNo));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)2),_variant_t(this->m_csCustomerNo));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)4),_variant_t(this->m_csCurrentColor));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)5),_variant_t(this->m_csaShippingDate.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)6),_variant_t(this->m_csaPalletID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)8),_variant_t(this->m_csaBoxID.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)9),_variant_t(this->m_csaCartonBoxWeigh.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)10),_variant_t(this->m_csaIMEI1.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)11),_variant_t(this->m_csaIMEI2.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)12),_variant_t(this->m_csaColorBoxWeigh.GetAt(j-2)));
				m_ExlRge.SetItem(_variant_t((long)j),_variant_t((long)14),_variant_t(this->m_csaSN.GetAt(j-2)));
			}
		}
	}

	//������ʹ�õĵ�Ԫ��
	m_ExlRge.AttachDispatch(m_ExlSheet.GetUsedRange(),TRUE);
	
	//������߶���
	m_ExlRge.SetHorizontalAlignment((_variant_t)(long)-4131);
	
	//�������ݵ�EXCEL
	m_ExlBook.SaveAs(COleVariant(PathDest),covOptional,covOptional,covOptional,covOptional,covOptional,0,covOptional,covOptional,covOptional,covOptional,covOptional);  
	
	//����Ϊ�ɼ�
	m_ExlApp.SetVisible(TRUE);

	//�˳�
	m_ExlApp.Quit();
	
	//�ͷŶ���
	m_ExlRge.ReleaseDispatch();
	m_ExlSheet.ReleaseDispatch();
	m_ExlSheets.ReleaseDispatch();
	m_ExlBook.ReleaseDispatch();
	m_ExlBooks.ReleaseDispatch();
	m_ExlApp.ReleaseDispatch();
	
	//InsertListInfo("�������ݵ����ɹ�...",0);
	temp.Format("������%s���ݵ����ɹ�",m_csCurrentOrder);
	MessageBox(temp);
	return;
}


//��ȡ�ʺг�������
bool OrderList::GetColorBoxWeighData()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	sql.Format("select * from %s_%s_ColorBox where (ColorBoxWeigh<>'' and ColorBoxWeigh IS NOT NULL) and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
			temp=VariantToCString(var);
			m_csaIMEI1.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeigh");
			temp=VariantToCString(var);
			m_csaColorBoxWeigh.Add(temp);
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}

	return TRUE;
}

//��ȡ��ͨ���������
bool OrderList::GetCartonBoxWeighData()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	sql.Format("select distinct CartonName, * from %s_%s_CartonBox where CartonWeigh<>'' and CartonWeigh IS NOT NULL",this->m_csCurrentProduct,this->m_csCurrentOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
			temp=VariantToCString(var);

			temp=m_csCartonNameStatic+temp;
			m_csaBoxID.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
			temp=VariantToCString(var);
			m_csaCartonBoxWeigh.Add(temp);
			
			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	return TRUE;
}

//��ȡ��������
bool OrderList::GetShippingData()
{
	CString temp;
	_variant_t var;
	CString sql;

	//�԰�װ��ɵĿ�ͨ��Ϊ������ȡ����������Ϣ,��ȡ��ͨ��ż�ջ���
	sql.Format("select distinct CartonName, * from %s_%s_CartonBox where Status=2 or Status=3",this->m_csCurrentProduct,this->m_csCurrentOrder);
	try
	{
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonName");
			temp=VariantToCString(var);
			m_csaCartonNametemp.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletName");
			temp=VariantToCString(var);
			m_csaPalletNametemp.Add(temp);

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonWeigh");
			temp=VariantToCString(var);
			m_csaCartonBoxWeigh.Add(temp);
			
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("datetime");
			//temp=VariantToCString(var);
			temp=(LPCSTR)_bstr_t(var);
			m_csaShippingDatetemp.Add(temp);

			((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
	}
	catch(_com_error e)
	{
		return FALSE;
	}
	
	//���ݿ�ͨ��Ż�ȡ��Ӧ��IMEI��SN��
	for (int j=0;j<m_csaCartonNametemp.GetSize();j++)
	{
		if (m_csaCartonNametemp.GetAt(j) != "")
		{
			sql.Format("select * from %s_%s_ColorBox where CartonName='%s' and Enable=1",this->m_csCurrentProduct,this->m_csCurrentOrder,m_csaCartonNametemp.GetAt(j));
			try
			{
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
				((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
				while(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
				{
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI1");
					temp=VariantToCString(var);
					m_csaIMEI1.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI2");
					temp=VariantToCString(var);
					m_csaIMEI2.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("IMEI3");
					temp=VariantToCString(var);
					m_csaIMEI3.Add(temp);
					
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("NetCode");
					temp=VariantToCString(var);
					m_csaNetCode.Add(temp);
					
					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ProductSN");
					temp=VariantToCString(var);
					m_csaSN.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("BTAddress");
					temp=VariantToCString(var);
					m_csaBTAddr.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("WIFIMAC");
					temp=VariantToCString(var);
					m_csaMACAddr.Add(temp);

					var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("ColorBoxWeigh");
					temp=VariantToCString(var);
					m_csaColorBoxWeigh.Add(temp);

					temp=m_csCartonNameStatic+m_csaCartonNametemp.GetAt(j);
					m_csaBoxID.Add(temp);

					temp=m_csPalletNameStatic+m_csaPalletNametemp.GetAt(j);
					m_csaPalletID.Add(temp);

					temp=m_csaShippingDatetemp.GetAt(j);
					m_csaShippingDate.Add(temp);
					
					((CPACKApp *)AfxGetApp())->m_pRst->MoveNext();
				}
				if(((CPACKApp *)AfxGetApp())->m_pRst->State)
					((CPACKApp *)AfxGetApp())->m_pRst->Close();
			}
			catch(_com_error e)
			{
				return FALSE;
			}
		}
	}

	return TRUE;
}


bool OrderList::GetProductOrderInfo()
{
	CString temp;
	_variant_t var;
	CString sql;
	
	try
	{
		sql.Format("select *  from ProductList where Enable=1 and ProductName='%s' and OrderName='%s'",this->m_csCurrentProduct,m_csCurrentOrder);
		
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		((CPACKApp *)AfxGetApp())->m_pRst=((CPACKApp *)AfxGetApp())->m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
		if(!((CPACKApp *)AfxGetApp())->m_pRst->adoEOF)
		{
			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CustomerNo");
			this->m_csCustomerNo=var.bstrVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("SNStatic");
			this->m_csDWNo=var.bstrVal;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("Color");
			temp=VariantToCString(var);
			this->m_csCurrentColor= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("CartonNameStatic");
			temp=VariantToCString(var);
			this->m_csCartonNameStatic= temp;

			var = ((CPACKApp *)AfxGetApp())->m_pRst->GetCollect("PalletNameStatic");
			m_csPalletNameStatic=var.bstrVal;

		}
		if(((CPACKApp *)AfxGetApp())->m_pRst->State)
			((CPACKApp *)AfxGetApp())->m_pRst->Close();
		
	}
	catch(_com_error e)
	{
		return FALSE;
	}	

	return TRUE;
}

void OrderList::OnCloseupComboType() 
{
		UpdateData();
		
		int index;
		
		index = this->m_ctrComboxType.GetCurSel();
		
		if(index == 2)
		{
			m_iCustomer = -1;
			m_ctrCustomer.EnableWindow(TRUE);
		}
		else
		{
			m_iCustomer = -1;
			m_ctrCustomer.EnableWindow(FALSE);
		}
		
	UpdateData(FALSE);
}



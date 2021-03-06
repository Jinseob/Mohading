// WMCALOADERDlg.cpp : implementation file
//
#include "stdafx.h"
#include "WMCALOADER.h"
#include "WMCALOADERDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "trio_inv.h"
#include "trio_ord.h"
#include "math.h"

const	int	TRID_c1101	=1;		//<--蕨衛蒂 爾檜晦 嬪л檜貊 堅薑高橾 в蹂朝 橈蝗棲棻
const	int	TRID_c8201	=2;		//<--蕨衛蒂 爾檜晦 嬪л檜貊 堅薑高橾 в蹂朝 橈蝗棲棻
const	int	TRID_c8102	=3;		//<--蕨衛蒂 爾檜晦 嬪л檜貊 堅薑高橾 в蹂朝 橈蝗棲棻

/************************************************************************************

							!!! 輿曖 !!!

	檜 蕨薯朝 OPEN API library(wmca.dll)曖 餌辨寞徹擊 撲貲ж晦 嬪и 蕨薯縑 碳婁м棲棻.
	檜 蕨薯虜戲煎朝 餌辨濠陛 в蹂煎ж朝 賅萇 薑爾蒂 �挫恉� 熱朝 橈戲嘎煎
	晦獄瞳檣 餌辨寞徹擊 櫛�� �� 陝 餌辨濠滌煎 в蹂и 晦棟擎 滌紫煎 薯奢腎朝 
	濠猿(*.doc)蒂 饜渠煎 億煎 濛撩ж衛晦 夥奧棲棻.

	傳и, 檜 蕨薯縑朝 曖紫ж雖 彊擎 Щ煎斜極 螃盟陛 んл腆 熱 氈戲棲 
	褒�秣瞈� 夥煎 餌辨ж衛朝 匙擎 掏濰ж雖 彊蝗棲棻.
	辨紫縑 蜃啪 Щ煎薛お蒂 億煎 儅撩п憮 濛撩ж衛晦蒂 掏濰м棲棻.

	* 渡餌縑憮朝 檜 蕨薯蒂 鱔и Щ煎斜極 螃翕濛縑 渠п憮 橫集и 疇歜紫 雖雖 彊蝗棲棻.
	* 檜 模蝶 囀萄朝 餌辨濠 蹂羶 傳朝 渡餌 頂睡 餌薑縑 評塭 樹薯萇雖 滲唳腆 熱 氈蝗棲棻.
	* 蕨薯縑 餌辨脹 憮綠蝶 I/O(TR 塽 褒衛除衛撮 ぬ韃)朝 樹薯萇雖 滲唳腆 陛棟撩檜 氈蝗棲棻.
	* 檜 蕨薯朝 Microsoft Visual C++ 6.0, Microsoft Visual C++ 2008 �秣瞈□� 濛撩腎歷蝗棲棻.
	* wmca.dll 塽 蕨薯 囀萄朝 Ansi code晦奩 32bit 晦遽戲煎 薯奢腎貊
	* 64bit 傳朝 Unicode寞衝戲煎曖 翕濛擎 爾濰腎雖 彊蝗棲棻.

************************************************************************************/





/************************************************************************************

	wmca.dll 擊 wrapping и CWmcaIntf class蒂 檜辨ж罹 棻擠 晦棟菟擊 纔蝶おм棲棻.
	
	0. 檣隸(渡餌檣隸+奢檣檣隸)
	1. 癱濠薑爾 褻��(⑷營陛)		c1101
	2. 啗謝薑爾 褻��(濤堅褻��)	c8102
	3. 褒衛除 衛撮 憮綠蝶			j8(囀蝶Я 輿衝 ⑷營陛)
	4. 褒衛除 羹唸鱔爾			d2


************************************************************************************/



/////////////////////////////////////////////////////////////////////////////
// CWMCALOADERDlg dialog
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
CWMCALOADERDlg::CWMCALOADERDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWMCALOADERDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWMCALOADERDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWMCALOADERDlg)
	DDX_Control(pDX, IDC_LIST1, m_listboxTrace);
	DDX_Control(pDX, IDC_COMBOACCOUNTLIST, m_comboAccountList);
	DDX_Control(pDX, IDC_STATICLOGIN, m_staticLoginTime);
	DDX_Control(pDX, IDC_EDIT3, m_editSignPassword);
	DDX_Control(pDX, IDC_EDIT2, m_editPassword);
	DDX_Control(pDX, IDC_EDIT1, m_editID);
	DDX_Control(pDX, IDC_CONNECT, m_buttonConnect);
	DDX_Control(pDX, IDC_DISCONNECT, m_buttonDisconnect);
	DDX_Control(pDX, IDC_BALANCE, m_buttonBalance);
	//}}AFX_DATA_MAP
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
BEGIN_MESSAGE_MAP(CWMCALOADERDlg, CDialog)
	//{{AFX_MSG_MAP(CWMCALOADERDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(IDC_BALANCE, OnBalance)
	ON_BN_CLICKED(IDC_BUTTON_CURRENT, OnButtonCurrent)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_ORDER, OnButtonOrder)
	//}}AFX_MSG_MAP

	ON_MESSAGE(CA_WMCAEVENT, OnWmcaEvent)
END_MESSAGE_MAP()
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收

/////////////////////////////////////////////////////////////////////////////
// CWMCALOADERDlg message handlers
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnPaint() 
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
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
HCURSOR CWMCALOADERDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnOK() 
{
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnCancel() 
{
	CDialog::OnCancel();
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnConnect() 
{
	CString	strID;
	CString	strPassword;
	CString	strSignPassword;

	m_editID.GetWindowText(strID);
	m_editPassword.GetWindowText(strPassword);
	m_editSignPassword.GetWindowText(strSignPassword);

	//蕾樓 塽 煎斜檣
	//衙羹囀萄朝 か滌и 唳辦蒂 薯諼ж堅 о鼻 嬴楚 晦獄高擊 餌辨ж衛晦 夥奧棲棻.
	m_wmca.Connect(GetSafeHwnd(),CA_WMCAEVENT,'T','W',strID,strPassword,strSignPassword);	//Namuh OpenAPI 餌辨濠辨
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnDisconnect() 
{
	m_wmca.Disconnect();
}

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
//	僥濠翮擊 掘褻羹 в萄煎 瞳瞰�� 瓣辦朝 嶸せ葬じ л熱殮棲棻. (剩纂賊 澀葡)
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void	_smove(char* szTarget,int nSize,CString strSource)
{
	int	nMin	=min(nSize,strSource.GetLength());

	memset(szTarget,' ',nSize);
	strncpy(szTarget,strSource,nMin);
}

#define SMOVE(fTarget,strSource)	_smove(fTarget,sizeof fTarget,strSource)

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
//	璋濠蒂 掘褻羹 в萄煎 瞳瞰�� 瓣辦朝 嶸せ葬じ л熱殮棲棻.	  (剩纂賊 幗葡)
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void	_nmove(char* szTarget,int nTarget,CString strSource)
{
	if(strSource.GetLength()>nTarget)
		return;

	memset(szTarget,'0',nTarget);
	strncpy(szTarget+nTarget-strSource.GetLength(),strSource,strSource.GetLength());
}

#define NMOVE(fTarget,strSource)	_nmove(fTarget,sizeof fTarget,strSource)

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
//	掘褻羹 в萄高擊 僥濠翮 ⑽鷓煎 滲�納炴� 嶸せ葬じ л熱殮棲棻.
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
CString	_scopy(const char* szData,int nSize)
{
	char	szBuf[256];				//в萄曖 譆渠 觼晦朝 鼻�窒� 評塭 褻瞰й в蹂陛 氈擠
	memset(szBuf,0,sizeof szBuf);
	strncpy(szBuf,szData,nSize);
	
	return szBuf;
}

#define SCOPY(x)	_scopy(x,sizeof x)

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
//	掘褻羹 в萄高擊 璋濠 ⑽鷓煎 滲�納炴� 嶸せ葬じ л熱殮棲棻.
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
CString	_ncopy(const char* szData,int nSize)
{
	CString	strInput	=_scopy(szData,nSize);

	for(int i=0;i<strInput.GetLength();i++)
		if(strInput.GetAt(i)=='0')
		{
			//葆雖虞 '0' 傳朝 棻擠縑 模熱薄檜 螃朝 唳辦縑朝 雖辦雖 彊朝棻
			if(i!=strInput.GetLength()-1 && strInput.GetAt(i+1)!='.')	
				strInput.SetAt(i,' ');
		}
		else if(strInput.GetAt(i)=='-')	//minus
			;
		else if(strInput.GetAt(i)==' ')	//璋濠⑽歜縑紫 奢寥僥濠陛 螃朝 唳辦陛 氈擠
			;
		else
			break;

	return	strInput;
}

#define NCOPY(x)	_ncopy(x,sizeof x)

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
//	 璋濠縑 繭 欽嬪煎 闡葆 鳶殮ж朝 嶸せ葬じ л熱殮棲棻.
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
CString	_comma(const char* szData,int nSize,int decimal=0)
{
	CString	strInput	=_scopy(szData,nSize);
	strInput.TrimLeft();
	strInput.TrimRight();
	
	double	fInput	=atof(strInput);

	CString	strTemp;
	strTemp.Format("%0.*f",decimal,fInput);

	if(fInput>=1000000000.0F)
		strTemp.Insert(strTemp.GetLength()-9,',');
	if(fInput>=1000000.0F)
		strTemp.Insert(strTemp.GetLength()-6,',');
	if(fInput>=1000.0F)
		strTemp.Insert(strTemp.GetLength()-3,',');

	CString	strOutput;
	strOutput.Format("%*s",nSize,strTemp);

	return strOutput;
}

#define COMMA(x)	_comma(x,sizeof x)
#define COMMAF(x,d)	_comma(x,sizeof x,d)

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
//	wmca.dll煎 睡攪 熱褐и 孺紫辦 詭衛雖蒂 鱔п 陝 檜漸お с菟楝煎 碟晦м棲棻
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
LRESULT CWMCALOADERDlg::OnWmcaEvent(WPARAM dwMessageType, LPARAM lParam)
{
	switch(dwMessageType) {
	case CA_CONNECTED:			//煎斜檣 撩奢
		OnWmConnected( (LOGINBLOCK*)lParam );
		break;
	case CA_DISCONNECTED:		//蕾樓 莒梯
		OnWmDisconnected();
		break;
	case CA_SOCKETERROR:		//鱔褐 螃盟 嫦儅
		OnWmSocketerror( (int)lParam );
		break;
	case CA_RECEIVEDATA:		//憮綠蝶 擬港 熱褐(TR)
		OnWmReceivedata( (OUTDATABLOCK*)lParam );
		break;
	case CA_RECEIVESISE:		//褒衛除 等檜攪 熱褐(BC)
		OnWmReceivesise( (OUTDATABLOCK*)lParam );
		break;
	case CA_RECEIVEMESSAGE:		//鼻鷓 詭衛雖 熱褐 (殮溘高檜 澀跤腎歷擊 唳辦 僥濠翮⑽鷓煎 撲貲檜 熱褐脾)
		OnWmReceivemessage( (OUTDATABLOCK*)lParam );
		break;
	case CA_RECEIVECOMPLETE:	//憮綠蝶 籀葬 諫猿
		OnWmReceivecomplete( (OUTDATABLOCK*)lParam );
		break;
	case CA_RECEIVEERROR:		//憮綠蝶 籀葬醞 螃盟 嫦儅 (殮溘高 螃盟蛔)
		OnWmReceiveerror( (OUTDATABLOCK*)lParam );
		break;
	default:
		break;
	}

	return TRUE;
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmConnected( LOGINBLOCK* pLogin )
{
	//煎斜檣檜 撩奢ж賊, 蕾樓衛陝 塽 啗謝廓�� 薑爾蒂 嫡嬴 瞳瞰�� 爾婦/轎溘м棲棻.
	//啗謝廓�ˋ� 渠и 牖憮(檣策蝶)朝 啗謝婦溼 憮綠蝶 ��轎衛 餌辨腎嘎煎 醞蹂м棲棻.
	
	//鐘お煤 �側獄鬌繙秣�
	m_editID.EnableWindow(FALSE);
	m_editPassword.EnableWindow(FALSE);
	m_editSignPassword.EnableWindow(FALSE);

	m_buttonConnect.EnableWindow(FALSE);
	m_buttonDisconnect.EnableWindow(TRUE);

	//蕾樓衛陝 轎溘
	char	szText[256]	={0};
	strncpy(szText,pLogin->pLoginInfo->szDate,sizeof pLogin->pLoginInfo->szDate);
	CString	strText	="蕾樓衛陝 : ";
	strText	+=szText;
	m_staticLoginTime.SetWindowText(strText);

	//啗謝廓�� 轎溘
	char	szAccountCount[8]	={0};
	strncpy(szAccountCount,pLogin->pLoginInfo->szAccountCount,sizeof pLogin->pLoginInfo->szAccountCount);
	int	nAccountCount	=atoi(szAccountCount);

	m_comboAccountList.ResetContent();
	for(int i=0;i<nAccountCount;i++)
	{
		char	szAccountNo[16]	={0};
		strncpy(szAccountNo,(char*)&pLogin->pLoginInfo->accountlist[i].szAccountNo,sizeof pLogin->pLoginInfo->accountlist[i].szAccountNo);

		CString	strAccountNo	=szAccountNo;
		m_comboAccountList.AddString(strAccountNo);

		//strAccountNo.Insert(3,'-');
		//strAccountNo.Insert(6,'-');

		//CString	strIndex;
		//strIndex.Format("啗謝%3d:%s",i+1,strAccountNo);		//啗謝廓�ㄣ� '1'廓睡攪 衛濛м棲棻. 

		//m_comboAccountList.AddString(strIndex);
	}

	//濠翕戲煎 羅 廓簞 啗謝蒂 摹鷗
	if(nAccountCount)
		m_comboAccountList.SetCurSel(0);

	//
	m_listboxTrace.AddString("薑鼻 蕾樓腎歷蝗棲棻");
	ScrollDown();
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmDisconnected()
{
	//蕾樓檜 莒啣擊 唳辦 籀葬
	m_staticLoginTime.SetWindowText("");

	m_editID.EnableWindow(TRUE);
	m_editPassword.EnableWindow(TRUE);
	m_editSignPassword.EnableWindow(TRUE);

	m_buttonConnect.EnableWindow(TRUE);
	m_buttonDisconnect.EnableWindow(FALSE);
	
	//
	m_listboxTrace.AddString("蕾樓檜 莒啣蝗棲棻");
	ScrollDown();
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmSocketerror(int socket_error_code)
{
	m_listboxTrace.AddString("鱔褐螃盟嫦儅");
	ScrollDown();
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmReceivedata( OUTDATABLOCK* pOutData )
{
	switch(pOutData->TrIndex)
	{
	case TRID_c1101:
		//////////////////////////////////////////////////////////////////////////
		//奩犒腎雖 彊朝 欽牖轎溘 籀葬 寞衝
		//////////////////////////////////////////////////////////////////////////

		if(strcmp(pOutData->pData->szBlockName,"c1101OutBlock")==0)			
		{
			Tc1101OutBlock*	pc1101outblock	=(Tc1101OutBlock*)pOutData->pData->szData;
			
			m_listboxTrace.AddString(">>  輿衝⑷營陛褻�� - ⑷營陛");
			
			CString	strList;
			strList.Format("%10s %6s %20s %15s錳 %15s輿",
				SCOPY(pc1101outblock->hotime),
				SCOPY(pc1101outblock->code),
				SCOPY(pc1101outblock->hname),
				COMMA(pc1101outblock->price),
				COMMA(pc1101outblock->volume)
				);
			
			m_listboxTrace.AddString(strList);
			ScrollDown();
		}
		//////////////////////////////////////////////////////////////////////////
		//奩犒陛棟и 轎溘縑 渠и 籀葬 寞衝
		//////////////////////////////////////////////////////////////////////////

		//輿衝 ⑷營陛/滲翕剪楚榆濠猿	
		if(strcmp(pOutData->pData->szBlockName,"c1101OutBlock2")==0)		
		{
			Tc1101OutBlock2*	pc1101outblock2	=(Tc1101OutBlock2*)pOutData->pData->szData;
			
			m_listboxTrace.AddString(">>  輿衝⑷營陛褻�� - 滲翕剪楚榆");
			
			//褒薯 等檜攪縑 評塭 熱褐 等檜攪 ч曖 熱陛 陛滲瞳檜嘎煎
			//熱褐濠猿 觼晦蒂 掘褻羹 觼晦煎 釭援橫 賃 廓 奩犒腎朝雖 啗骯л
			int		nOccursCount	=pOutData->pData->nLen/sizeof(Tc1101OutBlock2);			//奩犒 �蜈鷏� 掘л
			
			for(int i=0;i<nOccursCount;i++)	//�蜈鷏衙� 奩犒ж賊憮 等檜攪 掘л
			{
				CString	strList;
				strList.Format("%10s %9s錳 %7s錳 %7s錳 %7s錳 %10s輿 %12s輿",
					SCOPY(pc1101outblock2->time),
					COMMA(pc1101outblock2->price),
					COMMA(pc1101outblock2->change),
					COMMA(pc1101outblock2->offer),
					COMMA(pc1101outblock2->bid),
					COMMA(pc1101outblock2->movolume),
					COMMA(pc1101outblock2->volume)
					);
				
				m_listboxTrace.AddString(strList);
				
				pc1101outblock2++;	//棻擠ч戲煎 ん檣攪 檜翕
			}

			ScrollDown();
		}
		break;
	case TRID_c8201:
		//////////////////////////////////////////////////////////////////////////
		//奩犒腎雖 彊朝 欽牖轎溘 籀葬 寞衝
		//////////////////////////////////////////////////////////////////////////
		if(strcmp(pOutData->pData->szBlockName,"c8201OutBlock")==0)			
		{
			Tc8201OutBlock*	pc8201outblock	=(Tc8201OutBlock*)pOutData->pData->szData;
			
			m_listboxTrace.AddString("*** 濤堅褻�� 蕨衛 ***");
			m_listboxTrace.AddString("  識ゎ陛識擋    ="+COMMA(pc8201outblock->dpsit_amtz16));
			m_listboxTrace.AddString("  隸剪旎識擋    ="+COMMA(pc8201outblock->chgm_pos_amtz16));
			m_listboxTrace.AddString("  輿僥陛棟旎擋  ="+COMMA(pc8201outblock->pos_csamt4z16));

			ScrollDown();
		}
		//////////////////////////////////////////////////////////////////////////
		//奩犒陛棟и 轎溘縑 渠и 籀葬 寞衝
		//////////////////////////////////////////////////////////////////////////
		else if(strcmp(pOutData->pData->szBlockName,"c8201OutBlock1")==0)			
		{
			Tc8201OutBlock1*	pc8201outblock1	=(Tc8201OutBlock1*)pOutData->pData->szData;

			int		nOccursCount	=pOutData->pData->nLen/sizeof(Tc8201OutBlock1);			//熱褐 觼晦蒂 溯囀萄 觼晦煎 釭援橫憮 褒薯 奩犒 �蜈鷏� 憲 熱 氈擠
			m_listboxTrace.AddString("*** 爾嶸謙跡褻�� 蕨衛 ***");

			for(int i=0;i<nOccursCount;i++)	//�蜈鷏衙� 奩犒ж賊憮 等檜攪 掘л
			{
				//嬴楚 о跡菟擎 欽牖�� 蕨衛蒂 嬪п 厥擎 高菟殮棲棻. в蹂縑 評塭 繩餉ж衛晦 夥奧棲棻.
				//渡餌 HTS縑 褻�葭Ж� 頂辨婁 翕橾ж貊 翕橾 謙跡檜 罹楝還縑 勘藥 ル晦腆 唳辦 謙跡貲婁 謙跡囀萄陛 儅楞腎晦紫 м棲棻.
				m_listboxTrace.AddString("  謙跡囀萄      ="	+SCOPY(pc8201outblock1->issue_codez6));
				m_listboxTrace.AddString("  謙跡貲        ="	+SCOPY(pc8201outblock1->issue_namez40));
				m_listboxTrace.AddString("  隸剪旎睦(%)   ="	+COMMA(pc8201outblock1->issue_mgamt_ratez6));
				m_listboxTrace.AddString("  濤堅嶸⑽      ="	+SCOPY(pc8201outblock1->bal_typez6));
				m_listboxTrace.AddString("  嘐唸薯        ="	+COMMA(pc8201outblock1->unstl_qtyz16));
				m_listboxTrace.AddString("  ⑷營濤堅      ="	+COMMA(pc8201outblock1->jan_qtyz16));
				m_listboxTrace.AddString("  ゎ敕衙殮陛    ="	+COMMA(pc8201outblock1->slby_amtz16));
				m_listboxTrace.AddString("  ゎ陛槳櫛(繭錳)="	+COMMA(pc8201outblock1->lsnpf_amtz16));
				m_listboxTrace.AddString("  槳櫛睦        ="	+COMMAF(pc8201outblock1->earn_ratez9,2));
				m_listboxTrace.AddString("  ゎ陛旎擋      ="	+COMMA(pc8201outblock1->ass_amtz16));
				m_listboxTrace.AddString(" ");

				pc8201outblock1++;	//棻擠ч戲煎 ん檣攪 檜翕
			}

			ScrollDown();
		}
		break;
	case TRID_c8102:
		//////////////////////////////////////////////////////////////////////////
		//奩犒腎雖 彊朝 欽牖轎溘 籀葬 寞衝
		//////////////////////////////////////////////////////////////////////////
		if(strcmp(pOutData->pData->szBlockName,"c8102OutBlock")==0)			
		{
			Tc8102OutBlock*	pc8102OutBlock	=(Tc8102OutBlock*)pOutData->pData->szData;
			
			CString	strOrderNum		=SCOPY(pc8102OutBlock->order_noz10);
			strOrderNum.TrimLeft();
			strOrderNum.TrimRight();

			if(strOrderNum.IsEmpty())
			{
				m_listboxTrace.AddString(">>  輿僥 褒ぬ");
				break;
			}
			
			m_listboxTrace.AddString(">>  輿僥 薑鼻");
			m_listboxTrace.AddString("輿僥廓�� ="+strOrderNum);
			
			ScrollDown();
		}
		break;
	}
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::ScrollDown()
{
//	m_listboxTrace.AddString("");
	m_listboxTrace.SetTopIndex(	m_listboxTrace.GetCount()-1	);
	m_listboxTrace.SetSel(m_listboxTrace.GetCount()-1);
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmReceivesise( OUTDATABLOCK* pSiseData )
{
	//囀蝶Я 輿衝⑷營陛 褒衛除 衛撮 熱褐
	if(strncmp(pSiseData->pData->szBlockName,"j8",2)==0)		
	{
		Tj8OutBlock*	pj8	=(Tj8OutBlock*)(pSiseData->pData->szData+3);	//擅薹 3夥檜お朝 ぬ韃嶸⑽婁 憶蹴掘碟檜嘎煎 skip
		
		CString	strOut;
		strOut.Format("囀蝶Я 輿衝 ⑷營陛(褒衛除):  %10s %6s %15s %15s",
				SCOPY(pj8->time),
				SCOPY(pj8->code),
				COMMA(pj8->price),
				COMMA(pj8->volume)
		);

		m_listboxTrace.AddString(strOut);
		ScrollDown();
	}
	
	//輿曖) 褒衛除 羹唸鱔爾	-	褒衛除 羹唸鱔爾朝 滌紫煎 Attach()л熱蒂 ��轎ж雖 彊嬴紫 濠翕 熱褐腌棲棻
	//d2 掘褻羹 薑爾蒂 鱔п в蹂煎 ж朝 薑爾蒂 蹺轎й 熱 氈蝗棲棻.
	else if(strncmp(pSiseData->pData->szBlockName,"d2",2)==0)	
	{
		Td2OutBlock*	pd2	=(Td2OutBlock*)(pSiseData->pData->szData+3);	//擅薹 3夥檜お朝 ぬ韃嶸⑽婁 憶蹴掘碟檜嘎煎 skip

		//
		CString	strResult;
		strResult.Format("褒衛除 羹唸鱔爾- 衛陝(%s) 啗謝廓��(%s) 熱榆(%15s) 陛問(%15s)",SCOPY(pd2->conctime),
			SCOPY(pd2->accountno),COMMA(pd2->concgty),COMMA(pd2->concprc));
		m_listboxTrace.AddString(strResult);
		ScrollDown();
	}
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmReceivemessage( OUTDATABLOCK* pMessage )
{
	//⑷營 鼻鷓蒂 僥濠翮 ⑽鷓煎 轎溘л
	MSGHEADER*	pMsgHeader		=(MSGHEADER*)pMessage->pData->szData;

	CString	strMsg;
	strMsg.Format("[%10d]  %5s : %s",
			pMessage->TrIndex,
			SCOPY(pMsgHeader->msg_cd),
			SCOPY(pMsgHeader->user_msg)	
	);

	m_listboxTrace.AddString(strMsg);
	ScrollDown();
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmReceivecomplete( OUTDATABLOCK* pOutData )
{
	//TR ��轎 諫猿衛薄縑 劃陛 п撿и棻賊 嬴楚諦 偽檜 籀葬й 熱 氈蝗棲棻
	switch(pOutData->TrIndex)
	{
	case TRID_c1101:	;
		m_listboxTrace.AddString("輿衝 ⑷營陛 褻�� 諫猿");
		ScrollDown();
		break;
	case TRID_c8201:	;
		m_listboxTrace.AddString("啗謝 濤堅 褻�� 諫猿");
		ScrollDown();
		break;
	}
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnWmReceiveerror( OUTDATABLOCK* pError )
{
	//憮綠蝶 ��轎檜 褒ぬй 唳辦 熱褐脾
	m_listboxTrace.AddString("*** ERROR ***");
	m_listboxTrace.AddString(pError->pData->szData);
	ScrollDown();
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnBalance()					//濤堅 褻��(Queryл熱 餌辨 幗瞪)
{
    //濤堅褻�虜� 嬪п 餌辨й 啗謝廓�� 檣策蝶蒂 掘м棲棻.
	//啗謝廓�� 檣策蝶朝 '1'睡攪 衛濛腌棲棻.
	int	nAccountIndex	=m_comboAccountList.GetCurSel()+1;

	//濤堅褻�� 憮綠蝶縑憮 蹂掘ж朝 殮溘高擊 盪濰й 掘褻羹 滲熱殮棲棻.
	//樓撩夥檜お 援塊擊 寞雖ж晦 嬪п 陛晝瞳 殮溘掘褻羹蒂 餌辨ж朝 匙擊 掏濰м棲棻.
	//渡餌 OpenAPI蒂 籀擠 餌辨ж衛朝 碟菟眷憮 陛濰 號檜 褒熱ж朝 睡碟殮棲棻. 
	//
	//ex)'殮溘高擊 薯渠煎 厥歷棻堅 儅陝ж朝等 凳陛 蜃雖 彊棻堅 啗樓 剪睡腌棲棻. 凳陛 澀跤脹 勘梱蹂?'

	Tc8201InBlock	c8201inblock;
	memset(&c8201inblock,0x20,sizeof Tc8201InBlock);	//奢寥僥濠(space)煎 蟾晦�倆桭炴�.

	//�飛暺騔� 啗謝 ゎ僥 綠塵廓�ㄧ� OpenAPI縑憮 薯奢腎堅 氈朝 hashл熱縑 殮溘ж賊
	//雖薑и 殮溘в萄縑 hash 綠塵廓�ㄦ� 瓣錶餵棲棻.
	//賅萇 hash 綠塵廓��曖 望檜朝 44夥檜お 堅薑殮棲棻.
	CString	strPassword;
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(strPassword);
	m_wmca.SetAccountIndexPwd(c8201inblock.pswd_noz44,nAccountIndex,strPassword);

	//陝 殮溘 в萄縑憮 蹂掘ж朝 高菟縑 渠и 薑曖朝 *.doc 僥憮蒂 鱔п �挫恉� 熱 氈蝗棲棻.
	SMOVE(c8201inblock.bnc_bse_cdz1,"1");			//掘碟	

	m_wmca.Query(
			GetSafeHwnd(),			//檜 孺紫辦煎 擬港 詭衛雖蒂 嫡啊蝗棲棻.
			TRID_c8201,				//檜 憮綠蝶縑 渠п憮 TRID_c8201(3) 衝滌濠蒂 稱檜啊棻朝 曖嘐檜貊 奩萄衛 鼻熱橾 в蹂朝 橈蝗棲棻.
			"c8201",				//��轎ж溥朝 憮綠蝶 囀萄朝 'c8201' 殮棲棻.
			(char*)&c8201inblock,	//c8201縑憮 蹂掘ж朝 殮溘 掘褻羹 ん檣攪蒂 雖薑м棲棻
			sizeof Tc8201InBlock,	//殮溘 掘褻羹 觼晦殮棲棻
			nAccountIndex			//啗謝廓�� 檣策蝶朝 '1'睡攪 衛濛腌棲棻.
	);
}
//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
void CWMCALOADERDlg::OnButtonCurrent()	//⑷營陛 褻��
{
	//輿衝⑷營陛褻�� 憮綠蝶縑憮 蹂掘ж朝 殮溘高擊 盪濰й 掘褻羹 滲熱殮棲棻.
	Tc1101InBlock	c1101inblock;
	memset(&c1101inblock,0x20,sizeof Tc1101InBlock);

	//�飛暺騔� 謙跡囀萄蒂 掘м棲棻
	CString	strJCode;
	GetDlgItem(IDC_EDIT_JCODE)->GetWindowText(strJCode);
	
	//陝 殮溘 в萄縑憮 蹂掘ж朝 高菟縑 渠и 薑曖朝 *.doc 僥憮蒂 鱔п �挫恉� 熱 氈蝗棲棻.
	SMOVE(c1101inblock.formlang,"k");
	SMOVE(c1101inblock.code,strJCode);
	
	//輿衝 ⑷營陛 褻��
	m_wmca.Query(
			GetSafeHwnd(),			//檜 孺紫辦煎 擬港 詭衛雖蒂 嫡啊蝗棲棻.
			TRID_c1101,				//檜 憮綠蝶縑 渠п憮 TRID_c1101(5) 衝滌濠蒂 稱檜啊棻朝 曖嘐檜貊 奩萄衛 鼻熱橾 в蹂朝 橈蝗棲棻.
			"c1101",				//��轎ж溥朝 憮綠蝶 囀萄朝 'c1101' 殮棲棻.
			(char*)&c1101inblock,	//c1101縑憮 蹂掘ж朝 殮溘 掘褻羹 ん檣攪蒂 雖薑м棲棻
			sizeof Tc1101InBlock 	//殮溘 掘褻羹 觼晦殮棲棻
									//⑷營陛蒂 んли 癱濠薑爾 褻�葩� 啗謝廓�ˋ� 鼠婦ж嘎煎 啗謝廓�� 檣策蝶蒂 雖薑ж雖 彊蝗棲棻.
	);

	//晦襄縑 蹂羶и 褒衛除 衛撮陛 氈棻賊 賅舒 鏃模
	m_wmca.DetachAll();

	//輿衝 褒衛除 ⑷營陛 ぬ韃 蹂羶 蕨衛
	m_wmca.Attach(
			GetSafeHwnd(),			//褒衛除 等檜攪 熱褐 詭衛雖蒂 檜 孺紫辦煎 嫡啊蝗棲棻.
			"j8",					//蹂羶ж朝 褒衛除 ぬ韃擎 '囀蝶Я輿衝⑷營陛'(j8)殮棲棻
			strJCode,				//j8 憮綠蝶縑憮 蹂掘ж朝 謙跡囀萄殮溘高擊 雖薑м棲棻.
			6/*謙跡囀萄 觼晦*/,	//偃滌謙跡囀萄曖 望檜朝 6夥檜お檜貊
			6/*殮溘高 瞪羹 觼晦*/	//瞪羹謙跡囀萄曖 望檜紫 6夥檜お殮棲棻. 罹楝 謙跡橾 唳辦縑朝 (謙跡囀萄望檜*謙跡熱)蒂 雖薑м棲棻.
	);			

	//輿衝 褒衛除 ⑷營陛 ぬ韃 鏃模 蕨衛
	//碳в蹂и 褒衛除 ぬ韃擊 鏃模ж雖 彊擊 唳辦 п渡 ぬ韃檜 啗樓 熱褐腎嘎煎 輿曖ж衛晦 夥奧棲棻!
	//
	//m_wmca.Detach(
	//	GetSafeHwnd(),			//褒衛除 等檜攪 熱褐 詭衛雖蒂 檜 孺紫辦煎 嫡啊蝗棲棻.
	//	"j8",					//鏃模ж朝 褒衛除 ぬ韃擎 '囀蝶Я輿衝⑷營陛'(j8)殮棲棻
	//	strJCode,				//j8 憮綠蝶縑憮 蹂掘ж朝 謙跡囀萄殮溘高擊 雖薑м棲棻.
	//	6/*謙跡囀萄 觼晦*/,	//偃滌謙跡囀萄曖 望檜朝 6夥檜お檜貊
	//	6/*殮溘高 瞪羹 觼晦*/	//瞪羹謙跡囀萄曖 望檜紫 6夥檜お殮棲棻.
	//	);			
	
	//3謙跡(000660,005940,005930)縑 渠и 褒衛除 ⑷營陛 等檜攪 蹂羶 蕨衛
	//m_wmca.Attach(GetSafeHwnd(),"j8","000660005940005930",	6/*謙跡囀萄 望檜*/,18/*=謙跡囀萄望檜(6)*謙跡熱(3)*/);		
	
	//摹僭 ⑷營陛, �ㄟ� 褒衛除 等檜攪 蹂羶
	//m_wmca.Attach(GetSafeHwnd(),"f8","101N6000", 8, 8);	//2018喇 6錯僭 摹僭 ⑷營陛
	//m_wmca.Attach(GetSafeHwnd(),"f1","101N6000", 8, 8);	//2018喇 6錯僭 摹僭 �ㄟ�
	
	//褫暮 ⑷營陛, �ㄟ� 褒衛除 等檜攪 蹂羶
	//m_wmca.Attach(GetSafeHwnd(),"o2","201N5315", 8, 8);	//2018喇 05錯僭 屬褫暮 ч餌陛 315.0 ⑷營陛
	//m_wmca.Attach(GetSafeHwnd(),"o1","201N5315", 8, 8);	//2009喇 05錯僭 屬褫暮 ч餌陛 315.0 �ㄟ�
}

void CWMCALOADERDlg::OnButtonClear() 
{
	m_listboxTrace.ResetContent();
}

void CWMCALOADERDlg::OnButtonOrder()
{
/*
	AfxMessageBox(	"輿僥 褒熱 寞雖蒂 嬪п 褒ч擊 離欽ж艘蝗棲棻.\n\n模蝶 囀萄蒂 �挫恉牮� �� 瞳瞰�� 熱薑ж罹 餌辨ж衛晦 夥奧棲棻",MB_ICONSTOP);
	return;
*/

	//啗謝廓�� 檣策蝶蒂 掘м棲棻.	(啗謝廓�ㄣ� '1'廓睡攪 衛濛)
	int	nAccountIndex	=m_comboAccountList.GetCurSel()+1;

	//輿僥 test朝 輿曖陛 蹂掘腌棲棻
	//輿衝輿僥 憮綠蝶縑憮 蹂掘ж朝 殮溘高擊 盪濰й 掘褻羹 滲熱殮棲棻.
	Tc8102InBlock	c8102inblock	={0};
	memset(&c8102inblock,0x20,sizeof Tc8102InBlock);

	//�飛暺騔� 啗謝 綠塵廓�ㄧ� 掘м棲棻
	CString	strPassword;
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(strPassword);

	//謙跡囀萄 �挫�
	CString	strItemCode;
	GetDlgItem(IDC_EDIT_JCODE)->GetWindowText(strItemCode);
	strItemCode.TrimRight();

	//熱榆 �挫�
	CString	strAmount;
	GetDlgItem(IDC_EDIT_AMOUNT)->GetWindowText(strAmount);
	strAmount.TrimRight();

	//欽陛 �挫�
	CString	strPrice;
	GetDlgItem(IDC_EDIT_PRICE)->GetWindowText(strPrice);
	strPrice.TrimRight();

	//陝 殮溘 в萄縑憮 蹂掘ж朝 高菟縑 渠и 薑曖朝 *.doc 僥憮蒂 鱔п �挫恉� 熱 氈蝗棲棻.
	//啗謝綠塵廓�ㄧ� 賅曖癱濠�秣瞈□韭� �挫恉狫� 彊雖虜 褒�秣瞈□韭� �挫恉牊Й� 薑�旁炾� 殮溘ж衛晦 夥奧棲棻
	//啗謝綠塵廓�ㄣ� 剪楚(輿僥)綠塵廓�ˋ芫� 棻落棲棻. 剪楚綠塵廓�ㄧ� 厥雖 彊紫煙 輿曖ж衛晦 夥奧棲棻.
	m_wmca.SetAccountIndexPwd(c8102inblock.pswd_noz8,nAccountIndex,strPassword);	

	SMOVE(c8102inblock.issue_codez6, strItemCode);		//謙跡囀萄
	NMOVE(c8102inblock.order_qtyz12, strAmount);		//熱榆
	NMOVE(c8102inblock.order_unit_pricez10,strPrice);	//陛問
	SMOVE(c8102inblock.trade_typez2, "00");				//雖薑陛(00),衛濰陛(03)

	//嬴楚 殮溘ж朝 剪楚綠塵廓��1, 2塢縑朝 餌辨濠曖 剪楚綠塵廓�ㄧ� 殮溘п撿м棲棻.
	//剪楚(輿僥)綠塵廓�ㄣ� 啗謝綠塵廓�ˋ芫� 棻腦貊 啗謝綠塵廓�ㄧ� 厥雖 彊紫煙 輿曖ж衛晦 夥奧棲棻.
	m_wmca.SetOrderPwd(c8102inblock.trad_pswd_no_1z8,"--------");		
	m_wmca.SetOrderPwd(c8102inblock.trad_pswd_no_2z8,"--------");		
	
	//輿衝 輿僥
	m_wmca.Query(
			GetSafeHwnd(),			//檜 孺紫辦煎 擬港 詭衛雖蒂 嫡啊蝗棲棻.
			TRID_c8102,				//檜 憮綠蝶縑 渠п憮 TRID_c8102 衝滌濠蒂 稱檜啊蝗棲棻. (蕨衛橾 閨檜貊,棻艇 高擊 厥橫憮 餌辨ж敷紫 腌棲棻)
			"c8102",				//��轎ж溥朝 憮綠蝶 囀萄朝 c8102 殮棲棻.
			(char*)&c8102inblock,	//c8102縑憮 蹂掘ж朝 殮溘 掘褻羹 ん檣攪蒂 雖薑м棲棻.
			sizeof Tc8102InBlock,	//殮溘 掘褻羹 觼晦殮棲棻
			nAccountIndex			//錳ж朝 啗謝廓�� 檣策蝶蒂 雖薑м棲棻.		(啗謝廓�ㄣ� '1'廓睡攪 衛濛)
	);

}

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收
BOOL CWMCALOADERDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//
	GetDlgItem(IDC_EDIT_JCODE)->SetWindowText("003160");

	GetDlgItem(IDC_EDIT1)->SetWindowText("");
	GetDlgItem(IDC_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_EDIT3)->SetWindowText("");
	//////////////////////////////////////////////////////////////////////////
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


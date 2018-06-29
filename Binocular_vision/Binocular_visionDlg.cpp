
// Binocular_visionDlg.cpp : ÊµÏÖÎÄ¼þ
//

#include "stdafx.h"
#include "Binocular_vision.h"
#include "Binocular_visionDlg.h"

#include "afxdialogex.h"



#include "opencv.h"
#include "zhaojiaodian.h"
#include "danbiaoding.h"
#include "litibiaoding.h"
#include "xiaobobianhuan.h"
#include "chubeijing.h"
#include "dianyunhecheng.h"
#include "dakaiwenjianjia.h"
#include "snake.h"

#undef max 
#undef min 
#include "dianyunxianshi.h"
#include "dianyunxiacaiyang.h"
#include "dianyunquzao.h"
#include "dianyunpeidui.h"





//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif



// ÓÃÓÚÓ¦ÓÃ³ÌÐò¡°¹ØÓÚ¡±²Ëµ¥ÏîµÄ CAboutDlg ¶Ô»°¿ò

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ¶Ô»°¿òÊý¾Ý
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Ö§³Ö

// ÊµÏÖ
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


// CBinocular_visionDlg ¶Ô»°¿ò




CBinocular_visionDlg::CBinocular_visionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBinocular_visionDlg::IDD, pParent)
	, CornerX(0)
	, CornerY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_shangeshuliang = 0;
	//  m_danbiaoding_shuchumingzi = 0;
	m_danbiaoding_shuchuming = _T("");
	m_zuocanshu = _T("");
	m_youcanshu = _T("");
	xiaobohecheng = 0;
	m_qubeijing_yuzhi = 0;
	m_qubeijing_al = 0;
	m_qubeijing_be = 0;
	m_qubeijing_ga = 0;
	m_chubeijing_zuixiao = 1500;
	m_chubeijing_zuida = 3000;
	m_xingtaixue_zuixiao = 700;
	m_xingtaixue_zuida = 2000;
	m_dianyunmingzi = _T("apoint1.pcd");
	m_shichatidu = 1.5f;
	m_mkmin = 150;
	m_mkmax = 500;
	m_mkmingzi = _T("mark1.pcd");
	m_hechengdianyunmingzi = _T("point_s.pcd");
	m_bili = 0.1f;
	CornerX=10;
	CornerY=7;

}

void CBinocular_visionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_shangeshuliang);
	DDV_MinMaxInt(pDX, m_shangeshuliang, 0, 128);
	//  DDX_Control(pDX, IDC_EDIT2, m_danbiaoding_shuchumingzi);
	DDX_Text(pDX, IDC_EDIT2, m_danbiaoding_shuchuming);
	DDX_Text(pDX, IDC_EDIT3, m_zuocanshu);
	//  DDX_Control(pDX, IDC_EDIT4, m_youcanshu);
	DDX_Text(pDX, IDC_EDIT4, m_youcanshu);
	DDX_Slider(pDX, IDC_SLIDER1, m_qubeijing_yuzhi);
	DDV_MinMaxInt(pDX, m_qubeijing_yuzhi, 0, 255);
	DDX_Control(pDX, IDC_BUTTON6, m_qubeijing_yuzhixianshi);
	DDX_Control(pDX, IDC_SLIDER1, m_chubeijing_kongshiyuzhi);
	DDX_Slider(pDX, IDC_SLIDER2, m_qubeijing_al);
	DDV_MinMaxInt(pDX, m_qubeijing_al, 0, 100);
	DDX_Control(pDX, IDC_BUTTON9, m_chubeijing_al1);
	DDX_Slider(pDX, IDC_SLIDER3, m_qubeijing_be);
	DDV_MinMaxInt(pDX, m_qubeijing_be, 0, 100);
	DDX_Control(pDX, IDC_BUTTON10, m_chubeijing_be1);
	DDX_Slider(pDX, IDC_SLIDER4, m_qubeijing_ga);
	DDV_MinMaxInt(pDX, m_qubeijing_ga, 0, 100);
	DDX_Control(pDX, IDC_BUTTON11, m_chubeijing_ga1);
	DDX_Control(pDX, IDC_SLIDER2, m_qubeijing_alkongzhi);
	DDX_Control(pDX, IDC_SLIDER3, m_chubeijing_bekongzhi);
	DDX_Control(pDX, IDC_SLIDER4, m_chubeijing_gakongzhi);
	DDX_Control(pDX, IDC_EDIT1, m_shengeshuliangkongzhi);
	DDX_Control(pDX, IDC_EDIT2, m_danbiaodingmingzi);
	DDX_Control(pDX, IDC_EDIT3, m_litibiaodingzuo);
	DDX_Control(pDX, IDC_EDIT4, m_litibiaodingyou);
	DDX_Text(pDX, IDC_EDIT5, m_chubeijing_zuixiao);
	DDV_MinMaxInt(pDX, m_chubeijing_zuixiao, 0, 10000);
	DDX_Text(pDX, IDC_EDIT6, m_chubeijing_zuida);
	DDV_MinMaxInt(pDX, m_chubeijing_zuida, 0, 10000);
	DDX_Control(pDX, IDC_EDIT5, m_chubeijing_zuixiaokongz);
	DDX_Text(pDX, IDC_EDIT7, m_xingtaixue_zuixiao);
	DDV_MinMaxInt(pDX, m_xingtaixue_zuixiao, 0, 10000);
	DDX_Text(pDX, IDC_EDIT8, m_xingtaixue_zuida);
	DDV_MinMaxInt(pDX, m_xingtaixue_zuida, 0, 10000);
	DDX_Text(pDX, IDC_EDIT12, m_dianyunmingzi);
	DDX_Text(pDX, IDC_EDIT9, m_shichatidu);
	DDV_MinMaxFloat(pDX, m_shichatidu, 0, 3);
	DDX_Text(pDX, IDC_EDIT10, m_mkmin);
	DDV_MinMaxInt(pDX, m_mkmin, 1, 10000);
	DDX_Text(pDX, IDC_EDIT11, m_mkmax);
	DDV_MinMaxInt(pDX, m_mkmax, 1, 10000);
	DDX_Text(pDX, IDC_EDIT13, m_mkmingzi);
	DDX_Text(pDX, IDC_EDIT14, m_hechengdianyunmingzi);
	DDX_Text(pDX, IDC_EDIT15, m_bili);
	DDV_MinMaxFloat(pDX, m_bili, 0, 1);
	DDX_Text(pDX, IDC_EDIT16, CornerX);
	DDX_Text(pDX, IDC_EDIT17, CornerY);
}

BEGIN_MESSAGE_MAP(CBinocular_visionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CBinocular_visionDlg::OnClicked_qipan)
	ON_BN_CLICKED(IDC_BUTTON3, &CBinocular_visionDlg::OnClicked_shange)
	ON_EN_CHANGE(IDC_EDIT1, &CBinocular_visionDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CBinocular_visionDlg::OnClicked_dantibiaoding)
	ON_BN_CLICKED(IDC_BUTTON4, &CBinocular_visionDlg::OnClicked_litibiaoding)
	ON_BN_CLICKED(IDC_BUTTON7, &CBinocular_visionDlg::OnClicked_xiaobofenjie)
	ON_BN_CLICKED(IDC_BUTTON8, &CBinocular_visionDlg::OnClicked_xiaobohecheng)
	ON_BN_CLICKED(IDC_BUTTON5, &CBinocular_visionDlg::OnClicked_chubeijing)
//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CBinocular_visionDlg::OnNMCustomdrawSlider1)
//ON_BN_CLICKED(IDC_BUTTON6, &CBinocular_visionDlg::OnClicked_chubeijing_yuzhixianshi)
//ON_NOTIFY(NM_THEMECHANGED, IDC_SLIDER1, &CBinocular_visionDlg::OnThemechanged_yuzhi)
//ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CBinocular_visionDlg::OnThumbposchanging_yuzhi)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CBinocular_visionDlg::OnCustomdraw_yizhi)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CBinocular_visionDlg::OnCustomdraw_al)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CBinocular_visionDlg::OnCustomdraw_be)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &CBinocular_visionDlg::OnCustomdraw_ga)
//ON_COMMAND(IDD_BINOCULAR_VISION_DIALOG, &CBinocular_visionDlg::OnIddBinocularVisionDialog)
//ON_UPDATE_COMMAND_UI(IDD_BINOCULAR_VISION_DIALOG, &CBinocular_visionDlg::OnUpdateIddBinocularVisionDialog)
//ON_COMMAND(IDD_BINOCULAR_VISION_DIALOG, &CBinocular_visionDlg::OnIddBinocularVisionDialog)
ON_BN_CLICKED(IDC_BUTTON12, &CBinocular_visionDlg::OnClicked_dianyunhecheng)
//ON_BN_CLICKED(IDC_BUTTON13, &CBinocular_visionDlg::OnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON13, &CBinocular_visionDlg::OnClickedButton13)
ON_BN_CLICKED(IDC_BUTTON14, &CBinocular_visionDlg::OnClicked_xiacaiyang)
ON_BN_CLICKED(IDC_BUTTON15, &CBinocular_visionDlg::OnClicked_dianyunquzao)
ON_BN_CLICKED(IDC_BUTTON17, &CBinocular_visionDlg::OnClicked_biaojidian)
ON_BN_CLICKED(IDC_BUTTON16, &CBinocular_visionDlg::OnClicked_dianyunhepeidui)
END_MESSAGE_MAP()


// CBinocular_visionDlg ÏûÏ¢´¦Àí³ÌÐò

BOOL CBinocular_visionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_chubeijing_kongshiyuzhi.SetRange(0,255);
	m_shangeshuliang=0;
	m_qubeijing_yuzhi=90;
	m_qubeijing_al=50;
	m_qubeijing_be=50;
	m_qubeijing_ga=50;

	m_shengeshuliangkongzhi.SetWindowTextW(L"0") ;
	m_danbiaodingmingzi.SetWindowTextW(L"L.yml") ;
	m_litibiaodingzuo.SetWindowTextW(L"L.yml");
	m_litibiaodingyou.SetWindowTextW(L"R.yml");
	m_chubeijing_kongshiyuzhi.SetPos (m_qubeijing_yuzhi);
	m_qubeijing_alkongzhi.SetPos (m_qubeijing_al);
	m_chubeijing_bekongzhi.SetPos (m_qubeijing_be);
	m_chubeijing_gakongzhi.SetPos (m_qubeijing_ga);

	SetCurrentDirectory(L".");//µ±Ç°¹¤×÷Ä¿Â¼
	// ½«¡°¹ØÓÚ...¡±²Ëµ¥ÏîÌí¼Óµ½ÏµÍ³²Ëµ¥ÖÐ¡£

	// IDM_ABOUTBOX ±ØÐëÔÚÏµÍ³ÃüÁî·¶Î§ÄÚ¡£
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

	// ÉèÖÃ´Ë¶Ô»°¿òµÄÍ¼±ê¡£µ±Ó¦ÓÃ³ÌÐòÖ÷´°¿Ú²»ÊÇ¶Ô»°¿òÊ±£¬¿ò¼Ü½«×Ô¶¯
	//  Ö´ÐÐ´Ë²Ù×÷
	SetIcon(m_hIcon, TRUE);			// ÉèÖÃ´óÍ¼±ê
	SetIcon(m_hIcon, FALSE);		// ÉèÖÃÐ¡Í¼±ê

	// TODO: ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯´úÂë

	return TRUE;  // ³ý·Ç½«½¹µãÉèÖÃµ½¿Ø¼þ£¬·ñÔò·µ»Ø TRUE
}

void CBinocular_visionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Èç¹ûÏò¶Ô»°¿òÌí¼Ó×îÐ¡»¯°´Å¥£¬ÔòÐèÒªÏÂÃæµÄ´úÂë
//  À´»æÖÆ¸ÃÍ¼±ê¡£¶ÔÓÚÊ¹ÓÃÎÄµµ/ÊÓÍ¼Ä£ÐÍµÄ MFC Ó¦ÓÃ³ÌÐò£¬
//  Õâ½«ÓÉ¿ò¼Ü×Ô¶¯Íê³É¡£

void CBinocular_visionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ÓÃÓÚ»æÖÆµÄÉè±¸ÉÏÏÂÎÄ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ê¹Í¼±êÔÚ¹¤×÷Çø¾ØÐÎÖÐ¾ÓÖÐ
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// »æÖÆÍ¼±ê
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//µ±ÓÃ»§ÍÏ¶¯×îÐ¡»¯´°¿ÚÊ±ÏµÍ³µ÷ÓÃ´Ëº¯ÊýÈ¡µÃ¹â±ê
//ÏÔÊ¾¡£
HCURSOR CBinocular_visionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CBinocular_visionDlg::OnClicked_qipan()
{
	
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	IplImage* image=cvCreateImage(cvSize(1280,1024),8,1);
   ///Éú³ÉºÚ°×Ìõ
   int size=1280/numx_qipan;
   for(int i=0;i<image->height;i++)
   {
      uchar* data=(uchar*)image->imageData+image->widthStep*i;
      for(int j=0;j<image->width;j++)
      {
         if((j/size)%2==1)
		 *data=0;
		 else
		 *data=255;
		 data++;
		 
      }
   }
   //Éú³ÉÆåÅÌ¸ñ
   for(int i=0;i<image->height;i++)
   {
      if((i/size)%2==1)
      {   
         uchar* data=(uchar*)image->imageData+image->widthStep*i;
         for(int j=0;j<image->width;j++)
         {
            *data=255-*data;
            data++;
         }
      }
   }
   cv::Mat img = cv::cvarrToMat(image);
   cv::namedWindow("chessboard", 1);
   cv::imshow("chessboard", img);
   char c = cv::waitKey(2000);
   if (c=='w')
   {
   cv::waitKey(0);
   }
   cv::destroyWindow("chessboard");
   cv::imwrite("chessboard.bmp", img);
}


void CBinocular_visionDlg::OnClicked_shange()
{
	UpdateData();
	IplImage* image=cvCreateImage(cvSize(1280,1024),8,1);
   ///Éú³ÉºÚ°×Ìõ
   int size;
   
   for(int i=0;i<image->height;i++)
   {
      uchar* data=(uchar*)image->imageData+image->widthStep*i;
      for(int j=0;j<image->width;j++)
      {
		  if(m_shangeshuliang==0)
            *data=0;
		  else if(m_shangeshuliang==1)
            *data=50;
		  else
		  {
		   size=1280/m_shangeshuliang;
          if((j/size)==0)
            *data=0;
		  else if ((j-size)/(size*2)%2==0)
            *data=200;
          else
			  *data=0;
		  }
         data++;
      }
   }
   cv::Mat img = cv::cvarrToMat(image);
   cv::namedWindow("grid", 1);
   
   cv::imshow("grid", img);
   
   char c = cvWaitKey(2000);
   if (c=='w')
   {
   cvWaitKey(0);
   }
   cv::destroyWindow("grid");
   int index=m_shangeshuliang;
   char  filename[100];  
   sprintf_s(filename,100,"grid%d.bmp",index);
   cv::imwrite(filename, img);
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnEnChangeEdit1()
{
	// TODO:  Èç¹û¸Ã¿Ø¼þÊÇ RICHEDIT ¿Ø¼þ£¬Ëü½«²»
	// ·¢ËÍ´ËÍ¨Öª£¬³ý·ÇÖØÐ´ CDialogEx::OnInitDialog()
	// º¯Êý²¢µ÷ÓÃ CRichEditCtrl().SetEventMask()£¬
	// Í¬Ê±½« ENM_CHANGE ±êÖ¾¡°»ò¡±ÔËËãµ½ÑÚÂëÖÐ¡£

	// TODO:  ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_dantibiaoding()
{
	/*
	
	
	CString filter=CBinocular_visionDlg::OnClickedButton13();
	
	filter="opencvÎÄ¼þ(*.xml)|*.xml|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}	*/
	UpdateData();
	/*CString m_FileDir;   
    BROWSEINFO bi;   
    ZeroMemory(&bi, sizeof(BROWSEINFO));   
    bi.hwndOwner = m_hWnd;   
    bi.ulFlags   = BIF_RETURNONLYFSDIRS;   
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   
    BOOL bRet = FALSE;   
    TCHAR szFolder[MAX_PATH*2];   
    szFolder[0] = _T('/0');   
    if (pidl)
     {   
      if (SHGetPathFromIDList(pidl, szFolder))     
         bRet = TRUE;   
      IMalloc *pMalloc = NULL;   
      if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)   
        {    
         pMalloc->Free(pidl);    
         pMalloc->Release();   
        }   
    }   
    m_FileDir = szFolder;//Ñ¡ÔñµÄÎÄ¼þ¼ÐÂ·¾¶ */
	//¶¨Òå²ÎÊý
	cv::Size boardSize, imageSize;
    float squareSize = 23.f, aspectRatio = 1.f;
    cv::Mat cameraMatrix, distCoeffs;
    const char* outputFilename =0;
    const char* inputFilename = 0;
    
    int i, nframes = 10;
    bool writeExtrinsics = false, writePoints = false;
    bool undistortImage = false;
    int flags = 0;
    cv::VideoCapture capture;
    bool flipVertical = false;
    bool showUndistorted = false;
    bool videofile = false;
    int delay = 1000;
    clock_t prevTimestamp = 0;
    int mode = DETECTION;
    int cameraId = 0;
    vector<vector<cv::Point2f> > imagePoints;
    vector<string> imageList;
	//ÆåÅÌÍ¼µÄ³ß´ç
    boardSize.width = CornerX;
	boardSize.height = CornerY;
	//squareSize = 0.025f;
	writePoints = true;
    writeExtrinsics = true;
	
	int _convert = 0;
    UINT _acp = ATL::_AtlGetConversionACP(); 
    LPCWSTR _lpw = NULL;
    LPCSTR _lpa = NULL;

	outputFilename = T2A(m_danbiaoding_shuchuming.GetBuffer());//(LPSTR)m_danbiaoding_shuchuming.GetBufferSetLength(20);
	//char  *filename;  
    //sprintf(filename,"%s",(LPSTR)(LPCTSTR)str);
	//inputFilename =(LPSTR)str.GetBuffer(sizeof(str)); //(LPSTR)(LPCTSTR)str;
	 //sprintf(inputFilename,"%s",(LPCTSTR)str);
     inputFilename="L1.xml";

	//¶ÁÈ¡ÕÕÆ¬Á´±í
	if( inputFilename )
    {
        if( !videofile && ListFolder(imageList) )
            mode = CAPTURING;
        else    
            capture.open(inputFilename);
    }
    else
        capture.open(cameraId);

	if( !imageList.empty() )
        nframes = (int)imageList.size();

	 cv::namedWindow( "calibration", 1 );

	 for(i = 0;;i++)
    {
        cv::Mat view, viewGray;
        bool blink = false;
        
        if( capture.isOpened() )
        {
            cv::Mat view0;
            capture >> view0;
            view0.copyTo(view);
        }
        else if( i < (int)imageList.size() )
            view = cv::imread(imageList[i], 1);
        
        if(!view.data)
        {
            if( imagePoints.size() > 0 )
                runAndSave(outputFilename, imagePoints, imageSize,
                           boardSize, squareSize, aspectRatio,
                           flags, cameraMatrix, distCoeffs,
                           writeExtrinsics, writePoints);
            break;
        }
        
        imageSize = view.size();

        if( flipVertical )
            flip( view, view, 0 );

        vector<cv::Point2f> pointbuf;
        cvtColor(view, viewGray, CV_BGR2GRAY); 

        bool found = findChessboardCorners( view, boardSize, pointbuf,
            CV_CALIB_CB_ADAPTIVE_THRESH & CV_CALIB_CB_FAST_CHECK & CV_CALIB_CB_NORMALIZE_IMAGE);

       // improve the found corners' coordinate accuracy
        if(found) cornerSubPix( viewGray, pointbuf, cv::Size(11,11),
            cv::Size(-1,-1), cv::TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

        if( mode == CAPTURING && found &&
           (!capture.isOpened() || clock() - prevTimestamp > delay*1e-3*CLOCKS_PER_SEC) )
        {
            imagePoints.push_back(pointbuf);
            prevTimestamp = clock();
            blink = capture.isOpened();
        }
        
        if(found)
            drawChessboardCorners( view, boardSize, cv::Mat(pointbuf), found );

        string msg = mode == CAPTURING ? "100/100" :
            mode == CALIBRATED ? "Calibrated" : "Press 'g' to start";
        int baseLine = 0;
        cv::Size textSize = cv::getTextSize(msg, 1, 1, 1, &baseLine);        
        cv::Point textOrigin(view.cols - 2*textSize.width - 10, view.rows - 2*baseLine - 10);

        if( mode == CAPTURING )
        {
            if(undistortImage)
                msg = cv::format( "%d/%d Undist", (int)imagePoints.size(), nframes );
            else
                msg = cv::format( "%d/%d", (int)imagePoints.size(), nframes );
        }

        putText( view, msg, textOrigin, 1, 1,
                 mode != CALIBRATED ? cv::Scalar(0,0,255) : cv::Scalar(0,255,0));

        if( blink )
            bitwise_not(view, view);

        if( mode == CALIBRATED && undistortImage )
        {
            cv::Mat temp = view.clone();
            undistort(temp, view, cameraMatrix, distCoeffs);
        }

        imshow("calibration", view);
        int key = 0xff & cv::waitKey(capture.isOpened() ? 50 : 500);

        if( (key & 255) == 27 )
            break;
        
        if( key == 'u' && mode == CALIBRATED )
            undistortImage = !undistortImage;

        if( capture.isOpened() && key == 'g' )
        {
            mode = CAPTURING;
            imagePoints.clear();
        }

        if( mode == CAPTURING && imagePoints.size() >= (unsigned)nframes )
        {
            if( runAndSave(outputFilename, imagePoints, imageSize,
                       boardSize, squareSize, aspectRatio,
                       flags, cameraMatrix, distCoeffs,
                       writeExtrinsics, writePoints))
                mode = CALIBRATED;
            else
                mode = DETECTION;
            if( !capture.isOpened() )
                break;
        }
    }
	if( !capture.isOpened() && showUndistorted )
    {
        cv::Mat view, rview, map1, map2;
        initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(),
                                getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
                                imageSize, CV_16SC2, map1, map2);
        
        for( i = 0; i < (int)imageList.size(); i++ )
        {
            view = cv::imread(imageList[i], 1);
            if(!view.data)
                continue;
            //undistort( view, rview, cameraMatrix, distCoeffs, cameraMatrix );
            remap(view, rview, map1, map2, cv::INTER_LINEAR);
            imshow("calibration", rview);
            int c = 0xff & cv::waitKey();
            if( (c & 255) == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }
                                                
   char c = cvWaitKey(2000);
   if (c=='w')
   {
   cvWaitKey(0);
   }
   cvDestroyWindow("calibration");

   AfxMessageBox(L"calibration_finish！"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
    
}



void CBinocular_visionDlg::OnClicked_litibiaoding()
{
	UpdateData();
	/*CString filter;
	filter="opencvÎÄ¼þ(*.xml)|*.xml|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}	*/
	/*
	CString m_FileDir;   
    BROWSEINFO bi;   
    ZeroMemory(&bi, sizeof(BROWSEINFO));   
    bi.hwndOwner = m_hWnd;   
    bi.ulFlags   = BIF_RETURNONLYFSDIRS;   
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   
    BOOL bRet = FALSE;   
    TCHAR szFolder[MAX_PATH*2];   
    szFolder[0] = _T('/0');   
    if (pidl)
     {   
      if (SHGetPathFromIDList(pidl, szFolder))     
         bRet = TRUE;   
      IMalloc *pMalloc = NULL;   
      if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)   
        {    
         pMalloc->Free(pidl);    
         pMalloc->Release();   
        }   
    }   
    m_FileDir = szFolder;//Ñ¡ÔñµÄÎÄ¼þ¼ÐÂ·¾¶ */

	cv::Size boardSize;
    string imagelistfn;
    const char*  intrinsicsFilename_l=0;
    const char*  intrinsicsFilename_r=0;
    bool showRectified = true;
    
	int _convert = 0;
    UINT _acp = ATL::_AtlGetConversionACP(); 
    LPCWSTR _lpw = NULL;
    LPCSTR _lpa = NULL;

	//imagelistfn=T2A(m_FileDir.GetBuffer());
	intrinsicsFilename_l=T2A(m_zuocanshu.GetBuffer());
    intrinsicsFilename_r=T2A(m_youcanshu.GetBuffer());
	boardSize.width=CornerX;
	boardSize.height=CornerY;

    
    if( imagelistfn == "" )
    {
        imagelistfn = "stereo_calib.xml";
		
        boardSize = cv::Size(CornerX, CornerY);
    }
    else if( boardSize.width <= 0 || boardSize.height <= 0 )
    {
        cout << "if you specified XML file with chessboards, you should also specify the board width and height (-w and -h options)" << endl; 
        
    }
    
    vector<string> imagelist;
    bool ok = ListFolder(imagelist);
    if(!ok || imagelist.empty())
    {
        cout << "can not open " << imagelistfn << " or the string list is empty" << endl;
        
    }
    
    StereoCalib(imagelist, boardSize, true, showRectified, intrinsicsFilename_l, intrinsicsFilename_r);
    AfxMessageBox(L"stereo_calibration_finish！"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_xiaobofenjie()
{
	
	int nLayer = 1;
	//string imagelistxiaobo;
	vector<string> imagelistxb;
	/*
	CString filter;
	filter="opencvÎÄ¼þ(*.xml)|*.xml|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}*/
	/*
	CString m_FileDir;   
    BROWSEINFO bi;   
    ZeroMemory(&bi, sizeof(BROWSEINFO));   
    bi.hwndOwner = m_hWnd;   
    bi.ulFlags   = BIF_RETURNONLYFSDIRS;   
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   
    BOOL bRet = FALSE;   
    TCHAR szFolder[MAX_PATH*2];   
    szFolder[0] = _T('/0');   
    if (pidl)
     {   
      if (SHGetPathFromIDList(pidl, szFolder))     
         bRet = TRUE;   
      IMalloc *pMalloc = NULL;   
      if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)   
        {    
         pMalloc->Free(pidl);    
         pMalloc->Release();   
        }   
    }   
    m_FileDir = szFolder;//Ñ¡ÔñµÄÎÄ¼þ¼ÐÂ·¾¶ */

	int _convert = 0;
    UINT _acp = ATL::_AtlGetConversionACP(); 
    LPCWSTR _lpw = NULL;
    LPCSTR _lpa = NULL;

	//imagelistxiaobo=T2A(m_FileDir.GetBuffer());

     ListFolder(imagelistxb);
	 int nimages = (int)imagelistxb.size();
	  for( int i = 0; i < nimages; i++ )//¶ÁÈ¡¶ÔÓ¦ÕÕÆ¬
	  {
		  const string& filename = imagelistxb[i];
		  IplImage *pSrc = cvLoadImage(filename.c_str() , 1);
		  CvSize size = cvGetSize(pSrc);
		  IplImage *pWavelet = cvCreateImage(size, IPL_DEPTH_32F, pSrc->nChannels);
        if (pWavelet)
        {
  
  
	 // Ð¡²¨Í¼Ïó¸³Öµ
           cvSetImageROI(pWavelet, cvRect(0, 0, pSrc->width, pSrc->height));
           cvConvertScale(pSrc, pWavelet, 1, -128);
           cvResetImageROI(pWavelet);
  
           cvNamedWindow("pWavelet",1);
           cvShowImage("pWavelet",pSrc);
  

  // ²ÊÉ«Í¼ÏñÐ¡²¨±ä»»
          IplImage *pImage = cvCreateImage(cvGetSize(pWavelet), IPL_DEPTH_32F,1);
          if (pImage)
          {
          for (int i = 1; i <= pWavelet->nChannels; i++)
          {
           cvSetImageCOI(pWavelet, i);
           cvCopy(pWavelet, pImage, NULL);

	
   // ¶þÎ¬ÀëÉ¢Ð¡²¨±ä»»
          DWT(pImage, nLayer);
   // ¶þÎ¬ÀëÉ¢Ð¡²¨»Ö¸´
          if (xiaobohecheng==1)
		  IDWT(pImage, nLayer);
		  cvCopy(pImage, pWavelet, NULL);
	      }
          cvSetImageCOI(pWavelet, 0);
          cvReleaseImage(&pImage);
          }
 


  // Ð¡²¨±ä»»Í¼Ïó
         cvSetImageROI(pWavelet, cvRect(0, 0, pSrc->width, pSrc->height));
         cvConvertScale(pWavelet, pSrc, 1, 128);
         cvResetImageROI(pWavelet); // ±¾ÐÐ´úÂëÓÐµã¶àÓà£¬µ«ÓÐÀûÓÃÑø³ÉÁ¼ºÃµÄ±à³ÌÏ°¹ß
         cvReleaseImage(&pWavelet);
          }
 // ÏÔÊ¾Í¼ÏñpSrc
        cvNamedWindow("dwt",1);
        cvShowImage("dwt",pSrc);
		if(xiaobohecheng==1)
		{
		char  filename1[1000];
	    //int index=filename.find_first_of(".");
		//string s =filename.substr(0,index);
		string s = filename.c_str();
		int index=(int)s.find_first_of(".");
		s =s.substr(0,index);
		sprintf_s(filename1,1000,"%s_a.bmp",s.c_str());
		cv::Mat img = cv::cvarrToMat(pSrc);
		cv::imwrite (filename1, img);
		}
        char c = cvWaitKey(2000);
        if (c=='w')
         {
           cvWaitKey(0);
          }
        cvDestroyWindow("dwt");
        cvDestroyWindow("pWavelet");
 // ...
        cvReleaseImage(&pSrc);
	  }
	  AfxMessageBox(L"wavelet_break"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_xiaobohecheng()
{
	xiaobohecheng=1;
	CBinocular_visionDlg::OnClicked_xiaobofenjie();
	xiaobohecheng=0;
	AfxMessageBox(L"wavelet_compound"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_chubeijing()
{
	UpdateData();
	// Read input binary image
	CString filter;
	filter="Bmp file(*.bmp)|*.bmp|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}
   else
   return;
	/*
	m_chubeijing_kongshiyuzhi.SetRange(0,255);

	m_qubeijing_yuzhi=90;
	m_qubeijing_al=50;
	m_qubeijing_be=50;
	m_qubeijing_ga=50;

	m_chubeijing_kongshiyuzhi.SetPos (m_qubeijing_yuzhi); 
	m_qubeijing_alkongzhi.SetPos (m_qubeijing_al);
	m_chubeijing_bekongzhi.SetPos (m_qubeijing_be);
	m_chubeijing_gakongzhi.SetPos (m_qubeijing_ga);
	*/
	cv::Mat image;
	
	cv::namedWindow("binary");
	while(1)
	{
	UpdateData(); 
	image= cv::imread(T2A(str.GetBuffer()),0);
	// Read input binary image
	cv::threshold(image,image,m_qubeijing_yuzhi,255,cv::THRESH_BINARY);
	
	cv::imshow("binary",image);
	cv::imwrite("binary.jpg",image);
    if (cvWaitKey(40)=='q')
        break;
	}
    cv::destroyWindow ("binary");

	std::vector<std::vector<cv::Point>> contours;
	

	cv::findContours(image, 
		contours, // a vector of contours 
		CV_RETR_EXTERNAL, // retrieve the external contours
		CV_CHAIN_APPROX_NONE); // retrieve all pixels of each contours

	// Print contours' length
	std::cout << "Contours: " << contours.size() << std::endl;
	std::vector<std::vector<cv::Point>>::const_iterator itContours= contours.begin();
	for ( ; itContours!=contours.end(); ++itContours) {

		std::cout << "Size: " << itContours->size() << std::endl;
	}
	
	int cmin= m_chubeijing_zuixiao;  // minimum contour length
	int cmax= m_chubeijing_zuida; // maximum contour length
	std::vector<std::vector<cv::Point>>::const_iterator itc= contours.begin();
	while (itc!=contours.end()) {

		if (itc->size() < cmin || itc->size() > cmax)
			itc= contours.erase(itc);
		else 
			++itc;
	}
	//cvSnakeImage(image,);
	// draw black contours on white image
	cv::Mat result=cv::imread(T2A(str.GetBuffer()),0);//(image.size(),CV_8U,cv::Scalar(0));
	cv::Mat result1(image.size(),CV_8U,3);
	cv::cvtColor (result,result1,CV_GRAY2BGR);
	cv::drawContours(result1,contours,
		-1, // draw all contours
		cv::Scalar(255,0,0), // in black
		5); // with a thickness of 2
	const cv::Mat result2=result1;
	cv::namedWindow("contour");
	cv::imshow("contour",result1);
	cv::imwrite("contour.jpg",result1);
	char c = cvWaitKey(2000);
    if (c=='w')
     {
       cvWaitKey(0);
     }
	cv::destroyWindow ("contour");

	
 
	CvSize size; 
	size.width=3; 
	size.height=3; 
	CvTermCriteria criteria; 
	criteria.type=CV_TERMCRIT_ITER; 
	criteria.max_iter=1000; 
	criteria.epsilon=0.1; 
	const IplImage* image1;
	//IplImage* image2;
	image1=&IplImage(image);
	
	//snake
	
	
	
	int length = (int)contours[0].size();	
	 
	 //·ÖÅäÂÖÀªµã
    
	
	cv::namedWindow("Snake");
	std::vector<std::vector<cv::Point>> contours1;
	while(1)
	{
	CvPoint* point = new CvPoint[length];
	for(int i=0;i<length;i++)
	point[i]=contours[0][i];
	
	result1=cv::imread("contour.jpg",1);
	UpdateData(); 

	float alpha=m_qubeijing_al/100.0f; 
	float beta=m_qubeijing_be/100.0f; 
	float gamma=m_qubeijing_ga/100.0f; 

	cvSnakeImage(image1, point, length, &alpha, &beta, &gamma, CV_VALUE, size, criteria, 1);
	
	std::vector<cv::Point> first;
	for(int i=0;i<length;i++)
	{
		first.push_back(point[i]);
	}
   
    contours1.push_back(first);
	
	cv::drawContours(result1,contours1,
		-1, // draw all contours
		cv::Scalar(0,0,255), // in black
		5); // with a thickness of 2

	cv::imshow("Snake",result1);
	//
	
	
	if (cvWaitKey(40)=='q')
        break;
	else {
		delete []point; 
		contours1.clear ();}
	}
	cv::destroyWindow ("Snake");
	// Eliminate too short or too long contours
	//string imagelistbeijing;
	vector<string> imagelistbj;

	/*CString filter1;
	filter1="opencvÎÄ¼þ(*.xml)|*.xml|";
	CFileDialog dlg1(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter1);
	CString str1;
	if(dlg1.DoModal ()==IDOK)
	{
		str1=dlg1.GetPathName();
		//AfxMessageBox(str);
	}*/
	/*
	CString m_FileDir;   
    BROWSEINFO bi;   
    ZeroMemory(&bi, sizeof(BROWSEINFO));   
    bi.hwndOwner = m_hWnd;   
    bi.ulFlags   = BIF_RETURNONLYFSDIRS;   
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   
    BOOL bRet = FALSE;   
    TCHAR szFolder[MAX_PATH*2];   
    szFolder[0] = _T('/0');   
    if (pidl)
     {   
      if (SHGetPathFromIDList(pidl, szFolder))     
         bRet = TRUE;   
      IMalloc *pMalloc = NULL;   
      if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)   
        {    
         pMalloc->Free(pidl);    
         pMalloc->Release();   
        }   
    }   
    m_FileDir = szFolder;//Ñ¡ÔñµÄÎÄ¼þ¼ÐÂ·¾¶ */

	// imagelistbeijing=T2A(m_FileDir.GetBuffer());

	 ListFolder(imagelistbj);

     
      int nimages = (int)imagelistbj.size();
	  for( int i = 0; i < nimages; i++ )//¶ÁÈ¡¶ÔÓ¦ÕÕÆ¬
	 {
		 const string& filename = imagelistbj[i];
	  // draw contours on the original image
	
	  cv::Mat original  = cv::imread(filename);
	  cv::Mat original1 = cv::imread(filename);
	  cv::drawContours(original,contours1,
		-1, // draw all contours
		cvScalarAll(255), // in white
		-1); // with a thickness of 2
	  

	 // cv::imwrite("../ob4/ob/L128t1.bmp",original); 
	  cv::threshold(original,original,254,255,cv::THRESH_BINARY_INV);
	 //cv::imwrite("../ob4/ob/L128t2.bmp",original); 
	  cv::add(original1,original,original1); //original1=original+original1;
	 // cv::imwrite("../ob4/ob/L128TEXT3",original1); 
	 //cv::threshold(original1,original1,254,255,cv::THRESH_TOZERO_INV);
	  cv::namedWindow("result");
	  cv::imshow("result",original1);
	  char c = cvWaitKey(2000);
      if (c=='w')
         {
          cvWaitKey(0);
          }
	  cv::destroyWindow("result");
	  
	  char  filename1[1000];
	  string s = filename.c_str();
	  int index= (int)s.find_first_of(".");
	  s =s.substr(0,index);
	  sprintf_s(filename1,1000,"%s_b.bmp", s.c_str());
	  cv::imwrite(filename1,original1);
	    //index=index*2;
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
     }
	  AfxMessageBox(L"remove_background"); 
}

void CBinocular_visionDlg::OnCustomdraw_yizhi(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	UpdateData(); 
    TCHAR buffer[8];
	wsprintf(buffer,_T("%d"),m_qubeijing_yuzhi);
	m_qubeijing_yuzhixianshi.SetWindowTextW (buffer) ;
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	*pResult = 0;
}


void CBinocular_visionDlg::OnCustomdraw_al(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	UpdateData(); 
	TCHAR bufferal[8];
	wsprintf(bufferal,_T("%d"),m_qubeijing_al);
	m_chubeijing_al1.SetWindowTextW (bufferal) ;
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	*pResult = 0;
}


void CBinocular_visionDlg::OnCustomdraw_be(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	UpdateData(); 
	TCHAR bufferbe[8];
	wsprintf(bufferbe,_T("%d"),m_qubeijing_be);
	m_chubeijing_be1.SetWindowTextW (bufferbe) ;

	
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	*pResult = 0;
}


void CBinocular_visionDlg::OnCustomdraw_ga(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	UpdateData(); 
	TCHAR bufferga[8];
	wsprintf(bufferga,_T("%d"),m_qubeijing_ga);
	m_chubeijing_ga1.SetWindowTextW (bufferga) ;
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	*pResult = 0;
	
}


     
     

void CBinocular_visionDlg::OnClicked_dianyunhecheng()
{
	 UpdateData(); 
	 const char* intrinsic_filename = "intrinsics.yml";
     const char* extrinsic_filename = "extrinsics.yml";
	 int k=0;
	 int k1=0;
     int color_mode = 0 ;
	  vector<string> imagelistdy;
	 if( !ListFolder( imagelistdy))
	 {
		 return;
	 }
	
	  cv::Mat original  = cv::imread(imagelistdy[0]);
	  cv::Mat img0  = cv::imread(imagelistdy[0], color_mode);
      cv::Mat img1  = cv::imread(imagelistdy[2], color_mode);
	  cv::Mat img2  = cv::imread(imagelistdy[4], color_mode);
	  cv::Mat img4  = cv::imread(imagelistdy[6], color_mode);
	  cv::Mat img8  = cv::imread(imagelistdy[8], color_mode);
	  cv::Mat img16 = cv::imread(imagelistdy[10], color_mode);
	  cv::Mat img32 = cv::imread(imagelistdy[12], color_mode);
	  cv::Mat img64 = cv::imread(imagelistdy[14], color_mode);
  
	  cv::Mat img01  = cv::imread(imagelistdy[1], color_mode);
	  cv::Mat img11  = cv::imread(imagelistdy[3], color_mode);
	  cv::Mat img21  = cv::imread(imagelistdy[5], color_mode);
	  cv::Mat img41  = cv::imread(imagelistdy[7], color_mode);
	  cv::Mat img81  = cv::imread(imagelistdy[9], color_mode);
	  cv::Mat img161 = cv::imread(imagelistdy[11], color_mode);
	  cv::Mat img321 = cv::imread(imagelistdy[13], color_mode);
	  cv::Mat img641 = cv::imread(imagelistdy[15], color_mode);

	  IplImage* imgt  = cvLoadImage(imagelistdy[8].c_str(), color_mode);
	  IplImage* imgt1 = cvLoadImage(imagelistdy[9].c_str(), color_mode);
	  IplImage* imggt  = cvLoadImage(imagelistdy[8].c_str(), color_mode);
	  IplImage* imggt1 = cvLoadImage(imagelistdy[9].c_str(), color_mode);

	  IplImage *frame_gray_0;
	  IplImage *frame_gray_1;
	  IplImage *frame_gray_2;
	  IplImage *frame_gray_4;
	  IplImage *frame_gray_8;
	  IplImage *frame_gray_16;
	  IplImage *frame_gray_32;
	  IplImage *frame_gray_64;
	  
	  
	  IplImage *frame_gray_01;
	  IplImage *frame_gray_11;
	  IplImage *frame_gray_21;
	  IplImage *frame_gray_41;
	  IplImage *frame_gray_81;
	  IplImage *frame_gray_161;
	  IplImage *frame_gray_321;
	  IplImage *frame_gray_641;


	cv::Size img_size = img0.size();
    
    cv::Rect roi1, roi2;
    cv::Mat Q;
    cv::Mat Q1;
  if( intrinsic_filename )
    {
        // reading intrinsic parameters
        cv::FileStorage fs(intrinsic_filename, CV_STORAGE_READ);
        if(!fs.isOpened())
        {
            printf("Failed to open file %s\n", intrinsic_filename);
            
        }
        
        cv::Mat M1, D1, M2, D2;
        fs["M1"] >> M1;
        fs["D1"] >> D1;
        fs["M2"] >> M2;
        fs["D2"] >> D2;
        
        fs.open(extrinsic_filename, CV_STORAGE_READ);
        if(!fs.isOpened())
        {
            printf("Failed to open file %s\n", extrinsic_filename);
            
        }
        
        cv::Mat R, T, R1, P1, R2, P2;
        fs["R"] >> R;
        fs["T"] >> T;
        fs["Q"] >> Q1;

        stereoRectify( M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q,cv::CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2 );//Á¢ÌåÐ£Õý
        
        cv::Mat map11, map12, map21, map22;
        initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);//Ð£ÕýÓ³Éä
        initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);
      //GRAyÍ¼ 
		img2=cali(img2 ,map11, map12);
		img4=cali(img4 ,map11, map12);
		img8=cali(img8 ,map11, map12);
		img16=cali(img16 ,map11, map12);
		img32=cali(img32 ,map11, map12);
		img64=cali(img64 ,map11, map12);
		img0=cali(img0 ,map11, map12);
		img1=cali(img1 ,map11, map12);

		img21=cali(img21 ,map21, map22);
		img41=cali(img41 ,map21, map22);
		img81=cali(img81 ,map21, map22);
		img161=cali(img161 ,map21, map22);
		img321=cali(img321 ,map21, map22);
		img641=cali(img641 ,map21, map22);
		img01=cali(img01 ,map21, map22);
		img11=cali(img11 ,map21, map22);

        }

//****************************
    cv::namedWindow("MyPicture");
    cv::imshow("MyPicture",img1);
    cv::waitKey(0);
    cv::destroyWindow("MyPicture");

//******************************
		frame_gray_2  = &IplImage(img2 ); 
	    frame_gray_4  = &IplImage(img4 ); 
	    frame_gray_8  = &IplImage(img8 ); 
       	frame_gray_16 = &IplImage(img16); 
	    frame_gray_32 = &IplImage(img32); 
	    frame_gray_64 = &IplImage(img64); 
	    frame_gray_0  = &IplImage(img0 ); 
		frame_gray_1  = &IplImage(img1 ); 
		 
        frame_gray_21  = &IplImage(img21 ); 
	    frame_gray_41  = &IplImage(img41 ); 
	    frame_gray_81  = &IplImage(img81 ); 
       	frame_gray_161 = &IplImage(img161); 
	    frame_gray_321 = &IplImage(img321); 
	    frame_gray_641 = &IplImage(img641); 
	    frame_gray_01  = &IplImage(img01 ); 
		frame_gray_11  = &IplImage(img11 ); 
     //grid Í¼
       
	std::cout<<"image_size:"<<frame_gray_1->depth<<";"<<frame_gray_1->height<<";"<<frame_gray_1->width<<"\n";
	int imgwidth=frame_gray_1->width;//1280
	int imgheight=frame_gray_1->height;//1024
	std::cout<<"making_grid_image\n";
    CvScalar pixel0;
	CvScalar pixel1;
	CvScalar pixel2;
	CvScalar pixel4;
	CvScalar pixel8;
	CvScalar pixel16;
    CvScalar pixel32;
	CvScalar pixel64;
    CvScalar pixelt;
	 

	CvScalar pixel01;
	CvScalar pixel11;
	CvScalar pixel21;
	CvScalar pixel41;
	CvScalar pixel81;
	CvScalar pixel161;
	CvScalar pixel321;
    CvScalar pixel641;
    CvScalar pixelt1;


	int a[7]  ={0};
	int a1[7] ={0};

	for (int i = 0; i < frame_gray_1->width; ++i)
       {
	  
        for (int j = 0; j < frame_gray_1->height; ++j)
           {   
               pixel0  = cvGet2D(frame_gray_0, j, i);
               pixel1  = cvGet2D(frame_gray_1, j, i);
               pixel01 = cvGet2D(frame_gray_01, j, i);
               pixel11 = cvGet2D(frame_gray_11, j, i);
			   b[j][i]=(pixel0.val[0]+pixel1.val[0])/2;
			   c[j][i]=(pixel01.val[0]+pixel11.val[0])/2;
			   
		   }
		}

   //gray½âÂëL

	for (int i = 0; i < frame_gray_1->width; ++i)
       {

        for (int j = 0; j < frame_gray_1->height; ++j)
           {

               pixel1 = cvGet2D(frame_gray_1, j, i);
               a[0] = pixel1.val[0];
               if(a[0]>b[j][i])
				   a[0]=1;
			   else
			       a[0]=0;
			 
			   pixel2 = cvGet2D(frame_gray_2, j, i);
               a[1]   = pixel2.val[0];

			   if(a[1]>b[j][i])
				   a[1]=1;
			   else
			       a[1]=0;

               pixel4 = cvGet2D(frame_gray_4, j, i);
               a[2] = pixel4.val[0];
			   
			   if(a[2]>b[j][i])
				   a[2]=1;//(1+a[1])%2;
			   else
			       a[2]=0;//a[1];

			   pixel8 = cvGet2D(frame_gray_8, j, i);
               a[3] = pixel8.val[0];
			   if(a[3]>b[j][i])
				   a[3]=1;
			   else
			       a[3]=0;

			   pixel16 = cvGet2D(frame_gray_16, j, i);
               a[4] = pixel16.val[0];			   
			   if(a[4]>b[j][i])
				   a[4]=1;
			   else
			       a[4]=0;

			   pixel32 = cvGet2D(frame_gray_32, j, i);
               a[5] = pixel32.val[0];			   
			   if(a[5]>b[j][i])
				   a[5]=1;
			   else
			       a[5]=0;

			   pixel64 = cvGet2D(frame_gray_64, j, i);
               a[6] = pixel64.val[0];			   
			   if(a[6]>b[j][i])
				   a[6]=1;
			   else
			       a[6]=0;

			   pixelt = cvGet2D(imgt, j, i);
  
			   b[j][i] = 128*a[0]+64*a[1]+32*a[2]+16*a[3]+8*a[4]+4*a[5]+2*a[6];

			   pixelt.val[0]=b[j][i];
		
               cvSet2D(imgt, j, i, pixelt);

			   
	//gray½âÂëR

			   pixel11 = cvGet2D(frame_gray_11, j, i);
               a1[0] = pixel11.val[0];
               if(a1[0]>c[j][i])
				   a1[0]=1;
			   else
			       a1[0]=0;
			 
			   pixel21 = cvGet2D(frame_gray_21, j, i);
               a1[1]   = pixel21.val[0];

			   if(a1[1]>c[j][i])
				   a1[1]=1;
			   else
			       a1[1]=0;

               pixel41 = cvGet2D(frame_gray_41, j, i);
               a1[2] = pixel41.val[0];
			   
			   if(a1[2]>c[j][i])
				   a1[2]=1;
			   else
			       a1[2]=0;

			   pixel81 = cvGet2D(frame_gray_81, j, i);
               a1[3] = pixel81.val[0];
			   if(a1[3]>c[j][i])
				   a1[3]=1;
			   else
			       a1[3]=0;

			   pixel161 = cvGet2D(frame_gray_161, j, i);
               a1[4] = pixel161.val[0];			   
			   if(a1[4]>c[j][i])
				   a1[4]=1;
			   else
			       a1[4]=0;

			   pixel321 = cvGet2D(frame_gray_321, j, i);
               a1[5] = pixel321.val[0];			   
			   if(a1[5]>c[j][i])
				   a1[5]=1;
			   else
			       a1[5]=0;

			   pixel641 = cvGet2D(frame_gray_641, j, i);
               a1[6] = pixel641.val[0];			   
			   if(a1[6]>c[j][i])
				   a1[6]=1;
			   else
			       a1[6]=0;

			   pixelt1 = cvGet2D(imgt1, j, i);
  
			   c[j][i] = 128*a1[0]+64*a1[1]+32*a1[2]+16*a1[3]+8*a1[4]+4*a1[5]+2*a1[6];

			   pixelt1.val[0]=c[j][i];
		
               cvSet2D(imgt1, j, i, pixelt1);
 
              
			
       }
    }

	
	//ÕûºÏÇø¼ä
    cvNormalize(imgt1, imgt1,0,255,CV_MINMAX,NULL); 
	
  	cvNormalize(imgt, imgt, 0,255,CV_MINMAX,NULL); 
	
    

	cv::Mat imgTT = cv::cvarrToMat(imgt);
	cv::Mat imgTT1 = cv::cvarrToMat(imgt1);
	cv::imwrite("grayL.bmp", imgTT);
	cv::namedWindow("imageL", 1);
	cv::imshow("imageL", imgTT);
    //cvSaveImage("grayL.bmp" , imgt);
    //cvNamedWindow("imageL", 1);
    //cvShowImage("imageL", imgt);
	cv::imwrite("grayR.bmp", imgTT1);
	cv::namedWindow("imageR", 1);
	cv::imshow("imageR", imgTT1);
    //cvSaveImage("grayR.bmp" , imgt1);
    //cvNamedWindow("imageR", 1);
    //cvShowImage("imageR", imgt1);
    
	cv::waitKey(0);
    
	cv::destroyWindow("imageL");
	cv::destroyWindow("imageR");

   


   
	//ÏàÎ»Æ¥Åä ¼«ÏÞÌáÈ¡£»

    cv::Mat image1 = cv::imread("grayL.bmp");
    cv::Mat image2 = cv::imread("grayR.bmp");


	
	//Æ¥Åä
	
	CvPoint  TEMPL;
	CvPoint  TEMPR;            //Æ¥Åäºó×ø±ê¼ÇÂ¼×ª»»µã

    vector<CvPoint> m_pointL;  //¶¨Òå¶¯Ì¬Æ¥Åäºó×ø±ê
    vector<CvPoint> m_pointR;
	vector<CvPoint3D64f> m_point3D;

	CvPoint3D64f TEMP3D;

    int mnum =0; //Æ¥ÅäµÄÊýÁ¿
	

	
	int ld=0;//ld2,ld8,ld3,ld4,ld5,ld6,ld7=0;
	int lo=0;
	int ro=0;
	int rd=0;//rd2,rd8,rd3,rd4,rd5,rd6,rd7=0;
	int lth=0;
	int rth=0;
	double chd=0;
	double chd1=0;
	double chd2=0;
    double lsu=0;
	double Zmax=0;
	double Zmin=0;
	std::cout<<"matching";
	for (int i = 0; i <  imgheight; ++i)
       {
		   if(i%100==0)
			std::cout<<".";
		   for (int j = 0; j < imgwidth; ++j)
           {
            if (j>=0&&j<=imgwidth&&i>=0&&i<=imgheight)
			{
			   //È·¶¨Ò»µã»Ò¶È
                ld=b[i][j];
			    lo=0;
				lth=0;
				if (ld!=0)
				{
				//Ñ°ÕÒ³¤¶È,ÆðÊ¼µã
                 for (int j1 = 0; j1<imgwidth; ++j1)
                    {
						if(ld == b[i][j1])
						{   
							lth++;
							//std::cout<<lth;
							if(lo == 0)
							{lo=j1;}
							
						}
				    }
				
					for (int u=0;u <= imgwidth;u++)
					{
                  
					if (u>=0&&u<imgwidth&&i>=0&&i<=imgheight)
					  {
				         rd = c[i][u];
						 ro=0;
						 rth=0;
					     if( rd==ld )
						     {
								  for (int u1 = 0; u1 < imgwidth; ++u1)
                                      {
						               if(rd == c[i][u1])
						               {  
                                            rth++;
											//std::cout<<"#";
							             if(ro == 0)
							               {ro=u1;}
							               
						                }
				                       }
								  if(lth<=rth)
								  {
								 double su = ro + (j-lo)*1.0*rth/lth;
								
								 if(su==ro)
								 {
									 chd=0;
									 lsu=0;
								 }
								//²âÊÔ
								// std::cout<<"!";
								 
								 TEMPL.x=j;
						         TEMPL.y=i;
						         m_pointL.push_back(TEMPL);
						         TEMPR.x=su;
						         TEMPR.y=i;
						         m_pointR.push_back(TEMPR);
								 
								 if(lsu!=0)
								 {
								 chd1=abs(1-su+lsu);
                                 chd2=2*chd1/(1+su-lsu);
								 chd=abs(chd2);
								 }

								 if(chd<m_shichatidu)
								 {
                                 double d = j-su;

								 image1.at<cv::Vec3b>(i,j)[0]=	0;
								 image1.at<cv::Vec3b>(i,j)[1]=	0;
                                 image1.at<cv::Vec3b>(i,j)[2]=	255;
                                 image2.at<cv::Vec3b>(i,su)[0]=	255;
								 image2.at<cv::Vec3b>(i,su)[1]=	0;
								 image2.at<cv::Vec3b>(i,su)[2]=	0;
								 
								 double c0= d * (Q1.at<double>(3,2));
								 double ts = (Q1.at<double>(2,3))/c0;
								 TEMP3D.x=j;//(j-5.9076374053955078e+002)/c0;//j*(fb*tt2-i*tt3)/(i*(r31*j+r32*i+r33*fa)-fb*(r21*j+r22*i+r23*fa));
								 TEMP3D.y=i;//(i-5.0817117691040039e+002)/c0;//i*(fb*tt2-i*tt3)/(i*(r31*j+r32*i+r33*fa)-fb*(r21*j+r22*i+r23*fa));
								 TEMP3D.z=(Q1.at<double>(2,3))/c0;//fa*(fb*tt2-i*tt3)/(i*(r31*j+r32*i+r33*fa)-fb*(r21*j+r22*i+r23*fa));
								 
								 if(Zmax == 0)
								    Zmax=TEMP3D.z;

                                 if(Zmin == 0)
								    Zmin=TEMP3D.z;

							     if(Zmax < TEMP3D.z)
								    Zmax=TEMP3D.z;

								 if(Zmin > TEMP3D.z)
								    Zmin=TEMP3D.z;

								 m_point3D.push_back(TEMP3D);
						         mnum=mnum+1;
								
								 lsu=su;
                                 break;
								 }
								 }
						     }

					  }
					}

				}
			
			}
		   }
	   }
      for (int i = 0; i <imgheight; ++i)
       {
		   if(i%100==0)
			   std::cout<<"#";
		   for (int j = 0; j <imgwidth; ++j)
           {
            if (j>=0&&j<=imgwidth&&i>=0&&i<=imgheight)
			{
			   //È·¶¨Ò»µã»Ò¶È
                ld=c[i][j];
			    lo=0;
				lth=0;
				if (ld!=0)
				{
				//Ñ°ÕÒ³¤¶È,ÆðÊ¼µã
                 for (int j1 = 0; j1 <imgwidth; ++j1)
                    {
						if(ld == c[i][j1])
						{   
							lth++;
							//std::cout<<lth;
							if(lo == 0)
							{lo=j1;}
							
						}
				    }
				
					for (int u=0;u<=imgwidth;u++)
					{
                  
					if (u>=0&&u<imgwidth&&i>=0&&i<=imgheight)
					  {
				         rd = b[i][u];
						 ro=0;
						 rth=0;
					     if( rd==ld )
						     {
								  for (int u1 = 0; u1 <imgwidth; ++u1)
                                      {
						               if(rd == b[i][u1])
						               {  
                                            rth++;
											//std::cout<<"#";
							             if(ro == 0)
							               {ro=u1;}
							               
						                }
				                       }
								  if(lth<rth)
								  {
								 double su = ro + (j-lo)*1.0*rth/lth;
                                 if(su==ro)
									 {
									 chd=0;
									 lsu=0;
								     }
								//²âÊÔ
								// std::cout<<"!";
								 
								 TEMPL.x=su;
						         TEMPL.y=i;
						         m_pointL.push_back(TEMPL);
						         TEMPR.x=j;
						         TEMPR.y=i;
						         m_pointR.push_back(TEMPR);

								 if(lsu!=0)
								 {
								 chd1=abs(1-su+lsu);
                                 chd2=2*chd1/(1+su-lsu);
								 chd=abs(chd2);
								 /*std::cout<<"chd"<<chd<<"\n";
								 std::cout<<"chd1"<<chd1<<"\n";
								 std::cout<<"chd2"<<chd2<<"\n";*/
								 }

								 if(chd<m_shichatidu)
								 {
                                 double d = su-j;
								 
								 image1.at<cv::Vec3b>(i,su)[0]=	0;
								 image1.at<cv::Vec3b>(i,su)[1]=	0;
                                 image1.at<cv::Vec3b>(i,su)[2]=	255;
                                 image2.at<cv::Vec3b>(i,j)[0]=	255;
								 image2.at<cv::Vec3b>(i,j)[1]=	0;
								 image2.at<cv::Vec3b>(i,j)[2]=	0;
								// cout<<"$$$\n";
								 double c0= d * (Q1.at<double>(3,2));
								 double ts = (Q1.at<double>(2,3))/c0;
								 TEMP3D.x=su;//(su-5.9076374053955078e+002)/c0;//j*(fb*tt2-i*tt3)/(i*(r31*j+r32*i+r33*fa)-fb*(r21*j+r22*i+r23*fa));
								 TEMP3D.y=i;//(i-5.0817117691040039e+002)/c0;//i*(fb*tt2-i*tt3)/(i*(r31*j+r32*i+r33*fa)-fb*(r21*j+r22*i+r23*fa));
								 TEMP3D.z=(Q1.at<double>(2,3))/c0;//fa*(fb*tt2-i*tt3)/(i*(r31*j+r32*i+r33*fa)-fb*(r21*j+r22*i+r23*fa));
								 
								if(Zmax < TEMP3D.z)
								    Zmax=TEMP3D.z;
 
   							    if(Zmin > TEMP3D.z)
								    Zmin=TEMP3D.z;

								 m_point3D.push_back(TEMP3D);
						         mnum=mnum+1;
								 lsu=su;
                                 break;
								 }
								 }
						     }

					  }
					}

				}
			
			}
		   }
	   }
//Ó³Éä ³ýÔë
	std::cout<<"\n"<<"Zmin: "<<Zmin<<"\n";
	std::cout<<"Zmax: "<<Zmax<<"\n";
    double ax=0 ,ay=0;   
	//if(Zmin<0)
	ax=0.0-Zmin;
	ay=1000/(Zmax-Zmin);
	std::cout<<"cZmin: "<<(Zmin+ax)*ay<<"\n";
	std::cout<<"cZmax: "<<(Zmax+ax)*ay<<"\n";

	cv::imwrite("testl.jpg" , image1);
	cv::imwrite("testr.jpg" , image2);
	
	cv::Mat imageXZ(cv::Size(1280,1024),CV_8UC3,cv::Scalar::all(255));//=cv::imread("example.jpg");
	cv::Mat imageYZ(cv::Size(1280,1024),CV_8UC3,cv::Scalar::all(255));

	cv::namedWindow("左图");
	cv::imshow("左图",image1);
	cv::namedWindow("右图");
	cv::imshow("右图",image2);
	cv::waitKey();
	cv::destroyWindow("左图");
	cv::destroyWindow("右图");

    for(int o3=0;o3<=mnum-1;o3++)
	{
		double CX, CY, CZ;

		CX = m_point3D[o3].x;
		CY = m_point3D[o3].y;
		CZ = (m_point3D[o3].z+ax)*ay;

		imageXZ.at<cv::Vec3b>(CZ,CX)[0]=0;
		imageXZ.at<cv::Vec3b>(CZ,CX)[1]=0;
        imageXZ.at<cv::Vec3b>(CZ,CX)[2]=0;

        imageYZ.at<cv::Vec3b>(CZ,CY)[0]=0;
		imageYZ.at<cv::Vec3b>(CZ,CY)[1]=0;
		imageYZ.at<cv::Vec3b>(CZ,CY)[2]=0;
	}
	
    cv::namedWindow("ImageXZ");
	cv::imshow("ImageXZ",imageXZ);
	cv::namedWindow("ImageYZ");
	cv::imshow("ImageYZ",imageYZ);
	cv::imwrite("XZ.jpg" , imageXZ);
	cv::imwrite("YZ.jpg" , imageYZ);
    cv::waitKey();
	cv::destroyWindow("ImageXZ");
	cv::destroyWindow("ImageYZ");
//·ÖË®Áë·¨
    cv::Mat imgXZB= cv::imread ("XZ.jpg",0);
	cv::Mat imageXZg = imgXZB;//WatershedsS(imageXZ,imgXZB,m_xingtaixue_zuixiao,m_xingtaixue_zuida);
	cv::Mat imgYZB= cv::imread ("YZ.jpg",0);
	cv::Mat imageYZg = WatershedsS(imageYZ,imgYZB,m_xingtaixue_zuixiao,m_xingtaixue_zuida);

//Ó³Éä ³ýÔë ½â

//µãµÄÊýÁ¿

    int mnumf =0;
	mnumf = mnum ;
	int o2;
    for(o2=0;o2<=mnum-1;o2++)
	{
		double CX1, CY1, CZ1;

		CX1 = m_point3D[o2].x;
		CY1 = m_point3D[o2].y;
		CZ1 = (m_point3D[o2].z+ax)*ay;
		

		if(imageXZg.at<uchar>(CZ1,CX1)!=0 || imageYZg.at<uchar>(CZ1,CY1)!=0)
			mnumf = mnumf -1;
	}	 

//ÊýÍêÁË
    int o4;
	FILE * fpF5=NULL;
	fopen_s(&fpF5,T2A(m_dianyunmingzi.GetBuffer()),"w+");
	fprintf(fpF5,"# .PCD v.5 - Point Cloud Data file format\t\n");
        fprintf(fpF5,"VERSION .5\t\n");
        fprintf(fpF5,"FIELDS x y z\t\n");
        fprintf(fpF5,"SIZE 4 4 4\t\n");
        fprintf(fpF5,"TYPE F F F\t\n");
        fprintf(fpF5,"COUNT 1 1 1\t\n");
        fprintf(fpF5,"WIDTH \t");
		fprintf(fpF5,"%d\t",mnumf);
		fprintf(fpF5,"\n");
        fprintf(fpF5,"HEIGHT 1\t\n");
        fprintf(fpF5,"POINTS \t");
		fprintf(fpF5,"%d\t",mnumf);
		fprintf(fpF5,"\n");
        fprintf(fpF5," DATA ascii\t\n");
	for(o4=0;o4<=mnum-1;o4++)
	{  
		
        double CX2, CY2, CZ2;

		CX2 = m_point3D[o4].x;
		CY2 = m_point3D[o4].y;
		CZ2 = (m_point3D[o4].z+ax)*ay;

		if(imageXZg.at<uchar>(CZ2,CX2)==0 && imageYZg.at<uchar>(CZ2,CY2) ==0)
		{

        CX2 = m_point3D[o4].z * ( m_point3D[o4].x+Q1.at<double>(0,3))/Q1.at<double>(2,3);
        CY2 = m_point3D[o4].z * ( m_point3D[o4].y+Q1.at<double>(1,3))/Q1.at<double>(2,3);


		fprintf(fpF5,"%f\t",CX2);
		fprintf(fpF5,"%f\t",CY2);
		fprintf(fpF5,"%f\t",m_point3D[o4].z);
		fprintf(fpF5,"\n");
		}
	}
	fclose(fpF5);//±£´æÎÄ¼þ
	AfxMessageBox(L"get point cloud"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


//CString CBinocular_visionDlg::OnClickedButton13()
//{
//	CString m_FileDir;   
//    BROWSEINFO bi;   
//    ZeroMemory(&bi, sizeof(BROWSEINFO));   
//    bi.hwndOwner = m_hWnd;   
//    bi.ulFlags   = BIF_RETURNONLYFSDIRS;   
//    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);   
//    BOOL bRet = FALSE;   
//    TCHAR szFolder[MAX_PATH*2];   
//    szFolder[0] = _T('/0');   
//    if (pidl)
//     {   
//      if (SHGetPathFromIDList(pidl, szFolder))     
//         bRet = TRUE;   
//      IMalloc *pMalloc = NULL;   
//      if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)   
//        {    
//         pMalloc->Free(pidl);    
//         pMalloc->Release();   
//        }   
//    }   
//   m_FileDir = szFolder;//Ñ¡ÔñµÄÎÄ¼þ¼ÐÂ·¾¶ 
//   return m_FileDir;
//	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
//}


void CBinocular_visionDlg::OnClickedButton13()
{
	CString filter;
	filter="pcd(*.pcd)|*.pcd|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}
   else
   return;
   const char* Filename1 ;
   Filename1 =T2A(str.GetBuffer());
   std::cout<< Filename1;
   dianyunxianshi (Filename1);
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_xiacaiyang()
{
	UpdateData();
	CString filter;
	filter="pcd(*.pcd)|*.pcd|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}
   else
   return;
   const char* Filename1 ;
   Filename1 =T2A(str.GetBuffer());
   std::cout<<"\n点云下采样\n";
   dianyunxiacaiyang (Filename1,m_bili);
   AfxMessageBox(L"完成下采样"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_dianyunquzao()
{
	 
	CString filter;
	filter="pcd(*.pcd)|*.pcd|";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	CString str;
	if(dlg.DoModal ()==IDOK)
	{
		str=dlg.GetPathName();
		//AfxMessageBox(str);
	}
   else
   return;
   const char* Filename1 ;
   Filename1 =T2A(str.GetBuffer());
   std::cout<<"\n点云去噪\n";
   //std::cout<<"pairwise_incremental_registration\r\n";
   //CreateProcess(_T("D:\\yeelou_sun\\documents\\visual_studio_2010\\Projects\\Binocular_vision\\Debug\\iterative_closest_point.exe"),_T(""),NULL,NULL,0,0,NULL,NULL,NULL,NULL);
   dianyunquzao (Filename1);
   AfxMessageBox(L"完成去噪"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_biaojidian()
{
	UpdateData(); 
	vector<string> imagelistmk;
	 if( !ListFolder( imagelistmk))
	 {
		 return;
	 }
	
	cv::Mat lmo= cv::imread (imagelistmk[0]);
	cv::Mat lmg= cv::imread (imagelistmk[0],0);
	cv::Mat rmo= cv::imread (imagelistmk[1]);
	cv::Mat rmg= cv::imread (imagelistmk[1],0);
	
	const char* intrinsic_filename = "intrinsics.yml";
    const char* extrinsic_filename = "extrinsics.yml";
	cv::Size img_size = lmo.size();
    
    cv::Rect roi1, roi2;
    cv::Mat Q;
    cv::Mat Q1;
	 cv::FileStorage fs(intrinsic_filename, CV_STORAGE_READ);
     if(!fs.isOpened())
        {
            printf("Failed to open file %s\n", intrinsic_filename);
        }
        
        cv::Mat M1, D1, M2, D2;
        fs["M1"] >> M1;
        fs["D1"] >> D1;
        fs["M2"] >> M2;
        fs["D2"] >> D2;
        
        fs.open(extrinsic_filename, CV_STORAGE_READ);
        if(!fs.isOpened())
        {
            printf("Failed to open file %s\n", extrinsic_filename);
            
        }
        
        cv::Mat R, T, R1, P1, R2, P2;
        fs["R"] >> R;
        fs["T"] >> T;
        fs["Q"] >> Q1;
		
        stereoRectify( M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q,cv::CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2 );//Á¢ÌåÐ£Õý
        
        cv::Mat map11, map12, map21, map22;
        initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);//Ð£ÕýÓ³Éä
        initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);
		lmo=cali(lmo ,map11, map12);
		lmg=cali(lmg ,map11, map12);
		rmo=cali(rmo ,map21, map22);
		rmg=cali(rmg ,map21, map22);
		
		
	std::vector<cv::Point3d> lmk;
	std::vector<cv::Point3d> rmk;
	cv::Point3d lmark[3];
	cv::Point3d rmark[3];
	cv::Point3d lt;
	cv::Point3d rt;
	lmk=markpoint(lmo,lmg,m_mkmin,m_mkmax);
	rmk=markpoint(rmo,rmg,m_mkmin,m_mkmax);
	//Æ¥Åä
	std::vector<cv::Point3d> mp;
	cv::Point3d mpp;

	
	for(int i=0; i<3 ; i++)
	{
		lmark[i]=lmk[i];
		rmark[i]=rmk[i];
	}

	
	for(int j=0;j<2;j++)
	 {
     for(int i=0;i<2-j;i++)
	 {  
      if(lmark[i].z>lmark[i+1].z)
      {
      lt=lmark[i];
      lmark[i]=lmark[i+1];
      lmark[i+1]=lt;
	  } 

	 if(rmark[i].z>rmark[i+1].z)
      {
      rt=rmark[i];
      rmark[i]=rmark[i+1];
      rmark[i+1]=rt;
	  }
	 }
	}
	  for(int i=0;i<3;i++)
	  {
		
		 	  std::cout<<"l"<<i<<",mark point="<<lmark[i].z<<";r"<<i<<",mark point="<<rmark[i].z<<"\n"	;
			 
			  double d = lmark[i].x-rmark[i].x;
			  double c0= d * (Q1.at<double>(3,2));
						//ÀûÓÃÍ¶Ó°ÏµÊý¼ÆËãÈýÎ¬×ø±ê
			  mpp.x=(lmark[i].x+Q1.at<double>(0,3))/c0;
			  mpp.y=(lmark[i].y+Q1.at<double>(1,3))/c0;
			  mpp.z=(Q1.at<double>(2,3))/c0;
			  
			  mp.push_back(mpp);
		

	  }
	//ok for Æ¥Åä
	
	FILE * fpF5 = NULL;
	fopen_s(&fpF5,T2A(m_mkmingzi.GetBuffer()),"w+");
	fprintf(fpF5,"# .PCD v.5 - Point Cloud Data file format\t\n");
    fprintf(fpF5,"VERSION .5\t\n");
    fprintf(fpF5,"FIELDS x y z\t\n");
    fprintf(fpF5,"SIZE 4 4 4\t\n");
    fprintf(fpF5,"TYPE F F F\t\n");
    fprintf(fpF5,"COUNT 1 1 1\t\n");
    fprintf(fpF5,"WIDTH \t");
	fprintf(fpF5,"%d\t",3);
	fprintf(fpF5,"\n");
    fprintf(fpF5,"HEIGHT 1\t\n");
    fprintf(fpF5,"POINTS \t");
	fprintf(fpF5,"%d\t",3);
	fprintf(fpF5,"\n");
    fprintf(fpF5," DATA ascii\t\n");

	for(int o=0;o<3;o++)
	{  
		fprintf(fpF5,"%f\t",mp[o].x);
		fprintf(fpF5,"%f\t",mp[o].y);
		fprintf(fpF5,"%f\t",mp[o].z);
		fprintf(fpF5,"\n");
		
	}
	fclose(fpF5);//±£´æÎÄ¼þ
	AfxMessageBox(L"mark point finished"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CBinocular_visionDlg::OnClicked_dianyunhepeidui()
{
    UpdateData(); 
	vector<string> imagelistpd;
	if( !ListFolder( imagelistpd))
	    return;
	 
	std::cout<<"start registraion\n";
	if(dianyunpeidui(imagelistpd,m_hechengdianyunmingzi)==1)
	    return;

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ing (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_outg (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out2 (new pcl::PointCloud<pcl::PointXYZ>);
	
	pcl::io::loadPCDFile<pcl::PointXYZ> ("change.pcd", *cloud_in);
	pcl::io::loadPCDFile<pcl::PointXYZ> (imagelistpd[1], *cloud_out);
	pcl::VoxelGrid<pcl::PointXYZ> grid;
 
    grid.setLeafSize (0.5, 0.5, 0.7);
    grid.setInputCloud (cloud_in);
    grid.filter (*cloud_ing);

    grid.setInputCloud (cloud_out);
    grid.filter (*cloud_outg);

  Eigen::Matrix4f Ti = Eigen::Matrix4f::Identity () , targetToSource;
  pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
  icp.setTransformationEpsilon (1e-6);
  icp.setMaxCorrespondenceDistance (10); 
  icp.setMaximumIterations (2);
  icp.setInputCloud(cloud_ing);
  icp.setInputTarget(cloud_outg);
  pcl::PointCloud<pcl::PointXYZ> Final;
  icp.align(Final);
  std::cout << "has converged:" << icp.hasConverged() << " score: " <<
  icp.getFitnessScore() << std::endl;
  std::cout << icp.getFinalTransformation() << std::endl;
  Ti=icp.getFinalTransformation();
  targetToSource = Ti.inverse();

  pcl::transformPointCloud (*cloud_out, *cloud_out2, targetToSource);
  int _convert = 0;
  UINT _acp = ATL::_AtlGetConversionACP(); 
  LPCWSTR _lpw = NULL;
  LPCSTR _lpa = NULL;

  *cloud_out2 += *cloud_in;
  

  pcl::io::savePCDFileASCII(T2A(m_hechengdianyunmingzi.GetBuffer()), *cloud_out2);
  

  AfxMessageBox(L"registraion finished"); 
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	
}

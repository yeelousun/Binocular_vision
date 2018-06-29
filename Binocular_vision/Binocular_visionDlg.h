
// Binocular_visionDlg.h : 头文件
//

#pragma once


// CBinocular_visionDlg 对话框
class CBinocular_visionDlg : public CDialogEx
{
// 构造
public:
	CBinocular_visionDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BINOCULAR_VISION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClicked_qipan();
	int m_shangeshuliang;
	afx_msg void OnClicked_shange();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnClicked_dantibiaoding();
//	afx_msg void OnClicked_dianbiaoding_shuoming();
//	CEdit m_danbiaoding_shuchumingzi;
//	char m_danbiaoding_shuchumingzi;
	CString m_danbiaoding_shuchuming;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnClicked_litibiaoding();
	CString m_zuocanshu;
//	CEdit m_youcanshu;
	CString m_youcanshu;
	afx_msg void OnClicked_xiaobofenjie();
	afx_msg void OnClicked_xiaobohecheng();
	int xiaobohecheng;
	afx_msg void OnClicked_chubeijing();
	int m_qubeijing_yuzhi;
//	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_qubeijing_yuzhixianshi;
//	afx_msg void OnClicked_chubeijing_yuzhixianshi();
	CSliderCtrl m_chubeijing_kongshiyuzhi;
	int m_qubeijing_al;
	CButton m_chubeijing_al1;
	int m_qubeijing_be;
	CButton m_chubeijing_be1;
	int m_qubeijing_ga;
	CButton m_chubeijing_ga1;
	CSliderCtrl m_qubeijing_alkongzhi;
	CSliderCtrl m_chubeijing_bekongzhi;
	CSliderCtrl m_chubeijing_gakongzhi;
//	afx_msg void OnThemechanged_yuzhi(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnThumbposchanging_yuzhi(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCustomdraw_yizhi(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCustomdraw_al(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCustomdraw_be(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCustomdraw_ga(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnIddBinocularVisionDialog();
//	afx_msg void OnUpdateIddBinocularVisionDialog(CCmdUI *pCmdUI);
//	afx_msg void OnIddBinocularVisionDialog();
	afx_msg void OnClicked_dianyunhecheng();
//	afx_msg CString OnClickedButton13();
	afx_msg void OnClickedButton13();
	CEdit m_shengeshuliangkongzhi;
	CEdit m_danbiaodingmingzi;
	CEdit m_litibiaodingzuo;
	CEdit m_litibiaodingyou;
	int m_chubeijing_zuixiao;
	int m_chubeijing_zuida;
	CEdit m_chubeijing_zuixiaokongz;
	int m_xingtaixue_zuixiao;
	int m_xingtaixue_zuida;
	CString m_dianyunmingzi;
	float m_shichatidu;
	afx_msg void OnClicked_xiacaiyang();
	afx_msg void OnClicked_dianyunquzao();
	afx_msg void OnClicked_biaojidian();
	int m_mkmin;
	int m_mkmax;
	CString m_mkmingzi;
	afx_msg void OnClicked_dianyunhepeidui();
	CString m_hechengdianyunmingzi;
	float m_bili;
	int CornerX;
	int CornerY;
};
		
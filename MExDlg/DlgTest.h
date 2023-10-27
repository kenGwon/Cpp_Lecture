#pragma once
#include "afxdialogex.h"


// CDlgTest 대화 상자

class CDlgTest : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTest)

public:
	CDlgTest(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	BOOL OnInitDialog();
	virtual ~CDlgTest();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIGTEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	BOOL m_bCheckButton;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CString m_strEdit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnSelchangeCombo1();
	CListBox m_ListBox;
	afx_msg void OnSelchangeList1();
	CComboBox m_ComboBox;
	CSliderCtrl m_SlideCtrl;
	afx_msg void OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl m_SlideCtrl2;
	CSliderCtrl m_SlideCtrl3;
	afx_msg void OnCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult);



private:
	CImage m_image; // cimage 변수 생성

public:
	BOOL CImageLoadExamDlg(CWnd* pParent = nullptr);
};

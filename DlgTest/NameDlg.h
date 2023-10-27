#pragma once
#include "afxdialogex.h"


// CNameDlg 대화 상자

class CNameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNameDlg)

public:
	CNameDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CNameDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString get_m_strName();
	int get_m_nAge();

	void set_m_strName(CString name);
	void set_m_nAge(int age);

private:
	CString m_strName;
	int m_nAge;

public:
	BOOL m_bLicense;
	int m_nJob;
	int m_nResidence;
	int m_nTestNum;
	
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEdit3();
};

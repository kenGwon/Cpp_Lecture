// NameDlg.cpp: 구현 파일
//

#include "pch.h"
#include "DlgTest.h"
#include "afxdialogex.h"
#include "NameDlg.h"


// CNameDlg 대화 상자

IMPLEMENT_DYNAMIC(CNameDlg, CDialogEx)

CNameDlg::CNameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strName(_T(""))
	, m_nAge(0)
	, m_bLicense(FALSE)
	, m_nJob(0)
	, m_nResidence(0)
	, m_nTestNum(0)
{

}

CNameDlg::~CNameDlg()
{
}

void CNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDV_MaxChars(pDX, m_strName, 10);
	DDX_Text(pDX, IDC_EDIT2, m_nAge);
	DDV_MinMaxInt(pDX, m_nAge, 0, 100);
	DDX_Check(pDX, IDC_CHECK1, m_bLicense);
	DDX_Radio(pDX, IDC_RADIO1, m_nJob);
	DDX_Radio(pDX, IDC_RADIO5, m_nResidence);
	DDX_Text(pDX, IDC_EDIT3, m_nTestNum);
	DDV_MinMaxInt(pDX, m_nTestNum, 0, 100);
}

CString CNameDlg::get_m_strName() {
	return this->m_strName;
}
int CNameDlg::get_m_nAge() {
	return this->m_nAge;
}

void CNameDlg::set_m_strName(CString name) {
	this->m_strName = name;
}
void CNameDlg::set_m_nAge(int age) {
	this->m_nAge = age;
}







BEGIN_MESSAGE_MAP(CNameDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CNameDlg::OnDeltaposSpin1)
	ON_EN_CHANGE(IDC_EDIT3, &CNameDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


void CNameDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CNameDlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

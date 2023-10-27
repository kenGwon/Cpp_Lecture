// DlgTest.cpp: 구현 파일
//

#include "pch.h"
#include "MExDlg.h"
#include "afxdialogex.h"
#include "DlgTest.h"


// CDlgTest 대화 상자

IMPLEMENT_DYNAMIC(CDlgTest, CDialogEx)

CDlgTest::CDlgTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIGTEST, pParent)
	, m_bCheckButton(FALSE)
	, m_strEdit(_T(""))
	//, m_strEdit(_T("Hello everyone!! this is from 생성자"))
{

}

CDlgTest::~CDlgTest()
{
}

void CDlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bCheckButton);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Control(pDX, IDC_SLIDER1, m_SlideCtrl);
	DDX_Control(pDX, IDC_SLIDER2, m_SlideCtrl2);
	DDX_Control(pDX, IDC_SLIDER3, m_SlideCtrl3);
}


BEGIN_MESSAGE_MAP(CDlgTest, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CDlgTest::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTest::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgTest::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgTest::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgTest::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgTest::OnSelchangeCombo1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDlgTest::OnSelchangeList1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CDlgTest::OnCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CDlgTest::OnCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CDlgTest::OnCustomdrawSlider3)
END_MESSAGE_MAP()


// CDlgTest 메시지 처리기


void CDlgTest::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString message;
	message.Format(_T("Check button press value:%d"), m_bCheckButton);
	AfxMessageBox(message);
	//UpdateData(FALSE); 
}


void CDlgTest::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	//AfxMessageBox(_T("Button 1 Press"));
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0); // x y 0,0 기준으로 그림이 그려진다.
}


void CDlgTest::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("Radio Button 1 Press"));
}


void CDlgTest::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("Radio Button 2 Press"));
}


void CDlgTest::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

/*
  부모클래스에 가상함수 인터페이스로 존재하는 OnInitDialog()를 오버라이딩 하여, 자식클래스인 CDlgTest에서 재정의해주었다.
  생성자에서 초기화 하는 방법도 있고, 이렇게 부모 클래스의 인터페이스 함수를 오버라이딩 하여 초기화 하는 방법도 있다는 것이다.
*/
BOOL CDlgTest::OnInitDialog()
{
	// TODO: 여기에 구현 코드 추가.

	CDialog::OnInitDialog(); // 오버라이딩으로 함수 호출하는데 명시적으로 앞에서 선언해줬다. 없어도 돌아가긴 하더라.
	m_strEdit = _T("Hello Everyone!! 이거는 OnInitDialog()함수로 생성된 문자열입니다.");
	UpdateData(FALSE);

	CString data;
	for (int i = 1; i < 11; i++)
	{
		data.Format(_T("List data%d"), i);
		m_ListBox.AddString(data);
		data.Format(_T("Combo data%d"), i);
		m_ComboBox.AddString(data);
	}

	// 년월일 초기화
	m_SlideCtrl.SetRange(2000, 2300, TRUE);
	m_SlideCtrl.SetPos(2023);
	m_SlideCtrl2.SetRange(1, 12, TRUE);
	m_SlideCtrl2.SetPos(3);
	m_SlideCtrl3.SetRange(0, 31, TRUE);
	m_SlideCtrl3.SetPos(27);

	//m_image.Load(L"Lenna.bmp");

	return TRUE;
}


void CDlgTest::OnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int num = m_ComboBox.GetCurSel();
	CString data;
	m_ComboBox.GetLBText(num, data); // 리스트박스에서는 GetText()함수를 썼는데, 콤보박스에서는 GetLBText()함수를 썼다.
	AfxMessageBox(data);
}


void CDlgTest::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int num = m_ListBox.GetCurSel();// 리스트 박스에서 현재 커서가 위치한 인덱스를 리턴 Search the current position
	CString data;
	m_ListBox.GetText(num, data);//get character at select position
	AfxMessageBox(data);//output message box
}


void CDlgTest::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	int position;
	position = m_SlideCtrl.GetPos();
	SetDlgItemInt(IDC_EDIT2, position);
	
	*pResult = 0;
}


void CDlgTest::OnCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int position;
	position = m_SlideCtrl2.GetPos();
	SetDlgItemInt(IDC_EDIT3, position);

	*pResult = 0;
}


void CDlgTest::OnCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int position;
	position = m_SlideCtrl3.GetPos();
	SetDlgItemInt(IDC_EDIT4, position);

	*pResult = 0;
}

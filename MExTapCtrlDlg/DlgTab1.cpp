﻿// DlgTab1.cpp: 구현 파일
//

#include "pch.h"
#include "MExTapCtrlDlg.h"
#include "afxdialogex.h"
#include "DlgTab1.h"


// CDlgTab1 대화 상자

IMPLEMENT_DYNAMIC(CDlgTab1, CDialogEx)

CDlgTab1::CDlgTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TAB1, pParent)
{

}

CDlgTab1::~CDlgTab1()
{
}

void CDlgTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTab1, CDialogEx)
END_MESSAGE_MAP()


// CDlgTab1 메시지 처리기

// DlgRectangulo.cpp: archivo de implementación
//

#include "pch.h"
#include "AppSimulacro.h"
#include "afxdialogex.h"
#include "DlgRectangulo.h"


// Cuadro de diálogo de DlgRectangulo

IMPLEMENT_DYNAMIC(DlgRectangulo, CDialogEx)

DlgRectangulo::DlgRectangulo(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_DLG_RECTANGULO, pParent)
	, vX1(0)
	, vY1(0)
	, vX2(0)
	, vY2(0)
{

}

DlgRectangulo::~DlgRectangulo()
{
}

void DlgRectangulo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_X1, vX1);
	DDX_Text(pDX, IDC_EDT_Y1, vY1);
	DDX_Text(pDX, IDC_EDT_X2, vX2);
	DDX_Text(pDX, IDC_EDT_Y2, vY2);
}


BEGIN_MESSAGE_MAP(DlgRectangulo, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_GRAFICAR, &DlgRectangulo::OnBnClickedBtnGraficar)
END_MESSAGE_MAP()


// Controladores de mensajes de DlgRectangulo


void DlgRectangulo::OnBnClickedBtnGraficar()
{
	CClientDC p(this);
	//p.Rectangle(20, 20, 100, 100);
	//p.Rectangle(-10, 130, 100, 200); // Se pierde parte del rectangulo
	//p.Rectangle(20, -1, 40, 18);
	//p.Rectangle(50, 50, 200, 100);
	//p.Ellipse(50, 50, 200, 100);
	//p.MoveTo(50, 50);
	//p.LineTo(200, 100);
	UpdateData(true);
	p.Rectangle(vX1, vY1, vX2, vY2);
	UpdateData(false);
}

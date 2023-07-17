// DlgCuadrante.cpp: archivo de implementación
//

#include "pch.h"
#include "AppSimulacro.h"
#include "afxdialogex.h"
#include "DlgCuadrante.h"


// Cuadro de diálogo de DlgCuadrante

IMPLEMENT_DYNAMIC(DlgCuadrante, CDialogEx)

DlgCuadrante::DlgCuadrante(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_DLG_RECTANGULO_1, pParent)
	, vCuadrante(0)
{

}

DlgCuadrante::~DlgCuadrante()
{
}

void DlgCuadrante::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_CUADRANTE, vCuadrante);
}


BEGIN_MESSAGE_MAP(DlgCuadrante, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_GRAFICAR, &DlgCuadrante::OnBnClickedBtnGraficar)
	ON_BN_CLICKED(IDC_BTN_LIMPIAR, &DlgCuadrante::OnBnClickedBtnLimpiar)
END_MESSAGE_MAP()


// Controladores de mensajes de DlgCuadrante


void DlgCuadrante::OnBnClickedBtnGraficar()
{
	UpdateData(true);
	CClientDC p(this);
	CRect rect;
	GetClientRect(rect);
	int cx = (rect.right - rect.left);
	int cy = (rect.bottom - rect.top);
	p.SetMapMode(MM_ISOTROPIC);
	p.SetViewportOrg(cx / 2, cy / 2);//coordenadas fisicas
	p.SetViewportExt(cx, cy);
	p.SetWindowOrg(0, 0);//Coordenadas lógicas
	p.SetWindowExt(2000, -1000);

	p.MoveTo(-1000, 0);
	p.LineTo(1000, 0);
	p.MoveTo(0, -2000);
	p.LineTo(0, 2000);

	switch (vCuadrante) {
	case 1: p.Rectangle(20, 20, 100, 100); break;
	case 2: p.Rectangle(-20, 20, -100, 100); break;
	case 3: p.Rectangle(-20, -20, -100, -100); break;
	case 4: p.Rectangle(20, -20, 100, -100); break;
	}
	
	UpdateData(false);
}


void DlgCuadrante::OnBnClickedBtnLimpiar()
{
	UpdateData(true);
	CClientDC p(this);
	p.DeleteDC();
	UpdateData(false);
}

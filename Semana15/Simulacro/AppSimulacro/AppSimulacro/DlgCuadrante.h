#pragma once
#include "afxdialogex.h"


// Cuadro de diálogo de DlgCuadrante

class DlgCuadrante : public CDialogEx
{
	DECLARE_DYNAMIC(DlgCuadrante)

public:
	DlgCuadrante(CWnd* pParent = nullptr);   // Constructor estándar
	virtual ~DlgCuadrante();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_RECTANGULO_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int vCuadrante;
	afx_msg void OnBnClickedBtnGraficar();
	afx_msg void OnBnClickedBtnLimpiar();
};

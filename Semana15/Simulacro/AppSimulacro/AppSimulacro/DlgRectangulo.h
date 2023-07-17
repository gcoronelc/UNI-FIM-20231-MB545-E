#pragma once
#include "afxdialogex.h"


// Cuadro de diálogo de DlgRectangulo

class DlgRectangulo : public CDialogEx
{
	DECLARE_DYNAMIC(DlgRectangulo)

public:
	DlgRectangulo(CWnd* pParent = nullptr);   // Constructor estándar
	virtual ~DlgRectangulo();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_RECTANGULO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnGraficar();
//	CString pX1;
	int vX1;
	int vY1;
	int vX2;
	int vY2;
};

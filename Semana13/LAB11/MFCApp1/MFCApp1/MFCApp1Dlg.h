
// MFCApp1Dlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCApp1Dlg
class CMFCApp1Dlg : public CDialogEx
{
// Construcción
public:
	CMFCApp1Dlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int numero1;
	int numero2;
	int suma;
	int resta;
	CButton btnProcesar;
	CButton btnLimpiar;
	CButton btnSalir;
	afx_msg void OnBnClickedBtnProcesar();
	afx_msg void OnBnClickedBtnLimpiar();
};

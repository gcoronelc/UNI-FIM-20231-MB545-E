
// MFCProyecto1Dlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCProyecto1Dlg
class CMFCProyecto1Dlg : public CDialogEx
{
// Construcción
public:
	CMFCProyecto1Dlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROYECTO1_DIALOG };
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
	afx_msg void OnBnClickedBtnProcesar();
	float importe;
	float impuesto;
	float precio;
	float total;
	int cantidad;
};

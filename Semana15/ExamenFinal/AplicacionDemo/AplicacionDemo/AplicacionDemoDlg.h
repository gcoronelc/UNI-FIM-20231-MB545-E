
// AplicacionDemoDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CAplicacionDemoDlg
class CAplicacionDemoDlg : public CDialogEx
{
// Construcción
public:
	CAplicacionDemoDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APLICACIONDEMO_DIALOG };
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
	float temperatura;
	CComboBox unidadOrigen;
	BOOL chkCel;
	BOOL chkFah;
	BOOL chkKel;
	BOOL chkRan;
	afx_msg void OnBnClickedBtnProcesar();
	CString resultado;
};

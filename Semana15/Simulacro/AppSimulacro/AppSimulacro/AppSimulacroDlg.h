
// AppSimulacroDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CAppSimulacroDlg
class CAppSimulacroDlg : public CDialogEx
{
// Construcción
public:
	CAppSimulacroDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPSIMULACRO_DIALOG };
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
	afx_msg void OnBnClickedBtnRectangulo();
	afx_msg void OnBnClickedBtnCuadrante();
};

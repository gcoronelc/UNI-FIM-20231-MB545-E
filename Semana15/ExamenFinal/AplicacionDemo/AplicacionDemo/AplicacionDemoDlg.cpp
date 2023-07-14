
// AplicacionDemoDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "AplicacionDemo.h"
#include "AplicacionDemoDlg.h"
#include "afxdialogex.h"
#include "Logica.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CAplicacionDemoDlg



CAplicacionDemoDlg::CAplicacionDemoDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_APLICACIONDEMO_DIALOG, pParent)
	, temperatura(0)
	, chkCel(FALSE)
	, chkFah(FALSE)
	, chkKel(FALSE)
	, chkRan(FALSE)
	, resultado(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAplicacionDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_TEMPERATURA, temperatura);
	DDX_Control(pDX, IDC_CBO_UNI_ORIGEN, unidadOrigen);
	DDX_Check(pDX, IDC_CHK_CEL, chkCel);
	DDX_Check(pDX, IDC_CHK_FAH, chkFah);
	DDX_Check(pDX, IDC_CHK_KEL, chkKel);
	DDX_Check(pDX, IDC_CHK_RAN, chkRan);
	DDX_Text(pDX, IDC_EDT_RESULTADO, resultado);
}

BEGIN_MESSAGE_MAP(CAplicacionDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_PROCESAR, &CAplicacionDemoDlg::OnBnClickedBtnProcesar)
END_MESSAGE_MAP()


// Controladores de mensajes de CAplicacionDemoDlg

BOOL CAplicacionDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CAplicacionDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CAplicacionDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CAplicacionDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAplicacionDemoDlg::OnBnClickedBtnProcesar()
{
	UpdateData(true);
	resultado.Empty();
	float valorConv = 0.0;
	CString dato;

	// Destino es Celsius
	if (chkCel) {
		switch (unidadOrigen.GetCurSel()) {
		case 0: valorConv = temperatura; break;
		case 1: valorConv = CLogica::convertir(FTOC, temperatura); break;
		case 2: valorConv = CLogica::convertir(KTOC, temperatura); break;
		case 3: valorConv = CLogica::convertir(RTOC, temperatura); break;
		}
		dato.Format(_T("%.2f C"), valorConv);
		resultado.Append(dato);
	}

	// Destino es Fahrenheit
	if (chkFah) {
		switch (unidadOrigen.GetCurSel()) {
		case 0: valorConv = CLogica::convertir(CTOF, temperatura); break;
		case 1: valorConv = temperatura; break; 
		case 2: valorConv = CLogica::convertir(KTOF, temperatura); break;
		case 3: valorConv = CLogica::convertir(RTOF, temperatura); break;
		}
		dato.Format(_T(" %.2f F"), valorConv);
		resultado.Append(dato);
	}

	// Destino es Kelvin
	if (chkKel) {
		switch (unidadOrigen.GetCurSel()) {
		case 0: valorConv = CLogica::convertir(CTOK, temperatura); break;
		case 1: valorConv = CLogica::convertir(FTOK, temperatura); break;
		case 2: valorConv = temperatura; break; 
		case 3: valorConv = CLogica::convertir(RTOK, temperatura); break;
		}
		dato.Format(_T(" %.2f K"), valorConv);
		resultado.Append(dato);
	}

	// Destino es Rankine
	if (chkRan) {
		switch (unidadOrigen.GetCurSel()) {
		case 0: valorConv = CLogica::convertir(CTOR, temperatura); break;
		case 1: valorConv = CLogica::convertir(FTOR, temperatura); break;
		case 2: valorConv = CLogica::convertir(KTOR, temperatura); break; 
		case 3: valorConv = temperatura; break;
		}
		dato.Format(_T(" %.2f R"), valorConv);
		resultado.Append(dato);
	}

	UpdateData(false);
}

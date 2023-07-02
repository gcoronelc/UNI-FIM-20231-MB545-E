
// MFCProyecto1.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CMFCProyecto1App:
// Consulte MFCProyecto1.cpp para obtener información sobre la implementación de esta clase
//

class CMFCProyecto1App : public CWinApp
{
public:
	CMFCProyecto1App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CMFCProyecto1App theApp;

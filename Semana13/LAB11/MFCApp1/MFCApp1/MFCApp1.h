
// MFCApp1.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CMFCApp1App:
// Consulte MFCApp1.cpp para obtener información sobre la implementación de esta clase
//

class CMFCApp1App : public CWinApp
{
public:
	CMFCApp1App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CMFCApp1App theApp;

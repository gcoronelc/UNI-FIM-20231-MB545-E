#pragma once


// Tipos de Conversion
enum TConv {
	CTOF, CTOK, CTOR,
	FTOC, FTOK, FTOR,
	KTOC, KTOF, KTOR,
	RTOC, RTOF, RTOK,
};

// Clase de la logica
class CLogica {

private:

	// Constructor privado para que no se 
	// pueda instanciar la clase.
	CLogica() {
	}

public:

	static float convertir(TConv tipo, float valor) {
		float resultado = 0.0;
		switch (tipo) {
		case CTOF: resultado = valor * 9 / 5 + 32; break;
		case CTOK: resultado = 2; break;
		case CTOR: resultado = 3; break;
		case FTOC: resultado = 4; break;
		case FTOK: resultado = 5; break;
		case FTOR: resultado = 6; break;
		case KTOC: resultado = 7; break;
		case KTOF: resultado = 8; break;
		case KTOR: resultado = 9; break;
		case RTOC: resultado = 10; break;
		case RTOF: resultado = 11; break;
		case RTOK: resultado = 12; break;
		}
		return resultado;
	}

};



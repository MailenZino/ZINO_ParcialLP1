///////////////////////////////////////////////////////////
//  cElite.h
//  Implementation of the Class cElite
//  Created on:      11-jun.-2021 09:52:33
//  Original author: maile
///////////////////////////////////////////////////////////

#if !defined(EA_9B0ABABE_F6D8_4bf4_9D79_D71A1BCDAEB2__INCLUDED_)
#define EA_9B0ABABE_F6D8_4bf4_9D79_D71A1BCDAEB2__INCLUDED_

#include "cMonstruo.h"

class cElite : public cMonstruo
{

public:
	cElite();
	virtual ~cElite();

	void Atacar(cPersona* Victima);

private:
	int Fuerza;
	int Inteligencia;
	int ProbabilidadGolpe;

};
#endif // !defined(EA_9B0ABABE_F6D8_4bf4_9D79_D71A1BCDAEB2__INCLUDED_)

///////////////////////////////////////////////////////////
//  cJefe.h
//  Implementation of the Class cJefe
//  Created on:      11-jun.-2021 09:52:34
//  Original author: maile
///////////////////////////////////////////////////////////

#if !defined(EA_B6E245B7_F99B_40f6_B0D5_3D8BAD83370C__INCLUDED_)
#define EA_B6E245B7_F99B_40f6_B0D5_3D8BAD83370C__INCLUDED_

#include "cMonstruo.h"

class cJefe : public cMonstruo
{

public:
	cJefe();
	virtual ~cJefe();

	void Atacar(cPersona* Victima);

protected:
	void RecibirDanio(int Danio);

private:
	int Fuerza;
	int Inteligencia;
	int ProbabilidadCritico;

};
#endif // !defined(EA_B6E245B7_F99B_40f6_B0D5_3D8BAD83370C__INCLUDED_)

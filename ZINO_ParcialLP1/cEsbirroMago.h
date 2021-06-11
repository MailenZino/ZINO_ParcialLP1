///////////////////////////////////////////////////////////
//  cEsbirroMago.h
//  Implementation of the Class cEsbirroMago
//  Created on:      11-jun.-2021 09:52:34
//  Original author: maile
///////////////////////////////////////////////////////////

#if !defined(EA_4B9D7B38_7F7E_433d_BD61_BAFA738BA302__INCLUDED_)
#define EA_4B9D7B38_7F7E_433d_BD61_BAFA738BA302__INCLUDED_

#include "cMonstruo.h"

class cEsbirroMago : public cMonstruo
{

public:
	cEsbirroMago();
	virtual ~cEsbirroMago();

	void Atacar(cPersona* Victima);

private:
	int Inteligencia;

};
#endif // !defined(EA_4B9D7B38_7F7E_433d_BD61_BAFA738BA302__INCLUDED_)

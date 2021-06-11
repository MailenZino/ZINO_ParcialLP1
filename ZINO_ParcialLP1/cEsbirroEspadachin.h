///////////////////////////////////////////////////////////
//  cEsbirroEspadachin.h
//  Implementation of the Class cEsbirroEspadachin
//  Created on:      11-jun.-2021 09:52:34
//  Original author: maile
///////////////////////////////////////////////////////////

#if !defined(EA_2BEF7EA4_3756_4869_B67C_41C94A6E1110__INCLUDED_)
#define EA_2BEF7EA4_3756_4869_B67C_41C94A6E1110__INCLUDED_

#include "cMonstruo.h"

class cEsbirroEspadachin : public cMonstruo
{

public:
	cEsbirroEspadachin();
	virtual ~cEsbirroEspadachin();

	void Atacar(cPersona* Victima);

private:
	int Fuerza;

};
#endif // !defined(EA_2BEF7EA4_3756_4869_B67C_41C94A6E1110__INCLUDED_)

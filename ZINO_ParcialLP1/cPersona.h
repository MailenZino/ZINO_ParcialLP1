///////////////////////////////////////////////////////////
//  cPersona.h
//  Implementation of the Class cPersona
//  Created on:      11-jun.-2021 09:52:34
//  Original author: maile
///////////////////////////////////////////////////////////

#if !defined(EA_E21F6A2C_B3FB_481c_84EF_0F53AFEC9DEE__INCLUDED_)
#define EA_E21F6A2C_B3FB_481c_84EF_0F53AFEC9DEE__INCLUDED_

#include <string>
using namespace std;
class cMonstruo;
class cPersona
{

public:
	cPersona(string Nombre);
	cPersona(int Armadura, bool Estado, int Fuerza, int PoderdeAtaque, const string USERNAME, int VidaActual, int VidaMaxima, int Inteligencia);
	virtual ~cPersona();

	void Atacar(cMonstruo* Victima);
	void ChequearVida();
	void Revivir();
	string To_String()const;
	bool getEstado() { return Estado; };

	friend ostream& operator<<(ostream& out, cPersona& P);
	friend void operator-(cPersona& P, int danio);

protected:
	void RecibirDanio(int Danio, cMonstruo* Atacante);
	
private:
	int Armadura;
	bool Estado; //true cuando vive
	int Fuerza;
	int PoderdeAtaque;
	const string USERNAME;
	int VidaActual;
	int VidaMaxima;
	int Inteligencia;

};

#endif // !defined(EA_E21F6A2C_B3FB_481c_84EF_0F53AFEC9DEE__INCLUDED_)

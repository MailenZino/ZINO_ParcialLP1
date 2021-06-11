///////////////////////////////////////////////////////////
//  cMonstruo.h
//  Implementation of the Class cMonstruo
//  Created on:      11-jun.-2021 09:52:34
//  Original author: maile
///////////////////////////////////////////////////////////

#if !defined(EA_BCB198A9_27C8_4907_9D24_77DCAA6FD8F3__INCLUDED_)
#define EA_BCB198A9_27C8_4907_9D24_77DCAA6FD8F3__INCLUDED_

class cMonstruo
{
public:
	cMonstruo();
	virtual ~cMonstruo();

	virtual void Atacar(cPersona* Victima)=0;
	void ChequearVida();
	bool getEstado() { return Estado; };

protected:
	int Ataque;
	bool Estado; //true cuando vive
	int Nombre;
	int Vida;
	friend void cPersona::Atacar(cMonstruo* Victima);
	virtual void RecibirDanio(int Danio);

private:
	static unsigned int CantCreados;

};
#endif // !defined(EA_BCB198A9_27C8_4907_9D24_77DCAA6FD8F3__INCLUDED_)

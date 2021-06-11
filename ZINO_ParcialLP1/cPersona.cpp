///////////////////////////////////////////////////////////
//  cPersona.cpp
//  Implementation of the Class cPersona
//  Created on:      11-jun.-2021 09:52:34
//  Original author: maile
///////////////////////////////////////////////////////////

#include "cPersona.h"
#include "cEsbirroEspadachin.h"
#include "cEsbirroMago.h"
#include "cJefe.h"
#include "cElite.h"
#include <iostream>
#define VMAX 100;
#define VMIN 35;
using namespace std;
cPersona::cPersona(string Nombre):USERNAME(Nombre)
{

	Estado = true;
	VidaMaxima = VMAX;
	VidaActual = VidaMaxima;

	Armadura=(rand()%5)+1; //de 1 a 5
	Fuerza=(rand()%66)+35; //un minimo de 35 puntos
	PoderdeAtaque=(rand()%10); //de 0 a 10
	Inteligencia = (rand() % 61) + 40;

}

cPersona::cPersona(int Armadura, bool Estado, int Fuerza, int PoderdeAtaque, const string USERNAME, int VidaActual, int VidaMaxima, int Inteligencia)
{
	this->Armadura = Armadura;
	this->Estado = Estado;
	this->Fuerza = Fuerza;
	this->PoderdeAtaque = PoderdeAtaque;
	this->VidaActual = VidaActual;
	this->Inteligencia = Inteligencia;
	this->VidaMaxima = VidaMaxima;
}

cPersona::~cPersona(){

}





/**
 * DANIO= PODERATAQUE+FUERZA+INTELIGENCIA
 */
void cPersona::Atacar(cMonstruo* Victima){

	int DANIO = PoderdeAtaque + Fuerza + Inteligencia;

	Victima->RecibirDanio(DANIO);
}


/**
 * //TIRAR EXCEPCION EN 0
 */
void cPersona::ChequearVida(){
	if (VidaActual <= 0)
	{
		int opcion;
		cout << "ESTAS A PUNTO DE MORIR! HAS SIDO VENCIDO\n Ingresa 1 si quieres revivir o 0 para rendirte:";
		cin >> opcion;
		if (opcion == 0)
			throw new exception("TE HAN ASESINADO");
		else
			Revivir();
	}
}


/**
 * usar dynamic cast
 * 0 si es neg
 * EsbirroMago
 *        DANIO=Danio-inteligencia/2
 * Jefe
 *        DANIO=Danio-armadura/4-inteligencia/4
 * EsbirroEsapadachin/elite
 *        DANIO=Danio-armadura
 * 
 * //SOBRECARGAR COMO FUNCION FRIEND EL OPERADOR -
 * void operator-(cPersona*P,int danio)
 */
void cPersona::RecibirDanio(int Danio, cMonstruo* Atacante){
	int auxDanio = 0;
	if (dynamic_cast<cEsbirroEspadachin*>(Atacante) != NULL || dynamic_cast<cElite*>(Atacante) != NULL)
	{
		auxDanio = Danio - Armadura;
	}
	else if (dynamic_cast<cJefe*>(Atacante) != NULL)
	{
		auxDanio = Danio - Armadura / 4 - Inteligencia / 4;
	}
	else if(dynamic_cast<cEsbirroMago*>(Atacante) != NULL) //podria sacar el dynamic porque es la unica opcion q queda
	{
		auxDanio = Danio - Inteligencia / 2;
	}
	(*this) - auxDanio;
}



void cPersona::Revivir(){
	
	VidaActual = (rand()%66) +VMIN;
	cout << (*this);
}


/**
 * //para usar con sobrecarga COUT
 */
string cPersona::To_String()const{
	string aux = "---" + USERNAME + "---\n TIENES LA VIDA AL "+to_string(VidaActual)+"% \n" ;
	aux += to_string(Fuerza)+"PUNTOS DE FUERZA \t" + to_string(PoderdeAtaque)+" DE PODER DE ATAQUE\t" + to_string(Inteligencia)+ " PUNTOS DE INTELIGENCIA\t" + to_string(Armadura)+" PUNTOS DE ARMADURA\n";
	return  aux;
}
ostream& operator<<(ostream& out, cPersona& P)
{
	out << P.To_String();
	return out;
}

void operator-(cPersona& P, int danio)
{
	P.VidaActual - danio;
}

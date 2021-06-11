#include "cPersona.h"
#include "cEsbirroEspadachin.h"
#include "cEsbirroMago.h"
#include "cJefe.h"
#include "cElite.h"
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
bool Batallar(cPersona* P1, cMonstruo* M1);
int main()
{
	srand(time(NULL));
	cPersona* P1 = new cPersona("PepePapas");
	cMonstruo* M1 = new cEsbirroEspadachin();
	if (Batallar(P1, M1))
		cout << "HAS CONQUISTADO LA MAZAMORRA";
	else
		cout << "EL MONSTRUO TE HA VENCIDO";
	M1 = new cEsbirroMago();
	if (Batallar(P1, M1))
		cout << "HAS CONQUISTADO LA MAZAMORRA";
	else
		cout << "EL MONSTRUO TE HA VENCIDO";
	M1 = new cJefe();
	if (Batallar(P1, M1))
		cout << "HAS CONQUISTADO LA MAZAMORRA";
	else
		cout << "EL MONSTRUO TE HA VENCIDO";
	M1 = new cElite();
	if (Batallar(P1, M1))
		cout << "HAS CONQUISTADO LA MAZAMORRA";
	else
		cout << "EL MONSTRUO TE HA VENCIDO";

	delete M1;
	delete P1;

}
bool Batallar(cPersona* P1, cMonstruo* M1)
{
	int aux = 0;
	//batallan hasta la muerte
	do
	{
		aux = rand() % 2;
		if (aux == 1)
			P1->Atacar(M1);
		else
			M1->Atacar(P1);
	} while (P1->getEstado() && M1->getEstado());
	//si sigue viva la persona, gano y devuelvo true
	if (P1->getEstado())
		return true;
}
#include<iostream>
#include<math.h>
#include "GrapheCirculaire.h"

using namespace std;

GrapheCirculaire::GrapheCirculaire(int c){
	C = c;
	nb_sommets = (pow(2, C)-1);
	tab = new int[nb_sommets];
	remplissage_parabole();
}
GrapheCirculaire::~GrapheCirculaire(){
	delete[] tab;
}

void GrapheCirculaire::remplissage_parabole(){
	for(int i=0; i<nb_sommets; i++){
		tab[i]=pow(i-nb_sommets/2, 2);
	}
}

int GrapheCirculaire::nombre_voisins(int sommet){
	if(!existe(sommet))
		return -1;
	int couche = log2(sommet);
	if (couche == 0)
		return 2;
	else if(couche == 1)
		return 4;
	else if(couche == C-1)
		return 3;
	else
		return 5;
}

int GrapheCirculaire::keme_voisin(int sommet, int k){
	
	if(!existe(sommet) || k<= 0 || k>nb_voisins)
		return -1;
}

bool GrapheCirculaire::existe(int sommet){
	if(sommet<=0 || sommet>nb_sommets)
		return false;
	return true;
}
	



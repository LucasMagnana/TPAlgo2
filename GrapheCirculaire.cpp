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
	int couche_s = couche(sommet);
	if (couche_s == 0)
		return 2;
	else if(couche_s == 1)
		return 4;
	else if(couche_s == C-1)
		return 3;
	else
		return 5;
}

int GrapheCirculaire::couche(int sommet){
	return log2(sommet);
}

int GrapheCirculaire::keme_voisin(int sommet, int k){
	int nb_voisins = nombre_voisins(sommet);
	int val;
	if(k<= 0 || k>nb_voisins)
		return -1;
	switch(nb_voisins){
		case 2:
			if(k == 1){
				return 2;
			}else if(k == 2){
				return 3;
			}
		case 4:
			switch(k){
				case 1:
					return 1;
				case 2:
					if(sommet == 2){
						return 3;
					}
					else if(sommet == 3){
						return 2;
					}
				case 3:
					return 2*sommet;
				case 4:
					return 2*sommet + 1;
			}
		case 3:
			if(k == 1){
				return sommet/2;
			}else if(k == 2){
				val = (sommet - 1)%(int)pow(2, C-1);
				val = pow(2, C-1) + val;
				return val;
			}else if(k == 3){
				val = (sommet - pow(2, C-1)) + 1;
				val = val%(int)pow(2, C-1);
				return pow(2, C-1) + val;
			}
		case 5:
			int couche_s = couche(sommet);
			switch(k){
				case 1:
					return sommet/2;
				case 2:
					return 2*sommet;
				case 3:
					return 2*sommet + 1;
				case 4:
					val = (sommet - 1)%(int)pow(2, couche_s);
					val = pow(2, couche_s) + val;
					return val;
				case 5:
					val = (sommet - pow(2, couche_s)) + 1;
					val = val%(int)pow(2, couche_s);
					return pow(2, couche_s) + val;
			}
	}
	
	return -1;
}

bool GrapheCirculaire::existe(int sommet){
	if(sommet<=0 || sommet>nb_sommets)
		return false;
	return true;
}

//l'affichage est merdique, mais j'ai pas trouve comment faire mieux WALLAH JPP
void GrapheCirculaire::affiche(){
	int sommet = 0, couche_s = 0;
	while(couche_s != C-1){
		couche_s = couche(sommet);
		cout << "Couche " << couche_s + 1 << " : " ;
		while(couche(sommet) == couche_s){
			cout << sommet << "  ";
			sommet += 1;
		}
		cout << endl;
	}
}



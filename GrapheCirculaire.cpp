#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<queue>
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
		//tab[i]=pow(i-nb_sommets/2, 2);
		tab[i] = i;
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

void GrapheCirculaire::affiche(){
	int sommet = 1, couche_s = 0;
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

void GrapheCirculaire::A_star(int depart, int arrive){
	if(!existe(depart) || !existe(arrive)){
		cout << "Un des sommets n'existe pas !" << endl;
		return ;
	}
	priority_queue<Node, vector<Node>, CompareNode> pq;
	struct_ensemble ensemble[nb_sommets+1];
	for(int i=0; i<=nb_sommets; i++){
		ensemble[i].couleur = BLANC;
		ensemble[i].distance = 0;
		ensemble[i].prec = 0;
	}
	Node actu, nd_depart;
	int voisin;
	nd_depart.sommet = depart;
	nd_depart.distance = 0;
	nd_depart.approximation = abs(tab[depart] - tab[arrive]); 
	pq.push(nd_depart);
	ensemble[depart].couleur = GRIS;
	int somme_d;
	while(true){
		actu = pq.top();
		pq.pop();
		if(actu.sommet != arrive){
			for(int i=1; i<=nombre_voisins(actu.sommet);i++){
				voisin=keme_voisin(actu.sommet, i);
				somme_d = ensemble[voisin].distance + actu.distance;
				if(ensemble[voisin].couleur == BLANC || (ensemble[voisin].couleur == GRIS && ensemble[voisin].distance < somme_d)){
					Node nd_voisin;
					nd_voisin.sommet=voisin;
					nd_voisin.approximation = abs(tab[arrive]-tab[voisin]);
					nd_voisin.distance = actu.distance + abs(tab[voisin]-tab[actu.sommet]);
					pq.push(nd_voisin);
					ensemble[nd_voisin.sommet].prec = actu.sommet;
					ensemble[nd_voisin.sommet].couleur = GRIS;
					ensemble[nd_voisin.sommet].distance = nd_voisin.distance;
				}
				
			}
			ensemble[actu.sommet].couleur=NOIR;
			ensemble[actu.sommet].distance = actu.distance;
		}
		else{
			int som = actu.sommet;
			cout << "Chemin de " << depart << " vers " << arrive << endl << som << endl;
			while(som != depart){
				cout << ensemble[som].prec << endl;
				som = ensemble[som].prec;
			}
			return;
			/*for(int j = 0 ; j<nb_sommets ; j++){
				cout << j << "  " << ensemble[j].couleur << "  " << ensemble[j].prec << endl;
			}
			return;*/
		}
	}
	
}





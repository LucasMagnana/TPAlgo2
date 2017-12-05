#include<iostream>
#include "GrapheCirculaire.h"

using namespace std;

int main() {
	GrapheCirculaire graphe1(4);
	/*int sommet = 15;
	cout << graphe1.keme_voisin(sommet, 1) << endl;
	cout << graphe1.keme_voisin(sommet, 2) << endl;
	cout << graphe1.keme_voisin(sommet, 3) << endl;
	cout << graphe1.keme_voisin(sommet, 4) << endl;
	cout << graphe1.keme_voisin(sommet, 5) << endl;
	cout << graphe1.keme_voisin(sommet, 6) << endl;
	cout << graphe1.keme_voisin(sommet, -1) << endl;*/
	/*graphe1.A_star(12,7);
	cout << "2eme " << endl;
	graphe1.A_star(7,15);*/
	for(int i = 1 ; i<= 15 ; i++){
		for(int j= 1 ; j<= 15 ; j++){
			if(i != j){
				graphe1.A_star(i,j);
			}
		}
	}
	return 0;
}
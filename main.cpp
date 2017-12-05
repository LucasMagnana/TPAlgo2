#include<iostream>
#include "GrapheCirculaire.h"

using namespace std;

void check_cin(int &input){
	cin >> input;
	while (!cin.good() || input < 0)
	{
		cout << "Veuillez entrer un entier naturel :";
		cin.clear();
		cin.ignore(INT8_MAX, '\n');
		cin >> input;
	}
}

int main() {
	int choice, resultat;
	bool continuer = true;
	cout << "Combien de couche voulez vous que le graphe contienne ?" << endl;
	check_cin(choice);
	GrapheCirculaire graphe(choice);
	while(continuer){
		cout << "1)A*                2)Nombre de voisins                     3)Keme voisin             4)Afficher la table             5)Quitter" << endl;
		check_cin(choice);
		if(choice == 1) {
			cout << "Sommet de départ : ";
			check_cin(choice);
			resultat = choice;
			cout << "Sommet d'arrivée : ";
			check_cin(choice);
			graphe.A_star(resultat, choice);
			
		} else if(choice == 2) {
			cout << "Quel sommet ? ";
			check_cin(choice);
			resultat = choice;
			cout << "K? ";
			check_cin(choice);
			if(graphe.keme_voisin(resultat, choice)!= -1){
				cout << graphe.keme_voisin(resultat, choice) << endl;
			} else
				cout << "Le sommet n'existe pas !" << endl;
		} else if(choice == 3) {
			cout << "Quel sommet ? ";
			check_cin(choice);
			if(graphe.nombre_voisins(choice) != -1){
				cout << graphe.nombre_voisins(choice) << endl;
			} else
				cout << "Le sommet n'existe pas !" << endl;
		}else if(choice == 4)
			graphe.affiche();
		else if(choice == 5)
				continuer = false;
		 else
			 cout << "Mauvais choix !" << endl;
			
	}
	return 0;
}
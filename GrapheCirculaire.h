#include<iostream>

class GrapheCirculaire{
	public:
		GrapheCirculaire(int c);
		~GrapheCirculaire();
		int nombre_voisins(int sommet);
		int keme_voisin(int sommet, int k);
		int couche(int sommet);
		void affiche();
	private:
		int C;
		int *tab;
		int nb_sommets;
		void remplissage_parabole();
		bool existe(int sommet);
};
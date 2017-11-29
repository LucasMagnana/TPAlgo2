#include<iostream>

class GrapheCirculaire{
	public:
		GrapheCirculaire(int c);
		~GrapheCirculaire();
		int nombre_voisins(int sommet);
	private:
		int C;
		int *tab;
		int nb_sommets;
		void remplissage_parabole();
		bool existe(int sommet);
};
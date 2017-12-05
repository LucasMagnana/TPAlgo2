#include<iostream>
#define BLANC 0
#define GRIS 1
#define NOIR 2

struct Node  {
	int sommet, approximation, distance;
};

struct CompareNode{
	bool operator()(Node const &n1, Node const &n2){
			return n1.approximation < n2.approximation;
	}
};

struct struct_ensemble {
	int couleur, distance;
};

class GrapheCirculaire{
	public:
		GrapheCirculaire(int c);
		~GrapheCirculaire();
		int nombre_voisins(int sommet);
		int keme_voisin(int sommet, int k);
		int couche(int sommet);
		void affiche();
		void A_star(int depart, int arrive);
	private:
		int C;
		int *tab;
		int nb_sommets;
		void remplissage_parabole();
		bool existe(int sommet);
};
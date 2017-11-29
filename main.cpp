#include<iostream>
#include "GrapheCirculaire.h"

using namespace std;

int main() {
	GrapheCirculaire graphe1(4);
	cout << graphe1.nombre_voisins(15) << endl;
	return 0;
}
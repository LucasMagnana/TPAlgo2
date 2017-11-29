graphe: main.o GrapheCirculaire.o
	g++ -o graphe main.o GrapheCirculaire.o
main.o: main.cpp GrapheCirculaire.h
	g++ -Wall -c main.cpp
GrapheCirculaire.o: GrapheCirculaire.cpp GrapheCirculaire.h
	g++ -Wall -c GrapheCirculaire.cpp 
	


clean:
	rm -f *.o
	rm -f *.txt
mr: clean
	rm -f graphe

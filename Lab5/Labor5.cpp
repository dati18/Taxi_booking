#include <iostream>
#include "Taxi.h"
#include "Menue.h"
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "Route.h"
using namespace std;

int main()
{
	Node *pAlex = new Node("Alexanderplatz");
	Node *pFunkturm = new Node("Funkturm");
	Node *pWannsee = new Node("Strandbad Wannsee");
	Node *pBrandenburgerTor = new Node("BrandenburgerTor");
	Node *pOstkreuz = new Node("Ostkreuz");
	Node *pRegattastrecke = new Node("Regattastrecke Grünau");
	Node *pGrenzallee = new Node("Grenzallee");
	Node *pZitadelle = new Node("Zitadelle Spandau");

	Route *pR1a = new Route(*pAlex, *pFunkturm, 10.2);
	Route *pR1b = new Route(*pFunkturm, *pAlex, 10.2);
	Route *pR2a = new Route(*pFunkturm, *pWannsee, 11.2);
	Route *pR2b = new Route(*pWannsee, *pFunkturm, 11.2);
	Route *pR3a = new Route(*pWannsee, *pBrandenburgerTor, 18.0);
	Route *pR3b = new Route(*pBrandenburgerTor, *pWannsee, 18.0);
	Route *pR4a = new Route(*pBrandenburgerTor, *pAlex, 2.3);
	Route *pR4b = new Route(*pAlex, *pBrandenburgerTor, 2.3);
	Route *pR5a = new Route(*pAlex, *pOstkreuz, 6.2);
	Route *pR5b = new Route(*pOstkreuz, *pAlex, 6.2);
	Route *pR6a = new Route(*pOstkreuz, *pRegattastrecke, 14.6);
	Route *pR6b = new Route(*pRegattastrecke, *pOstkreuz, 14.6);
	Route *pR7a = new Route(*pRegattastrecke, *pGrenzallee, 12.8);
	Route *pR7b = new Route(*pGrenzallee, *pRegattastrecke, 12.8);
	Route *pR8a = new Route(*pGrenzallee, *pAlex, 11.2);
	Route *pR8b = new Route(*pAlex, *pGrenzallee, 11.2);
	Route *pR9a = new Route(*pGrenzallee, *pFunkturm, 14.9);
	Route *pR9b = new Route(*pFunkturm, *pGrenzallee, 14.9);
	Route *pR10a = new Route(*pFunkturm, *pZitadelle, 8.5);
	Route *pR10b = new Route(*pZitadelle, *pFunkturm, 8.5);
	
	Graph g;
	try
	{
		g.addNode(pAlex);
		g.addNode(pFunkturm);
		g.addNode(pWannsee);
		g.addNode(pBrandenburgerTor);
		g.addNode(pOstkreuz);
		g.addNode(pRegattastrecke);
		g.addNode(pGrenzallee);
		g.addNode(pZitadelle);
		g.addEdge(pR1a);
		g.addEdge(pR1b);
		g.addEdge(pR2a);
		g.addEdge(pR2b);
		g.addEdge(pR3a);
		g.addEdge(pR3b);
		g.addEdge(pR4a);
		g.addEdge(pR4b);
		g.addEdge(pR5a);
		g.addEdge(pR5b);
		g.addEdge(pR6a);
		g.addEdge(pR6b);
		g.addEdge(pR7a);
		g.addEdge(pR7b);
		g.addEdge(pR8a);
		g.addEdge(pR8b);
		g.addEdge(pR9a);
		g.addEdge(pR9b);
		g.addEdge(pR10a);
		g.addEdge(pR10b);
	}
	catch (const GraphException& e)
	{
		cout << e.what() << endl;
	}

	deque<Edge*> path;
	g.findShortestPathDijkstra(path, *pAlex, *pFunkturm);

	try
	{
		Taxi* taxiArray[2];
		taxiArray[0] = new Taxi(7.2 / 100, 0.7, 75.0, "Taxi 1", 25.75);
		taxiArray[1] = new Taxi(12.5 / 100, 0.95, 90.0, "Taxi 2");

		Taxi t1;
		Taxi t2(t1);

		int auswahl = 0;
		int taxi = 0;
		double entfernung, benzinpreis;

		Node *pStart = NULL, *pZiel;
		deque<Edge*> path;

		while (auswahl != 5)
		{
			showMenue();
			auswahl = nutzerMenueAuswahl();

			if (auswahl != 5)
			{
				cout << "1: " << taxiArray[0]->getName() << endl;
				cout << "2: " << taxiArray[1]->getName() << endl;
				taxi = nutzerTaxiAuswahl();
			}
			switch (auswahl)
			{
			case 1:
				pStart = nutzerOrtAuswahl(g, "Startort");
				pZiel = nutzerOrtAuswahl(g, "Zielort");
				g.findShortestPathDijkstra(path, *pStart, *pZiel);
				for (auto e : path)
				{
					entfernung = entfernung + e->getWeight();
				}
				taxiArray[taxi]->fahrtVerbuchen(entfernung, true);
				path.clear();
				break;
			case 2:
				pStart = nutzerOrtAuswahl(g, "Startort");
				pZiel = nutzerOrtAuswahl(g, "Zielort");
				g.findShortestPathDijkstra(path, *pStart, *pZiel);
				for (auto e : path)
				{
					entfernung = entfernung + e->getWeight();
				}
				taxiArray[taxi]->fahrtVerbuchen(entfernung, false);
				path.clear();
				break;
			case 3:
				cout << "Bitte geben Sie den Benzinpreis an: ";
				cin >> benzinpreis;
				taxiArray[taxi]->tanken(benzinpreis);
				break;
			case 4:
				cout << taxiArray[taxi]->getState() << endl;
				break;
			case 5:
				break;
			}

		}

		delete taxiArray[0];
		delete taxiArray[1];
	}
	catch (const TaxiException& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	system("pause");
    return 0;
}


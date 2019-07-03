#include "Menue.h"
#include <iostream>
#include <string>
#include "Graph.h"
#include <map>

using namespace std;

void showMenue()
{
	cout << "1. Fahrt verbuchen mit Fahrgast" << endl;
	cout << "2. Fahrt verbuchen ohne Fahrgast" << endl;
	cout << "3. Tanken" << endl;
	cout << "4. Status" << endl;
	cout << "5. Beenden" << endl;
}

int nutzerMenueAuswahl()
{
	int auswahl = 0;
	while (auswahl < 1 || auswahl > 5)
	{
		cout << "Was wollen Sie tun (1...5)? ";
		cin >> auswahl;

		if (auswahl < 1 || auswahl > 5)
			cout << "ERROR: Auswahl muss zwischen 1 bis 5 sein..." << endl;
	}
	return auswahl;
}

int nutzerTaxiAuswahl()
{
	int auswahl = 0;
	while (auswahl < 1 || auswahl > 2)
	{
		cout << "Taxi 1 oder Taxi 2? ";
		cin >> auswahl;

		if (auswahl < 1 || auswahl > 2)
			cout << "ERROR: Auswahl muss zwischen 1 und 2 sein..." << endl;
	}
	return ( auswahl - 1 );
}

Node* nutzerOrtAuswahl(Graph& g, string ortsart)
{
	map<int, Node*> nodeMap;
	int i = 0;
	for (auto n : g.getNodes())
	{
		nodeMap[i] = n;
		cout <<" " << n->getId() << endl;
		i++;
	}

	int auswahl = 0;
	while (auswahl < 1 || auswahl > g.getNodes().size())
	{
		cout << "Bitte waehlen Sie aus" << ortsart;
		cin >> auswahl;

		if (auswahl < 1 || auswahl > 5)
			cout << "ERROR: Auswahl nicht im richtigen Wertebereich!" << endl;
	}
	return nodeMap[auswahl];
}
#pragma once
#include "Node.h"
#include "Graph.h"
#include <string>

using namespace std;

void showMenue();
int nutzerMenueAuswahl();
int nutzerTaxiAuswahl();

Node* nutzerOrtAuswahl(Graph& g, string ortsart);

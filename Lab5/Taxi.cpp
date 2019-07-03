#include "Taxi.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int Taxi::s_count = 0;
int Taxi::s_index = 0;

Taxi::Taxi(double verbrauch, double fahrPreis, double maxTankInhalt, string name, double geldBilanz )
	: m_maxTankInhalt( maxTankInhalt), m_verbrauchProKm( verbrauch ),
	m_preisProKm( fahrPreis ), m_geldBilanz( geldBilanz)
{
	m_tankInhalt = m_maxTankInhalt;
	m_tagesKm = 0;

	setName(name);
	s_count++;
	s_index++;
}

Taxi::Taxi()
	: m_maxTankInhalt(100.0), m_verbrauchProKm(9.0 / 100), m_preisProKm(0.25),
	m_geldBilanz(0.0), m_tagesKm(0.0)
{
	m_tankInhalt = m_maxTankInhalt;

	s_count++;
	s_index++;

	m_name = createName();
}

Taxi::Taxi(const Taxi& taxi)
	: m_maxTankInhalt(taxi.m_maxTankInhalt), m_verbrauchProKm(taxi.m_verbrauchProKm), 
	m_preisProKm(taxi.m_preisProKm), m_geldBilanz(taxi.m_geldBilanz), 
	m_tagesKm(taxi.m_tagesKm), m_tankInhalt( taxi.m_tankInhalt), m_name( taxi.m_name)
{
	s_count++;
	s_index++;
}

string Taxi::createName() const
{
	stringstream ss;
	ss << "Taxi_";
	ss << setw(3) << setfill('0');
	ss << s_index;

	return ss.str();
}

void Taxi::fahrtVerbuchen(double entfernung, bool fahrgaeste)
{
	double benoetigterTreibstoff = entfernung * m_verbrauchProKm;
	if (benoetigterTreibstoff <= m_tankInhalt)
	{
		m_tankInhalt -= benoetigterTreibstoff;
		m_tagesKm += entfernung;
		if (fahrgaeste)
			m_geldBilanz += entfernung * m_preisProKm;
	}
	else
		cout << "ERROR: Tankinhalt nicht ausreichend" << endl;
}

void Taxi::tanken(double benzinPreis)
{
	double benoetigterTreibstoff = m_maxTankInhalt - m_tankInhalt;
	if (m_geldBilanz < benoetigterTreibstoff * benzinPreis)
		benoetigterTreibstoff = m_geldBilanz / benzinPreis;

	m_tankInhalt += benoetigterTreibstoff;
	m_geldBilanz -= benoetigterTreibstoff * benzinPreis;
}

string Taxi::getState() const
{
	stringstream ss;
	ss << setw(8) << left << m_name << " >> ";
	ss << setw(7) << right << fixed << setprecision(2) << m_tagesKm << " km, ";
	ss << setw(7) << m_tankInhalt << " l, ";
	ss << setw(7) << m_geldBilanz << " €";

	return ss.str();
}
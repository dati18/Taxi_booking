#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Taxi
{
public:
	Taxi(double verbrauch, double fahrPreis, double maxTankInhalt, string name, double geldBilanz = 0 );
	Taxi();
	Taxi(const Taxi& taxi);
	~Taxi() { s_count--; }
	void fahrtVerbuchen(double entfernung, bool fahrgaeste);
	void tanken(double benzinPreis);
	inline void setName(string name);
	inline string getName() const { return m_name; }
	string getState() const;
	string createName() const;

private:
	double m_tagesKm;
	double m_tankInhalt;
	const double m_maxTankInhalt;
	const double m_verbrauchProKm;
	const double m_preisProKm;
	double m_geldBilanz;
	string m_name;

	static int s_count;
	static int s_index;
};


class TaxiException
{
public:
	TaxiException(string reason) : m_reason(reason) {}
	inline string what() const { return m_reason; }
private:
	string m_reason;
};


void Taxi::setName(string name)
{
	if (name.length() <= 8)
		m_name = name;
	else
	{
		TaxiException e("Taxi-Name ist so lang (max. 8 Zeichen!)");
		throw e;
	}
}


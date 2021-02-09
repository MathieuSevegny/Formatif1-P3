#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sort
{
private:
	string m_nom;
	int m_degat;
public:
	Sort(string nom, int degat);
	string getNom();
	int getDegat();
};


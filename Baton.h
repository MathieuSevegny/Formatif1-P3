#pragma once
#include <iostream>
#include <string>
#include "Sort.h"

using namespace std;

class Baton
{
private:
	string m_nom;
	int m_mana;
	Sort* m_sortDefense;
	Sort* m_sortAttaque;
public:
	Baton(Sort* sortAttaque, Sort* sortDefense);
	int utiliserSort(bool attaque);
	string getNom();
	int getMana();
};


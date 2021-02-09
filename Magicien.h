#pragma once
#include <iostream>
#include <string>
#include "Baton.h"

class Magicien
{
private:
	int m_hp;
	int m_bouclier;
	Baton m_baton;
	bool m_estSonTour;
public:
	Magicien(Sort* sortsAttaques[], Sort* sortsDefense[]);
	void recevoirDegat(int degat);
	void changerBaton(Sort* sortsAttaques[], Sort* sortsDefense[]);
	int getHp();
	void setEstSonTour();
	int getMana();
	int utliserSort(bool attaque);
};


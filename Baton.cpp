#include "Baton.h"

Baton::Baton(Sort* sortAttaque, Sort* sortDefense) :
		m_mana{50},
		m_nom{ sortAttaque->getNom() + " de " + sortDefense->getNom() },
		m_sortAttaque { sortAttaque },
m_sortDefense{ sortDefense }
{}

int Baton::utiliserSort(bool attaque)
{
	if (attaque) {
		cout << " utilise le sort d'attaque " << m_sortAttaque->getNom() << "!\n";
		return m_sortAttaque->getDegat();
	}
	else {
		cout << " utilise le sort de defense " << m_sortDefense->getNom() << "!\n";
		return m_sortDefense->getDegat();
	}
	m_mana -= 10;
}

string Baton::getNom()
{
	return m_nom;
}

int Baton::getMana()
{
	return m_mana;
}

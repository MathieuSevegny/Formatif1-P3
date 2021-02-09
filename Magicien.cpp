#include "Magicien.h"
#include "utilitaires.h"

Magicien::Magicien(Sort* sortsAttaques[], Sort* sortsDefense[]) : 
	m_hp{ 50 }, m_bouclier{ 0 }, m_baton{ Baton(sortsAttaques[random(0, 1)], sortsDefense[random(0, 1)]) }, m_estSonTour{ false }
{}

void Magicien::recevoirDegat(int degat)
{
	if (m_estSonTour) {
		if (degat < 0)
		{
			m_bouclier += abs(degat);
		}
		else {
			if (m_hp + degat > 100) {
				m_hp = 100;
			}
			else
			{
				m_hp += degat;
			}
		}
	}
	else
	{
		if (degat < 0)
		{
			m_hp -= abs(degat);
		}
		else {
			if (m_bouclier < degat) {
				m_hp -= degat - m_bouclier;
				m_bouclier = 0;
			}
			else {
				m_bouclier -= degat;
			}
		}
	}
}

void Magicien::changerBaton(Sort* sortsAttaques[],Sort* sortsDefense[])
{
	m_baton = Baton(sortsAttaques[random(0, 1)], sortsDefense[random(0, 1)]);
	cout << "Le magicien recoit le baton " << m_baton.getNom() << "!\n";
}

int Magicien::getHp()
{
	return m_hp;
}
int Magicien::getMana() {
	return m_baton.getMana();
}

int Magicien::utliserSort(bool attaque)
{
	cout << "Le magicien";
	return m_baton.utiliserSort(attaque);
}

void Magicien::setEstSonTour()
{
	m_estSonTour = !m_estSonTour;
}

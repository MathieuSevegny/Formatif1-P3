#include "Sort.h"

Sort::Sort(string nom, int degat) : m_nom{ nom }, m_degat{ degat } {}

string Sort::getNom()
{
    return m_nom;
}

int Sort::getDegat()
{
    return m_degat;
}


#include <iostream>
#include "Magicien.h"
#include "utilitaires.h"

Sort attaqueun{ "Incinerateur", 30 };
Sort attaquedeux{ "Foudre", 30 };
Sort* sortsAttaques[2]{ &attaqueun,&attaquedeux };

Sort defenseun{ "Guerison", 10 };
Sort defensedeux{ "Protection", 5 };
Sort* sortsDefenses[2]{ &defenseun,&defensedeux };

Magicien magicienJoueur{ sortsAttaques,sortsDefenses };
Magicien magicienOrdi{ sortsAttaques,sortsDefenses };

bool choixAttaque() {
    bool choix{ false };
    bool correct{ false };
    string attaquer = "";
    cout << "Voulez-vous etre offensif (a) ou voulez-vous etre defensif (d) ?";
    while (!correct) {
        cin >> attaquer;
        if (attaquer == "a") {
            choix = true;
            correct = true;
        }
        else if(attaquer == "d"){
            correct = true;
        }
    }
    return choix;
}

void tourJoueur() {
    bool decide{ false };
    bool correct{ false };
    string choix = "";
    if (magicienJoueur.getMana() >= 10)
    {
        cout << "Voulez-vous faire un sort (s) ou voulez-vous changer de baton (b) ?";

        while (!correct) {
            cin >> choix;
            if (choix == "s") {
                decide = true;
                correct = true;
            }
            else if (choix == "b") {
                correct = true;
            }
        }
        if (decide) {
            bool attaque{ choixAttaque() };
            if (attaque) {
                magicienOrdi.recevoirDegat(magicienJoueur.utliserSort(attaque));
            }
            else
            {
                magicienJoueur.recevoirDegat(magicienJoueur.utliserSort(attaque));
            }
        }
        else {
            magicienJoueur.changerBaton(sortsAttaques, sortsDefenses);
        }
    }
    else {
        magicienJoueur.changerBaton(sortsAttaques, sortsDefenses);
    }
}

void tourOrdi() {
    bool attaque{false};
    if (magicienOrdi.getMana() >= 10) {
        if (random(1,2) == 1)
        {
            attaque = true;
        }
        if (attaque) {
            magicienJoueur.recevoirDegat(magicienOrdi.utliserSort(attaque));
        }
        else
        {
            magicienOrdi.recevoirDegat(magicienOrdi.utliserSort(attaque));
        }
    }
    else {
        magicienOrdi.changerBaton(sortsAttaques, sortsDefenses);
    }
}

bool isSomeoneDead() {
    if (magicienJoueur.getHp() <= 0 || magicienOrdi.getHp() <= 0)
    {
        return true;
    }
    return false;
}


int main()
{
    bool isNotFinished = true;
    int tour;
    string attaquer;

    while (isNotFinished) {
        if (!isSomeoneDead()) {
            tour = random(1, 2);
            if (tour == 1) {
                magicienJoueur.setEstSonTour();
                tourJoueur();
                magicienJoueur.setEstSonTour();
                if (magicienOrdi.getHp() > 0) {
                    magicienOrdi.setEstSonTour();
                    tourOrdi();
                    magicienOrdi.setEstSonTour();
                }
                else {
                    isNotFinished = false;
                }
            }
            else {
                magicienOrdi.setEstSonTour();
                tourOrdi();
                magicienOrdi.setEstSonTour();
                if (magicienJoueur.getHp() > 0) {
                    magicienJoueur.setEstSonTour();
                    tourJoueur();
                    magicienJoueur.setEstSonTour();
                }
                else {
                    isNotFinished = false;
                }
            }
        }
        else
        {
            isNotFinished = false;
        }
        system("cls");
        if (!isNotFinished) {
            if (magicienJoueur.getHp() <= 0) {
                cout << "Vous avez perdu...\n";
            }
            else
            {
                cout << "Vous avez gagne!!\n";
            }
        }
        cout << "Votre vie restante : " << magicienJoueur.getHp() << "\n";
        cout << "La vie restante de l'ennemi: " << magicienOrdi.getHp() << "\n";

    }
}
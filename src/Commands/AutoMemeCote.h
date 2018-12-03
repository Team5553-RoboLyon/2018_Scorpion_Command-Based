#ifndef AUTOMEMECOTE_H
#define AUTOMEMECOTE_H

#include "Commands/CommandGroup.h"


/*
 * Cette commande comporte la suite des commandes à éxécuter durant la période autonome
 * Elle n'est appelée seulement si le robot est du même coté que le switch de l'alliance
 * Cependant elle peut être appelé quand le robot (et le switch) est à droite ou à gauche
 * On appelle donc la fonction Init() pour initialiser les sens de rotations
 */


class AutoMemeCote: public frc::CommandGroup
{
public:
	AutoMemeCote(char coteSwitch);

private:
	double rotation1;

};

#endif

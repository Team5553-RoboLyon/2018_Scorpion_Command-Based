#ifndef AUTOOPPOSEE_H
#define AUTOOPPOSEE_H

#include "Commands/CommandGroup.h"


/*
 * Cette commande comporte la suite des commandes à éxécuter durant la période autonome
 * Elle n'est appelée seulement si le robot est du coté opposé au switch de l'alliance
 * Cependant elle peut être appelé quand le robot est à droite ou à gauche
 * On appelle donc la fonction Init() pour initialiser les sens de rotations
 */


class AutoOpposee: public frc::CommandGroup
{
public:
	AutoOpposee(char coteSwitch);

private:

};

#endif

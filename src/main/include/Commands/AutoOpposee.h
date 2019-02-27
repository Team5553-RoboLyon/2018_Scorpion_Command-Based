#ifndef AUTOOPPOSEE_H
#define AUTOOPPOSEE_H

#include "frc/WPILib.h"


/*
 * Cette commande comporte la suite des commandes � �x�cuter durant la p�riode autonome
 * Elle n'est appel�e seulement si le robot est du cot� oppos� au switch de l'alliance
 * Cependant elle peut �tre appel� quand le robot est � droite ou � gauche
 * On appelle donc la fonction Init() pour initialiser les sens de rotations
 */


class AutoOpposee: public frc::CommandGroup
{
public:
	AutoOpposee(char coteSwitch);

private:

};

#endif

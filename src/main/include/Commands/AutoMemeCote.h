#ifndef AUTOMEMECOTE_H
#define AUTOMEMECOTE_H

#include "frc/WPILib.h"


/*
 * Cette commande comporte la suite des commandes � �x�cuter durant la p�riode autonome
 * Elle n'est appel�e seulement si le robot est du m�me cot� que le switch de l'alliance
 * Cependant elle peut �tre appel� quand le robot (et le switch) est � droite ou � gauche
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

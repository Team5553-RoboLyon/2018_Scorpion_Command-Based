#ifndef AUTOMILIEU_H
#define AUTOMILIEU_H

#include "frc/WPILib.h"


/*
 * Cette commande comporte la suite des commandes � �x�cuter durant la p�riode autonome
 * Elle n'est appel�e seulement si le robot est au milieu
 * Cependant elle peut �tre appel� quand le switch de l'alliance est � droite ou � gauche
 * On appelle donc la fonction Init() pour initialiser les sens de rotations
 */


class AutoMilieu: public frc::CommandGroup
{
public:
	AutoMilieu(char coteSwitch);

private:
	double rotation1et8, rotation2et7, rotation3et5, rotation4et6;
};

#endif

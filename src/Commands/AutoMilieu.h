#ifndef AUTOMILIEU_H
#define AUTOMILIEU_H

#include "Commands/CommandGroup.h"


/*
 * Cette commande comporte la suite des commandes à éxécuter durant la période autonome
 * Elle n'est appelée seulement si le robot est au milieu
 * Cependant elle peut être appelé quand le switch de l'alliance est à droite ou à gauche
 * On appelle donc la fonction Init() pour initialiser les sens de rotations
 */


class AutoMilieu: public frc::CommandGroup
{
public:
	void Init(char coteSwitch);
	AutoMilieu();

private:
	double rotation1et8, rotation2et7, rotation3et5, rotation4et6;
};

#endif

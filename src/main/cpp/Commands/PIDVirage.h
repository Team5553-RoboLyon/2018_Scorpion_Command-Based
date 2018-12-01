#ifndef PIDVIRAGE_H
#define PIDVIRAGE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/*
 *  Cette fonction permet de faire tourner le robot sur un certain angle
 *  Pour l'initialiser on remet tout d'abord les capteurs à zero
 *  Puis pendant l'éxécution on active les moteurs en fonction de l'angle restant à parcourir
 *
 *  La fonction est finie quand elle est proche de l'objectif
 */


class PIDVirage: public Command
{
public:
	PIDVirage(double angleConsigne);

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double m_angleConsigne;

	const double tolerance = 2;

	const double kP = 0.05; //0.050 pour cotés et 0.075 pour milieu
	const double kI = 0.00003;
	const double kD = 0.28;

	double angleParcouru, erreur, erreurPrecedente, sommeErreurs, differenceErreurs;
	double vitesse;
};

#endif

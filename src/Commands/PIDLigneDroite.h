#ifndef PIDLIGNEDROITE_H
#define PIDLIGNEDROITE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/*
 *  Cette fonction permet de faire rouler le robot sur une certaine distance
 *  Pour l'initialiser on remet tout d'abord les capteurs à zero
 *  Puis pendant l'éxécution on active les moteurs en fonction de la distance restante à parcourir
 *
 *  La fonction est finie quand elle est proche de l'objectif
 */


class PIDLigneDroite: public Command
{
public:
	PIDLigneDroite(double distanceConsigne);


	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double m_distanceConsigne;

	const double r = 7.62, tolerance = 2;

	double distanceParcourueDroite, erreurDroite, erreurPrecedenteDroite, sommeErreursDroite, differenceErreursDroite;
	double distanceParcourueGauche, erreurGauche, erreurPrecedenteGauche, sommeErreursGauche, differenceErreursGauche;
	double vitesseDroite;
	const double kP = 0.02;
	const double kI = 0.0000045;
	const double kD = 0.05;
};

#endif

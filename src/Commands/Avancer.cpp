/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Avancer.h"

Avancer::Avancer(double distance_a_parcourir)
{
	Requires(&Robot::baseRoulante);
	m_distance_a_parcourir = distance_a_parcourir;
}

void Avancer::Initialize()
{
	Robot::baseRoulante.EncodeurDroit->Reset();
	erreurPrecedenteDroite = 0;
	erreurPrecedenteGauche = 0;
	sommeErreursDroite = 0;
	sommeErreursGauche = 0;
}

void Avancer::Execute()
{
	distanceParcourueDroite = -(Robot::baseRoulante.EncodeurDroit->Get() * r * 2 * M_PI / 263);

	erreurDroite = m_distance_a_parcourir - distanceParcourueDroite;
	sommeErreursDroite += erreurDroite;
	differenceErreursDroite = erreurDroite - erreurPrecedenteDroite;

	vitesseDroite = kPAvancer * erreurDroite + kIAvancer * sommeErreursDroite + kDAvancer * differenceErreursDroite;

	Robot::baseRoulante.Drive(-vitesseDroite, vitesseDroite);

	erreurPrecedenteDroite = erreurDroite;
}

bool Avancer::IsFinished()
{
	return 	abs(erreurDroite) < tolerance;
}

void Avancer::End()
{
	Robot::baseRoulante.Drive(0, 0);
}

void Avancer::Interrupted()
{
	Robot::baseRoulante.Drive(0, 0);
}

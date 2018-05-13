/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Tourner.h"

Tourner::Tourner(double angle_consigne)
{
	Requires(&Robot::baseRoulante);
	m_angle_consigne = angle_consigne;
}

void Tourner::Initialize()
{
	Robot::baseRoulante.Gyro->Reset();
	erreurPrecedente = 0;
	sommeErreurs = 0;
}

void Tourner::Execute()
{
	angleParcouru = Robot::baseRoulante.Gyro->GetAngle();

	erreur = m_angle_consigne - angleParcouru;
	sommeErreurs += erreur;
	differenceErreurs = erreur - erreurPrecedente;

	vitesse = kP * erreur + kI * sommeErreurs + kD * differenceErreurs;

	Robot::baseRoulante.Drive(-vitesse, -vitesse);

	erreurPrecedente = erreur;
}

bool Tourner::IsFinished()
{
	return 	abs(erreur) < tolerance;
}

void Tourner::End()
{
	Robot::baseRoulante.Drive(0, 0);
}

void Tourner::Interrupted()
{
	Robot::baseRoulante.Drive(0, 0);
}

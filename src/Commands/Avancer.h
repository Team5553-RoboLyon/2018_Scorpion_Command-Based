/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../Robot.h"

class Avancer : public frc::Command
{
public:
	Avancer(double distance_a_parcourir);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	const double r = 7.62, tolerance = 2;

	double distanceParcourueDroite, erreurDroite, erreurPrecedenteDroite, sommeErreursDroite, differenceErreursDroite;
	double distanceParcourueGauche, erreurGauche, erreurPrecedenteGauche, sommeErreursGauche, differenceErreursGauche;
	double m_distance_a_parcourir, vitesseDroite;
	double kPAvancer, kIAvancer, kDAvancer;
};


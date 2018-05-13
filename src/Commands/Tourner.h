/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../Robot.h"

class Tourner : public frc::Command {
public:
	Tourner(double angle_consigne);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	const double tolerance = 2;

	double angleParcouru, erreur, erreurPrecedente, sommeErreurs, differenceErreurs;
	double m_angle_consigne, vitesse;
	double kP, kI, kD;
};


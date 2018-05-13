/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "WPILib.h"
#include "../Commands/AjusterPivot.h"
#include <Commands/PIDSubsystem.h>

class Pivot : public frc::PIDSubsystem
{
private:
	PWMVictorSPX* Moteur;
	Encoder* Encodeur;

	double kP = 0.003;
	double kI = 0.00000001;
	double kD = 0.000001;

public:
	Pivot();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;

	const int ECHANGEUR_AVANT = 700;
	const int ECHANGEUR_ARRIERE = -700;
	const int SWITCH_AVANT = 300;
	const int SWITCH_ARRIERE = -300;
	const int MILIEU = 0;
};


/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Pince : public frc::Subsystem
{
private:
	PWMVictorSPX* Roues;
	DoubleSolenoid* Verin;

public:
	Pince();
	void InitDefaultCommand() override;
	void Init();
	void Ouvrir();
	void Fermer();
	void Aspirer();
	void Ejecter();
	void Stop();

	bool pinceOuverte;
};


/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "WPILib.h"
#include "../Robot.h"
#include <Commands/Subsystem.h>

class BaseRoulante : public frc::Subsystem {
private:
	VictorSP* BaseDroite1;
	VictorSP* BaseDroite2;
	VictorSP* BaseGauche1;
	VictorSP* BaseGauche2;

	DoubleSolenoid* DoubleSolenoid1;

public:
	BaseRoulante();
	void InitDefaultCommand() override;
	void Init();
	void Drive(double gauche, double droite);
	void ActiverVitesse1();
	void ActiverVitesse2();

	Encoder* EncodeurDroit;
	Encoder* EncodeurGauche;

	ADXRS450_Gyro* Gyro;

	bool vitesse1;
};


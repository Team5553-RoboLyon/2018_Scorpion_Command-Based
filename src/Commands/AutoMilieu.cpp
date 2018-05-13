/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoMilieu.h"

AutoMilieu::AutoMilieu()
{
	if (Robot::coteSwitch == 'L')
	{
		rotation1et8 = -35;
		rotation2et7 = 35;
		rotation3et5 = 74;
		rotation4et6 = -83;
	}
	else
	{
		rotation1et8 = 35;
		rotation2et7 = -35;
		rotation3et5 = -74;
		rotation4et6 = 83;
	}

	AddSequential(new Avancer(30));
	AddSequential(new Tourner(rotation1et8));
	AddSequential(new Avancer(195));
	AddSequential(new Tourner(rotation2et7));
	AddSequential(new SetPivotSetpoint(Robot::pivot.SWITCH_AVANT));
	AddSequential(new Ejection(0.5));
	AddSequential(new Avancer(-80));
	AddSequential(new Tourner(rotation3et5));
	AddSequential(new Avancer(110));
	AddSequential(new Tourner(rotation4et6));
	AddSequential(new SetPivotSetpoint(Robot::pivot.ECHANGEUR_AVANT));
	AddParallel(new Aspiration(1.0, 0.2));
	AddSequential(new Avancer(50));
	AddSequential(new Avancer(-50));
	AddSequential(new SetPivotSetpoint(Robot::pivot.SWITCH_AVANT));
	AddSequential(new Tourner(rotation3et5));
	AddSequential(new Avancer(-100));
	AddSequential(new Tourner(rotation4et6));
	AddSequential(new Avancer(80));
	AddSequential(new Ejection(0.5));
}

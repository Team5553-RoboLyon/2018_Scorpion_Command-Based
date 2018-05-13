/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoMemeCote.h"

AutoMemeCote::AutoMemeCote()
{
	if(Robot::coteSwitch == 'L')
	{
		rotation1 = 90;
	}
	else
	{
		rotation1 = -90;
	}

	AddSequential(new Avancer(340));
	AddSequential(new Tourner(rotation1));
	AddSequential(new SetPivotSetpoint(Robot::pivot.SWITCH_AVANT));
	AddSequential(new Avancer(25));
	AddSequential(new Ejection(0.5));
}

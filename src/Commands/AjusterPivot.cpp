/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AjusterPivot.h"
#include "../Robot.h"

AjusterPivot::AjusterPivot()
{
	Requires(&Robot::pivot);
}

void AjusterPivot::Initialize()
{
	int pov = OI::joystick->GetPOV();

	if(pov == 0)
	{
		Robot::pivot.SetSetpointRelative(12);
	}
	else if(pov == 180)
	{
		Robot::pivot.SetSetpointRelative(-12);
	}
}

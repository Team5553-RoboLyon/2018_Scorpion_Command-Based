/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ChangementPositionPince.h"

ChangementPositionPince::ChangementPositionPince()
{
	Requires(&Robot::pince);
}

void ChangementPositionPince::Initialize()
{
	if(Robot::pince.pinceOuverte)
	{
		Robot::pince.Fermer();
	}
	else
	{
		Robot::pince.Ouvrir();
	}
}

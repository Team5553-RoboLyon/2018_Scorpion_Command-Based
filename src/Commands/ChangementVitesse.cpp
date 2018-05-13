/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ChangementVitesse.h"

ChangementVitesse::ChangementVitesse()
{
	Requires(&Robot::baseRoulante);
}

void ChangementVitesse::Initialize()
{
	if(Robot::baseRoulante.vitesse1)
	{
		Robot::baseRoulante.ActiverVitesse2();
	}
	else
	{
		Robot::baseRoulante.ActiverVitesse1();
	}
}

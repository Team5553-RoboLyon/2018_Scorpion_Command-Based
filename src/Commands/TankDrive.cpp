/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TankDrive.h"
#include "../Robot.h"

TankDrive::TankDrive()
{
	Requires(&Robot::baseRoulante);
}

void TankDrive::Initialize()
{

}

void TankDrive::Execute()
{
	double y = OI::joystick->GetY();
	double z = OI::joystick->GetZ();

	if (y < 0.2 && y > -0.2)
	{
		y = 0;
	}
	if (z < 0.2 && z > -0.2)
	{
		z = 0;
	}

	double vitesseGauche = y - 0.5 * z;
	double vitesseDroite = -y - 0.5 * z;

	Robot::baseRoulante.Drive(vitesseGauche, vitesseDroite);
}

bool TankDrive::IsFinished()
{
	return false;
}

void TankDrive::End()
{
	Robot::baseRoulante.Drive(0, 0);
}

void TankDrive::Interrupted()
{
	Robot::baseRoulante.Drive(0, 0);
}

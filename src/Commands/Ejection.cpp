/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Ejection.h"

Ejection::Ejection(double timeout) : TimedCommand(timeout)
{
	Requires(&Robot::pince);
}

void Ejection::Initialize()
{

}

void Ejection::Execute()
{
	Robot::pince.Ejecter();
}

void Ejection::End()
{
	Robot::pince.Ouvrir();
	Robot::pince.Stop();
}

void Ejection::Interrupted()
{
	Robot::pince.Stop();
}

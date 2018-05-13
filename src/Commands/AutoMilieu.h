/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/CommandGroup.h>
#include "../Robot.h"

class AutoMilieu : public frc::CommandGroup
{
public:
	AutoMilieu();

private:
	double rotation1et8, rotation2et7, rotation3et5, rotation4et6;
};


/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "../Robot.h"
#include "Commands/TimedCommand.h"

class Ejection : public frc::TimedCommand
{
public:
	Ejection(double timeout);
	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;
};

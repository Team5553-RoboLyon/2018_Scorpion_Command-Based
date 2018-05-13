/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "../Robot.h"
#include "Commands/TimedCommand.h"

class Aspiration : public frc::TimedCommand
{
public:
	Aspiration(double timeout, double dureeApresFermeture);
	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;

private:
	double m_dureeApresFermeture, m_duree;
};

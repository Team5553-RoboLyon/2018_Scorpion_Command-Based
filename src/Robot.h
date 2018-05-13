/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#include "OI.h"

#include "Commands/TankDrive.h"
#include "Commands/Avancer.h"
#include "Commands/Tourner.h"
#include "Commands/Ejection.h"
#include "Commands/Aspiration.h"
#include "Commands/ChangementPositionPince.h"
#include "Commands/ChangementVitesse.h"
#include "Commands/SetPivotSetpoint.h"
#include "Commands/AjusterPivot.h"

#include "Commands/AutoMilieu.h"
#include "Commands/AutoMemeCote.h"
#include "Commands/AutoOpposee.h"

#include "Subsystems/Pince.h"
#include "Subsystems/Pivot.h"
#include "Subsystems/BaseRoulante.h"

#include <string>

class Robot : public frc::TimedRobot
{
public:
	static Pince pince;
	static Pivot pivot;
	static BaseRoulante baseRoulante;
	static OI m_oi;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

	char coteSwitch;

private:
	frc::Command* m_autonomousCommand = nullptr;
	AutoMilieu m_AutoMilieu;
	AutoMemeCote m_AutoMemeCote;
	AutoOpposee m_AutoOpposee;
	frc::SendableChooser<char> positionChooser;
};

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Scheduler.h>
#include <Robot.h>
#include <SmartDashboard/SmartDashboard.h>

OI Robot::m_oi;

Pince Robot::pince;
Pivot Robot::pivot;
BaseRoulante Robot::baseRoulante;

void Robot::RobotInit()
{
	positionChooser.AddDefault("Depart milieu", 'M');
	positionChooser.AddObject("Depart gauche", 'L');
	positionChooser.AddObject("Depart droite", 'R');
	frc::SmartDashboard::PutData("Auto Modes", &positionChooser);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	baseRoulante.Init();
	pince.Init();

	char positonSwitch = frc::DriverStation::GetInstance().GetGameSpecificMessage()[0];
	coteSwitch = positonSwitch;
	char positionRobot = positionChooser.GetSelected();

	if(positionRobot == 'M')
	{
		m_autonomousCommand = &m_AutoMilieu;
	}
	else if(positonSwitch == positionRobot)
	{
		m_autonomousCommand = &m_AutoMemeCote;
	}
	else
	{
		m_autonomousCommand = &m_AutoOpposee;
	}

	if (m_autonomousCommand != nullptr)
	{
		m_autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	if (m_autonomousCommand != nullptr)
	{
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)

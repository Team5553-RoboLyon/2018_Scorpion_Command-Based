// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<BaseRoulante> Robot::baseRoulante;
std::shared_ptr<Pince> Robot::pince;
std::shared_ptr<Pivot> Robot::pivot;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit()
{
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    baseRoulante.reset(new BaseRoulante());
    pince.reset(new Pince());
    pivot.reset(new Pivot());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	oi.reset(new OI());

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	positionChooser.AddDefault("Depart milieu", 'M');
	positionChooser.AddObject("Depart gauche", 'L');
	positionChooser.AddObject("Depart droite", 'R');
	frc::SmartDashboard::PutData("Auto Modes", &positionChooser);

	baseRoulante->ActiverVitesse1();
	pince->Fermer();
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	baseRoulante->ActiverVitesse1();
	pince->Fermer();

	char positonSwitch = frc::DriverStation::GetInstance().GetGameSpecificMessage()[0];
	char positionRobot = positionChooser.GetSelected();

	if(positionRobot == 'M')
	{
		m_AutoMilieu.Init(positonSwitch);
		autonomousCommand = &m_AutoMilieu;
	}
	else if(positonSwitch == positionRobot)
	{
		m_AutoMemeCote.Init(positonSwitch);
		autonomousCommand = &m_AutoMemeCote;
	}
	else
	{
		m_AutoOpposee.Init(positonSwitch);
		autonomousCommand = &m_AutoOpposee;
	}

	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);


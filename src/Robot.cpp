#include "Robot.h"

BaseRoulante Robot::baseRoulante;
Pince Robot::pince;
Pivot Robot::pivot;
OI Robot::oi;

void Robot::RobotInit()
{
	// Show what command your subsystem is running on the SmartDashboard
	frc::SmartDashboard::PutData(&baseRoulante);
	frc::SmartDashboard::PutData(&pince);
	frc::SmartDashboard::PutData(&pivot);

	//Choix de la position de départ sur le SmartDashboard
	positionChooser.AddDefault("Depart milieu", 'M');
	positionChooser.AddObject("Depart gauche", 'L');
	positionChooser.AddObject("Depart droite", 'R');
	frc::SmartDashboard::PutData("Auto Modes", &positionChooser);

	//Initialisation de la pneumatique
	baseRoulante.ActiverVitesse1();
	pince.Fermer();
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
	//Initialisation de la pneumatique (2ème fois pour être sûr)
	baseRoulante.ActiverVitesse1();
	pince.Fermer();

	//On récupère la position du robot sur le SmartDashboard et celle du switch grâce au FMS
	char positonSwitch = frc::DriverStation::GetInstance().GetGameSpecificMessage()[0];
	char positionRobot = positionChooser.GetSelected();

	m_AutoMilieu = new AutoMilieu(positonSwitch);
	m_AutoMemeCote = new AutoMemeCote(positonSwitch);
	m_AutoOpposee = new AutoOpposee(positonSwitch);

	//Séléction de l'auto qui correspond et initialisation pour gérer de quel côté elle part
	if(positionRobot == 'M')
	{
		autonomousCommand = m_AutoMilieu;
	}
	else if(positonSwitch == positionRobot)
	{
		autonomousCommand = m_AutoMemeCote;
	}
	else
	{
		autonomousCommand = m_AutoOpposee;
	}

	//Lancement de l'auto
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	//La autonomousCommand est éxécutée
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	//Arrêt de l'auto si elle était active
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	//Les commandes sont appelées selon les boutons du joystick, si elles sont finis, etc...
	frc::Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);


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

	//Choix de la position de d�part sur le SmartDashboard
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
	//Initialisation de la pneumatique (2�me fois pour �tre s�r)
	baseRoulante.ActiverVitesse1();
	pince.Fermer();

	//On r�cup�re la position du robot sur le SmartDashboard et celle du switch gr�ce au FMS
	char positonSwitch = frc::DriverStation::GetInstance().GetGameSpecificMessage()[0];
	char positionRobot = positionChooser.GetSelected();

	//S�l�ction de l'auto qui correspond et initialisation pour g�rer de quel c�t� elle part
	if(positionRobot == 'M')
	{
		m_AutoMilieu.reset(new AutoMilieu(positonSwitch));
		autonomousCommand.reset(m_AutoMilieu.release());
	}
	else if(positonSwitch == positionRobot)
	{
		m_AutoMemeCote.reset(new AutoMemeCote(positonSwitch));
		autonomousCommand.reset(m_AutoMemeCote.release());
	}
	else
	{
		m_AutoOpposee.reset(new AutoOpposee(positonSwitch));
		autonomousCommand.reset(m_AutoOpposee.release());
	}

	//Lancement de l'auto
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	//La autonomousCommand est �x�cut�e
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	//Arr�t de l'auto si elle �tait active
	if (autonomousCommand != nullptr)
	{
		autonomousCommand->Cancel();
		autonomousCommand.release();
	}
}

void Robot::TeleopPeriodic()
{
	//Les commandes sont appel�es selon les boutons du joystick, si elles sont finis, etc...
	frc::Scheduler::GetInstance()->Run();
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif

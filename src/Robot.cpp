#include "Robot.h"

std::shared_ptr<BaseRoulante> Robot::baseRoulante;
std::shared_ptr<Pince> Robot::pince;
std::shared_ptr<Pivot> Robot::pivot;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit()
{
	RobotMap::init();

    baseRoulante.reset(new BaseRoulante());
    pince.reset(new Pince());
    pivot.reset(new Pivot());
	oi.reset(new OI());

	//Choix de la position de d�part sur le SmartDashboard
	positionChooser.AddDefault("Depart milieu", 'M');
	positionChooser.AddObject("Depart gauche", 'L');
	positionChooser.AddObject("Depart droite", 'R');
	frc::SmartDashboard::PutData("Auto Modes", &positionChooser);

	//Initialisation de la pneumatique
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
	//Initialisation de la pneumatique (2�me fois pour �tre s�r)
	baseRoulante->ActiverVitesse1();
	pince->Fermer();

	//On r�cup�re la position du robot sur le SmartDashboard et celle du switch gr�ce au FMS
	char positonSwitch = frc::DriverStation::GetInstance().GetGameSpecificMessage()[0];
	char positionRobot = positionChooser.GetSelected();

	//S�l�ction de l'auto qui correspond et initialisation pour g�rer de quel c�t� elle part
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
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	//Les commandes sont appel�es selon les boutons du joystick, si elles sont finis, etc...
	frc::Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);


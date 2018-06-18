#include "Pivot.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/AjusterPivot.h"


const double Pivot::MILIEU = 0;
const double Pivot::ECHANGEUR_AVANT = 300;
const double Pivot::ECHANGEUR_ARRIERE = -300;
const double Pivot::SWITCH_AVANT = 700;
const double Pivot::SWITCH_ARRIERE = -700;


Pivot::Pivot() : PIDSubsystem("Pivot", kP, kI, kD)
{
    frc::LiveWindow::GetInstance()->AddActuator("Pivot", "PIDSubsystem Controller", GetPIDController());

	//On récupère tous les capteurs et controlleurs dont on à besoin
    moteur = RobotMap::pivotMoteur;
    encodeur = RobotMap::pivotEncodeur;

    //Initialisation et démarage du PIDController
    GetPIDController()->SetContinuous(false);
	SetAbsoluteTolerance(20);
	SetInputRange(-700, 700);
	SetSetpoint(MILIEU);
	Enable();
}

double Pivot::ReturnPIDInput()
{
	return encodeur->PIDGet();
}

void Pivot::UsePIDOutput(double output)
{
    moteur->PIDWrite(output);
}

void Pivot::InitDefaultCommand()
{
	//AjusterPivot() sera appelée si aucune autre commande n'est en cours d'éxécution
	SetDefaultCommand(new AjusterPivot());
}

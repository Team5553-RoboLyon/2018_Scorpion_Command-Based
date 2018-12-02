#include "Pivot.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/AjusterPivot.h"


const double Pivot::MILIEU = 0;
const double Pivot::ECHANGEUR_AVANT = 700;
const double Pivot::ECHANGEUR_ARRIERE = -700;
const double Pivot::SWITCH_AVANT = 300;
const double Pivot::SWITCH_ARRIERE = -300;


Pivot::Pivot() : PIDSubsystem("Pivot", 0.003, 0.00000001, 0.000001)
{
    GetPIDController()->SetName("Pivot", "PIDSubsystem Controller");

    //Initialisation et démarrage du PIDController
    GetPIDController()->SetContinuous(false);
	SetAbsoluteTolerance(20);
	SetInputRange(-700, 700);
	SetSetpoint(0);
	Enable();

	AddChild("Moteur", moteur);
	AddChild("Encodeur", encodeur);
}

double Pivot::ReturnPIDInput()
{
	return encodeur.Get();
}

void Pivot::UsePIDOutput(double output)
{
    moteur.PIDWrite(output);
}

void Pivot::InitDefaultCommand()
{
	//AjusterPivot() sera appelée si aucune autre commande n'est en cours d'éxécution
	SetDefaultCommand(new AjusterPivot());
}

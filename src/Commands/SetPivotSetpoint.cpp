#include "SetPivotSetpoint.h"


SetPivotSetpoint::SetPivotSetpoint(double setpoint): Command()
{
    m_setpoint = setpoint;

    //Quand la commande est éxécutée elle stoppe la commande (si il y en a une) qui utilise le même subsystème
	Requires(Robot::pivot.get());
}

void SetPivotSetpoint::Initialize()
{
	//On active le PID du Pivot (pas forcément utile)
    Robot::pivot->Enable();

    //On change sa consigne
    Robot::pivot->SetSetpoint(m_setpoint);
}

//Tant que la commande est active on passe par cette boucle
void SetPivotSetpoint::Execute()
{
	//C'est le PIDController qui gère
}

bool SetPivotSetpoint::IsFinished()
{
	//Quand la cible est atteinte
    return Robot::pivot->OnTarget();
}

void SetPivotSetpoint::End()
{

}

void SetPivotSetpoint::Interrupted()
{

}

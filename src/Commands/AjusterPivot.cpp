#include "AjusterPivot.h"


AjusterPivot::AjusterPivot(): Command()
{
	//Quand la commande est éxécutée elle stoppe la commande (si il y en a une) qui utilise le même subsystème
	Requires(Robot::pivot.get());

    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialisées
	pov = 0;
}

void AjusterPivot::Initialize()
{
	//On active le PID du Pivot (pas forcément utile)
    Robot::pivot->Enable();
}

//Tant que la commande est active on passe par cette boucle
void AjusterPivot::Execute()
{
	//On récupère la position du POV du joystick
	pov = Robot::oi->getJoystick1()->GetPOV();

	//On augmente ou diminue sa consigne en foncion de la position du joystick
	if(pov == 0)
	{
		Robot::pivot->SetSetpointRelative(12);
	}
	else if(pov == 180)
	{
		Robot::pivot->SetSetpointRelative(-12);
	}
}

bool AjusterPivot::IsFinished()
{
	//Cette commande n'a pas de fin, elle peut être éxécutée sans arrêt
	return false;
}

void AjusterPivot::End()
{

}

void AjusterPivot::Interrupted()
{

}

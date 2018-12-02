#include "DriveWithJoystick.h"


DriveWithJoystick::DriveWithJoystick(): frc::Command()
{
	//Quand la commande est éxécutée elle stoppe la commande (si il y en a une) qui utilise le même subsystème
	Requires(&Robot::baseRoulante);
    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialisées
	y = 0;
	z = 0;
	vitesseGauche = 0;
	vitesseDroite = 0;
}

void DriveWithJoystick::Initialize()
{

}

//Tant que la commande est active on passe par cette boucle
void DriveWithJoystick::Execute()
{
	//On récupère la position du joystick
	y = Robot::oi.getJoystick1()->GetY();
	z = Robot::oi.getJoystick1()->GetZ();

	//Si les valeurs lues sont trop petites, insignifiantes on les considère comme nulles
	if (y < 0.2 && y > -0.2)
	{
		y = 0;
	}
	if (z < 0.2 && z > -0.2)
	{
		z = 0;
	}

	//La "formule" pour calculer la vitesse de chaque moteur
	vitesseGauche = y - 0.5 * z;
	vitesseDroite = y + 0.5 * z;

	//On utilise la fonction membre du subsystème BaseRoulante
	Robot::baseRoulante.Drive(vitesseGauche, vitesseDroite);
}

bool DriveWithJoystick::IsFinished()
{
	//Cette commande n'a pas de fin, elle peut être éxécutée sans arrêt
    return false;
}

void DriveWithJoystick::End()
{
	//On utilise la fonction membre du subsystème BaseRoulante
	Robot::baseRoulante.Drive(0,0);
}

void DriveWithJoystick::Interrupted()
{
	this->End();
}

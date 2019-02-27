#include "Commands/DriveWithJoystick.h"


DriveWithJoystick::DriveWithJoystick(): frc::Command()
{
	//Quand la commande est �x�cut�e elle stoppe la commande (si il y en a une) qui utilise le m�me subsyst�me
	Requires(&Robot::baseRoulante);
    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialis�es
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
	//On r�cup�re la position du joystick
	y = Robot::oi.GetJoystick().GetY();
	z = Robot::oi.GetJoystick().GetZ();

	//Si les valeurs lues sont trop petites, insignifiantes on les consid�re comme nulles
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

	//On utilise la fonction membre du subsyst�me BaseRoulante
	Robot::baseRoulante.Drive(vitesseGauche, vitesseDroite);
}

bool DriveWithJoystick::IsFinished()
{
	//Cette commande n'a pas de fin, elle peut �tre �x�cut�e sans arr�t
    return false;
}

void DriveWithJoystick::End()
{
	//On utilise la fonction membre du subsyst�me BaseRoulante
	Robot::baseRoulante.Drive(0,0);
}

void DriveWithJoystick::Interrupted()
{
	this->End();
}

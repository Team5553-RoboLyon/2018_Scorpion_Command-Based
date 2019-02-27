#include "Commands/EjecterCube.h"


EjecterCube::EjecterCube() : TimedCommand(1.0)
{
	//Cette commande n'a pas de fin, elle peut �tre �x�cut�e sans arr�t
	Requires(&Robot::pince);
}

void EjecterCube::Initialize()
{

}

//Tant que la commande est active on passe par cette boucle
void EjecterCube::Execute()
{
	Robot::pince.Ejecter();
}

//Pas de IsFinished() car c'est le timeout qui g�re �a

void EjecterCube::End()
{
	Robot::pince.Ouvrir();
	Robot::pince.Stop();
}

void EjecterCube::Interrupted()
{
	Robot::pince.Stop();
}

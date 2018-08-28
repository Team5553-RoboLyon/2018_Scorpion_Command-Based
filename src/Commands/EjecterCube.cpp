#include "EjecterCube.h"


EjecterCube::EjecterCube() : TimedCommand(1.0)
{
	//Cette commande n'a pas de fin, elle peut être éxécutée sans arrêt
	Requires(Robot::pince.get());
}

void EjecterCube::Initialize()
{

}

//Tant que la commande est active on passe par cette boucle
void EjecterCube::Execute()
{
	Robot::pince->Ejecter();
}

//Pas de IsFinished() car c'est le timeout qui gère ça

void EjecterCube::End()
{
	Robot::pince->Ouvrir();
	Robot::pince->Stop();
}

void EjecterCube::Interrupted()
{
	Robot::pince->Stop();
}

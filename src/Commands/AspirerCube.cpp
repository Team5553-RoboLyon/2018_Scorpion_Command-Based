#include "AspirerCube.h"


AspirerCube::AspirerCube() : TimedCommand(1.0)  //Le chrono est lancé
{
	//Quand la commande est éxécutée elle stoppe la commande (si il y en a une) qui utilise le même subsystème
	Requires(&Robot::pince);
}

void AspirerCube::Initialize()
{

}

//Tant que la commande est active on passe par cette boucle
void AspirerCube::Execute()
{
	Robot::pince.Aspirer();

	//Le chrono est lancé à l'initialisation de la commande, on peut le récuperer avec la fonction TimeSinceInitialized()
	//Ici on ferme la pince (m_dureeApresFermeture =) 0.2 sec avant la fin du timeout
	if(this->TimeSinceInitialized() > m_timeout - m_dureeApresFermeture)
	{
		Robot::pince.Fermer();
	}
}

//Pas de IsFinished() car c'est le timeout qui gère ça

void AspirerCube::End()
{
	//On prend soin d'arrêter les roues
	Robot::pince.Stop();
}

void AspirerCube::Interrupted()
{
	//On prend soin d'arrêter les roues
	End();
}

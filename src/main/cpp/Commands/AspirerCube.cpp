#include "Commands/AspirerCube.h"


AspirerCube::AspirerCube() : TimedCommand(1.0)  //Le chrono est lanc�
{
	//Quand la commande est �x�cut�e elle stoppe la commande (si il y en a une) qui utilise le m�me subsyst�me
	Requires(&Robot::pince);
}

void AspirerCube::Initialize()
{

}

//Tant que la commande est active on passe par cette boucle
void AspirerCube::Execute()
{
	Robot::pince.Aspirer();

	//Le chrono est lanc� � l'initialisation de la commande, on peut le r�cuperer avec la fonction TimeSinceInitialized()
	//Ici on ferme la pince (m_dureeApresFermeture =) 0.2 sec avant la fin du timeout
	if(this->TimeSinceInitialized() > m_timeout - m_dureeApresFermeture)
	{
		Robot::pince.Fermer();
	}
}

//Pas de IsFinished() car c'est le timeout qui g�re �a

void AspirerCube::End()
{
	//On prend soin d'arr�ter les roues
	Robot::pince.Stop();
}

void AspirerCube::Interrupted()
{
	//On prend soin d'arr�ter les roues
	End();
}

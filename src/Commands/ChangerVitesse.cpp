#include "ChangerVitesse.h"


ChangerVitesse::ChangerVitesse(): InstantCommand()
{
	//Quand la commande est �x�cut�e elle stoppe la commande (si il y en a une) qui utilise le m�me subsyst�me
	Requires(Robot::baseRoulante.get());
}

void ChangerVitesse::Initialize()
{
	Robot::baseRoulante->ChangerVitesse();
}

//Pas de Execute(), IsFinished(), End() et Interrupted() dans cette commande car elle ne dure que le temps du Initialize()

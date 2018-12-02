#include "ChangerPositionPince.h"


ChangerPositionPince::ChangerPositionPince(): InstantCommand()
{
	//Quand la commande est éxécutée elle stoppe la commande (si il y en a une) qui utilise le même subsystème
	Requires(&Robot::pince);
}

void ChangerPositionPince::Initialize()
{
	Robot::pince.ChangerPosition();
}

//Pas de Execute(), IsFinished(), End() et Interrupted() dans cette commande car elle ne dure que le temps du Initialize()

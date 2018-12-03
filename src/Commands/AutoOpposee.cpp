#include "AutoOpposee.h"

#include "AspirerCube.h"
#include "EjecterCube.h"
#include "PIDLigneDroite.h"
#include "PIDVirage.h"
#include "SetPivotSetpoint.h"


AutoOpposee::AutoOpposee(char coteSwitch)
{
	Requires(&Robot::baseRoulante);
	Requires(&Robot::pivot);
	Requires(&Robot::pince);

	//Suite des commandes � �x�cuter :
	// AddSequential() bloque les commandes qui suivent tant qu'elle n'est pas finie
	// AddParallel() s'�x�cute en m�me tant que les commandes qui suivent

	AddSequential(new PIDLigneDroite(340));
}

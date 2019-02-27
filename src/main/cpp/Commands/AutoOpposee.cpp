#include "Commands/AutoOpposee.h"

#include "Commands/AspirerCube.h"
#include "Commands/EjecterCube.h"
#include "Commands/PIDLigneDroite.h"
#include "Commands/PIDVirage.h"
#include "Commands/SetPivotSetpoint.h"


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

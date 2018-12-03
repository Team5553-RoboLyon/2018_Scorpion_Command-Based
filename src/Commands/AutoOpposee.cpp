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

	//Suite des commandes à éxécuter :
	// AddSequential() bloque les commandes qui suivent tant qu'elle n'est pas finie
	// AddParallel() s'éxécute en même tant que les commandes qui suivent

	AddSequential(new PIDLigneDroite(340));
}

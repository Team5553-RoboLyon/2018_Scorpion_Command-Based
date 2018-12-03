#include "AutoMemeCote.h"

#include "AspirerCube.h"
#include "EjecterCube.h"
#include "PIDLigneDroite.h"
#include "PIDVirage.h"
#include "SetPivotSetpoint.h"


AutoMemeCote::AutoMemeCote(char coteSwitch)
{
	Requires(&Robot::baseRoulante);
	Requires(&Robot::pivot);
	Requires(&Robot::pince);

	//Initialisation des sens de rotations en fonction de la position du switch
	if(coteSwitch == 'L')
	{
		rotation1 = 90;
	}
	else
	{
		rotation1 = -90;
	}

	//Suite des commandes à éxécuter :
	// AddSequential() bloque les commandes qui suivent tant qu'elle n'est pas finie
	// AddParallel() s'éxécute en même tant que les commandes qui suivent

	AddSequential(new PIDLigneDroite(340));
	AddSequential(new PIDVirage(rotation1));
	AddParallel(new SetPivotSetpoint(Pivot::SWITCH_AVANT));
	AddSequential(new PIDLigneDroite(25));
	AddSequential(new EjecterCube());
}

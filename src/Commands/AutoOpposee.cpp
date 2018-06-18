#include "AutoOpposee.h"

#include "AspirerCube.h"
#include "EjecterCube.h"
#include "PIDLigneDroite.h"
#include "PIDVirage.h"
#include "SetPivotSetpoint.h"

void AutoOpposee::Init(char coteSwitch)
{

}

AutoOpposee::AutoOpposee()
{
	//Suite des commandes � �x�cuter :
	// AddSequential() bloque les commandes qui suivent tant qu'elle n'est pas finie
	// AddParallel() s'�x�cute en m�me tant que les commandes qui suivent

	AddSequential(new PIDLigneDroite(340));
}

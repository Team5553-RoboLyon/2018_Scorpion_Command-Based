#include "Commands/AutoMilieu.h"

#include "Commands/AspirerCube.h"
#include "Commands/EjecterCube.h"
#include "Commands/PIDLigneDroite.h"
#include "Commands/PIDVirage.h"
#include "Commands/SetPivotSetpoint.h"


AutoMilieu::AutoMilieu(char coteSwitch)
{
	Requires(&Robot::baseRoulante);
	Requires(&Robot::pivot);
	Requires(&Robot::pince);

	//Initialisation des sens de rotations en fonction de la position du switch
	if (coteSwitch == 'L')
	{
		rotation1et8 = -35;
		rotation2et7 = 35;
		rotation3et5 = 74;
		rotation4et6 = -83;
	}
	else
	{
		rotation1et8 = 35;
		rotation2et7 = -35;
		rotation3et5 = -74;
		rotation4et6 = 83;
	}

	//Suite des commandes � �x�cuter :
	// AddSequential() bloque les commandes qui suivent tant qu'elle n'est pas finie
	// AddParallel() s'�x�cute en m�me tant que les commandes qui suivent

	AddSequential(new PIDLigneDroite(30));
	AddSequential(new PIDVirage(rotation1et8));
	AddSequential(new PIDLigneDroite(195));
	AddSequential(new PIDVirage(rotation2et7));
	AddSequential(new SetPivotSetpoint(Pivot::SWITCH_AVANT));
	AddSequential(new EjecterCube());
	AddSequential(new PIDLigneDroite(-80));
	AddSequential(new PIDVirage(rotation3et5));
	AddSequential(new PIDLigneDroite(110));
	AddSequential(new PIDVirage(rotation4et6));
	AddSequential(new SetPivotSetpoint(Pivot::ECHANGEUR_AVANT));
	AddParallel(new AspirerCube());
	AddSequential(new PIDLigneDroite(50));
	AddSequential(new PIDLigneDroite(-50));
	AddSequential(new SetPivotSetpoint(Pivot::SWITCH_AVANT));
	AddSequential(new PIDVirage(rotation3et5));
	AddSequential(new PIDLigneDroite(-100));
	AddSequential(new PIDVirage(rotation4et6));
	AddSequential(new PIDLigneDroite(80));
	AddSequential(new EjecterCube());
 }

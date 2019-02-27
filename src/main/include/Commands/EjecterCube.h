#ifndef EJECTERCUBE_H
#define EJECTERCUBE_H


#include "frc/WPILib.h"
#include "Robot.h"


/*
 *  Cette commande fait tourner les roues pendant 1 seconde
 *  Elle est consid�r�e comme finie � la fin du chrono = 1 sec
 *  Quand elle est termin�e ou interompue on ouvre la pince et on arr�te les roues
 */


class EjecterCube: public frc::TimedCommand
{
public:
	EjecterCube();

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;

private:
};

#endif

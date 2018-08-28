#ifndef EJECTERCUBE_H
#define EJECTERCUBE_H


#include "Commands/TimedCommand.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"


/*
 *  Cette commande fait tourner les roues pendant 1 seconde
 *  Elle est considérée comme finie à la fin du chrono = 1 sec
 *  Quand elle est terminée ou interompue on ouvre la pince et on arrête les roues
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

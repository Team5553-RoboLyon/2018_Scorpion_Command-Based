#ifndef AJUSTERPIVOT_H
#define AJUSTERPIVOT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/*
 * Cette commande augmente ou diminue la consigne (ou setpoint) du pivot
 * Pour cela elle lit la position du POV du joystick, puis :
 * - Ajoute 12 à la consigne si il est vers le haut
 * - Enlève 12 à la consigne si il est vers le bas
 *
 * Pas de fin pour cette commande
 */


class AjusterPivot: public frc::Command
{
public:
	AjusterPivot();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	int pov;
};

#endif

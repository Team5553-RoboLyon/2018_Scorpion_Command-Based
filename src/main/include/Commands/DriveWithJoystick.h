#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H


#include "frc/WPILib.h"
#include "Robot.h"


/*
 * Cette commande active les moteurs de la base selon la position du joystick
 * Pas de fin pour cette commande
 */


class DriveWithJoystick: public frc::Command
{
public:
	DriveWithJoystick();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double y, z, vitesseGauche, vitesseDroite;
};

#endif

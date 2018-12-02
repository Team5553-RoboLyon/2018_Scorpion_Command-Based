#ifndef PINCE_H
#define PINCE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Cablage.h"


class Pince: public frc::Subsystem
{
private:
	frc::PWMVictorSPX roues{PWM_ROUES};
	frc::DoubleSolenoid verin{PCM_VERIN_PINCE_A, PCM_VERIN_PINCE_B};


public:
	Pince();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Ouvrir();
	void Fermer();
	void ChangerPosition();
	void Aspirer();
	void Ejecter();
	void Stop();

	bool pinceOuverte;
};

#endif

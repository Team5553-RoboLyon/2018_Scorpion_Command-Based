#ifndef PINCE_H
#define PINCE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class Pince: public frc::Subsystem
{
private:
	frc::PWMVictorSPX roues{4};
	frc::DoubleSolenoid verin{2, 3};


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

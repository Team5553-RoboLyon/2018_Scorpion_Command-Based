#ifndef PINCE_H
#define PINCE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class Pince: public frc::Subsystem
{
private:
	std::shared_ptr<frc::SpeedController> roues;
	std::shared_ptr<frc::DoubleSolenoid> verin;


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

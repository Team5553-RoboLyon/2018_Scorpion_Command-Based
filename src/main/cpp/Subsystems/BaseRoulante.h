#ifndef BASEROULANTE_H
#define BASEROULANTE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class BaseRoulante: public frc::Subsystem
{
private:
	std::shared_ptr<frc::SpeedController> baseDroite2;
	std::shared_ptr<frc::SpeedController> baseDroite1;
	std::shared_ptr<frc::SpeedControllerGroup> baseDroite;
	std::shared_ptr<frc::SpeedController> baseGauche1;
	std::shared_ptr<frc::SpeedController> baseGauche2;
	std::shared_ptr<frc::SpeedControllerGroup> baseGauche;
	std::shared_ptr<frc::AnalogGyro> gyro;
	std::shared_ptr<frc::Encoder> encodeurDroit;
	std::shared_ptr<frc::Encoder> encodeurGauche;
	std::shared_ptr<frc::DoubleSolenoid> ballshiffter;

	bool vitesse1;

public:
	BaseRoulante();
	void InitDefaultCommand() override;
	void Periodic() override;

	void Drive(double gauche, double droite);
	void ActiverVitesse1();
	void ActiverVitesse2();
	void ChangerVitesse();

	int GetEncodeurDroit();
	int GetGyro();
	void ResetPID();
};

#endif

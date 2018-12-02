#ifndef BASEROULANTE_H
#define BASEROULANTE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class BaseRoulante: public frc::Subsystem
{
private:
	frc::PWMVictorSPX baseDroite1{0};
	frc::PWMVictorSPX baseDroite2{1};
	frc::SpeedControllerGroup baseDroite{baseDroite1, baseDroite2};

	frc::PWMVictorSPX baseGauche1{2};
	frc::PWMVictorSPX baseGauche2{3};
	frc::SpeedControllerGroup baseGauche{baseGauche1, baseGauche2};

	frc::AnalogGyro gyro{0};
	frc::Encoder encodeurDroit{0, 1, true, frc::Encoder::k4X};
	frc::Encoder encodeurGauche{2, 3, false, frc::Encoder::k4X};

	frc::DoubleSolenoid ballshiffter{0, 0, 1};

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

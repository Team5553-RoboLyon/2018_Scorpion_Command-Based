#ifndef BASEROULANTE_H
#define BASEROULANTE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Cablage.h"


class BaseRoulante: public frc::Subsystem
{
private:
	frc::PWMVictorSPX baseDroite1{PWM_BASE_DROITE_1};
	frc::PWMVictorSPX baseDroite2{PWM_BASE_DROITE_2};
	frc::SpeedControllerGroup baseDroite{baseDroite1, baseDroite2};

	frc::PWMVictorSPX baseGauche1{PWM_BASE_GAUCHE_1};
	frc::PWMVictorSPX baseGauche2{PWM_BASE_GAUCHE_2};
	frc::SpeedControllerGroup baseGauche{baseGauche1, baseGauche2};

	frc::ADXRS450_Gyro gyro;
	frc::Encoder encodeurDroit{DIO_ENCODEUR_DROIT_A, DIO_ENCODEUR_DROIT_B, true, frc::Encoder::k4X};
	frc::Encoder encodeurGauche{DIO_ENCODEUR_GAUCHE_A, DIO_ENCODEUR_GAUCHE_B, false, frc::Encoder::k4X};

	frc::DoubleSolenoid ballshiffter{PCM_BALLSHIFTER_A, PCM_BALLSHIFTER_B};

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

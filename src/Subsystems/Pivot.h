#ifndef PIVOT_H
#define PIVOT_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"


class Pivot: public frc::PIDSubsystem
{
 public:
	frc::PWMVictorSPX moteur{5};
	frc::Encoder encodeur{4, 5, false, frc::Encoder::k4X};

	Pivot();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;

	const static double MILIEU;
	const static double ECHANGEUR_AVANT;
	const static double ECHANGEUR_ARRIERE;
	const static double SWITCH_AVANT;
	const static double SWITCH_ARRIERE;


 private:
	double kP = 0.003;
	double kI = 0.00000001;
	double kD = 0.000001;
};

#endif

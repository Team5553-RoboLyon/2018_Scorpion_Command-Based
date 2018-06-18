#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"


class RobotMap
{
public:
	static std::shared_ptr<frc::SpeedController> baseRoulanteBaseDroite2;
	static std::shared_ptr<frc::SpeedController> baseRoulanteBaseDroite1;
	static std::shared_ptr<frc::SpeedControllerGroup> baseRoulanteBaseDroite;
	static std::shared_ptr<frc::SpeedController> baseRoulanteBaseGauche1;
	static std::shared_ptr<frc::SpeedController> baseRoulanteBaseGauche2;
	static std::shared_ptr<frc::SpeedControllerGroup> baseRoulanteBaseGauche;
	static std::shared_ptr<frc::AnalogGyro> baseRoulanteGyro;
	static std::shared_ptr<frc::Encoder> baseRoulanteEncodeurDroit;
	static std::shared_ptr<frc::Encoder> baseRoulanteEncodeurGauche;
	static std::shared_ptr<frc::DoubleSolenoid> baseRoulanteBallshiffter;
	static std::shared_ptr<frc::SpeedController> pinceRoues;
	static std::shared_ptr<frc::DoubleSolenoid> pinceVerin;
	static std::shared_ptr<frc::SpeedController> pivotMoteur;
	static std::shared_ptr<frc::Encoder> pivotEncodeur;

	static void init();
};
#endif

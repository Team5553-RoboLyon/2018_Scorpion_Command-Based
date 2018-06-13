// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef PIDVIRAGE_H
#define PIDVIRAGE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class PIDVirage: public Command
{
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	PIDVirage(double angleConsigne);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

    double m_angleConsigne;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	const double tolerance = 2;

	const double kP = 0.05; //0.050 pour cot�s et 0.075 pour milieu
	const double kI = 0.00003;
	const double kD = 0.28;

	double angleParcouru, erreur, erreurPrecedente, sommeErreurs, differenceErreurs;
	double vitesse;
};

#endif

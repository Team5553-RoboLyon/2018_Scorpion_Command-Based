#ifndef SETPIVOTSETPOINT_H
#define SETPIVOTSETPOINT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/*
 * Cette commande change la consigne (=setpoint) indiquée au pivot
 * Elle est "instantanée" et n'a donc ni Execute(), IsFinished(), End() et Interrupted() mais seulement un Initialize()
 */


class SetPivotSetpoint: public frc::Command
{
public:
	SetPivotSetpoint(double setpoint);

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
    double m_setpoint;

};

#endif

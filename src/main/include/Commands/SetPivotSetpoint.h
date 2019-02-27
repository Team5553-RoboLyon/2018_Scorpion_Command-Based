#ifndef SETPIVOTSETPOINT_H
#define SETPIVOTSETPOINT_H


#include "frc/WPILib.h"
#include "Robot.h"




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

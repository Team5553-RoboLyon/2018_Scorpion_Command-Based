/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SetPivotSetpoint.h"

SetPivotSetpoint::SetPivotSetpoint(int setpoint)
{
	Requires(&Robot::pivot);
	m_setpoint = setpoint;
}

void SetPivotSetpoint::Initialize()
{
	Robot::pivot.SetSetpoint(m_setpoint);
}

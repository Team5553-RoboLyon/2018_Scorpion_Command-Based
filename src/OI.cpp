/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

OI::OI()
{
	b_changementVitesse->WhenPressed(new ChangementVitesse());
	b_aspirerCube->WhenPressed(new Aspiration(1.0, 0.2));
	b_ejecterCube->WhenPressed(new Ejection(0.5));
	b_verinPince->WhenPressed(new ChangementPositionPince());

	b_pivotMilieu->WhenPressed(new SetPivotSetpoint(Robot::pivot.MILIEU));
	b_pivotSwitchAvant->WhenPressed(new SetPivotSetpoint(Robot::pivot.SWITCH_AVANT));
	b_pivotSwitchArriere->WhenPressed(new SetPivotSetpoint(Robot::pivot.SWITCH_ARRIERE));
	b_pivotEchangeurAvant->WhenPressed(new SetPivotSetpoint(Robot::pivot.ECHANGEUR_AVANT));
	b_pivotEchangeurArriere->WhenPressed(new SetPivotSetpoint(Robot::pivot.ECHANGEUR_ARRIERE));
}

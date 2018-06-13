// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoMemeCote.h"

#include "AspirerCube.h"
#include "EjecterCube.h"
#include "PIDLigneDroite.h"
#include "PIDVirage.h"
#include "SetPivotSetpoint.h"

void AutoMemeCote::Init(char coteSwitch)
{
	if(coteSwitch == 'L')
	{
		rotation1 = 90;
	}
	else
	{
		rotation1 = -90;
	}
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoMemeCote::AutoMemeCote()
{
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	AddSequential(new PIDLigneDroite(340));
	AddSequential(new PIDVirage(rotation1));
	AddSequential(new SetPivotSetpoint(Pivot::SWITCH_AVANT));
	AddSequential(new PIDLigneDroite(25));
	AddSequential(new EjecterCube());

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }

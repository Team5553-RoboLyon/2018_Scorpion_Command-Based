/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "WPILib.h"
#include "Robot.h"

class OI
{
public:
	OI();

	Joystick* joystick = new Joystick(1);

	/*JoystickButton* b_changementVitesse;
	JoystickButton* b_aspirerCube;
	JoystickButton* b_ejecterCube;
	JoystickButton* b_verinPince;
	JoystickButton* b_pivotMilieu;
	JoystickButton* b_pivotSwitchAvant;
	JoystickButton* b_pivotSwitchArriere;
	JoystickButton* b_pivotEchangeurAvant;
	JoystickButton* b_pivotEchangeurArriere;*/

	JoystickButton* b_changementVitesse = new JoystickButton(joystick, 1);
	JoystickButton* b_aspirerCube = new JoystickButton(joystick, 2);
	JoystickButton* b_ejecterCube = new JoystickButton(joystick, 3);
	JoystickButton* b_verinPince = new JoystickButton(joystick, 4);

	JoystickButton* b_pivotMilieu = new JoystickButton(joystick, 8);
	JoystickButton* b_pivotSwitchAvant = new JoystickButton(joystick, 9);
	JoystickButton* b_pivotSwitchArriere = new JoystickButton(joystick, 10);
	JoystickButton* b_pivotEchangeurAvant = new JoystickButton(joystick, 11);
	JoystickButton* b_pivotEchangeurArriere = new JoystickButton(joystick, 12);
};

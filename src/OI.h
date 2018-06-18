#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	std::shared_ptr<frc::Joystick> joystick1;
	std::shared_ptr<frc::JoystickButton> button12;
	std::shared_ptr<frc::JoystickButton> button11;
	std::shared_ptr<frc::JoystickButton> button10;
	std::shared_ptr<frc::JoystickButton> button9;
	std::shared_ptr<frc::JoystickButton> button8;
	std::shared_ptr<frc::JoystickButton> button5;
	std::shared_ptr<frc::JoystickButton> button4;
	std::shared_ptr<frc::JoystickButton> button3;
	std::shared_ptr<frc::JoystickButton> button2;
	std::shared_ptr<frc::JoystickButton> button1;

public:
	OI();

	std::shared_ptr<frc::Joystick> getJoystick1();
};

#endif

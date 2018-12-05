#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "LiveWindow/LiveWindow.h"

#include "Commands/AutoMilieu.h"
#include "Commands/AutoOpposee.h"
#include "Commands/AutoMemeCote.h"
#include "Subsystems/BaseRoulante.h"
#include "Subsystems/Pince.h"
#include "Subsystems/Pivot.h"

#include "OI.h"


class Robot : public frc::TimedRobot
{
public:
	std::unique_ptr<AutoMilieu> m_AutoMilieu;
	std::unique_ptr<AutoMemeCote> m_AutoMemeCote;
	std::unique_ptr<AutoOpposee> m_AutoOpposee;
	std::unique_ptr<frc::Command> autonomousCommand{nullptr};

	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<char> positionChooser;

	static OI oi;
	static BaseRoulante baseRoulante;
	static Pince pince;
	static Pivot pivot;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif

#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
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
	AutoMilieu m_AutoMilieu;
	AutoMemeCote m_AutoMemeCote;
	AutoOpposee m_AutoOpposee;
	frc::Command* autonomousCommand = nullptr;

	static std::unique_ptr<OI> oi;
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<char> positionChooser;

	static std::shared_ptr<BaseRoulante> baseRoulante;
	static std::shared_ptr<Pince> pince;
	static std::shared_ptr<Pivot> pivot;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif

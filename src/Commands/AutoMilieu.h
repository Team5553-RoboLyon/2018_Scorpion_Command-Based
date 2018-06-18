#ifndef AUTOMILIEU_H
#define AUTOMILIEU_H

#include "Commands/CommandGroup.h"


class AutoMilieu: public frc::CommandGroup
{
public:
	void Init(char coteSwitch);
	AutoMilieu();

private:
	double rotation1et8, rotation2et7, rotation3et5, rotation4et6;
};

#endif

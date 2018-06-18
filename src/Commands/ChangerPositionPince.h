#ifndef CHANGERPOSITIONPINCE_H
#define CHANGERPOSITIONPINCE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class ChangerPositionPince: public frc::InstantCommand
{
public:
	ChangerPositionPince();
	void Initialize() override;

private:

};

#endif

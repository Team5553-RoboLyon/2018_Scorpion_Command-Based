#ifndef AUTOMEMECOTE_H
#define AUTOMEMECOTE_H

#include "Commands/CommandGroup.h"


class AutoMemeCote: public frc::CommandGroup
{
public:
	void Init(char coteSwitch);
	AutoMemeCote();

private:
	double rotation1;

};

#endif

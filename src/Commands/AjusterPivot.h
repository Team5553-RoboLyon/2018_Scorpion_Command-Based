#ifndef AJUSTERPIVOT_H
#define AJUSTERPIVOT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class AjusterPivot: public frc::Command
{
public:
	AjusterPivot();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	int pov;
};

#endif

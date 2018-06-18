#ifndef EJECTERCUBE_H
#define EJECTERCUBE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class EjecterCube: public frc::TimedCommand
{
public:
	EjecterCube();

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;

private:
	const double m_timeout = 0.5;
};

#endif

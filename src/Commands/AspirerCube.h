#ifndef ASPIRERCUBE_H
#define ASPIRERCUBE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class AspirerCube: public frc::TimedCommand
{
public:
	AspirerCube();

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;

private:
	const double m_timeout = 1.0;
	const double m_dureeApresFermeture = 0.2;

};

#endif

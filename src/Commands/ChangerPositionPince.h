#ifndef CHANGERPOSITIONPINCE_H
#define CHANGERPOSITIONPINCE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/*
 * Cette commande change la position du verin et donc ferme ou ouvre la pince suivant sa précedente position
 * Elle est "instantanée" et n'a donc ni Execute(), IsFinished(), End() et Interrupted() mais seulement un Initialize()
 */


class ChangerPositionPince: public frc::InstantCommand
{
public:
	ChangerPositionPince();
	void Initialize() override;

private:

};

#endif

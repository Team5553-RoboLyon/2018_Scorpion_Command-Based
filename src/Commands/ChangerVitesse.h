#ifndef CHANGERVITESSE_H
#define CHANGERVITESSE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/*
 * Cette commande change la position du ballshifter de la base et donc active la vitesse 1 ou 2 suivant sa précedente position
 * Elle est "instantanée" et n'a donc ni Execute(), IsFinished(), End() et Interrupted() mais seulement un Initialize()
 */


class ChangerVitesse: public frc::InstantCommand
{
public:
	ChangerVitesse();
	void Initialize() override;


private:

};

#endif

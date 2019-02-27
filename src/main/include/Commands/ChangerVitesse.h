#ifndef CHANGERVITESSE_H
#define CHANGERVITESSE_H


#include "frc/WPILib.h"
#include "Robot.h"


/*
 * Cette commande change la position du ballshifter de la base et donc active la vitesse 1 ou 2 suivant sa pr�cedente position
 * Elle est "instantan�e" et n'a donc ni Execute(), IsFinished(), End() et Interrupted() mais seulement un Initialize()
 */


class ChangerVitesse: public frc::InstantCommand
{
public:
	ChangerVitesse();
	void Initialize() override;


private:

};

#endif

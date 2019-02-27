#ifndef ASPIRERCUBE_H
#define ASPIRERCUBE_H


#include "frc/WPILib.h"
#include "Robot.h"


/*
 *  Cette commande fait tourner les roues pendant 1 seconde
 *  Elle ferme la pince 0.2 secondes avant la fin pour laisser les roues tourner (0.2 sec) apr�s la fermeture et s�curiser le cube
 *  On ferme donc la pince 1 sec - 0.2 sec = 0.8 sec apr�s avoir appel� la fonction
 *
 *  La commande est consid�r�e comme finie � la fin du chrono = 1 sec
 *
 *  Si elle est interompue plus de 0.2 sec avant la fin, la pince reste ouverte mais les roues s'arr�tent de tourner
 */


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

#include "PIDLigneDroite.h"


PIDLigneDroite::PIDLigneDroite(double distanceConsigne): Command()
{
    m_distanceConsigne = distanceConsigne;

    //Quand la commande est éxécutée elle stoppe la commande (si il y en a une) qui utilise le même subsystème
	Requires(&Robot::baseRoulante);

    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialisées
	distanceParcourueDroite = 0;
	erreurDroite = 0;
	erreurPrecedenteDroite = 0;
	sommeErreursDroite = 0;
	differenceErreursDroite = 0;

	distanceParcourueGauche = 0;
	erreurGauche = 0;
	erreurPrecedenteGauche = 0;
	sommeErreursGauche = 0;
	differenceErreursGauche = 0;

	vitesseDroite = 0;
}

void PIDLigneDroite::Initialize()
{
	//On reset les capteurs
	Robot::baseRoulante.ResetPID();

	erreurPrecedenteDroite = 0;
	erreurPrecedenteGauche = 0;
	sommeErreursDroite = 0;
	sommeErreursGauche = 0;
}

//Tant que la commande est active on passe par cette boucle
void PIDLigneDroite::Execute()
{
	//On recupère la valeur de l'encodeur pour calculer la distance parcourue
	distanceParcourueDroite = Robot::baseRoulante.GetEncodeurDroit() * r * 2 * M_PI / 263;

	erreurDroite = m_distanceConsigne - distanceParcourueDroite;
	sommeErreursDroite += erreurDroite;
	differenceErreursDroite = erreurDroite - erreurPrecedenteDroite;

	vitesseDroite = kP * erreurDroite + kI * sommeErreursDroite + kD * differenceErreursDroite;

	Robot::baseRoulante.Drive(vitesseDroite, -vitesseDroite);

	erreurPrecedenteDroite = erreurDroite;
}

bool PIDLigneDroite::IsFinished()
{
	return 	abs(erreurDroite) < tolerance;
}

void PIDLigneDroite::End()
{
	Robot::baseRoulante.Drive(0, 0);
}

void PIDLigneDroite::Interrupted()
{
	this->End();
}

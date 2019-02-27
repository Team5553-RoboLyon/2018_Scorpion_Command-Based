#include "Commands/PIDVirage.h"


PIDVirage::PIDVirage(double angleConsigne): Command()
{
    m_angleConsigne = angleConsigne;

    //Quand la commande est �x�cut�e elle stoppe la commande (si il y en a une) qui utilise le m�me subsyst�me
	Requires(&Robot::baseRoulante);

    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialis�es
	angleParcouru = 0;
	erreur = 0;
	erreurPrecedente = 0;
	sommeErreurs = 0;
	differenceErreurs = 0;
	vitesse = 0;
}

void PIDVirage::Initialize()
{
	//On reset les capteurs
	Robot::baseRoulante.ResetPID();

	erreurPrecedente = 0;
	sommeErreurs = 0;
}

//Tant que la commande est active on passe par cette boucle
void PIDVirage::Execute()
{
	//On recup�re la valeur du gyroscope
	angleParcouru = Robot::baseRoulante.GetGyro();

	erreur = m_angleConsigne - angleParcouru;
	sommeErreurs += erreur;
	differenceErreurs = erreur - erreurPrecedente;

	vitesse = kP * erreur + kI * sommeErreurs + kD * differenceErreurs;

	Robot::baseRoulante.Drive(vitesse, -vitesse);

	erreurPrecedente = erreur;
}

bool PIDVirage::IsFinished()
{
	return 	abs(erreur) < tolerance;
}

void PIDVirage::End()
{
	Robot::baseRoulante.Drive(0, 0);
}

void PIDVirage::Interrupted()
{
	this->End();
}

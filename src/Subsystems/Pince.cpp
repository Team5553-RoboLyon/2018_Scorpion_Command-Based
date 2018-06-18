#include "Pince.h"
#include "../RobotMap.h"
#include "WPILib.h"


Pince::Pince() : frc::Subsystem("Pince")
{
	//On r�cup�re tous les capteurs et controlleurs dont on � besoin
    roues = RobotMap::pinceRoues;
    verin = RobotMap::pinceVerin;

    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialis�es
    pinceOuverte = false;
}

void Pince::InitDefaultCommand()
{
	//Aucune  sera appel�e si aucune autre commande n'est en cours d'�x�cution
}

void Pince::Periodic()
{

}

//Fonctions simples qui vont �tre utilis�es par les commandes
void Pince::Ouvrir()
{
	verin->Set(frc::DoubleSolenoid::Value::kReverse);
	pinceOuverte = true;
}

void Pince::Fermer()
{
	verin->Set(frc::DoubleSolenoid::Value::kForward);
	pinceOuverte = false;
}

void Pince::ChangerPosition()
{
	if(pinceOuverte)
	{
		this->Fermer();
	}
	else
	{
		this->Ouvrir();
	}
}

void Pince::Aspirer()
{
	roues->Set(0.5);
}

void Pince::Ejecter()
{
	roues->Set(-1);
}

void Pince::Stop()
{
	roues->Set(0);
}

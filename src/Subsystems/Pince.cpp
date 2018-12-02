#include "Pince.h"
#include "WPILib.h"


Pince::Pince() : frc::Subsystem("Pince")
{
    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialisées
    pinceOuverte = false;
}

void Pince::InitDefaultCommand()
{
	//Aucune ne sera appelée si aucune autre commande n'est en cours d'exécution
}

void Pince::Periodic()
{

}

//Fonctions simples qui vont être utilisées par les commandes
void Pince::Ouvrir()
{
	verin.Set(frc::DoubleSolenoid::Value::kReverse);
	pinceOuverte = true;
}

void Pince::Fermer()
{
	verin.Set(frc::DoubleSolenoid::Value::kForward);
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
	roues.Set(0.5);
}

void Pince::Ejecter()
{
	roues.Set(-0.5);
}

void Pince::Stop()
{
	roues.Set(0);
}

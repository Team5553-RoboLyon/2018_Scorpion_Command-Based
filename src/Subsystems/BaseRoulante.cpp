#include "BaseRoulante.h"

#include "../Commands/DriveWithJoystick.h"

BaseRoulante::BaseRoulante() : frc::Subsystem("BaseRoulante")
{
    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialisées
    vitesse1 = true;

    baseDroite.SetInverted(false);
    baseDroite.SetInverted(true);
}

void BaseRoulante::InitDefaultCommand()
{
	//DriveWithJoystick() sera appelée si aucune autre commande n'est en cours d'éxécution
	SetDefaultCommand(new DriveWithJoystick());
}

void BaseRoulante::Periodic()
{

}

//Fonctions simples qui vont être utilisées par les commandes
void BaseRoulante::Drive(double gauche, double droite)
{
	baseGauche.Set(gauche);
	baseDroite.Set(droite);
}

void BaseRoulante::ActiverVitesse1()
{
	ballshiffter.Set(frc::DoubleSolenoid::Value::kReverse);
	vitesse1 = true;
}

void BaseRoulante::ActiverVitesse2()
{
	ballshiffter.Set(frc::DoubleSolenoid::Value::kForward);
	vitesse1 = false;
}

void BaseRoulante::ChangerVitesse()
{
	if(vitesse1 == true)
	{
		this->ActiverVitesse2();
	}
	else
	{
		this->ActiverVitesse1();
	}
}

int BaseRoulante::GetEncodeurDroit()
{
	return encodeurDroit.Get();
}

int BaseRoulante::GetGyro()
{
	return gyro.GetAngle();
}

void BaseRoulante::ResetPID()
{
	encodeurDroit.Reset();
	gyro.Reset();
}

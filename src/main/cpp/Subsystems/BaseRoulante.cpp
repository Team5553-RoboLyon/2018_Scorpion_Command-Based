#include "BaseRoulante.h"
#include "../RobotMap.h"

#include "../Commands/DriveWithJoystick.h"

BaseRoulante::BaseRoulante() : frc::Subsystem("BaseRoulante")
{
	//On récupère tous les capteurs et controlleurs dont on a besoin
    baseDroite2 = RobotMap::baseRoulanteBaseDroite2;
    baseDroite1 = RobotMap::baseRoulanteBaseDroite1;
    baseDroite = RobotMap::baseRoulanteBaseDroite;
    baseGauche1 = RobotMap::baseRoulanteBaseGauche1;
    baseGauche2 = RobotMap::baseRoulanteBaseGauche2;
    baseGauche = RobotMap::baseRoulanteBaseGauche;
    gyro = RobotMap::baseRoulanteGyro;
    encodeurDroit = RobotMap::baseRoulanteEncodeurDroit;
    encodeurGauche = RobotMap::baseRoulanteEncodeurGauche;
    ballshiffter = RobotMap::baseRoulanteBallshiffter;

    //Pour ne pas avoir d'avertissement :)
    //Ce n'est pas bien d'avoir des variables non-initialisées
    vitesse1 = true;
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
	baseGauche->Set(droite);
	baseDroite->Set(droite);
}

void BaseRoulante::ActiverVitesse1()
{
	ballshiffter->Set(frc::DoubleSolenoid::Value::kReverse);
	vitesse1 = true;
}

void BaseRoulante::ActiverVitesse2()
{
	ballshiffter->Set(frc::DoubleSolenoid::Value::kForward);
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
	return encodeurDroit->Get();
}

int BaseRoulante::GetGyro()
{
	return gyro->GetAngle();
}

void BaseRoulante::ResetPID()
{
	encodeurDroit->Reset();
	gyro->Reset();
}

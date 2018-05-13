/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Pince.h"
#include "../RobotMap.h"
#include "WPILib.h"

Pince::Pince() : Subsystem("Pince")
{
	Roues = new PWMVictorSPX(PWM_ROUES);
	Verin = new DoubleSolenoid(PCM_VERIN_PINCE_A, PCM_VERIN_PINCE_B);
}

void Pince::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Pince::Init()
{
	this->Stop();
	this->Fermer();
}

void Pince::Ouvrir()
{
	Verin->Set(frc::DoubleSolenoid::Value::kReverse);
	pinceOuverte = true;
}

void Pince::Fermer()
{
	Verin->Set(frc::DoubleSolenoid::Value::kForward);
	pinceOuverte = false;
}

void Pince::Aspirer()
{
	Roues->Set(0.5);
}

void Pince::Ejecter()
{
	Roues->Set(-1);
}

void Pince::Stop()
{
	Roues->Set(0);
}

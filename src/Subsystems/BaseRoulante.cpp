/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "BaseRoulante.h"
#include "WPILib.h"
#include "../RobotMap.h"

BaseRoulante::BaseRoulante() : Subsystem("BaseRoulante")
{
	BaseDroite1 = new VictorSP(PWM_BASE_DROITE_1);
	BaseDroite2 = new VictorSP(PWM_BASE_DROITE_2);
	BaseGauche1 = new VictorSP(PWM_BASE_GAUCHE_1);
	BaseGauche2 = new VictorSP(PWM_BASE_GAUCHE_2);

	Gyro = new ADXRS450_Gyro();
	Gyro->Calibrate();
	Gyro->Reset();

	EncodeurDroit = new Encoder(DIO_ENCODEUR_DROIT_A, DIO_ENCODEUR_DROIT_B,false, Encoder::EncodingType::k4X);
	EncodeurGauche = new Encoder(DIO_ENCODEUR_GAUCHE_A, DIO_ENCODEUR_GAUCHE_B, false, Encoder::EncodingType::k4X);
	EncodeurDroit->Reset();
	EncodeurGauche->Reset();

	DoubleSolenoid1 = new DoubleSolenoid(PCM_BALLSHIFTER_A, PCM_BALLSHIFTER_B);
}

void BaseRoulante::InitDefaultCommand()
{
	SetDefaultCommand(new TankDrive());
}

void BaseRoulante::Init()
{
	this->ActiverVitesse1();
}

void BaseRoulante::Drive(double gauche, double droite)
{
	BaseGauche1->Set(gauche);
	BaseGauche2->Set(gauche);
	BaseDroite1->Set(droite);
	BaseDroite2->Set(droite);
}

void BaseRoulante::ActiverVitesse1()
{
	DoubleSolenoid1->Set(frc::DoubleSolenoid::Value::kReverse);
	vitesse1 = true;
}

void BaseRoulante::ActiverVitesse2()
{
	DoubleSolenoid1->Set(frc::DoubleSolenoid::Value::kForward);
	vitesse1 = false;
}

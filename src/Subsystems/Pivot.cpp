/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Pivot.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include "WPILib.h"

#include "../RobotMap.h"

Pivot::Pivot() : PIDSubsystem("Pivot", kP, kI, kD)
{
	Moteur = new PWMVictorSPX(PWM_PIVOT);
	Encodeur = new Encoder(DIO_ENCODEUR_PIVOT_A, DIO_ENCODEUR_PIVOT_B);
	Encodeur->Reset();

	SetAbsoluteTolerance(20);
	SetInputRange(-700, 700);
	SetSetpoint(MILIEU);
	Enable();
}

double Pivot::ReturnPIDInput()
{
	return Encodeur->Get();
}

void Pivot::UsePIDOutput(double output)
{
	Moteur->PIDWrite(output);
}

void Pivot::InitDefaultCommand()
{
	SetDefaultCommand(new AjusterPivot());
}

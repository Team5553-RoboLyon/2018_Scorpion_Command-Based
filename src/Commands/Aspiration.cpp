/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Aspiration.h"

Aspiration::Aspiration(double timeout, double dureeApresFermeture) : TimedCommand(timeout)
{
	Requires(&Robot::pince);
	m_dureeApresFermeture = dureeApresFermeture;
	m_duree = timeout;
}

void Aspiration::Initialize()
{

}

void Aspiration::Execute()
{
	Robot::pince.Aspirer();

	if(this->TimeSinceInitialized() > m_duree - m_dureeApresFermeture)
	{
		Robot::pince.Fermer();
	}
}

void Aspiration::End()
{
	Robot::pince.Stop();
}

void Aspiration::Interrupted()
{
	Robot::pince.Stop();
}

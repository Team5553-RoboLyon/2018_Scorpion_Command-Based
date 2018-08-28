#include "OI.h"
#include "Robot.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AjusterPivot.h"
#include "Commands/AspirerCube.h"
#include "Commands/AutoMemeCote.h"
#include "Commands/AutoMilieu.h"
#include "Commands/AutoOpposee.h"
#include "Commands/ChangerPositionPince.h"
#include "Commands/ChangerVitesse.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/EjecterCube.h"
#include "Commands/PIDLigneDroite.h"
#include "Commands/PIDVirage.h"
#include "Commands/SetPivotSetpoint.h"


OI::OI()
{
    // Process operator interface input here.
    joystick1.reset(new frc::Joystick(0));
    
    button12.reset(new frc::JoystickButton(joystick1.get(), 12));
    button12->WhenPressed(new SetPivotSetpoint(Pivot::ECHANGEUR_ARRIERE));
    button11.reset(new frc::JoystickButton(joystick1.get(), 11));
    button11->WhenPressed(new SetPivotSetpoint(Pivot::ECHANGEUR_AVANT));
    button10.reset(new frc::JoystickButton(joystick1.get(), 10));
    button10->WhenPressed(new SetPivotSetpoint(Pivot::SWITCH_ARRIERE));
    button9.reset(new frc::JoystickButton(joystick1.get(), 9));
    button9->WhenPressed(new SetPivotSetpoint(Pivot::SWITCH_AVANT));
    button8.reset(new frc::JoystickButton(joystick1.get(), 8));
    button8->WhenPressed(new SetPivotSetpoint(Pivot::MILIEU));
    button4.reset(new frc::JoystickButton(joystick1.get(), 4));
    button4->WhenPressed(new ChangerPositionPince());
    button3.reset(new frc::JoystickButton(joystick1.get(), 3));
    button3->WhenPressed(new EjecterCube());
    button2.reset(new frc::JoystickButton(joystick1.get(), 2));
    button2->WhenPressed(new AspirerCube());
    button1.reset(new frc::JoystickButton(joystick1.get(), 1));
    button1->WhenPressed(new ChangerVitesse());

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("AutoMemeCote", new AutoMemeCote());
    frc::SmartDashboard::PutData("AutoOpposee", new AutoOpposee());
    frc::SmartDashboard::PutData("AutoMilieu", new AutoMilieu());
    frc::SmartDashboard::PutData("SetPivotSetpoint: milieu", new SetPivotSetpoint(Pivot::MILIEU));
    frc::SmartDashboard::PutData("SetPivotSetpoint: echangeurAvant", new SetPivotSetpoint(Pivot::ECHANGEUR_AVANT));
    frc::SmartDashboard::PutData("SetPivotSetpoint: echangeurArriere", new SetPivotSetpoint(Pivot::ECHANGEUR_ARRIERE));
    frc::SmartDashboard::PutData("SetPivotSetpoint: switchAvant", new SetPivotSetpoint(Pivot::SWITCH_AVANT));
    frc::SmartDashboard::PutData("SetPivotSetpoint: switchArriere", new SetPivotSetpoint(Pivot::SWITCH_ARRIERE));
    frc::SmartDashboard::PutData("ChangerPositionPince", new ChangerPositionPince());
    frc::SmartDashboard::PutData("EjecterCube: dureeEjection", new EjecterCube());
    frc::SmartDashboard::PutData("AspirerCube: dureeAspiration", new AspirerCube());
    frc::SmartDashboard::PutData("ChangerVitesse", new ChangerVitesse());
    frc::SmartDashboard::PutData("DriveWithJoystick", new DriveWithJoystick());
}

std::shared_ptr<frc::Joystick> OI::getJoystick1()
{
   return joystick1;
}

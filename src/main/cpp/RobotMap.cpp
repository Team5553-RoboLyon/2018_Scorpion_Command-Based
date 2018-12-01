#include "WPILib.h"

#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<frc::SpeedController> RobotMap::baseRoulanteBaseDroite2;
std::shared_ptr<frc::SpeedController> RobotMap::baseRoulanteBaseDroite1;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::baseRoulanteBaseDroite;
std::shared_ptr<frc::SpeedController> RobotMap::baseRoulanteBaseGauche1;
std::shared_ptr<frc::SpeedController> RobotMap::baseRoulanteBaseGauche2;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::baseRoulanteBaseGauche;
std::shared_ptr<frc::AnalogGyro> RobotMap::baseRoulanteGyro;
std::shared_ptr<frc::Encoder> RobotMap::baseRoulanteEncodeurDroit;
std::shared_ptr<frc::Encoder> RobotMap::baseRoulanteEncodeurGauche;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::baseRoulanteBallshiffter;
std::shared_ptr<frc::SpeedController> RobotMap::pinceRoues;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::pinceVerin;
std::shared_ptr<frc::SpeedController> RobotMap::pivotMoteur;
std::shared_ptr<frc::Encoder> RobotMap::pivotEncodeur;

void RobotMap::init()
{
	//Création de tous les capteurs et controlleurs

    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    baseRoulanteBaseDroite2.reset(new frc::PWMVictorSPX(1));
    lw->AddActuator("BaseRoulante", "BaseDroite2", std::static_pointer_cast<frc::PWMVictorSPX>(baseRoulanteBaseDroite2));
    
    baseRoulanteBaseDroite1.reset(new frc::PWMVictorSPX(0));
    lw->AddActuator("BaseRoulante", "BaseDroite1", std::static_pointer_cast<frc::PWMVictorSPX>(baseRoulanteBaseDroite1));
    
    baseRoulanteBaseDroite = std::make_shared<frc::SpeedControllerGroup>(*baseRoulanteBaseDroite1, *baseRoulanteBaseDroite2  );
    lw->AddActuator("BaseRoulante", "BaseDroite", baseRoulanteBaseDroite);
    baseRoulanteBaseDroite->SetInverted(false);
    
    baseRoulanteBaseGauche1.reset(new frc::PWMVictorSPX(2));
    lw->AddActuator("BaseRoulante", "BaseGauche1", std::static_pointer_cast<frc::PWMVictorSPX>(baseRoulanteBaseGauche1));
    
    baseRoulanteBaseGauche2.reset(new frc::PWMVictorSPX(3));
    lw->AddActuator("BaseRoulante", "BaseGauche2", std::static_pointer_cast<frc::PWMVictorSPX>(baseRoulanteBaseGauche2));
    
    baseRoulanteBaseGauche = std::make_shared<frc::SpeedControllerGroup>(*baseRoulanteBaseGauche1, *baseRoulanteBaseGauche2  );
    lw->AddActuator("BaseRoulante", "BaseGauche", baseRoulanteBaseGauche);
    baseRoulanteBaseDroite->SetInverted(true);
    
    baseRoulanteGyro.reset(new frc::AnalogGyro(0));
    lw->AddSensor("BaseRoulante", "Gyro", baseRoulanteGyro);
    baseRoulanteGyro->SetSensitivity(0.007);

    baseRoulanteEncodeurDroit.reset(new frc::Encoder(0, 1, true, frc::Encoder::k4X));
    lw->AddSensor("BaseRoulante", "EncodeurDroit", baseRoulanteEncodeurDroit);
    baseRoulanteEncodeurDroit->SetDistancePerPulse(1.0);
    baseRoulanteEncodeurDroit->SetPIDSourceType(frc::PIDSourceType::kRate);

    baseRoulanteEncodeurGauche.reset(new frc::Encoder(2, 3, false, frc::Encoder::k4X));
    lw->AddSensor("BaseRoulante", "EncodeurGauche", baseRoulanteEncodeurGauche);
    baseRoulanteEncodeurGauche->SetDistancePerPulse(1.0);
    baseRoulanteEncodeurGauche->SetPIDSourceType(frc::PIDSourceType::kRate);

    //Warning, the two modules in robot builder are different!
    baseRoulanteBallshiffter.reset(new frc::DoubleSolenoid(0, 0, 1));
    lw->AddActuator("BaseRoulante", "Ballshiffter", baseRoulanteBallshiffter);
    
    pinceRoues.reset(new frc::PWMVictorSPX(4));
    lw->AddActuator("Pince", "Roues", std::static_pointer_cast<frc::PWMVictorSPX>(pinceRoues));
    
    //Warning, the two modules in robot builder are different!
    pinceVerin.reset(new frc::DoubleSolenoid(2, 3));
    lw->AddActuator("Pince", "Verin", pinceVerin);
    
    pivotMoteur.reset(new frc::PWMVictorSPX(5));
    lw->AddActuator("Pivot", "Moteur", std::static_pointer_cast<frc::PWMVictorSPX>(pivotMoteur));
    
    pivotEncodeur.reset(new frc::Encoder(4, 5, false, frc::Encoder::k4X));
    lw->AddSensor("Pivot", "Encodeur", pivotEncodeur);
    pivotEncodeur->SetDistancePerPulse(1.0);
    pivotEncodeur->SetPIDSourceType(frc::PIDSourceType::kRate);
}

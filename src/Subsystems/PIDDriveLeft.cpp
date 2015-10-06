#include "PIDDriveLeft.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

PIDDriveLeft::PIDDriveLeft() :
	PIDSubsystem("PIDDriveLeft", 1.0, 0.0, 0.0),
	encoderLeft(5),
	LeftSpeedController(LEFT_DRIVE_PORT)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	encoderLeft.Reset();
	encoderLeft.SetPIDSourceParameter(PIDSource::kRate);
	encoderLeft.SetDistancePerPulse((M_PI)/4096);
	SetSetpoint(0);
	Enable();
}

double PIDDriveLeft::ReturnPIDInput()

{

}

void PIDDriveLeft::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void PIDDriveLeft::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void PIDDriveLeft::Stop() {
}

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/AutoCommand.h"
#include "Commands/AutoGrabToteCommand.h"
#include "Commands/AutoStackTotes.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();
//		autonomousCommand = new AutoCommand();
		chooser = new SendableChooser();
		chooser->AddDefault("Move Forward", new AutoCommand());
		chooser->AddObject("Move forward and grab tote", new AutoGrabToteCommand());
		chooser->AddObject("Stack totes", new AutoStackTotes());
		SmartDashboard::PutData("Autonomous mode", chooser);
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command*) chooser->GetSelected();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);


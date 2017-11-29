#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <CANTalon.h>
#include <Joystick.h>

class Robot: public frc::IterativeRobot {
public:
	Joystick *driverController;

		CANTalon *fL, *fR, *bL, *bR;
	void RobotInit() {
		driverController = new Joystick(0);

		fL = new CANTalon(14);//front left
		fR = new CANTalon(13);//front right
		bR = new CANTalon(12);//back right
		bL = new CANTalon(15);//back left

	}

	
	void AutonomousInit() override {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {
		if(driverController->GetRawAxis(1) < 2.4 || driverController->GetRawAxis(1) > -2.4)
		{
			fL->Set(driverController->GetRawAxis(1));
			bL->Set(driverController->GetRawAxis(1));
		}
		if(driverController->GetRawAxis(5) < 2.4 || driverController->GetRawAxis(5) > -2.4)
				{
					fR->Set(driverController->GetRawAxis(5));
					bR->Set(driverController->GetRawAxis(5));
				}
	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();

};

START_ROBOT_CLASS(Robot)

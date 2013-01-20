#ifndef TinMan_h
#define TinMan_h

#include "WPILib.h"
#include "RobotDefines.h"


//******************************************************************************
//******************************************************************************
class TinMan : public SimpleRobot
{

public:
	
	//*** constructor ***
	TinMan(void);

	//*** autonomous mode code ***
	void Autonomous(void);

	//*** teleop code ***
	void OperatorControl(void);
	
	//*** test mode ***
	void Test(void);
	
protected:
	
	//*** variables ***
	
	RobotDrive *drive; 	    // robot drive system
	
	Joystick   *stick; 		// only joystick
	
	//*** methods ***
	
	//*** drive the robot ***
	void handleDriving();
	
	//*** handle joystick buttons ***
	void handleJoystickButtons();
	
	//*** handle limit switches ***
	void handleLimitSwitches();
	
	//*** joystick button states ***
	bool isRampDownActivated();
	bool isRampUpActivated();
	bool isReadConfigActivated();
	bool isShootBallActivated();
	bool isToggleBallMoveActivated();
	bool isReverseBallMoveActivated();
	
	//*** joystick button handlers ***
	void doRampDown();
	void doRampUp();
	void doReadConfig();
	void doShootBall();
	void doToggleBallMove();
	void doReverseBallMove();
	
	//*** limit switch states ***
	bool isShooterReadySwitchActivated();
	bool isRampUpSwitchActivated();

	//*** limit switch handlers ***
	void handleShooterReadyActivated();
	void handleRampUpActivated();
};

#endif

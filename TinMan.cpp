#include "TinMan.h"

//*** constants ***

const float EXPIRATION_TIME = 0.5;

const float AUTO_DRIVE_SPEED = 0.5;
const float DRIVE_STRAIGHT = 0.0;

const float DRIVE_TIME_SECS = 2.0;

const float STOP_ROBOT = 0.0;

const float MAIN_LOOP_DELAY = 0.005;


//******************************************************************************
//******************************************************************************
/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
TinMan::TinMan(void)
{
	//*** create robot object ***
	drive = new RobotDrive( PWM_LEFT_DRIVE_MOTOR, PWM_RIGHT_DRIVE_MOTOR );
	
	//*** create joystick object ***
	stick = new Joystick( PORT_DRIVER_JOYSTICK );
	
	//*** set up expiration timeout ***
	drive->SetExpiration( EXPIRATION_TIME );
}


//******************************************************************************
//******************************************************************************
/**
 * Drive left & right motors for 2 seconds then stop
 */
void TinMan::Autonomous(void)
{
	//*** disable safety in autonomous mode ***
	drive->SetSafetyEnabled(false);
	
	//*** drive forward at half speed ***
	drive->Drive( AUTO_DRIVE_SPEED, DRIVE_STRAIGHT );
	
	//*** drive for 2 seconds ***
	Wait( DRIVE_TIME_SECS );
	
	//*** stop robot ***
	drive->Drive( STOP_ROBOT, DRIVE_STRAIGHT );
}


//******************************************************************************
//******************************************************************************
/**
 * Runs the motors with arcade steering. 
 */
void TinMan::OperatorControl(void)
{
	//*** use safety ***
	drive->SetSafetyEnabled( true );
	
	//*** main while loop ***
	while ( IsOperatorControl() )
	{
		//*** handle limit switches ***
		handleLimitSwitches();
		
		//*** implement driving ***
		handleDriving();
		
		//*** handle all joystick buttons ***
		handleJoystickButtons();
		
		//*** give it time to update ***
		Wait( MAIN_LOOP_DELAY );
	}
}


//******************************************************************************
//******************************************************************************
/**
 * implement driving 
 */
void TinMan::handleDriving()
{
	//*** handle arcade drive ***
	drive->ArcadeDrive(stick);
}


//******************************************************************************
//******************************************************************************
/**
 * Checks if we need to shoot 
 */
void TinMan::handleJoystickButtons()
{
	//*** shoot ball ***
	if ( isShootBallActivated() )
	{
		doShootBall();
	}
	
	//*** ramp down ***
	if ( isRampDownActivated() )
	{
		doRampDown();
	}
	
	//*** ramp up ***
	if ( isRampUpActivated() )
	{
		doRampUp();
	}
	
	//*** read config ***
	if ( isReadConfigActivated() )
	{
		doReadConfig();
	}
	
	//*** toggle ball movement running ***
	if ( isToggleBallMoveActivated() )
	{
		doToggleBallMove();
	}
	
	//*** reverse ball movement direction ***
	if ( isReverseBallMoveActivated() )
	{
		doReverseBallMove();
	}
}


//******************************************************************************
//******************************************************************************
/**
 * Handle limit switches 
 */
void TinMan::handleLimitSwitches()
{
	//*** shooter ready switch ***
	if ( isShooterReadySwitchActivated() )
	{
		handleShooterReadyActivated();
	}
	
	//*** ramp up ***
	if ( isRampUpSwitchActivated() )
	{
		handleRampUpActivated();
	}
}





//************************************
//*** DO NOT REMOVE THE LAST LINE ****
//************************************
START_ROBOT_CLASS(TinMan);


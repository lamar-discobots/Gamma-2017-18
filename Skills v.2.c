#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in8,    Lift1_R,        sensorPotentiometer)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           InstaL,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Right,         tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port3,           Left,          tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port4,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RaiseR,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RaiseL,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           Lift1_R,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Lift1_L,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          InstaR,        tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define abs(X) ((X < 0) ? -1 * X : X)
#define M_PI acos(-1.0)

float wheelRadiusCM = 10.16;

//define functions
int getStraightGoal(float cm);
int getRotationGoal(float deg);

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

task autonomous()
{
	motor[Lift1_L]=motor[Lift1_R]=127;
	motor[Lift1_L]=motor[Lift1_R]=0;
	//lifts lift
	motor[InstaL]=motor[InstaR]=-127;
	motor[InstaL]=motor[InstaR]=0;
	//moblie down
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(300))
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	//foward pushing mobiles
	motor[InstaL]=motor[InstaR]=-127;
	motor[InstaL]=motor[InstaR]=0;
	//lifts mobile
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(44.84))
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	//puts mobile in zone
	motor[InstaL]=motor[InstaR]=-127;
	motor[InstaL]=motor[InstaR]=0;
	//drops mobile in zone
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(344.84))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	//backs it up
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getRotationGoal(90))
	{
		motor[Left]= -127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	//turns
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(86.21))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	//foward
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getRotationGoal(90))
	{
		motor[Left]= 127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	//turns
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(300))
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	motor[InstaL]=motor[InstaR]=127;
	motor[InstaL]=motor[InstaR]=0;
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(44.84))
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	motor[InstaL]=motor[InstaR]=-127;
	motor[InstaL]=motor[InstaR]=0
	;
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(344.84))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getRotationGoal(60))
	{
		motor[Left]= -127;
		motor[Right]= 127;
	}
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(365.76))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
}

task usercontrol()
{
	while (true)
	{
		int leftside=vexRT(Ch3);
		int rightside=vexRT(Ch2);
		int liftup=vexRT(Btn6U);
		int liftdown=vexRT(Btn6D);
		int clawopen=vexRT(Btn5U);
		int clawclose=vexRT(Btn5D);
		int mobileup=vexRT(Btn8D);
		int mobiledown=vexRT(Btn8U);
		int RaiseUpManual=vexRT (Btn7D);
		int RaiseDownManual=vexRT (Btn7U);

		if (leftside >=10)
			{motor [Left] =leftside;}
		else if (leftside <=-10)
			{motor [Left] =leftside;}
		else
			{motor [Left] =0;}
// Leftside of the drivetrain

		if (rightside >=10)
			{motor [Right] =rightside;}
		else if (rightside <=-10)
			{motor [Right] =rightside;}
		else
			{motor [Right] =0;}
// Rightside of the drivetrain

		if (liftup == 1){
			motor [Lift1_R] = 127;
			motor [Lift1_L] = 127;
			motor [RaiseR] = 127;
			motor [RaiseL] = 127;
		}
// Lift 1 and raise to go up
		else if (liftdown == 1){
			motor [Lift1_L] = -127;
			motor [Lift1_R] = -127;
			motor [RaiseR] = -127;
			motor [RaiseL] = -127;
		}
// Lift 1 and raise to go down
		else{
			motor [Lift1_R] = 0;
			motor [Lift1_L] = 0;
			motor [RaiseR] = 0;
			motor [RaiseL] = 0;
		}
// If the Lift 1 button isn't pressed then it won't move and the raise won't move

		if (clawopen == 1)
	  	motor [Claw] = 127;
// Opens the claw
	 	else if (clawclose == 1)
	 	  motor [Claw] = -127;
// Closes the claw
	 	else
	 		{motor [Claw] = 0;}
// If the claw button isn't pressed then there will be no claw movement

   	if (mobiledown == 1){
   		motor[InstaR] = 127;
   		motor[InstaL] = 127;
  	}
  	else if (mobileup == 1){
  		motor[InstaR] = -127;
  		motor[InstaL] = -127;
  	}
  	else {
  		motor [InstaR] = 0;
  		motor [InstaL] = 0;
  	}

//RaiseUpManual
			if (RaiseUpManual == 1){
			motor [RaiseR] = 127;
			motor [RaiseL] = 127;
		}
// Raise to go up
		else if (RaiseDownManual == 1){
			motor [RaiseL] = -127;
			motor [RaiseR] = -127;}
// Raise to go down
		else{
			motor [RaiseR] = 0;
			motor [RaiseL] = 0;}
    UserControlCodePlaceholderForTesting();
  }
}

/*** FUNCTIONS ***/

int getStraightGoal(float cm) {
		return 392*(cm/(wheelRadiusCM*M_PI));
}

int getRotationGoal(float deg) {
		return 392*(deg/102.9);
}

//END FUNCTIONS

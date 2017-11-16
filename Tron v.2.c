#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           InstaL,        tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           Left,          tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port3,           Right,         tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port5,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Lift1_R,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Lift1_L,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          InstaR,        tmotorVex393_HBridge, openLoop)
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
	motor[Lift1_L]= 127;
	motor[Lift1_R]= 127;
	wait(1);
	motor[Lift1_L]= 0;
	motor[Lift1_R]= 0;
// The lift moves up 1 second

	nMotorEncoder[Left]= 0;
	nMotorEncoder[Right]= 0;

	while(abs(nMotorEncoder[Left]) < 20000)
	while(abs(nMotorEncoder[Right]) < 2000)
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
//Robot goes forward

	motor[Lift1_L]= -100;
	motor[Lift1_R]= -100;
	wait(0.5);
//The lift moves down 0.5 seconds
 	motor[Lift1_L]= 0;
	motor[Lift1_R]= 0;
//The lift stops

	motor[Claw]= 127;
	wait(0.5);
//Opens claw

	motor[Lift1_L]= 100;
	motor[Lift1_R]= 100;
	wait(1);
//The lift moves up 1 second
 	motor[Lift1_L]= 0;
	motor[Lift1_R]= 0;
//The lift stops

	motor[InstaL]= 100;
	motor[InstaR]= 100;
	wait(1);
//Mobile goal goes forward

	motor[InstaL]= 0;
	motor[InstaR]= 0;
//M0obile goal stops

	motor[InstaL]= -100;
	motor[InstaR]= -100;
	wait(1);
//Mobile goal goes backward

	motor[InstaL&&InstaR]=0;
//Mobile goal stops

	nMotorEncoder[Left]= 0;
	nMotorEncoder[Right]= 0;

	while(abs(nMotorEncoder[Left]) < 1000)
	while(abs(nMotorEncoder[Right]) < 1000)
	{
		motor[Left]= -100;
		motor[Right]= -100;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// Robot goes backwards

	motor[Claw]= 0;
//Claw stops

	/*#define abs(X) ((X < 0) ? -1 * X : X)

	void driveDistance(int tenthsOfIn, int power)
	{
	SensorValue[Left] = 0;
	SensorValue[Right] = 0;

	int tickGoal= (29* tenthsOfIn) / 10;

	while (abs(SensorValue[Left&&Right]) < tickGoal)
	{
		motor[Left]= power;
		motor[Right]= power;
	}
	motor[Left]= 0;
	motor[Right]= 0;
	}
}*/
}

task usercontrol()
{
	while (true)
	{
		int leftside=vexRT(Ch2);
		int rightside=vexRT(Ch3);
		int liftup=vexRT(Btn6U);
		int liftdown=vexRT(Btn6D);
		int clawopen=vexRT(Btn5U);
		int clawclose=vexRT(Btn5D);
		int mobileup=vexRT(Btn8U);
		int mobiledown=vexRT(Btn8D);

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
		}
// Lift 1 to go up
		else if (liftdown == 1){
			motor [Lift1_L] = -127;
			motor [Lift1_R] = -127;
		}
// Lift 1 to go down
		else{
			motor [Lift1_R] = 0;
			motor [Lift1_L] = 0;
		}
// If the Lift 1 button isn't pressed then it won't move

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

    UserControlCodePlaceholderForTesting();
  }
}

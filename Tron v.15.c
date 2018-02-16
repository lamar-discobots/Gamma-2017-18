#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in8,    Lift1_R,        sensorPotentiometer)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           InstaL,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Right,         tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port3,           Left,          tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port6,           LiftL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          InstaR,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define abs(X) ((X < 0) ? -1 * X : X)
#define M_PI acos(-1.0)

float wheelRadiusCM = 10.16;

//define functions
int getStraightGoal(float cm);
int getRotationGoal(float deg);
void moveArm(float deg, int armSpeed);

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

void pre_auton()
{
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
  bStopTasksBetweenModes = true;
}

task autonomous()
{
	motor[LiftL]= 127;
	motor[LiftR]= 127;
	wait(1);
	motor[LiftL]= 0;
	motor[LiftR]= 0;
//The lift moves up 1 second

	motor[InstaL]= 127;
	motor[InstaR]= 127;
	wait(0.5);
//Mobile goal goes forward
	motor[InstaL]= 0;
	motor[InstaR]= 0;
//Mobile goal stops

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(125))
	{
		motor[Left]= 85;
		motor[Right]= 85;
	}
	motor[Left]= 0;
	motor[Right]= 0;
//Robot goes forward to collect the mobile goal

	motor[LiftL]= -127;
	motor[LiftR]= -127;
	wait (1);
//The lift moves down 1 second
 	motor[LiftL]= 0;
	motor[LiftR]= 0;
//The lift stops

	motor[Claw]= 127;
	wait(1.5);
	motor[LiftL]= 127;
	motor[LiftR]= 127;
	wait(1.5);
//The lift moves up 1.5 seconds
 	motor[LiftL]= 0;
	motor[LiftR]= 0;
	motor[Claw]= 0;
//The lift stops

	motor[InstaL]= -127;
	motor[InstaR]= -127;
	wait(0.5);
//Mobile goal goes backward
	motor[InstaL]=0;
	motor[InstaR]=0;
//Mobile goal stops

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(122))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// The robot goes  backward from collecting the mobile goal

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getRotationGoal(265))
	{
		motor[Left]= -127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// The robot turns 265 degrees

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(45))
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// Robot goes forward for a little bit

	motor[InstaL]= 127;
	motor[InstaR]= 127;
	wait(0.5);
//Mobile goal goes forward
	motor[InstaL]= 0;
	motor[InstaR]= 0;
//Mobile goal stops

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(50))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// The robot backs away

	motor[Claw]= 0;
// Claw stops
}

task usercontrol()
{
	while (true)
	{
		int liftup=vexRT(Btn6U);
		int liftdown=vexRT(Btn6D);
		int clawopen=vexRT(Btn5U);
		int clawclose=vexRT(Btn5D);
		int mobileup=vexRT(Btn8D);
		int mobiledown=vexRT(Btn8U);
		int leftstickX;
  	int leftstickY;
  	int deadzone   = 5;

/////////// Arcade Drive////////////////////////
  	if(abs(vexRT[Ch3]) >deadzone)
  	{leftstickY = vexRT[Ch3];}

		else
		{leftstickY = 0;}

		if(abs(vexRT[Ch4]) > deadzone)
		{leftstickX = vexRT[Ch4];}

		else
		{leftstickX =0 ;}

		motor[Left] = leftstickY + leftstickX;
		motor[Right]= leftstickY - leftstickX;
/////////// Arcade Drive///////////////////////

/////////// Lift///////////////////////////////
		if (liftup == 1)
		{
			motor [LiftR] = 127;
			motor [LiftL] = 127;
		}

		else if (liftdown == 1)
		{
			motor [LiftL] = -127;
			motor [LiftR] = -127;
		}

		else
		{
			motor [LiftR] = 0;
			motor [LiftL] = 0;
		}
/////////// Lift///////////////////////////////

/////////// Claw///////////////////////////////
		if (clawopen == 1)
	  	motor [Claw] = 127;

	 	else if (clawclose == 1)
	 	  motor [Claw] = -127;

	 	else
	 		{motor [Claw] = 0;}
/////////// Claw///////////////////////////////

/////////// Mobile Goal////////////////////////
   	if (mobiledown == 1)
   	{
   		motor[InstaR] = 63.5;
   		motor[InstaL] = 63.5;
  	}

  	else if (mobileup == 1)
  	{
  		motor[InstaR] = -63.5;
  		motor[InstaL] = -63.5;
  	}

  	else
  	{
  		motor [InstaR] = 0;
  		motor [InstaL] = 0;
  	}
/////////// Mobile Goal////////////////////////

    UserControlCodePlaceholderForTesting();
  }
}

/////////// Functions//////////////////////////
	int getStraightGoal(float cm)
		{return 392*(cm/(wheelRadiusCM*M_PI));}

	int getRotationGoal(float deg)
		{return 392*(deg/102.9);}

void moveArm(float deg, int armSpeed)
{
	armSpeed = abs(armSpeed);

		if(deg < SensorValue[LiftR])
		{
			while(SensorValue[LiftR] <= deg)
			{motor[LiftR] = motor[LiftL] = armSpeed;}
		}

		else
		{
			while(SensorValue[LiftR] >= deg)
			{motor[LiftR] = motor[LiftL] = -armSpeed;}
		}
}
/////////// End of Functions///////////////////

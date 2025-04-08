/*
 *****************************************************************************
 *  CarMaker - Version 14.0
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2024 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 *
 * Simple VehicleControl Model to demonstrate the manipulation of Driver Gas
 *
 * Add the declaration of the register function to one of your header files,
 * for example to User.h and call it in User_Register()
 *
 *    VehicleControl_Register_LKAS ()
 *
 *****************************************************************************
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Vehicle/Sensor_Road.h>

#include "CarMaker.h"
#include "Car/Vehicle_Car.h"
#include "LKAS.h"
#include <stdbool.h>

struct tMyModel {
    /* parameters of MyVehicleControl */
    double GasFac;

    /* variables of MyVehicleControl */
    double Gas;
};

static char const ThisModelClass[] = "VehicleControl";
static char const ThisModelKind[]  = "LKAS";
static int const  ThisVersionId    = 1;

/******************************************************************************/

static void
MyModel_DeclQuants_dyn(struct tMyModel *mp, int park)
{
    static struct tMyModel MyModel_Dummy = {0};
    if (park) {
        mp = &MyModel_Dummy;
    }

    /* Define here dict entries for dynamically allocated variables. */

    //DDefDouble4(NULL, "MyVehicleControl.Gas", "", &mp->Gas, DVA_None);
}

static void
MyModel_DeclQuants(void *MP)
{
    struct tMyModel *mp = (struct tMyModel *) MP;

    if (mp == NULL) {
        /* Define here dict entries for non-dynamically allocated (static) variables. */

    } else {
        MyModel_DeclQuants_dyn(mp, 0);
    }
}

// double devDist=0;
// double d_dist1;
// double st=3;
// static int
// MyModel_Calc(void *MP, double dt)
// {
//     struct tMyModel *mp = (struct tMyModel *) MP;

//     /* Manipulation of VehicleControl */
//    /* mp->Gas            = mp->GasFac * VehicleControl.Gas;
//     VehicleControl.Gas = mp->Gas;*/
// /*	
// double Dev_Dist= DrivMan.LaneOffset;
// if(Dev_Dist>0.5 || Dev_Dist<-0.5)
//  {
//   DrivMan.LaneOffset=0;
//  }
//  */

//  devDist = RoadSensor->Route.Deviation.Dist;

//  static bool devDistExecuted = false;
//  if (!devDistExecuted && devDist < 0)
//  {
//      d_dist1 = devDist;  // Only execute this once
//      devDistExecuted = true;  // Set the flag to true after the code runs
//     // Log("%.5f",d_dist1);
//  }

//     if(devDist > d_dist1)
//     {
//         VehicleControl.Steering.Ang=-3;
//         Log("devDist= %.5f  d_dist= %.5f \n",devDist,d_dist1);
//         devDist=devDist -1;
//     }
 


//     if (devDist < d_dist1)
// {
//     VehicleControl.Steering.Ang=3;

// }
 


// //  if(Vehicle.tRoad>-1.5)
// //  {
// //   VehicleControl.Steering.Ang=-1;
// //  //SimCore.Time=SimCore.Time+0.002;
// //  }

// // else if (Vehicle.tRoad<-2.2) {
// // 	VehicleControl.Steering.Ang=1;
// //  } 
// //  else{VehicleControl.Steering.Ang=DrivMan.Steering.Ang;}
//     return 0;
// }

double devDist = 0;
double d_dist1;
double d_dist2;

static int MyModel_Calc(void *MP, double dt)
{
    struct tMyModel *mp = (struct tMyModel *) MP;

    // Read the current lane deviation from the sensor
    devDist = RoadSensor->Route.Deviation.Dist;

    // Static variables for PID control
    static double prevError = 0.0;   // Previous error for derivative term
    static double integral = 0.0;    // Integral of the error
    static bool devDistExecuted = false;

    // PID control parameters for steering (adjust these values as needed)
    double Kp = 0.1;  // Proportional gain
    double Ki = 0.01; // Integral gain
    double Kd = 0.05; // Derivative gain

    // The error term is the difference between current deviation and the reference deviation
    double error = devDist - d_dist1;

    // Only execute this once, when we first detect a negative deviation (to store the reference distance)
    if (!devDistExecuted && devDist < 0)
    {
        d_dist1 = devDist;  // Store the initial deviation
        devDistExecuted = true;
        // Log("%.5f", d_dist1);  // Optionally log this value for debugging
    }

//execute thus in monday

    // else if (!devDistExecuted && devDist > 0)
    // {
    //     d_dist1 = devDist;  // Store the initial deviation
    //     devDistExecuted = true;
    //     // Log("%.5f", d_dist1);  // Optionally log this value for debugging
    // }





    // Check if the deviation is large enough to apply correction
    // Define a threshold to avoid minor fluctuations
    double deviationThreshold = 0.05; // Adjust this threshold as needed

    if (fabs(devDist - d_dist1) > deviationThreshold)  // If the vehicle is deviating significantly
    {
        // Update the integral (sum of the errors over time)
        integral += error * dt;

        // Calculate the derivative (rate of change of error)
        double derivative = (error - prevError) / dt;

        // Calculate the PID control output for steering correction
        double steeringCorrection = Kp * error + Ki * integral + Kd * derivative;

        // Now apply the PID output to control the steering angle
        if (devDist != d_dist1)  // Only apply steering adjustment if there's a deviation
        {
            // Apply gradual steering correction to avoid sudden jumps
            if (devDist > d_dist1)  // If the vehicle is too far to the right of the lane center
            {
                VehicleControl.Steering.Ang = -3 + steeringCorrection;  // Apply steering correction

                // Log the deviation and the steering angle for debugging purposes
                Log("devDist= %.5f  d_dist= %.5f  Steering: %.5f\n", devDist, d_dist1, VehicleControl.Steering.Ang);
            }
            else if (devDist < d_dist1)  // If the vehicle is too far to the left of the lane center
            {
                VehicleControl.Steering.Ang = 3 + steeringCorrection;  // Apply steering correction

                // Log the deviation and the steering angle for debugging purposes
                Log("devDist= %.5f  d_dist= %.5f  Steering: %.5f\n", devDist, d_dist1, VehicleControl.Steering.Ang);
            }
            
            // Gradually reduce the deviation (this part might depend on your specific use case)
            devDist = devDist - 1; // Adjust this part depending on how you want the car to behave

            // Save the current error as the previous error for the next cycle
            prevError = error;
        }
    }
    else
    {
        // If deviation is small enough (within the threshold), no adjustment needed
        VehicleControl.Steering.Ang = 0;  // No steering correction needed

        // Optionally log when the vehicle is back on track
        Log("Vehicle is aligned. No steering correction needed.\n");
    }

    return 0;
}




static void *
MyModel_New(struct tInfos *Inf, char const *KindKey)
{ 

    struct tMyModel *mp = NULL;
    char const      *ModelKind, *key;
    char             MsgPre[64];
    int              VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, ModelClass_VehicleControl, KindKey, 0, ThisVersionId, &VersionId))
        == NULL) {
        return NULL;
    }

    mp = (struct tMyModel *) calloc(1, sizeof(*mp));

    sprintf(MsgPre, "%s %s", ThisModelClass, ThisModelKind);
/*
    //key        = "MyVC.GasFac";
    mp->GasFac = iGetDbl(Inf, key);
    if (mp->GasFac < 0.0 || mp->GasFac > 1.0) {
        LogErrF(EC_Init, "%s: gas factor '%s' must be 0...1", MsgPre, key);
        goto ErrorReturn;
    }*/

    return mp;
/*
ErrorReturn:
    free(mp);
    return NULL;
	*/
}

static void
MyModel_Delete(void *MP)
{
    struct tMyModel *mp = (struct tMyModel *) MP;

    /* Park the dict entries for dynamically allocated variables before deleting */
    MyModel_DeclQuants_dyn(mp, 1);
    free(mp);

}

int
VehicleControl_Register_LKAS(void)
{
    tModelClassDescr m;

    memset(&m, 0, sizeof(m));
    m.VehicleControl.VersionId  = ThisVersionId;
    m.VehicleControl.New        = MyModel_New;
    m.VehicleControl.Calc       = MyModel_Calc;
    m.VehicleControl.DeclQuants = MyModel_DeclQuants;
    m.VehicleControl.Delete     = MyModel_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    m.VehicleControl.ParamsChanged = ParamsChanged_IgnoreCheck;

    return Model_Register(ModelClass_VehicleControl, ThisModelKind, &m);
	
}


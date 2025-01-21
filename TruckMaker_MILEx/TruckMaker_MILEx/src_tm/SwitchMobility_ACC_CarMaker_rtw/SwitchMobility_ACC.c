/*
 * SwitchMobility_ACC.c
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "SwitchMobility_ACC".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Jan 21 12:02:49 2025
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SwitchMobility_ACC.h"
#include "rtwtypes.h"
#include <math.h>
#include "SwitchMobility_ACC_types.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "SwitchMobility_ACC_private.h"
#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "SwitchMobility_ACC_wrap.h"

/* CarMaker: Compile- and link-time checks for the right Matlab version. */
#if MATSUPP_NUMVER == 91300

/* The following statement will cause an "unresolved symbol" error when
   linking with a MatSupp library built for the wrong Matlab version. */
extern int MATSUPP_VARNAME(MatSupp, MATSUPP_NUMVER);
void *MATSUPP_VARNAME(MODEL, MATSUPP_NUMVER) = &MATSUPP_VARNAME(MatSupp,
  MATSUPP_NUMVER);

#else
# error Compiler options unsuitable for C code created with Matlab 9.13
#endif

const cmVehicleControlIn SwitchMobility_ACC_rtZcmVehicleControlIn = { 0.0,/* SST */
  0.0,                                 /* Key */

  { 0.0,                               /* s0 */
    0.0,                               /* s1 */
    0.0,                               /* s2 */
    0.0,                               /* s3 */
    0.0                                /* s4 */
  },                                   /* UserSignal */
  0.0,                                 /* GearNo */
  0.0,                                 /* SelectorCtrl */

  { 0.0,                               /* DGS0 */
    0.0,                               /* DGS1 */
    0.0                                /* DGS2 */
  },                                   /* DigitalSelectorCtrl */
  0.0,                                 /* Brake */
  0.0,                                 /* BrakePark */
  0.0,                                 /* BrakeLever */
  0.0,                                 /* Clutch */
  0.0,                                 /* Gas */

  { 0.0,                               /* Ang */
    0.0,                               /* AngVel */
    0.0,                               /* AngAcc */
    0.0                                /* Trq */
  },                                   /* Steering */

  { 0.0,                               /* RollAng */
    0.0                                /* RollAngVel */
  },                                   /* Rider */

  { 0.0,                               /* LowBeam */
    0.0,                               /* HighBeam */
    0.0,                               /* Daytime */
    0.0,                               /* ParkL */
    0.0,                               /* ParkR */
    0.0,                               /* IndL */
    0.0,                               /* IndR */
    0.0,                               /* FogFrontL */
    0.0,                               /* FogFrontR */
    0.0,                               /* FogRear */
    0.0,                               /* Brake */
    0.0                                /* Reverse */
  }                                    /* Lights */
};

const cmVehicleControlOut SwitchMobility_ACC_rtZcmVehicleControlOut = { 0.0,/* SST */
  0.0,                                 /* Key */

  { 0.0,                               /* s0 */
    0.0,                               /* s1 */
    0.0,                               /* s2 */
    0.0,                               /* s3 */
    0.0                                /* s4 */
  },                                   /* UserSignal */
  0.0,                                 /* GearNo */
  0.0,                                 /* SelectorCtrl */
  0.0,                                 /* Brake */
  0.0,                                 /* BrakePark */
  0.0,                                 /* BrakeLever */
  0.0,                                 /* Clutch */
  0.0,                                 /* Gas */

  { 0.0,                               /* Ang */
    0.0,                               /* AngVel */
    0.0,                               /* AngAcc */
    0.0                                /* Trq */
  },                                   /* Steering */

  { 0.0,                               /* RollAng */
    0.0                                /* RollAngVel */
  },                                   /* Rider */

  { 0.0,                               /* LowBeam */
    0.0,                               /* HighBeam */
    0.0,                               /* Daytime */
    0.0,                               /* ParkL */
    0.0,                               /* ParkR */
    0.0,                               /* IndL */
    0.0,                               /* IndR */
    0.0,                               /* FogFrontL */
    0.0,                               /* FogFrontR */
    0.0,                               /* FogRear */
    0.0,                               /* Brake */
    0.0                                /* Reverse */
  }                                    /* Lights */
};

/* Model step function */
void SwitchMobility_ACC_step(RT_MODEL_SwitchMobility_ACC_T *const
  SwitchMobility_ACC_M)
{
  B_SwitchMobility_ACC_T *SwitchMobility_ACC_B = SwitchMobility_ACC_M->blockIO;
  DW_SwitchMobility_ACC_T *SwitchMobility_ACC_DW = SwitchMobility_ACC_M->dwork;
  PrevZCX_SwitchMobility_ACC_T *SwitchMobility_ACC_PrevZCX =
    SwitchMobility_ACC_M->prevZCSigState;
  ExtU_SwitchMobility_ACC_T *SwitchMobility_ACC_U = (ExtU_SwitchMobility_ACC_T *)
    SwitchMobility_ACC_M->inputs;
  ExtY_SwitchMobility_ACC_T *SwitchMobility_ACC_Y = (ExtY_SwitchMobility_ACC_T *)
    SwitchMobility_ACC_M->outputs;
  real_T rtb_dsm;
  real_T rtb_dvms;
  real_T rtb_u35ax1;
  uint8_T rtb_Compare;
  boolean_T rtb_targetdetected;
  ZCEventType zcEvent;

  /* S-Function (cm_sensor_object): '<S18>/S-Function' */
  {
    const tObjectSensor *os;
    int sindex;
    static tObjectSensor ZeroSensor = { .relvTargetObjId = -1 };

    if (SwitchMobility_ACC_DW->SFunction_IWORK.SIsFirstStep) {
      SwitchMobility_ACC_DW->SFunction_IWORK.SIndex =
        ObjectSensor_FindIndexForName("\122\141\144\141\162\114");// RadarL
      SwitchMobility_ACC_DW->SFunction_PWORK.SSensor = ObjectSensor_GetByIndex
        (SwitchMobility_ACC_DW->SFunction_IWORK.SIndex);
      if (SwitchMobility_ACC_DW->SFunction_PWORK.SSensor == NULL) {
        SwitchMobility_ACC_DW->SFunction_PWORK.SSensor = &ZeroSensor;
        SwitchMobility_ACC_DW->SFunction_IWORK.SIndex = -1;
      }

      SwitchMobility_ACC_DW->SFunction_IWORK.SIsFirstStep = 0;
    }

    sindex = SwitchMobility_ACC_DW->SFunction_IWORK.SIndex;
    os = (const tObjectSensor *)SwitchMobility_ACC_DW->SFunction_PWORK.SSensor;
    SwitchMobility_ACC_B->SFunction_o1 = sindex;
    SwitchMobility_ACC_B->SFunction_o2[0] = os->trtype;
    SwitchMobility_ACC_B->SFunction_o2[1] = os->Range;
    SwitchMobility_ACC_B->SFunction_o2[2] = os->FoV[0];
    SwitchMobility_ACC_B->SFunction_o2[3] = os->FoV[1];
    SwitchMobility_ACC_B->SFunction_o2[4] = os->rot_zyx[0];
    SwitchMobility_ACC_B->SFunction_o2[5] = os->rot_zyx[1];
    SwitchMobility_ACC_B->SFunction_o2[6] = os->rot_zyx[2];
    SwitchMobility_ACC_B->SFunction_o2[7] = os->DrvLaneCurv;
    SwitchMobility_ACC_B->SFunction_o3 = os->nObsvObjects;
    SwitchMobility_ACC_B->SFunction_o4[0] = os->Targ_Dtct;
    SwitchMobility_ACC_B->SFunction_o4[1] = os->relvTargetObjId;
  }

  /* S-Function (cm_sensor_object_obj): '<S19>/S-Function' */
  {
    int osindex, obindex;
    const tObjectSensor *os;
    const tObjectSensorObj *ob;
    static tObjectSensor ZeroSensor = { .relvTargetObjId = -1 };

    static tObjectSensorObj ZeroObject = { .ObjId = -1 };

    osindex = SwitchMobility_ACC_B->SFunction_o1;
    if (SimCore.State != SCState_Simulate ||
        (os = ObjectSensor_GetByIndex(osindex)) == NULL) {
      os = &ZeroSensor;
      osindex = -1;
    }

    obindex = SwitchMobility_ACC_B->SFunction_o4[1];
    if (obindex == 99999) {
      obindex = os->relvTargetObjId;
    } else {
    }

    ob = ObjectSensor_GetObjectByObjId(osindex, obindex);
    if (ob == NULL) {
      ob = &ZeroObject;
      obindex = -1;
    }

    SwitchMobility_ACC_B->SFunction_o1_k = obindex;
    SwitchMobility_ACC_B->SFunction_o2_i[0] = Traffic_ObjId2TrfId(ob->ObjId);
    SwitchMobility_ACC_B->SFunction_o2_i[1] = ob->w;
    SwitchMobility_ACC_B->SFunction_o2_i[2] = ob->h;
    SwitchMobility_ACC_B->SFunction_o2_i[3] = ob->l;
    SwitchMobility_ACC_B->SFunction_o2_i[4] = ob->zOff;
    SwitchMobility_ACC_B->SFunction_o2_i[5] = ob->ObjId;
    SwitchMobility_ACC_B->SFunction_o3_n[0] = ob->obsv;
    SwitchMobility_ACC_B->SFunction_o3_n[1] = ob->dtct;
    SwitchMobility_ACC_B->SFunction_o4_i[0] = ob->RefPnt.ds[0];
    SwitchMobility_ACC_B->SFunction_o4_i[1] = ob->RefPnt.ds[1];
    SwitchMobility_ACC_B->SFunction_o4_i[2] = ob->RefPnt.ds[2];
    SwitchMobility_ACC_B->SFunction_o4_i[3] = ob->RefPnt.ds_p;
    SwitchMobility_ACC_B->SFunction_o4_i[4] = ob->RefPnt.dv[0];
    SwitchMobility_ACC_B->SFunction_o4_i[5] = ob->RefPnt.dv[1];
    SwitchMobility_ACC_B->SFunction_o4_i[6] = ob->RefPnt.dv[2];
    SwitchMobility_ACC_B->SFunction_o4_i[7] = ob->RefPnt.dv_p;
    SwitchMobility_ACC_B->SFunction_o4_i[8] = ob->RefPnt.alpha_p;
    SwitchMobility_ACC_B->SFunction_o4_i[9] = ob->RefPnt.theta_p;
    SwitchMobility_ACC_B->SFunction_o4_i[10] = ob->RefPnt.r_zyx[0];
    SwitchMobility_ACC_B->SFunction_o4_i[11] = ob->RefPnt.r_zyx[1];
    SwitchMobility_ACC_B->SFunction_o4_i[12] = ob->RefPnt.r_zyx[2];
    SwitchMobility_ACC_B->SFunction_o5[0] = ob->NearPnt.ds[0];
    SwitchMobility_ACC_B->SFunction_o5[1] = ob->NearPnt.ds[1];
    SwitchMobility_ACC_B->SFunction_o5[2] = ob->NearPnt.ds[2];
    SwitchMobility_ACC_B->SFunction_o5[3] = ob->NearPnt.ds_p;
    SwitchMobility_ACC_B->SFunction_o5[4] = ob->NearPnt.dv[0];
    SwitchMobility_ACC_B->SFunction_o5[5] = ob->NearPnt.dv[1];
    SwitchMobility_ACC_B->SFunction_o5[6] = ob->NearPnt.dv[2];
    SwitchMobility_ACC_B->SFunction_o5[7] = ob->NearPnt.dv_p;
    SwitchMobility_ACC_B->SFunction_o5[8] = ob->NearPnt.alpha_p;
    SwitchMobility_ACC_B->SFunction_o5[9] = ob->NearPnt.theta_p;
    SwitchMobility_ACC_B->SFunction_o5[10] = ob->NearPnt.r_zyx[0];
    SwitchMobility_ACC_B->SFunction_o5[11] = ob->NearPnt.r_zyx[1];
    SwitchMobility_ACC_B->SFunction_o5[12] = ob->NearPnt.r_zyx[2];
    SwitchMobility_ACC_B->SFunction_o6[0] = ob->incangle[0];
    SwitchMobility_ACC_B->SFunction_o6[1] = ob->incangle[1];
    SwitchMobility_ACC_B->SFunction_o6[2] = ob->ImgArea_NearP;
    SwitchMobility_ACC_B->SFunction_o6[3] = ob->ImgArea_LeftP;
    SwitchMobility_ACC_B->SFunction_o6[4] = ob->ImgArea_RightP;
  }

  /* S-Function (read_dict): '<S5>/Is ACC enabled' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->IsACCenabled_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->IsACCenabled_IWORK.Checked) {
      SwitchMobility_ACC_DW->IsACCenabled_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->IsACCenabled = e->GetFunc(e->Var);
  }

  /* Logic: '<S5>/Logical Operator' */
  rtb_targetdetected = ((SwitchMobility_ACC_B->IsACCenabled != 0.0) &&
                        (SwitchMobility_ACC_B->SFunction_o4[0] != 0.0));

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/No target'
   *  Constant: '<S5>/Target dv'
   *  Switch: '<S5>/Switch1'
   */
  if (rtb_targetdetected) {
    rtb_dsm = SwitchMobility_ACC_B->SFunction_o5[3];
    rtb_dvms = SwitchMobility_ACC_B->SFunction_o5[7];
  } else {
    rtb_dsm = SwitchMobility_ACC_P.Notarget_Value;
    rtb_dvms = SwitchMobility_ACC_P.Targetdv_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* S-Function (read_dict): '<S7>/Read User desired time gap' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadUserdesiredtimegap_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->ReadUserdesiredtimegap_IWORK.Checked) {
      SwitchMobility_ACC_DW->ReadUserdesiredtimegap_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->ReadUserdesiredtimegap = e->GetFunc(e->Var);
  }

  /* S-Function (read_infoparam): '<S3>/Read init brake threshold from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam,
       NULL);
    SwitchMobility_ACC_B->ReadinitbrakethresholdfromInf = *vec++;
  }

  /* S-Function (read_dict): '<S7>/Is ACC enabled' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->IsACCenabled_PWORK_n.Entry;
    if (!SwitchMobility_ACC_DW->IsACCenabled_IWORK_f.Checked) {
      SwitchMobility_ACC_DW->IsACCenabled_IWORK_f.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->IsACCenabled_d = e->GetFunc(e->Var);
  }

  /* Switch: '<S3>/Switch Brake  ACC on//off' incorporates:
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  if (SwitchMobility_ACC_U->FromCM.Brake >
      SwitchMobility_ACC_B->ReadinitbrakethresholdfromInf) {
    /* Switch: '<S3>/Switch Brake  ACC on//off' incorporates:
     *  Constant: '<S3>/ACC Off'
     */
    SwitchMobility_ACC_B->SwitchBrakeACConoff =
      SwitchMobility_ACC_P.ACCOff_Value;
  } else {
    /* Switch: '<S3>/Switch Brake  ACC on//off' */
    SwitchMobility_ACC_B->SwitchBrakeACConoff =
      SwitchMobility_ACC_B->IsACCenabled_d;
  }

  /* End of Switch: '<S3>/Switch Brake  ACC on//off' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Compare = (uint8_T)((int32_T)rtb_targetdetected > (int32_T)
    SwitchMobility_ACC_P.Constant_Value_f);

  /* Outputs for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Logic: '<S6>/Logical Operator' */
  if ((SwitchMobility_ACC_B->SwitchBrakeACConoff != 0.0) && (rtb_Compare != 0))
  {
    /* S-Function (read_dict): '<S8>/Read Car.v[m//s]' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadCarvms_PWORK_p.Entry;
      if (!SwitchMobility_ACC_DW->ReadCarvms_IWORK_l.Checked) {
        SwitchMobility_ACC_DW->ReadCarvms_IWORK_l.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
      }

      SwitchMobility_ACC_B->ReadCarvms_j = e->GetFunc(e->Var);
    }

    /* S-Function (read_infoparam): '<S8>/Read init min distance from Inf' */
    {
      const double *vec = InfoParam_GetVec
        (SwitchMobility_ACC_DW->ReadinitmindistancefromInf_PWORK.InfoParam, NULL);
      SwitchMobility_ACC_B->ReadinitmindistancefromInf = *vec++;
    }

    /* MinMax: '<S8>/MinMax' incorporates:
     *  Product: '<S8>/Product'
     *  Sum: '<S8>/Add'
     */
    SwitchMobility_ACC_B->MinMax = fmax((rtb_dvms +
      SwitchMobility_ACC_B->ReadCarvms_j) *
      SwitchMobility_ACC_B->ReadUserdesiredtimegap,
      SwitchMobility_ACC_B->ReadinitmindistancefromInf);

    /* S-Function (write_dict): '<S8>/Write desired distance' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)SwitchMobility_ACC_DW->Writedesireddistance_PWORK.Entry;
      if (!SwitchMobility_ACC_DW->Writedesireddistance_IWORK.Checked) {
        SwitchMobility_ACC_DW->Writedesireddistance_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
      }

      value = SwitchMobility_ACC_B->MinMax;
      DVA_PokeSL(e, value);
    }
  }

  /* End of Logic: '<S6>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* S-Function (read_dict): '<S7>/Read User desired speed' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadUserdesiredspeed_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->ReadUserdesiredspeed_IWORK.Checked) {
      SwitchMobility_ACC_DW->ReadUserdesiredspeed_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->ReadUserdesiredspeed = e->GetFunc(e->Var);
  }

  /* S-Function (read_dict): '<S7>/Read Simulation Time' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadSimulationTime_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->ReadSimulationTime_IWORK.Checked) {
      SwitchMobility_ACC_DW->ReadSimulationTime_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->ReadSimulationTime = e->GetFunc(e->Var);
  }

  /* S-Function (read_infoparam): '<S7>/Read Init Velocity' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadInitVelocity_PWORK.InfoParam, NULL);
    SwitchMobility_ACC_B->ReadInitVelocity = *vec++;
  }

  /* S-Function (read_dict): '<S7>/Read Car.v[m//s]' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadCarvms_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->ReadCarvms_IWORK.Checked) {
      SwitchMobility_ACC_DW->ReadCarvms_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->ReadCarvms = e->GetFunc(e->Var);
  }

  /* Switch: '<S7>/ACC Active ACC//Actual Speed' */
  if (SwitchMobility_ACC_B->IsACCenabled_d >=
      SwitchMobility_ACC_P.ACCActiveACCActualSpeed_Threshold) {
    /* Switch: '<S7>/Switch' */
    if (SwitchMobility_ACC_B->ReadSimulationTime >
        SwitchMobility_ACC_P.Switch_Threshold) {
      /* Switch: '<S7>/ACC Active ACC//Actual Speed' */
      SwitchMobility_ACC_B->ACCActiveACCActualSpeed =
        SwitchMobility_ACC_B->ReadUserdesiredspeed;
    } else {
      /* Switch: '<S7>/ACC Active ACC//Actual Speed' incorporates:
       *  Gain: '<S7>/kmh2ms'
       */
      SwitchMobility_ACC_B->ACCActiveACCActualSpeed =
        SwitchMobility_ACC_P.kmh2ms_Gain *
        SwitchMobility_ACC_B->ReadInitVelocity;
    }

    /* End of Switch: '<S7>/Switch' */
  } else {
    /* Switch: '<S7>/ACC Active ACC//Actual Speed' */
    SwitchMobility_ACC_B->ACCActiveACCActualSpeed =
      SwitchMobility_ACC_B->ReadCarvms;
  }

  /* End of Switch: '<S7>/ACC Active ACC//Actual Speed' */

  /* Outputs for Atomic SubSystem: '<S6>/Speed Control Algorithm' */

  /* S-Function (read_dict): '<S13>/Read Car.v[m//s]' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadCarvms_PWORK_l.Entry;
    if (!SwitchMobility_ACC_DW->ReadCarvms_IWORK_i.Checked) {
      SwitchMobility_ACC_DW->ReadCarvms_IWORK_i.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->ReadCarvms_f = e->GetFunc(e->Var);
  }

  /* S-Function (read_infoparam): '<S13>/Read init spdctrl.kv from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam, NULL);
    SwitchMobility_ACC_B->ReadinitspdctrlkvfromInf = *vec++;
  }

  /* Product: '<S13>/Divide' incorporates:
   *  Sum: '<S13>/Sum'
   */
  rtb_u35ax1 = (SwitchMobility_ACC_B->ACCActiveACCActualSpeed -
                SwitchMobility_ACC_B->ReadCarvms_f) /
    SwitchMobility_ACC_B->ReadinitspdctrlkvfromInf;

  /* Saturate: '<S10>/-0.35<=ax<=1' */
  if (rtb_u35ax1 > SwitchMobility_ACC_P.u35ax1_UpperSat) {
    rtb_u35ax1 = SwitchMobility_ACC_P.u35ax1_UpperSat;
  } else if (rtb_u35ax1 < SwitchMobility_ACC_P.u35ax1_LowerSat) {
    rtb_u35ax1 = SwitchMobility_ACC_P.u35ax1_LowerSat;
  }

  /* End of Saturate: '<S10>/-0.35<=ax<=1' */

  /* End of Outputs for SubSystem: '<S6>/Speed Control Algorithm' */

  /* Outputs for Atomic SubSystem: '<S6>/Distance Control Algorithm' */

  /* S-Function (read_infoparam): '<S12>/Read init distctrl.kd from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam, NULL);
    SwitchMobility_ACC_B->ReadinitdistctrlkdfromInf = *vec++;
  }

  /* S-Function (read_infoparam): '<S12>/Read init distctrl.kv from Inf1' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam, NULL);
    SwitchMobility_ACC_B->ReadinitdistctrlkvfromInf1 = *vec++;
  }

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/Subtract'
   */
  rtb_dsm = fmin((rtb_dsm - SwitchMobility_ACC_B->MinMax) /
                 SwitchMobility_ACC_B->ReadinitdistctrlkdfromInf + rtb_dvms /
                 SwitchMobility_ACC_B->ReadinitdistctrlkvfromInf1, rtb_u35ax1);

  /* Saturate: '<S9>/-2.5<=ax<=1' */
  if (rtb_dsm > SwitchMobility_ACC_P.u5ax1_UpperSat) {
    rtb_dsm = SwitchMobility_ACC_P.u5ax1_UpperSat;
  } else if (rtb_dsm < SwitchMobility_ACC_P.u5ax1_LowerSat) {
    rtb_dsm = SwitchMobility_ACC_P.u5ax1_LowerSat;
  }

  /* End of Saturate: '<S9>/-2.5<=ax<=1' */

  /* End of Outputs for SubSystem: '<S6>/Distance Control Algorithm' */

  /* Switch: '<S6>/desired or NOTSET' */
  if (SwitchMobility_ACC_B->SwitchBrakeACConoff >=
      SwitchMobility_ACC_P.desiredorNOTSET_Threshold) {
    /* Switch: '<S6>/desired Ax' */
    if (rtb_Compare >= SwitchMobility_ACC_P.desiredAx_Threshold) {
      /* Switch: '<S6>/desired or NOTSET' */
      SwitchMobility_ACC_B->desiredorNOTSET = rtb_dsm;
    } else {
      /* Switch: '<S6>/desired or NOTSET' */
      SwitchMobility_ACC_B->desiredorNOTSET = rtb_u35ax1;
    }

    /* End of Switch: '<S6>/desired Ax' */
  } else {
    /* Switch: '<S6>/desired or NOTSET' incorporates:
     *  Constant: '<S6>/Ax is NOTSET'
     */
    SwitchMobility_ACC_B->desiredorNOTSET =
      SwitchMobility_ACC_P.AxisNOTSET_Value;
  }

  /* End of Switch: '<S6>/desired or NOTSET' */

  /* S-Function (write_dict): '<S1>/Write desired Ax' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->WritedesiredAx_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->WritedesiredAx_IWORK.Checked) {
      SwitchMobility_ACC_DW->WritedesiredAx_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    value = SwitchMobility_ACC_B->desiredorNOTSET;
    DVA_PokeSL(e, value);
  }

  /* S-Function (write_dict): '<S3>/Write ACC IsActive' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->WriteACCIsActive_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->WriteACCIsActive_IWORK.Checked) {
      SwitchMobility_ACC_DW->WriteACCIsActive_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    value = SwitchMobility_ACC_B->SwitchBrakeACConoff;
    DVA_PokeSL(e, value);
  }

  /* S-Function (write_dict): '<S3>/Write desired Ax' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->WritedesiredAx_PWORK_n.Entry;
    if (!SwitchMobility_ACC_DW->WritedesiredAx_IWORK_h.Checked) {
      SwitchMobility_ACC_DW->WritedesiredAx_IWORK_h.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    value = SwitchMobility_ACC_B->desiredorNOTSET;
    DVA_PokeSL(e, value);
  }

  /* S-Function (write_dict): '<S7>/Write desired speed' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->Writedesiredspeed_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->Writedesiredspeed_IWORK.Checked) {
      SwitchMobility_ACC_DW->Writedesiredspeed_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    value = SwitchMobility_ACC_B->ACCActiveACCActualSpeed;
    DVA_PokeSL(e, value);
  }

  /* S-Function (read_infoparam): '<S7>/Read init desired time gap from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam,
       NULL);
    SwitchMobility_ACC_B->ReadinitdesiredtimegapfromInf = *vec++;
  }

  /* Outputs for Triggered SubSystem: '<S7>/Init Desired time gap quantity' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  /* Memory: '<S7>/Memory' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &SwitchMobility_ACC_PrevZCX->InitDesiredtimegapquantity_Trig_ZCE,
                     (SwitchMobility_ACC_DW->Memory_PreviousInput));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (write_dict): '<S14>/Write init time gap' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)SwitchMobility_ACC_DW->Writeinittimegap_PWORK.Entry;
      if (!SwitchMobility_ACC_DW->Writeinittimegap_IWORK.Checked) {
        SwitchMobility_ACC_DW->Writeinittimegap_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
      }

      value = SwitchMobility_ACC_B->ReadinitdesiredtimegapfromInf;
      DVA_PokeSL(e, value);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Init Desired time gap quantity' */

  /* S-Function (read_infoparam): '<S15>/Read init p-gain from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitpgainfromInf_PWORK.InfoParam, NULL);
    SwitchMobility_ACC_B->ReadinitpgainfromInf = *vec++;
  }

  /* S-Function (read_dict): '<S16>/Read Car.ax' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)SwitchMobility_ACC_DW->ReadCarax_PWORK.Entry;
    if (!SwitchMobility_ACC_DW->ReadCarax_IWORK.Checked) {
      SwitchMobility_ACC_DW->ReadCarax_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'SwitchMobility_ACC'");
    }

    SwitchMobility_ACC_B->ReadCarax = e->GetFunc(e->Var);
  }

  /* Sum: '<S16>/Subtract' */
  rtb_u35ax1 = SwitchMobility_ACC_B->desiredorNOTSET -
    SwitchMobility_ACC_B->ReadCarax;

  /* Product: '<S15>/p-gain' */
  rtb_dsm = SwitchMobility_ACC_B->ReadinitpgainfromInf * rtb_u35ax1;

  /* S-Function (read_infoparam): '<S15>/Read init i-gain from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (SwitchMobility_ACC_DW->ReadinitigainfromInf_PWORK.InfoParam, NULL);
    SwitchMobility_ACC_B->ReadinitigainfromInf = *vec++;
  }

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<S4>/Ax is NOTSET'
   */
  rtb_targetdetected = (SwitchMobility_ACC_B->desiredorNOTSET !=
                        SwitchMobility_ACC_P.AxisNOTSET_Value_c);

  /* Switch: '<S17>/Switch Ax  Init I-Part' incorporates:
   *  Memory: '<S17>/Memory'
   */
  if (rtb_targetdetected) {
    rtb_dvms = SwitchMobility_ACC_DW->Memory_PreviousInput_j;
  } else {
    rtb_dvms = SwitchMobility_ACC_U->FromCM.Gas;
  }

  /* Sum: '<S17>/Add1' incorporates:
   *  Product: '<S15>/i-gain'
   *  Switch: '<S17>/Switch Ax  Init I-Part'
   */
  rtb_u35ax1 = rtb_u35ax1 * SwitchMobility_ACC_B->ReadinitigainfromInf +
    rtb_dvms;

  /* Sum: '<S15>/Add' */
  rtb_dsm += rtb_u35ax1;

  /* Saturate: '<S15>/Saturation' */
  if (rtb_dsm > SwitchMobility_ACC_P.Saturation_UpperSat) {
    rtb_dsm = SwitchMobility_ACC_P.Saturation_UpperSat;
  } else if (rtb_dsm < SwitchMobility_ACC_P.Saturation_LowerSat) {
    rtb_dsm = SwitchMobility_ACC_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Saturate: '<S17>/Saturation' */
  if (rtb_u35ax1 > SwitchMobility_ACC_P.Saturation_UpperSat_i) {
    rtb_u35ax1 = SwitchMobility_ACC_P.Saturation_UpperSat_i;
  } else if (rtb_u35ax1 < SwitchMobility_ACC_P.Saturation_LowerSat_n) {
    rtb_u35ax1 = SwitchMobility_ACC_P.Saturation_LowerSat_n;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Switch: '<S1>/Switch Ax  Brake on//off' incorporates:
   *  Switch: '<S1>/Switch Ax  Gas on//off'
   */
  if (rtb_targetdetected) {
    /* Saturate: '<S4>/Brake if -1<x<0' */
    if (rtb_dsm > SwitchMobility_ACC_P.Brakeif1x0_UpperSat) {
      rtb_dvms = SwitchMobility_ACC_P.Brakeif1x0_UpperSat;
    } else if (rtb_dsm < SwitchMobility_ACC_P.Brakeif1x0_LowerSat) {
      rtb_dvms = SwitchMobility_ACC_P.Brakeif1x0_LowerSat;
    } else {
      rtb_dvms = rtb_dsm;
    }

    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Gain: '<S4>/Gain'
     *  Outport: '<Root>/ToCM'
     *  Saturate: '<S4>/Brake if -1<x<0'
     */
    SwitchMobility_ACC_Y->ToCM.Brake = SwitchMobility_ACC_P.Gain_Gain * rtb_dvms;

    /* Saturate: '<S4>/Gas  if 0<=x<=1' */
    if (rtb_dsm > SwitchMobility_ACC_P.Gasif0x1_UpperSat) {
      /* BusCreator generated from: '<Root>/ToCM' incorporates:
       *  Outport: '<Root>/ToCM'
       */
      SwitchMobility_ACC_Y->ToCM.Gas = SwitchMobility_ACC_P.Gasif0x1_UpperSat;
    } else if (rtb_dsm < SwitchMobility_ACC_P.Gasif0x1_LowerSat) {
      /* BusCreator generated from: '<Root>/ToCM' incorporates:
       *  Outport: '<Root>/ToCM'
       */
      SwitchMobility_ACC_Y->ToCM.Gas = SwitchMobility_ACC_P.Gasif0x1_LowerSat;
    } else {
      /* BusCreator generated from: '<Root>/ToCM' incorporates:
       *  Outport: '<Root>/ToCM'
       */
      SwitchMobility_ACC_Y->ToCM.Gas = rtb_dsm;
    }

    /* End of Saturate: '<S4>/Gas  if 0<=x<=1' */
  } else {
    /* BusCreator generated from: '<Root>/ToCM' incorporates:
     *  Outport: '<Root>/ToCM'
     */
    SwitchMobility_ACC_Y->ToCM.Brake = SwitchMobility_ACC_U->FromCM.Brake;
    SwitchMobility_ACC_Y->ToCM.Gas = SwitchMobility_ACC_U->FromCM.Gas;
  }

  /* End of Switch: '<S1>/Switch Ax  Brake on//off' */

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Constant: '<S2>/UserSignal.s0'
   *  Constant: '<S2>/UserSignal.s1'
   *  Constant: '<S2>/UserSignal.s2'
   *  Constant: '<S2>/UserSignal.s3'
   *  Constant: '<S2>/UserSignal.s4'
   */
  SwitchMobility_ACC_Y->ToCM.UserSignal.s0 =
    SwitchMobility_ACC_P.UserSignals0_Value;
  SwitchMobility_ACC_Y->ToCM.UserSignal.s1 =
    SwitchMobility_ACC_P.UserSignals1_Value;
  SwitchMobility_ACC_Y->ToCM.UserSignal.s2 =
    SwitchMobility_ACC_P.UserSignals2_Value;
  SwitchMobility_ACC_Y->ToCM.UserSignal.s3 =
    SwitchMobility_ACC_P.UserSignals3_Value;
  SwitchMobility_ACC_Y->ToCM.UserSignal.s4 =
    SwitchMobility_ACC_P.UserSignals4_Value;

  /* BusCreator generated from: '<Root>/ToCM' */
  SwitchMobility_ACC_Y->ToCM.Steering = SwitchMobility_ACC_U->FromCM.Steering;

  /* BusCreator generated from: '<Root>/ToCM' */
  SwitchMobility_ACC_Y->ToCM.Rider = SwitchMobility_ACC_U->FromCM.Rider;

  /* BusCreator generated from: '<Root>/ToCM' */
  SwitchMobility_ACC_Y->ToCM.Lights = SwitchMobility_ACC_U->FromCM.Lights;

  /* BusCreator generated from: '<Root>/ToCM' incorporates:
   *  Outport: '<Root>/ToCM'
   */
  SwitchMobility_ACC_Y->ToCM.SST = SwitchMobility_ACC_U->FromCM.SST;
  SwitchMobility_ACC_Y->ToCM.Key = SwitchMobility_ACC_U->FromCM.Key;
  SwitchMobility_ACC_Y->ToCM.GearNo = SwitchMobility_ACC_U->FromCM.GearNo;
  SwitchMobility_ACC_Y->ToCM.SelectorCtrl =
    SwitchMobility_ACC_U->FromCM.SelectorCtrl;
  SwitchMobility_ACC_Y->ToCM.BrakePark = SwitchMobility_ACC_U->FromCM.BrakePark;
  SwitchMobility_ACC_Y->ToCM.BrakeLever =
    SwitchMobility_ACC_U->FromCM.BrakeLever;
  SwitchMobility_ACC_Y->ToCM.Clutch = SwitchMobility_ACC_U->FromCM.Clutch;

  /* Update for Memory: '<S7>/Memory' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SwitchMobility_ACC_DW->Memory_PreviousInput =
    SwitchMobility_ACC_P.Constant_Value;

  /* Update for Memory: '<S17>/Memory' */
  SwitchMobility_ACC_DW->Memory_PreviousInput_j = rtb_u35ax1;
}

/* Model initialize function */
void SwitchMobility_ACC_initialize(RT_MODEL_SwitchMobility_ACC_T *const
  SwitchMobility_ACC_M)
{
  DW_SwitchMobility_ACC_T *SwitchMobility_ACC_DW = SwitchMobility_ACC_M->dwork;
  B_SwitchMobility_ACC_T *SwitchMobility_ACC_B = SwitchMobility_ACC_M->blockIO;

  /* Start for S-Function (cm_sensor_object): '<S18>/S-Function' */
  SwitchMobility_ACC_DW->SFunction_IWORK.SIsFirstStep = 1;

  /* Start for S-Function (cm_sensor_object_obj): '<S19>/S-Function' */
  SwitchMobility_ACC_DW->SFunction_IWORK_b.SIsFirstStep = 1;

  /* Start for S-Function (read_dict): '<S5>/Is ACC enabled' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\111\163\101\143\164\151\166\145",
      NULL);                           // AccelCtrl.ACC.IsActive
    SwitchMobility_ACC_DW->IsACCenabled_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->IsACCenabled_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S7>/Read User desired time gap' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\124\107\141\160",
      NULL);                           // AccelCtrl.ACC.DesiredTGap
    SwitchMobility_ACC_DW->ReadUserdesiredtimegap_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->ReadUserdesiredtimegap_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S3>/Read init brake threshold from Inf' */
  SwitchMobility_ACC_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam =
    InfoParam_Create(InfoParam_Vehicle,
                     "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\102\162\141\153\145\124\150\162\145\163\150\157\154\144",
                     1,
                     &SwitchMobility_ACC_ConstP.ReadinitbrakethresholdfromInf_DefValue,
                     1);               // AccelCtrl.ACC.BrakeThreshold
  InfoParam_Read
    (SwitchMobility_ACC_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (read_dict): '<S7>/Is ACC enabled' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\111\163\101\143\164\151\166\145",
      NULL);                           // AccelCtrl.ACC.IsActive
    SwitchMobility_ACC_DW->IsACCenabled_IWORK_f.Checked = 0;
    SwitchMobility_ACC_DW->IsACCenabled_PWORK_n.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Start for S-Function (read_dict): '<S8>/Read Car.v[m//s]' */
  {
    char **namevec = CM_Names2StrVec("\103\141\162\056\166", NULL);// Car.v
    SwitchMobility_ACC_DW->ReadCarvms_IWORK_l.Checked = 0;
    SwitchMobility_ACC_DW->ReadCarvms_PWORK_p.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S8>/Read init min distance from Inf' */
  SwitchMobility_ACC_DW->ReadinitmindistancefromInf_PWORK.InfoParam =
    InfoParam_Create(InfoParam_Vehicle,
                     "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\151\163\164\115\151\156",
                     1,
                     &SwitchMobility_ACC_ConstP.ReadinitmindistancefromInf_DefValue,
                     1);               // AccelCtrl.ACC.DistMin
  InfoParam_Read
    (SwitchMobility_ACC_DW->ReadinitmindistancefromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (write_dict): '<S8>/Write desired distance' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\104\151\163\164",
      NULL);                           // AccelCtrl.ACC.DesiredDist
    SwitchMobility_ACC_DW->Writedesireddistance_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->Writedesireddistance_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* End of Start for SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Start for S-Function (read_dict): '<S7>/Read User desired speed' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\123\160\144",
      NULL);                           // AccelCtrl.ACC.DesiredSpd
    SwitchMobility_ACC_DW->ReadUserdesiredspeed_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->ReadUserdesiredspeed_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S7>/Read Simulation Time' */
  {
    char **namevec = CM_Names2StrVec("\124\151\155\145", NULL);// Time
    SwitchMobility_ACC_DW->ReadSimulationTime_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->ReadSimulationTime_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S7>/Read Init Velocity' */
  SwitchMobility_ACC_DW->ReadInitVelocity_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Testrun,
     "\104\162\151\166\115\141\156\056\115\141\156\056\123\164\141\162\164\056\126\145\154\157\143\151\164\171",
     1, &SwitchMobility_ACC_ConstP.ReadInitVelocity_DefValue, 1);// DrivMan.Man.Start.Velocity
  InfoParam_Read(SwitchMobility_ACC_DW->ReadInitVelocity_PWORK.InfoParam, 0);

  /* Start for S-Function (read_dict): '<S7>/Read Car.v[m//s]' */
  {
    char **namevec = CM_Names2StrVec("\103\141\162\056\166", NULL);// Car.v
    SwitchMobility_ACC_DW->ReadCarvms_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->ReadCarvms_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for Atomic SubSystem: '<S6>/Speed Control Algorithm' */

  /* Start for S-Function (read_dict): '<S13>/Read Car.v[m//s]' */
  {
    char **namevec = CM_Names2StrVec("\103\141\162\056\166", NULL);// Car.v
    SwitchMobility_ACC_DW->ReadCarvms_IWORK_i.Checked = 0;
    SwitchMobility_ACC_DW->ReadCarvms_PWORK_l.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S13>/Read init spdctrl.kv from Inf' */
  SwitchMobility_ACC_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam =
    InfoParam_Create(InfoParam_Vehicle,
                     "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\123\160\144\103\164\162\154\056\153\166",
                     1,
                     &SwitchMobility_ACC_ConstP.ReadinitspdctrlkvfromInf_DefValue,
                     1);               // AccelCtrl.ACC.SpdCtrl.kv
  InfoParam_Read(SwitchMobility_ACC_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam,
                 0);

  /* End of Start for SubSystem: '<S6>/Speed Control Algorithm' */

  /* Start for Atomic SubSystem: '<S6>/Distance Control Algorithm' */

  /* Start for S-Function (read_infoparam): '<S12>/Read init distctrl.kd from Inf' */
  SwitchMobility_ACC_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam =
    InfoParam_Create(InfoParam_Vehicle,
                     "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\151\163\164\103\164\162\154\056\153\144",
                     1,
                     &SwitchMobility_ACC_ConstP.ReadinitdistctrlkdfromInf_DefValue,
                     1);               // AccelCtrl.ACC.DistCtrl.kd
  InfoParam_Read
    (SwitchMobility_ACC_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (read_infoparam): '<S12>/Read init distctrl.kv from Inf1' */
  SwitchMobility_ACC_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam =
    InfoParam_Create(InfoParam_Vehicle,
                     "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\151\163\164\103\164\162\154\056\153\166",
                     1,
                     &SwitchMobility_ACC_ConstP.ReadinitdistctrlkvfromInf1_DefValue,
                     1);               // AccelCtrl.ACC.DistCtrl.kv
  InfoParam_Read
    (SwitchMobility_ACC_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam, 0);

  /* End of Start for SubSystem: '<S6>/Distance Control Algorithm' */

  /* Start for S-Function (write_dict): '<S1>/Write desired Ax' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\104\145\163\151\162\145\144\101\170",
      NULL);                           // AccelCtrl.DesiredAx
    SwitchMobility_ACC_DW->WritedesiredAx_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->WritedesiredAx_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write ACC IsActive' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\111\163\101\143\164\151\166\145",
      NULL);                           // AccelCtrl.ACC.IsActive
    SwitchMobility_ACC_DW->WriteACCIsActive_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->WriteACCIsActive_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write desired Ax' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\101\170",
      NULL);                           // AccelCtrl.ACC.DesiredAx
    SwitchMobility_ACC_DW->WritedesiredAx_IWORK_h.Checked = 0;
    SwitchMobility_ACC_DW->WritedesiredAx_PWORK_n.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S7>/Write desired speed' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\123\160\144",
      NULL);                           // AccelCtrl.ACC.DesiredSpd
    SwitchMobility_ACC_DW->Writedesiredspeed_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->Writedesiredspeed_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S7>/Read init desired time gap from Inf' */
  SwitchMobility_ACC_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam =
    InfoParam_Create(InfoParam_Vehicle,
                     "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\162\124\107\141\160",
                     1,
                     &SwitchMobility_ACC_ConstP.ReadinitdesiredtimegapfromInf_DefValue,
                     1);               // AccelCtrl.ACC.DesrTGap
  InfoParam_Read
    (SwitchMobility_ACC_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam, 0);

  /* Start for Triggered SubSystem: '<S7>/Init Desired time gap quantity' */

  /* Start for S-Function (write_dict): '<S14>/Write init time gap' */
  {
    char **namevec = CM_Names2StrVec(
      "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\124\107\141\160",
      NULL);                           // AccelCtrl.ACC.DesiredTGap
    SwitchMobility_ACC_DW->Writeinittimegap_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->Writeinittimegap_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* End of Start for SubSystem: '<S7>/Init Desired time gap quantity' */

  /* Start for S-Function (read_infoparam): '<S15>/Read init p-gain from Inf' */
  SwitchMobility_ACC_DW->ReadinitpgainfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "\101\143\143\145\154\103\164\162\154\056\160", 1,
     &SwitchMobility_ACC_ConstP.pooled1, 1);// AccelCtrl.p
  InfoParam_Read(SwitchMobility_ACC_DW->ReadinitpgainfromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (read_dict): '<S16>/Read Car.ax' */
  {
    char **namevec = CM_Names2StrVec("\103\141\162\056\141\170", NULL);// Car.ax
    SwitchMobility_ACC_DW->ReadCarax_IWORK.Checked = 0;
    SwitchMobility_ACC_DW->ReadCarax_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S15>/Read init i-gain from Inf' */
  SwitchMobility_ACC_DW->ReadinitigainfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "\101\143\143\145\154\103\164\162\154\056\151", 1,
     &SwitchMobility_ACC_ConstP.pooled1, 1);// AccelCtrl.i
  InfoParam_Read(SwitchMobility_ACC_DW->ReadinitigainfromInf_PWORK.InfoParam, 0);

  /* InitializeConditions for Memory: '<S7>/Memory' */
  SwitchMobility_ACC_DW->Memory_PreviousInput =
    SwitchMobility_ACC_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S17>/Memory' */
  SwitchMobility_ACC_DW->Memory_PreviousInput_j =
    SwitchMobility_ACC_P.Memory_InitialCondition_b;

  /* SystemInitialize for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' */
  /* SystemInitialize for MinMax: '<S8>/MinMax' incorporates:
   *  Outport: '<S8>/desired distance'
   */
  SwitchMobility_ACC_B->MinMax = SwitchMobility_ACC_P.desireddistance_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/Desired Distance Calculation with time gap' */
}

/* Model terminate function */
void SwitchMobility_ACC_terminate(RT_MODEL_SwitchMobility_ACC_T
  * SwitchMobility_ACC_M)
{
  DW_SwitchMobility_ACC_T *SwitchMobility_ACC_DW = SwitchMobility_ACC_M->dwork;

  /* Terminate for S-Function (read_infoparam): '<S3>/Read init brake threshold from Inf' */
  InfoParam_Destroy
    (SwitchMobility_ACC_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam);

  /* Terminate for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Terminate for S-Function (read_infoparam): '<S8>/Read init min distance from Inf' */
  InfoParam_Destroy
    (SwitchMobility_ACC_DW->ReadinitmindistancefromInf_PWORK.InfoParam);

  /* End of Terminate for SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Terminate for S-Function (read_infoparam): '<S7>/Read Init Velocity' */
  InfoParam_Destroy(SwitchMobility_ACC_DW->ReadInitVelocity_PWORK.InfoParam);

  /* Terminate for Atomic SubSystem: '<S6>/Speed Control Algorithm' */

  /* Terminate for S-Function (read_infoparam): '<S13>/Read init spdctrl.kv from Inf' */
  InfoParam_Destroy
    (SwitchMobility_ACC_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam);

  /* End of Terminate for SubSystem: '<S6>/Speed Control Algorithm' */

  /* Terminate for Atomic SubSystem: '<S6>/Distance Control Algorithm' */

  /* Terminate for S-Function (read_infoparam): '<S12>/Read init distctrl.kd from Inf' */
  InfoParam_Destroy
    (SwitchMobility_ACC_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam);

  /* Terminate for S-Function (read_infoparam): '<S12>/Read init distctrl.kv from Inf1' */
  InfoParam_Destroy
    (SwitchMobility_ACC_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam);

  /* End of Terminate for SubSystem: '<S6>/Distance Control Algorithm' */

  /* Terminate for S-Function (read_infoparam): '<S7>/Read init desired time gap from Inf' */
  InfoParam_Destroy
    (SwitchMobility_ACC_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam);

  /* Terminate for S-Function (read_infoparam): '<S15>/Read init p-gain from Inf' */
  InfoParam_Destroy(SwitchMobility_ACC_DW->ReadinitpgainfromInf_PWORK.InfoParam);

  /* Terminate for S-Function (read_infoparam): '<S15>/Read init i-gain from Inf' */
  InfoParam_Destroy(SwitchMobility_ACC_DW->ReadinitigainfromInf_PWORK.InfoParam);

  /* model code */
  rt_FREE(SwitchMobility_ACC_M->blockIO);
  rt_FREE(SwitchMobility_ACC_M->inputs);
  rt_FREE(SwitchMobility_ACC_M->outputs);
  rt_FREE(SwitchMobility_ACC_M->dwork);
  rt_FREE(SwitchMobility_ACC_M->prevZCSigState);
  rt_FREE(SwitchMobility_ACC_M);
}

/* Model data allocation function */
RT_MODEL_SwitchMobility_ACC_T *SwitchMobility_ACC(struct tInfos *inf)
{
  RT_MODEL_SwitchMobility_ACC_T *SwitchMobility_ACC_M;
  SwitchMobility_ACC_M = (RT_MODEL_SwitchMobility_ACC_T *) malloc(sizeof
    (RT_MODEL_SwitchMobility_ACC_T));
  if (SwitchMobility_ACC_M == (NULL)) {
    return (NULL);
  }

  (void) memset((char *)SwitchMobility_ACC_M, 0,
                sizeof(RT_MODEL_SwitchMobility_ACC_T));
  MatSupp_Init();

  /* block I/O */
  {
    B_SwitchMobility_ACC_T *b = (B_SwitchMobility_ACC_T *) malloc(sizeof
      (B_SwitchMobility_ACC_T));
    rt_VALIDATE_MEMORY(SwitchMobility_ACC_M,b);
    SwitchMobility_ACC_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_SwitchMobility_ACC_T *dwork = (DW_SwitchMobility_ACC_T *) malloc(sizeof
      (DW_SwitchMobility_ACC_T));
    rt_VALIDATE_MEMORY(SwitchMobility_ACC_M,dwork);
    SwitchMobility_ACC_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_SwitchMobility_ACC_T *SwitchMobility_ACC_U = (ExtU_SwitchMobility_ACC_T
      *) malloc(sizeof(ExtU_SwitchMobility_ACC_T));
    rt_VALIDATE_MEMORY(SwitchMobility_ACC_M,SwitchMobility_ACC_U);
    SwitchMobility_ACC_M->inputs = (((ExtU_SwitchMobility_ACC_T *)
      SwitchMobility_ACC_U));
  }

  /* external outputs */
  {
    ExtY_SwitchMobility_ACC_T *SwitchMobility_ACC_Y = (ExtY_SwitchMobility_ACC_T
      *) malloc(sizeof(ExtY_SwitchMobility_ACC_T));
    rt_VALIDATE_MEMORY(SwitchMobility_ACC_M,SwitchMobility_ACC_Y);
    SwitchMobility_ACC_M->outputs = (SwitchMobility_ACC_Y);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_SwitchMobility_ACC_T *zc = (PrevZCX_SwitchMobility_ACC_T *) malloc
      (sizeof(PrevZCX_SwitchMobility_ACC_T));
    rt_VALIDATE_MEMORY(SwitchMobility_ACC_M,zc);
    SwitchMobility_ACC_M->prevZCSigState = (zc);
  }

  /* CarMaker parameter tuning */
  {
    SwitchMobility_ACC_SetParams(SwitchMobility_ACC_M, NULL, inf);
  }

  {
    B_SwitchMobility_ACC_T *SwitchMobility_ACC_B = SwitchMobility_ACC_M->blockIO;
    DW_SwitchMobility_ACC_T *SwitchMobility_ACC_DW = SwitchMobility_ACC_M->dwork;
    PrevZCX_SwitchMobility_ACC_T *SwitchMobility_ACC_PrevZCX =
      SwitchMobility_ACC_M->prevZCSigState;
    ExtU_SwitchMobility_ACC_T *SwitchMobility_ACC_U = (ExtU_SwitchMobility_ACC_T
      *) SwitchMobility_ACC_M->inputs;
    ExtY_SwitchMobility_ACC_T *SwitchMobility_ACC_Y = (ExtY_SwitchMobility_ACC_T
      *) SwitchMobility_ACC_M->outputs;

    /* block I/O */
    (void) memset(((void *) SwitchMobility_ACC_B), 0,
                  sizeof(B_SwitchMobility_ACC_T));

    /* states (dwork) */
    (void) memset((void *)SwitchMobility_ACC_DW, 0,
                  sizeof(DW_SwitchMobility_ACC_T));

    /* external inputs */
    SwitchMobility_ACC_U->FromCM = SwitchMobility_ACC_rtZcmVehicleControlIn;

    /* external outputs */
    SwitchMobility_ACC_Y->ToCM = SwitchMobility_ACC_rtZcmVehicleControlOut;

    /* previous zero-crossing states */
    {
      SwitchMobility_ACC_PrevZCX->InitDesiredtimegapquantity_Trig_ZCE =
        UNINITIALIZED_ZCSIG;
    }
  }

  return SwitchMobility_ACC_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *SwitchMobility_ACC_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)SwitchMobility_ACC_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0,
    0.0 },

  { "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\111\163\101\143\164\151\166\145",
    "", "Char", 0, 2.0, 0.0, "DM", 1.0, 0.0 },// AccelCtrl.ACC.IsActive

  { "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\124\107\141\160",
    "\163", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },// AccelCtrl.ACC.DesiredTGap

  { "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\123\160\144",
    "\155\057\163", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },// AccelCtrl.ACC.DesiredSpd

  { "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\101\170",
    "\155\057\163\136\062", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },// AccelCtrl.ACC.DesiredAx

  { "\101\143\143\145\154\103\164\162\154\056\104\145\163\151\162\145\144\101\170",
    "\155\057\163\136\062", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },// AccelCtrl.DesiredAx

  { "\101\143\143\145\154\103\164\162\154\056\101\103\103\056\104\145\163\151\162\145\144\104\151\163\164",
    "\155", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },// AccelCtrl.ACC.DesiredDist

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *SwitchMobility_ACC_DictDefines = DictDefines;
tQuantEntry *SwitchMobility_ACC_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *SwitchMobility_ACC_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)SwitchMobility_ACC_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *SwitchMobility_ACC_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *SwitchMobility_ACC_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif

/*
 * SwitchMobility_ACC_data.c
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

/* Block parameters (default storage) */
P_SwitchMobility_ACC_T SwitchMobility_ACC_P = {
  /* Expression: 0
   * Referenced by: '<S8>/desired distance'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/-2.5<=ax<=1'
   */
  1.0,

  /* Expression: -2.5
   * Referenced by: '<S9>/-2.5<=ax<=1'
   */
  -2.5,

  /* Expression: 1
   * Referenced by: '<S10>/-0.35<=ax<=1'
   */
  1.0,

  /* Expression: -0.35
   * Referenced by: '<S10>/-0.35<=ax<=1'
   */
  -0.35,

  /* Expression: -99999
   * Referenced by: '<S6>/Ax is NOTSET'
   */
  -99999.0,

  /* Expression: 0.28
   * Referenced by: '<S7>/kmh2ms'
   */
  0.28,

  /* Expression: 0
   * Referenced by: '<S7>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/ACC Off'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S5>/Target dv'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S5>/No target'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Brake if -1<x<0'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Brake if -1<x<0'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Gas  if 0<=x<=1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Gas  if 0<=x<=1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/ACC Active ACC//Actual Speed'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S6>/desired or NOTSET'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Expression: -99999
   * Referenced by: '<S4>/Ax is NOTSET'
   */
  -99999.0,

  /* Expression: 0
   * Referenced by: '<S17>/Memory'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S15>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S15>/Saturation'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S17>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S17>/Saturation'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2>/UserSignal.s0'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/UserSignal.s1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/UserSignal.s2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/UserSignal.s3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/UserSignal.s4'
   */
  0.0,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S11>/Constant'
   */
  false,

  /* Computed Parameter: desiredAx_Threshold
   * Referenced by: '<S6>/desired Ax'
   */
  1U
};

/* Constant parameters (default storage) */
const ConstP_SwitchMobility_ACC_T SwitchMobility_ACC_ConstP = {
  /* Expression: xdefaults
   * Referenced by: '<S8>/Read init min distance from Inf'
   */
  20.0,

  /* Expression: xdefaults
   * Referenced by: '<S12>/Read init distctrl.kd from Inf'
   */
  36.0,

  /* Expression: xdefaults
   * Referenced by: '<S12>/Read init distctrl.kv from Inf1'
   */
  2.0,

  /* Expression: xdefaults
   * Referenced by: '<S13>/Read init spdctrl.kv from Inf'
   */
  13.0,

  /* Expression: xdefaults
   * Referenced by: '<S3>/Read init brake threshold from Inf'
   */
  0.2,

  /* Expression: xdefaults
   * Referenced by: '<S7>/Read Init Velocity'
   */
  0.0,

  /* Expression: xdefaults
   * Referenced by: '<S7>/Read init desired time gap from Inf'
   */
  1.8,

  /* Pooled Parameter (Expression: xdefaults)
   * Referenced by:
   *   '<S15>/Read init i-gain from Inf'
   *   '<S15>/Read init p-gain from Inf'
   */
  0.001
};

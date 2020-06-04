/*
 * distancesensor_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "distancesensor".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Mon Jun  1 23:57:11 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "distancesensor.h"
#include "distancesensor_private.h"

/* Block parameters (default storage) */
P_distancesensor_T distancesensor_P = {
  /* Expression: sampleTime
   * Referenced by: '<S1>/Digital Read'
   */
  0.0001,

  /* Expression: sampleTime
   * Referenced by: '<S2>/Digital Read'
   */
  0.0001,

  /* Expression: sampleTime
   * Referenced by: '<S3>/Digital Read'
   */
  0.0001,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  10000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0
};

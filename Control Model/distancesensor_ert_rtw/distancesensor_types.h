/*
 * distancesensor_types.h
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

#ifndef RTW_HEADER_distancesensor_types_h_
#define RTW_HEADER_distancesensor_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_linux_blocks_Digi_T
#define typedef_codertarget_linux_blocks_Digi_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
} codertarget_linux_blocks_Digi_T;

#endif                               /*typedef_codertarget_linux_blocks_Digi_T*/

#ifndef typedef_codertarget_linux_blocks_Di_a_T
#define typedef_codertarget_linux_blocks_Di_a_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_linux_blocks_Di_a_T;

#endif                               /*typedef_codertarget_linux_blocks_Di_a_T*/

/* Parameters (default storage) */
typedef struct P_distancesensor_T_ P_distancesensor_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_distancesensor_T RT_MODEL_distancesensor_T;

#endif                                 /* RTW_HEADER_distancesensor_types_h_ */

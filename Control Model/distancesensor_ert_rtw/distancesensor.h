/*
 * distancesensor.h
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

#ifndef RTW_HEADER_distancesensor_h_
#define RTW_HEADER_distancesensor_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef distancesensor_COMMON_INCLUDES_
# define distancesensor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_gpio.h"
#endif                                 /* distancesensor_COMMON_INCLUDES_ */

#include "distancesensor_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  boolean_T DigitalRead;               /* '<S3>/Digital Read' */
  boolean_T DigitalRead_m;             /* '<S2>/Digital Read' */
  boolean_T DigitalRead_o;             /* '<S1>/Digital Read' */
} B_distancesensor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S3>/Digital Read' */
  codertarget_linux_blocks_Digi_T obj_i;/* '<S2>/Digital Read' */
  codertarget_linux_blocks_Digi_T obj_d;/* '<S1>/Digital Read' */
  codertarget_linux_blocks_Di_a_T obj_m;/* '<S6>/Digital Write' */
  codertarget_linux_blocks_Di_a_T obj_g;/* '<S5>/Digital Write' */
  codertarget_linux_blocks_Di_a_T obj_gu;/* '<S4>/Digital Write' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_GPIOR;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_GPI_g;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_GPI_f;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Pulse;   /* synthesized block */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  boolean_T objisempty;                /* '<S6>/Digital Write' */
  boolean_T objisempty_k;              /* '<S5>/Digital Write' */
  boolean_T objisempty_j;              /* '<S4>/Digital Write' */
  boolean_T objisempty_kt;             /* '<S3>/Digital Read' */
  boolean_T objisempty_f;              /* '<S2>/Digital Read' */
  boolean_T objisempty_g;              /* '<S1>/Digital Read' */
} DW_distancesensor_T;

/* Parameters (default storage) */
struct P_distancesensor_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: sampleTime
                                        * Referenced by: '<S1>/Digital Read'
                                        */
  real_T DigitalRead_SampleTime_o;     /* Expression: sampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T DigitalRead_SampleTime_b;     /* Expression: sampleTime
                                        * Referenced by: '<S3>/Digital Read'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_distancesensor_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_distancesensor_T distancesensor_P;

/* Block signals (default storage) */
extern B_distancesensor_T distancesensor_B;

/* Block states (default storage) */
extern DW_distancesensor_T distancesensor_DW;

/* Model entry point functions */
extern void distancesensor_initialize(void);
extern void distancesensor_step(void);
extern void distancesensor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_distancesensor_T *const distancesensor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'distancesensor'
 * '<S1>'   : 'distancesensor/GPIO Read'
 * '<S2>'   : 'distancesensor/GPIO Read1'
 * '<S3>'   : 'distancesensor/GPIO Read2'
 * '<S4>'   : 'distancesensor/GPIO Write'
 * '<S5>'   : 'distancesensor/GPIO Write1'
 * '<S6>'   : 'distancesensor/GPIO Write2'
 */
#endif                                 /* RTW_HEADER_distancesensor_h_ */

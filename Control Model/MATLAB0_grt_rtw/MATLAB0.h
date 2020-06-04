/*
 * MATLAB0.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MATLAB0".
 *
 * Model version              : 1.106
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Sat Apr 11 04:21:50 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MATLAB0_h_
#define RTW_HEADER_MATLAB0_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MATLAB0_COMMON_INCLUDES_
# define MATLAB0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* MATLAB0_COMMON_INCLUDES_ */

#include "MATLAB0_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T StateVariables[10];           /* '<Root>/x' */
  real_T WingAngles[4];                /* '<Root>/u' */
  real_T AerodynamicConstants[84];     /* '<Root>/km' */
  real_T PropellerThrust;              /* '<Root>/T' */
} ExtU_MATLAB0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T z[10];                        /* '<Root>/z' */
} ExtY_MATLAB0_T;

/* Real-time Model Data Structure */
struct tag_RTM_MATLAB0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

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
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_MATLAB0_T MATLAB0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MATLAB0_T MATLAB0_Y;

/* Model entry point functions */
extern void MATLAB0_initialize(void);
extern void MATLAB0_step(void);
extern void MATLAB0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MATLAB0_T *const MATLAB0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('scalemodelsimulation/Hydrofoil Boat Model/MATLAB Function')    - opens subsystem scalemodelsimulation/Hydrofoil Boat Model/MATLAB Function
 * hilite_system('scalemodelsimulation/Hydrofoil Boat Model/MATLAB Function/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'scalemodelsimulation/Hydrofoil Boat Model'
 * '<S1>'   : 'scalemodelsimulation/Hydrofoil Boat Model/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_MATLAB0_h_ */

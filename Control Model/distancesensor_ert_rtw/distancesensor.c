/*
 * distancesensor.c
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

/* Block signals (default storage) */
B_distancesensor_T distancesensor_B;

/* Block states (default storage) */
DW_distancesensor_T distancesensor_DW;

/* Real-time model */
RT_MODEL_distancesensor_T distancesensor_M_;
RT_MODEL_distancesensor_T *const distancesensor_M = &distancesensor_M_;

/* Forward declaration for local functions */
static void distancesens_SystemCore_release(const
  codertarget_linux_blocks_Digi_T *obj);
static void distancesenso_SystemCore_delete(const
  codertarget_linux_blocks_Digi_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_linux_blocks_Digi_T *obj);
static void distancese_SystemCore_release_a(const
  codertarget_linux_blocks_Digi_T *obj);
static void distancesen_SystemCore_delete_a(const
  codertarget_linux_blocks_Digi_T *obj);
static void matlabCodegenHandle_matlabCod_a(codertarget_linux_blocks_Digi_T *obj);
static void distances_SystemCore_release_a3(const
  codertarget_linux_blocks_Digi_T *obj);
static void distancese_SystemCore_delete_a3(const
  codertarget_linux_blocks_Digi_T *obj);
static void matlabCodegenHandle_matlabCo_a3(codertarget_linux_blocks_Digi_T *obj);
static void distance_SystemCore_release_a3f(const
  codertarget_linux_blocks_Di_a_T *obj);
static void distances_SystemCore_delete_a3f(const
  codertarget_linux_blocks_Di_a_T *obj);
static void matlabCodegenHandle_matlabC_a3f(codertarget_linux_blocks_Di_a_T *obj);
static void distanc_SystemCore_release_a3fs(const
  codertarget_linux_blocks_Di_a_T *obj);
static void distance_SystemCore_delete_a3fs(const
  codertarget_linux_blocks_Di_a_T *obj);
static void matlabCodegenHandle_matlab_a3fs(codertarget_linux_blocks_Di_a_T *obj);
static void distan_SystemCore_release_a3fsh(const
  codertarget_linux_blocks_Di_a_T *obj);
static void distanc_SystemCore_delete_a3fsh(const
  codertarget_linux_blocks_Di_a_T *obj);
static void matlabCodegenHandle_matla_a3fsh(codertarget_linux_blocks_Di_a_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void distancesens_SystemCore_release(const
  codertarget_linux_blocks_Digi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(16U);
  }
}

static void distancesenso_SystemCore_delete(const
  codertarget_linux_blocks_Digi_T *obj)
{
  distancesens_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    distancesenso_SystemCore_delete(obj);
  }
}

static void distancese_SystemCore_release_a(const
  codertarget_linux_blocks_Digi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(18U);
  }
}

static void distancesen_SystemCore_delete_a(const
  codertarget_linux_blocks_Digi_T *obj)
{
  distancese_SystemCore_release_a(obj);
}

static void matlabCodegenHandle_matlabCod_a(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    distancesen_SystemCore_delete_a(obj);
  }
}

static void distances_SystemCore_release_a3(const
  codertarget_linux_blocks_Digi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(20U);
  }
}

static void distancese_SystemCore_delete_a3(const
  codertarget_linux_blocks_Digi_T *obj)
{
  distances_SystemCore_release_a3(obj);
}

static void matlabCodegenHandle_matlabCo_a3(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    distancese_SystemCore_delete_a3(obj);
  }
}

static void distance_SystemCore_release_a3f(const
  codertarget_linux_blocks_Di_a_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(26U);
  }
}

static void distances_SystemCore_delete_a3f(const
  codertarget_linux_blocks_Di_a_T *obj)
{
  distance_SystemCore_release_a3f(obj);
}

static void matlabCodegenHandle_matlabC_a3f(codertarget_linux_blocks_Di_a_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    distances_SystemCore_delete_a3f(obj);
  }
}

static void distanc_SystemCore_release_a3fs(const
  codertarget_linux_blocks_Di_a_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(19U);
  }
}

static void distance_SystemCore_delete_a3fs(const
  codertarget_linux_blocks_Di_a_T *obj)
{
  distanc_SystemCore_release_a3fs(obj);
}

static void matlabCodegenHandle_matlab_a3fs(codertarget_linux_blocks_Di_a_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    distance_SystemCore_delete_a3fs(obj);
  }
}

static void distan_SystemCore_release_a3fsh(const
  codertarget_linux_blocks_Di_a_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(13U);
  }
}

static void distanc_SystemCore_delete_a3fsh(const
  codertarget_linux_blocks_Di_a_T *obj)
{
  distan_SystemCore_release_a3fsh(obj);
}

static void matlabCodegenHandle_matla_a3fsh(codertarget_linux_blocks_Di_a_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    distanc_SystemCore_delete_a3fsh(obj);
  }
}

/* Model step function */
void distancesensor_step(void)
{
  uint8_T tmp;
  real_T tmp_0;

  /* MATLABSystem: '<S1>/Digital Read' */
  if (distancesensor_DW.obj_d.SampleTime !=
      distancesensor_P.DigitalRead_SampleTime) {
    distancesensor_DW.obj_d.SampleTime = distancesensor_P.DigitalRead_SampleTime;
  }

  distancesensor_B.DigitalRead_o = MW_gpioRead(16U);

  /* End of MATLABSystem: '<S1>/Digital Read' */

  /* MATLABSystem: '<S2>/Digital Read' */
  if (distancesensor_DW.obj_i.SampleTime !=
      distancesensor_P.DigitalRead_SampleTime_o) {
    distancesensor_DW.obj_i.SampleTime =
      distancesensor_P.DigitalRead_SampleTime_o;
  }

  distancesensor_B.DigitalRead_m = MW_gpioRead(18U);

  /* End of MATLABSystem: '<S2>/Digital Read' */

  /* MATLABSystem: '<S3>/Digital Read' */
  if (distancesensor_DW.obj.SampleTime !=
      distancesensor_P.DigitalRead_SampleTime_b) {
    distancesensor_DW.obj.SampleTime = distancesensor_P.DigitalRead_SampleTime_b;
  }

  distancesensor_B.DigitalRead = MW_gpioRead(20U);

  /* End of MATLABSystem: '<S3>/Digital Read' */
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  distancesensor_B.PulseGenerator = (distancesensor_DW.clockTickCounter <
    distancesensor_P.PulseGenerator_Duty) && (distancesensor_DW.clockTickCounter
    >= 0) ? distancesensor_P.PulseGenerator_Amp : 0.0;
  if (distancesensor_DW.clockTickCounter >=
      distancesensor_P.PulseGenerator_Period - 1.0) {
    distancesensor_DW.clockTickCounter = 0;
  } else {
    distancesensor_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S4>/Digital Write' incorporates:
   *  MATLABSystem: '<S5>/Digital Write'
   *  MATLABSystem: '<S6>/Digital Write'
   */
  tmp_0 = rt_roundd_snf(distancesensor_B.PulseGenerator);
  if (tmp_0 < 256.0) {
    if (tmp_0 >= 0.0) {
      tmp = (uint8_T)tmp_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_gpioWrite(26U, tmp);

  /* End of MATLABSystem: '<S4>/Digital Write' */

  /* MATLABSystem: '<S5>/Digital Write' */
  if (tmp_0 < 256.0) {
    if (tmp_0 >= 0.0) {
      tmp = (uint8_T)tmp_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_gpioWrite(19U, tmp);

  /* MATLABSystem: '<S6>/Digital Write' */
  if (tmp_0 < 256.0) {
    if (tmp_0 >= 0.0) {
      tmp = (uint8_T)tmp_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_gpioWrite(13U, tmp);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rtExtModeUpload(0, (real_T)distancesensor_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0001s, 0.0s] */
    if ((rtmGetTFinal(distancesensor_M)!=-1) &&
        !((rtmGetTFinal(distancesensor_M)-distancesensor_M->Timing.taskTime0) >
          distancesensor_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(distancesensor_M, "Simulation finished");
    }

    if (rtmGetStopRequested(distancesensor_M)) {
      rtmSetErrorStatus(distancesensor_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++distancesensor_M->Timing.clockTick0)) {
    ++distancesensor_M->Timing.clockTickH0;
  }

  distancesensor_M->Timing.taskTime0 = distancesensor_M->Timing.clockTick0 *
    distancesensor_M->Timing.stepSize0 + distancesensor_M->Timing.clockTickH0 *
    distancesensor_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void distancesensor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)distancesensor_M, 0,
                sizeof(RT_MODEL_distancesensor_T));
  rtmSetTFinal(distancesensor_M, 999999.0);
  distancesensor_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  distancesensor_M->Sizes.checksums[0] = (3182904749U);
  distancesensor_M->Sizes.checksums[1] = (156799932U);
  distancesensor_M->Sizes.checksums[2] = (3839169592U);
  distancesensor_M->Sizes.checksums[3] = (1584303665U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    distancesensor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(distancesensor_M->extModeInfo,
      &distancesensor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(distancesensor_M->extModeInfo,
                        distancesensor_M->Sizes.checksums);
    rteiSetTPtr(distancesensor_M->extModeInfo, rtmGetTPtr(distancesensor_M));
  }

  /* block I/O */
  (void) memset(((void *) &distancesensor_B), 0,
                sizeof(B_distancesensor_T));

  /* states (dwork) */
  (void) memset((void *)&distancesensor_DW, 0,
                sizeof(DW_distancesensor_T));

  /* Start for MATLABSystem: '<S1>/Digital Read' */
  distancesensor_DW.obj_d.matlabCodegenIsDeleted = false;
  distancesensor_DW.objisempty_g = true;
  distancesensor_DW.obj_d.SampleTime = distancesensor_P.DigitalRead_SampleTime;
  distancesensor_DW.obj_d.isInitialized = 1;
  MW_gpioInit(16U, false);
  distancesensor_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Digital Read' */
  distancesensor_DW.obj_i.matlabCodegenIsDeleted = false;
  distancesensor_DW.objisempty_f = true;
  distancesensor_DW.obj_i.SampleTime = distancesensor_P.DigitalRead_SampleTime_o;
  distancesensor_DW.obj_i.isInitialized = 1;
  MW_gpioInit(18U, false);
  distancesensor_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Read' */
  distancesensor_DW.obj.matlabCodegenIsDeleted = false;
  distancesensor_DW.objisempty_kt = true;
  distancesensor_DW.obj.SampleTime = distancesensor_P.DigitalRead_SampleTime_b;
  distancesensor_DW.obj.isInitialized = 1;
  MW_gpioInit(20U, false);
  distancesensor_DW.obj.isSetupComplete = true;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  distancesensor_DW.clockTickCounter = 0;

  /* Start for MATLABSystem: '<S4>/Digital Write' */
  distancesensor_DW.obj_gu.matlabCodegenIsDeleted = false;
  distancesensor_DW.objisempty_j = true;
  distancesensor_DW.obj_gu.isInitialized = 1;
  MW_gpioInit(26U, true);
  distancesensor_DW.obj_gu.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Write' */
  distancesensor_DW.obj_g.matlabCodegenIsDeleted = false;
  distancesensor_DW.objisempty_k = true;
  distancesensor_DW.obj_g.isInitialized = 1;
  MW_gpioInit(19U, true);
  distancesensor_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Digital Write' */
  distancesensor_DW.obj_m.matlabCodegenIsDeleted = false;
  distancesensor_DW.objisempty = true;
  distancesensor_DW.obj_m.isInitialized = 1;
  MW_gpioInit(13U, true);
  distancesensor_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void distancesensor_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Read' */
  matlabCodegenHandle_matlabCodeg(&distancesensor_DW.obj_d);

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  matlabCodegenHandle_matlabCod_a(&distancesensor_DW.obj_i);

  /* Terminate for MATLABSystem: '<S3>/Digital Read' */
  matlabCodegenHandle_matlabCo_a3(&distancesensor_DW.obj);

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  matlabCodegenHandle_matlabC_a3f(&distancesensor_DW.obj_gu);

  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  matlabCodegenHandle_matlab_a3fs(&distancesensor_DW.obj_g);

  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  matlabCodegenHandle_matla_a3fsh(&distancesensor_DW.obj_m);
}

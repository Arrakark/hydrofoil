/*
 * MATLAB0.c
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

#include "MATLAB0.h"
#include "MATLAB0_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_MATLAB0_T MATLAB0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MATLAB0_T MATLAB0_Y;

/* Real-time model */
RT_MODEL_MATLAB0_T MATLAB0_M_;
RT_MODEL_MATLAB0_T *const MATLAB0_M = &MATLAB0_M_;

/* Forward declaration for local functions */
static void MATLAB0_sind(real_T *x);
static void MATLAB0_cosd(real_T *x);
static void MATLAB0_tand(real_T *x);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MATLAB0_M->Timing.TaskCounters.TID[1])++;
  if ((MATLAB0_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.5s, 0.0s] */
    MATLAB0_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MATLAB0_sind(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      *x = sin(c_x);
    } else {
      if (absx <= 135.0) {
        if (c_x > 0.0) {
          c_x = (c_x - 90.0) * 0.017453292519943295;
          n = 1;
        } else {
          c_x = (c_x + 90.0) * 0.017453292519943295;
          n = -1;
        }
      } else if (c_x > 0.0) {
        c_x = (c_x - 180.0) * 0.017453292519943295;
        n = 2;
      } else {
        c_x = (c_x + 180.0) * 0.017453292519943295;
        n = -2;
      }

      if (n == 1) {
        *x = cos(c_x);
      } else if (n == -1) {
        *x = -cos(c_x);
      } else {
        *x = -sin(c_x);
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MATLAB0_cosd(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      *x = cos(b_x);
    } else {
      if (absx <= 135.0) {
        if (b_x > 0.0) {
          b_x = (b_x - 90.0) * 0.017453292519943295;
          n = 1;
        } else {
          b_x = (b_x + 90.0) * 0.017453292519943295;
          n = -1;
        }
      } else if (b_x > 0.0) {
        b_x = (b_x - 180.0) * 0.017453292519943295;
        n = 2;
      } else {
        b_x = (b_x + 180.0) * 0.017453292519943295;
        n = -2;
      }

      if (n == 1) {
        *x = -sin(b_x);
      } else if (n == -1) {
        *x = sin(b_x);
      } else {
        *x = -cos(b_x);
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void MATLAB0_tand(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    *x = tan(b_x);
    if ((n == 1) || (n == -1)) {
      b_x = 1.0 / *x;
      *x = -(1.0 / *x);
      if (rtIsInf(*x) && (n == 1)) {
        *x = b_x;
      }
    }
  }
}

/* Model step function */
void MATLAB0_step(void)
{
  real_T X;
  real_T Y;
  real_T Z;
  real_T L;
  real_T M;
  real_T N;
  real_T Vt2;
  real_T qbar;
  real_T Fdrag;
  real_T Flift;
  real_T b_a;
  real_T qb;
  real_T Fdrag_tmp;
  real_T b_a_tmp;
  real_T c_a_tmp;
  real_T d_a_tmp;
  real_T e_a_tmp;
  real_T b_a_tmp_0;
  real_T c_a_tmp_0;
  real_T d_a_tmp_0;
  real_T e_a_tmp_0;
  real_T c_a_tmp_1;
  real_T e_a_tmp_1;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/T'
   *  Inport: '<Root>/km'
   *  Inport: '<Root>/u'
   *  Inport: '<Root>/x'
   *  Outport: '<Root>/z'
   */
  Vt2 = MATLAB0_U.StateVariables[0] * MATLAB0_U.StateVariables[0];
  qbar = 498.5 * Vt2;
  Fdrag_tmp = MATLAB0_U.StateVariables[2] + MATLAB0_U.WingAngles[0];
  Fdrag = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[16];
  Fdrag = (Fdrag * Fdrag * MATLAB0_U.AerodynamicConstants[12] +
           MATLAB0_U.AerodynamicConstants[8]) * (qbar * 0.075);
  Flift = (Fdrag_tmp * MATLAB0_U.AerodynamicConstants[0] +
           MATLAB0_U.AerodynamicConstants[4]) * (qbar * 0.075);
  Y = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[24];
  L = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[40];
  M = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[56];
  N = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[72];
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&Fdrag_tmp);
  qb = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&qb);
  X = Flift * Fdrag_tmp - Fdrag * qb;
  b_a = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&b_a);
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&Fdrag_tmp);
  Z = -Fdrag * b_a - Flift * Fdrag_tmp;
  Fdrag_tmp = MATLAB0_U.StateVariables[2] + MATLAB0_U.WingAngles[1];
  Fdrag = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[17];
  Fdrag = (Fdrag * Fdrag * MATLAB0_U.AerodynamicConstants[13] +
           MATLAB0_U.AerodynamicConstants[9]) * (qbar * 0.075);
  Flift = (Fdrag_tmp * MATLAB0_U.AerodynamicConstants[1] +
           MATLAB0_U.AerodynamicConstants[5]) * (qbar * 0.075);
  b_a_tmp = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[25];
  c_a_tmp = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[41];
  d_a_tmp = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[57];
  e_a_tmp = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[73];
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&Fdrag_tmp);
  qb = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&qb);
  X += Flift * Fdrag_tmp - Fdrag * qb;
  b_a = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&b_a);
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&Fdrag_tmp);
  Z += -Fdrag * b_a - Flift * Fdrag_tmp;
  Fdrag_tmp = MATLAB0_U.StateVariables[2] + MATLAB0_U.WingAngles[2];
  Fdrag = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[18];
  Fdrag = (Fdrag * Fdrag * MATLAB0_U.AerodynamicConstants[14] +
           MATLAB0_U.AerodynamicConstants[10]) * (qbar * 0.101);
  Flift = (Fdrag_tmp * MATLAB0_U.AerodynamicConstants[2] +
           MATLAB0_U.AerodynamicConstants[6]) * (qbar * 0.101);
  b_a_tmp_0 = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[26];
  c_a_tmp_0 = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[42];
  d_a_tmp_0 = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[58];
  e_a_tmp_0 = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[74];
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&Fdrag_tmp);
  qb = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&qb);
  X += Flift * Fdrag_tmp - Fdrag * qb;
  b_a = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&b_a);
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&Fdrag_tmp);
  Z += -Fdrag * b_a - Flift * Fdrag_tmp;
  Fdrag_tmp = MATLAB0_U.StateVariables[2] + MATLAB0_U.WingAngles[3];
  Fdrag = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[19];
  Fdrag = (Fdrag * Fdrag * MATLAB0_U.AerodynamicConstants[15] +
           MATLAB0_U.AerodynamicConstants[11]) * (qbar * 0.101);
  Flift = (Fdrag_tmp * MATLAB0_U.AerodynamicConstants[3] +
           MATLAB0_U.AerodynamicConstants[7]) * (qbar * 0.101);
  b_a = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[27];
  c_a_tmp_1 = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[43];
  qbar = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[59];
  e_a_tmp_1 = Fdrag_tmp - MATLAB0_U.AerodynamicConstants[75];
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&Fdrag_tmp);
  qb = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&qb);
  X += Flift * Fdrag_tmp - Fdrag * qb;
  Y = ((b_a * MATLAB0_U.AerodynamicConstants[23] + b_a * b_a *
        MATLAB0_U.AerodynamicConstants[31]) + MATLAB0_U.AerodynamicConstants[35])
    * Vt2 + (((b_a_tmp_0 * MATLAB0_U.AerodynamicConstants[22] + b_a_tmp_0 *
               b_a_tmp_0 * MATLAB0_U.AerodynamicConstants[30]) +
              MATLAB0_U.AerodynamicConstants[34]) * Vt2 + (((b_a_tmp *
    MATLAB0_U.AerodynamicConstants[21] + b_a_tmp * b_a_tmp *
    MATLAB0_U.AerodynamicConstants[29]) + MATLAB0_U.AerodynamicConstants[33]) *
              Vt2 + ((Y * MATLAB0_U.AerodynamicConstants[20] + Y * Y *
                      MATLAB0_U.AerodynamicConstants[28]) +
                     MATLAB0_U.AerodynamicConstants[32]) * Vt2));
  b_a = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&b_a);
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&Fdrag_tmp);
  Z += -Fdrag * b_a - Flift * Fdrag_tmp;
  L = ((c_a_tmp_1 * MATLAB0_U.AerodynamicConstants[39] + c_a_tmp_1 * c_a_tmp_1 *
        MATLAB0_U.AerodynamicConstants[47]) + MATLAB0_U.AerodynamicConstants[51])
    * Vt2 + (((c_a_tmp_0 * MATLAB0_U.AerodynamicConstants[38] + c_a_tmp_0 *
               c_a_tmp_0 * MATLAB0_U.AerodynamicConstants[46]) +
              MATLAB0_U.AerodynamicConstants[50]) * Vt2 + (((c_a_tmp *
    MATLAB0_U.AerodynamicConstants[37] + c_a_tmp * c_a_tmp *
    MATLAB0_U.AerodynamicConstants[45]) + MATLAB0_U.AerodynamicConstants[49]) *
              Vt2 + ((L * MATLAB0_U.AerodynamicConstants[36] + L * L *
                      MATLAB0_U.AerodynamicConstants[44]) +
                     MATLAB0_U.AerodynamicConstants[48]) * Vt2));
  M = (((qbar * MATLAB0_U.AerodynamicConstants[55] + qbar * qbar *
         MATLAB0_U.AerodynamicConstants[63]) + MATLAB0_U.AerodynamicConstants[67])
       * Vt2 + MATLAB0_U.PropellerThrust) + ((((d_a_tmp_0 *
    MATLAB0_U.AerodynamicConstants[54] + d_a_tmp_0 * d_a_tmp_0 *
    MATLAB0_U.AerodynamicConstants[62]) + MATLAB0_U.AerodynamicConstants[66]) *
    Vt2 + MATLAB0_U.PropellerThrust) + ((((d_a_tmp *
    MATLAB0_U.AerodynamicConstants[53] + d_a_tmp * d_a_tmp *
    MATLAB0_U.AerodynamicConstants[61]) + MATLAB0_U.AerodynamicConstants[65]) *
    Vt2 + MATLAB0_U.PropellerThrust) + (((M * MATLAB0_U.AerodynamicConstants[52]
    + M * M * MATLAB0_U.AerodynamicConstants[60]) +
    MATLAB0_U.AerodynamicConstants[64]) * Vt2 + MATLAB0_U.PropellerThrust)));
  N = ((e_a_tmp_1 * MATLAB0_U.AerodynamicConstants[71] + e_a_tmp_1 * e_a_tmp_1 *
        MATLAB0_U.AerodynamicConstants[79]) + MATLAB0_U.AerodynamicConstants[83])
    * Vt2 + (((e_a_tmp_0 * MATLAB0_U.AerodynamicConstants[70] + e_a_tmp_0 *
               e_a_tmp_0 * MATLAB0_U.AerodynamicConstants[78]) +
              MATLAB0_U.AerodynamicConstants[82]) * Vt2 + (((e_a_tmp *
    MATLAB0_U.AerodynamicConstants[69] + e_a_tmp * e_a_tmp *
    MATLAB0_U.AerodynamicConstants[77]) + MATLAB0_U.AerodynamicConstants[81]) *
              Vt2 + ((N * MATLAB0_U.AerodynamicConstants[68] + N * N *
                      MATLAB0_U.AerodynamicConstants[76]) +
                     MATLAB0_U.AerodynamicConstants[80]) * Vt2));
  X += MATLAB0_U.PropellerThrust;
  Vt2 = MATLAB0_U.StateVariables[1];
  MATLAB0_sind(&Vt2);
  qbar = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&qbar);
  Fdrag = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&Fdrag);
  Flift = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&Flift);
  e_a_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&e_a_tmp);
  e_a_tmp_0 = MATLAB0_U.StateVariables[1];
  MATLAB0_sind(&e_a_tmp_0);
  d_a_tmp = MATLAB0_U.StateVariables[3];
  MATLAB0_sind(&d_a_tmp);
  b_a = MATLAB0_U.StateVariables[4];
  MATLAB0_sind(&b_a);
  Fdrag_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&Fdrag_tmp);
  qb = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&qb);
  d_a_tmp_0 = MATLAB0_U.StateVariables[4];
  MATLAB0_sind(&d_a_tmp_0);
  c_a_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&c_a_tmp);
  c_a_tmp_0 = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&c_a_tmp_0);
  e_a_tmp_1 = MATLAB0_U.StateVariables[4];
  MATLAB0_cosd(&e_a_tmp_1);
  b_a_tmp = MATLAB0_U.StateVariables[3];
  MATLAB0_cosd(&b_a_tmp);
  MATLAB0_Y.z[0] = ((X * qbar * Fdrag + Y * Vt2) + Z * Flift * e_a_tmp) *
    0.0033557046979865771 + ((e_a_tmp_0 * d_a_tmp * b_a - Fdrag_tmp * qb *
    d_a_tmp_0) + c_a_tmp * c_a_tmp_0 * e_a_tmp_1 * b_a_tmp) * 9.81;
  MATLAB0_Y.z[1] = 0.0;
  Y = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&Y);
  Vt2 = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&Vt2);
  qbar = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&qbar);
  Fdrag = MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&Fdrag);
  Flift = MATLAB0_U.StateVariables[4];
  MATLAB0_sind(&Flift);
  e_a_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&e_a_tmp);
  e_a_tmp_0 = MATLAB0_U.StateVariables[3];
  MATLAB0_cosd(&e_a_tmp_0);
  d_a_tmp = MATLAB0_U.StateVariables[4];
  MATLAB0_cosd(&d_a_tmp);
  b_a = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&b_a);
  Fdrag_tmp = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&Fdrag_tmp);
  qb = MATLAB0_U.StateVariables[1];
  MATLAB0_cosd(&qb);
  d_a_tmp_0 = MATLAB0_U.StateVariables[1];
  MATLAB0_sind(&d_a_tmp_0);
  c_a_tmp = MATLAB0_U.StateVariables[2];
  MATLAB0_cosd(&c_a_tmp);
  MATLAB0_Y.z[2] = ((e_a_tmp * e_a_tmp_0 * d_a_tmp + Fdrag * Flift) * 9.81 / b_a
                    + (Z * Y - X * Vt2) / (298.0 * qbar)) +
    (MATLAB0_U.StateVariables[7] * qb - (MATLAB0_U.StateVariables[6] * c_a_tmp +
      MATLAB0_U.StateVariables[8] * MATLAB0_U.StateVariables[2]) * d_a_tmp_0) *
    (1.0 / Fdrag_tmp);
  X = MATLAB0_U.StateVariables[3];
  MATLAB0_cosd(&X);
  Z = MATLAB0_U.StateVariables[4];
  MATLAB0_tand(&Z);
  Y = MATLAB0_U.StateVariables[3];
  MATLAB0_sind(&Y);
  Vt2 = MATLAB0_U.StateVariables[4];
  MATLAB0_tand(&Vt2);
  MATLAB0_Y.z[3] = (MATLAB0_U.StateVariables[8] * X * Z +
                    MATLAB0_U.StateVariables[6]) + MATLAB0_U.StateVariables[7] *
    Y * Vt2;
  X = MATLAB0_U.StateVariables[3];
  MATLAB0_cosd(&X);
  Z = MATLAB0_U.StateVariables[3];
  MATLAB0_sind(&Z);
  MATLAB0_Y.z[4] = MATLAB0_U.StateVariables[7] * X - MATLAB0_U.StateVariables[8]
    * Z;
  X = MATLAB0_U.StateVariables[4];
  MATLAB0_cosd(&X);
  Z = MATLAB0_U.StateVariables[3];
  MATLAB0_sind(&Z);
  Y = MATLAB0_U.StateVariables[3];
  MATLAB0_cosd(&Y);
  MATLAB0_Y.z[5] = (MATLAB0_U.StateVariables[7] * Z + MATLAB0_U.StateVariables[8]
                    * Y) * (1.0 / X);
  MATLAB0_Y.z[6] = (-MATLAB0_U.StateVariables[7] * MATLAB0_U.StateVariables[8] *
                    0.0 / 100.0 + MATLAB0_U.StateVariables[7] *
                    MATLAB0_U.StateVariables[6] * 100.0 / 100.0) + L / 100.0;
  MATLAB0_Y.z[7] = (-MATLAB0_U.StateVariables[6] * MATLAB0_U.StateVariables[8] *
                    0.0 / 100.0 - (MATLAB0_U.StateVariables[6] *
    MATLAB0_U.StateVariables[6] - MATLAB0_U.StateVariables[8] *
    MATLAB0_U.StateVariables[8]) * 100.0 / 100.0) + M / 100.0;
  MATLAB0_Y.z[8] = (-MATLAB0_U.StateVariables[6] * MATLAB0_U.StateVariables[7] *
                    0.0 / 100.0 - MATLAB0_U.StateVariables[7] *
                    MATLAB0_U.StateVariables[8] * 100.0 / 100.0) + N / 100.0;
  L = MATLAB0_U.StateVariables[4] - MATLAB0_U.StateVariables[2];
  MATLAB0_sind(&L);
  MATLAB0_Y.z[9] = L * MATLAB0_U.StateVariables[0];

  /* Matfile logging */
  rt_UpdateTXYLogVars(MATLAB0_M->rtwLogInfo, (&MATLAB0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(MATLAB0_M)!=-1) &&
        !((rtmGetTFinal(MATLAB0_M)-MATLAB0_M->Timing.taskTime0) >
          MATLAB0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MATLAB0_M, "Simulation finished");
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
  if (!(++MATLAB0_M->Timing.clockTick0)) {
    ++MATLAB0_M->Timing.clockTickH0;
  }

  MATLAB0_M->Timing.taskTime0 = MATLAB0_M->Timing.clockTick0 *
    MATLAB0_M->Timing.stepSize0 + MATLAB0_M->Timing.clockTickH0 *
    MATLAB0_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler();
}

/* Model initialize function */
void MATLAB0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MATLAB0_M, 0,
                sizeof(RT_MODEL_MATLAB0_T));
  rtmSetTFinal(MATLAB0_M, 0.5);
  MATLAB0_M->Timing.stepSize0 = 0.05;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    MATLAB0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(MATLAB0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(MATLAB0_M->rtwLogInfo, (NULL));
    rtliSetLogT(MATLAB0_M->rtwLogInfo, "tout");
    rtliSetLogX(MATLAB0_M->rtwLogInfo, "");
    rtliSetLogXFinal(MATLAB0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(MATLAB0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(MATLAB0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(MATLAB0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(MATLAB0_M->rtwLogInfo, 1);
    rtliSetLogY(MATLAB0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(MATLAB0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(MATLAB0_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&MATLAB0_U, 0, sizeof(ExtU_MATLAB0_T));

  /* external outputs */
  (void) memset(&MATLAB0_Y.z[0], 0,
                10U*sizeof(real_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(MATLAB0_M->rtwLogInfo, 0.0, rtmGetTFinal
    (MATLAB0_M), MATLAB0_M->Timing.stepSize0, (&rtmGetErrorStatus(MATLAB0_M)));
}

/* Model terminate function */
void MATLAB0_terminate(void)
{
  /* (no terminate code required) */
}

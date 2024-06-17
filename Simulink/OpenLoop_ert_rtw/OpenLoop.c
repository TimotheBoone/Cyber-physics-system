/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OpenLoop.c
 *
 * Code generated for Simulink model 'OpenLoop'.
 *
 * Model version                  : 6.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 12 16:55:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OpenLoop.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rtwtypes.h"
#include "OpenLoop_private.h"
#include <string.h>

/* Block signals (default storage) */
B_OpenLoop_T OpenLoop_B;

/* Continuous states */
X_OpenLoop_T OpenLoop_X;

/* Block states (default storage) */
DW_OpenLoop_T OpenLoop_DW;

/* Real-time model */
static RT_MODEL_OpenLoop_T OpenLoop_M_;
RT_MODEL_OpenLoop_T *const OpenLoop_M = &OpenLoop_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  OpenLoop_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void OpenLoop_step(void)
{
  real_T sampleTime;
  real_T sampleTime_0;
  int16_T rtb_MATLABSystem_0;
  if (rtmIsMajorTimeStep(OpenLoop_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&OpenLoop_M->solverInfo,
                          ((OpenLoop_M->Timing.clockTick0+1)*
      OpenLoop_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(OpenLoop_M)) {
    OpenLoop_M->Timing.t[0] = rtsiGetT(&OpenLoop_M->solverInfo);
  }

  /* Gain: '<Root>/Gain17' incorporates:
   *  Integrator: '<Root>/Integrator8'
   */
  OpenLoop_B.Gain17 = (OpenLoop_P.Gain17_Gain[0] *
                       OpenLoop_X.Integrator8_CSTATE[0] +
                       OpenLoop_P.Gain17_Gain[1] *
                       OpenLoop_X.Integrator8_CSTATE[1]) +
    OpenLoop_P.Gain17_Gain[2] * OpenLoop_X.Integrator8_CSTATE[2];

  /* FromWorkspace: '<S2>/FromWs' */
  {
    real_T *pDataValues = (real_T *) OpenLoop_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) OpenLoop_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = OpenLoop_DW.FromWs_IWORK.PrevIndex;
    real_T t = OpenLoop_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[5]) {
      currTimeIndex = 4;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    OpenLoop_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          OpenLoop_B.FromWs = pDataValues[currTimeIndex];
        } else {
          OpenLoop_B.FromWs = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        OpenLoop_B.FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 6;
      }
    }
  }

  if (rtmIsMajorTimeStep(OpenLoop_M)) {
  }

  /* Sum: '<Root>/Sum8' incorporates:
   *  Gain: '<Root>/Gain11'
   *  Gain: '<Root>/Gain12'
   *  Integrator: '<Root>/Integrator6'
   */
  OpenLoop_B.Sum8 = (0.0 - OpenLoop_P.k2 * OpenLoop_B.Gain17) - OpenLoop_P.k1 *
    OpenLoop_X.Integrator6_CSTATE;

  /* Saturate: '<Root>/Saturation1' */
  if (OpenLoop_B.Sum8 > OpenLoop_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    OpenLoop_B.Saturation1 = OpenLoop_P.Saturation1_UpperSat;
  } else if (OpenLoop_B.Sum8 < OpenLoop_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    OpenLoop_B.Saturation1 = OpenLoop_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    OpenLoop_B.Saturation1 = OpenLoop_B.Sum8;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(OpenLoop_M)) {
    /* MATLABSystem: '<S7>/MATLAB System' */
    if (OpenLoop_DW.obj.SampleTime != OpenLoop_P.MATLABSystem_SampleTime) {
      if (((!rtIsInf(OpenLoop_P.MATLABSystem_SampleTime)) && (!rtIsNaN
            (OpenLoop_P.MATLABSystem_SampleTime))) || rtIsInf
          (OpenLoop_P.MATLABSystem_SampleTime)) {
        sampleTime = OpenLoop_P.MATLABSystem_SampleTime;
      }

      OpenLoop_DW.obj.SampleTime = sampleTime;
    }

    /*         %% Define output properties */
    /*  Call C-function implementing device output */
    rtb_MATLABSystem_0 = EncPortRead1();

    /* Gain: '<S7>/Gain' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     *  MATLABSystem: '<S7>/MATLAB System'
     */
    OpenLoop_B.Gain = OpenLoop_P.Gain_Gain_e * (real32_T)rtb_MATLABSystem_0;
  }

  /* Gain: '<Root>/Gain14' incorporates:
   *  Integrator: '<Root>/Integrator8'
   */
  OpenLoop_B.Gain14 = (OpenLoop_P.Cobis[0] * OpenLoop_X.Integrator8_CSTATE[0] +
                       OpenLoop_P.Cobis[1] * OpenLoop_X.Integrator8_CSTATE[1]) +
    OpenLoop_P.Cobis[2] * OpenLoop_X.Integrator8_CSTATE[2];
  if (rtmIsMajorTimeStep(OpenLoop_M)) {
  }

  /* Sum: '<Root>/Sum11' */
  sampleTime = OpenLoop_B.Gain - OpenLoop_B.Gain14;
  if (rtmIsMajorTimeStep(OpenLoop_M)) {
    /* MATLABSystem: '<S7>/MATLAB System1' */
    if (OpenLoop_DW.obj_f.SampleTime != OpenLoop_P.MATLABSystem1_SampleTime) {
      if (((!rtIsInf(OpenLoop_P.MATLABSystem1_SampleTime)) && (!rtIsNaN
            (OpenLoop_P.MATLABSystem1_SampleTime))) || rtIsInf
          (OpenLoop_P.MATLABSystem1_SampleTime)) {
        sampleTime_0 = OpenLoop_P.MATLABSystem1_SampleTime;
      }

      OpenLoop_DW.obj_f.SampleTime = sampleTime_0;
    }

    /*         %% Define output properties */
    /*  Call C-function implementing device output */
    EncPeriodRead1();

    /* End of MATLABSystem: '<S7>/MATLAB System1' */
  }

  /* Gain: '<S5>/Gain' */
  /*         %% Define input properties */
  /*  Call C-function implementing device output */
  sampleTime_0 = 255.0 / OpenLoop_P.Motor1_Vmax * OpenLoop_B.Saturation1;

  /* Saturate: '<S5>/Saturation' */
  if (sampleTime_0 > OpenLoop_P.Saturation_UpperSat) {
    sampleTime_0 = OpenLoop_P.Saturation_UpperSat;
  } else if (sampleTime_0 < OpenLoop_P.Saturation_LowerSat) {
    sampleTime_0 = OpenLoop_P.Saturation_LowerSat;
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Saturate: '<S5>/Saturation'
   */
  sampleTime_0 = floor(sampleTime_0);
  if (rtIsNaN(sampleTime_0) || rtIsInf(sampleTime_0)) {
    sampleTime_0 = 0.0;
  } else {
    sampleTime_0 = fmod(sampleTime_0, 65536.0);
  }

  /* MATLABSystem: '<S5>/MATLAB System1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  DCMotor1Set(sampleTime_0 < 0.0 ? -(int16_T)(uint16_T)-sampleTime_0 : (int16_T)
              (uint16_T)sampleTime_0);

  /* Gain: '<S6>/Gain' incorporates:
   *  Gain: '<S1>/Gain'
   */
  /*         %% Define input properties */
  /*  Call C-function implementing device output */
  sampleTime_0 = 255.0 / OpenLoop_P.Motor2_Vmax * (OpenLoop_P.Gain_Gain *
    OpenLoop_B.Saturation1);

  /* Saturate: '<S6>/Saturation' */
  if (sampleTime_0 > OpenLoop_P.Saturation_UpperSat_l) {
    sampleTime_0 = OpenLoop_P.Saturation_UpperSat_l;
  } else if (sampleTime_0 < OpenLoop_P.Saturation_LowerSat_a) {
    sampleTime_0 = OpenLoop_P.Saturation_LowerSat_a;
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Saturate: '<S6>/Saturation'
   */
  sampleTime_0 = floor(sampleTime_0);
  if (rtIsNaN(sampleTime_0) || rtIsInf(sampleTime_0)) {
    sampleTime_0 = 0.0;
  } else {
    sampleTime_0 = fmod(sampleTime_0, 65536.0);
  }

  /* MATLABSystem: '<S6>/MATLAB System' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  DCMotor2Set(sampleTime_0 < 0.0 ? -(int16_T)(uint16_T)-sampleTime_0 : (int16_T)
              (uint16_T)sampleTime_0);

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum9'
   */
  OpenLoop_B.Sum1 = (OpenLoop_B.Saturation1 - OpenLoop_B.Sum8) * OpenLoop_P.Kb +
    (OpenLoop_B.FromWs - OpenLoop_B.Gain17);
  for (rtb_MATLABSystem_0 = 0; rtb_MATLABSystem_0 < 3; rtb_MATLABSystem_0++) {
    /* Sum: '<Root>/Sum10' incorporates:
     *  Gain: '<Root>/Gain13'
     *  Gain: '<Root>/Gain15'
     *  Gain: '<Root>/Gain16'
     *  Integrator: '<Root>/Integrator8'
     */
    OpenLoop_B.Sum10[rtb_MATLABSystem_0] = ((OpenLoop_P.Aobis[rtb_MATLABSystem_0
      + 3] * OpenLoop_X.Integrator8_CSTATE[1] +
      OpenLoop_P.Aobis[rtb_MATLABSystem_0] * OpenLoop_X.Integrator8_CSTATE[0]) +
      OpenLoop_P.Aobis[rtb_MATLABSystem_0 + 6] * OpenLoop_X.Integrator8_CSTATE[2])
      + (OpenLoop_P.Bobis[rtb_MATLABSystem_0] * OpenLoop_B.Saturation1 +
         OpenLoop_P.Lbis[rtb_MATLABSystem_0] * sampleTime);
  }

  /* StateSpace: '<S3>/Modèle chenille gauche1' */
  OpenLoop_B.Modlechenillegauche1 = OpenLoop_P.Modlechenillegauche1_C *
    OpenLoop_X.Modlechenillegauche1_CSTATE;
  if (rtmIsMajorTimeStep(OpenLoop_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((OpenLoop_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(OpenLoop_M)) {/* Sample time: [0.002s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((OpenLoop_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(OpenLoop_M)) {
    rt_ertODEUpdateContinuousStates(&OpenLoop_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++OpenLoop_M->Timing.clockTick0;
    OpenLoop_M->Timing.t[0] = rtsiGetSolverStopTime(&OpenLoop_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      OpenLoop_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void OpenLoop_derivatives(void)
{
  XDot_OpenLoop_T *_rtXdot;
  _rtXdot = ((XDot_OpenLoop_T *) OpenLoop_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator8' */
  _rtXdot->Integrator8_CSTATE[0] = OpenLoop_B.Sum10[0];
  _rtXdot->Integrator8_CSTATE[1] = OpenLoop_B.Sum10[1];
  _rtXdot->Integrator8_CSTATE[2] = OpenLoop_B.Sum10[2];

  /* Derivatives for Integrator: '<Root>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = OpenLoop_B.Sum1;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = OpenLoop_B.Modlechenillegauche1;

  /* Derivatives for StateSpace: '<S3>/Modèle chenille gauche1' */
  _rtXdot->Modlechenillegauche1_CSTATE = OpenLoop_P.a *
    OpenLoop_X.Modlechenillegauche1_CSTATE;
  _rtXdot->Modlechenillegauche1_CSTATE += OpenLoop_P.b * 0.0;
}

/* Model initialize function */
void OpenLoop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)OpenLoop_M, 0,
                sizeof(RT_MODEL_OpenLoop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&OpenLoop_M->solverInfo,
                          &OpenLoop_M->Timing.simTimeStep);
    rtsiSetTPtr(&OpenLoop_M->solverInfo, &rtmGetTPtr(OpenLoop_M));
    rtsiSetStepSizePtr(&OpenLoop_M->solverInfo, &OpenLoop_M->Timing.stepSize0);
    rtsiSetdXPtr(&OpenLoop_M->solverInfo, &OpenLoop_M->derivs);
    rtsiSetContStatesPtr(&OpenLoop_M->solverInfo, (real_T **)
                         &OpenLoop_M->contStates);
    rtsiSetNumContStatesPtr(&OpenLoop_M->solverInfo,
      &OpenLoop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&OpenLoop_M->solverInfo,
      &OpenLoop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&OpenLoop_M->solverInfo,
      &OpenLoop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&OpenLoop_M->solverInfo,
      &OpenLoop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&OpenLoop_M->solverInfo, (&rtmGetErrorStatus
      (OpenLoop_M)));
    rtsiSetRTModelPtr(&OpenLoop_M->solverInfo, OpenLoop_M);
  }

  rtsiSetSimTimeStep(&OpenLoop_M->solverInfo, MAJOR_TIME_STEP);
  OpenLoop_M->intgData.f[0] = OpenLoop_M->odeF[0];
  OpenLoop_M->contStates = ((X_OpenLoop_T *) &OpenLoop_X);
  rtsiSetSolverData(&OpenLoop_M->solverInfo, (void *)&OpenLoop_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&OpenLoop_M->solverInfo, false);
  rtsiSetSolverName(&OpenLoop_M->solverInfo,"ode1");
  rtmSetTPtr(OpenLoop_M, &OpenLoop_M->Timing.tArray[0]);
  rtmSetTFinal(OpenLoop_M, 10.0);
  OpenLoop_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  OpenLoop_M->Sizes.checksums[0] = (2612295620U);
  OpenLoop_M->Sizes.checksums[1] = (1720684412U);
  OpenLoop_M->Sizes.checksums[2] = (231801807U);
  OpenLoop_M->Sizes.checksums[3] = (405958311U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    OpenLoop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(OpenLoop_M->extModeInfo,
      &OpenLoop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(OpenLoop_M->extModeInfo, OpenLoop_M->Sizes.checksums);
    rteiSetTPtr(OpenLoop_M->extModeInfo, rtmGetTPtr(OpenLoop_M));
  }

  /* block I/O */
  (void) memset(((void *) &OpenLoop_B), 0,
                sizeof(B_OpenLoop_T));

  /* states (continuous) */
  {
    (void) memset((void *)&OpenLoop_X, 0,
                  sizeof(X_OpenLoop_T));
  }

  /* states (dwork) */
  (void) memset((void *)&OpenLoop_DW, 0,
                sizeof(DW_OpenLoop_T));

  {
    real_T sampleTime;
    real_T sampleTime_0;

    /* Start for FromWorkspace: '<S2>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 4.0, 4.0, 5.0, 5.0, 10.0 } ;

      static real_T pDataValues0[] = { 250.0, 250.0, 700.0, 700.0, 250.0, 250.0
      } ;

      OpenLoop_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      OpenLoop_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      OpenLoop_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* InitializeConditions for Integrator: '<Root>/Integrator8' */
    OpenLoop_X.Integrator8_CSTATE[0] = OpenLoop_P.Integrator8_IC;
    OpenLoop_X.Integrator8_CSTATE[1] = OpenLoop_P.Integrator8_IC;
    OpenLoop_X.Integrator8_CSTATE[2] = OpenLoop_P.Integrator8_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator6' */
    OpenLoop_X.Integrator6_CSTATE = OpenLoop_P.Integrator6_IC;

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    OpenLoop_X.Integrator_CSTATE = OpenLoop_P.Integrator_IC;

    /* InitializeConditions for StateSpace: '<S3>/Modèle chenille gauche1' */
    OpenLoop_X.Modlechenillegauche1_CSTATE =
      OpenLoop_P.Modlechenillegauche1_InitialCon;

    /* Start for MATLABSystem: '<S7>/MATLAB System' */
    OpenLoop_DW.obj.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(OpenLoop_P.MATLABSystem_SampleTime)) && (!rtIsNaN
          (OpenLoop_P.MATLABSystem_SampleTime))) || rtIsInf
        (OpenLoop_P.MATLABSystem_SampleTime)) {
      sampleTime = OpenLoop_P.MATLABSystem_SampleTime;
    }

    OpenLoop_DW.obj.SampleTime = sampleTime;
    OpenLoop_DW.obj.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call C-function implementing device initialization */
    EncPort1Setup();
    OpenLoop_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/MATLAB System' */

    /* Start for MATLABSystem: '<S7>/MATLAB System1' */
    OpenLoop_DW.obj_f.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(OpenLoop_P.MATLABSystem1_SampleTime)) && (!rtIsNaN
          (OpenLoop_P.MATLABSystem1_SampleTime))) || rtIsInf
        (OpenLoop_P.MATLABSystem1_SampleTime)) {
      sampleTime_0 = OpenLoop_P.MATLABSystem1_SampleTime;
    }

    OpenLoop_DW.obj_f.SampleTime = sampleTime_0;
    OpenLoop_DW.obj_f.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call C-function implementing device initialization */
    EncPort1Setup();
    OpenLoop_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/MATLAB System1' */

    /* Start for MATLABSystem: '<S5>/MATLAB System1' */
    OpenLoop_DW.obj_d.matlabCodegenIsDeleted = false;
    OpenLoop_DW.obj_d.isInitialized = 1L;

    /*         %% Define input properties */
    /*  Call C-function implementing device initialization */
    DCMotor1Setup();
    OpenLoop_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/MATLAB System' */
    OpenLoop_DW.obj_k.matlabCodegenIsDeleted = false;
    OpenLoop_DW.obj_k.isInitialized = 1L;

    /*         %% Define input properties */
    /*  Call C-function implementing device initialization */
    DCMotor2Setup();
    OpenLoop_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void OpenLoop_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/MATLAB System' */
  if (!OpenLoop_DW.obj.matlabCodegenIsDeleted) {
    OpenLoop_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/MATLAB System' */
  /* Terminate for MATLABSystem: '<S7>/MATLAB System1' */
  if (!OpenLoop_DW.obj_f.matlabCodegenIsDeleted) {
    OpenLoop_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/MATLAB System1' */

  /* Terminate for MATLABSystem: '<S5>/MATLAB System1' */
  if (!OpenLoop_DW.obj_d.matlabCodegenIsDeleted) {
    OpenLoop_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((OpenLoop_DW.obj_d.isInitialized == 1L) &&
        OpenLoop_DW.obj_d.isSetupComplete) {
      /*  Call C-function implementing device termination */
      /* coder.ceval('sink_terminate'); */
      DCMotor1Set(0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/MATLAB System1' */

  /* Terminate for MATLABSystem: '<S6>/MATLAB System' */
  if (!OpenLoop_DW.obj_k.matlabCodegenIsDeleted) {
    OpenLoop_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((OpenLoop_DW.obj_k.isInitialized == 1L) &&
        OpenLoop_DW.obj_k.isSetupComplete) {
      /*  Call C-function implementing device termination */
      DCMotor2Set(0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

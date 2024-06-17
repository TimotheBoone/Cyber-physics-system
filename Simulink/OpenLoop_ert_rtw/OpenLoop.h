/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OpenLoop.h
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

#ifndef RTW_HEADER_OpenLoop_h_
#define RTW_HEADER_OpenLoop_h_
#ifndef OpenLoop_COMMON_INCLUDES_
#define OpenLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MegapiDCMotors.h"
#endif                                 /* OpenLoop_COMMON_INCLUDES_ */

#include "OpenLoop_types.h"
#include <math.h>
#include "rtGetInf.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain17;                       /* '<Root>/Gain17' */
  real_T FromWs;                       /* '<S2>/FromWs' */
  real_T Sum8;                         /* '<Root>/Sum8' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Gain14;                       /* '<Root>/Gain14' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Sum10[3];                     /* '<Root>/Sum10' */
  real_T Modlechenillegauche1;         /* '<S3>/Modèle chenille gauche1' */
  real32_T Gain;                       /* '<S7>/Gain' */
} B_OpenLoop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Enc1Read_OpenLoop_T obj;             /* '<S7>/MATLAB System' */
  Enc1Period_OpenLoop_T obj_f;         /* '<S7>/MATLAB System1' */
  DCMotor1Set_OpenLoop_T obj_d;        /* '<S5>/MATLAB System1' */
  DCMotor2Set_OpenLoop_T obj_k;        /* '<S6>/MATLAB System' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S2>/FromWs' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S2>/FromWs' */
} DW_OpenLoop_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator8_CSTATE[3];        /* '<Root>/Integrator8' */
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Modlechenillegauche1_CSTATE;  /* '<S3>/Modèle chenille gauche1' */
} X_OpenLoop_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator8_CSTATE[3];        /* '<Root>/Integrator8' */
  real_T Integrator6_CSTATE;           /* '<Root>/Integrator6' */
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Modlechenillegauche1_CSTATE;  /* '<S3>/Modèle chenille gauche1' */
} XDot_OpenLoop_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator8_CSTATE[3];     /* '<Root>/Integrator8' */
  boolean_T Integrator6_CSTATE;        /* '<Root>/Integrator6' */
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
  boolean_T Modlechenillegauche1_CSTATE;/* '<S3>/Modèle chenille gauche1' */
} XDis_OpenLoop_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_OpenLoop_T_ {
  real_T Aobis[9];                     /* Variable: Aobis
                                        * Referenced by: '<Root>/Gain15'
                                        */
  real_T Bobis[3];                     /* Variable: Bobis
                                        * Referenced by: '<Root>/Gain13'
                                        */
  real_T Cobis[3];                     /* Variable: Cobis
                                        * Referenced by: '<Root>/Gain14'
                                        */
  real_T Kb;                           /* Variable: Kb
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Lbis[3];                      /* Variable: Lbis
                                        * Referenced by: '<Root>/Gain16'
                                        */
  real_T a;                            /* Variable: a
                                        * Referenced by: '<S3>/Modèle chenille gauche1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<S3>/Modèle chenille gauche1'
                                        */
  real_T k1;                           /* Variable: k1
                                        * Referenced by: '<Root>/Gain12'
                                        */
  real_T k2;                           /* Variable: k2
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T Motor1_Vmax;                  /* Mask Parameter: Motor1_Vmax
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Motor2_Vmax;                  /* Mask Parameter: Motor2_Vmax
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.002
                                        * Referenced by: '<S7>/MATLAB System'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: 0.002
                                        * Referenced by: '<S7>/MATLAB System1'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator8'
                                        */
  real_T Gain17_Gain[3];               /* Expression: [1 0 0]
                                        * Referenced by: '<Root>/Gain17'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator6'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 9
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -9
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -255
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 255
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -255
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Modlechenillegauche1_C;       /* Expression: 1
                                        * Referenced by: '<S3>/Modèle chenille gauche1'
                                        */
  real_T Modlechenillegauche1_InitialCon;/* Expression: 0
                                          * Referenced by: '<S3>/Modèle chenille gauche1'
                                          */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S7>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_OpenLoop_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_OpenLoop_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_OpenLoop_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][6];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_OpenLoop_T OpenLoop_P;

/* Block signals (default storage) */
extern B_OpenLoop_T OpenLoop_B;

/* Continuous states (default storage) */
extern X_OpenLoop_T OpenLoop_X;

/* Block states (default storage) */
extern DW_OpenLoop_T OpenLoop_DW;

/* Model entry point functions */
extern void OpenLoop_initialize(void);
extern void OpenLoop_step(void);
extern void OpenLoop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_OpenLoop_T *const OpenLoop_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Diff' : Unused code path elimination
 * Block '<S4>/TSamp' : Unused code path elimination
 * Block '<S4>/UD' : Unused code path elimination
 * Block '<S7>/Data Type Conversion1' : Unused code path elimination
 * Block '<S7>/Gain1' : Unused code path elimination
 * Block '<S7>/Gain2' : Unused code path elimination
 * Block '<S7>/Math Function' : Unused code path elimination
 */

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
 * '<Root>' : 'OpenLoop'
 * '<S1>'   : 'OpenLoop/SYSTEME Réel1'
 * '<S2>'   : 'OpenLoop/Signal Builder1'
 * '<S3>'   : 'OpenLoop/Système simulé'
 * '<S4>'   : 'OpenLoop/SYSTEME Réel1/Discrete Derivative'
 * '<S5>'   : 'OpenLoop/SYSTEME Réel1/Motor1'
 * '<S6>'   : 'OpenLoop/SYSTEME Réel1/Motor2'
 * '<S7>'   : 'OpenLoop/SYSTEME Réel1/MotorEncoder'
 */
#endif                                 /* RTW_HEADER_OpenLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

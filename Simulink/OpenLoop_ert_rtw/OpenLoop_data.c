/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OpenLoop_data.c
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

/* Block parameters (default storage) */
P_OpenLoop_T OpenLoop_P = {
  /* Variable: Aobis
   * Referenced by: '<Root>/Gain15'
   */
  { -50.0, 1.0, 0.0, 0.0, 0.0, 0.0, 2500.0, 0.0, 0.0 },

  /* Variable: Bobis
   * Referenced by: '<Root>/Gain13'
   */
  { 2500.0, 0.0, 0.0 },

  /* Variable: Cobis
   * Referenced by: '<Root>/Gain14'
   */
  { 0.0, 1.0, 0.0 },

  /* Variable: Kb
   * Referenced by: '<Root>/Gain'
   */
  50.0,

  /* Variable: Lbis
   * Referenced by: '<Root>/Gain16'
   */
  { 9674.9999999998054, 189.99999999999844, 203.99999999999528 },

  /* Variable: a
   * Referenced by: '<S3>/Modèle chenille gauche1'
   */
  -50.0,

  /* Variable: b
   * Referenced by: '<S3>/Modèle chenille gauche1'
   */
  2500.0,

  /* Variable: k1
   * Referenced by: '<Root>/Gain12'
   */
  -3.000000000000004,

  /* Variable: k2
   * Referenced by: '<Root>/Gain11'
   */
  0.05999999999999947,

  /* Mask Parameter: Motor1_Vmax
   * Referenced by: '<S5>/Gain'
   */
  12.0,

  /* Mask Parameter: Motor2_Vmax
   * Referenced by: '<S6>/Gain'
   */
  12.0,

  /* Expression: 0.002
   * Referenced by: '<S7>/MATLAB System'
   */
  0.002,

  /* Expression: 0.002
   * Referenced by: '<S7>/MATLAB System1'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator8'
   */
  0.0,

  /* Expression: [1 0 0]
   * Referenced by: '<Root>/Gain17'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Integrator6'
   */
  0.0,

  /* Expression: 9
   * Referenced by: '<Root>/Saturation1'
   */
  9.0,

  /* Expression: -9
   * Referenced by: '<Root>/Saturation1'
   */
  -9.0,

  /* Expression: 255
   * Referenced by: '<S5>/Saturation'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<S5>/Saturation'
   */
  -255.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<S6>/Saturation'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<S6>/Saturation'
   */
  -255.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Modèle chenille gauche1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Modèle chenille gauche1'
   */
  0.0,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S7>/Gain'
   */
  0.496956527F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

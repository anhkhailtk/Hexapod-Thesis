/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Hexapod_2nd_sfun.h"
#include "c2_Hexapod_2nd.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hexapod_2nd_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[7] = { "motor_pos", "k", "i", "nargin",
  "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);
static void initialize_params_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);
static void enable_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct *chartInstance);
static void disable_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Hexapod_2nd
  (SFc2_Hexapod_2ndInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Hexapod_2nd
  (SFc2_Hexapod_2ndInstanceStruct *chartInstance);
static void set_sim_state_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);
static void sf_gateway_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);
static void mdl_start_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);
static void initSimStructsc2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct *chartInstance,
  const mxArray *c2_b_y, const char_T *c2_identifier, real_T c2_c_y[6]);
static void c2_b_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[6]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Hexapod_2nd, const char_T
  *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_Hexapod_2ndInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_Hexapod_2nd(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_Hexapod_2nd = 0U;
}

static void initialize_params_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_Hexapod_2nd
  (SFc2_Hexapod_2ndInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_Hexapod_2nd
  (SFc2_Hexapod_2ndInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(2, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_y, 0, 0U, 1U, 0U,
    1, 6), false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Hexapod_2nd;
  c2_b_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  real_T c2_dv0[6];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("y", c2_b_u, 0)),
                      "y", c2_dv0);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    (*chartInstance->c2_y)[c2_i0] = c2_dv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_Hexapod_2nd = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_Hexapod_2nd", c2_b_u,
       1)), "is_active_c2_Hexapod_2nd");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_Hexapod_2nd(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  uint8_T c2_b_u[37];
  uint32_T c2_debug_family_var_map[7];
  real_T c2_motor_pos[6];
  real_T c2_k;
  real_T c2_i;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_y[6];
  int32_T c2_i3;
  int32_T c2_b_i;
  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u0;
  uint8_T c2_a;
  uint32_T c2_u1;
  uint8_T c2_c_y;
  uint32_T c2_b_q0;
  uint32_T c2_b_qY;
  uint32_T c2_u2;
  uint8_T c2_b_a;
  uint32_T c2_u3;
  uint8_T c2_d_y;
  uint32_T c2_c_q0;
  uint32_T c2_c_qY;
  uint32_T c2_u4;
  uint8_T c2_c_a;
  uint8_T c2_e_y;
  uint32_T c2_d_q0;
  uint32_T c2_d_qY;
  uint32_T c2_u5;
  uint8_T c2_d_a;
  real_T c2_d0;
  uint8_T c2_u6;
  uint8_T c2_f_y;
  uint32_T c2_e_q0;
  uint32_T c2_e_qY;
  uint32_T c2_u7;
  uint8_T c2_e_a;
  real_T c2_d1;
  uint8_T c2_u8;
  uint8_T c2_g_y;
  uint32_T c2_f_q0;
  uint32_T c2_f_qY;
  uint32_T c2_u9;
  uint8_T c2_f_a;
  real_T c2_d2;
  uint8_T c2_u10;
  uint8_T c2_h_y;
  uint32_T c2_u11;
  uint32_T c2_u12;
  uint32_T c2_u13;
  uint32_T c2_u14;
  uint32_T c2_u15;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 37; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_u)[c2_i1], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 37; c2_i2++) {
    c2_b_u[c2_i2] = (*chartInstance->c2_u)[c2_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_motor_pos, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u, 5U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_y, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i3 = 0; c2_i3 < 6; c2_i3++) {
    c2_motor_pos[c2_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)c2_b_u[0], 109.0,
        0, 0U, c2_b_u[0] == 109))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
    c2_k = 2.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
    c2_i = 1.0;
    c2_b_i = 0;
    while (c2_b_i < 6) {
      c2_i = 1.0 + (real_T)c2_b_i;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
      c2_q0 = c2_b_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)
        _SFD_INTEGER_CHECK("k", c2_k), 1, 37, 1, 0) - 1];
      c2_qY = c2_q0 - 48U;
      if (CV_SATURATION_EVAL(4, 0, 6, 0, c2_qY > c2_q0)) {
        c2_qY = 0U;
      }

      c2_u0 = c2_qY;
      if (CV_SATURATION_EVAL(4, 0, 6, 0, c2_u0 > 255U)) {
        c2_u0 = 255U;
      }

      c2_a = (uint8_T)c2_u0;
      c2_u1 = (uint32_T)c2_a * 100U;
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_u1 > 255U)) {
        c2_u1 = 255U;
      }

      c2_c_y = (uint8_T)c2_u1;
      c2_b_q0 = c2_b_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)
        _SFD_INTEGER_CHECK("k + 1", c2_k + 1.0), 1, 37, 1, 0) - 1];
      c2_b_qY = c2_b_q0 - 48U;
      if (CV_SATURATION_EVAL(4, 0, 8, 0, c2_b_qY > c2_b_q0)) {
        c2_b_qY = 0U;
      }

      c2_u2 = c2_b_qY;
      if (CV_SATURATION_EVAL(4, 0, 8, 0, c2_u2 > 255U)) {
        c2_u2 = 255U;
      }

      c2_b_a = (uint8_T)c2_u2;
      c2_u3 = (uint32_T)c2_b_a * 10U;
      if (CV_SATURATION_EVAL(4, 0, 7, 0, c2_u3 > 255U)) {
        c2_u3 = 255U;
      }

      c2_d_y = (uint8_T)c2_u3;
      c2_c_q0 = c2_b_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)
        _SFD_INTEGER_CHECK("k + 2", c2_k + 2.0), 1, 37, 1, 0) - 1];
      c2_c_qY = c2_c_q0 - 48U;
      if (CV_SATURATION_EVAL(4, 0, 9, 0, c2_c_qY > c2_c_q0)) {
        c2_c_qY = 0U;
      }

      c2_u4 = c2_c_qY;
      if (CV_SATURATION_EVAL(4, 0, 9, 0, c2_u4 > 255U)) {
        c2_u4 = 255U;
      }

      c2_c_a = (uint8_T)c2_u4;
      c2_e_y = c2_c_a;
      c2_d_q0 = c2_b_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)
        _SFD_INTEGER_CHECK("k + 3", c2_k + 3.0), 1, 37, 1, 0) - 1];
      c2_d_qY = c2_d_q0 - 48U;
      if (CV_SATURATION_EVAL(4, 0, 11, 0, c2_d_qY > c2_d_q0)) {
        c2_d_qY = 0U;
      }

      c2_u5 = c2_d_qY;
      if (CV_SATURATION_EVAL(4, 0, 11, 0, c2_u5 > 255U)) {
        c2_u5 = 255U;
      }

      c2_d_a = (uint8_T)c2_u5;
      c2_d0 = muDoubleScalarRound((real_T)c2_d_a * 0.1);
      if (c2_d0 < 256.0) {
        if (CV_SATURATION_EVAL(4, 0, 10, 1, c2_d0 >= 0.0)) {
          c2_u6 = (uint8_T)c2_d0;
        } else {
          c2_u6 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 0, 10, 0, c2_d0 >= 256.0)) {
        c2_u6 = MAX_uint8_T;
      } else {
        c2_u6 = 0U;
      }

      c2_f_y = c2_u6;
      c2_e_q0 = c2_b_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)
        _SFD_INTEGER_CHECK("k + 4", c2_k + 4.0), 1, 37, 1, 0) - 1];
      c2_e_qY = c2_e_q0 - 48U;
      if (CV_SATURATION_EVAL(4, 0, 13, 0, c2_e_qY > c2_e_q0)) {
        c2_e_qY = 0U;
      }

      c2_u7 = c2_e_qY;
      if (CV_SATURATION_EVAL(4, 0, 13, 0, c2_u7 > 255U)) {
        c2_u7 = 255U;
      }

      c2_e_a = (uint8_T)c2_u7;
      c2_d1 = muDoubleScalarRound((real_T)c2_e_a * 0.01);
      if (c2_d1 < 256.0) {
        if (CV_SATURATION_EVAL(4, 0, 12, 1, c2_d1 >= 0.0)) {
          c2_u8 = (uint8_T)c2_d1;
        } else {
          c2_u8 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 0, 12, 0, c2_d1 >= 256.0)) {
        c2_u8 = MAX_uint8_T;
      } else {
        c2_u8 = 0U;
      }

      c2_g_y = c2_u8;
      c2_f_q0 = c2_b_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)
        _SFD_INTEGER_CHECK("k + 5", c2_k + 5.0), 1, 37, 1, 0) - 1];
      c2_f_qY = c2_f_q0 - 48U;
      if (CV_SATURATION_EVAL(4, 0, 15, 0, c2_f_qY > c2_f_q0)) {
        c2_f_qY = 0U;
      }

      c2_u9 = c2_f_qY;
      if (CV_SATURATION_EVAL(4, 0, 15, 0, c2_u9 > 255U)) {
        c2_u9 = 255U;
      }

      c2_f_a = (uint8_T)c2_u9;
      c2_d2 = muDoubleScalarRound((real_T)c2_f_a * 0.001);
      if (c2_d2 < 256.0) {
        if (CV_SATURATION_EVAL(4, 0, 14, 1, c2_d2 >= 0.0)) {
          c2_u10 = (uint8_T)c2_d2;
        } else {
          c2_u10 = 0U;
        }
      } else if (CV_SATURATION_EVAL(4, 0, 14, 0, c2_d2 >= 256.0)) {
        c2_u10 = MAX_uint8_T;
      } else {
        c2_u10 = 0U;
      }

      c2_h_y = c2_u10;
      c2_u11 = (uint32_T)c2_c_y + (uint32_T)c2_d_y;
      if (CV_SATURATION_EVAL(4, 0, 1, 0, c2_u11 > 255U)) {
        c2_u11 = 255U;
      }

      c2_u12 = (uint32_T)(uint8_T)c2_u11 + (uint32_T)c2_e_y;
      if (CV_SATURATION_EVAL(4, 0, 2, 0, c2_u12 > 255U)) {
        c2_u12 = 255U;
      }

      c2_u13 = (uint32_T)(uint8_T)c2_u12 + (uint32_T)c2_f_y;
      if (CV_SATURATION_EVAL(4, 0, 3, 0, c2_u13 > 255U)) {
        c2_u13 = 255U;
      }

      c2_u14 = (uint32_T)(uint8_T)c2_u13 + (uint32_T)c2_g_y;
      if (CV_SATURATION_EVAL(4, 0, 4, 0, c2_u14 > 255U)) {
        c2_u14 = 255U;
      }

      c2_u15 = (uint32_T)(uint8_T)c2_u14 + (uint32_T)c2_h_y;
      if (CV_SATURATION_EVAL(4, 0, 5, 0, c2_u15 > 255U)) {
        c2_u15 = 255U;
      }

      c2_motor_pos[_SFD_EML_ARRAY_BOUNDS_CHECK("motor_pos", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_i), 1, 6, 1, 0) - 1] = (real_T)(uint8_T)
        c2_u15;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
      c2_k += 6.0;
      c2_b_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0, 0);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    c2_b_y[c2_i4] = c2_motor_pos[c2_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    (*chartInstance->c2_y)[c2_i5] = c2_b_y[c2_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Hexapod_2ndMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_y)[c2_i6], 1U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void mdl_start_c2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_Hexapod_2nd(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i7;
  real_T c2_b_u[6];
  const mxArray *c2_b_y = NULL;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    c2_b_u[c2_i7] = (*(real_T (*)[6])c2_inData)[c2_i7];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct *chartInstance,
  const mxArray *c2_b_y, const char_T *c2_identifier, real_T c2_c_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
}

static void c2_b_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_b_y[6])
{
  real_T c2_dv1[6];
  int32_T c2_i8;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i8 = 0; c2_i8 < 6; c2_i8++) {
    c2_b_y[c2_i8] = c2_dv1[c2_i8];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_c_y[6];
  int32_T c2_i9;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_b_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
  for (c2_i9 = 0; c2_i9 < 6; c2_i9++) {
    (*(real_T (*)[6])c2_outData)[c2_i9] = c2_c_y[c2_i9];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  uint8_T c2_b_u[37];
  const mxArray *c2_b_y = NULL;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i10 = 0; c2_i10 < 37; c2_i10++) {
    c2_b_u[c2_i10] = (*(uint8_T (*)[37])c2_inData)[c2_i10];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 3, 0U, 1U, 0U, 2, 37, 1),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d3;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout),
    &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Hexapod_2nd_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_b_y;
  int32_T c2_i11;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i11, 1, 6, 0U, 0, 0U, 0);
  c2_b_y = c2_i11;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_b_y;
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Hexapod_2nd, const char_T
  *c2_identifier)
{
  uint8_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Hexapod_2nd), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Hexapod_2nd);
  return c2_b_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_y;
  uint8_T c2_u16;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u16, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u16;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void init_dsm_address_info(SFc2_Hexapod_2ndInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_Hexapod_2ndInstanceStruct
  *chartInstance)
{
  chartInstance->c2_u = (uint8_T (*)[37])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_y = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_Hexapod_2nd_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2426770163U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(837465014U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1317619860U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3163144557U);
}

mxArray* sf_c2_Hexapod_2nd_get_post_codegen_info(void);
mxArray *sf_c2_Hexapod_2nd_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("cdYM7LcD8C9ey10X5FU5lG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(37);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_Hexapod_2nd_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_Hexapod_2nd_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_Hexapod_2nd_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_Hexapod_2nd_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_Hexapod_2nd_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_Hexapod_2nd(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_Hexapod_2nd\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Hexapod_2nd_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Hexapod_2ndInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_Hexapod_2ndInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Hexapod_2ndMachineNumber_,
           2,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Hexapod_2ndMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Hexapod_2ndMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Hexapod_2ndMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,16,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,337);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,140,-1,157);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,140,-1,180);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,140,-1,202);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,140,-1,226);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,140,-1,251);
        _SFD_CV_INIT_EML_SATURATION(0,1,5,140,-1,277);
        _SFD_CV_INIT_EML_SATURATION(0,1,6,141,-1,150);
        _SFD_CV_INIT_EML_SATURATION(0,1,7,160,-1,180);
        _SFD_CV_INIT_EML_SATURATION(0,1,8,161,-1,174);
        _SFD_CV_INIT_EML_SATURATION(0,1,9,184,-1,197);
        _SFD_CV_INIT_EML_SATURATION(0,1,10,205,-1,226);
        _SFD_CV_INIT_EML_SATURATION(0,1,11,206,-1,219);
        _SFD_CV_INIT_EML_SATURATION(0,1,12,229,-1,251);
        _SFD_CV_INIT_EML_SATURATION(0,1,13,230,-1,243);
        _SFD_CV_INIT_EML_SATURATION(0,1,14,254,-1,277);
        _SFD_CV_INIT_EML_SATURATION(0,1,15,255,-1,268);
        _SFD_CV_INIT_EML_IF(0,1,0,62,77,-1,322);
        _SFD_CV_INIT_EML_FOR(0,1,0,101,113,314);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,65,76,0,0);

        {
          unsigned int dimVector[2];
          dimVector[0]= 37;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Hexapod_2ndMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Hexapod_2ndInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_Hexapod_2ndInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c2_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVV17itMEearXAxD0srQckC";
}

static void sf_opaque_initialize_c2_Hexapod_2nd(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Hexapod_2nd(void *chartInstanceVar)
{
  enable_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Hexapod_2nd(void *chartInstanceVar)
{
  disable_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Hexapod_2nd(void *chartInstanceVar)
{
  sf_gateway_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_Hexapod_2nd(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_Hexapod_2nd(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_Hexapod_2nd(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Hexapod_2nd_optimization_info();
    }

    finalize_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Hexapod_2nd(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c2_Hexapod_2nd((SFc2_Hexapod_2ndInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Hexapod_2nd(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hexapod_2nd_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2835061787U));
  ssSetChecksum1(S,(1075432031U));
  ssSetChecksum2(S,(2348349328U));
  ssSetChecksum3(S,(2806773856U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Hexapod_2nd(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Hexapod_2nd(SimStruct *S)
{
  SFc2_Hexapod_2ndInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_Hexapod_2ndInstanceStruct *)utMalloc(sizeof
    (SFc2_Hexapod_2ndInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Hexapod_2ndInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Hexapod_2nd;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_Hexapod_2nd;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_Hexapod_2nd;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Hexapod_2nd;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Hexapod_2nd;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_Hexapod_2nd;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_Hexapod_2nd;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Hexapod_2nd;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Hexapod_2nd;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Hexapod_2nd;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Hexapod_2nd;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->isEnhancedMooreMachine = 0;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->fCheckOverflow = sf_runtime_overflow_check_is_on(S);
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
}

void c2_Hexapod_2nd_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Hexapod_2nd(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Hexapod_2nd(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Hexapod_2nd(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Hexapod_2nd_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

#pragma once

/**
 * DIY_Prusa_Mini_Configuration.h
 *
 * This file includes basic settings like:
 *
 * - Getting Started with DIY Prusa Mini Firmware
 * - Custom Printer Name
 * - Printer/Frame Type
 * - Motherboard
 * - Stepper Motors
 * - Extruder
 * - Input Shaping
 * - Probe & Bed Leveling
 * - Fans
 * - Thermal & PID Settings
 * - LCD / TFT / Controller
 * - Custom Menus
 */
#define CONFIGURATION_H_VERSION 02010300
#define DIY_PRUSA_MINI_VERSION 20241019

//===========================================================================
//============== Getting Started with DIY Prusa Mini Firmware ===============
//===========================================================================

/**
 * If you find this project helpful, please consider donating:
 *
 * Keith Bennett, Marlin tester/config builder:  https://github.com/sponsors/thisiskeithb
 *                                               https://ko-fi.com/thisiskeithb
 * Thank you and Happy Printing!
 */

//===========================================================================
//=========================== Custom Printer Name ===========================
//===========================================================================

// Uncomment to set a custom printer name.
//#define DIY_PRUSA_MINI_CUSTOM_PRINTER_NAME "Mini"

//===========================================================================
//=============================== Motherboard ===============================
//===========================================================================

/**
 * Motherboard Options
 *
 *  BigTreeTech
 *
 *    - SKR Mini E3 V3      (STM32G0B0RE/STM32G0B1RE)
 *    - SKR Mini E3 V3.0.1  (STM32F401RC)
 *    - SKR Mini E3 V2      (STM32F103RC/RE)
 */
#define DIY_PRUSA_MINI_MOTHERBOARD_BTT_SKR_MINI_E3_V3_0
//#define DIY_PRUSA_MINI_MOTHERBOARD_BTT_SKR_MINI_E3_V3_0_1
//#define DIY_PRUSA_MINI_MOTHERBOARD_BTT_SKR_MINI_E3_V2_0

//===========================================================================
//============================= Stepper Motors ==============================
//===========================================================================

/**
 * X/Y Stepper Motors
 *
 *   - LDO COOLER LDO-42STH40-1004ASR 1.8°:  https://www.printedsolid.com/products/ldo-nema-17-motor-cooler-ldo-42sth40-1004asr
 */
#define DIY_PRUSA_MINI_XY_STEPPERS_LDO_1_8

/**
 * Z Stepper Motor
 *
 *   - LDO LDO-42STH34-1004L321EC 1.8° with integrated leadscrew:  https://www.printedsolid.com/products/ldo-nema-17-motor-mk3-z-motor-qlink-ldo-42sth34-1004l321ec
 */
#define DIY_PRUSA_MINI_Z_STEPPER_LDO_1_8

/**
 * Extruder Stepper Motor
 *
 *   - LDO COOLER LDO-42STH40-1004ASR 1.8°:  https://www.printedsolid.com/products/ldo-nema-17-motor-cooler-ldo-42sth40-1004asr
 */
#define DIY_PRUSA_MINI_E_STEPPER_LDO_1_8

// Invert the stepper direction. Enable if an axis goes the wrong way.
//#define DIY_PRUSA_MINI_INVERT_X_DIR
//#define DIY_PRUSA_MINI_INVERT_Y_DIR
//#define DIY_PRUSA_MINI_INVERT_Z_DIR
//#define DIY_PRUSA_MINI_INVERT_E_DIR

/**
 * Sensorless Homing
 *
 *  Sensitivity   TMC2209
 *    HIGHEST       255      (Too sensitive => False positive)
 *    LOWEST         0       (Too insensitive => No trigger)
 *
 * If needed, uncomment DIY_PRUSA_MINI_*_STALL sensorless (StallGuard) settings below.
 * Settings can also be customized via LCD under Configuration -> Advanced Settings -> TMC Drivers -> Sensorless Homing
 */
//#define DIY_PRUSA_MINI_X_STALL_SENSITIVITY  75
//#define DIY_PRUSA_MINI_Y_STALL_SENSITIVITY  75

// If needed, uncomment DIY_PRUSA_MINI_HOMING_FEEDRATE_MM_M to customize Homing speeds (mm/min)
//#define DIY_PRUSA_MINI_HOMING_FEEDRATE_MM_M { (50*60), (50*60), (6*60) }

//===========================================================================
//================================ Extruder =================================
//===========================================================================

/**
 * Extruder
 *
 *  - Stock Prusa Mini Extruder
 *  - Bondtech Prusa Mini IFS Extruder  https://www.bondtech.se/product/ifs-extruder-for-prusa-mini/
 */
#define DIY_PRUSA_MINI_EXTRUDER_STOCK
//#define DIY_PRUSA_MINI_EXTRUDER_BONDTECH_IFS

//===========================================================================
//============================== Input Shaping ==============================
//===========================================================================

/**
 * Input Shaping -- EXPERIMENTAL
 *
 * Zero Vibration (ZV) Input Shaping for X and/or Y movements.
 *
 * See https://github.com/MarlinFirmware/Marlin/pull/24797 for configuration & full details.
 *
 * Tune with M593 D<factor> F<frequency>:
 *
 *  D<factor>    Set the zeta/damping factor. If axes (X, Y, etc.) are not specified, set for all axes.
 *  F<frequency> Set the frequency. If axes (X, Y, etc.) are not specified, set for all axes.
 *  X<1>         Set the given parameters only for the X axis.
 *  Y<1>         Set the given parameters only for the Y axis.
 */
//#define DIY_PRUSA_MINI_INPUT_SHAPING
#if ENABLED(DIY_PRUSA_MINI_INPUT_SHAPING)
  #define DIY_PRUSA_MINI_SHAPING_FREQ_X     40  // (Hz) The default dominant resonant frequency on the X axis.
  #define DIY_PRUSA_MINI_SHAPING_FREQ_Y     40  // (Hz) The default dominant resonant frequency on the Y axis.
  #define DIY_PRUSA_MINI_SHAPING_ZETA_X  0.15f  // Damping ratio of the X axis (range: 0.0 = no damping to 1.0 = critical damping).
  #define DIY_PRUSA_MINI_SHAPING_ZETA_Y  0.15f  // Damping ratio of the Y axis (range: 0.0 = no damping to 1.0 = critical damping).
#endif

//===========================================================================
//========================== Probe & Bed Leveling ===========================
//===========================================================================

/*
 * Custom Probe Offset
 *
 * If needed, uncomment to customize probe offset. This can also be customized via LCD
 * under Configuration -> Advanced Settings -> Probe Offsets
 */
//#define DIY_PRUSA_MINI_NOZZLE_TO_PROBE_OFFSET { -29, -3, -0.4 }

/**
 * Bed Leveling Type
 *
 *   - Bilinear
 *   - Unified Bed Leveling
 */
#define DIY_PRUSA_MINI_BED_LEVELING_BILINEAR
//#define DIY_PRUSA_MINI_BED_LEVELING_UBL

//===========================================================================
//================================== Fans ===================================
//===========================================================================

/**
 * Part Cooling Fan
 *
 * 24V Options:
 *
 *   - Generic (No minimum PWM limit is applied)
 *   - 24V Delta BFB0524HH
 *   - 24V SoundOriginal
 */
#define DIY_PRUSA_MINI_PART_COOLING_FAN_GENERIC
//#define DIY_PRUSA_MINI_PART_COOLING_FAN_24V_DELTA_BFB0524HH
//#define DIY_PRUSA_MINI_PART_COOLING_FAN_24V_SOUNDORIGINAL

//===========================================================================
//========================= Thermal & PID Settings ==========================
//===========================================================================

/**
 * Standard Thermistor
 *
 *   - Stock Prusa Mini Semitec 104NT
 *   - Generic NTC 100K (Type 1)
 */
#define DIY_PRUSA_MINI_THERMISTOR_STOCK_SEMITEC_104NT
//#define DIY_PRUSA_MINI_THERMISTOR_GENERIC_100K

/**
 * Custom PID Settings
 *
 * Stock Prusa Mini hotend and bed PID settings are enabled by default.
 *
 * If needed, uncomment PDIY_PRUSA_MINI_CUSTOM_HOTEND_PID or DIY_PRUSA_MINI_CUSTOM_BED_PID to customize PID settings.
 */
//#define DIY_PRUSA_MINI_CUSTOM_HOTEND_PID
#if ENABLED(DIY_PRUSA_MINI_CUSTOM_HOTEND_PID)
  #define DIY_PRUSA_MINI_DEFAULT_Kp   7.00
  #define DIY_PRUSA_MINI_DEFAULT_Ki   0.50
  #define DIY_PRUSA_MINI_DEFAULT_Kd  45.00
  // Find your own by running "M303 E0 C8 S210" via serial to run autotune on the hotend at 210 °C for 8 cycles.
#endif

//#define DIY_PRUSA_MINI_CUSTOM_BED_PID
#if ENABLED(DIY_PRUSA_MINI_CUSTOM_BED_PID)
  #define DIY_PRUSA_MINI_DEFAULT_bedKp  120.00
  #define DIY_PRUSA_MINI_DEFAULT_bedKi    1.50
  #define DIY_PRUSA_MINI_DEFAULT_bedKd  600.00
  // Find your own by running "M303 E-1 C8 S65" via serial to run autotune on the bed at 65 °C for 8 cycles.
#endif

/**
 * Model Predictive Control for Hotend
 *
 * Stock Prusa Mini hotend with 40W heater cartridge is configured by default.
 *
 * Note: Replaces PID for the hotend
 */
//#define DIY_PRUSA_MINI_HOTEND_MPCTEMP

// If needed, uncomment DIY_PRUSA_MINI_CUSTOM_HOTEND_MPCTEMP to customize MPCTEMP settings.
// Use M306 T to autotune the model. See https://marlinfw.org/docs/gcode/M306.html for full details.
//#define DIY_PRUSA_MINI_CUSTOM_HOTEND_MPCTEMP
#if ALL(DIY_PRUSA_MINI_HOTEND_MPCTEMP, DIY_PRUSA_MINI_CUSTOM_HOTEND_MPCTEMP)
  #define DIY_PRUSA_MINI_CUSTOM_MPC_HEATER_POWER { 40.0f }                 // (W) Heat cartridge power.
  #define DIY_PRUSA_MINI_CUSTOM_MPC_BLOCK_HEAT_CAPACITY { 10.46f }         // (J/K) Heat block heat capacity. Use M306 T to autotune the model.
  #define DIY_PRUSA_MINI_CUSTOM_MPC_SENSOR_RESPONSIVENESS { 0.7801f }      // (K/s per ∆K) Rate of change of sensor temperature from heat block.
  #define DIY_PRUSA_MINI_CUSTOM_MPC_AMBIENT_XFER_COEFF { 0.0564f }         // (W/K) Heat transfer coefficients from heat block to room air with fan off.
  #define DIY_PRUSA_MINI_CUSTOM_MPC_AMBIENT_XFER_COEFF_FAN255 { 0.1264f }  // (W/K) Heat transfer coefficients from heat block to room air with fan on full.

  // Filament Heat Capacity (joules/kelvin/mm)
  // Set with M306 H<value> in your filament or start G-code.
  #define DIY_PRUSA_MINI_CUSTOM_FILAMENT_HEAT_CAPACITY_PERMM { 5.6e-3f }  //   PLA = 5.6e-3f (0.0056) J/K/mm
                                                                          //  PETG = 3.6e-3f (0.0036) J/K/mm
                                                                          //   ABS = 5.15e-3f (0.00515) J/K/mm
                                                                          // Nylon = 5.22e-3f (0.00522) J/K/mm
#endif

//===========================================================================
//========================= LCD / TFT / Controller ==========================
//===========================================================================

/**
 * LCD / TFT / Controller
 *
 *   - BigTreeTech TFT35 E3 Dual Mode TFT
 */
#define DIY_PRUSA_MINI_DISPLAY_BTT_TFT35_E3_TFT

//
// Reverse the encoder direction everywhere.
//
//#define DIY_PRUSA_MINI_REVERSE_ENCODER_DIRECTION

/**
 * LCD LANGUAGE
 *
 * Select the language to display on the LCD. These languages are available:
 *
 *   en, an, bg, ca, cz, da, de, el, el_CY, es, eu, fi, fr, gl, hr, hu, it,
 *   jp_kana, ko_KR, nl, pl, pt, pt_br, ro, ru, sk, sv, tr, uk, vi, zh_CN, zh_TW
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek (Greece)', 'el_CY':'Greek (Cyprus)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'hu':'Hungarian', 'it':'Italian', 'jp_kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'sv':'Swedish', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)' }
 */
#define DIY_PRUSA_MINI_LCD_LANGUAGE en


//===========================================================================
//============================== Custom Menus ===============================
//===========================================================================

/**
 * Sheet Profiles Menu
 *
 * Automatically adjust Z Probe Offset with M851 based on selected Sheet Profile.
 * Up to 10 are supported without changes.
 */
//#define DIY_PRUSA_MINI_SHEET_PROFILES_MENU
#if ENABLED(DIY_PRUSA_MINI_SHEET_PROFILES_MENU)
  #define DIY_PRUSA_MINI_SHEET_1_DESC      "Smooth"    // Short description of Sheet
  #define DIY_PRUSA_MINI_SHEET_1_OFFSET      -0.000    // Sheet offset. This should be a negative value.

  #define DIY_PRUSA_MINI_SHEET_2_DESC    "Textured"
  #define DIY_PRUSA_MINI_SHEET_2_OFFSET      -0.000

  //#define DIY_PRUSA_MINI_SHEET_3_DESC     "Satin"
  //#define DIY_PRUSA_MINI_SHEET_3_OFFSET    -0.000
#endif

/**
 * Calibration Menu
 *
 * Top-level menu with first layer calibration, nozzle change, automated cold pull, and more.
 */
//#define DIY_PRUSA_MINI_CALIBRATION_MENU

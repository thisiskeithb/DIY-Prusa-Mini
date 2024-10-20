//===========================================================================
//========================== DO NOT EDIT THIS FILE ==========================
//===========================================================================

/**
 * DIY_Prusa_Mini_Warnings.cpp
 * Test DIY Prusa Mini configuration values and give warnings at compile-time.
 */
#include "MarlinConfig.h"
#define DIY_PRUSA_MINI_VERSION 20241019

//
// Warnings! Located here so they will appear just once in the build output.
//

/**
 * DIY Prusa Mini Warnings / Reminders
 */
#ifndef NO_DIY_PRUSA_MINI_WARNINGS

//===========================================================================
//============================== Jumpers/Pins ===============================
//===========================================================================

#if ENABLED(USES_DIAG_JUMPERS)
  #warning "DIAG jumpers must be installed for X & Y and removed for Z & E or homing and filament runout will not work correctly."
#endif

#endif // NO_DIY_PRUSA_MINI_WARNINGS

//===========================================================================
//============================== Please Donate ==============================
//===========================================================================

#warning "If you find this project helpful, please consider donating at https://github.com/sponsors/thisiskeithb or https://ko-fi.com/thisiskeithb"

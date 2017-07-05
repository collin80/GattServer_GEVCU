// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum GATT_PRESENTATION_FORMAT
{
  GATT_PRESENT_FORMAT_BOOLEAN = 0x01,
  GATT_PRESENT_FORMAT_2BIT    = 0x02,
  GATT_PRESENT_FORMAT_4BIT    = 0x03,
  GATT_PRESENT_FORMAT_UINT8   = 0x04,
  GATT_PRESENT_FORMAT_UINT12  = 0x05,
  GATT_PRESENT_FORMAT_UINT16  = 0x06,
  GATT_PRESENT_FORMAT_UINT24  = 0x07,
  GATT_PRESENT_FORMAT_UINT32  = 0x08,
  GATT_PRESENT_FORMAT_UINT48  = 0x09,
  GATT_PRESENT_FORMAT_UINT64  = 0x0A,
  GATT_PRESENT_FORMAT_UINT128 = 0x0B,
  GATT_PRESENT_FORMAT_SINT8   = 0x0C,
  GATT_PRESENT_FORMAT_SINT12  = 0x0D,
  GATT_PRESENT_FORMAT_SINT16  = 0x0E,
  GATT_PRESENT_FORMAT_SINT24  = 0x0F,
  GATT_PRESENT_FORMAT_SINT32  = 0x10,
  GATT_PRESENT_FORMAT_SINT48  = 0x11,
  GATT_PRESENT_FORMAT_SINT64  = 0x12,
  GATT_PRESENT_FORMAT_SINT128 = 0x13,
  GATT_PRESENT_FORMAT_FLOAT32 = 0x14,
  GATT_PRESENT_FORMAT_FLOAT64 = 0x15,
  GATT_PRESENT_FORMAT_SFLOAT  = 0x16,
  GATT_PRESENT_FORMAT_FLOAT   = 0x17,
  GATT_PRESENT_FORMAT_DUINT16 = 0x18,
  GATT_PRESENT_FORMAT_UTF8S   = 0x19,
  GATT_PRESENT_FORMAT_UTF16S  = 0x1A,
  GATT_PRESENT_FORMAT_STRUCT  = 0x1B,
};

enum GATT_PRESENTATION_UNIT
{
  GATT_PRESENT_UNIT_NONE                                                   = 0x2700,
  GATT_PRESENT_UNIT_LENGTH_METRE                                           = 0x2701,
  GATT_PRESENT_UNIT_MASS_KILOGRAM                                          = 0x2702,
  GATT_PRESENT_UNIT_TIME_SECOND                                            = 0x2703,
  GATT_PRESENT_UNIT_ELECTRIC_CURRENT_AMPERE                                = 0x2704,
  GATT_PRESENT_UNIT_THERMODYNAMIC_TEMPERATURE_KELVIN                       = 0x2705,
  GATT_PRESENT_UNIT_AMOUNT_OF_SUBSTANCE_MOLE                               = 0x2706,
  GATT_PRESENT_UNIT_LUMINOUS_INTENSITY_CANDELA                             = 0x2707,
  GATT_PRESENT_UNIT_AREA_SQUARE_METRES                                     = 0x2710,
  GATT_PRESENT_UNIT_VOLUME_CUBIC_METRES                                    = 0x2711,
  GATT_PRESENT_UNIT_VELOCITY_METRES_PER_SECOND                             = 0x2712,
  GATT_PRESENT_UNIT_ACCELERATION_METRES_PER_SECOND_SQUARED                 = 0x2713,
  GATT_PRESENT_UNIT_WAVENUMBER_RECIPROCAL_METRE                            = 0x2714,
  GATT_PRESENT_UNIT_DENSITY_KILOGRAM_PER_CUBIC_METRE                       = 0x2715,
  GATT_PRESENT_UNIT_SURFACE_DENSITY_KILOGRAM_PER_SQUARE_METRE              = 0x2716,
  GATT_PRESENT_UNIT_SPECIFIC_VOLUME_CUBIC_METRE_PER_KILOGRAM               = 0x2717,
  GATT_PRESENT_UNIT_CURRENT_DENSITY_AMPERE_PER_SQUARE_METRE                = 0x2718,
  GATT_PRESENT_UNIT_MAGNETIC_FIELD_STRENGTH_AMPERE_PER_METRE               = 0x2719,
  GATT_PRESENT_UNIT_AMOUNT_CONCENTRATION_MOLE_PER_CUBIC_METRE              = 0x271A,
  GATT_PRESENT_UNIT_MASS_CONCENTRATION_KILOGRAM_PER_CUBIC_METRE            = 0x271B,
  GATT_PRESENT_UNIT_LUMINANCE_CANDELA_PER_SQUARE_METRE                     = 0x271C,
  GATT_PRESENT_UNIT_REFRACTIVE_INDEX                                       = 0x271D,
  GATT_PRESENT_UNIT_RELATIVE_PERMEABILITY                                  = 0x271E,
  GATT_PRESENT_UNIT_PLANE_ANGLE_RADIAN                                     = 0x2720,
  GATT_PRESENT_UNIT_SOLID_ANGLE_STERADIAN                                  = 0x2721,
  GATT_PRESENT_UNIT_FREQUENCY_HERTZ                                        = 0x2722,
  GATT_PRESENT_UNIT_FORCE_NEWTON                                           = 0x2723,
  GATT_PRESENT_UNIT_PRESSURE_PASCAL                                        = 0x2724,
  GATT_PRESENT_UNIT_ENERGY_JOULE                                           = 0x2725,
  GATT_PRESENT_UNIT_POWER_WATT                                             = 0x2726,
  GATT_PRESENT_UNIT_ELECTRIC_CHARGE_COULOMB                                = 0x2727,
  GATT_PRESENT_UNIT_ELECTRIC_POTENTIAL_DIFFERENCE_VOLT                     = 0x2728,
  GATT_PRESENT_UNIT_CAPACITANCE_FARAD                                      = 0x2729,
  GATT_PRESENT_UNIT_ELECTRIC_RESISTANCE_OHM                                = 0x272A,
  GATT_PRESENT_UNIT_ELECTRIC_CONDUCTANCE_SIEMENS                           = 0x272B,
  GATT_PRESENT_UNIT_MAGNETIC_FLEX_WEBER                                    = 0x272C,
  GATT_PRESENT_UNIT_MAGNETIC_FLEX_DENSITY_TESLA                            = 0x272D,
  GATT_PRESENT_UNIT_INDUCTANCE_HENRY                                       = 0x272E,
  GATT_PRESENT_UNIT_THERMODYNAMIC_TEMPERATURE_DEGREE_CELSIUS               = 0x272F,
  GATT_PRESENT_UNIT_LUMINOUS_FLUX_LUMEN                                    = 0x2730,
  GATT_PRESENT_UNIT_ILLUMINANCE_LUX                                        = 0x2731,
  GATT_PRESENT_UNIT_ACTIVITY_REFERRED_TO_A_RADIONUCLIDE_BECQUEREL          = 0x2732,
  GATT_PRESENT_UNIT_ABSORBED_DOSE_GRAY                                     = 0x2733,
  GATT_PRESENT_UNIT_DOSE_EQUIVALENT_SIEVERT                                = 0x2734,
  GATT_PRESENT_UNIT_CATALYTIC_ACTIVITY_KATAL                               = 0x2735,
  GATT_PRESENT_UNIT_DYNAMIC_VISCOSITY_PASCAL_SECOND                        = 0x2740,
  GATT_PRESENT_UNIT_MOMENT_OF_FORCE_NEWTON_METRE                           = 0x2741,
  GATT_PRESENT_UNIT_SURFACE_TENSION_NEWTON_PER_METRE                       = 0x2742,
  GATT_PRESENT_UNIT_ANGULAR_VELOCITY_RADIAN_PER_SECOND                     = 0x2743,
  GATT_PRESENT_UNIT_ANGULAR_ACCELERATION_RADIAN_PER_SECOND_SQUARED         = 0x2744,
  GATT_PRESENT_UNIT_HEAT_FLUX_DENSITY_WATT_PER_SQUARE_METRE                = 0x2745,
  GATT_PRESENT_UNIT_HEAT_CAPACITY_JOULE_PER_KELVIN                         = 0x2746,
  GATT_PRESENT_UNIT_SPECIFIC_HEAT_CAPACITY_JOULE_PER_KILOGRAM_KELVIN       = 0x2747,
  GATT_PRESENT_UNIT_SPECIFIC_ENERGY_JOULE_PER_KILOGRAM                     = 0x2748,
  GATT_PRESENT_UNIT_THERMAL_CONDUCTIVITY_WATT_PER_METRE_KELVIN             = 0x2749,
  GATT_PRESENT_UNIT_ENERGY_DENSITY_JOULE_PER_CUBIC_METRE                   = 0x274A,
  GATT_PRESENT_UNIT_ELECTRIC_FIELD_STRENGTH_VOLT_PER_METRE                 = 0x274B,
  GATT_PRESENT_UNIT_ELECTRIC_CHARGE_DENSITY_COULOMB_PER_CUBIC_METRE        = 0x274C,
  GATT_PRESENT_UNIT_SURFACE_CHARGE_DENSITY_COULOMB_PER_SQUARE_METRE        = 0x274D,
  GATT_PRESENT_UNIT_ELECTRIC_FLUX_DENSITY_COULOMB_PER_SQUARE_METRE         = 0x274E,
  GATT_PRESENT_UNIT_PERMITTIVITY_FARAD_PER_METRE                           = 0x274F,
  GATT_PRESENT_UNIT_PERMEABILITY_HENRY_PER_METRE                           = 0x2750,
  GATT_PRESENT_UNIT_MOLAR_ENERGY_JOULE_PER_MOLE                            = 0x2751,
  GATT_PRESENT_UNIT_MOLAR_ENTROPY_JOULE_PER_MOLE_KELVIN                    = 0x2752,
  GATT_PRESENT_UNIT_EXPOSURE_COULOMB_PER_KILOGRAM                          = 0x2753,
  GATT_PRESENT_UNIT_ABSORBED_DOSE_RATE_GRAY_PER_SECOND                     = 0x2754,
  GATT_PRESENT_UNIT_RADIANT_INTENSITY_WATT_PER_STERADIAN                   = 0x2755,
  GATT_PRESENT_UNIT_RADIANCE_WATT_PER_SQUARE_METRE_STERADIAN               = 0x2756,
  GATT_PRESENT_UNIT_CATALYTIC_ACTIVITY_CONCENTRATION_KATAL_PER_CUBIC_METRE = 0x2757,
  GATT_PRESENT_UNIT_TIME_MINUTE                                            = 0x2760,
  GATT_PRESENT_UNIT_TIME_HOUR                                              = 0x2761,
  GATT_PRESENT_UNIT_TIME_DAY                                               = 0x2762,
  GATT_PRESENT_UNIT_PLANE_ANGLE_DEGREE                                     = 0x2763,
  GATT_PRESENT_UNIT_PLANE_ANGLE_MINUTE                                     = 0x2764,
  GATT_PRESENT_UNIT_PLANE_ANGLE_SECOND                                     = 0x2765,
  GATT_PRESENT_UNIT_AREA_HECTARE                                           = 0x2766,
  GATT_PRESENT_UNIT_VOLUME_LITRE                                           = 0x2767,
  GATT_PRESENT_UNIT_MASS_TONNE                                             = 0x2768,
  GATT_PRESENT_UNIT_PRESSURE_BAR                                           = 0x2780,
  GATT_PRESENT_UNIT_PRESSURE_MILLIMETRE_OF_MERCURY                         = 0x2781,
  GATT_PRESENT_UNIT_LENGTH_ANGSTROM                                        = 0x2782,
  GATT_PRESENT_UNIT_LENGTH_NAUTICAL_MILE                                   = 0x2783,
  GATT_PRESENT_UNIT_AREA_BARN                                              = 0x2784,
  GATT_PRESENT_UNIT_VELOCITY_KNOT                                          = 0x2785,
  GATT_PRESENT_UNIT_LOGARITHMIC_RADIO_QUANTITY_NEPER                       = 0x2786,
  GATT_PRESENT_UNIT_LOGARITHMIC_RADIO_QUANTITY_BEL                         = 0x2787,
  GATT_PRESENT_UNIT_LENGTH_YARD                                            = 0x27A0,
  GATT_PRESENT_UNIT_LENGTH_PARSEC                                          = 0x27A1,
  GATT_PRESENT_UNIT_LENGTH_INCH                                            = 0x27A2,
  GATT_PRESENT_UNIT_LENGTH_FOOT                                            = 0x27A3,
  GATT_PRESENT_UNIT_LENGTH_MILE                                            = 0x27A4,
  GATT_PRESENT_UNIT_PRESSURE_POUND_FORCE_PER_SQUARE_INCH                   = 0x27A5,
  GATT_PRESENT_UNIT_VELOCITY_KILOMETRE_PER_HOUR                            = 0x27A6,
  GATT_PRESENT_UNIT_VELOCITY_MILE_PER_HOUR                                 = 0x27A7,
  GATT_PRESENT_UNIT_ANGULAR_VELOCITY_REVOLUTION_PER_MINUTE                 = 0x27A8,
  GATT_PRESENT_UNIT_ENERGY_GRAM_CALORIE                                    = 0x27A9,
  GATT_PRESENT_UNIT_ENERGY_KILOGRAM_CALORIE                                = 0x27AA,
  GATT_PRESENT_UNIT_ENERGY_KILOWATT_HOUR                                   = 0x27AB,
  GATT_PRESENT_UNIT_THERMODYNAMIC_TEMPERATURE_DEGREE_FAHRENHEIT            = 0x27AC,
  GATT_PRESENT_UNIT_PERCENTAGE                                             = 0x27AD,
  GATT_PRESENT_UNIT_PER_MILLE                                              = 0x27AE,
  GATT_PRESENT_UNIT_PERIOD_BEATS_PER_MINUTE                                = 0x27AF,
  GATT_PRESENT_UNIT_ELECTRIC_CHARGE_AMPERE_HOURS                           = 0x27B0,
  GATT_PRESENT_UNIT_MASS_DENSITY_MILLIGRAM_PER_DECILITRE                   = 0x27B1,
  GATT_PRESENT_UNIT_MASS_DENSITY_MILLIMOLE_PER_LITRE                       = 0x27B2,
  GATT_PRESENT_UNIT_TIME_YEAR                                              = 0x27B3,
  GATT_PRESENT_UNIT_TIME_MONTH                                             = 0x27B4,
  GATT_PRESENT_UNIT_CONCENTRATION_COUNT_PER_CUBIC_METRE                    = 0x27B5,
  GATT_PRESENT_UNIT_IRRADIANCE_WATT_PER_SQUARE_METRE                       = 0x27B6,
  GATT_PRESENT_UNIT_MILLILITER                                             = 0x27B7,
  GATT_PRESENT_UNIT_POUNDS                                                 = 0x27B8
};

typedef struct
{
    uint8_t format;
    int8_t exponent;
    uint16_t unit;
    uint8_t nameSpace;
    uint16_t desc;
} GATT_PRESENTATION_t;

typedef struct 
{
    uint16_t id;
    uint8_t properties;
    uint8_t minLen;
    uint8_t maxLen;
    const char *description;
    GATT_PRESENTATION_t presentation;
    uint8_t *data;
} GATT_CHARACTERISTIC_t;

typedef struct
{
    int16_t torqueRequested;
    int16_t torqueActual;
    int16_t throttleRawLevel1;
    int16_t throttleRawLevel2;
    int16_t brakeRawLevel;
    int8_t throttlePercentage;
    int8_t brakePercentage; 
    int16_t speedRequested;
    int16_t speedActual;
    uint8_t powerMode;
    uint8_t gear;
    uint8_t isRunning;
    uint8_t isFaulted;
    uint8_t isWarning;
    uint8_t logLevel;
    uint16_t can0Speed;
    uint16_t can1Speed;
    uint16_t busVoltage;
    int16_t busCurrent;
    int16_t motorCurrent;
    uint16_t kwHours;
    int16_t mechPower;
    uint8_t SOC;
    uint32_t bitfield1;
    uint32_t bitfield2;
    uint32_t digitalInputs;
    uint32_t digitalOutputs;
    int16_t motorTemperature;
    int16_t inverterTemperature;
    int16_t systemTemperature;
    uint16_t prechargeDuration;
    uint8_t prechargeRelay;
    uint8_t mainContRelay;
    uint8_t coolingRelay;
    int8_t coolOnTemp;
    int8_t coolOffTemp;
    uint8_t brakeLightOut;
    uint8_t reverseLightOut;
    uint8_t enableIn;
    uint8_t reverseIn;
    int16_t throttle1Min;
    int16_t throttle2Min;
    int16_t throttle1Max;
    int16_t throttle2Max;   
    uint8_t numThrottlePots;
    uint8_t throttleType;
    uint16_t throttleRegenMax; 
    uint16_t throttleRegenMin; 
    uint16_t throttleFwd; 
    uint16_t throttleMap; 
    uint8_t throttleLowestRegen; 
    uint8_t throttleHighestRegen; 
    uint8_t throttleCreep; 
    int16_t brakeMin;
    int16_t brakeMax;
    uint8_t brakeRegenMin;
    uint8_t brakeRegenMax;
    uint16_t nomVoltage;
    uint16_t maxRPM;
    uint16_t maxTorque;
    uint32_t deviceEnable1;
    uint32_t deviceEnable2;
    uint32_t timeRunning;
} GEVCU_PARAM_CACHE_t;


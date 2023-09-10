/**
 * \file MPU_Cfg.h
 *
 * \brief Preprocessor macro defines for MPU configuration.
 *
 * \section Scope Scope
 * Public
 *
 * \section Authors Authors
 * - Shehab Abdalah
 * - Abdelrahman Sanad
 */

#ifndef MPU_CFG_H_
#define MPU_CFG_H_

#include "Std_Types.h"


/**
 * @brief Used to set all memory map as the background region which can only be accessed in privileged mode.
 *        It will fire a hard fault exception in unprivileged mode.
 *
 * @details
 * - Type: Macro
 * - Range: STD_ON or STD_OFF
 * - Resolution: 1
 * - Unit: Flag
 */
#define PRIVDEFENA      STD_ON

/**
 * @brief Enables the operation of MPU during hard fault, NMI, and FAULTMASK handlers.
 *        When the MPU is enabled
 *
 * @details
 * - Type: Macro
 * - Range: STD_ON or STD_OFF
 * - Resolution: 1
 * - Unit: Flag
 */
#define HFNMIENA        STD_ON

#endif /* MPU_CFG_H_ */


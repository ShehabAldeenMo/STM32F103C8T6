/**
* \file MPU_Private.h
*
* \brief Contains private defines and addresses of registers for the MPU (Memory Protection Unit) driver.
*
* \section Scope
* Private
*
* @section Author
* Shehab Abdalah - Abdelrahman Sanad
*/

#ifndef MPU_PRIVATE_H_
#define MPU_PRIVATE_H_

#include "Std_Types.h"

/**
 * \section Brief
 * Structure used in a pointer that helps access registers in the MPU peripheral.
 *
 * \section Details
 * - Type: Structure
 * - Range: Unapplicable
 * - Resolution: Unapplicable
 * - Unit: Address
 */
typedef struct {
    /**
     * \section Brief
     * Type register.
     */
    uint32 TYPER;

    /**
     * \section Brief
     * Control register.
     */
    uint32 CR;

    /**
     * \section Brief
     * Region number register.
     */
    uint32 RNR;

    /**
     * \section Brief
     * Region base address register.
     */
    uint32 RBAR;

    /**
     * \section Brief
     * Region attribute and size register.
     */
    uint32 RASR;
} MPU_REG;

/**
 * \section Brief
 * Pointer to a structure used to access registers in the MPU peripheral.
 *
 * \section Details
 * - Type: Macro
 * - Range: Unapplicable
 * - Resolution: Unapplicable
 * - Unit: Base address
 */
#define MPU        ((volatile MPU_REG *)(0xE000ED90))

/**
 * \section Brief
 * Bit position to access the VALID bit in RBAR.
 *
 * \section Details
 * - Type: Macro
 * - Range: Constant
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
#define VALID   4

/**
 * \section Brief
 * Base address of flash memory (0x00000000).
 *
 * \section Details
 * - Type: Macro
 * - Range: Constant
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
#define FLASH_BASE_ADDRESS   0x00000000

/**
 * \section Brief
 * Base address of internal RAM memory (0x20000000).
 *
 * \section Details
 * - Type: Macro
 * - Range: Constant
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
#define ISRAM_BASE_ADDRESS   0x20000000

/**
 * \section Brief
 * Base address of peripheral memory (0x40000000).
 *
 * \section Details
 * - Type: Macro
 * - Range: Constant
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
#define PERPH_BASE_ADDRESS   0x40000000

/**
 * \section Brief
 * Define the enable bit in each register.
 *
 * \section Details
 * - Type: Macro
 * - Range: Constant
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
#define ENABLE_REGION    0x1

/**
 * \section Brief
 * Define to enable all subregions in a region.
 *
 * \section Details
 * - Type: Macro
 * - Range: Constant
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
#define SUBREGIONS    0x0000

#endif /* MPU_PRIVATE_H_ */

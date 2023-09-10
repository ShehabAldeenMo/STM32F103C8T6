/**
 * \file MPU_Cfg.c
 *
 * \brief Set the initial specifications of memory.
 *
 * \section Scope
 * Public
 *
 * @section Author
 * - Shehab Abdalah
 * - Abdelrahman Sanad
 */

#include "MPU_Interface.h"
#include "Std_Types.h"

/**
 * \section Brief Brief
 * Set specific attributes for Flash memory as default.
 *
 * \section Details
 * - Type: Attributes_1
 * - Range: Same as Attributes_1
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
Attributes Flash_Memory = Normal_Not_Shareable_Write_Through;

/**
 * \section Brief Brief
 * Determine the size of covered Flash memory.
 *
 * \section Details
 * - Type: Size_Enum
 * - Range: Same as Size_Enum
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
Size_Enum Flash_Size = Size_512MB;

/**
 * \section Brief Brief
 * Set specific attributes for Internal SRAM memory as default.
 *
 * \section Details
 * - Type: Attributes_1
 * - Range: Same as Attributes_1
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
Attributes Internal_SRAM = Normal_Shareable_Write_Through;

/**
 * \section Brief Brief
 * Determine the size of covered Internal SRAM memory.
 *
 * \section Details
 * - Type: Size_Enum
 * - Range: Same as Size_Enum
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
Size_Enum Internal_SRAM_Size = Size_32MB;

/**
 * \section Brief Brief
 * Set specific attributes for Peripherals memory as default.
 *
 * \section Details
 * - Type: Attributes_1
 * - Range: Same as Attributes_1
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
Attributes Peripherals = Device_Shearable;

/**
 * \section Brief Brief
 * Determine the size of covered Internal Peripheral memory.
 *
 * \section Details
 * - Type: Size_Enum
 * - Range: Same as Size_Enum
 * - Resolution: Inapplicable
 * - Unit: Bit
 */
Size_Enum Peripherals_Size = Size_1MB;


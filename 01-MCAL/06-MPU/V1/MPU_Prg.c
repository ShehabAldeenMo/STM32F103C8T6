/**
 * @file MPU_Prg.c
 *
 * This file contains the implementation of functions for the MPU (Memory Protection Unit) driver.
 *
 *
 * @section Scope
 * Private
 *
 * @section Author
 * Shehab Abdalah - Abdelrahman Sanad
 */

#include "MPU_Interface.h"
#include "MPU_Private.h"
#include "MPU_Cfg.h"

extern Attributes Peripherals;
extern Attributes Internal_SRAM;
extern Attributes Flash_Memory;

extern Size_Enum Peripherals_Size;
extern Size_Enum Internal_SRAM_Size;
extern Size_Enum Flash_Size;

/**
 * @brief Macro to concatenate two macros.
 *
 *
 * @param x Type macro, Range unapplicable, Resolution unapplicable, Unit bit
 * @param y Type macro, Range unapplicable, Resolution unapplicable, Unit bit
 * @return Combined macro value
 */
#define MPU_CR_HELPER(x, y)  0b0##x##y##1

/**
 * @defgroup MPU_Driver MPU Driver
 * @{
 *
 * @file MPU_Cfg.h
 * @file MPU_Interface.h
 * @file MPU_Private.h
 * @file MPU_Cfg.c
 * @file MPU_Prg.c
 */

/**
 * @addtogroup MPU_Driver
 * @{
 *
 * This file contains the implementation of functions for the MPU (Memory Protection Unit) driver.
 */

/**
 * @section Description
 * - This function initializes the MPU with the specified configuration.
 *
 *
 * @section Synchronous Synchronous Behavior
 * - Synchronous
 * @section Reentrancy Reentrancy Behavior
 * - Re-entrant
 *
 * @param None
 * @return None
 * @note Call MPU_Init() before configuring memory protection regions.
 *
 *
 *  @section Activity Activity Diagram
 *  @startuml MPU_Init
 *
 * start
 *
 * :Initialize MPU Control Register;
 *
 * :Configure Regions;
 * :Set Region Numbers, Base Addresses, and Attributes;
 *
 * :Enable Regions;
 *
 * stop
 *
 * @enduml
 *
 *@section Sequence Sequence Diagram
 *
 */
void MPU_Init(void) {
    MPU->CR = MPU_CR(PRIVDEFENA, HFNMIENA);

    MPU->RNR  = Region_0 ;
    MPU->RBAR = FLASH_BASE_ADDRESS;
    MPU->RASR = Flash_Memory | Flash_Size | Ap_Acess_all_Modes | ENABLE_REGION | SUBREGIONS ;

    MPU->RNR  = Region_1 ;
    MPU->RBAR = ISRAM_BASE_ADDRESS;
    MPU->RASR = Internal_SRAM | Internal_SRAM_Size | Ap_Acess_all_Modes | ENABLE_REGION | SUBREGIONS ;

    MPU->RNR  = Region_2 ;
    MPU->RBAR = PERPH_BASE_ADDRESS;
    MPU->RASR = Peripherals | Peripherals_Size | Ap_Acess_all_Modes | ENABLE_REGION | SUBREGIONS ;
}

/**
 * @section Description
 * - This function enables the MPU, allowing memory protection to take effect.
 *
 *
 * @section Synchronous Synchronous Behavior
 * - Synchronous
 * @section Reentrancy Reentrancy Behavior
 * - Re-entrant
 *
 * @param None
 * @return None
 *
 *  @section Activity Activity Diagram
 *  @startuml MPU_Enable
 *
 *  usecase UC1 as "Enables MPU"
 *
 * @enduml
 *
 *@section Sequence Sequence Diagram
 *
 */
void MPU_Enable(void) {
    MPU->CR = 0x00000001;
}

/**
 * @section Description
 * - This function disables the MPU, preventing memory protection from taking effect.
 *
 *
 * @section Synchronous Synchronous Behavior
 * - Synchronous
 * @section Reentrancy Reentrancy Behavior
 * - Re-entrant
 *
 * @param None
 * @return None
 *
 * @section Activity Activity Diagram
 * @startuml MPU_Disable
 *
 *  usecase UC1 as "Disables MPU"
 *
 * @enduml
 *
 *@section Sequence Sequence Diagram
 */
void MPU_Disable(void) {
    MPU->CR = 0x00000000;
}

/**
 * @section Description
 * - This function configures a specific memory protection region with the provided attributes
 *
 * @section Synchronous Synchronous Behavior
 * - Synchronous
 * @section Reentrancy Reentrancy Behavior
 * - Re-entrant
 *
 * @param region     Type Region_Enum      Range determined from Region_Enum
 * @param baseAddress Type uint32           Constant range based on the size of the region
 * @param size       Type Size_Enum        Constant range [32B, 10KB, 1MB, 1GB, 4GB]
 * @param attributes Type uint32           Constant range according to the desired configurations
 * @return None
 * @note Call MPU_EnableRegion to activate the configured region.
 *
 *  @section Activity Activity Diagram
 *  @startuml MPU_ConfigRegion
 *
  * start
 *
 * :Set Region Number to specified region;
 *
 * :Set Base Address Register;
 *
 * :Set Region Attribute and Size Register;
 *
 * stop
 *
 * @enduml
 *
 *@section Sequence Sequence Diagram
 *
 */
void MPU_ConfigRegion(const Region_Enum region, const uint32 baseAddress, const Size_Enum size, const uint32 attributes) {
    MPU->RNR  = region;
    MPU->RBAR = baseAddress;
    MPU->RASR = attributes | size;
}

/**
 * @section Description
 * - Enable a memory protection region with the specified configuration.
 *
 * @section Synchronous Synchronous Behavior
 * - Synchronous
 * @section Reentrancy Reentrancy Behavior
 * - Re-entrant
 *
 * @param region Type Region_Enum           Range determined from Region_Enum
 * @return None
 *
 * * @section Activity Activity Diagram
 * @startuml MPU_EnableRegion
 *
 *  usecase UC1 as "Enables MPU Region"
 *
 * @enduml
 *
 *@section Sequence Sequence Diagram
 *
 */
void MPU_EnableRegion(const Region_Enum region) {
    MPU->RNR  = region;
}

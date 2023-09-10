/**
 * @mainpage STM32F103 MPU Driver Documentation
 *
 * @section intro Introduction
 *
 * Welcome to the documentation for the Memory Protection Unit (MPU) driver designed for
 * the STM32F103 microcontroller. This documentation provides a comprehensive overview of
 * the MPU driver's functionality, usage, and API within the context of embedded systems.
 *
 * @section features Features
 *
 * - **Memory Protection and Access Control**
 *
 * - **Configurable Memory Regions**
 *
 * - **Protection Against Unauthorized Access**
 *
 * @section scope Scope
 *
 * Public
 *
 * @section Global_Sequence MPU Configuration Sequence
 *  \startuml
 *   main -> interface: Enable or disable the MPU
 *   main -> interface: Set configurations for specific regions at an offset from the base address
 *   main -> interface: Enable or disable specific regions
 *  \enduml
 *
 * @section reference References
 *
 * - **STM32F10xxx Cortex-M3 Programming Manual**
 * - **GeeksforGeeks - Write-Through and Write-Back in Cache Article**
 *
 * @section Component_History
 *  - **V.1.0.0:** Initial release.
 *
 * @section Author
 * Shehab Abdalah - Abdelrahman Sanad
 *
 * @section Memory_Types Memory Types
 *
 * The STM32F103 MPU driver supports various memory types, including:
 * \startuml
 *  usecase UC1 as "Normal Memory"
 *  usecase UC2 as "Device Memory"
 *  usecase UC3 as "Strongly Ordered Memory"
 *  usecase UC4 as "Execute Never Memory"
 * \enduml
 *
 * @section Attributes Memory Attributes
 *
 * The driver defines memory attributes that control access and caching behavior:
 * \startuml
 *  usecase UC5 as "Shareability"
 *  usecase UC6 as "Cacheability"
 * \enduml
 *
 */

/**
 * \file MPU_Interface.h
 *
 * Defined data structures and function declarations for the MPU driver.
 *
 * \section Scope
 * Public
 *
 * @section Author
 * Shehab Abdalah - Abdelrahman Sanad
 */

#ifndef MPU_INTERFACE_H_
#define MPU_INTERFACE_H_

#include "Std_Types.h"
#include "Bit_Math.h"

/**
 * @brief Enumeration for memory protection attributes.
 *
 *
 * @details
 * - Type: enum
 * - Range: Inapplicable
 * - Resolution: Inapplicable
 * - Unit: Bits
 */
typedef enum {
    Strongly_Shearable                          = 0x00000000 ,
    Device_Shearable                            = 0x00020000 ,

    Normal_Not_Shareable_Write_Through          = 0x00040000 ,
    Normal_Shareable_Write_Through              = 0x00050000 ,

    Normal_Not_Shareable_Write_Back             = 0x00060000 ,
    Normal_Shareable_Write_Back                 = 0x00070000 ,

    Normal_Not_Shareable_Non_cacheable          = 0x00080000 ,
    Normal_Shareable_Non_cacheable              = 0x00090000 ,

    Normal_Not_Shareable_Write_Back_RW_Allocate = 0x000C0000 ,
    Normal_Shareable_Write_Back_RW_Allocate     = 0x000E0000 ,

    Device_Not_Shearable                        = 0x00100000 ,

    Ap_No_Acess                                 = 0x00000000,
    Ap_Pri_RW                                   = 0x01000000,
    Ap_Pri_RW_Unpri_RO                          = 0x02000000,
    Ap_Acess_all_Modes                          = 0x03000000,
    Ap_Pri_RO                                   = 0x04000000,
    Ap_Pri_RO_Unpri_RO                          = 0x05000000,

    XN_Enabled                                  = 0x00000000 ,
    XN_Disabled                                 = 0x10000000
} Attributes;

/**
 * @brief Enumeration for memory region accessibility.
 *
 *
 * @details
 * - Type: enum
 * - Range: [0x00000000 : 0x05000000]
 * - Resolution: Inapplicable
 * - Unit: Bits
 */
typedef enum {
    Region_0 = 0x00000001,
    Region_1 = 0x00000002,
    Region_2 = 0x00000004,
    Region_3 = 0x00000008,
    Region_4 = 0x00000010,
    Region_5 = 0x00000020,
    Region_6 = 0x00000040,
    Region_7 = 0x00000080,
} Region_Enum;

/**
 * @brief Enumeration for memory region sizes.
 *
 *
 * @details
 * - Type: enum
 * - Range: [0x00000008 : 0x0000003E]
 * - Resolution: Inapplicable
 * - Unit: Bits
 */
typedef enum {
    Size_32B   = 0x00000008,
    Size_64B   = 0x0000000A,
    Size_128B  = 0x0000000C,
    Size_256B  = 0x0000000E,
    Size_512B  = 0x00000010,
    Size_1KB   = 0x00000012,
    Size_2KB   = 0x00000014,
    Size_4KB   = 0x00000016,
    Size_8KB   = 0x00000018,
    Size_16KB  = 0x0000001A,
    Size_32KB  = 0x0000001C,
    Size_64KB  = 0x0000001E,
    Size_128KB = 0x00000020,
    Size_256KB = 0x00000022,
    Size_512KB = 0x00000024,
    Size_1MB   = 0x00000026,
    Size_2MB   = 0x00000028,
    Size_4MB   = 0x0000002A,
    Size_8MB   = 0x0000002C,
    Size_16MB  = 0x0000002E,
    Size_32MB  = 0x00000030,
    Size_64MB  = 0x00000032,
    Size_128MB = 0x00000034,
    Size_256MB = 0x00000036,
    Size_512MB = 0x00000038,
    Size_1GB   = 0x0000003A,
    Size_2GB   = 0x0000003C,
    Size_4GB   = 0x0000003E,
} Size_Enum;

/**
 *
 * This function enables the MPU peripheral with default attributes for memory protection regions.
 *
 * @param None
 * @return None
 * @note This function must be called before configuring memory protection regions.
 */
void MPU_Init(void);

/**
 *
 * This function enables the MPU, allowing memory protection to take effect.
 *
 * @param None
 * @return None
 */
void MPU_Enable(void);

/**
 *
 * This function disables the MPU, preventing memory protection from taking effect.
 *
 * @param None
 * @return None
 */
void MPU_Disable(void);

/**
 *
 * This function configures a specific memory protection region with the provided attributes.
 *
 * @param region     Type Region_Enum      Range determined from Region_Enum
 * @param baseAddress Type uint32           Constant range based on the size of the region
 * @param size       Type Size_Enum        Constant range [32B, 10KB, 1MB, 1GB, 4GB]
 * @param attributes Type uint32           Constant range according to the desired configurations
 * @return None
 * @note Call MPU_EnableRegion to activate the configured region.
 */
void MPU_ConfigRegion(const Region_Enum region, const uint32 baseAddress, const Size_Enum size, const uint32 attributes);

/**
 *
 * This function enables memory protection for the specified region.
 *
 * @param region Type Region_Enum           Range determined from Region_Enum
 * @return None
 */
void MPU_EnableRegion(const Region_Enum region);

/**
 *
 * This function disables memory protection for the specified region.
 *
 * @param region Type Region_Enum           Range determined from Region_Enum
 * @return None
 */
void MPU_DisableRegion(const Region_Enum region);

#endif /* MPU_INTERFACE_H_ */


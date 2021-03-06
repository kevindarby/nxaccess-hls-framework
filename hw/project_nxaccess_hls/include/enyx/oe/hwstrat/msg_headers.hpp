//--------------------------------------------------------------------------------
//--! Licensed Materials - Property of ENYX
//--!
//--! Organization:          Enyx
//--! Project Identifier:    010 - Enyx nxAccess HLS Framework
//--! Author:                Raphael Charolois (raphael.charolois@enyx.com)
//--!
//--! © Copyright            Enyx 2019
//--! © Copyright Notice:    The source code for this program is not published or otherwise divested of its trade secrets, 
//--!                        irrespective of what has been deposited with the U.S. Copyright Office.
//--------------------------------------------------------------------------------

#ifndef DMA_MSGS_H
#define DMA_MSGS_H

/// This file contains the format of DMA messages sent to & from FPGA.
/// This header file is intended for software designers and serve as reference documentation
/// for the hardware designers
/// There are no dependencies on HLS library.

#include <stdint.h>

namespace enyx {
namespace oe {
namespace hwstrat {

#pragma pack(1)
struct cpu2fpga_header {
    uint8_t version:4;     /// message format version
    uint8_t dest:4;      /// source fpga module id
    uint8_t msg_type:4;    /// message_type, defined per module
    uint8_t ack_request:1; /// Ack message request (1 = want ack)
    uint8_t reserved:3;       ///
    uint32_t timestamp;   /// future use : hw timestamp, unused by soft
    uint16_t length;    /// message format version

};

//static_assert(8 == sizeof(cpu2fpga_header), "Invalid cpu2fpga header size. Must be 8B");
//_Static_assert(8 == sizeof(cpu2fpga_header), "Invalid cpu2fpga header size. Must be 8B");

#pragma pack(1)
struct fpga2cpu_header {
    uint8_t version:4;     /// message format version
    uint8_t source:4;  /// source fpga module id
    uint8_t msg_type:4;  /// message_type
    uint8_t error:1;     /// error bit in case message is not processed correctly
    uint8_t reserved:3;     /// ack


    uint32_t timestamp;   /// future use : hw timestamp, unused for now.
    uint16_t length;    /// message format version
};

// Modules Ids convention for all Enyx nxAccess HLS designs
enum {
    Reserved0, // Reserved for enyx
    Reserved1, // Reserved for enyx
    Reserved2, // Reserved for enyx
    Reserved3, // Reserved for enyx
    Reserved4, // Reserved for enyx
    Reserved5, // Reserved for enyx
    Reserved6, // Reserved for enyx
    Reserved7, // Reserved for enyx
    UserDefined0, // Allocated for User convenience
    UserDefined1, // Allocated for User convenience
    UserDefined2, // Allocated for User convenience
    UserDefined3, // Allocated for User convenience
    UserDefined4, // Allocated for User convenience
    UserDefined5, // Allocated for User convenience
    UserDefined6, // Allocated for User convenience
    UserDefined7, // Allocated for User convenience

} fpga_modules_ids;


//static_assert(8 == sizeof(fpga2cpu_header), "Invalid cpu2fpga header size. Must be 8B");
//_Static_assert(8 == sizeof(fpga2cpu_header), "Invalid cpu2fpga header size. Must be 8B");

}}} // Namespaces
#endif // DMA_MSGS_H

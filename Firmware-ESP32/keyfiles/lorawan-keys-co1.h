/*******************************************************************************
 *
 *  File:          lorawan-keys_example.h
 * 
 *  Function:      Example for lorawan-keys.h required by LMIC-node.
 *
 *  Copyright:     Copyright (c) 2021 Leonel Lopes Parente
 *
 *  Important      ██ DO NOT EDIT THIS EXAMPLE FILE (see instructions below) ██
 * 
 *  Decription:    lorawan-keys.h defines LoRaWAN keys needed by the LMIC library.
 *                 It can contain keys for both OTAA and for ABP activation.
 *                 Only the keys for the used activation type need to be specified.
 * 
 *                 It is essential that each key is specified in the correct format.
 *                 lsb: least-significant-byte first, msb: most-significant-byte first.
 * 
 *                 For security reasons all files in the keyfiles folder (except file
 *                 lorawan-keys_example.h) are excluded from the Git(Hub) repository.
 *                 Also excluded are all files matching the pattern *lorawan-keys.h.
 *                 This way they cannot be accidentally committed to a public repository.
 * 
 *  Instructions:  1. Copy this file lorawan-keys_example.h to file lorawan-keys.h
 *                    in the same folder (keyfiles).
 *                 2. Place/edit required LoRaWAN keys in the new lorawan-keys.h file.
 *
 ******************************************************************************/

#pragma once

#ifndef LORAWAN_KEYS_H_
#define LORAWAN_KEYS_H_

// Optional: If DEVICEID is defined it will be used instead of the default defined in the BSF.
// #define DEVICEID "<deviceid>"

// Keys required for OTAA activation:

// End-device Identifier (u1_t[8]) in lsb format
#define OTAA_DEVEUI 0x3F, 0xAE, 0xC4, 0x36, 0xA8, 0x9D, 0xEB, 0x1C

// Application Identifier (u1_t[8]) in lsb format
#define OTAA_APPEUI 0xAE, 0x20, 0xEF, 0xD4, 0xEB, 0xDC, 0x22, 0x1A

// Application Key (u1_t[16]) in msb format
#define OTAA_APPKEY 0x58, 0x0D, 0x63, 0xF2, 0x31, 0xC1, 0xA7, 0x53, 0x8E, 0x92, 0xBF, 0xDD, 0xE7, 0x19, 0x6F, 0xC9


// -----------------------------------------------------------------------------

// Optional: If ABP_DEVICEID is defined it will be used for ABP instead of the default defined in the BSF.
// #define ABP_DEVICEID "<deviceid>"

// Keys required for ABP activation:

// End-device Address (u4_t) in uint32_t format. 
// Note: The value must start with 0x (current version of TTN Console does not provide this).
#define ABP_DEVADDR 0x661e70e5

// Network Session Key (u1_t[16]) in msb format
#define ABP_NWKSKEY 0xC6, 0x1A, 0x56, 0x11, 0x54, 0x76, 0x88, 0x75, 0x17, 0x10, 0x0E, 0xF4, 0x73, 0x88, 0xBB, 0x21

// Application Session K (u1_t[16]) in msb format
#define ABP_APPSKEY 0x3F, 0xF6, 0xA7, 0xEA, 0x3D, 0xE0, 0xF4, 0x51, 0xA2, 0x3A, 0x94, 0xE6, 0xE4, 0x0E, 0x0D, 0xD7


#endif  // LORAWAN_KEYS_H_

/* Copyright 2022 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

// #include <sm_types.h>
#include "se05x_APDU_apis.h"
#include "sm_port.h"

#define USE_COMPRESSED_EC_KEY 0

/*
 * !!! WARNING !!!
 *
 * The credentials added here are just for demonstration purpose.
 * These variables must be overwritten/erased/made inaccessible once they 
 * have been transferred to the secure element
 */

/* clang-format off */
#if USE_COMPRESSED_EC_KEY
const uint8_t qi_ec_priv_key[] = {
	/* Replace with Qi key to be provisioned here */
	0x56, 0xD8, 0x4C, 0x3C, 0xB0, 0x56, 0x36, 0xBD, 0x5E, 0x20, 0xA8, 0x86, 
	0xC4, 0x38, 0x57, 0xFE, 0x19, 0x31, 0x65, 0xBD, 0xC7, 0xAD, 0xF7, 0xC8, 
	0x97, 0x20, 0x1C, 0x02, 0x86, 0xAE, 0xE5, 0x74 
};
const uint8_t qi_ec_pub_key[] = {
	/* Replace with Qi key to be provisioned here */
	0x04, 0x8B, 0x9C, 0xDC, 0x5E, 0x24, 0xF1, 0xE1, 0x39, 0xB2, 0x04, 0x09, 
	0x4A, 0x47, 0xB6, 0xB6, 0xFA, 0x30, 0x0D, 0x18, 0x16, 0xBC, 0xB6, 0x53, 
	0x6D, 0xD8, 0x7F, 0x8F, 0xFC, 0xC5, 0x43, 0x46, 0xC0, 0x89, 0x85, 0xED, 
	0xB7, 0xDD, 0x74, 0x17, 0xA3, 0xC1, 0x2F, 0xCA, 0xF5, 0x3A, 0xB7, 0x41, 
	0x54, 0xD2, 0x47, 0x81, 0x08, 0x30, 0x7C, 0x50, 0xAB, 0x33, 0x77, 0xC2, 
	0x89, 0x94, 0x48, 0x70, 0xC0
};

const uint8_t qi_certificate_chain[] = {
	/* Replace with Qi certificate chain to be provisioned here */
	0x42, 0x98, 0x7B, 0x59, 0xE9, 0x4D, 0x30, 0xBF, 0xCA, 0x0E, 0x8C, 0x89,
	0xCE, 0x1A, 0x9B, 0x71, 0x19, 0x0A, 0xD2, 0xEA, 0x48, 0x8F, 0xAD, 0x54,
	0x6A, 0x7E, 0x90, 0x86, 0xF3, 0x94, 0x18, 0xCC, 0x02, 0x8B, 0x9F, 0x50,
	0xDD, 0xDD, 0x27, 0xE2, 0xE1, 0x94, 0x27, 0x5C, 0x90, 0x83, 0xCA, 0xCF,
	0xA0, 0xA0, 0x9F, 0x43, 0xBC, 0x99, 0xF2, 0x57, 0x4B, 0xC3, 0xF9, 0xFC,
	0x41, 0x26, 0x53, 0x18, 0x86, 0x3D, 0x30, 0x82, 0x01, 0x45, 0x30, 0x81,
	0xEC, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08, 0x23, 0x70, 0x04, 0x7A,
	0x39, 0xA4, 0x63, 0x6E, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE,
	0x3D, 0x04, 0x03, 0x02, 0x30, 0x12, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03,
	0x55, 0x04, 0x03, 0x0C, 0x07, 0x54, 0x53, 0x54, 0x57, 0x50, 0x43, 0x31,
	0x30, 0x20, 0x17, 0x0D, 0x32, 0x32, 0x30, 0x35, 0x31, 0x31, 0x31, 0x33,
	0x34, 0x36, 0x33, 0x37, 0x5A, 0x18, 0x0F, 0x39, 0x39, 0x39, 0x39, 0x31,
	0x32, 0x33, 0x31, 0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5A, 0x30, 0x12,
	0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x07, 0x30,
	0x30, 0x32, 0x41, 0x2D, 0x54, 0x30, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07,
	0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A, 0x86, 0x48,
	0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x88, 0xAB, 0x25,
	0x70, 0x7E, 0x85, 0x31, 0x5C, 0xD8, 0x04, 0x88, 0x8E, 0x00, 0xAD, 0x9A,
	0xC3, 0xAC, 0x58, 0x75, 0x6D, 0x4E, 0x86, 0xAA, 0x37, 0xB9, 0x69, 0x1B,
	0x3F, 0xBE, 0x0B, 0x1C, 0xC5, 0xCC, 0x96, 0xC8, 0x23, 0x79, 0x70, 0x24,
	0xC5, 0x1A, 0xF9, 0xA9, 0x3A, 0xC6, 0x0E, 0x5E, 0x88, 0xEF, 0x77, 0x03,
	0x69, 0xF4, 0xEE, 0xE1, 0x26, 0x55, 0x33, 0x60, 0x86, 0x25, 0x4A, 0x17,
	0xC8, 0xA3, 0x2A, 0x30, 0x28, 0x30, 0x12, 0x06, 0x03, 0x55, 0x1D, 0x13,
	0x01, 0x01, 0xFF, 0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xFF, 0x02, 0x01,
	0x00, 0x30, 0x12, 0x06, 0x05, 0x67, 0x81, 0x14, 0x01, 0x01, 0x01, 0x01,
	0xFF, 0x04, 0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x01, 0x30, 0x0A, 0x06,
	0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00,
	0x30, 0x45, 0x02, 0x21, 0x00, 0xA6, 0x84, 0x00, 0xD4, 0x38, 0x7D, 0x63,
	0x21, 0x7E, 0xDD, 0xB3, 0x94, 0x68, 0x91, 0xF9, 0x0B, 0x86, 0x2D, 0x6D,
	0x5B, 0x5D, 0x01, 0x84, 0xE4, 0x50, 0x3D, 0x6F, 0x97, 0xB8, 0x18, 0x36,
	0x38, 0x02, 0x20, 0x67, 0x67, 0x9D, 0xC6, 0x17, 0x1E, 0x89, 0x4D, 0x61,
	0x82, 0xF7, 0x73, 0x0C, 0x41, 0x86, 0xBC, 0xB8, 0xBA, 0xBC, 0x5D, 0x2D,
	0xB7, 0xB6, 0x9F, 0xB7, 0x59, 0x5D, 0x3B, 0x98, 0x7D, 0xE7, 0xBE, 0x30,
	0x82, 0x01, 0x1E, 0x30, 0x81, 0xC6, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02,
	0x09, 0x04, 0x32, 0x02, 0x59, 0x8B, 0x89, 0x90, 0x00, 0x00, 0x30, 0x0A,
	0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x12,
	0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x07, 0x30,
	0x30, 0x32, 0x41, 0x2D, 0x54, 0x30, 0x30, 0x22, 0x18, 0x0F, 0x32, 0x30,
	0x32, 0x32, 0x30, 0x34, 0x32, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
	0x5A, 0x18, 0x0F, 0x32, 0x30, 0x34, 0x32, 0x30, 0x34, 0x32, 0x33, 0x30,
	0x30, 0x30, 0x30, 0x30, 0x30, 0x5A, 0x30, 0x18, 0x31, 0x16, 0x30, 0x14,
	0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0D, 0x30, 0x30, 0x36, 0x33, 0x38,
	0x36, 0x2D, 0x4D, 0x6F, 0x64, 0x65, 0x6C, 0x35, 0x30, 0x39, 0x30, 0x13,
	0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A,
	0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x22, 0x00, 0x02, 0x8B,
	0x9C, 0xDC, 0x5E, 0x24, 0xF1, 0xE1, 0x39, 0xB2, 0x04, 0x09, 0x4A, 0x47,
	0xB6, 0xB6, 0xFA, 0x30, 0x0D, 0x18, 0x16, 0xBC, 0xB6, 0x53, 0x6D, 0xD8,
	0x7F, 0x8F, 0xFC, 0xC5, 0x43, 0x46, 0xC0, 0xA3, 0x1B, 0x30, 0x19, 0x30,
	0x17, 0x06, 0x05, 0x67, 0x81, 0x14, 0x01, 0x02, 0x01, 0x01, 0xFF, 0x04,
	0x0B, 0x04, 0x09, 0x02, 0x21, 0x18, 0x95, 0x62, 0x64, 0x00, 0x00, 0x02,
	0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02,
	0x03, 0x47, 0x00, 0x30, 0x44, 0x02, 0x20, 0x11, 0xDB, 0xFA, 0xD4, 0x80,
	0xB5, 0xBA, 0x2A, 0x82, 0x09, 0x9C, 0xFB, 0xC9, 0x45, 0xCE, 0xFD, 0xC8,
	0xD2, 0x5E, 0xCB, 0xC5, 0xF1, 0x40, 0xD4, 0x7D, 0xEE, 0xF5, 0x70, 0x08,
	0x5B, 0xA2, 0x3E, 0x02, 0x20, 0x21, 0x07, 0xA9, 0x80, 0x92, 0x2E, 0x19,
	0xED, 0x74, 0x1E, 0xEF, 0xAE, 0x66, 0x10, 0xDE, 0x32, 0x8C, 0x38, 0x68,
	0xB3, 0x65, 0x42, 0xEB, 0x2B, 0x44, 0xD2, 0x4C, 0x87, 0xE3, 0xCC, 0x0C,
	0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#else
const uint8_t qi_ec_priv_key[] = {
	/* Replace with Qi key to be provisioned here */
	0x56, 0xD8, 0x4C, 0x3C, 0xB0, 0x56, 0x36, 0xBD, 0x5E, 0x20, 0xA8, 0x86, 
	0xC4, 0x38, 0x57, 0xFE, 0x19, 0x31, 0x65, 0xBD, 0xC7, 0xAD, 0xF7, 0xC8, 
	0x97, 0x20, 0x1C, 0x02, 0x86, 0xAE, 0xE5, 0x74 
};
const uint8_t qi_ec_pub_key[] = {
	/* Replace with Qi key to be provisioned here */
	0x04, 0x8B, 0x9C, 0xDC, 0x5E, 0x24, 0xF1, 0xE1, 0x39, 0xB2, 0x04, 0x09, 
	0x4A, 0x47, 0xB6, 0xB6, 0xFA, 0x30, 0x0D, 0x18, 0x16, 0xBC, 0xB6, 0x53, 
	0x6D, 0xD8, 0x7F, 0x8F, 0xFC, 0xC5, 0x43, 0x46, 0xC0, 0x89, 0x85, 0xED, 
	0xB7, 0xDD, 0x74, 0x17, 0xA3, 0xC1, 0x2F, 0xCA, 0xF5, 0x3A, 0xB7, 0x41, 
	0x54, 0xD2, 0x47, 0x81, 0x08, 0x30, 0x7C, 0x50, 0xAB, 0x33, 0x77, 0xC2, 
	0x89, 0x94, 0x48, 0x70, 0xC0
};

const uint8_t qi_certificate_chain[] = {
	/* Replace with Qi certificate chain to be provisioned here */
	0x0F, 0xA8, 0xC0, 0xE3, 0x66, 0x31, 0x3B, 0x6E, 0xBC, 0x17, 0xD9, 0xA4,
	0xB3, 0xCA, 0x64, 0x9E, 0xD6, 0x86, 0xEC, 0x98, 0x11, 0x6D, 0x70, 0x8E,
	0xCC, 0x84, 0xEE, 0xC1, 0xE8, 0x09, 0x71, 0x35, 0x02, 0xAC, 0x9F, 0x50,
	0xDD, 0xDD, 0x27, 0xE2, 0xE1, 0x94, 0x27, 0x5C, 0x90, 0x83, 0xCA, 0xCF,
	0xA0, 0xA0, 0x9F, 0x43, 0xBC, 0x99, 0xF2, 0x57, 0x4B, 0xC3, 0xF9, 0xFC,
	0x41, 0x26, 0x53, 0x18, 0x86, 0x3D, 0x30, 0x82, 0x01, 0x45, 0x30, 0x81,
	0xEC, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08, 0x23, 0x70, 0x04, 0x7A,
	0x39, 0xA4, 0x63, 0x6E, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE,
	0x3D, 0x04, 0x03, 0x02, 0x30, 0x12, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03,
	0x55, 0x04, 0x03, 0x0C, 0x07, 0x54, 0x53, 0x54, 0x57, 0x50, 0x43, 0x31,
	0x30, 0x20, 0x17, 0x0D, 0x32, 0x32, 0x30, 0x35, 0x31, 0x31, 0x31, 0x33,
	0x34, 0x36, 0x33, 0x37, 0x5A, 0x18, 0x0F, 0x39, 0x39, 0x39, 0x39, 0x31,
	0x32, 0x33, 0x31, 0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5A, 0x30, 0x12,
	0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x07, 0x30,
	0x30, 0x32, 0x41, 0x2D, 0x54, 0x30, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07,
	0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A, 0x86, 0x48,
	0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x88, 0xAB, 0x25,
	0x70, 0x7E, 0x85, 0x31, 0x5C, 0xD8, 0x04, 0x88, 0x8E, 0x00, 0xAD, 0x9A,
	0xC3, 0xAC, 0x58, 0x75, 0x6D, 0x4E, 0x86, 0xAA, 0x37, 0xB9, 0x69, 0x1B,
	0x3F, 0xBE, 0x0B, 0x1C, 0xC5, 0xCC, 0x96, 0xC8, 0x23, 0x79, 0x70, 0x24,
	0xC5, 0x1A, 0xF9, 0xA9, 0x3A, 0xC6, 0x0E, 0x5E, 0x88, 0xEF, 0x77, 0x03,
	0x69, 0xF4, 0xEE, 0xE1, 0x26, 0x55, 0x33, 0x60, 0x86, 0x25, 0x4A, 0x17,
	0xC8, 0xA3, 0x2A, 0x30, 0x28, 0x30, 0x12, 0x06, 0x03, 0x55, 0x1D, 0x13,
	0x01, 0x01, 0xFF, 0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xFF, 0x02, 0x01,
	0x00, 0x30, 0x12, 0x06, 0x05, 0x67, 0x81, 0x14, 0x01, 0x01, 0x01, 0x01,
	0xFF, 0x04, 0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x01, 0x30, 0x0A, 0x06,
	0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00,
	0x30, 0x45, 0x02, 0x21, 0x00, 0xA6, 0x84, 0x00, 0xD4, 0x38, 0x7D, 0x63,
	0x21, 0x7E, 0xDD, 0xB3, 0x94, 0x68, 0x91, 0xF9, 0x0B, 0x86, 0x2D, 0x6D,
	0x5B, 0x5D, 0x01, 0x84, 0xE4, 0x50, 0x3D, 0x6F, 0x97, 0xB8, 0x18, 0x36,
	0x38, 0x02, 0x20, 0x67, 0x67, 0x9D, 0xC6, 0x17, 0x1E, 0x89, 0x4D, 0x61,
	0x82, 0xF7, 0x73, 0x0C, 0x41, 0x86, 0xBC, 0xB8, 0xBA, 0xBC, 0x5D, 0x2D,
	0xB7, 0xB6, 0x9F, 0xB7, 0x59, 0x5D, 0x3B, 0x98, 0x7D, 0xE7, 0xBE, 0x30,
	0x82, 0x01, 0x3F, 0x30, 0x81, 0xE6, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02,
	0x09, 0x04, 0x32, 0x02, 0x59, 0x8B, 0x89, 0x90, 0x00, 0x00, 0x30, 0x0A,
	0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x12,
	0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x07, 0x30,
	0x30, 0x32, 0x41, 0x2D, 0x54, 0x30, 0x30, 0x22, 0x18, 0x0F, 0x32, 0x30,
	0x32, 0x32, 0x30, 0x34, 0x32, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
	0x5A, 0x18, 0x0F, 0x32, 0x30, 0x34, 0x32, 0x30, 0x34, 0x32, 0x33, 0x30,
	0x30, 0x30, 0x30, 0x30, 0x30, 0x5A, 0x30, 0x18, 0x31, 0x16, 0x30, 0x14,
	0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x0D, 0x30, 0x30, 0x36, 0x33, 0x38,
	0x36, 0x2D, 0x4D, 0x6F, 0x64, 0x65, 0x6C, 0x35, 0x30, 0x59, 0x30, 0x13,
	0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A,
	0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x8B,
	0x9C, 0xDC, 0x5E, 0x24, 0xF1, 0xE1, 0x39, 0xB2, 0x04, 0x09, 0x4A, 0x47,
	0xB6, 0xB6, 0xFA, 0x30, 0x0D, 0x18, 0x16, 0xBC, 0xB6, 0x53, 0x6D, 0xD8,
	0x7F, 0x8F, 0xFC, 0xC5, 0x43, 0x46, 0xC0, 0x89, 0x85, 0xED, 0xB7, 0xDD,
	0x74, 0x17, 0xA3, 0xC1, 0x2F, 0xCA, 0xF5, 0x3A, 0xB7, 0x41, 0x54, 0xD2,
	0x47, 0x81, 0x08, 0x30, 0x7C, 0x50, 0xAB, 0x33, 0x77, 0xC2, 0x89, 0x94,
	0x48, 0x70, 0xC0, 0xA3, 0x1B, 0x30, 0x19, 0x30, 0x17, 0x06, 0x05, 0x67,
	0x81, 0x14, 0x01, 0x02, 0x01, 0x01, 0xFF, 0x04, 0x0B, 0x04, 0x09, 0x02,
	0x21, 0x18, 0x95, 0x62, 0x64, 0x00, 0x00, 0x02, 0x30, 0x0A, 0x06, 0x08,
	0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30,
	0x45, 0x02, 0x21, 0x00, 0xBA, 0xBC, 0xDF, 0x8B, 0x36, 0xA9, 0x1C, 0x15,
	0xBE, 0xE8, 0x49, 0xC8, 0x9D, 0x5B, 0xC9, 0x97, 0x80, 0xC0, 0x58, 0x2D,
	0x5B, 0x5F, 0x50, 0x9A, 0x5B, 0xB3, 0xB6, 0x85, 0x62, 0xAE, 0x67, 0x6C,
	0x02, 0x20, 0x3E, 0x16, 0xA2, 0x01, 0x17, 0xC6, 0xC0, 0xEC, 0x41, 0x9F,
	0xED, 0x98, 0x99, 0x95, 0x83, 0x81, 0x7F, 0x12, 0x98, 0xB1, 0x6B, 0x90,
	0x54, 0x56, 0x31, 0x30, 0xD1, 0x30, 0xDA, 0x23, 0xAC, 0xA7, 0x00, 0x00
};
/* clang-format on */

#endif // USE_COMPRESSED_EC_KEY

size_t qi_ec_priv_key_len       = sizeof(qi_ec_priv_key);
size_t qi_ec_pub_key_len        = sizeof(qi_ec_pub_key);
size_t qi_certificate_chain_len = sizeof(qi_certificate_chain);
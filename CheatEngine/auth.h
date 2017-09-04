#pragma once

typedef enum _CLIENT_TIERS : BYTE {
	ADMIN = 0x00,
	CLIENT = 0x01,
	VIP = 0x02,
	FREEMODE_ENABLED = 0x3
} CLIENT_TIERS;

typedef struct _AuthenticationResponse
{
	unsigned char Tier;
	unsigned char Padding[3];
	unsigned char PacketChecksum[0x10];
} AuthenticationResponse, *pAuthenticationResponse;
typedef struct _AuthenticationRequest
{
	unsigned char CPUKey[0x10];
	unsigned char XEXChecksum[0x10];
	unsigned char XEXVersion;
	unsigned char Padding[3];
	unsigned char PacketChecksum[0x10];
} AuthenticationRequest, *pAuthenticationRequest;

namespace AUTH {
	BOOL Authenticate();
}
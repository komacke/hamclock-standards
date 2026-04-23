// antenna_lookup.h
// Copyright(c) 2026 HamClock Contributors and David Strickland KR8X
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information
#ifndef ANTENNA_LOOKUP_H
#define ANTENNA_LOOKUP_H

#include <cstdint>
#include <string>

struct AntennaInfo {
	std::string path;
	std::string description;
};

// Build the lookup table from ANTENNA_DATA (call once at startup).
void antenna_lookup_init();

// Return pointer to AntennaInfo for the given index (msb*256+lsb),
// or nullptr if not found.
const AntennaInfo* antenna_lookup(uint16_t index);

#endif // ANTENNA_LOOKUP_H
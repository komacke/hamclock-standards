// antenna_lookup.cpp
// Copyright(c) 2026 HamClock Contributors and David Strickland KR8X
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information
#include "antenna_lookup.h"
#include "antenna_data.h"       // generated -- contains ANTENNA_DATA[]

#include <unordered_map>
#include <cstdint>

static std::unordered_map<uint16_t, AntennaInfo> s_table;

void antenna_lookup_init()
{
	s_table.reserve(ANTENNA_DATA_COUNT);
	for (std::size_t i = 0; i < ANTENNA_DATA_COUNT; ++i) {
		const AntennaEntry& e = ANTENNA_DATA[i];
		s_table[e.index] = AntennaInfo{ e.path, e.description };
	}
}

const AntennaInfo* antenna_lookup(uint16_t index)
{
	auto it = s_table.find(index);
	return (it != s_table.end()) ? &it->second : nullptr;
}
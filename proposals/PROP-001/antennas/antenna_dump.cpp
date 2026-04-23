// antenna_dump.cpp
// Copyright(c) 2026 HamClock Contributors and David Strickland KR8X
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information
#include <cstdint>
#include <cstdio>
#include "antenna_lookup.h"
#include "antenna_data.h"

int main()
{
	antenna_lookup_init();

	for (std::size_t i = 0; i < ANTENNA_DATA_COUNT; ++i) {
		const AntennaEntry& e = ANTENNA_DATA[i];
		const AntennaInfo*  info = antenna_lookup(e.index);
		if (info) {
			std::printf("%5u %s\n", e.index, info->description.c_str());
		}
	}
	return 0;
}
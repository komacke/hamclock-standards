// antenna_dump.cpp
// LICENSE_BEGIN
// Copyright (c) 2026 David Strickland KR8X and openhamclock/hamclock-standards
// See https://github.com/openhamclock/hamclock-standards/blob/main/LICENSE.md
//
// Licensed under Apache License 2.0
// https://www.apache.org/licenses/LICENSE-2.0
// LICENSE_END 
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
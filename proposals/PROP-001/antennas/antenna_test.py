# ============================================================
# Static antenna data: (msb, lsb, path, description)
# ============================================================
# LICENSE_BEGIN
# Copyright (c) 2026 David Strickland KR8X and openhamclock/hamclock-standards
# See https://github.com/openhamclock/hamclock-standards/blob/main/LICENSE.md
#
# Licensed under Apache License 2.0
# https://www.apache.org/licenses/LICENSE-2.0
# LICENSE_END 
from antenna_data import ANTENNA_DATA
# ============================================================
# Build lookup dict at runtime: key = msb*256+lsb
# ============================================================
antenna_lookup = {
    msb * 256 + lsb: {'path': path, 'description': desc}
    for msb, lsb, path, desc in ANTENNA_DATA
}

# ============================================================
# Helper
# ============================================================
def lookup_antenna(index: int) -> dict | None:
    return antenna_lookup.get(index)

# ============================================================
# Example usage
# ============================================================
if __name__ == '__main__':
    tests = [
        (0,   0),
        (1,  17),
        (4,   5),
        (2,  17),
        (5,  14),
        (9,  99),   # not found
    ]

    for msb, lsb in tests:
        index = msb * 256 + lsb
        ant = lookup_antenna(index)
        if ant:
            print(f"index={index:5d} (msb={msb}, lsb={lsb:3d}) => path='{ant['path']}'  desc='{ant['description']}'")
        else:
            print(f"index={index:5d} (msb={msb}, lsb={lsb:3d}) => NOT FOUND")

"""
antenna_lookup.py  --  Builds and exposes the runtime lookup dict.
Import this anywhere you need antenna resolution.
"""
# Copyright (C) 2026 Open HamClock Backend (OHB) Contributors and David Strickland KR8X
# License: GNU Affero General Public License v3.0 (AGPLv3)
# See LICENSE file or <https://www.gnu.org/licenses/agpl-3.0.html>
from antenna_data import ANTENNA_DATA

# key = msb*256 + lsb  →  {'path': ..., 'description': ...}
antenna_lookup: dict[int, dict[str, str]] = {
    msb * 256 + lsb: {'path': path, 'description': desc}
    for msb, lsb, path, desc in ANTENNA_DATA
}


def lookup_antenna(index: int) -> dict[str, str] | None:
    """Return {'path', 'description'} for a given msb*256+lsb index, or None."""
    return antenna_lookup.get(index)
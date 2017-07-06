//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "inetveins/physicallayer/ieee80211/bitlevel/Ieee80211OFDMInterleaving.h"

namespace inetveins {

namespace physicallayer {

Ieee80211OFDMInterleaving::Ieee80211OFDMInterleaving(int numberOfCodedBitsPerSymbol, int numberOfCodedBitsPerSubcarrier) :
    numberOfCodedBitsPerSymbol(numberOfCodedBitsPerSymbol),
    numberOfCodedBitsPerSubcarrier(numberOfCodedBitsPerSubcarrier)
{
}

std::ostream& Ieee80211OFDMInterleaving::printToStream(std::ostream& stream, int level) const
{
    stream << "Ieee80211OFDMInterleaving";
    if (level >= PRINT_LEVEL_TRACE)
        stream << ", numberOfCodedBitsPerSymbol = " << numberOfCodedBitsPerSymbol
               << ", numberOfCodedBitsPerSubcarrier = " << numberOfCodedBitsPerSubcarrier;
    return stream;
}

} /* namespace physicallayer */

} /* namespace inetveins */

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

#ifndef __INETVEINS_ISCRAMBLER_H
#define __INETVEINS_ISCRAMBLER_H

#include "inetveins/physicallayer/contract/packetlevel/IPrintableObject.h"
#include "inetveins/common/BitVector.h"
#include "inetveins/common/ShortBitVector.h"

namespace inetveins {

namespace physicallayer {

class INETVEINS_API IScrambling : public IPrintableObject
{
  public:
    const ShortBitVector& getGeneratorPolynomial() const;
    const ShortBitVector& getSeed() const;
};

class INETVEINS_API IScrambler : public IPrintableObject
{
  public:
    virtual BitVector scramble(const BitVector& bits) const = 0;
    virtual BitVector descramble(const BitVector& bits) const = 0;
    virtual const IScrambling *getScrambling() const = 0;
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_ISCRAMBLER_H

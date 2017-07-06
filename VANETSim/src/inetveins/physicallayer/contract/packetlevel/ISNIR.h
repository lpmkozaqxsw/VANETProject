//
// Copyright (C) 2013 OpenSim Ltd.
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

#ifndef __INETVEINS_ISNIR_H
#define __INETVEINS_ISNIR_H

#include "inetveins/physicallayer/contract/packetlevel/INoise.h"
#include "inetveins/physicallayer/contract/packetlevel/IReception.h"

namespace inetveins {

namespace physicallayer {

class INETVEINS_API ISNIR : public IPrintableObject
{
  public:
    virtual const IReception *getReception() const = 0;

    virtual const INoise *getNoise() const = 0;

    virtual double getMin() const = 0;
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_ISNIR_H

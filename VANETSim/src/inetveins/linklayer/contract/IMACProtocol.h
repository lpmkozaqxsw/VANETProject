//
// Copyright (C) 2013 Opensim Ltd.
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

#ifndef __INETVEINS_IMACPROTOCOL_H
#define __INETVEINS_IMACPROTOCOL_H

#include "inetveins/linklayer/contract/IMACProtocolControlInfo.h"

namespace inetveins {

class INETVEINS_API IMACProtocol
{
  public:
    virtual ~IMACProtocol() {}

//    virtual ILinkLayerControlInfo *createControlInfo() = 0;
};

} // namespace inetveins

#endif // ifndef __INETVEINS_IMACPROTOCOL_H

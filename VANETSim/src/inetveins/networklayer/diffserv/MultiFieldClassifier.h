//
// Copyright (C) 2012 Opensim Ltd.
// Author: Tamas Borbely
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

#ifndef __INETVEINS_MULTIFIELDCLASSIFIER_H
#define __INETVEINS_MULTIFIELDCLASSIFIER_H

#include "inetveins/common/INETVEINSDefs.h"

namespace inetveins {

/**
 * Absolute dropper.
 */
class INETVEINS_API MultiFieldClassifier : public cSimpleModule
{
  protected:
    struct Filter
    {
        int gateIndex = -1;

        L3Address srcAddr;
        int srcPrefixLength = 0;
        L3Address destAddr;
        int destPrefixLength = 0;
        int protocol = -1;
        int tos = 0;
        int tosMask = 0;
        int srcPortMin = -1;
        int srcPortMax = -1;
        int destPortMin = -1;
        int destPortMax = -1;

        Filter() {}
    #ifdef WITH_INETVEINS_IPv4
        bool matches(IPv4Datagram *datagram);
    #endif // ifdef WITH_INETVEINS_IPv4
    #ifdef WITH_INETVEINS_IPv6
        bool matches(IPv6Datagram *datagram);
    #endif // ifdef WITH_INETVEINS_IPv6
    };

  protected:
    int numOutGates = 0;
    std::vector<Filter> filters;

    int numRcvd = 0;

    static simsignal_t pkClassSignal;

  protected:
    void addFilter(const Filter& filter);
    void configureFilters(cXMLElement *config);

  public:
    MultiFieldClassifier() {}

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    virtual void initialize(int stage) override;

    virtual void handleMessage(cMessage *msg) override;

    virtual int classifyPacket(cPacket *packet);
};

} // namespace inetveins

#endif // ifndef __INETVEINS_MULTIFIELDCLASSIFIER_H

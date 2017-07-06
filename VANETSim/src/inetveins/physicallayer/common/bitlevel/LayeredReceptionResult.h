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

#ifndef __INETVEINS_LAYEREDRECEPTIONRESULT_H
#define __INETVEINS_LAYEREDRECEPTIONRESULT_H

#include "inetveins/physicallayer/contract/packetlevel/IReceptionResult.h"
#include "inetveins/physicallayer/common/packetlevel/ReceptionResult.h"
#include "inetveins/physicallayer/contract/bitlevel/ISignalPacketModel.h"
#include "inetveins/physicallayer/contract/bitlevel/ISignalBitModel.h"
#include "inetveins/physicallayer/contract/bitlevel/ISignalSymbolModel.h"
#include "inetveins/physicallayer/contract/bitlevel/ISignalSampleModel.h"
#include "inetveins/physicallayer/contract/bitlevel/ISignalAnalogModel.h"

namespace inetveins {

namespace physicallayer {

class INETVEINS_API LayeredReceptionResult : public ReceptionResult
{
  protected:
    const IReceptionPacketModel *packetModel;
    const IReceptionBitModel *bitModel;
    const IReceptionSymbolModel *symbolModel;
    const IReceptionSampleModel *sampleModel;
    const IReceptionAnalogModel *analogModel;

  public:
    LayeredReceptionResult(const IReception *reception, const std::vector<const IReceptionDecision *> *decisions, const ReceptionIndication *indication, const IReceptionPacketModel *packetModel, const IReceptionBitModel *bitModel, const IReceptionSymbolModel *symbolModel, const IReceptionSampleModel *sampleModel, const IReceptionAnalogModel *analogModel);
    virtual ~LayeredReceptionResult();

    virtual std::ostream& printToStream(std::ostream& stream, int level) const override;

    virtual const IReceptionPacketModel *getPacketModel() const { return packetModel; }
    virtual const IReceptionBitModel *getBitModel() const { return bitModel; }
    virtual const IReceptionSymbolModel *getSymbolModel() const { return symbolModel; }
    virtual const IReceptionSampleModel *getSampleModel() const { return sampleModel; }
    virtual const IReceptionAnalogModel *getAnalogModel() const { return analogModel; }

    virtual const cPacket *getPhyFrame() const override;
    virtual const cPacket *getMacFrame() const override;
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_LAYEREDRECEPTIONRESULT_H

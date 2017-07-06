//
// Copyright (c) 2010 The Boeing Company
// Copyright (C) 2015 OpenSim Ltd.
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
// Author: Gary Pei <guangyu.pei@boeing.com>
//

#ifndef __INETVEINS_IEEE80211NISTERRORMODEL_H
#define __INETVEINS_IEEE80211NISTERRORMODEL_H

#include "inetveins/physicallayer/ieee80211/packetlevel/errormodel/Ieee80211ErrorModelBase.h"
#include "inetveins/physicallayer/ieee80211/packetlevel/errormodel/dsss-error-rate-model.h"
#include "inetveins/physicallayer/common/bitlevel/ConvolutionalCode.h"
#include "inetveins/physicallayer/base/packetlevel/APSKModulationBase.h"

namespace inetveins {

namespace physicallayer {

/**
 * A model for the error rate for different modulations.  For OFDM modulation,
 * the model description and validation can be found in
 * http://www.nsnam.org/~pei/80211ofdm.pdf.  For DSSS modulations (802.11b),
 * the model uses the DsssErrorRateModel.
 */
class INETVEINS_API Ieee80211NistErrorModel : public Ieee80211ErrorModelBase
{
  protected:
    double calculatePe(double p, uint32_t bValue) const;
    double getBpskBer(double snr) const;
    double getQpskBer(double snr) const;
    double get16QamBer(double snr) const;
    double get64QamBer(double snr) const;
    double getFecBpskBer(double snr, double nbits, uint32_t bValue) const;
    double getFecQpskBer(double snr, double nbits, uint32_t bValue) const;
    double getFec16QamBer(double snr, uint32_t nbits, uint32_t bValue) const;
    double getFec64QamBer(double snr, uint32_t nbits, uint32_t bValue) const;

    virtual double getOFDMAndERPOFDMChunkSuccessRate(const APSKModulationBase *subcarrierModulation, const ConvolutionalCode *convolutionalCode, unsigned int bitLength, double snr) const;
    virtual double getDSSSAndHrDSSSChunkSuccessRate(bps bitrate, unsigned int bitLength, double snr) const;

    virtual double getHeaderSuccessRate(const IIeee80211Mode *mode, unsigned int headerBitLength, double snr) const override;
    virtual double getDataSuccessRate(const IIeee80211Mode *mode, unsigned int bitLength, double snr) const override;

  public:
    virtual std::ostream& printToStream(std::ostream& stream, int level) const override { return stream << "Ieee80211NistErrorModel"; }
};

} // namespace physicallayer

} // namespace inetveins

#endif // ifndef __INETVEINS_NISTERRORRATEMODEL_H

/***************************************************************************
                          reports.h  -  description
                             -------------------
    begin                : Tue Oct 23 2001
    copyright            : (C) 2001 by Matthias Oppitz
    email                : Matthias.Oppitz@gmx.de
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/

/** \file reports.h
 * This file declares the classes SenderReport and ReceptionReport as used
 * in RTCPSenderReportPacket and RTCPReceiverReportPacket.
 */

#ifndef __INETVEINS_REPORTS_H
#define __INETVEINS_REPORTS_H

#include "inetveins/common/INETVEINSDefs.h"
#include "inetveins/transportlayer/rtp/reports_m.h"

namespace inetveins {

namespace rtp {

/**
 * The class SenderReport represents an RTP sender report as contained
 * in an RTCPSenderReportPacket.
 */
class INETVEINS_API SenderReport : public SenderReport_Base
{
  public:
    SenderReport() : SenderReport_Base() {}
    SenderReport(const SenderReport& other) : SenderReport_Base(other) {}
    SenderReport& operator=(const SenderReport& other) { SenderReport_Base::operator=(other); return *this; }
    virtual SenderReport *dup() const override { return new SenderReport(*this); }
    // ADD CODE HERE to redefine and implement pure virtual functions from SenderReport_Base

  public:
    /**
     * Writes a short info about this SenderReport into the given string.
     */
    virtual std::string info() const override;

    /**
     * Writes a longer info about this SenderReport into the given stream.
     */
    virtual void dump(std::ostream& os) const;
};

/**
 * The class ReceptionReport represents an RTP receiver report stored
 * in an RTPSenderReportPacket or RTPReceiverReport.
 */
class INETVEINS_API ReceptionReport : public ReceptionReport_Base
{
  public:
    ReceptionReport() : ReceptionReport_Base() {}
    ReceptionReport(const ReceptionReport& other) : ReceptionReport_Base(other) {}
    ReceptionReport& operator=(const ReceptionReport& other) { ReceptionReport_Base::operator=(other); return *this; }
    virtual ReceptionReport *dup() const override { return new ReceptionReport(*this); }
    // ADD CODE HERE to redefine and implement pure virtual functions from ReceptionReport_Base

  public:
    /**
     * Writes a short info about this ReceptionReport into the given string.
     */
    virtual std::string info() const override;

    /**
     * Writes a longer info about this ReceptionReport into the given stream.
     */
    virtual void dump(std::ostream& os) const;
};

} // namespace rtp

} // namespace inetveins

#endif // ifndef __INETVEINS_REPORTS_H

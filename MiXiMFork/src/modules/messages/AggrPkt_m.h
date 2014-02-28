//
// Generated file, do not edit! Created by opp_msgc 4.4 from messages/AggrPkt.msg.
//

#ifndef _AGGRPKT_M_H_
#define _AGGRPKT_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "ApplPkt_m.h"
typedef ApplPkt* pApplPkt;
// }}



/**
 * Class generated from <tt>messages/AggrPkt.msg</tt> by opp_msgc.
 * <pre>
 * message AggrPkt extends cPacket  {
 *   @customize(true);
 *   abstract pApplPkt storedPackets[];    
 * };
 * </pre>
 *
 * AggrPkt_Base is only useful if it gets subclassed, and AggrPkt is derived from it.
 * The minimum code to be written for AggrPkt is the following:
 *
 * <pre>
 * class AggrPkt : public AggrPkt_Base
 * {
 *   private:
 *     void copy(const AggrPkt& other) { ... }

 *   public:
 *     AggrPkt(const char *name=NULL, int kind=0) : AggrPkt_Base(name,kind) {}
 *     AggrPkt(const AggrPkt& other) : AggrPkt_Base(other) {copy(other);}
 *     AggrPkt& operator=(const AggrPkt& other) {if (this==&other) return *this; AggrPkt_Base::operator=(other); copy(other); return *this;}
 *     virtual AggrPkt *dup() const {return new AggrPkt(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from AggrPkt_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(AggrPkt);
 * </pre>
 */
class AggrPkt_Base : public ::cPacket
{
  protected:

  private:
    void copy(const AggrPkt_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AggrPkt_Base&);
    // make constructors protected to avoid instantiation
    AggrPkt_Base(const char *name=NULL, int kind=0);
    AggrPkt_Base(const AggrPkt_Base& other);
    // make assignment operator protected to force the user override it
    AggrPkt_Base& operator=(const AggrPkt_Base& other);

  public:
    virtual ~AggrPkt_Base();
    virtual AggrPkt_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class AggrPkt");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setStoredPacketsArraySize(unsigned int size) = 0;
    virtual unsigned int getStoredPacketsArraySize() const = 0;
    virtual pApplPkt& getStoredPackets(unsigned int k) = 0;
    virtual const pApplPkt& getStoredPackets(unsigned int k) const {return const_cast<AggrPkt_Base*>(this)->getStoredPackets(k);}
    virtual void setStoredPackets(unsigned int k, const pApplPkt& storedPackets) = 0;
};


#endif // _AGGRPKT_M_H_

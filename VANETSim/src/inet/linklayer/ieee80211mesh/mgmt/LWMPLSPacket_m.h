//
// Generated file, do not edit! Created by nedtool 4.6 from linklayer/ieee80211mesh/mgmt/LWMPLSPacket.msg.
//

#ifndef _INET__IEEE80211_LWMPLSPACKET_M_H_
#define _INET__IEEE80211_LWMPLSPACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "inet/linklayer/common/MACAddress.h"
// }}


namespace inet {
namespace ieee80211 {

/**
 * Enum generated from <tt>linklayer/ieee80211mesh/mgmt/LWMPLSPacket.msg:31</tt> by nedtool.
 * <pre>
 * enum LwmplsType
 * {
 * 
 *     WMPLS_NORMAL = 0;
 *     WMPLS_BEGIN = 1;
 *     WMPLS_REFRES = 2;
 *     WMPLS_END = 3;
 *     WMPLS_BREAK = 4;
 *     WMPLS_NOTFOUND = 5;
 *     WMPLS_ACK = 6;
 *     WMPLS_ADITIONAL = 7;
 *     WMPLS_BEGIN_W_ROUTE = 8;
 *     WMPLS_SEND = 9;
 *     WMPLS_BROADCAST = 10;
 *     // Use the mac addess like labels
 *     WMPLS_MACBASEDLABEL_BEGIN = 11;
 *     WMPLS_MACBASEDLABEL_BEGIN_W_ROUTE = 12;
 *     WMPLS_ANNOUNCE_GATEWAY = 14;
 *     WMPLS_REQUEST_GATEWAY = 15;
 * }
 * </pre>
 */
enum LwmplsType {
    WMPLS_NORMAL = 0,
    WMPLS_BEGIN = 1,
    WMPLS_REFRES = 2,
    WMPLS_END = 3,
    WMPLS_BREAK = 4,
    WMPLS_NOTFOUND = 5,
    WMPLS_ACK = 6,
    WMPLS_ADITIONAL = 7,
    WMPLS_BEGIN_W_ROUTE = 8,
    WMPLS_SEND = 9,
    WMPLS_BROADCAST = 10,
    WMPLS_MACBASEDLABEL_BEGIN = 11,
    WMPLS_MACBASEDLABEL_BEGIN_W_ROUTE = 12,
    WMPLS_ANNOUNCE_GATEWAY = 14,
    WMPLS_REQUEST_GATEWAY = 15
};

/**
 * Class generated from <tt>linklayer/ieee80211mesh/mgmt/LWMPLSPacket.msg:58</tt> by nedtool.
 * <pre>
 * //
 * // Capability Information field format. This field is not used
 * // by the model (and is omitted from management frame formats too),
 * // because its fields are related to features not supported by this model
 * // (PCF, privacy, and beacons in ad-hoc mode). It is only provided here
 * // for completeness.
 * //
 * packet LWMPLSPacket
 * {
 *     int label;// 20 bits
 *     int labelReturn;
 *     int type @enum(LwmplsType); // 4 bits
 *     bool nextHeader = false; //1 bit
 *              // 7 bits route long
 *     unsigned int counter;
 *     byteLength = 6;
 *     MACAddress source; // This fields are in the 4 address I'm include here for simplicity
 *     MACAddress dest;   //
 *     short TTL;
 *     MACAddress vectorAddress[];
 * }
 * </pre>
 */
class LWMPLSPacket : public ::cPacket
{
  protected:
    int label_var;
    int labelReturn_var;
    int type_var;
    bool nextHeader_var;
    unsigned int counter_var;
    MACAddress source_var;
    MACAddress dest_var;
    short TTL_var;
    MACAddress *vectorAddress_var; // array ptr
    unsigned int vectorAddress_arraysize;

  private:
    void copy(const LWMPLSPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LWMPLSPacket&);

  public:
    LWMPLSPacket(const char *name=NULL, int kind=0);
    LWMPLSPacket(const LWMPLSPacket& other);
    virtual ~LWMPLSPacket();
    LWMPLSPacket& operator=(const LWMPLSPacket& other);
    virtual LWMPLSPacket *dup() const {return new LWMPLSPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getLabel() const;
    virtual void setLabel(int label);
    virtual int getLabelReturn() const;
    virtual void setLabelReturn(int labelReturn);
    virtual int getType() const;
    virtual void setType(int type);
    virtual bool getNextHeader() const;
    virtual void setNextHeader(bool nextHeader);
    virtual unsigned int getCounter() const;
    virtual void setCounter(unsigned int counter);
    virtual MACAddress& getSource();
    virtual const MACAddress& getSource() const {return const_cast<LWMPLSPacket*>(this)->getSource();}
    virtual void setSource(const MACAddress& source);
    virtual MACAddress& getDest();
    virtual const MACAddress& getDest() const {return const_cast<LWMPLSPacket*>(this)->getDest();}
    virtual void setDest(const MACAddress& dest);
    virtual short getTTL() const;
    virtual void setTTL(short TTL);
    virtual void setVectorAddressArraySize(unsigned int size);
    virtual unsigned int getVectorAddressArraySize() const;
    virtual MACAddress& getVectorAddress(unsigned int k);
    virtual const MACAddress& getVectorAddress(unsigned int k) const {return const_cast<LWMPLSPacket*>(this)->getVectorAddress(k);}
    virtual void setVectorAddress(unsigned int k, const MACAddress& vectorAddress);
};

inline void doPacking(cCommBuffer *b, LWMPLSPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LWMPLSPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>linklayer/ieee80211mesh/mgmt/LWMPLSPacket.msg:73</tt> by nedtool.
 * <pre>
 * packet LWMPLSControl extends LWMPLSPacket
 * {
 *     byteLength = 12;
 *     unsigned char gateAddressPtr[];
 *     unsigned char assocAddressPtr[];
 * }
 * </pre>
 */
class LWMPLSControl : public ::inet::ieee80211::LWMPLSPacket
{
  protected:
    unsigned char *gateAddressPtr_var; // array ptr
    unsigned int gateAddressPtr_arraysize;
    unsigned char *assocAddressPtr_var; // array ptr
    unsigned int assocAddressPtr_arraysize;

  private:
    void copy(const LWMPLSControl& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LWMPLSControl&);

  public:
    LWMPLSControl(const char *name=NULL, int kind=0);
    LWMPLSControl(const LWMPLSControl& other);
    virtual ~LWMPLSControl();
    LWMPLSControl& operator=(const LWMPLSControl& other);
    virtual LWMPLSControl *dup() const {return new LWMPLSControl(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setGateAddressPtrArraySize(unsigned int size);
    virtual unsigned int getGateAddressPtrArraySize() const;
    virtual unsigned char getGateAddressPtr(unsigned int k) const;
    virtual void setGateAddressPtr(unsigned int k, unsigned char gateAddressPtr);
    virtual void setAssocAddressPtrArraySize(unsigned int size);
    virtual unsigned int getAssocAddressPtrArraySize() const;
    virtual unsigned char getAssocAddressPtr(unsigned int k) const;
    virtual void setAssocAddressPtr(unsigned int k, unsigned char assocAddressPtr);
};

inline void doPacking(cCommBuffer *b, LWMPLSControl& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, LWMPLSControl& obj) {obj.parsimUnpack(b);}

} // namespace ieee80211
} // namespace inet

#endif // ifndef _INET__IEEE80211_LWMPLSPACKET_M_H_

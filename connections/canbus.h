#ifndef CANBus_H
#define CANBus_H
#include <QDataStream>
#include "can_structs.h"

class CANBus
{
    int speed;
    bool listenOnly;
    bool singleWire;
    bool active; //is this bus turned on?
    bool canFD;
    int dataRate;

    friend QDataStream& operator<<(QDataStream & pStream, const CANBus& pCanBus);
    friend QDataStream& operator>>(QDataStream & pStream, CANBus& pCanBus);

	bool canFDCapable;		// does this CANBUS support CANFD?
	bool r120Switchable;	// does this CANBUS support programmable switching 120R termination resistor?
	bool r120;				// doest 120R terminator is ON?

public:
    CANBus();

    bool operator==(const CANBus&) const;

    void setSpeed(int); // new speed
    void setListenOnly(bool); //bool for whether to only listen
    void setSingleWire(bool); //bool for whether to use single wire mode
    void setActive(bool); //whether this bus should be enabled or not.
    void setCanFD(bool); // enable or disable CANFD support
    void setDataRate(int newSpeed);

    int getSpeed() const;
    int getDataRate() const;
    bool isListenOnly() const;
    bool isSingleWire() const;
    bool isActive() const;
    bool isCanFD() const;

	void setCanFDCapable(bool val);
	void setR120Swithcable(bool val);
	void setR120(bool val);

	bool isCanFDCapable(void) const;
	bool isR120Switchable(void) const;
	bool isR120On(void) const;
};

QDataStream& operator<<(QDataStream & pStream, const CANBus& pCanBus);
QDataStream& operator>>(QDataStream & pStream, CANBus& pCanBus);

Q_DECLARE_METATYPE(CANBus);

struct BusData {
    CANBus             mBus;
    bool               mConfigured = {};
    QVector<CANFltObserver>    mTargettedFrames;
};

#endif // CANBus_H

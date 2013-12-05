#ifndef  _SIM_CARD_INFO_H_
#define  _SIM_CARD_INFO_H_

class SIMCardInfo
{
public:
	SIMCardInfo();
	~SIMCardInfo();

	
	static const char* getPhoneNumber();

	static const char* getProviderName();

};

#endif
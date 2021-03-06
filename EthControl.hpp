#ifndef EthControl_h
#define EthControl_h

// CONFIG FOR WAVESHARE LAN8720 WITH POWER EN MOD BY SAUTTER
//#define ETH_CLK_MODE    ETH_CLOCK_GPIO0_IN
//#define ETH_POWER_PIN   17
//#define ETH_TYPE        ETH_PHY_LAN8720
//#define ETH_ADDR        1
//#define ETH_MDC_PIN     23
//#define ETH_MDIO_PIN    18

#include "debug.hpp"
#include <iomanip>
#include <sstream>
#include <ETH.h>
#include <WiFiClient.h>
#include <Preferences.h>
#include <IPAddress.h>

typedef enum eth_state_t {
    ETH_STARTED,
    ETH_CONNECTED,
    ETH_GOT_IP,
    ETH_DISCONNECTED,
    ETH_STOPPED
};

class EthControl {
	public:
        EthControl(){};
                
        void begin(String hostname = "BasecampDevice");
        bool config(IPAddress ip, IPAddress gateway, IPAddress subnet, IPAddress dns1, IPAddress dns2 );
        bool config(const String& ip, const String& gateway, const String& subnet, const String& dns1, const String& dns2 );
        bool connected();
        IPAddress getIP();
        String getMac();
        static eth_state_t status();

        static void WiFiEvent(WiFiEvent_t event);
    private:
        static eth_state_t _state;
};

#endif //EthControl_h

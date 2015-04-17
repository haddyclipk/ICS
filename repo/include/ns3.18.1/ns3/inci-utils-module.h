
#ifdef NS3_MODULE_COMPILATION
# error "Do not include ns3 module aggregator headers from other modules; these are meant only for end user scripts."
#endif

#ifndef NS3_MODULE_INCI_UTILS
    

// Module headers:
#include "comm-module-installer.h"
#include "configuration-manager-xml.h"
#include "dvbh-bs-installer.h"
#include "dvbh-installer.h"
#include "dvbh-vehicle-installer.h"
#include "iTETRISNodeManager.h"
#include "inci-packet-list.h"
#include "inci-packet.h"
#include "ip-interface-list.h"
#include "itetris-network-transport-installer.h"
#include "itetris-types.h"
#include "lte-bs-installer.h"
#include "lte-installer.h"
#include "lte-vehicle-installer.h"
#include "mobility-model-installer.h"
#include "packet-manager.h"
#include "tmc-installer.h"
#include "umts-bs-installer.h"
#include "umts-installer.h"
#include "umts-vehicle-installer.h"
#include "wave-installer.h"
#include "wave-rsu-installer.h"
#include "wave-vehicle-installer.h"
#include "wifi-bs-installer.h"
#include "wifi-installer.h"
#include "wifi-ip-installer.h"
#include "wifi-vehicle-installer.h"
#include "wimax-bs-installer.h"
#include "wimax-installer.h"
#include "wimax-vehicle-installer.h"
#endif

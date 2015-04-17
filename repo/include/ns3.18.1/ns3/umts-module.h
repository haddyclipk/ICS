
#ifdef NS3_MODULE_COMPILATION
# error "Do not include ns3 module aggregator headers from other modules; these are meant only for end user scripts."
#endif

#ifndef NS3_MODULE_UMTS
    

// Module headers:
#include "blerTable.h"
#include "controlpacket.h"
#include "cost231_model.h"
#include "ovsfTrees.h"
#include "umts-basestation-manager.h"
#include "umts-channel.h"
#include "umts-helper.h"
#include "umts-ifq-layer.h"
#include "umts-mac-header.h"
#include "umts-mac-layer.h"
#include "umts-manager.h"
#include "umts-net-device.h"
#include "umts-phy-layer-bs.h"
#include "umts-phy-layer-ue.h"
#include "umts-queue.h"
#include "umts-rlc-ack-header.h"
#include "umts-rlc-am-header.h"
#include "umts-rlc-layer.h"
#include "umts-rlc-um-header.h"
#include "umts-rrc-layer-bs.h"
#include "umts-rrc-layer-ue.h"
#include "umts-tags.h"
#include "umts-userequipment-manager.h"
#endif

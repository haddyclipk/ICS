
#ifdef NS3_MODULE_COMPILATION
# error "Do not include ns3 module aggregator headers from other modules; these are meant only for end user scripts."
#endif

#ifndef NS3_MODULE_VANET_HIGHWAY
    

// Module headers:
#include "Geometry.h"
#include "Highway.h"
#include "HighwayConnectionXml.h"
#include "HighwayManager.h"
#include "HighwayProject.h"
#include "HighwayProjectXml.h"
#include "HighwayXml.h"
#include "IdGenerator.h"
#include "Intersection.h"
#include "LaneChange.h"
#include "Model.h"
#include "Obstacle.h"
#include "TrafficLightGenerator.h"
#include "TrafficLightGeneratorXml.h"
#include "TrafficPointXml.h"
#include "Vehicle.h"
#include "VehicleGenerator.h"
#include "VehicleGeneratorXml.h"
#include "WifiConfigurationXml.h"
#include "tinystr.h"
#include "tinyxml.h"
#endif

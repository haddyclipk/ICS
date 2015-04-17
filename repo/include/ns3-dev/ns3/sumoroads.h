/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 FT R&D
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Guillaume Remy <guillaume1.remy@orange-ftgroup.com>
 */

#ifndef _ROADS_
#define _ROADS_

#include "ns3/callback.h"
#include "ns3/ptr.h"
#include "ns3/object.h"
#include "ns3/point-to-point-module.h"
#include "ns3/epc-helper.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/random-variable.h"
#include "ns3/vector.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/lte-helper.h"
#include "ns3/wifi-helper.h"
#include "sumovehicle.h"
#include "ns3/lte-module.h"
#include <list>

namespace ns3 {
/**
* Roads is a place holder for Vehicles and manages each step of the vehicles mobility.
*
* A Roads object represents the roads topology: it holds the vehicles and is
* responsible for the management of the eNodeB and the WiFi and LTE prameters
* used in the VANET. The eNodeB is placed in the center of the map.
*/
class Roads : public ns3::Object
{
public:
  static TypeId GetTypeId ();

  Roads ();
  Roads (uint width, uint height, float simTime);
  ~Roads ();

  /**
  * Starts the highway.
  */
  void Start ();

  /**
  * Stops the highway. Therefore no vehicles mobility after.
  */
  void Stop ();

  /** Sets the width of the map.
   * @param width Map width
   */
  void SetWidth (uint width)
  {
    m_mapWidth = width;
  }

  /** Gets the width of the map.
   * @return Map width
   */
  uint GetWidth ()
  {
    return m_mapWidth;
  }

  /** Sets the height of the map.
   * @param height Map height
   */
  void SetHeight (uint height)
  {
    m_mapHeight = height;
  }
  
  /** Gets the height of the map.
   * @return Map height
   */
  uint GetHeight ()
  {
    return m_mapHeight;
  }

  /**
  * This function will add the vehicle on the Roads.
  * @param vehicle Vehicle to add
  */
  void AddVehicle (Ptr<Vehicle> vehicle);
  
  /**
  * This function will add the global mobility to all nodes.
  * 
  */
  void AddGlobalVehicleMobility ();

  /** This returns the EnbNetDevice cointaner for eNodeBs.
   * @return A EnbNetDevice cointaner
   */
  NetDeviceContainer GetENBNetDeviceC ()
  {
    return m_enbC;
  }

  /** This returns the Ipv4AddressHelper for WiFi interfaces.
   * @return A reference to the Ipv4AddressHelper
   */
  Ipv4AddressHelper& GetWifiAddressHelper ()
  {
    return m_ipv4Waddr;
  }
  
  /** This returns the Ipv4Address for Remote host.
   * @return A reference to the Ipv4Address
   */
  Ipv4Address& GetLteIpAddress()
  {
    return m_remoteHostAddr;
  }

  /** This returns the LteHelper for LTE interfaces.
   * @returns A reference to the LteHelper used by the eNodeB.
   */
  LteHelper& GetLteHelper ()
  {
    return m_lteHelper;
  }

  /** This returns the WifiHelper for WiFi interfaces.
   * @returns A reference to the WifiHelper used to initialize vehicles.
   */
  WifiHelper& GetWifiHelper ()
  {
    return m_wifiHelper;
  }

  /** This returns the YansWifiPhyHelper for WiFi interfaces.
   * @returns A reference to the YansWifiPhyHelper used to initialize vehicles.
   */
  YansWifiPhyHelper& GetWifiPhyHelper ()
  {
    return m_wifiPhyHelper;
  }

  /** This returns the NqosWifiMacHelper for WiFi interfaces.
   * @returns A reference to the NqosWifiMacHelper used to initialize vehicles.
   */
  NqosWifiMacHelper& GetWifiMacHelper ()
  {
    return m_wifiMacHelper;
  }

  /** Runs one mobility step.
   */
  void Step (void);

  /** Returns the Control Vehicle callback.
   */
  Callback<void, Ptr<Vehicle> > GetControlVehicleCallback ()
  {
    return m_controlVehicle;
  }

  /** Sets the Control Vehicle callback.
   */
  void SetControlVehicleCallback (Callback<void, Ptr<Vehicle> > controlVehicle);

  /** Returns the Init Vehicles callback.
   */
  Callback<bool, int&> GetInitVehiclesCallback ()
  {
    return m_initVehicles;
  }
  
  /** Sets the Simulation Time for server app.
  * @param Simulation time
  */
  void SetSimTime (float fSimTime)
  {
	  m_simTime = fSimTime;
  }
  
  /** Gets the Simulation Time for server app.
   * @return Simulation time
   */
  float GetSimTime ()
  {
	  return m_simTime;
  }

  /** Sets the Init Vehicles callback.
   */
  void SetInitVehiclesCallback (Callback<bool, int&> initVehicles);
  
  
  /** Sets the tracefile.
  * @param the tracefile
  */
  void SetTraceFile (std::string traceFile);
  
  /** Sets the GlobalLte.
  *
  */
  void SetupGlobalLte ();

private:
  /** Initializes the Roads and raises the event InitVehicles.
   */
  void InitRoads ();

  /** Executed each step interval, this function raises the event ControlVehicle
   * for all vehicles on the Roads
   */
  void Control (void);

  /** This function prints all vehicles circulating on the roads.
   * @param os The output stream to which we print the vehicles
   */
  void PrintVehicles (std::ostream& os = std::cout);

  /**
   * An event called for each step of mobility. It allows to act on the vehicle's
   * mobility.
   */
  Callback<void, Ptr<Vehicle> > m_controlVehicle;
  /**
  * An event called at Roads initialization (InitRoads).
  * It gives the Roads and the current Vehicle Id value.
  */
  Callback<bool, int&> m_initVehicles;
  std::list<Ptr<Vehicle> > m_vehicles;          /**< List of vehicles on the roads.*/
  double m_dt;                                  /**< The mobility step interval.*/
  int m_vehicleId;                              /**< Current ehicle id which will be assigned to next vehicle.*/
  bool m_stopped;                               /**< true if the Roads object is stopped.*/
  uint m_mapWidth;                                /**< Map width, in meters.*/
  uint m_mapHeight;                               /**< Map height, in meters.*/
  Ipv4AddressHelper m_ipv4Waddr;                /**< AddressHelper used to assign WiFi interfaces.*/
  Ipv4Address m_remoteHostAddr;
  NetDeviceContainer m_enbC;                   /**< eNode NetDeviceCointaner.*/
  LteHelper m_lteHelper;                        /**< The LTEHelper used to setup vehicles and eNodeB.*/
  WifiHelper m_wifiHelper;                      /**< The WiFiHelper used to setup vehicles.*/
  NqosWifiMacHelper m_wifiMacHelper;            /**< The wifi mac helper used to setup vehicles WiFi.*/
  YansWifiPhyHelper m_wifiPhyHelper;            /**< The wifi phy helper used to setup vehicles WiFi.*/
  YansWifiChannelHelper m_wifiChannelHelper;    /**< The wifi channel helper used to setup vehicles Wifi.*/
  float m_simTime; 								/**< Sim Time. */
  Ptr<YansWifiChannel> m_wifiChannel;           /**< The common Wifi Channel created by Roads and shared by the vehicles.*/
  std::string m_traceFile;
};
}
#endif // _ROADS_

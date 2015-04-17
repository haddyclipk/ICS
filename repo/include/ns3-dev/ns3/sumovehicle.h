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
 * Modified by: Guillaume Remy <guillaume1.remy@orange-ftgroup.com>
 */

#ifndef _VEHICLE_
#define _VEHICLE_

#include "ns3/ptr.h"
#include "ns3/object.h"
#include "ns3/vector.h"
#include "ns3/ptr.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/waypoint-mobility-model.h"
#include "ns3/wifi-module.h"
#include "ns3/lte-module.h"

namespace ns3 {

/** Vehicle is a mobile Object which follows the traces given in a file
*/
class Vehicle : public ns3::Object
{
public:
  static TypeId GetTypeId (void);

  Vehicle ();

  ~Vehicle ();

  /** Initialize the vehicle's mobility model in parsing the traces file.
   * @param file The traces file to use (the format has to be the same as
   * VanetMobiSim format.
   */
  void InitMobilityModel (std::string file = std::string ("mobility.tr"));

  /** Setup the vehicle's WiFi interface.
   * @param wifi The WifiHelper to be used.
   * @param phy The YansWifiPhyHelper.
   * @param mac The NqosWifiMacHelper.
   * @param address The address helper used to initialize WiFi interface.
   */
  void SetupWifi (WifiHelper& wifi, YansWifiPhyHelper& phy,
                  NqosWifiMacHelper& mac, Ipv4AddressHelper& address);

  /** Setup the vehicle's LTE interface.
   * @param lte the LteHelper to be used.
   * @param enb  the eNodeB interface.
   * @param address  the address helper used to initialize LTE interface.
   */
  void SetupLte (LteHelper& lte, Ptr<LteEnbNetDevice> enb, Ipv4Address& remoteHostAddr);

  /** Rturns the vehicle's ID.
   * @returns the Vehicle's ID.
   */
  int GetVehicleId () const;

  /** Sets the vehicle's ID.
   * @param value Vehicle ID.
   */
  void SetVehicleId (int value);

  /** Returns the position of the vehicle.
   */
  Vector GetPosition () const;

  /** Returns the length of the vehicle.
   * @returns the length of the Vehicle.
   */
  double GetLength () const;

  /** Sets the length of the vehicle.
   * @param value the length of the Vehicle.
   */
  void SetLength (double value);

  /** Returns the width of the vehicle.
   * @returns the width of the Vehicle.
   */
  double GetWidth () const;
  
  /** Returns the node linked to the vehicle.
  * @returns the node linked to of the Vehicle.
  */
  Ptr<Node> GetNode ();

  /** Sets the width of the vehicle.
   * @param value the width of the Vehicle.
   */
  void SetWidth (double value);

  /** Returns the current velocity of the vehicle.
   * @returns the current velocity of the Vehicle.
   */
  double GetVelocity () const;
  
  /** Sets the LteDevice.
  * @param LteDevice
  */
  void SetLteDevice (Ptr<LteUeNetDevice> deviceLte)
  {
	  m_deviceLte = deviceLte;
  }
  
  /** Gets the LteDevice.
   * @return LteDevice
   */
  Ptr<LteUeNetDevice> GetLteDevice ()
  {
	  return m_deviceLte;
  }
  
  /** Returns the state of HandOver.
   * @returns the state of HandOver.
   */
  bool GetHandOver ()
  {
	  return m_bHand;
  }

  /** Sets the length of the vehicle.
   * @param value the length of the Vehicle.
   */
  void SetHandOver (bool bValue)
  {
	  m_bHand = bValue;
  }


  bool IsEquipped; /**< True when vehicle is equipped with radio interfaces.*/

private:
  double m_length;              /**< Vehicle's length.*/
  double m_width;               /**< Vehicle's width.*/
  int m_vehicleId;              /**< Vehicle's ID.*/
  bool m_bHand;                 /**< HandOverExecuted*/
  Ptr<Node> m_node;             /**< Node which corresponds to the vehicle.*/
  Ptr<NetDevice> m_device;      /**< WiFi interface of the vehicle.*/
  Ptr<LteUeNetDevice> m_deviceLte; /**< LTE interface of the vahicle.*/
};
}
#endif // _VEHICLE_

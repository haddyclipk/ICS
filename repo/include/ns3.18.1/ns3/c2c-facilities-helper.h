// iTetris INTECS
/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009-2010, Uwicore Laboratory (www.uwicore.umh.es),
 * University Miguel Hernandez, EU FP7 iTETRIS project
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
 * Author:  Michele Rondinone <mrondinone@umh.es>,
 */

#ifndef C2C_FACILITIES_HELPER_H
#define C2C_FACILITIES_HELPER_H

#include "ns3/node-container.h"
#include "ns3/CAMmanage-helper.h"
#include "ns3/service-list-helper.h"
#include "ns3/service-list.h"
#include "ns3/net-device-container.h"
#include "ns3/packet.h"
#include "ns3/ptr.h"
#include "ns3/object-factory.h"

namespace ns3 {

class Node;
class ServiceListHelper;                     
class iTETRISns3Facilities;    

/**
 * This helper is used to create and aggregate the functionalities of the iTETRIS ns-3 Facilities layer to existing Nodes.
 */
class C2CFacilitiesHelper
{
public:
  /**
   * Create a new C2CFacilitiesHelper which implements some specific
   * service helpers by default and include them in its private list
   * of service helpers.
   */
  C2CFacilitiesHelper(void);

  /**
   * Destroy the FacilitiesHelper
   */
  virtual ~C2CFacilitiesHelper(void);


  /**
   * \param servicelisthelper a new service list helper
   *
   * Set the service list helper to Install all the needed applications on a node. 
   */
  void SetServiceListHelper  (ServiceListHelper* servicelisthelper);

  /**
   * \param servicelisthelper a default service list helper
   *
   * Add the service list helper to Install the default applications on a node. 
   */
  void AddDefaultServices  (ServiceListHelper* servicelisthelper);

  /**
   * Aggregate the implementations of the facilities classes on this
   *  node.
   * 
   * \param nodeName The node where the facilities have to be installed.
   */
  void Install (std::string nodeName);

  /**
   * Aggregate the implementations of the facilities classes on this
   * node.
   * 
   * \param node The node where the facilities have to be installed.
   */
  void Install (Ptr<Node> node);

  /**
   * Aggregate the implementations of the facilities classes on all the nodes of this
   * node container.
   * 
   * \param c NodeContainer containing the pointer to nodes where the facilities have to be installed
   */
  void Install (NodeContainer c) ;

  void AddServices (Ptr<iTETRISns3Facilities> facilities, Ptr<Node> node); 

private:
  /**
   *  service list helper.
   */
   ServiceListHelper* m_ServiceListHelper;                

   static void CreateAndAggregateObjectFromTypeId (Ptr<Node> node, const std::string typeId);

};

} // namespace ns3

#endif /* C2C_FACILITIES_HELPER_H*/

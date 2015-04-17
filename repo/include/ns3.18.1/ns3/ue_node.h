/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013 Intecs
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
 * Author: Daniele Azzarelli <daniele.azzarelli@intecs.it>
 */
#ifndef UE_NODE_H
#define UE_NODE_H

#include <string>
#include <stdint.h>
#include <map>
#include "ns3/node.h"
#include "ns3/core-module.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"

using namespace std;

namespace ns3 {

class Ue_Node: public Node
{
public:


  struct totDataInterface {
	double LteDtaTx;
	double LteDtaRx;
	double WiFiDataTx;
	double WiFiDataRx;
	double WiFiDataHelloTx;
	double WiFiDataHelloRx;
  };

  struct DelayJitterSample {
  	double m_time;   // time when this sample was collected, i.e. when the packet was received by the sink application, in s
  	double m_delay;  // delay of the packet, in ms
  	double m_jitter; // jitter of the packet, in ms
  	bool bSet; // jitter of the packet, in ms
  };

  Ue_Node ();

  /**
     * \param systemId a unique integer used for parallel simulations.
  */
  Ue_Node(uint32_t systemId);

  //Schedules the execution of the SendPosition function(mandatory)
  void SetSchedulingPos(double dTime);

  //Schedules the execution of the bundle request
  void SetSchedulingCmdReq(double dTime);

  //Sets  m_dPosFreq
  void SetFreqPosSend(double dFreq);

  //Sets m_CdmAddress (mandatory)
  void SetCdmAddress(Address address);

  //Sets m_MyLteAddress (mandatory)
  void SetMyAddress(Ipv4Address myAddress);

  //Sets m_bSendPos
  void SetPosSendEnable(bool bActive);

  //Sets m_delayJitterTrace
  void SetDelay(Ptr<Packet> receivedPacket, uint32_t uiMessageId);

  //Gets the number of bytes for interface
  void GetNBytesForInterface(totDataInterface& bytesTotal);

  //Returns the bundle delay/jitter map
  map <uint32_t, DelayJitterSample> GetDelay();

  //Gets the  m_bInject map
  map<uint32_t, bool> GetInjectMode();

  //Sets for a messageID the related inject mode - true if LTE
  void SetInjectMode(uint32_t uiMessageId, bool bIsLte);

  //Sets the sinker application for the bundle reception from CDM
  void SetRecApp();

  //Add message to request
  void AddMsgId(uint32_t uiMessageId, double m_delay);

  //Sends the Ack: bEpidemic has to be set to true if the ack is sent following epidemic routing
  void SendAck(bool bEpidemic, uint32_t ui32IdMessage);

private:

  //Initialization of variables
  void Init();

  //Callback used to receive the bundle from CDM
  void SinkRx (std::string path, Ptr<const Packet> packet, const Address &address);

  //Callback used to update metrics each time a packet is received at Node level
  void RxTracer(string context, Ptr<const Packet> packet, Ptr<Ipv4> ipv4,	uint32_t interface);

  //Callback used to update metrics each time a packet is transmitted at Node level
  void TxTracer(string context, Ptr<const Packet> packet, Ptr<Ipv4> ipv4,	uint32_t interface);

  //Function scheduled to send the position of the UE to CDM
  void SendPosition();
  
  //Function scheduled to send the bundle request from the UE to CDM
  void SendCmdReq();

  struct NodePosition
  {
	  uint32_t uiX;
	  uint32_t uiY;
  };

  //Structure for collecting n° bytes on different interfaces
  totDataInterface m_bytesTotal;

  //Frequency in msec for Position sending: settable by interface, default 1000
  double m_dPosFreq;

  //Internal usage: socket for ack/position sending
  Ptr<Socket> m_ns3UdpSocket;

  //CDM LTE Address(PORT too): settable by interface (MANDATORY), default 0
  Address m_CdmAddress;

  //Internal usage
  ApplicationContainer m_BundleApps;

  //Own LTE Ipv4Address: settable by interface (MANDATORY), default 0
  Ipv4Address m_MyLteAddress;

  //Flag to indicate if execute Position sending: settable by interface, default true
  bool m_bSendPos;

  //Flag to indicate if the UE has received the content by LTE or WIFI: true if LTE
  map<uint32_t, bool> m_bInject;

  //Flag to indicate if all contents have already been received
  bool m_bContent;

  //Number of Messages created from CDM
  uint32_t m_uiNMessages;

  //Number of received Messages
  uint32_t m_uiNMessagesRec;

  //DelayJitterSample map
  map <uint32_t, DelayJitterSample> m_delayJitterTrace;

  //DelayJitterSample map
  map <uint32_t, double> m_MessageToRequestList;

};

} // namespace ns3

#endif /* UE_NODE_H */

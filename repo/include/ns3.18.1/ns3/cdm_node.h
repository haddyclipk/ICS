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
#ifndef CDM_NODE_H
#define CDM_NODE_H

#include <string>
#include <stdint.h>
#include <map>
#include "ns3/node.h"
#include "ns3/core-module.h"
#include "ns3/applications-module.h"
#include "ns3/seeders-calc-module.h"
#include "ns3/internet-module.h"

using namespace std;

namespace ns3 {

class Cdm_Node: public Node
{
public:

	struct packetStruct {
		uint32_t uiDim;
		Ptr<Packet> packet;
	};

	Cdm_Node ();

	/**
	 * \param systemId a unique integer used for parallel simulations.
	 */
	Cdm_Node(uint32_t systemId);

	//Sets m_dTimeDelay (mandatory)
	void SetTimeDelay(double dTimeDelay);

	//Gets m_dTimeDelay
	void GetTimeDelay(double& dTimeDelay);

	//Sets m_dDeltaT (mandatory)
	void SetDeltaT(double dDeltaT);

	//Schedules the diffusion status evaluation function (mandatory): uiTime is the
	//initial starting time from the beginning of the simulation
	void SetScheduling(double uiTime /* msec */);
	
	//Schedules the function for the bundle initialization and creation (only for CNR version): uiTime is the
	//initial starting time from the beginning of the simulation
	void SetSchedulingInit(double uiTime /* msec */);

	//Sets the sinker application for ack/position reception (mandatory)
	void SetRecApp();

	//Adds to the m_UesAddress the related data (mandatory for each UE)
	void AddUeCdm(uint32_t uiUeId, Address ueAddress);

	//Gets m_uiNueByCdm and m_uiNueByEpidemic
	void GetNUesReached(uint32_t& uiCdm, uint32_t& uiEpidemic);

	/*
	 * Install the CDM application at the CDM node, to manage the re-injection of contents following the WHEN and WHO strategies
	 *\param whenStrategy The when-strategy to apply at CDM.
	 *\param whoStrategy The who-strategy to apply at CDM.
	 */
	void InstallCdmApplication(std::string whenStrategy, std::string whoStrategy);

	//Gets m_LteDtaTx and m_LteDtaRx
	void GetNBytes(double& dTx, double& dRx);

	//Load the creation of an empty message of the required length in bytes
	void LoadPacket(uint32_t uiDataSize, uint32_t uiMessageId);


private:

	//Initialization of variables
	void Init();
	//Callback used to receive the ack/position from UEs
	void SinkRx (std::string path, Ptr<const Packet> packet, const Address &address);

	//Callback used to update metrics each time a packet is received at Node level
	void RxTracer(string context, Ptr<const Packet> packet, Ptr<Ipv4> ipv4,	uint32_t interface);

	//Callback used to update metrics each time a packet is transmitted at Node level
	void TxTracer(string context, Ptr<const Packet> packet, Ptr<Ipv4> ipv4,	uint32_t interface);

	//Function scheduled and designed to send directly a content to the UE after a timeout elapsed
	void DirectSendigTimeOut(uint32_t uiUeId, uint32_t uiIdMsg);

	//Return number of UEs currently not reached from the content
	void GetNAllUesNotServed (map<uint32_t, bool> mUes, uint32_t& uiNUes);

	//Function periodically scheduled to evaluate the bundle diffusion
	void PushValuation();
	
	//Function used to send a bundle when required from Ue
	void FirstSendigBundle(uint32_t ueId, uint32_t ueIdMsg);

	//Sends a bundle to Ues by UDP
	void SendBundleToUe(uint32_t uiId, uint32_t uiIdMsg, Address ueAddress);

	//Creates empty message
	void CreatePackets(bool bPrepareTx);

	//Life time for the Bundle in sec: settable by interface (MANDATORY), default 0
	double m_dTimeDelay;

	//flag to understand if the Packet creation has already been completed
	bool m_bPacketInit;

	//Internal usage: used for each content to understand if it is the first inject and initialize m_dTimeFIrstInject
	map<uint32_t, bool> m_bFirstInject;

	//Internal usage in sec: used for each content to storage the initial life time of the bundle
	map<uint32_t, double> m_dTimeFirstInject;

	//Period for diffusion status evaluation in msec: settable by interface, default 20000
	double m_dDeltaT;

	//Number of messages received directly by CDM by Lte: output, readable by interface
	uint32_t m_uiNueByCdm;

	//Number of messages received by epidemic routing: output, readable by interface
	uint32_t m_uiNueByEpidemic;

	//Internal usage: map of Ack received for each message: first key is the MessageID
	map<uint32_t, map<uint32_t, bool> > m_Ack;

	//Internal usage: map of Ue Node ID and Lte IP address
	map<uint32_t, Address> m_UesAddress;

	//Internal usage: map of Node ID Position coordinates
	map<uint32_t, Vector> m_Position;

	//Internal usage
	ApplicationContainer m_AckApps;

	//Internal usage: module to retrieve, during diffusion evaluation, the number of UEs to
	//which inject and the related UE Id
	SeedersCalcHelper m_seedersCalcHelper;

	//Internal usage: Blank bundle map used for the transmission to UEs of contents
	map<uint32_t, packetStruct > m_PacketMap;

	//Internal usage: when and who strategies for re injection
	Ptr<SeedersCalc> whenModel;
	Ptr<WhoCalc> whoModel;

	//Number of bytes transmitted
	double m_LteDtaTx;
	//Number of bytes received
	double m_LteDtaRx;

	//Number of contents delivered created(default 1)
	uint32_t m_uiNMessages;
};

} // namespace ns3

#endif /* CDM_NODE_H */

/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
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
 * Author:
 */
#ifndef EPIDEMIC_ROUTING_H
#define EPIDEMIC_ROUTING_H

#include "ns3/core-module.h"
#include "ns3/wifi-module.h"
#include "ns3/v4ping-helper.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/qos-tag.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>

#include "mypacket.h"


using namespace std;

namespace ns3 {

class DtnApp : public Application
{
public:

	DtnApp ();
	virtual ~DtnApp();
	static TypeId GetTypeId (void);

	void Setup (Ptr<Node> node);
	void SetTimeLive (uint32_t uiLive);
	void SetHelloInt (double dHelloInt);
	void SetInitialCountUe (uint32_t uiStart);
	void DstHandleConnectionCreated (Ptr<Socket> s, const Address & addr);
	void ReceiveHello (Ptr<Socket> socket);
	void ScheduleTx (uint32_t dstnode, Time tNext, uint32_t packetSize);
	void SendHello (Ptr<Socket> socket, double endTime, Time initTime, uint32_t first);
	void Retransmit (InetSocketAddress sendTo, int32_t id, int32_t retx);
	void SendMore (InetSocketAddress sendTo, int32_t id, int32_t retx);
	void ConnectionSucceeds (Ptr<Socket> localSocket);
	void ConnectionFails (Ptr<Socket> localSocket);
	void ReceiveBundle (Ptr<Socket> socket);
	void SendBundle (Ptr<Packet> packetToSend, uint32_t uiSeqno);

private:
	virtual void StartApplication (void);
	virtual void StopApplication (void);

	void SendAP (Ipv4Address srcaddr, Ipv4Address dstaddr, uint32_t seqno, Time srctimestamp);
	void PrintBuffers (void);
	void CheckBuffers (uint32_t bundletype);
	int IsDuplicate (Ptr<Packet> pkt, Ptr<Queue> queue);
	int AntipacketExists (Ptr<Packet> pkt);
	void RemoveBundle (Ptr<Packet> pkt);

	Ptr<Node>         m_node;
	Ptr<Socket>       m_socket;
	std::vector<Ptr<Packet> > newpkt;
	std::vector<Ptr<Packet> > retxpkt; 			//vector of packets to retransmit
	Ptr<Queue>        m_antipacket_queue;		//antipacket queue
	Ptr<Queue>        m_queue;					//bundle queue
	Ptr<Queue>        m_helper_queue;			//helper queue to reorder packets
	Ptr<WifiMacQueue> mac_queue;				//MAC packets queue
	Address           m_peer;					//Not used
	EventId           m_sendEvent;				//bundle sending event
	bool              m_running;				//show if application is running
	uint32_t          m_serverReadSize;			//Not used
	uint32_t          neighbors;				//Number of neighbors
	InetSocketAddress *neighbor_address;		//Neighbors address vector
	double            *neighbor_last_seen; 		//vector of last received hello message from neighbor
	uint32_t          *currentServerRxBytes;	//vector of received bytes from each neighbor
	int32_t           **neighbor_hello_bundles;	//matrix of bundle in hello message
	int32_t           **neighbor_sent_bundles;	//bundle sent matrix
	int32_t           **neighbor_sent_aps;		//antipacket sent matrix
	double            **neighbor_sent_ap_when;	//antipacket leaving time matrix
	uint32_t          bundles;					//number of bundles
	InetSocketAddress *bundle_address;			//vector of bundels' source
	int32_t           *bundle_seqno;			//bundles' sequence number vector
	int32_t           *bundle_retx;				//pacjet type vector
	uint32_t          *bundle_size;				//Vector of bundles' dimension
	double            *bundle_ts;				//vector of bundles' arrive timestamp
	double            firstSendTime[10000];		//vector of bunldes' first inject of bundle
	double            lastSendTime[10000];		//last sent bundle timestamp vector
	uint32_t          lastTxBytes[10000];		//last transmitted bytes vector
	uint32_t          currentTxBytes[10000];
	uint32_t          totalTxBytes[10000];
	InetSocketAddress *sendTos;
	int32_t           ids[10000];				//ID tag vector
	int32_t           retxs[10000]; 			//QoS tag vector
	int               NumFlows;
	uint32_t          drops;
	double            t_c;						//congestion window threshold
	uint32_t          b_s;						//Buffer size
	uint32_t          *b_a;						//left space in congestion window
	uint32_t          rp;						//1=spray and wait, 0=epidemic
	uint32_t          cc;						//congetion 0=off, 1=static, 2=adaptive
	uint32_t		  m_timeLive;				//sec
	uint32_t		  m_uiUeStart;
	double			  m_dHelloInt;				//sec
};


} // namespace ns3

#endif /* EPIDEMIC_ROUTING_H */

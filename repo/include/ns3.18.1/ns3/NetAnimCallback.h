/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * NetAnimCallback.h
 *
 *  Created on: 21/ott/2013
 *      Author: Filippo Rebecchi  <filippo.rebecchi@lip6.fr>
 */

#ifndef NETANIMCALLBACK_H
#define NETANIMCALLBACK_H

#include "ns3/object.h"
#include "ns3/traced-value.h"
#include "ns3/traced-callback.h"

using namespace std;

namespace ns3 {


class NetAnimCallback : public Object
{
public:
	static TypeId GetTypeId (void);
	NetAnimCallback () ;
	virtual ~NetAnimCallback ();

	void UpdateCellularId (uint32_t value);
	void UpdateAdhocId (uint32_t value);

	TracedValue<uint32_t> m_cellularId;
	TracedValue<uint32_t> m_adhocId;
};

}

#endif /* NETANIMCALLBACK_H */

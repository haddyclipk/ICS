/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013 INTECS, Thales, UPMC
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
 *	Author: Filippo Rebecchi <filippo.rebecchi@lip6.fr>
 */

#ifndef WHO_CALC_H_
#define WHO_CALC_H_

#include "ns3/object.h"
#include "ns3/core-module.h"
#include "float.h"

using namespace std;

namespace ns3 {

class WhoCalc : public Object
{
public:
	static TypeId GetTypeId (void);
	WhoCalc ();
	virtual ~WhoCalc ();

	/**
	 * Get back the list of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param listUes list of UEs to inject (OUTPUT)
	 * \param uiStartIndexUes first index for UEs(INPUT)
	 * \return 0 if it worked
	 */
	 virtual uint32_t GetUeToDelivery (bool bFirst, uint32_t uiNumUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, list<uint32_t>& lListUes);

	 /**
	 * Get back the list of UEs not reached from content
	 *
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param listUes list of UEs to inject (OUTPUT)
	 * \return 0 if it worked
	 */
	 uint32_t GetUesForPanicZone (uint32_t uiNumUes, map<uint32_t, bool> mUes, list<uint32_t>& lListUes);

protected:

	/**
	 * Get back the first ID of UEs
	 *
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \return the UE ID
	 */
	uint32_t  GetFirstUeId (map<uint32_t, bool> mUes);

};

class RandomWho : public WhoCalc
{
public:
	static TypeId GetTypeId (void);
	RandomWho ();
	virtual ~RandomWho ();

	/**
	 * Get back the list of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param listUes list of UEs to inject (OUTPUT)
	 * \param uiStartIndexUes first index for UEs(INPUT)
	 * \return 0 if it worked
	 */
	uint32_t  GetUeToDelivery (bool bFirst, uint32_t uiNumUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, list<uint32_t>& lListUes);

};




//////////////////////Not finished yet////////////////////////////////////////////////////////////////////////////////////////

//class PositionWho : public WhoCalc
//{
//public:
//	static TypeId GetTypeId (void);
//	PositionWho ();
//	virtual ~PositionWho ();
//
//	/**
//		 * Get back a list of UEs to which inject the bundle depending on their position
//		 *
//		 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
//		 * \param uiNumUes total number of UEs (INPUT)
//		 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
//		 * \param mPosition map <UE_ID, POSITION> (INPUT)
//		 * \param listUes list of UEs to inject (OUTPUT)
//		 * \return 0 if it worked
//		 */
//	uint32_t
//	PositionWho::GetUeToDelivery (bool bFirst, uint32_t uiNumUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, list<uint32_t>& lListUes);
//
//
//
//private:
//	Zone _mainZone;
//	map<uint32_t,Zone> _zoneMap;
//	double _padding;
//	double _minX;
//	double _maxX;
//	double _minY;
//	double _maxY;
//
//};
//
//struct ScoreCard {
//	uint32_t node;
//	double score;
//};
//
//class ScoreCompare{
//public:
//	bool operator()(ScoreCard& t1, ScoreCard& t2) const// Returns true if t1 is earlier than t2
//	    {
//	       if (t1.score < t2.score) return true;
//	       if (t1.score > t2.score) return false;
//	       return false;
//	    }

//};

}// namespace ns3



#endif /* WHO_CALC_H_ */

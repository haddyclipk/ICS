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
#ifndef SEEDERS_CALC_H
#define SEEDERS_CALC_H

#include "ns3/object.h"
#include "ns3/core-module.h"
#include <map>


using namespace std;

namespace ns3 {

/**
 * \brief The black Box module used to get the number and the list of UEs to which inject
 *
 */
class SeedersCalc : public Object
{
public:
	static TypeId GetTypeId (void);
	SeedersCalc ();
	virtual ~SeedersCalc ();

	/**
	 * Set the initial number of UEs to which inject the bundle
	 *
	 * \param uiStaticNInjects the number of injects (INPUT)
	 */
	void SetNInjects (uint32_t uiStaticNInjects);

	/**
	 * Get the initial number of UEs to which inject the bundle
	 *
	 * \return  the number of injects
	 */
	uint32_t GetNInjects () const;

	/**
	 * Get back the number of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param uiNnotServedUes number of not served UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param uiNumInjects number off inject to execute (OUTPUT)
	 * \return 0 if it worked
	 */
	virtual uint32_t GetNPacketsToDelivery (bool bFirst, uint32_t uiNumUes, uint32_t uiNnotServedUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, uint32_t& uiNumInjects, double dTotTime, double dRemainingTime) = 0;


private:

	//Static Number of Injects
	uint32_t m_uiStaticNInjects;

};

// ------------------------------------------------------------------------------------ //

class InitialInjection : public SeedersCalc
{
public:
	static TypeId GetTypeId (void);
	InitialInjection ();
	virtual ~InitialInjection ();


	/**
	 * Get back the number of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param uiNnotServedUes number of not served UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param uiNumInjects number off inject to execute (OUTPUT)
	 * \return 0 if it worked
	 */
	uint32_t GetNPacketsToDelivery (bool bFirst, uint32_t uiNumUes, uint32_t uiNnotServedUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, uint32_t& uiNumInjects, double dTotTime, double dRemainingTime);
};

// ------------------------------------------------------------------------------------ //

class LinearInjection : public SeedersCalc
{
public:
	static TypeId GetTypeId (void);
	LinearInjection ();
	virtual ~LinearInjection ();

	/**
	 * Get back the number of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param uiNnotServedUes number of not served UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param uiNumInjects number off inject to execute (OUTPUT)
	 * \return 0 if it worked
	 */
	uint32_t GetNPacketsToDelivery (bool bFirst, uint32_t uiNumUes, uint32_t uiNnotServedUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, uint32_t& uiNumInjects, double dTotTime, double dRemainingTime);
};


// ------------------------------------------------------------------------------------ //

class LinearSegmentInjection : public SeedersCalc
{
public:
	static TypeId GetTypeId (void);
	LinearSegmentInjection ();
	virtual ~LinearSegmentInjection ();

	/**
	 * Set the offset with respect to a 0.5 linear slope coefficient for the first linear segment
	 * \param offset the total offset to add to the parameter 0.5
	 */
	void SetOffset(double offset);

	/**
	 * Get the offset with respect to a 0.5 linear slope coefficient for the first segment
	 * \return double the offset
	 */
	double GetOffset()const;

	/**
	 * Get back the number of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param uiNnotServedUes number of not served UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param uiNumInjects number off inject to execute (OUTPUT)
	 * \return 0 if it worked
	 */
	uint32_t GetNPacketsToDelivery (bool bFirst, uint32_t uiNumUes, uint32_t uiNnotServedUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, uint32_t& uiNumInjects, double dTotTime, double dRemainingTime);


private:
	double d_offset;

};

// ------------------------------------------------------------------------------------ //

class SquareInjection : public SeedersCalc
{
public:
	static TypeId GetTypeId (void);
	SquareInjection ();
	virtual ~SquareInjection ();

	/**
	 * Get back the number of UEs to which inject the bundle
	 *
	 * \param bFirst flag to indicate if it is the first inject or not (INPUT)
	 * \param uiNumUes total number of UEs (INPUT)
	 * \param uiNnotServedUes number of not served UEs (INPUT)
	 * \param mUes map <UE_ID, ACK_STATE> (INPUT)
	 * \param mPosition map <UE_ID, POSITION> (INPUT)
	 * \param uiNumInjects number off inject to execute (OUTPUT)
	 * \return 0 if it worked
	 */
	uint32_t GetNPacketsToDelivery (bool bFirst, uint32_t uiNumUes, uint32_t uiNnotServedUes, map<uint32_t, bool> mUes, map<uint32_t, Vector> mPosition, uint32_t& uiNumInjects, double dTotTime, double dRemainingTime);
};

// ------------------------------------------------------------------------------------ //

} // namespace ns3

#endif /* SEEDERS_CALC_H */

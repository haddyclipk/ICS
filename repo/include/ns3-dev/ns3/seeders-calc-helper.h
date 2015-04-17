/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */ 
/* 
 * Copyright (c) 2011 Yufei Cheng 
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
 * Author: Yufei Cheng   <yfcheng@ittc.ku.edu> 
 * 
 * James P.G. Sterbenz <jpgs@ittc.ku.edu>, director 
 * ResiliNets Research Group  http://wiki.ittc.ku.edu/resilinets 
 * Information and Telecommunication Technology Center (ITTC) 
 * and Department of Electrical Engineering and Computer Science 
 * The University of Kansas Lawrence, KS USA. 
 * 
 * Work supported in part by NSF FIND (Future Internet Design) Program 
 * under grant CNS-0626918 (Postmodern Internet Architecture), 
 * NSF grant CNS-1050226 (Multilayer Network Resilience Analysis and Experimentaion on GENI), 
 * US Department of Defense (DoD), and ITTC at The University of Kansas. 
 */ 
 
#ifndef SEEDERS_CALC_HELPER_H 
#define SEEDERS_CALC_HELPER_H 

#include "ns3/object-factory.h" 
#include "ns3/node-container.h"
#include "ns3/trace-helper.h" 
#include "ns3/seeders-calc-module.h"
 
namespace ns3 { 
 
/** 
 * \brief Create a server application which waits for input http packets 
 *        and uses the information carried into their payload to compute 
 *        delay and to determine if some packets are lost. 
 */ 
class SeedersCalcHelper
{ 
public: 
  /** 
   * Create SeedersCalcHelper
   * 
   */ 
  SeedersCalcHelper ();
  /**
   * \internal
   * Destroy a SeedersCalc Helper
   */
  ~SeedersCalcHelper ();
 

  /** 
   * Create one SeedersCalc application on each of the Nodes in the 
   * NodeContainer. 
   * 
   * \param node The node on which to create the Applications. 
   * \param whenStrategy The when-strategy to apply at CDM.
   * \param whenModel  A pointer to when-model (OUTPUT).
   * \param whoStrategy The who-strategy to apply at CDM.
   * \param whoModel  A pointer to the who-model (OUTPUT).
   * \returns The applications created, one Application per Node in the 
   *          NodeContainer. 
   */ 
  void Install (Ptr<Node> node, std::string whenStrategy, Ptr<SeedersCalc>& whenModel, std::string whoStrategy, Ptr<WhoCalc>& whoModel ) const;
  /** 
   * Create one SeedersCalc application on each of the Nodes in the 
   * NodeContainer. 
   * 
   * \param c The nodes on which to create the Applications.  The nodes 
   *          are specified by a NodeContainer. 
   * \returns The applications created, one Application per Node in the 
   *          NodeContainer. 
   */ 
  void Install (NodeContainer c) const;





private:
  ObjectFactory m_factory;

  /**
      * Set the WHO strategy at the CDM
      * \param node The node on which to create the Applications.
      * \param whoStrategy The who-strategy to apply at CDM.
      * \param whoModel  A pointer to who-model (OUTPUT).
      * \param m_factory the model factory
      *
      */
   void SetWhoStrategy(Ptr<Node> node, std::string whoStrategy, Ptr<WhoCalc>& whoModel, ObjectFactory m_factory) const;

   /**
      * Set the WHEN strategy at the CDM
      * \param node The node on which to create the Applications.
      * \param whenStrategy The when-strategy to apply at CDM.
      * \param whenModel  A pointer to when-model (OUTPUT).
      * \param m_factory the model factory
      *
      */
     void SetWhenStrategy(Ptr<Node> node, std::string whenStrategy, Ptr<SeedersCalc>& whenModel, ObjectFactory m_factory) const;

};


} // namespace ns3

#endif /* SEEDERS_CALC_HELPER_H */


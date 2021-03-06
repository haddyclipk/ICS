// Azzarelli
/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2007 INRIA
 *               2009,2010 Contributors
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
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 * Contributors: Thomas Waldecker <twaldecker@rocketmail.com>
 *               Martín Giachino <martin.giachino@gmail.com>
 */
#ifndef NS2_MOBILITY_WRAPPER_HELPER_H
#define NS2_MOBILITY_WRAPPER_HELPER_H

#include <string>
#include <stdint.h>
#include "ns2-mobility-helper.h"
#include "ns3/node-container.h"

namespace ns3 {

class Ns2MobilityWrapperHelper: public Ns2MobilityHelper
{
public:

  /**
   * \param filename filename of file which contains the
   *        ns2 movement trace.
   */
  Ns2MobilityWrapperHelper (std::string filename);
  
  /**
   * Read the ns2 trace file and configure the movement
   * patterns of all nodes contained in the NodeContainer c
   * whose nodeId is matches the nodeId of the nodes in the trace
   * file.
   */
  void Install (NodeContainer& c) const;

};

} // namespace ns3

#endif /* NS2_MOBILITY_WRAPPER_HELPER_H */

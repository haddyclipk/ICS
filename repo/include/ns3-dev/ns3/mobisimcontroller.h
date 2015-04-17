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
 * Author: Guillaume Remy <guillaume1.remy@orange-ftgroup.com>
 */

#ifndef _CONTROLLER_
#define _CONTROLLER_

#include "mobisimroads.h"

using namespace ns3;
using namespace std;

namespace ns3 {

/**
 * Controller is the main class to manage the events (callbacks), traces, rules,
 * and etc.
 *
 * Controller can be assumed as an application which is tied with the roads and
 * vehicles. We implement the VANETs simulations here, design and form the basic
 * of each experiments.
 */
class Controller : public Object
{
public:
  Controller ();

  /** Constructor.
   * @param roads The Roads to bind to the Controller.
   */
  Controller (Ptr<Roads> roads);

  /** Event handler for InitVehicle callbacks, used to add vehicles which are
   * in the traces file.
   * @param VID Current vehicle ID which has to be increment each time we add a
   * vehicle.
   * @return True if the vehicles are correctly initialized.
   */
  bool InitVehicles (int& VID);

  /** Event handler for ControlVehicle callbacks, used here to plot vehicles
   * position.
   * @param vehicle The vehicle to control.
   */
  void ControlVehicle (Ptr<Vehicle> vehicle);

  /** Returns the Roads bound to this Controller.
   * @return The Roads bound to this Controller.
   */
  Ptr<Roads> GetRoads ()
  {
    return m_roads;
  }

  /** Sets the Roads bound to this controller.
   * @param roads The Roads to bind to this Controller.
   */
  void SetRoads (Ptr<Roads> roads)
  {
    m_roads = roads;
  }

  /** Sets the number of vehicles which will circulate in the simulated area.
   */
  void SetVehiclesNumber (uint vn)
  {
    m_vn = vn;
  }

  bool Plot; /**< True if we want to plot vehicles.*/

private:
  Ptr<Roads> m_roads; /**< The Roads bound to this Controller.*/
  uint m_vn; /**< The number of vehicles we want to circulate on the Roads.*/
};
}
#endif

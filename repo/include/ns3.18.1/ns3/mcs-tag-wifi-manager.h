// iTetris INTECS
/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 EU FP7 iTETRIS project
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
 * Author: Ramon Bauza <rbauza@umh.es>
 */
#ifndef MCS_TAG_WIFI_MANAGER_H
#define MCS_TAG_WIFI_MANAGER_H

#include <stdint.h>
#include "wifi-remote-station-manager.h"

namespace ns3 {

struct McsTagWifiRemoteStation;

class McsTagWifiManager : public WifiRemoteStationManager
{
public:
  static TypeId GetTypeId (void);
  McsTagWifiManager ();
  virtual ~McsTagWifiManager ();
  WifiMode GetDataMode (WifiRemoteStation *station, Ptr<const Packet> packet, uint32_t fullPacketSize);
  WifiMode GetRtsMode (WifiRemoteStation *station, Ptr<const Packet> packet);

private:
  // iTetris INTECS
  virtual bool IsLowLatency (void) const;
  // iTetris INTECS

  // iTetris INTECS
  // overriden from base class
  virtual WifiRemoteStation * DoCreateStation (void) const;
  virtual void DoReportRxOk (WifiRemoteStation *station, double rxSnr, WifiMode txMode);
  virtual WifiTxVector DoGetDataTxVector (WifiRemoteStation *station, uint32_t size);
  virtual WifiTxVector DoGetRtsTxVector (WifiRemoteStation *station);
  virtual void DoReportRtsFailed (WifiRemoteStation *station);
  virtual void DoReportDataFailed (WifiRemoteStation *station);
  virtual void DoReportRtsOk (WifiRemoteStation *station, double ctsSnr, WifiMode ctsMode, double rtsSnr);
  virtual void DoReportDataOk (WifiRemoteStation *station, double ackSnr, WifiMode ackMode, double dataSnr);
  virtual void DoReportFinalRtsFailed (WifiRemoteStation *station);
  virtual void DoReportFinalDataFailed (WifiRemoteStation *station);
  //Prima in WifiRemoteStation
  virtual WifiMode DoGetDataMode (WifiRemoteStation *st, uint32_t size);
  virtual WifiMode DoGetRtsMode (WifiRemoteStation *st);
  virtual WifiMode GetWifiMode (uint8_t mcs);

  // iTetris INTECS

};

} // namespace ns3

#endif /* MCS_TAG_WIFI_MANAGER_H */

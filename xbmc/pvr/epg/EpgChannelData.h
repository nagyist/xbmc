/*
 *  Copyright (C) 2012-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "pvr/PVRConstants.h" // PVR_CLIENT_INVALID_UID

#include <ctime>
#include <string>
#include <string_view>

namespace PVR
{
class CPVRChannel;

class CPVREpgChannelData
{
public:
  CPVREpgChannelData() = default;
  CPVREpgChannelData(int iClientId, int iUniqueClientChannelId);
  explicit CPVREpgChannelData(const CPVRChannel& channel);

  int ClientId() const;
  int UniqueClientChannelId() const;
  bool IsRadio() const;

  bool IsHidden() const;
  void SetHidden(bool bIsHidden);

  bool IsLocked() const;
  void SetLocked(bool bIsLocked);

  bool IsEPGEnabled() const;
  void SetEPGEnabled(bool bIsEPGEnabled);

  int ChannelId() const;
  void SetChannelId(int iChannelId);

  const std::string& ChannelName() const;
  void SetChannelName(std::string_view strChannelName);

  const std::string& ChannelIconPath() const;
  void SetChannelIconPath(std::string_view strChannelIconPath);

private:
  const bool m_bIsRadio = false;
  const int m_iClientId = PVR_CLIENT_INVALID_UID;
  const int m_iUniqueClientChannelId = -1;

  bool m_bIsHidden = false;
  bool m_bIsLocked = false;
  bool m_bIsEPGEnabled = true;
  int m_iChannelId = -1;
  std::string m_strChannelName;
  std::string m_strChannelIconPath;
};
} // namespace PVR

/*
League Overseer
    Copyright (C) 2013-2015 Vladimir Jimenez & Ned Anderson

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <json/json.h>

#include "MatchEvent-Join.h"

JoinMatchEvent::JoinMatchEvent ()
{
    this->setEventType(PLAYER_JOIN);
    this->setTimestamp();
};

JoinMatchEvent& JoinMatchEvent::setCallsign (std::string _callsign)
{
    callsign = _callsign;

    return *this;
}

JoinMatchEvent& JoinMatchEvent::setBZID (std::string _bzID)
{
    bzID = _bzID;

    return *this;
}

JoinMatchEvent& JoinMatchEvent::setIpAddress (std::string _ipAddress)
{
    ipAddress = _ipAddress;

    return *this;
}

JoinMatchEvent& JoinMatchEvent::save (void)
{
    json_object *jCallsign   = json_object_new_string(callsign.c_str());
    json_object *jBZID       = json_object_new_string(bzID.c_str());
    json_object *jIpAddress  = json_object_new_string(ipAddress.c_str());
    json_object *iTimestamp  = json_object_new_string(timestamp.c_str());

    json_object_object_add(jsonData, "callsign", jCallsign);
    json_object_object_add(jsonData, "bzid", jBZID);
    json_object_object_add(jsonData, "ip", jIpAddress);
    json_object_object_add(jsonData, "timestamp", iTimestamp);

    json_object_object_add(jsonObj, "data", jsonData);

    return *this;
}

JoinMatchEvent& JoinMatchEvent::setTimestamp ()
{
    timestamp = getCurrentTimeStamp();

    return *this;
}
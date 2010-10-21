/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Waypoint.h"
#include <sstream>
#include "../Engine/Language.h"

/**
 * Initializes a waypoint.
 */
Waypoint::Waypoint() : Target(), _id(0)
{
}

/**
 *
 */
Waypoint::~Waypoint()
{
}

/**
 * Returns the waypoint's unique ID.
 * @return Unique ID.
 */
int Waypoint::getId()
{
	return _id;
}

/**
 * Changes the waypoint's unique ID.
 * @param id Unique ID.
 */
void Waypoint::setId(int id)
{
	_id = id;
}

/**
 * Returns the waypoint's unique identifying name.
 * @param lang Language to get strings from.
 * @return Full name.
 */
string Waypoint::getName(Language *lang)
{
	stringstream name;
	name << lang->getString(STR_WAY_POINT_) << _id;
	return name.str();
}
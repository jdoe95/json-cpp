/*
 * boolean.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */
#include "../json.hpp"

using namespace JSON;

/*** parsing and stringnify ***/
bool
Boolean_t::fromJson( std::string&& other )
{
	JsonHelpers::removeWhiteSpaces(other);

	if( other == "true" )
		_value = true;

	else if( other == "false" )
		_value = false;

	else
		return false;

	return true;
}



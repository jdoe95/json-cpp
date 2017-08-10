/*
 * number.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */
#include "../json.hpp"

using namespace JSON;

/*** parsing and stringnify ***/
bool
Number_t::fromJson( std::string&& other )
{
	JsonHelpers::removeWhiteSpaces(other);

	if( other.empty() )
		return false;

	if( ! ((other[0] >= '1') && (other[0] <= '9')) )
	{
		if( other[0] != '-' && other[0] != '+' )
			return false;
	}

	_value = std::atof( other.c_str() );

	return true;
}

/*
 * array.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */
#include "../json.hpp"

using namespace JSON;

bool
Array_t::fromJson( std::string&& other )
{
	JsonHelpers::removeWhiteSpaces(other);

	if( other.empty() )
		return false;

	if( other[0] != '[' )
		return false;

	// analyse array structure
	std::list<std::string::size_type> valueFromTo;

	std::string::size_type level = 1;
	for( std::string::size_type counter = 1; counter < other.size(); counter ++ )
	{
		if( other[counter] == ',' )
		{
			if(level == 1 )
			{
				valueFromTo.push_back(counter);
			}
		}

		else if( other[counter] == '{' || other[counter] == '[' )
			level++;

		else if( other[counter] == '}' || other[counter] == ']' ) {
			if( level > 1 )
				level--;
			else {
				// end of object
				valueFromTo.push_back( counter );
				break;
			}
		}
	}

	Array_t array;
	std::string::size_type start = 1;
	for( unsigned counter = 0; ! valueFromTo.empty(); counter++ )
	{
		std::string::size_type pos = valueFromTo.front();
		array[counter].fromJson( other.substr( start, pos - start) );

		valueFromTo.pop_front();
		start = pos + 1;
	}

	operator=(std::move(array));
	return true;
}

std::string
Array_t::toJson() const
{
	std::string ret;

	ret += '[';

	if( !_map.empty() )
	{
		std::map<unsigned, Json_t>::const_iterator it = _map.begin();
		const std::map<unsigned, Json_t> ::const_iterator end = _map.end();

		ret += it->second.toJson();

		for( ++it; it != end; ++it )
		{
			ret += ',' + it->second.toJson();
		}
	}

	ret += ']';

	return ret;
}





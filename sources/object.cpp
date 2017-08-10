/*
 * object.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */
#include "../json.hpp"

using namespace JSON;

bool
Object_t::fromJson( std::string&& other )
{
	JsonHelpers::removeWhiteSpaces(other);

	if( other.empty() )
		return false;

	if( other[0] != '{' )
		return false;

	// analyse object structure
	std::list<std::pair<std::string::size_type, std::string::size_type> > keyFromTo, valueFromTo;

	std::string::size_type level = 1;
	bool expectKey = true;
	std::string::size_type keyPos = 1;
	std::string::size_type valuePos = 1;
	bool inString = false;
	for( std::string::size_type counter = 1; counter < other.size(); counter ++ )
	{
		if( other[counter] == ':' )
		{
			if( level == 1 )
			{
				if( expectKey ) {
					keyFromTo.push_back( {keyPos, counter} );
					valuePos = counter + 1;
					expectKey = false;
				}
			}
		}
		else if( other[counter] == ',' )
		{
			if( level == 1 )
			{
				if( ! expectKey )
				{
					valueFromTo.push_back( {valuePos, counter} );
					keyPos = counter + 1;
					expectKey = true;
				}
			}
		}

		else if( other[counter] == '{' || other[counter] == '[' )
			level++;

		else if( other[counter] == '"' )
		{
			if( inString )
			{
				inString = false;
				level--;
			}
			else
			{
				inString = true;
				level++;
			}
		}

		else if( other[counter] == '}' || other[counter] == ']' ) {
			if( level > 1 )
				level--;
			else {
				// end of object
				valueFromTo.push_back( {valuePos, counter} );
				break;
			}
		}
	}

	if( keyFromTo.size() != valueFromTo.size() )
		return false;

	// construct object
	Object_t object;
	String_t key;
	for( ; ! keyFromTo.empty(); )
	{
		key.fromJson( std::move(other.substr(
				keyFromTo.front().first,
				keyFromTo.front().second - keyFromTo.front().first )) );

		object[key].fromJson( std::move( other.substr(
				valueFromTo.front().first,
				valueFromTo.front().second - valueFromTo.front().first) ) );

		keyFromTo.pop_front();
		valueFromTo.pop_front();
	}

	operator=(std::move(object));

	return true;
}

std::string
Object_t::toJson() const
{
	std::string ret;

	ret += '{';

	if( !_map.empty() )
	{
		std::map<std::string, Json_t>::const_iterator it = _map.begin();
		const std::map<std::string, Json_t> ::const_iterator end = _map.end();

		ret += String_t(it->first).toJson() + ':' + it->second.toJson();

		for( ++it; it != end; ++it )
		{
			ret += ',' + String_t(it->first).toJson() + ':' + it->second.toJson();
		}
	}

	ret += '}';

	return ret;
}





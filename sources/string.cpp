/*
 * string.cpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */
#include "../json.hpp"

using namespace JSON;

bool
String_t::fromJson( std::string&& other )
{
	JsonHelpers::removeWhiteSpaces(other);

	if( other.empty() )
		return false;

	std::string temp;

	if( other[0] != '\"' )
		return false;

	bool inEscape = false;
	bool inNumber = false;
	char numberBuf[4];
	uint8_t numberIndex = 0;

	for( unsigned i = 1; i < other.size(); i++ )
	{
		// if escape sequence
		if( other[i] == '\\' )
		{
			if( inEscape )
			{
				temp += '\\';
				inEscape = false;
				inNumber = false;
			}
			else
			{
				inEscape = true;
				inNumber = false;
			}
		}
		else if( inEscape )
		{
			if( inNumber )
			{
				numberBuf[numberIndex++] = other[i];

				if( numberIndex >= 4 )
				{
					numberIndex = 0;
					inNumber = false;
					inEscape = false;

					uint8_t first = JsonHelpers::fromHex<uint8_t>(numberBuf);

					if( first != 0 )
						temp += static_cast<char>(first);

					temp += static_cast<char>( JsonHelpers::fromHex<uint8_t>(numberBuf+2) );
				}
			}
			else
			{
				if( other[i] == '\"' ) {
					temp += '\"';
					inEscape = false;
				}

				else if( other[i] == '/' ) {
					temp += '/';
					inEscape = false;
				}

				else if( other[i] == 'b' ) {
					temp += '\b';
					inEscape = false;
				}

				else if( other[i] == 'f' ) {
					temp += '\f';
					inEscape = false;
				}

				else if( other[i] == 'n' ) {
					temp += '\n';
					inEscape = false;
				}

				else if( other[i] == 'r' ) {
					temp += '\r';
					inEscape = false;
				}

				else if( other[i] == 't' ) {
					temp += '\t';
					inEscape = false;
				}
				else if( other[i] == 'u' ) {
					inNumber = true;
				}
				else {
					// not escape character
					inEscape = false;
				}
			}
		}
		else if( other[i] == '\"' )
		{
			// string termination
			_string = temp;
			return true;
		}
		else
		{
			temp += other[i];
		}
	}

	return false;
}

std::string
String_t::toJson() const {

	std::string ret;
	ret += '\"';

	for( const auto& i : _string )
	{
		if( i == '\"' )
			ret += "\\\"";

		else if( i == '\\' )
			ret += "\\\\";

		else if( i < 0x1F )
		{
			if( i == '\"' )
				ret += "\\\"";

			else if( i == '\\' )
				ret += "\\\\";

			else if( i == '/' )
				ret += "\\/";

			else if( i == '\b' )
				ret += "\\b";

			else if( i == '\f' )
				ret += "\\f";

			else if( i == '\n' )
				ret += "\\n";

			else if( i == '\r' )
				ret += "\\r";

			else if( i == '\t' )
				ret += "\\t";

			else
				ret += "\\u" + JsonHelpers::toHex(i);
		}
		else
			ret += i;
	}

	ret += '\"';

	return ret;
}



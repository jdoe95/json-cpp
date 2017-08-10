/*
 * helpers.hpp
 *
 *  Created on: Aug 9, 2017
 *      Author: jdoe
 */

#ifndef H7872D9CB_0B73_419B_97E3_A2690C190000
#define H7872D9CB_0B73_419B_97E3_A2690C190000

namespace JSON
{

namespace JsonHelpers
{
template<typename Integer_t, typename T
	= typename std::enable_if<std::is_integral<Integer_t>::value, Integer_t>::type>
std::string toHex( Integer_t integer )
{
	const char table[] = { '0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	std::string ret;

	for( uint8_t counter = sizeof(Integer_t); counter > 0; counter-- )
	{
		uint8_t byte = static_cast<uint8_t>(integer >> ( (counter - 1) * 8 ));

		uint8_t nibble = (byte >> 4) & 0xF;

		ret += table[nibble];

		nibble = byte & 0xF;

		ret += table[nibble];
	}

	return ret;
}

template<typename Integer_t, typename T
	= typename std::enable_if<std::is_integral<Integer_t>::value, Integer_t>::type>
Integer_t fromHex( const char* str )
{
	Integer_t ret = 0;

	for( unsigned counter = 0; counter < sizeof(Integer_t) * 2; )
	{
		uint8_t nibble;

		if( (str[counter] >= '0') && (str[counter] <= '9') )
			nibble = static_cast<uint8_t>(str[counter] - '0');

		else if( (str[counter] >= 'A') && (str[counter] <= 'F') )
			nibble = static_cast<uint8_t>(str[counter] - 'A' + 10 );

		else if( (str[counter] >= 'a') && (str[counter] <= 'f') )
			nibble = static_cast<uint8_t>(str[counter] - 'a' + 10 );
		else
			break;

		nibble = static_cast<uint8_t>(nibble << 4);
		counter++;

		if( (str[counter] >= '0') && (str[counter] <= '9') )
			nibble |= static_cast<uint8_t>(str[counter] - '0');

		else if( (str[counter] >= 'A') && (str[counter] <= 'F') )
			nibble |= static_cast<uint8_t>(str[counter] - 'A' + 10 );

		else if( (str[counter] >= 'a') && (str[counter] <= 'f') )
			nibble |= static_cast<uint8_t>(str[counter] - 'a' + 10);
		else
			break;

		counter++;

		ret = static_cast<Integer_t>(ret | (nibble << (sizeof(Integer_t) * 8 - counter * 4)));
	}

	return ret;
}

inline void
removeWhiteSpaces( std::string& string )
{
	string.erase(
		std::remove_if(	string.begin(), string.end(), isspace), string.end() );
}

} // namespace JsonHelpers

} // namespace JSON

#endif /* H7872D9CB_0B73_419B_97E3_A2690C190000 */

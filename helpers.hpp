/*
 * helpers.hpp
 *
 *  Created on: Aug 9, 2017
 *      Author: jdoe
 */

#ifndef H8FC63DC3_BF5C_4508_AD4E_FEC1AD39D795
#define H8FC63DC3_BF5C_4508_AD4E_FEC1AD39D795

namespace JSON
{
namespace JsonHelpers
{

template<typename Integer_t, typename T
	= typename std::enable_if<std::is_integral<Integer_t>::value, Integer_t>::type>
std::string toHex( Integer_t integer );

template<typename Integer_t, typename T
	= typename std::enable_if<std::is_integral<Integer_t>::value, Integer_t>::type>
Integer_t fromHex( const char* str );

void removeWhiteSpaces( std::string& string );

} // namespace JsonHelpers
} // namespace JSON

#endif /* H8FC63DC3_BF5C_4508_AD4E_FEC1AD39D795 */

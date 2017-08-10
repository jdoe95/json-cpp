/*
 * string.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef H300F22E8_C5C5_4CF7_98D7_FA97AA9C64F3
#define H300F22E8_C5C5_4CF7_98D7_FA97AA9C64F3

namespace JSON
{
/*** construct from std::string ***/
inline
String_t::String_t( const std::string& other ) :
	_string(other)
{}

inline
String_t::String_t( std::string&& other ) :
	_string(std::move(other))
{}

/*** swap with another object ***/
inline void
String_t::swap( String_t& other ) {
	_string.swap(other._string);
}

/*** allow implicit conversion to string ***/
inline
String_t::operator const char*() const {
	return _string.c_str();
}

inline
String_t::operator std::string() const {
	return _string;
}

/*** allow explicit conversion to bool ***/
inline
String_t::operator bool() const {
	return ! _string.empty();
}

/*** parsing and stringnify ***/
inline bool
String_t::fromJson( const std::string& other ) {
	return fromJson( std::string(other) );
}

} // namespace JSON

#endif /* H300F22E8_C5C5_4CF7_98D7_FA97AA9C64F3 */

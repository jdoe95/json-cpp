/*
 * boolean.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef H9600B189_BD18_449C_8C73_1373D3E6B864
#define H9600B189_BD18_449C_8C73_1373D3E6B864

namespace JSON
{
/*** construct as false ***/
inline
Boolean_t::Boolean_t() :
	_value(false)
{}

/*** construct from bool ***/
inline
Boolean_t::Boolean_t( bool other ) :
	_value(other)
{}

/*** swap value with another object ***/
inline void
Boolean_t::swap( Boolean_t& other ) {
	bool value = other._value;
	other._value = _value;
	_value = value;
}

/*** allow implicit conversion to bool ***/
inline
Boolean_t::operator bool() const {
	return _value;
}

/*** parsing and stringnify ***/
inline bool
Boolean_t::fromJson( const std::string& other ) {
	return fromJson(std::string(other));
}

inline std::string
Boolean_t::toJson() const {
	if( _value )
		return std::string("true");

	else
		return std::string("false");
}

} // namespace JSON

#endif /* H9600B189_BD18_449C_8C73_1373D3E6B864 */

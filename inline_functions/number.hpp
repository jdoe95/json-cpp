/*
 * number.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef H1E55D89D_1DC4_481B_9526_F789A751A5E2
#define H1E55D89D_1DC4_481B_9526_F789A751A5E2

namespace JSON
{
/*** construct as 0 ***/
inline
Number_t::Number_t() :
	_value(0.0)
{}

/***construct from arithmetic***/
template<typename Arithmetic_t, typename T> inline
Number_t::Number_t( Arithmetic_t value ) :
	_value(value)
{}

/*** swap value with another object ***/
inline void
Number_t::swap( Number_t& other ) {
	double value = other._value;
	other._value = _value;
	_value = value;
}

/*** allow implicit conversion to artithmetic ***/
template<typename Arithmetic_t, typename T> inline
Number_t::operator Arithmetic_t() const {
	return static_cast<Arithmetic_t>(_value);
}

/*** parsing and stringnify ***/
inline bool
Number_t::fromJson( const std::string& other ) {
	return fromJson( std::string(other) );
}

inline std::string
Number_t::toJson() const {
	return std::to_string(_value);
}

} // namespace JSON

#endif /* H1E55D89D_1DC4_481B_9526_F789A751A5E2 */

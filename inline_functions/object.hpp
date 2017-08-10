/*
 * object.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef HA58EDA85_6844_4792_804D_E5834884F7EF
#define HA58EDA85_6844_4792_804D_E5834884F7EF

namespace JSON
{
/*** swap value with another object ***/
inline void
Object_t::swap( Object_t& other ) {
	_map.swap(other._map);
}

/*** allow explicit conversion to bool ***/
inline
Object_t::operator bool() const {
	return ! _map.empty();
}

/*** element access ***/
inline Json_t&
Object_t::operator[]( const std::string& string ) {
	return _map[string];
}

inline Json_t
Object_t::operator[]( const std::string& string ) const {
	std::map<std::string, Json_t>::const_iterator result
		= _map.find(string);
	if( result == _map.end() )
		return Json_t();
	else
		return result->second;
}

/*** parsing and stringnify ***/
inline bool
Object_t::fromJson( const std::string& other ) {
	return fromJson( std::string(other) );
}

} // namespace JSON

#endif /* HA58EDA85_6844_4792_804D_E5834884F7EF */

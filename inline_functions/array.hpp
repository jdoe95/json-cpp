/*
 * array.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef H84103ED6_3B33_4623_B9A0_2B968810E9DF
#define H84103ED6_3B33_4623_B9A0_2B968810E9DF

namespace JSON
{
/*** swap with another array ***/
inline void
Array_t::swap( Array_t& other ) {
	_map.swap(other._map);
}

/*** allow explicit conversion to bool ***/
inline
Array_t::operator bool() const {
	return ! _map.empty();
}

/*** element access ***/
inline Json_t&
Array_t::operator[]( unsigned i ) {
	return _map[i];
}

inline Json_t
Array_t::operator[]( unsigned i ) const {
	std::map<unsigned, Json_t>::const_iterator result = _map.find(i);
	if( result == _map.end() )
		return Json_t();
	else
		return result->second;
}

/*** parsing and stringnify ***/
inline bool
Array_t::fromJson( const std::string& other ){
	return fromJson( std::string(other) );
}

} // namespace JSON

#endif /* H84103ED6_3B33_4623_B9A0_2B968810E9DF */

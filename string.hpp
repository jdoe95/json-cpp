/*
 * string.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef HE867BE1B_FC1E_46C9_BECC_FBFCE9A97BDC
#define HE867BE1B_FC1E_46C9_BECC_FBFCE9A97BDC

namespace JSON
{

struct String_t
{
	// construct as empty string
	String_t() = default;

	// construct from std::string
	String_t( const std::string& string );
	String_t( std::string&& string );

	// destruct
	~String_t() = default;

	// copy construct
	String_t( const String_t& other ) = default;

	// move construct
	String_t( String_t&& other ) = default;

	// copy assignment
	String_t& operator=( const String_t& other ) = default;

	// move assignment
	String_t& operator=( String_t&& other ) = default;

	// swap with another object
	void swap( String_t& other );

	// allow implicit conversion to string
	operator const char*() const;
	operator std::string() const;

	// allow explicit conversion to bool
	explicit operator bool() const;

	// parsing and stringnify
	bool fromJson( const std::string& other );
	bool fromJson( std::string&& other );
	std::string toJson() const;

private:
	std::string _string;
};

} // namespace JSON

#endif /* HE867BE1B_FC1E_46C9_BECC_FBFCE9A97BDC */

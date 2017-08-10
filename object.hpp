/*
 * object.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef H432B1EC8_86F2_4DB4_B5DF_0C81BF24B6FA
#define H432B1EC8_86F2_4DB4_B5DF_0C81BF24B6FA

namespace JSON
{

struct Json_t;

struct Object_t
{
	// construct as empty object
	Object_t() = default;

	// destruct
	~Object_t() = default;

	// copy construct
	Object_t( const Object_t& other ) = default;

	// move construct
	Object_t( Object_t&& other ) = default;

	// copy assignment
	Object_t& operator=( const Object_t& other ) = default;

	// move assignment
	Object_t& operator=( Object_t&& other ) = default;

	// swap value with another object
	void swap( Object_t& other );

	// allow explicit conversion to bool
	explicit operator bool() const;

	// element access
	Json_t& operator[]( const std::string& string );
	Json_t operator[]( const std::string& string ) const;

	// parsing and stringnify
	bool fromJson( const std::string& other );
	bool fromJson( std::string&& other );
	std::string toJson() const;

private:
	std::map<std::string, Json_t> _map;
};

} // namespace JSON

#endif /* H432B1EC8_86F2_4DB4_B5DF_0C81BF24B6FA */

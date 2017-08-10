/*
 * array.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef H1CE947F9_BD3A_492A_8141_F3D1C08A4D26
#define H1CE947F9_BD3A_492A_8141_F3D1C08A4D26

namespace JSON
{
struct Json_t;

struct Array_t
{
	// construct as empty array
	Array_t() = default;

	// destruct
	~Array_t() = default;

	// copy construct
	Array_t( const Array_t& other ) = default;

	// move construct
	Array_t( Array_t&& other ) = default;

	// copy assignment
	Array_t& operator=( const Array_t& other ) = default;

	// move assignment
	Array_t& operator=( Array_t&& other ) = default;

	// swap value with another array
	void swap( Array_t& other );

	// allow explicit conversion to bool
	explicit operator bool() const;

	// element access
	Json_t& operator[]( unsigned i );
	Json_t operator[]( unsigned i ) const;

	// parsing and stringnify
	bool fromJson( const std::string& other );
	bool fromJson( std::string&& other );
	std::string toJson() const;

private:
	std::map<unsigned, Json_t> _map;
};

} // namespace JSON

#endif /* H1CE947F9_BD3A_492A_8141_F3D1C08A4D26 */

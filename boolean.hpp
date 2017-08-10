/*
 * boolean.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef HA79E5945_A85C_4D51_9B16_DFE61F394472
#define HA79E5945_A85C_4D51_9B16_DFE61F394472

namespace JSON
{
struct Boolean_t
{
	// construct as false
	Boolean_t();

	// construct from bool
	Boolean_t( bool other );

	// destruct
	~Boolean_t() = default;

	// copy construct
	Boolean_t( const Boolean_t& other ) = default;

	// copy assignment
	Boolean_t& operator=( const Boolean_t& other ) = default;

	// swap value with another object
	void swap( Boolean_t& other );

	// allow implicit conversion to bool
	operator bool () const;

	// parsing and stringnify
	bool fromJson( const std::string& other );
	bool fromJson( std::string&& other );
	std::string toJson() const;

private:
	bool _value;
};

} // namespace JSON

#endif /* HA79E5945_A85C_4D51_9B16_DFE61F394472 */

/*
 * number.hpp
 *
 *  Created on: Aug 7, 2017
 *      Author: jdoe
 */

#ifndef HA83FD511_0115_4905_9CD6_8C2518569350
#define HA83FD511_0115_4905_9CD6_8C2518569350

namespace JSON
{

struct Number_t
{
	// construct as 0
	Number_t();

	// construct from arithmetic
	template<typename Arithmetic_t, typename T
		= typename std::enable_if<std::is_arithmetic<Arithmetic_t>::value, Arithmetic_t>::type>
	Number_t( Arithmetic_t value );

	// destruct
	~Number_t() = default;

	// copy construct
	Number_t( const Number_t& other ) = default;

	// copy assignment
	Number_t& operator=( const Number_t& other ) = default;

	// swap value with another object
	void swap( Number_t& other );

	// allow implicit conversion to arithmetic
	template<typename Arithmetic_t, typename T
		= typename std::enable_if<std::is_arithmetic<Arithmetic_t>::value>::type>
	operator Arithmetic_t() const;

	// parsing and stringnify
	bool fromJson( const std::string& other );
	bool fromJson( std::string&& other );
	std::string toJson() const;

private:
	double _value;

};

} // namespace JSON

#endif /* HA83FD511_0115_4905_9CD6_8C2518569350 */

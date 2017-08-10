/*
 * json.hpp
 *
 *  Created on: Aug 6, 2017
 *      Author: jdoe
 */

#ifndef H8FE14B28_F434_4729_A433_9CFC3F6E9B51
#define H8FE14B28_F434_4729_A433_9CFC3F6E9B51

#include <cstdlib>
#include <utility>
#include <type_traits>
#include <algorithm>
#include <string>
#include <map>
#include <list>

// class and function prototype
#include "boolean.hpp"
#include "number.hpp"
#include "string.hpp"
#include "array.hpp"
#include "object.hpp"
#include "helpers.hpp"

namespace JSON
{
// Generic JSON Class (Tagged Union)
struct Json_t
{
	// tag
	enum class Type_t : uint8_t
	{
		DELETED = 0,
		STRING,
		NUMBER,
		OBJECT,
		ARRAY,
		BOOLEAN
	};

	// construct as null
	Json_t();

	// construct as boolean
	Json_t( bool value );
	Json_t( const Boolean_t& other );
	Json_t( Boolean_t&& other );

	// construct as number
	template<typename Arithmetic_t, typename T
		= typename std::enable_if<std::is_arithmetic<Arithmetic_t>::value, Arithmetic_t>::type>
	Json_t( Arithmetic_t value );
	Json_t( const Number_t& other );
	Json_t( Number_t&& number );

	// construct as string
	Json_t( const char* other );
	Json_t( const std::string& other );
	Json_t( std::string&& other );
	Json_t( const String_t& other );
	Json_t( String_t&& other );

	// construct as object
	Json_t( const Object_t& object );
	Json_t( Object_t&& object );

	// construct as array
	Json_t( const Array_t& array );
	Json_t( Array_t&& array );

	// copy construct
	Json_t( const Json_t& other );

	// move construct
	Json_t( Json_t&& other );

	// destruct
	~Json_t();
	void clear();

	// copy assignment
	Json_t& operator=( const Json_t& other );

	// move assignment
	Json_t& operator=( Json_t&& other );

	// swap value with another object
	void swap(Json_t& other);

	// type observers
	bool isDeleted() const;
	bool isBoolean() const;
	bool isString() const;
	bool isNumber() const;
	bool isArray() const;
	bool isObject() const;
	Type_t type() const;

	// allow implicit conversion to boolean
	operator bool() const;
	operator Boolean_t() const;

	// allow implicit conversion to arithmetic
	template<typename Arithmetic_t, typename T
		= typename std::enable_if<std::is_arithmetic<Arithmetic_t>::value, Arithmetic_t>::type>
	operator Arithmetic_t() const;
	operator Number_t() const;

	// allow implicit conversion to string
	operator std::string() const;
	operator const char*() const;
	operator String_t() const;

	// allow implicit conversion to array
	operator Array_t() const;

	// allow implicit conversion to object
	operator Object_t() const;

	// operator overload for object
	Json_t& operator[]( const char* other );
	Json_t& operator[]( const std::string& other );
	Json_t operator[]( const char* other ) const;
	Json_t operator[]( const std::string& other ) const;

	// operator overload for array
	Json_t& operator[]( unsigned n );
	Json_t operator[]( unsigned n ) const;

	// parsing and stringnify
	bool fromJson( const std::string& other );
	bool fromJson( std::string&& other );
	std::string toJson() const;

private:
	Type_t _type;

	union
	{
		void *_generic;
		Object_t *_object;
		Array_t *_array;
		String_t *_string;
		Boolean_t *_boolean;
		Number_t *_number;
	};
}; // class Json_t

} // namespace JSON

// member function definitions

#include "inline_functions/helpers.hpp"
#include "inline_functions/json.hpp"
#include "inline_functions/boolean.hpp"
#include "inline_functions/number.hpp"
#include "inline_functions/string.hpp"
#include "inline_functions/array.hpp"
#include "inline_functions/object.hpp"

#endif /* H8FE14B28_F434_4729_A433_9CFC3F6E9B51 */

/*
 * json.hpp
 *
 *  Created on: Aug 6, 2017
 *      Author: jdoe
 */

#ifndef H36D31A08_7903_4826_A4A8_BF392B86C41E
#define H36D31A08_7903_4826_A4A8_BF392B86C41E

namespace JSON
{
/*** construct as null ***/
inline
Json_t::Json_t() :
	_type(Type_t::DELETED)
{}

/*** construct as boolean ***/
inline
Json_t::Json_t( bool value ) :
	_type(Type_t::BOOLEAN),
	_boolean(new Boolean_t(value))
{}

inline
Json_t::Json_t( const Boolean_t& other ) :
	_type(Type_t::BOOLEAN),
	_boolean(new Boolean_t(other))
{}

inline
Json_t::Json_t( Boolean_t&& other ) :
	_type(Type_t::BOOLEAN),
	_boolean(new Boolean_t(std::move(other)))
{}

/*** construct as number ***/
template<typename Arithmetic_t, typename T> inline
Json_t::Json_t(Arithmetic_t value) :
	_type(Type_t::NUMBER),
	_number(new Number_t(value))
{}

inline
Json_t::Json_t( const Number_t& other ) :
	_type(Type_t::NUMBER),
	_number(new Number_t(other))
{}

inline
Json_t::Json_t( Number_t&& other ) :
	_type(Type_t::NUMBER),
	_number(new Number_t(std::move(other)))
{}

/*** construct as string ***/
inline
Json_t::Json_t( const char* other ) :
	_type(Type_t::STRING),
	_string(new String_t(other))
{}

inline
Json_t::Json_t( const std::string& other ) :
	_type( Type_t::STRING),
	_string(new String_t(other))
{}

inline
Json_t::Json_t( std::string&& other ) :
	_type( Type_t::STRING ),
	_string(new String_t(std::move(other)))
{}

inline
Json_t::Json_t( const String_t& other ) :
	_type(Type_t::STRING),
	_string(new String_t(other) )
{}

inline
Json_t::Json_t( String_t&& other ) :
	_type(Type_t::STRING),
	_string(new String_t(std::move(other)) )
{}

/*** construct as object ***/
inline
Json_t::Json_t( const Object_t& object ) :
	_type(Type_t::OBJECT),
	_object(new Object_t(object))
{}

inline
Json_t::Json_t( Object_t&& object ) :
	_type(Type_t::OBJECT),
	_object(new Object_t(std::move(object)))
{}

/*** construct as array ***/
inline
Json_t::Json_t( const Array_t& array ) :
	_type( Type_t::ARRAY ),
	_array( new Array_t(array))
{}

inline
Json_t::Json_t( Array_t&& array ) :
	_type(Type_t::ARRAY),
	_array(new Array_t(std::move(array)))
{}

/*** copy construct ***/
inline
Json_t::Json_t( const Json_t& other )
{
	operator=(other);
}

/*** move construct ***/
inline
Json_t::Json_t( Json_t&& other )
{
	operator=(std::move(other));
}

/*** destruct ***/
inline
Json_t::~Json_t() {
	clear();
}

/*** move assignment ***/
inline Json_t&
Json_t::operator=( Json_t&& other )
{
	clear();
	_type = other._type;
	_generic = other._generic;
	other._type = Type_t::DELETED;
	return *this;
}

/*** type observers ***/
inline bool
Json_t::isDeleted() const {
	return _type == Type_t::DELETED;
}

inline bool
Json_t::isBoolean() const {
	return _type == Type_t::BOOLEAN;
}

inline bool
Json_t::isString() const {
	return _type == Type_t::STRING;
}

inline bool
Json_t::isNumber() const {
	return _type == Type_t::NUMBER;
}

inline bool
Json_t::isArray() const {
	return _type == Type_t::ARRAY;
}

inline bool
Json_t::isObject() const {
	return _type == Type_t::OBJECT;
}

inline Json_t::Type_t
Json_t::type() const {
	return _type;
}

/*** allow implicit conversion to boolean ***/
inline
Json_t::operator Boolean_t() const {
	if( isBoolean() )
		return *_boolean;
	else
		return Boolean_t();
}

/*** allow implicit conversion to arithmetic ***/
template<typename Arithmetic_t, typename T> inline
Json_t::operator Arithmetic_t() const {
	if( isNumber() )
		return static_cast<Arithmetic_t>(*_number);
	else
		return Arithmetic_t();
}

inline
Json_t::operator Number_t() const {
	if( isNumber() )
		return *_number;
	else
		return Number_t();
}

/*** allow implicit conversion to string ***/
inline
Json_t::operator std::string() const {
	if( isString() )
		return _string->operator std::string();
	else
		return std::string();
}

inline
Json_t::operator const char*() const {
	if( isString() )
		return _string->operator const char*();
	else
		return nullptr;
}

inline
Json_t::operator String_t() const {
	if( isString() )
		return *_string;
	else
		return String_t();
}

/*** allow implicit conversion to array ***/
inline
Json_t::operator Array_t() const {
	if( isArray() )
		return *_array;
	else
		return Array_t();
}

/*** allow implicit conversion to object ***/
inline
Json_t::operator Object_t() const {
	if( isObject() )
		return *_object;
	else
		return Object_t();
}

/*** operator overload for object ***/
inline Json_t&
Json_t::operator[]( const char* other ) {
	if( ! isObject() )
		operator=(Json_t( Object_t() ));

	return _object->operator[](other);
}

inline Json_t&
Json_t::operator[]( const std::string& other ) {
	if( ! isObject() )
		operator=(Json_t(Object_t() ));

	return _object->operator[](other);
}

inline Json_t
Json_t::operator[]( const char* other ) const {
	if( isObject() )
		return _object->operator[](other);
	else
		return Json_t();
}

inline Json_t
Json_t::operator[]( const std::string& other ) const {
	if( isObject() )
		return _object->operator[](other);
	else
		return Json_t();
}

/*** operator overload for array ***/
inline Json_t&
Json_t::operator[]( unsigned n ) {
	if( ! isArray() )
		operator=(Json_t(Array_t() ));

	return _array->operator[](n);
}

inline Json_t
Json_t::operator[]( unsigned n ) const {
	if( isArray() )
		return _array->operator[](n);
	else
		return Json_t();
}

/*** parsing and stringnify ***/
inline bool
Json_t::fromJson( const std::string& other ) {
	return fromJson( std::string(other) );
}

} // namespace JSON

#endif /* H36D31A08_7903_4826_A4A8_BF392B86C41E */

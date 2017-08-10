/*
 * json.cpp
 *
 *  Created on: Aug 6, 2017
 *      Author: jdoe
 */
#include "../json.hpp"

using namespace JSON;

/*** copy assignment ***/
Json_t&
Json_t::operator=( const Json_t& other )
{
	clear();
	_type = other._type;

	// call specific object constructor
	switch(_type)
	{
	case Type_t::BOOLEAN:
		_boolean = new Boolean_t(*other._boolean);
		break;

	case Type_t::ARRAY:
		_array = new Array_t(*other._array);
		break;

	case Type_t::OBJECT:
		_object = new Object_t(*other._object);
		break;

	case Type_t::NUMBER:
		_number = new Number_t(*other._number);
		break;

	case Type_t::STRING:
		_string = new String_t(*other._string);
		break;

	case Type_t::DELETED:
	default:
		break;
	}

	return *this;
}

/*** destruct ***/
void
Json_t::clear()
{
	// call specific object destructor
	switch(_type)
	{
	case Type_t::BOOLEAN:
		delete _boolean;
		break;

	case Type_t::ARRAY:
		delete _array;
		break;

	case Type_t::OBJECT:
		delete _object;
		break;

	case Type_t::NUMBER:
		delete _number;
		break;

	case Type_t::STRING:
		delete _string;
		break;

	case Type_t::DELETED:
	default:
		break;
	}
}

/*** swap value with another object */
void
Json_t::swap( Json_t& other ) {
	Type_t type = other._type;
	other._type = _type;
	_type = type;

	void *generic = other._generic;
	other._generic = _generic;
	_generic = generic;
}

/*** allow implicit conversion to boolean ***/
Json_t::operator bool() const
{
	switch(_type)
	{
	case Type_t::BOOLEAN:
		return _boolean->operator bool();

	case Type_t::ARRAY:
		return _array->operator bool();

	case Type_t::OBJECT:
		return _object->operator bool();

	case Type_t::NUMBER:
		return _number->operator bool();

	case Type_t::STRING:
		return _string->operator bool();

	case Type_t::DELETED:
	default:
		return false;
	}
}

/*** parsing and stringnify ***/
bool
Json_t::fromJson( std::string&& other ) {

	// assume deleted
	if( other == "null" ) {
		operator=(Json_t());
		return true;
	}

	// assume string
	String_t string;
	if( string.fromJson(other) ) {
		operator=(Json_t(std::move(string)));
		return true;
	}

	// assume boolean
	Boolean_t boolean;
	if( boolean.fromJson(other) ) {
		operator=(Json_t(std::move(boolean)));
		return true;
	}

	// assume number
	Number_t number;
	if( number.fromJson(other) ) {
		operator=(Json_t(std::move(number)) );
		return true;
	}

	// assume object
	Object_t object;
	if( object.fromJson(other) ) {
		operator=(Json_t(std::move(object) ) );
		return true;
	}

	// assume array
	Array_t array;
	if( array.fromJson(other) ) {
		operator=(Json_t(std::move(array) ) );
		return true;
	}

	return false;
}

std::string
Json_t::toJson() const {
	switch(_type)
	{
	case Type_t::BOOLEAN :
		return _boolean->toJson();

	case Type_t::ARRAY :
		return _array->toJson();

	case Type_t::OBJECT :
		return _object->toJson();

	case Type_t::NUMBER :
		return _number->toJson();

	case Type_t::STRING :
		return _string->toJson();

	case Type_t::DELETED:
	default:
		return std::string( "null" );
	}
}


/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cppfontconfig.
 *
 *  cppfontconfig is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cppfontconfig is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cppfontconfig.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  @file   include/cppfontconfig/name.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFONTCONFIG_NAME_H_
#define CPPFONTCONFIG_NAME_H_


#include <cppfontconfig/common.h>
#include <cppfontconfig/ObjectType.h>
#include <cppfontconfig/Constant.h>

namespace fontconfig {



/// utility class for building a static list of ObjectTypes, replaces
/// static allocation of a list of FcObjectType objects
/**
 *  Example usage:
 *
 *  \code{.cpp}
 *      ObjectTypeList list = ObjectTypeList::create()
 *          ( "ObjectA", type::Integer )
 *          ( "ObjectB", type::String  )
 *          ( "ObjectC", type::Double  )
 *          ();
 *  \endcode
 */
class ObjectTypeList
{
    public:
        class Item;

    private:
        void*   m_ptr;
        int     m_iItem;
        int     m_nItems;
        bool    m_selfDestruct;

        ObjectTypeList(bool selfDestruct);
        ObjectTypeList(const ObjectTypeList& other );

    public:
        void* get_ptr();
        const void* get_ptr() const;
        int get_nItems() const;

        friend class Item;

        /// will destroy underlying data if m_selfDestruct is true, otherwise
        /// does nothing
        /**
         *  self destruct is only set true on the object returned from
         *  Item::finish. There is an additional temporary which is created
         *  on the heap and destroyed by Item::finish, and that one does
         *  not destroy the underlying data
         */
        ~ObjectTypeList();

        /// creates a new Object type list, and returns an item which points
        /// to it
        static Item create();

        /// increments the item count
        /**
         *  Called by Item constructor
         */
        void incrementCount();

        /// allocates the object type buffer given the current value of
        /// m_nItems
        /**
         *  Called by Item::operator()()
         */
        void allocate();

        /// writes data and increments counter, returns true if this is the
        /// last item
        /**
         *  Called by Item d'tor
         */
        bool write( const char* object, Type_t type );




};

class ObjectTypeList::Item
{
    private:
        ObjectTypeList*     m_list;
        const char*         m_object;
        Type_t              m_type;

    public:
        /// initializes the item as an empty last item and increments the
        /// number of items in the list
        Item( ObjectTypeList* list );

        /// writes the item data to the list
        ~Item();

        /// fills this item, increments the item count,  and returns a new item;
        Item operator()( const char* object, Type_t type );

        /// finalizes the initialization by signaling the list to allocate
        /// data, the data is filled by ~Item()
        ObjectTypeList operator()();
};




/// utility class for building a static list of ObjectTypes, replaces
/// static allocation of a list of FcObjectType objects
/**
 *  Example usage:
 *
 *  \code{.cpp}
 *      ConstantList list = ConstantList::create()
 *          ( "NameA", "ObjectA", 1001 )
 *          ( "NameB", "ObjectB", 1002  )
 *          ( "NameC", "ObjectC", 1003  )
 *          ();
 *  \endcode
 */
class ConstantList
{
    public:
        class Item;

    private:
        void*   m_ptr;
        int     m_iItem;
        int     m_nItems;
        bool    m_selfDestruct;

        ConstantList(bool selfDestruct);
        ConstantList(const ConstantList& other );

    public:
        void* get_ptr();
        const void* get_ptr() const;
        int get_nItems() const;

        friend class Item;

        /// will destroy underlying data if m_selfDestruct is true, otherwise
        /// does nothing
        /**
         *  self destruct is only set true on the object returned from
         *  Item::finish. There is an additional temporary which is created
         *  on the heap and destroyed by Item::finish, and that one does
         *  not destroy the underlying data
         */
        ~ConstantList();

        /// creates a new Object type list, and returns an item which points
        /// to it
        static Item create();

        /// increments the item count
        /**
         *  Called by Item constructor
         */
        void incrementCount();

        /// allocates the object type buffer given the current value of
        /// m_nItems
        /**
         *  Called by Item::operator()()
         */
        void allocate();

        /// writes data and increments counter, returns true if this is the
        /// last item
        /**
         *  Called by Item d'tor
         */
        bool write( const Char8_t* name, const char* object, int value );




};

class ConstantList::Item
{
    private:
        ConstantList*   m_list;
        const Char8_t*  m_name;
        const char*     m_object;
        int             m_value;

    public:
        /// initializes the item as an empty last item and increments the
        /// number of items in the list
        Item( ConstantList* list );

        /// writes the item data to the list
        ~Item();

        /// fills this item, increments the item count,  and returns a new item;
        Item operator()( const Char8_t* name, const char* object, int value );

        /// finalizes the initialization by signaling the list to allocate
        /// data, the data is filled by ~Item()
        ConstantList operator()();
};



namespace       name {

/// Register object types
/**
 *  Register ntype new object types. Returns FcFalse if some of the names
 *  cannot be registered (due to allocation failure). Otherwise returns FcTrue.
 */
bool registerObjectTypes( const ObjectTypeList& list );

/// Unregister object types
/**
 *  Unregister ntype object types. Returns FcTrue.
 */
bool unregisterObjectTypes( const ObjectTypeList& list );

/// Lookup an object type
/**
 *  Return the object type for the pattern element named object.
 */
ObjectType getObjectType( const char* object );

/// Register symbolic constants
/**
 *  Register nconsts new symbolic constants. Returns FcFalse if the constants
 *  cannot be registered (due to allocation failure). Otherwise returns FcTrue.
 */
bool registerConstants( const ConstantList& list );

/// Unregister symbolic constants
/**
 *  Unregister nconsts symbolic constants. Returns FcFalse if the specified
 *  constants were not registered. Otherwise returns FcTrue.
 */
bool unregisterConstants( const ConstantList& list );

/// Lookup symbolic constant
/**
 *  Return the FcConstant structure related to symbolic constant string.
 */
Constant getConstant(Char8_t* string);

/// Get the value for a symbolic constant
/**
 *  Returns whether a symbolic constant with name string is registered,
 *  placing the value of the constant in result if present.
 */
bool constant( Char8_t* string, int* result );



}
}














#endif // NAME_H_

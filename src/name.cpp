/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of Fontconfigmm.
 *
 *  Fontconfigmm is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Fontconfigmm is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Fontconfigmm.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  \file   name.cpp
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <fontconfigmm/name.h>
#include <fontconfig/fontconfig.h>
#include <cassert>

namespace fontconfig
{

ObjectTypeList::ObjectTypeList(bool selfDestruct):
    m_ptr(0),
    m_iItem(0),
    m_nItems(0),
    m_selfDestruct(selfDestruct)
{

}

ObjectTypeList::ObjectTypeList(const ObjectTypeList& other):
    m_ptr(other.m_ptr),
    m_iItem(0),
    m_nItems(other.m_nItems),
    m_selfDestruct(!other.m_selfDestruct)
{

}

void* ObjectTypeList::get_ptr()
{
    return m_ptr;
}

const void* ObjectTypeList::get_ptr() const
{
    return m_ptr;
}

int ObjectTypeList::get_nItems() const
{
    return m_nItems;
}

ObjectTypeList::~ObjectTypeList()
{
    if(m_selfDestruct)
        delete [] (FcObjectType*)m_ptr;
}

void ObjectTypeList::incrementCount()
{
    assert( !m_ptr );
    m_nItems++;
}

void ObjectTypeList::allocate()
{
    assert( !m_ptr );
    m_ptr = new FcObjectType[m_nItems];
}

bool ObjectTypeList::write( const char* object, Type_t type )
{
    assert( m_iItem < m_nItems );

    FcObjectType* ptr = (FcObjectType*)m_ptr;
    ptr[m_iItem].object = object;
    ptr[m_iItem].type   = (FcType)type;
    m_iItem++;

    return (m_iItem == m_nItems);
}

ObjectTypeList::Item ObjectTypeList::create()
{
    ObjectTypeList* list = new ObjectTypeList(false);
    return Item(list);
}


ObjectTypeList::Item::Item( ObjectTypeList* list ):
    m_list(list),
    m_object(0),
    m_type(type::Void)
{

}

ObjectTypeList::Item::~Item()
{
    if( m_list->write(m_object,m_type) )
        delete m_list;
}

ObjectTypeList::Item ObjectTypeList::Item::operator()( const char* object, Type_t type )
{
    m_object = object;
    m_type   = type;
    return Item(m_list);
}

ObjectTypeList ObjectTypeList::Item::operator()()
{
    m_list->allocate();
    return *m_list;
}










ConstantList::ConstantList(bool selfDestruct):
    m_ptr(0),
    m_iItem(0),
    m_nItems(0),
    m_selfDestruct(selfDestruct)
{
}

ConstantList::ConstantList(const ConstantList& other):
    m_ptr(other.m_ptr),
    m_iItem(0),
    m_nItems(other.m_nItems),
    m_selfDestruct(!other.m_selfDestruct)
{
}

void* ConstantList::get_ptr()
{
    return m_ptr;
}

const void* ConstantList::get_ptr() const
{
    return m_ptr;
}

int ConstantList::get_nItems() const
{
    return m_nItems;
}

ConstantList::~ConstantList()
{
     if(m_selfDestruct)
        delete [] (FcConstant*)m_ptr;
}

ConstantList::Item ConstantList::create()
{
    ConstantList* list = new ConstantList(false);
    return Item(list);
}

void ConstantList::incrementCount()
{
    assert( !m_ptr );
    m_nItems++;
}

void ConstantList::allocate()
{
    assert( !m_ptr );
    m_ptr = new FcObjectType[m_nItems];
}


bool ConstantList::write( const Char8_t* name, const char* object, int value )
{
    assert( m_iItem < m_nItems );

    FcConstant* ptr = (FcConstant*)m_ptr;
    ptr[m_iItem].name   = name;
    ptr[m_iItem].object = object;
    ptr[m_iItem].value  = value;
    m_iItem++;

    return (m_iItem == m_nItems);
}

ConstantList::Item::Item(ConstantList* list):
    m_list(list),
    m_name(0),
    m_object(0),
    m_value(0)
{
}

ConstantList::Item::~Item()
{
    if( m_list->write(m_name,m_object,m_value) )
        delete m_list;
}

ConstantList::Item ConstantList::Item::operator ()(
        const Char8_t* name, const char* object, int value)
{
    m_name      = name;
    m_object    = object;
    m_value     = value;

    return Item(m_list);
}

ConstantList ConstantList::Item::operator ()()
{
    m_list->allocate();
    return *m_list;
}



















namespace name
{


bool registerObjectTypes( const ObjectTypeList& list )
{
    return FcNameRegisterObjectTypes(
            (const FcObjectType*)list.get_ptr(),
            list.get_nItems() );
}

bool unregisterObjectTypes( const ObjectTypeList& list )
{
    return FcNameUnregisterObjectTypes(
            (const FcObjectType*)list.get_ptr(),
            list.get_nItems() );
}

ObjectType getObjectType( const char* object )
{
    return ObjectType(  FcNameGetObjectType(object) );
}

bool registerConstants(const ConstantList& list)
{
    return FcNameRegisterConstants(
                (const FcConstant*)list.get_ptr(),
                list.get_nItems() );
}

bool unregisterConstants(const ConstantList& list)
{
    return FcNameUnregisterConstants(
                (const FcConstant*)list.get_ptr(),
                list.get_nItems() );
}

Constant getConstant(Char8_t* string)
{
    return Constant( FcNameGetConstant(string) );
}

bool constant(Char8_t* string, int* result)
{
    return FcNameConstant(string, result);
}














}
}












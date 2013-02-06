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
 *  @file   include/cppfontconfig/ObjectSet.h
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFONTCONFIG_OBJECTSET_H_
#define CPPFONTCONFIG_OBJECTSET_H_

namespace fontconfig
{




/// holds a set of names and is used to specify which fields from fonts are
/// placed in the the list of returned patterns when listing fonts.
/**
 *  ObjectSet's are not reference counted. You may copy an object set but be
 *  sure to only destroy one of the copies.
 */
class ObjectSet
{
    public:
        class Builder;

    private:
        void* m_ptr;

        /// wrap constructor
        ObjectSet(void* ptr);

    public:
        void* get_ptr();
        const void* get_ptr() const;

        /// Create an object set
        /**
         *  Creates an empty set.
         */
        static ObjectSet create();

        /// Add to an object set
        /**
         *  Adds a property name to the set. Returns FcFalse if the property
         *  name cannot be inserted into the set (due to allocation failure).
         *  Otherwise returns FcTrue.
         */
        bool add( const char* obj );

        /// Destroy an object set
        /**
         *  Destroys an object set.
         */
        void destroy();

        /// Build object set from args
        /**
         *  These build an object set from a null-terminated list of property
         *  names.
         */
        static ObjectSet build( const char* first, ... );

};


class ObjectSet::Builder
{
    private:
        ObjectSet m_objset;

    public:
        Builder( ObjectSet objset );

        Builder& operator()(const char* object);

        ObjectSet done();
};

} // namespace fontconfig 

#endif // OBJECTSET_H_

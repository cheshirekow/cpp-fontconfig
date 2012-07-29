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
 *  \file   Pattern.cpp
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfontconfig/Pattern.h>
#include <cppfontconfig/Config.h>
#include <fontconfig/fontconfig.h>

namespace fontconfig
{

Pattern::Builder::Builder(Pattern pattern):
    m_pattern(pattern)
{
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, int i)
{
    m_pattern.add(obj,i);
    return *this;
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, double d)
{
    m_pattern.add(obj,d);
    return *this;
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, Char8_t* s)
{
    m_pattern.add(obj,s);
    return *this;
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, const Matrix& m)
{
    m_pattern.add(obj,m);
    return *this;
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, const CharSet& cs)
{
    m_pattern.add(obj,cs);
    return *this;
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, bool b)
{
    m_pattern.add(obj,b);
    return *this;
}

Pattern::Builder& Pattern::Builder::operator ()(const char* obj, const LangSet& ls)
{
    m_pattern.add(obj,ls);
    return *this;
}

Pattern Pattern::Builder::done()
{
    return m_pattern;
}




Pattern::Pattern(void* ptr):
    m_ptr(ptr)
{

}

Pattern::Pattern(const Pattern& other)
{
    m_ptr = other.m_ptr;
    FcPatternReference( (FcPattern*)other.m_ptr);
}

Pattern::~Pattern()
{
    FcPatternDestroy( (FcPattern*)m_ptr );
}

void* Pattern::get_ptr()
{
    return m_ptr;
}

const void* Pattern::get_ptr() const
{
    return m_ptr;
}

Pattern& Pattern::operator=( const Pattern& other )
{
    FcPatternDestroy( (FcPattern*)m_ptr );
    m_ptr = other.m_ptr;
    FcPatternReference( (FcPattern*)other.m_ptr);

    return *this;
}

Pattern Pattern::create(void)
{
    return Pattern( FcPatternCreate() );
}

Pattern Pattern::duplicate()
{
    return Pattern( FcPatternDuplicate( (FcPattern*)m_ptr ) );
}

Pattern Pattern::filter(const ObjectSet& os)
{
    return Pattern(
            FcPatternFilter( (FcPattern*)m_ptr,
                            (const FcObjectSet*)os.get_ptr() ) );
}

bool Pattern::equal(const Pattern& pb)
{
    return FcPatternEqual( (FcPattern*)m_ptr,
                            (const FcPattern*) pb.m_ptr );
}

bool Pattern::equalSubset(const Pattern& pb, const ObjectSet& os)
{
    return FcPatternEqualSubset(
                (FcPattern*)m_ptr,
                (const FcPattern*) pb.m_ptr,
                (const FcObjectSet*) os.get_ptr() );

}

Char32_t Pattern::hash()
{
    return FcPatternHash( (FcPattern*)m_ptr );
}

bool Pattern::del(const char* object)
{
    return FcPatternDel( (FcPattern*)m_ptr, object );
}

bool Pattern::remove(const char* object, int id)
{
    return FcPatternRemove( (FcPattern*)m_ptr, object, id );
}

bool Pattern::add(const char* obj, int i)
{
    return FcPatternAddInteger( (FcPattern*)m_ptr, obj, i );
}

bool Pattern::add(const char* obj, double d)
{
    return FcPatternAddDouble( (FcPattern*)m_ptr, obj, d );
}

bool Pattern::add(const char* obj, const Char8_t* s)
{
    return FcPatternAddString( (FcPattern*)m_ptr, obj, s );
}

bool Pattern::add(const char* obj, const Matrix& m)
{
    return FcPatternAddMatrix( (FcPattern*)m_ptr,
                                obj,
                                (FcMatrix*)m.get_ptr() );
}

bool Pattern::add(const char* obj, const CharSet& c)
{
    return FcPatternAddCharSet( (FcPattern*)m_ptr,
                                obj,
                                (const FcCharSet*)c.get_ptr() );
}

bool Pattern::add(const char* obj, bool b)
{
    return FcPatternAddBool( (FcPattern*)m_ptr,
                                obj,
                                b ? FcTrue : FcFalse );
}

bool Pattern::add(const char* obj, const LangSet& ls)
{
    return FcPatternAddLangSet( (FcPattern*)m_ptr,
                                obj,
                                (const FcLangSet*)ls.get_ptr() );
}

Result_t Pattern::get(const char* obj, int n, int& i)
{
    return (Result_t)FcPatternGetInteger( (FcPattern*)m_ptr, obj, n, &i );
}

Result_t Pattern::get(const char* obj, int n, double& d)
{
    return (Result_t)FcPatternGetDouble( (FcPattern*)m_ptr, obj, n, &d );
}

Result_t Pattern::get(const char* obj, int n, Char8_t*& s)
{
    return (Result_t)FcPatternGetString( (FcPattern*)m_ptr, obj, n, &s );
}


// FIXME: Figure out what to do about matrices... if we do what we're doing now,
// the got matrix is not modifiable, or rather, if modified the matrix stored
// in the pattern wont get those changes
Result_t Pattern::get(const char* obj, int n, Matrix& m)
{
    FcMatrix* mm;
    Result_t result =
            (Result_t)FcPatternGetMatrix( (FcPattern*)m_ptr, obj, n, &mm );
    FcMatrix* mm_out = (FcMatrix*)m.get_ptr();

    *mm_out = *mm;

    return result;
}

Result_t Pattern::get(const char* obj, int n, CharSet& c)
{
    FcCharSet* cc = (FcCharSet*)c.get_ptr();
    Result_t result =
            (Result_t)FcPatternGetCharSet( (FcPattern*)m_ptr, obj, n, &cc );

    // char sets are reference counted so we need to increment the reference
    // since we're taking a pointer to it
    c = CharSet( FcCharSetCopy(cc) );

    return result;
}

Result_t Pattern::get(const char* obj, int n, bool& b)
{
    FcBool bb;
    Result_t result =
            (Result_t)FcPatternGetBool( (FcPattern*)m_ptr, obj, n, &bb );
    b = bb != 0;
    return result;
}

Result_t Pattern::get(const char* obj, int n, LangSet& ls)
{
    FcLangSet* lss;
    Result_t result =
            (Result_t)FcPatternGetLangSet( (FcPattern*)m_ptr, obj, n, &lss );

    ls = LangSet( lss );
    return result;
}

Pattern::Builder Pattern::build( )
{
    return Builder(this);
}

Pattern::Builder Pattern::buildNew( )
{
    Pattern result = Pattern::create();
    return result.build();
}

Pattern Pattern::parse(const Char8_t* name)
{
    return Pattern( FcNameParse( name ) );
}

Char8_t* Pattern::unparse()
{
    return FcNameUnparse( (FcPattern*)m_ptr );
}

Char8_t* Pattern::format(const Char8_t* format)
{
    return FcPatternFormat( (FcPattern*)m_ptr, format );
}

void Pattern::print()
{
    return FcPatternPrint( (FcPattern*)m_ptr );
}

void Pattern::defaultSubstitute()
{
    return FcDefaultSubstitute( (FcPattern*)m_ptr );
}

bool Pattern::substitute(Config c, MatchKind_t kind)
{
    return c.substitute(*this,kind);
}

bool Pattern::substitute(MatchKind_t kind)
{
    return FcConfigSubstitute(
                (FcConfig*)0,
                (FcPattern*)m_ptr,
                (FcMatchKind)kind );
}

}


 // namespace fontconfig 

/*
 *  \file   Pattern.h
 *
 *  \date   Jul 20, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_PATTERN_H_
#define FONTCONFIGMM_PATTERN_H_

#include <fontconfigmm/common.h>
#include <fontconfigmm/CharSet.h>
#include <fontconfigmm/LangSet.h>
#include "fontconfigmm/Matrix.h"
#include <fontconfigmm/ObjectSet.h>

namespace fontconfig
{


/// holds a set of names with associated value lists;
/**
 *  each name refers to a property of a font. FcPatterns are used as inputs to
 *  the matching code as well as holding information about specific fonts.
 *  Each property can hold one or more values; conventionally all of the same
 *  type, although the interface doesn't demand that.
 */
class Pattern
{
    public:
        class Builder;

    private:
        void* m_ptr;

    public:
        /// wrap constructor, takes ownership of ptr and will call
        /// FcPatternDestroy in the destructor
        Pattern(void* ptr);

        /// Copy constructor, calls FcPatternReference to increment
        /// reference count
        /**
         *  Add another reference to p. Patterns are freed only when the
         *  reference count reaches zero.
         */
        Pattern( const Pattern& other );

        /// Calls FcPatternDestroy to decrement the reference count
        /**
         *  Decrement the pattern reference count. If all references are gone,
         *  destroys the pattern, in the process destroying all related values.
         */
        ~Pattern();

        /// assignment operator reassigns this pattern pointer dropping
        /// the reference to the old one and adding a reference to the new one
        Pattern& operator=( const Pattern& other );

        /// Create a pattern
        /**
         *  Creates a pattern with no properties; used to build patterns from
         *  scratch.
         */
        static Pattern create(void);

        /// Copy a pattern
        /**
         *  Copy a pattern, returning a new pattern that matches p. Each
         *  pattern may be modified without affecting the other.
         */
        Pattern duplicate();

        /// Filter the objects of pattern
        /**
         *  Returns a new pattern that only has those objects from p that are
         *  in os. If os is NULL, a duplicate of p is returned.
         */
        Pattern filter(const ObjectSet& os);

        /// Compare patterns
        /**
         *  Returns whether pa and pb are exactly alike.
         */
        bool equal (const Pattern& pb);

        /// Compare portions of patterns
        /**
         *  Returns whether pa and pb have exactly the same values for all of
         *  the objects in os.
         */
        bool equalSubset (const Pattern& pb, const ObjectSet& os);

        /// Computer a pattern hash value
        /**
         *  Returns a 32-bit number which is the same for any two patterns
         *  which are equal.
         */
        Char32_t hash ();

        /// Delete a property from a pattern
        /**
         *  Deletes all values associated with the property `object', returning
         *  whether the property existed or not.
         */
        bool del (const char* object);

        /// Remove one object of the specified type from the pattern
        /**
         *  Removes the value associated with the property `object' at position
         *  `id', returning whether the property existed and had a value at
         *  that position or not.
         */
        bool remove (const char* object, int id);

        /// Add an integer object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, int i );

        /// Add a double object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, double d );

        /// Add a string object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, const Char8_t* s );

        /// Add a matrix object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, const Matrix& m );

        /// Add a charset object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, const CharSet& c );

        /// Add a boolean object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, bool b );

        /// Add a language set object
        /**
         *  These are all convenience functions that insert objects of the
         *  specified type into the pattern. Use these in preference to
         *  FcPatternAdd as they will provide compile-time typechecking. These
         *  all append values to any existing list of values.
         */
        bool add( const char* obj, const LangSet& ls );

        /// Get an integer
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         */
        Result_t get( const char* obj, int n, int& i );

        /// Get a double
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         */
        Result_t get( const char* obj, int n, double& d );

        /// get a string
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         */
        Result_t get( const char* obj, int n, Char8_t*& s );

        /// get a matrix
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         */
        Result_t get( const char* obj, int n, Matrix& m );

        /// get a charset
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         */
        Result_t get( const char* obj, int n, CharSet& c );

        /// get a boolean
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         */
        Result_t get( const char* obj, int n, bool& b );

        /// get a language set
        /**
         *  These are convenience functions that call FcPatternGet and verify
         *  that the returned data is of the expected type. They return
         *  FcResultTypeMismatch if this is not the case. Note that these
         *  (like FcPatternGet) do not make a copy of any data structure
         *  referenced by the return value. Use these in preference to
         *  FcPatternGet to provide compile-time typechecking.
         *
         *  @note Do NOT destroy this langset, as it is simply a copy of the
         *        pointer stored internally in the pattern
         */
        Result_t get( const char* obj, int n, LangSet& ls );



        /// Builds a pattern using a list of objects, types and values.
        /**
         *  Each value to be entered in the pattern is specified with three
         *  arguments:
         *    * Object name, a string describing the property to be added.
         *    * Object type, one of the FcType enumerated values
         *    * Value, not an FcValue, but the raw type as passed to any of the
         *      FcPatternAdd<type> functions. Must match the type of the second
         *      argument.
         *
         *  The argument list is terminated by a null object name, no object
         *  type nor value need be passed for this. The values are added to
         *  `pattern', if `pattern' is null, a new pattern is created.
         *  In either case, the pattern is returned. Example
         *
         *  \code{.cpp}
         *  Pattern pattern = Pattern::create();
         *  pattern.build(FC_FAMILY, FcTypeString, "Times", (char *) 0);
         *  \endcode
         */
        Builder build( );

        /// Builds a pattern using a list of objects, types and values.
        /**
         *  Each value to be entered in the pattern is specified with three
         *  arguments:
         *    * Object name, a string describing the property to be added.
         *    * Object type, one of the FcType enumerated values
         *    * Value, not an FcValue, but the raw type as passed to any of the
         *      FcPatternAdd<type> functions. Must match the type of the second
         *      argument.
         *
         *  The argument list is terminated by a null object name, no object
         *  type nor value need be passed for this. The values are added to
         *  `pattern', if `pattern' is null, a new pattern is created.
         *  In either case, the pattern is returned. Example
         *
         *  \code{.cpp}
         *  Pattern pattern = Pattern::buildNew (FC_FAMILY, FcTypeString, "Times", (char *) 0);
         *  \endcode
         */
        static Builder buildNew( );

        /// Parse a pattern string
        /**
         *  Converts name from the standard text format described above into a
         *  pattern.
         */
        static Pattern parse( const Char8_t* name );

        /// Convert a pattern back into a string that can be parsed
        /**
         *  Converts the given pattern into the standard text format described
         *  above. The return value is not static, but instead refers to newly
         *  allocated memory which should be freed by the caller using free().
         */
        Char8_t* unparse();

        /// Format a pattern into a string according to a format specifier
        /**
         *  Converts given pattern pat into text described by the format
         *  specifier format. The return value refers to newly allocated
         *  memory which should be freed by the caller using free(), or NULL
         *  if format is invalid.
         *
         *  The format is loosely modeled after printf-style format string.
         *  The format string is composed of zero or more directives: ordinary
         *  characters (not "%"), which are copied unchanged to the output
         *  stream; and tags which are interpreted to construct text from the
         *  pattern in a variety of ways (explained below). Special characters
         *  can be escaped using backslash. C-string style special characters
         *  like \n and \r are also supported (this is useful when the format
         *  string is not a C string literal). It is advisable to always escape
         *  curly braces that are meant to be copied to the output as ordinary
         *  characters.
         *
         *  Each tag is introduced by the character "%", followed by an
         *  optional minimum field width, followed by tag contents in curly
         *  braces ({}). If the minimum field width value is provided the tag
         *  will be expanded and the result padded to achieve the minimum
         *  width. If the minimum field width is positive, the padding will
         *  right-align the text. Negative field width will left-align. The
         *  rest of this section describes various supported tag contents and
         *  their expansion.
         *
         *  A simple tag is one where the content is an identifier. When
         *  simple tags are expanded, the named identifier will be looked up
         *  in pattern and the resulting list of values returned, joined
         *  together using comma. For example, to print the family name and
         *  style of the pattern, use the format "%{family} %{style}\n". To
         *  extend the family column to forty characters use
         *  "%-40{family}%{style}\n".
         *
         *  Simple tags expand to list of all values for an element. To only
         *  choose one of the values, one can index using the syntax
         *  "%{elt[idx]}". For example, to get the first family name only,
         *  use "%{family[0]}".
         *
         *  If a simple tag ends with "=" and the element is found in the
         *  pattern, the name of the element followed by "=" will be output
         *  before the list of values. For example, "%{weight=}" may expand to
         *  the string "weight=80". Or to the empty string if pattern does not
         *  have weight set.
         *
         *  If a simple tag starts with ":" and the element is found in the
         *  pattern, ":" will be printed first. For example, combining this
         *  with the =, the format "%{:weight=}" may expand to ":weight=80"
         *  or to the empty string if pattern does not have weight set.
         *
         *  If a simple tag contains the string ":-", the rest of the the tag
         *  contents will be used as a default string. The default string is
         *  output if the element is not found in the pattern. For example,
         *  the format "%{:weight=:-123}" may expand to ":weight=80" or to the
         *  string ":weight=123" if pattern does not have weight set.
         *
         *  A count tag is one that starts with the character "#" followed by
         *  an element name, and expands to the number of values for the
         *  element in the pattern. For example, "%{#family}" expands to the
         *  number of family names pattern has set, which may be zero.
         *
         *  A sub-expression tag is one that expands a sub-expression. The tag
         *  contents are the sub-expression to expand placed inside another set
         *  of curly braces. Sub-expression tags are useful for aligning an
         *  entire sub-expression, or to apply converters (explained later) to
         *  the entire sub-expression output. For example, the format
         *  "%40{{%{family} %{style}}}" expands the sub-expression to construct
         *  the family name followed by the style, then takes the entire string
         *  and pads it on the left to be at least forty characters.
         *
         *  A filter-out tag is one starting with the character "-" followed by
         *  a comma-separated list of element names, followed by a
         *  sub-expression enclosed in curly braces. The sub-expression will be
         *  expanded but with a pattern that has the listed elements removed
         *  from it. For example, the format "%{-size,pixelsize{sub-expr}}"
         *  will expand "sub-expr" with pattern sans the size and pixelsize
         *  elements.
         *
         *  A filter-in tag is one starting with the character "+" followed by
         *  a comma-separated list of element names, followed by a
         *  sub-expression enclosed in curly braces. The sub-expression will
         *  be expanded but with a pattern that only has the listed elements
         *  from the surrounding pattern. For example, the format
         *  "%{+family,familylang{sub-expr}}" will expand "sub-expr" with a
         *  sub-pattern consisting only the family and family lang elements
         *  of pattern.
         *
         *  A conditional tag is one starting with the character "?" followed
         *  by a comma-separated list of element conditions, followed by two
         *  sub-expression enclosed in curly braces. An element condition can
         *  be an element name, in which case it tests whether the element is
         *  defined in pattern, or the character "!" followed by an element
         *  name, in which case the test is negated. The conditional passes
         *  if all the element conditions pass. The tag expands the first
         *  sub-expression if the conditional passes, and expands the second
         *  sub-expression otherwise. For example, the format
         *  "%{?size,dpi,!pixelsize{pass}{fail}}" will expand to "pass" if
         *  pattern has size and dpi elements but no pixelsize element, and
         *  to "fail" otherwise.
         *
         *  An enumerate tag is one starting with the string "[]" followed by
         *  a comma-separated list of element names, followed by a
         *  sub-expression enclosed in curly braces. The list of values for the
         *  named elements are walked in parallel and the sub-expression
         *  expanded each time with a pattern just having a single value for
         *  those elements, starting from the first value and continuing as
         *  long as any of those elements has a value. For example, the format
         *  "%{[]family,familylang{%{family} (%{familylang})\n}}" will expand
         *  the pattern "%{family} (%{familylang})\n" with a pattern having
         *  only the first value of the family and familylang elements, then
         *  expands it with the second values, then the third, etc.
         *
         *  As a special case, if an enumerate tag has only one element, and
         *  that element has only one value in the pattern, and that value is
         *  of type FcLangSet, the individual languages in the language set
         *  are enumerated.
         *
         *  A builtin tag is one starting with the character "=" followed by a
         *  builtin name. The following builtins are defined:
         *
         *  * \p unparse
         *  **  Expands to the result of calling FcNameUnparse() on the pattern.
         *  * \p fcmatch
         *  **  Expands to the output of the default output format of the
         *      fc-match command on the pattern, without the final newline.
         *  * \p fclist
         *  **  Expands to the output of the default output format of the
         *      fc-list command on the pattern, without the final newline.
         *
         *  * \p fccat
         *  **  Expands to the output of the default output format of the
         *      fc-cat command on the pattern, without the final newline.
         *  * \p pkgkit
         *  **  Expands to the list of PackageKit font() tags for the pattern.
         *      Currently this includes tags for each family name, and each
         *      language from the pattern, enumerated and sanitized into a set
         *      of tags terminated by newline. Package management systems can
         *      use these tags to tag their packages accordingly.
         *  **  For example, the format "%{+family,style{%{=unparse}}}\n" will
         *      expand to an unparsed name containing only the family and style
         *      element values from pattern.
         *  **  The contents of any tag can be followed by a set of zero or
         *      more converters. A converter is specified by the character "|"
         *      followed by the converter name and arguments. The following
         *      converters are defined:
         *  * \p basename
         *  **  Replaces text with the results of calling FcStrBasename() on it.
         *  * \p dirname
         *  **  Replaces text with the results of calling FcStrDirname() on it.
         *  * \p downcase
         *  **  Replaces text with the results of calling FcStrDowncase() on it.
         *  * \p shescape
         *  **  Escapes text for one level of shell expansion. (Escapes
         *      single-quotes, also encloses text in single-quotes.)
         *  * \p cescape
         *  **  Escapes text such that it can be used as part of a C string
         *      literal. (Escapes backslash and double-quotes.)
         *  * \p xmlescape
         *  **  Escapes text such that it can be used in XML and HTML. (Escapes
         *      less-than, greater-than, and ampersand.)
         *  * \p delete(chars)
         *  **  Deletes all occurrences of each of the characters in chars
         *      from the text. FIXME: This converter is not UTF-8 aware yet.
         *  * \p escape(chars)
         *  **  Escapes all occurrences of each of the characters in chars by
         *      prepending it by the first character in chars. FIXME: This
         *      converter is not UTF-8 aware yet.
         *  * \p translate(from,to)
         *  **  Translates all occurrences of each of the characters in from by
         *      replacing them with their corresponding character in to. If to
         *      has fewer characters than from, it will be extended by
         *      repeating its last character. FIXME: This converter is not
         *      UTF-8 aware yet.
         *  **  For example, the format "%{family|downcase|delete( )}\n" will
         *      expand to the values of the family element in pattern,
         *      lower-cased and with spaces removed.
         */
        Char8_t * format (const Char8_t *format);

        /// Print a pattern for debugging
        /**
         * Prints an easily readable version of the pattern to stdout. There is
         * no provision for reparsing data in this format, it's just for
         * diagnostics and debugging.
         */
        void print();

        /// Perform default substitutions in a pattern
        /**
         *  Supplies default values for underspecified font patterns:
         *    * Patterns without a specified style or weight are set to Medium
         *    * Patterns without a specified style or slant are set to Roman
         *    * Patterns without a specified pixel size are given one computed
         *      from any specified point size (default 12), dpi (default 75)
         *      and scale (default 1).
         */
        void defaultSubstitute();

};


/// utility for building patterns using interface similar to
/// variable argument list
class Pattern::Builder
{
    private:
        Pattern m_pattern;

    public:
        Builder( Pattern pattern );
        Builder& operator()( const char* obj, int               i);
        Builder& operator()( const char* obj, double            d);
        Builder& operator()( const char* obj, Char8_t*          s);
        Builder& operator()( const char* obj, const Matrix&     m);
        Builder& operator()( const char* obj, const CharSet&   cs);
        Builder& operator()( const char* obj, bool              b);
        Builder& operator()( const char* obj, const LangSet&   ls);

        Pattern  done();
};

} // namespace fontconfig 

#endif // PATTERN_H_

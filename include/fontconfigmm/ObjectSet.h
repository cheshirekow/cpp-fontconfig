/*
 *  \file   ObjectSet.h
 *
 *  \date   Jul 22, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_OBJECTSET_H_
#define FONTCONFIGMM_OBJECTSET_H_

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

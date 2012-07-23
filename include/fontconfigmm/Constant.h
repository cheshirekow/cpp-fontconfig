/*
 *  \file   Constant.h
 *
 *  \date   Jul 23, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef FONTCONFIGMM_CONSTANT_H_
#define FONTCONFIGMM_CONSTANT_H_

#include <fontconfigmm/common.h>

namespace fontconfig
{

class Constant
{
    private:
        const void* m_ptr;

    public:
        Constant(const void* ptr);

        const Char8_t*  get_name();
        const char*     get_object();
        int             get_value();
};

} // namespace fontconfig 

#endif // CONSTANT_H_

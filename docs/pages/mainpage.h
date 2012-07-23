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
 *  \file   mainpage.h
 *  \brief  Starting point for documentation (no code)
 *  \author Joshua Bialkowski (jbialk@mit.edu)
 *  \date   Apr 8, 2011
 *
 *  \mainpage   Documentation
 *
 *  Fontconfigmm is a very thin c++ wrapper around libfontconfig. It wraps
 *  only the public API and takes advantage of the fact that most of the
 *  library exposes opaque pointers.
 *
 *  Most of the classes in Fontconfigmm are wrappers around these opaque
 *  pointers. As such, you should treat objects of these classes as if they
 *  were, in fact, pointers themselves. It is probably better to pass around
 *  copies and/or references to these objects rather than pointers to
 *  these objects.
 *
 *  As a simple demonstration, here is a program which will output a system
 *  font file which matches a requested family name.
 *
 *  \include tutorial.cpp
 */









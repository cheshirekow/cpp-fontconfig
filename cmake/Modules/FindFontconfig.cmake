# - Try to find Fontconfig
# Once done, this will define
#
#  Fontconfig_FOUND - system has Fontconfig
#  Fontconfig_INCLUDE_DIRS - the Fontconfig include directories
#  Fontconfig_LIBRARIES - link these to use Fontconfig

include(LibFindMacros)

# Use pkg-config to get hints about paths
libfind_pkg_check_modules(Fontconfig_PKGCONF fontconfig)

# Include dir
find_path(Fontconfig_INCLUDE_DIR
  NAMES fontconfig/fontconfig.h
  HINTS ${Fontconfig_PKGCONF_INCLUDE_DIRS}
)

# Finally the library itself
find_library(Fontconfig_LIBRARY
  NAMES fontconfig
  HINTS ${Fontconfig_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(Fontconfig_PROCESS_INCLUDES Fontconfig_INCLUDE_DIR)
set(Fontconfig_PROCESS_LIBS Fontconfig_LIBRARY)
libfind_process(Fontconfig)


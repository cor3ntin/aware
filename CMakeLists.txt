###############################################################################
#
# http://github.com/breese/aware
#
# Copyright (C) 2013 Bjorn Reese <breese@users.sourceforge.net>
#
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)
#
###############################################################################

# Debug build
#   cmake -DCMAKE_BUILD_TYPE=Debug .

###############################################################################

cmake_minimum_required(VERSION 2.8)
project(aware)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

###############################################################################
# Aware package
###############################################################################

set(AWARE_BUILD_DIR ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${AWARE_BUILD_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${AWARE_BUILD_DIR}/bin)

include_directories(BEFORE include)
link_directories(${AWARE_BUILD_DIR}/lib)

add_subdirectory(src)

add_library(aware STATIC
  ${AWARE_SOURCE}
  include/aware/announce_socket.hpp
  include/aware/avahi/announce_socket.hpp
  include/aware/avahi/detail/announcer.hpp
  include/aware/avahi/detail/browser.hpp
  include/aware/avahi/detail/client.hpp
  include/aware/avahi/detail/poller.hpp
  include/aware/avahi/error.hpp
  include/aware/avahi/monitor_socket.hpp
  include/aware/avahi/service.hpp
  include/aware/bonjour/announce_socket.hpp
  include/aware/bonjour/detail/announcer.hpp
  include/aware/bonjour/detail/browser.hpp
  include/aware/bonjour/detail/handle.hpp
  include/aware/bonjour/detail/monitor.hpp
  include/aware/bonjour/detail/properties.hpp
  include/aware/bonjour/detail/resolver.hpp
  include/aware/bonjour/detail/service.hpp
  include/aware/bonjour/detail/throw_on_error.hpp
  include/aware/bonjour/error.hpp
  include/aware/bonjour/monitor_socket.hpp
  include/aware/contact.hpp
  include/aware/detail/native_socket.hpp
  include/aware/detail/utility.hpp
  include/aware/aware.hpp
)

target_include_directories(aware PUBLIC include)
target_link_libraries(aware Boost::asio zeroconf)

if (AVAHI_COMMON_LIBRARIES)
  target_include_directories(aware PUBLIC ${ZEROCONF_AVAHI_INCLUDE_DIRS})
  target_link_libraries(aware PUBLIC ${ZEROCONF_AVAHI_LIBRARIES} ${EXTRA_LIBS})
  target_compile_definitions(aware PUBLIC -DAWARE_HAS_AVAHI)

elseif (DNSSD_FOUND)
  target_include_directories(aware PUBLIC ${ZEROCONF_BONJOUR_INCLUDE_DIRS})
  target_link_libraries(aware PUBLIC ${ZEROCONF_BONJOUR_LIBRARIES} ${EXTRA_LIBS})
  target_compile_definitions(aware PUBLIC -DAWARE_HAS_BONJOUR)
else()
    message(FATAL_ERROR "No ZeroConf module found")
endif()


###############################################################################
# Examples
###############################################################################

#if(${ZEROCONF_AVAHI_FOUND})
#  add_subdirectory(example/avahi EXCLUDE_FROM_ALL)
#  add_custom_target(example DEPENDS avahi-example)
#elseif(${ZEROCONF_BONJOUR_FOUND})
#  add_subdirectory(example/bonjour EXCLUDE_FROM_ALL)
#  add_custom_target(example DEPENDS bonjour-example)
#endif()

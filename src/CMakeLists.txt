if(AVAHI_COMMON_LIBRARIES)
  message("Using avahi as backend")
  add_subdirectory(avahi)
else()
  message("Using bonjour as backend")
  add_subdirectory(bonjour)
endif()

set(AWARE_SOURCE
  ${AWARE_BACKEND_SOURCE}
  src/contact.cpp
  src/detail/native_socket.cpp
  src/detail/utility.cpp
  PARENT_SCOPE
)

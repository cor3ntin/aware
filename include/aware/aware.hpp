#ifdef DNSSD_AVAHI
#    include <aware/avahi/announce_socket.hpp>
#else
#    include <aware/bonjour/announce_socket.hpp>
#endif

#include <aware/contact.hpp>

namespace aware {

#ifdef DNSSD_AVAHI
using announce_socket = avahi::announce_socket;
#else
using announce_socket = bonjour::announce_socket;
#endif

}  // namespace aware

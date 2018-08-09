#ifdef DNSSD_AVAHI
#    include <aware/avahi/announce_socket.hpp>
#    include <aware/avahi/monitor_socket.hpp>
#else
#    include <aware/bonjour/announce_socket.hpp>
#    include <aware/bonjour/monitor_socket.hpp>
#endif

#include <aware/contact.hpp>

namespace aware {

#ifdef DNSSD_AVAHI
using announce_socket = avahi::announce_socket;
using monitor_socket = avahi::monitor_socket;
#else
using announce_socket = bonjour::announce_socket;
using monitor_socket = bonjour::monitor_socket;
#endif

}  // namespace aware

#include <iostream>

#include <karma/nal/nal/ipaddr.h>

using namespace std;

using namespace nal;

struct ipaddr_impl: public ipaddr::comparable<ipaddr_impl> {
    inline bool _cmp(const ipaddr_impl &d) const {
        return 0;
    }

    inline bool _cmp(const ipaddr_impl::version &v) const {
        return 0;
    }

    inline bool _cmp(const ipaddr_impl::type &t) const {
        return 0;
    }
};

int main() {
    ipaddr_impl p1;
    ipaddr_impl p2;
    cout << ( p1 == p2 ) << endl;
    cout << ( p2 == p1 ) << endl;
    cout << ( p1 != p2 ) << endl;
    cout << ( p2 != p1 ) << endl;
    cout << ( p1 == ipaddr_impl::version::ipv4 ) << endl;
    cout << ( ipaddr_impl::version::ipv4 == p1 ) << endl;
    cout << ( p1 != ipaddr_impl::version::ipv4 ) << endl;
    cout << ( ipaddr_impl::version::ipv4 != p1 ) << endl;
    cout << ( p1 == ipaddr_impl::type::loopback ) << endl;
    cout << ( ipaddr_impl::type::loopback == p1 ) << endl;
    cout << ( p1 != ipaddr_impl::type::loopback ) << endl;
    cout << ( ipaddr_impl::type::loopback != p1 ) << endl;
    return 0;
}


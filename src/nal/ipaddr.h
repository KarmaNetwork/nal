#ifndef KARMA_NAL_NAL_IPADDR_H
#define KARMA_NAL_NAL_IPADDR_H

#include <karma/nal/config.h>

namespace KARMA_NAL_NAMESPACE {

namespace ipaddr {

struct base {
    // comparable::version
    enum class version {
        ipv4, ipv6, any
    };

    // comparable::type
    enum class type {
        zero, any, loopback, broadcast, multicast
    };
};

template <typename Impl>
struct comparable: public base {
    // comparable == comparable
    inline bool operator == (const comparable<Impl> &d) const {
        const Impl *p = static_cast<const Impl *>(this);
        const Impl *pd = static_cast<const Impl *>(&d);
        return ( p->_cmp(*pd) == 0) ? true : false;
    }

    // comparable != comparable
    inline bool operator != (const comparable<Impl> &d) const {
        const Impl *p = static_cast<const Impl *>(this);
        const Impl *pd = static_cast<const Impl *>(&d);
        return ( p->_cmp(*pd) != 0) ? true : false;
    }

    // comparable == ipv4
    inline bool operator == (const version &v) const {
        const Impl *p = static_cast<const Impl *>(this);
        return ( p->_cmp(v) == 0 ) ? true : false;
    }

    // ipv4 == comparable
    template <typename I>
    friend inline bool operator == (const typename comparable<I>::version &v, const comparable<I> &ip);

    // comparable != ipv4
    inline bool operator != (const version &v) const {
        const Impl *p = static_cast<const Impl *>(this);
        return ( p->_cmp(v) != 0 ) ? true : false;
    }

    // ipv4 != comparable
    template <typename I>
    friend inline bool operator != (const typename comparable<I>::version &v, const comparable<I> &ip);

    // comparable == loopback
    inline bool operator == (const type &t) const {
        const Impl *p = static_cast<const Impl *>(this);
        return ( p->_cmp(t) == 0 ) ? true : false;
    }

    // loopback == comparable
    template <typename I>
    friend inline bool operator == (const typename comparable<I>::type &t, const comparable<I> &ip);

    // comparable != loopback
    inline bool operator != (const type &t) const {
        const Impl *p = static_cast<const Impl *>(this);
        return ( p->_cmp(t) != 0 ) ? true : false;
    }

    // loopback != comparable
    template <typename I>
    friend inline bool operator != (const typename comparable<I>::type &t, const comparable<I> &ip);
};

template <typename I>
inline bool operator == (const typename comparable<I>::version &v, const comparable<I> &ip) {
    const I *p = static_cast<const I *>(&ip);
    return ( p->_cmp(v) == 0 ) ? true : false;
}

template <typename I>
inline bool operator != (const typename comparable<I>::version &v, const comparable<I> &ip) {
    const I *p = static_cast<const I *>(&ip);
    return ( p->_cmp(v) != 0 ) ? true : false;
}

template <typename I>
inline bool operator == (const typename comparable<I>::type &t, const comparable<I> &ip) {
    const I *p = static_cast<const I *>(&ip);
    return ( p->_cmp(t) == 0 ) ? true : false;
}

template <typename I>
inline bool operator != (const typename comparable<I>::type &t, const comparable<I> &ip) {
    const I *p = static_cast<const I *>(&ip);
    return ( p->_cmp(t) != 0 ) ? true : false;
}

template <typename Impl>
struct ipaddr: public base {
    // content
    using impl_type = typename Impl::impl_type;
    impl_type _v;

    // constructor
    ipaddr();
};

};

}; // KARMA_NAL_NAMESPACE

#endif


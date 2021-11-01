#pragma once

#include <boost/optional.hpp>

namespace QWarhammerSimulator::LibUtils
{

template <class T> class MonadicPointer : private boost::optional<T*>
{
public:
    using Base = boost::optional<T*>;

    using Base::flat_map;
    using Base::has_value;
    using Base::map;
    using Base::value;
    using Base::value_or;
    using Base::value_or_eval;

    constexpr MonadicPointer() = default;

    constexpr MonadicPointer(T* ptr)
        : Base(ptr ? boost::make_optional(ptr) : boost::none)
    {
    }

    template <class Return> auto map(Return (T::*fct)())
    {
        return map(std::mem_fn(fct));
    }

    template <class Return> auto flat_map(Return (T::*fct)())
    {
        return flat_map(std::mem_fn(fct));
    }
};

} // namespace
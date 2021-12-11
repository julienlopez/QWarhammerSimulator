#include <catch2/catch.hpp>

#include "monadicpointer.hpp"

#include <boost/optional/optional_io.hpp>

namespace
{

using QWarhammerSimulator::LibUtils::MonadicPointer;

class SpyType
{
public:
    int normalFunction()
    {
        m_normal_function = true;
        return 42;
    }

    boost::optional<int> optionalFunction()
    {
        m_optional_function = true;
        return 5;
    }

    bool normalFunctionHasBeenCalled() const
    {
        return m_normal_function;
    }

    bool optionalFunctionHasBeenCalled() const
    {
        return m_optional_function;
    }

private:
    bool m_normal_function = false;
    bool m_optional_function = false;
};

} // namespace

TEST_CASE("calling a member function", "[LibUtils]")
{

    SECTION("On a null pointer")
    {
        MonadicPointer<SpyType> ptr{nullptr};
        const auto res = ptr.map(&SpyType::normalFunction);
        REQUIRE_FALSE(res.has_value());
    }

    SECTION("On a valid pointer")
    {
        const auto obj = std::make_unique<SpyType>();
        MonadicPointer<SpyType> ptr{obj.get()};
        const auto res = ptr.map(&SpyType::normalFunction);
        REQUIRE(res.has_value());
        CHECK(*res == 42);
        CHECK(obj->normalFunctionHasBeenCalled());
    }
}

TEST_CASE("calling a member function returning an optional", "[LibUtils]")
{

    SECTION("On a null pointer")
    {
        MonadicPointer<SpyType> ptr{nullptr};
        const auto res = ptr.flat_map(&SpyType::optionalFunction);
        REQUIRE_FALSE(res.has_value());
    }

    SECTION("On a valid pointer")
    {
        const auto obj = std::make_unique<SpyType>();
        MonadicPointer<SpyType> ptr{obj.get()};
        const auto res = ptr.flat_map(&SpyType::optionalFunction);
        REQUIRE(res.has_value());
        CHECK(*res == 5);
        CHECK(obj->optionalFunctionHasBeenCalled());
    }
}

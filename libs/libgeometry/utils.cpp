#include "utils.hpp"

namespace QWarhammerSimulator::LibGeometry::Utils
{

Point normalVector(const Point& p)
{
    return {-p.y, p.x};
}

} // namespace QWarhammerSimulator::LibGeometry::Utils

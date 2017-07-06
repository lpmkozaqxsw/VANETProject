//
// Copyright (C) 2013 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INETVEINS_PLANE_H
#define __INETVEINS_PLANE_H

#include "inetveins/common/geometry/base/GeometricObjectBase.h"
#include "inetveins/common/geometry/object/LineSegment.h"

namespace inetveins {

/**
 * This class represents a 2 dimensional plane in the 3 dimensional space.
 */
class INETVEINS_API Plane : public GeometricObjectBase
{
  public:
    static const Plane NIL;

  protected:
    Coord basePoint;
    Coord normalVector;

  public:
    Plane();
    Plane(const Coord& basePoint, const Coord& normalVector);

    const Coord& getBasePoint() { return basePoint; }
    void setBasePoint(const Coord& basePoint) { this->basePoint = basePoint; }
    const Coord& getNormalVector() { return normalVector; }
    void setNormalVector(const Coord& normalVector) { this->normalVector = normalVector; }

    virtual bool isNil() const override { return this == &NIL; }
    virtual bool isUnspecified() const override { return basePoint.isUnspecified() || normalVector.isUnspecified(); }

    Coord computeIntersection(const LineSegment& lineSegment);
};

} // namespace inetveins

#endif // ifndef __INETVEINS_PLANE_H

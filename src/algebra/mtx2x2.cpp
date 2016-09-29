#include "mtx2x2.h"

Mtx2x2::Mtx2x2(double value) : MtxNxN(2,value) {}

Mtx2x2::Mtx2x2(double v00, double v01, double v10, double v11) : MtxNxN(2,v00,v01,v10,v11) {}

Mtx2x2::~Mtx2x2() {}

Vec2 *Mtx2x2::getLine(unsigned int line)
{
    return (Vec2*) Mtx::getLine(line);
}

Vec2 *Mtx2x2::getColumn(unsigned int column)
{
    return (Vec2*) Mtx::getColumn(column);
}

void Mtx2x2::setLine(unsigned int line, Vec2 *value)
{
    Mtx::setLine(line,value);
}

void Mtx2x2::setColumn(unsigned int column, Vec2 *value)
{
    Mtx::setColumn(column,value);
}

Mtx2x2 *Mtx2x2::sum(Mtx2x2 *mtx)
{
    return (Mtx2x2*) MtxNxN::sum(mtx);
}

Mtx2x2 *Mtx2x2::sub(Mtx2x2 *mtx)
{
    return (Mtx2x2*) MtxNxN::sub(mtx);
}

Mtx2x2 *Mtx2x2::prod(Mtx2x2 *mtx)
{
    return (Mtx2x2*) MtxNxN::prod(mtx);
}

Vec2 *Mtx2x2::prod(Vec2 *vec)
{
    return (Vec2*) MtxNxN::prod(vec);
}

Mtx2x2 *Mtx2x2::prod(double lambda)
{
    return (Mtx2x2*) MtxNxN::prod(lambda);
}

Mtx2x2 *Mtx2x2::inverse()
{
    return (Mtx2x2*) MtxNxN::inverse();
}

Mtx2x2 *Mtx2x2::copy()
{
    return (Mtx2x2*) MtxNxN::copy();
}

Mtx2x2 *Mtx2x2::getIdentity()
{
    return (Mtx2x2*) MtxNxN::getIdentity(2);
}

Mtx2x2 *Mtx2x2::getRotateMtx(double degree)
{
    return new Mtx2x2(cos(degree),-sin(degree),
                      sin(degree),cos(degree));
}

Mtx2x2 *Mtx2x2::getScaleMtx(double x, double y)
{
    return new Mtx2x2(x,0,
                      0,y);
}

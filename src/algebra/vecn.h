#ifndef VEC_H
#define VEC_H

#include "mtx.h"
#include <stdarg.h>

class VecN : public Mtx
{
public:
    VecN(double value=0);
    VecN(int size, double value=0);
    VecN(int size, double v1, double v2, ...);
    VecN(Mtx mtx);

    int getSize();

    double getValue(int pos);
    void setValue(int pos, double value);

    VecN *sum(VecN *vec);
    VecN *sub(VecN *vec);
    VecN *prod(double lambda);
    Mtx *prod(VecN *vec);
    double dot(VecN *vec);

    VecN operator+(VecN vec);
    VecN operator-(VecN vec);
    VecN operator*(double lambda);
    Mtx operator*(VecN vec);
    double dot_(VecN vec);

    bool isColumn();
    void normalize();
    double getNorm();

    VecN *getSubVec(int initialPos, int finalPos=-1);
    VecN getSubVec_(int initialPos, int finalPos=-1);
    void setSubVec(int initialPos, VecN *vec);
    void setSubVec_(int initialPos, VecN vec);
    VecN *copy();
    VecN copy_();
};

#endif // VEC_H

#ifndef MTX_H
#define MTX_H

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using std::vector;
using std::string;
using std::cerr;
using std::endl;

class Mtx
{
public:
    /* CONSTRUCTORS */
    Mtx(double value=0);
    Mtx(unsigned int lines, unsigned int columns, double value=0);
    virtual ~Mtx();

    /* BASIC ACCESSORS */
    unsigned int getLines() const;
    unsigned int getColumns() const;

    /* ADVANCED ACCESSORS */
    double getValue(unsigned int line, unsigned int column);
    void setValue(unsigned int line, unsigned int column, double value);

    Mtx *getSubMatrix(unsigned int startLine, unsigned int endLine, unsigned int startColumn, unsigned int endColumn);
    void setSubMatrix(unsigned int startLine, unsigned int startColumn, Mtx *subMatrix);

    Mtx *getLine(unsigned int line);
    void setLine(unsigned int line, Mtx *value);

    Mtx *getColumn(unsigned int column);
    void setColumn(unsigned int column, Mtx *value);

    /* OPERATORS */
    Mtx *sum(Mtx *mtx);
    Mtx *sub(Mtx *mtx);
    Mtx *prod(Mtx *mtx);
    Mtx *prod(double lambda);

    void transpose();

    double normLine(unsigned int line);
    double normColumn(unsigned int column);
    double normMatrix();

    void normalizeLine(unsigned int line);
    void normalizeColumn(unsigned int column);
    void normalizeAllLines();
    void normalizeAllColumns();
    void normalize();

    Mtx *join(int position, Mtx *mtx);
    Mtx *resolve(Mtx *b); /* B must be a column vector. */

    /* UTILITIES */
    string toStdString();
    Mtx *copy();

    /* ERROR MESSAGES */
    void mtxIndexOutOfBoundError(int line=-1,int column=-1);
    void inconsistentSubMatrixError(string tag,unsigned int startLine, unsigned int endLine, unsigned int startColumn, unsigned int endColumn);
    void lineOutOfBoundError(int line);
    void columnOutOfBoundError(int column);
    void inconsistentLineSizeError(Mtx *mtx);
    void inconsistentColumnSizeError(Mtx *mtx);
    void mtxSizeError(Mtx *mtx);
    void mtxProdError(Mtx *mtx);
    void inconsistentColumnNumberError(unsigned int expectedValue, unsigned int foundValue);
    void inconsistentLineNumberError(unsigned int expectedValue, unsigned int foundValue);
    void positionError();

    static const int TOP = 0;
    static const int BOTTOM = 1;
    static const int LEFT = 2;
    static const int RIGHT = 3;

protected:
    unsigned int lines;
    unsigned int columns;
    vector<double> *values;

    virtual void initializeMatrix(double value);
    void gaussElimination(Mtx *mtx);
};

#endif // MTX_H

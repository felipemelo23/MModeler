#include "mtx.h"

Mtx::Mtx(double value)
{
    this->lines = 1;
    this->columns = 1;
    initializeMatrix(value);
}

Mtx::Mtx(unsigned int lines, unsigned int columns, double value)
{
    this->lines = lines;
    this->columns = columns;
    initializeMatrix(value);
}

Mtx::~Mtx()
{
    delete values;
}

unsigned int Mtx::getLines() const
{
    return lines;
}

unsigned int Mtx::getColumns() const
{
    return columns;
}

double Mtx::getValue(unsigned int line, unsigned int column)
{
    if ((line < lines)&&(column < columns))
        return values->at(column+(line*columns));

    mtxIndexOutOfBoundError(line,column);
    return INFINITY;
}

void Mtx::setValue(unsigned int line, unsigned int column, double value)
{
    if ((line < lines)&&(column < columns)) {
        values->at(column+(line*columns)) = value;
    } else {
        mtxIndexOutOfBoundError(line,column);
    }
}

Mtx *Mtx::getSubMatrix(unsigned int startLine, unsigned int endLine, unsigned int startColumn, unsigned int endColumn)
{
    if (((endLine < startLine)||(endColumn < startColumn))||((endLine >= lines)||(endColumn >= columns))) {
        inconsistentSubMatrixError("get",startLine,endLine,startColumn,endColumn);
        return NULL;
    }

    double subMatrixLines = endLine-startLine+1;
    double subMatrixColumns = endColumn-startColumn+1;

    Mtx *subMatrix = new Mtx(subMatrixLines,subMatrixColumns);

    for (int line=0;line<subMatrixLines;line++) {
        for (int column=0;column<subMatrixColumns;column++) {
            subMatrix->setValue(line,column,getValue(startLine+line,startColumn+column));
        }
    }

    return subMatrix;
}

void Mtx::setSubMatrix(unsigned int startLine, unsigned int startColumn, Mtx *subMatrix)
{
    unsigned int endLine = startLine+subMatrix->getLines()-1;
    unsigned int endColumn = startColumn+subMatrix->getColumns()-1;

    if (((endLine < startLine)||(endColumn < startColumn))||((endLine >= lines)||(endColumn >= columns))) {
        inconsistentSubMatrixError("set",startLine,endLine,startColumn,endColumn);
    } else {
        for (unsigned int line=0;line<subMatrix->getLines();line++) {
            for (unsigned int column=0;column<subMatrix->getColumns();column++) {
                setValue(startLine+line,startColumn+column,subMatrix->getValue(line,column));
            }
        }
    }
}

Mtx *Mtx::getLine(unsigned int line)
{
    if (line < lines)
        return getSubMatrix(line,line,0,columns-1);

    lineOutOfBoundError(line);

    return NULL;
}

void Mtx::setLine(unsigned int line, Mtx *value)
{
    if ((line < lines)&&(value->getColumns() <= columns)) {
        setSubMatrix(line,0,value);
    } else if (line >= lines) {
        lineOutOfBoundError(line);
    } else {
        inconsistentLineSizeError(value);
    }
}

Mtx *Mtx::getColumn(unsigned int column)
{
    if (column < columns)
        return getSubMatrix(0,lines-1,column,column);

    columnOutOfBoundError(column);

    return NULL;
}

void Mtx::setColumn(unsigned int column, Mtx *value)
{
    if ((column < columns)&&(value->getLines() <= lines)) {
        setSubMatrix(0,column,value);
    } else if (column >= columns) {
        columnOutOfBoundError(column);
    } else {
        inconsistentColumnSizeError(value);
    }
}

Mtx *Mtx::sum(Mtx *mtx)
{
    if ((lines==mtx->getLines()) && (columns==mtx->getColumns())) {
        Mtx *result = new Mtx(lines,columns);

        for (unsigned int line=0;line<lines;line++) {
            for (unsigned int column=0;column<columns;column++) {
                result->setValue(line,column,getValue(line,column)+mtx->getValue(line,column));
            }
        }

        return result;
    }

    mtxSizeError(mtx);

    return NULL;
}

Mtx *Mtx::sub(Mtx *mtx)
{
    if ((lines==mtx->getLines()) && (columns==mtx->getColumns())) {
        Mtx *result = new Mtx(lines,columns);

        for (unsigned int line=0;line<lines;line++) {
            for (unsigned int column=0;column<columns;column++) {
                result->setValue(line,column,getValue(line,column)-mtx->getValue(line,column));
            }
        }

        return result;
    }

    mtxSizeError(mtx);

    return NULL;
}

Mtx *Mtx::prod(Mtx *mtx)
{
    if (columns==mtx->getLines()) {
        Mtx *result = new Mtx(lines,mtx->getColumns());

        if ((lines == 1) && (mtx->getColumns() == 1)) {
            double resultValue = 0;
            for (unsigned int i=0;i<columns;i++) {
                resultValue += mtx->getValue(i,0)*getValue(0,i);
            }
            result->setValue(0,0,resultValue);
        } else {
            for (unsigned int line=0;line<lines;line++) {
                for (unsigned int column=0;column<mtx->getColumns();column++) {
                    result->setValue(line,column,(getLine(line)->prod(mtx->getColumn(column)))->getValue(0,0));
                }
            }
        }

        return result;
    }

    mtxProdError(mtx);

    return NULL;
}

Mtx *Mtx::prod(double lambda)
{
    Mtx *result = new Mtx(lines,columns);

    for (unsigned int line=0;line<lines;line++) {
        for (unsigned int column=0;column<columns;column++) {
            result->setValue(line,column,lambda*getValue(line,column));
        }
    }

    return result;
}

void Mtx::transpose()
{
    vector<double> *newValues = new vector<double>();

    for (unsigned int column=0;column<columns;column++) {
        for (unsigned int line=0;line<lines;line++) {
            newValues->push_back(getValue(line,column));
        }
    }

    int aux = lines;
    lines = columns;
    columns = aux;

    delete values;
    values = newValues;
}

double Mtx::normLine(unsigned int line)
{
    if (line < lines) {
        double norm = 0;

        for (unsigned int column=0;column<columns;column++) {
            norm += pow(getValue(line,column),2);
        }

        return sqrt(norm);
    }

    lineOutOfBoundError(line);

    return -1;
}

double Mtx::normColumn(unsigned int column)
{
    if (column < columns) {
        double norm = 0;

        for (unsigned int line=0;line<lines;line++) {
            norm += pow(getValue(line,column),2);
        }

        return sqrt(norm);
    }

    columnOutOfBoundError(column);

    return -1;
}

double Mtx::normMatrix()
{
    double norm = getValue(0,0);

    for (unsigned int i=0;i<lines*columns;i++) {
        if (norm < values->at(i)) norm = values->at(i);
    }

    return norm;
}

void Mtx::normalizeLine(unsigned int line)
{
    if (line < lines) {
        double norm = normLine(line);
        for (unsigned int column=0;column<columns;column++) {
            setValue(line,column,getValue(line,column)/norm);
        }
    } else {
        lineOutOfBoundError(line);
    }
}

void Mtx::normalizeColumn(unsigned int column)
{
    if (column < columns) {
        double norm = normColumn(column);
        for (unsigned int line=0;line<lines;line++) {
            setValue(line,column,getValue(line,column)/norm);
        }
    } else {
        columnOutOfBoundError(column);
    }
}

void Mtx::normalizeAllLines()
{
    for (unsigned int line=0;line<lines;line++) {
        normalizeLine(line);
    }
}

void Mtx::normalizeAllColumns()
{
    for (unsigned int column=0;column<columns;column++) {
        normalizeColumn(column);
    }
}

void Mtx::normalize()
{
    double norm = normMatrix();
    for (unsigned int line=0;line<lines;line++) {
        for (unsigned int column=0;column<columns;column++) {
            setValue(line,column,getValue(line,column)/norm);
        }
    }
}

Mtx *Mtx::join(int pos, Mtx *mtx)
{
    Mtx *result;

    switch (pos) {
    case TOP:
        if (getColumns() == mtx->getColumns()) {
            result = new Mtx(getLines()+mtx->getLines(),getColumns());
            result->setSubMatrix(0,0,mtx);
            result->setSubMatrix(mtx->getLines(),0,this);
        } else {
            inconsistentColumnNumberError(getColumns(),mtx->getColumns());
            result = NULL;
        }
        break;
    case BOTTOM:
        if (getColumns() == mtx->getColumns()) {
            result = new Mtx(getLines()+mtx->getLines(),getColumns());
            result->setSubMatrix(0,0,this);
            result->setSubMatrix(getLines(),0,mtx);
        } else {
            inconsistentColumnNumberError(getColumns(),mtx->getColumns());
            result = NULL;
        }
        break;
    case LEFT:
        if (getLines() == mtx->getLines()) {
            result = new Mtx(getLines(),getColumns()+mtx->getColumns());
            result->setSubMatrix(0,0,mtx);
            result->setSubMatrix(0,mtx->getColumns(),this);
        } else {
            inconsistentLineNumberError(getLines(),mtx->getLines());
            result = NULL;
        }
        break;
    case RIGHT:
        if (getLines() == mtx->getLines()) {
            result = new Mtx(getLines(),getColumns()+mtx->getColumns());
            result->setSubMatrix(0,0,this);
            result->setSubMatrix(0,getColumns(),mtx);
        } else {
            inconsistentLineNumberError(getLines(),mtx->getLines());
            result = NULL;
        }
        break;
    default:
        positionError();
        result = NULL;
        break;
    }

    return result;
}

Mtx *Mtx::resolve(Mtx *b)
{
    Mtx *thisTemp = this->copy();
    thisTemp = thisTemp->join(Mtx::RIGHT,b);
    gaussElimination(thisTemp);
    Mtx *solution = thisTemp->getSubMatrix(0,thisTemp->getLines()-1,thisTemp->getColumns()-1,thisTemp->getColumns()-1);

    delete thisTemp;
    return solution;
}

void Mtx::gaussElimination(Mtx *mtx)
{
    for (int pivot=0;pivot<getLines()-1;pivot++) {
        for (int line=pivot+1;line<getLines();line++) {
            mtx->setLine(line, mtx->getLine(line)->sub(mtx->getLine(pivot)->prod(mtx->getValue(line,pivot)/mtx->getValue(pivot,pivot))));
        }
    }

    for (int pivot=getLines()-1;pivot>0;pivot--) {
        mtx->setLine(pivot,mtx->getLine(pivot)->prod(1/mtx->getValue(pivot,pivot)));
        for (int line=pivot-1;line>=0;line--) {
            mtx->setLine(line,mtx->getLine(line)->sub(mtx->getLine(pivot)->prod(mtx->getValue(line,pivot))));
        }
    }
}

std::string Mtx::toStdString()
{
    string str = "";

    for (unsigned int line=0;line<lines;line++) {
        str += "[";
        for (unsigned int column=0;column<columns;column++) {
            str += std::to_string(getValue(line,column));
            if (column+1 != columns) str += " ";
        }
        str += "]";
        if (line+1 != lines) str += "\n";
    }

    return str;
}

Mtx *Mtx::copy()
{
    Mtx *newMatrix = new Mtx(lines,columns);

        for (unsigned int line=0;line<lines;line++) {
            for (unsigned int column=0;column<columns;column++) {
                newMatrix->setValue(line,column,getValue(line,column));
            }
        }

        return newMatrix;
}

void Mtx::mtxIndexOutOfBoundError(int line, int column)
{
    cerr << "-> Matrix index out of bound error: Tried to reach element (" << line << "," << column <<
            ") of a matrix " << lines << "x" << columns << "." << endl;
}

void Mtx::inconsistentSubMatrixError(std::string tag, unsigned int startLine, unsigned int endLine, unsigned int startColumn, unsigned int endColumn)
{
    cerr << "-> Inconsistet submatrix size error on a " << tag << " operation: " << endl;
    cerr << "startLine: " << startLine << endl;
    cerr << "endLine: " << endLine << endl;
    cerr << "startColumn: " << startColumn << endl;
    cerr << "endColumn: " << endColumn << endl;
    cerr << "Where the original matrix is " << lines << "x" << columns << "." << endl;
}

void Mtx::lineOutOfBoundError(int line)
{
    cerr << "-> Line out of bound error: Tried to reach line " << line <<
            " of a matrix " << lines << "x" << columns << "." << endl;
}

void Mtx::columnOutOfBoundError(int column)
{
    cerr << "-> Column out of bound error: Tried to reach column " << column <<
            " of a matrix " << lines << "x" << columns << "." << endl;
}

void Mtx::inconsistentLineSizeError(Mtx *mtx)
{
    cerr << "-> Inconsistent line size error: Expected a line with size " << columns <<
            ". Found a line with size " << mtx->getColumns() << "." << endl;
}

void Mtx::inconsistentColumnSizeError(Mtx *mtx)
{
    cerr << "-> Inconsistent column size error: Expected a column with size " << lines <<
            ". Found a column with size " << mtx->getLines() << "." << endl;
}

void Mtx::mtxSizeError(Mtx *mtx)
{
    cerr << "-> Matrix size error: Expected a matrix " << lines << "x" << columns <<
            ". Found a matrix " << mtx->getLines() << "x" << mtx->getColumns() << "." << endl;
}

void Mtx::mtxProdError(Mtx *mtx)
{
    cerr << "-> Matrix product error: Expected a matrix " << columns <<
            "xN. Found a matrix " << mtx->getLines() << "x" << mtx->getColumns() << "." << endl;
}

void Mtx::inconsistentColumnNumberError(unsigned int expectedValue, unsigned int foundValue)
{
    cerr << "-> Inconsistent Number of Columns Error: Expected a matrix Nx" << expectedValue <<
            ". Found a matrix Nx" << foundValue << "." << endl;
}

void Mtx::inconsistentLineNumberError(unsigned int expectedValue, unsigned int foundValue)
{
    cerr << "-> Inconsistent Number of Lines Error: Expected a matrix " << expectedValue <<
            "xN. Found a matrix " << foundValue << "xN." << endl;
}

void Mtx::positionError()
{
    cerr << "-> Not Valid Position Error." << endl;
}

void Mtx::initializeMatrix(double value)
{
    values = new vector<double>();

    for (unsigned int i=0;i<lines*columns;i++) {
        values->push_back(value);
    }
}

//
// Created by Paul Brown on 2/16/16.
//

#include "Point.h"
#include <cmath>

namespace Clustering {


    Point::Point(int initDim) {

        __dim = initDim;
        __values = new double[__dim];

        for (int i = 0; i < __dim; i++)
            __values[i] = 0;

    }

    Point::Point(int initDim, double *initValues) : Point(initDim) {

        for (int i = 0; i < initDim; i++)
            __values[i] = initValues[i];

    }

    Point::Point(const Point &point) {

        __dim = point.__dim;
        __values = new double[__dim];

        for (int i = 0; i < __dim; i++)
            __values[i] = point.__values[i];

    }

    Point &Point::operator=(const Point &point) {

        if (this == &point)
            return *this;

        else {
            delete[] __values;
            __dim = point.__dim;
            __values = new double[__dim];

            for (int i = 0; i < __dim; i++)
                __values[i] = point.__values[i];

            return *this;
        }
    }

    Point::~Point() {

        delete[] __values;

    }

    void Point::setValue(int dim, double newValues) {

        __values[dim] = newValues;
    }

    double Point::getValue(int dim) const {

        return __values[dim];
    }

    double Point::distanceTo(const Point &point) const {

        double sum = 0;

        for (int i = 0; i < __dim; i++)
            sum += pow(__values[i] - point.__values[i], 2);

        return sqrt(sum);
    }

    Point &Point::operator*=(double d) {

        for (int i = 0; i < __dim; i++)
            __values[i] *= d;

        return *this;
    }

    Point &Point::operator/=(double d) {

        for (int i = 0; i < __dim; i++)
            __values[i] /= d;

        return *this;
    }

    const Point Point::operator*(double d) const {

        for (int i = 0; i < __dim; i++)
            __values[i] *= d;

        return *this;
    }

    const Point Point::operator/(double d) const {

        if (d == 0)
            return *this;

        else {
            for (int i = 0; i < __dim; i++)
                __values[i] /= d;

            return *this;
        }
    }

    Point &operator+=(Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++)
            point.__values[i] += point1.__values[i];

        return point;
    }

    Point &operator-=(Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++)
            point.__values[i] -= point1.__values[i];

        return point;
    }

    const Point operator+(const Point &point, const Point &point1) {

        Point(p) = point;
        p += point1;

        return p;
    }

    const Point operator-(const Point &point, const Point &point1) {

        Point(p) = point;
        p -= point1;

        return p;
    }

    bool operator==(const Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++) {
            if (point.__values[i] != point1.__values[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++) {
            if (point.__values[i] == point1.__values[i])
                return false;
        }
        return true;
    }

    bool operator<(const Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++) {
            if (point.__values[i] < point1.__values[i])
                return true;
        }
        return false;
    }

    bool operator>(const Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++) {
            if (point.__values[i] > point1.__values[i])
                return true;
        }
        return false;
    }

    bool operator<=(const Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++) {
            if (point.__values[i] <= point1.__values[i])
                return true;
        }
        return false;
    }

    bool operator>=(const Point &point, const Point &point1) {

        for (int i = 0; i < point.__dim; i++) {
            if (point.__values[i] >= point1.__values[i])
                return true;
        }
        return false;
    }

    std::ostream &operator<<(std::ostream &out, const Point &point) {

        for (int i = 0; i < point.__dim; i++)
            out << point.__values[i] << ", ";

        return out;
    }

//std::istream &operator>>(std::istream &istream, Point &point) {
//
//    std::string value;
//
//    int i = 1;
//    while (getline(istream, value, Point::POINT_VALUE_DELIM)){
//        double d = stod(value);
//        std::cerr << "Value: " << d << std::endl;
//        point.setValue(i++, d);
//    }
//    std::cerr << "Point: " << point << std::endl;
//
//    return istream;
//}
}


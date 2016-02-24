//
// Created by Paul Brown on 2/16/16.
//

#include "Cluster.h"
#include "Point.h"
#include <cassert>
#include <sstream>

using Clustering::Point;

namespace Clustering {


    Cluster::Cluster(const Cluster &cluster) {

        __cpy(cluster.__points);

    }

    Cluster &Cluster::operator=(const Cluster &cluster) {

        if (this != &cluster) {
            __del();
            __cpy(cluster.__points);
        }
        return *this;
    }

    Cluster::~Cluster() {

        __del();

    }

    void Cluster::add(const Point &point) {

        LNodePtr a = new LNode(point, nullptr);

        if (__points == nullptr) {
            __points = a;
        }
        else if (__points->point > point) {
            a->next = __points;
            __points = a;
        }
        else {
            LNodePtr curr = __points, nxt = __points->next;
            while (true) {
                if (nxt == nullptr || nxt->point > point) {
                    curr->next = a;
                    a->next = nxt;
                    break;
                }
                else {
                    curr = nxt;
                    nxt = nxt->next;
                }
            }
        }

        __size++;
    }

    const Point &Cluster::remove(const Point &point) {

        LNodePtr prev = nullptr, del = nullptr;

        if (__points->point == point) {
            del = __points;
            __points = __points->next;
            delete del;

            __size--;
        }
        else {
            prev = __points;
            del = __points->next;

            while (del != nullptr) {

                if (del->point == point) {
                    prev->next = del->next;
                    delete del;

                    __size--;

                    break;
                }

                prev = del;
                del = del->next;
            }

            return point;
        }

    }

//    std::ostream &operator<<(std::ostream &out, const Cluster &cluster) {
//
//        int i = 0;
//        for ( ; i < cluster.__points; i++)
//            out << cluster.__values[i] << ", ";
//        out << cluster.__values[i];
//
//        return out;
//
//    }

    std::istream &operator>>(std::istream &istream, Cluster &cluster) {

        std::string line;
        while (getline(istream,line)) {
            int d = (int) std::count(line.begin(),
                                     line.end(),
                                     Point::POINT_VALUE_DELIM);
            Point p(d + 1);
            std::stringstream lineStream(line);

            // call to Point::operator>>
            lineStream >> p;

            cluster.add(p);
        }

        return istream;
    }


bool operator==(const Cluster &lhs, const Cluster &rhs){

        if (lhs == rhs)
            return true;
        return false;
    }
//
//}
    bool operator!=(const Cluster &lhs, const Cluster &rhs){

        if (lhs != rhs)
            return true;
    }
//
//    Cluster &Cluster::operator+=(const Cluster &rhs) {
//        return <#initializer#>;
//    }
//
//Cluster &Cluster::operator-=(const Cluster &rhs) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator+=(const Point &rhs) {
//    return <#initializer#>;
//}
//
//Cluster &Cluster::operator-=(const Point &rhs) {
//    return <#initializer#>;
//}
//
//const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
//
//    Cluster newCluster = Cluster();
//
//    return newCluster;
//}
//
//const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
//    return Clustering::Cluster();
//}
//
//const Cluster operator+(const Cluster &lhs, PointPtr const &rhs) {
//    return Cluster();
//}
//
//const Cluster operator-(const Cluster &lhs, PointPtr const &rhs) {
//    return Cluster();
//}*/

    void Cluster::__del() {

        if (__size != 0) {
            LNodePtr c = __points, n = __points->next;
            //delete c->point;
            delete c;
        }
        __points = nullptr;
        __size = 0;

    }

    void Cluster::__cpy(LNodePtr pts) {

        LNodePtr reached = pts;
        LNodePtr curr = new LNode(reached->point, nullptr);
        __points = curr;
        LNodePtr prev = curr;
        reached = reached->next;

        for (; reached != nullptr; reached = reached->next) {
            curr = new LNode(reached->point, nullptr);
            prev->next = curr;
            prev = curr;
        }

    }

    int Cluster::getSize() const {
        return __size;
    }

//    const Point &Cluster::operator[](unsigned int index) const {
//        return __points[index];
//    }
}


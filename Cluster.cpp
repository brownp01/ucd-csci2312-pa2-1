//
// Created by Paul Brown on 2/16/16.
//

#include "Cluster.h"
#include "Point.h"
#include <cassert>

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

//    void Cluster::add(const Point &ptr) {
//
//        LNodePtr a = new LNode(ptr, nullptr);
//
//        if (__points == nullptr) {
//            __points = a;
//        }
//        else if (*(__points->point) > *ptr) {
//            a->next = __points;
//            __points = a;
//        }
//        else {
//            LNodePtr c = __points, n = __points->next;
//            while (true) {
//                if (n == nullptr || *(n->point) > *ptr) {
//                    c->next = a;
//                    a->next = n;
//                    break;
//                }
//                else {
//                    c = n;
//                    n = n->next;
//                }
//            }
//        }
//
//        __size++;
//    }

    const Point &Cluster::remove(const Point &ptr) {

        LNodePtr prev = nullptr, del = nullptr;

        if (__points->point == ptr) {
            del = __points;
            __points = __points->next;
            //delete del->point;
            delete del;

            __size--;
        }
        else {
            prev = __points;
            del = __points->next;

            while (del != nullptr) {

                if (del->point == ptr) {
                    prev->next = del->next;
                    //delete del->point;
                    delete del;

                    __size--;

                    break;
                }

                prev = del;
                del = del->next;
            }

            return ptr;
        }

    }

//std::ostream &operator<<(std::ostream &ostream, const Cluster &cluster) {
//    return <#initializer#>;
//}
//
//std::istream &operator>>(std::istream &istream, Cluster &cluster) {
//    return <#initializer#>;
//}
//
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


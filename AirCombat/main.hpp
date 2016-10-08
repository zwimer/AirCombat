#ifndef MAIN_H
#define MAIN_H

//Helpful typedef
typedef unsigned int uint;

//Signum
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

#endif // MAIN_H

#pragma once

#include <vector>
#include <string>

using namespace std;

class Helpers {
    private:
        static bool seededRandom;

        static void seedRandom();

    public:
        static double dot_product(vector<double> *v1, vector<double> *v2);

        template<class T>
        static T get_random(T lower_bound, T upper_bound);

        template<class T>
        static string join_vec(vector<T> *vec, const char* delimiter);
};

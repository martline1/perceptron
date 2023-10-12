#include "Helpers.h"

#include <numeric>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

bool Helpers::seededRandom = false;

void Helpers::seedRandom() {
    srandom(time(NULL));
    Helpers::seededRandom = true;    
}

double Helpers::dot_product(vector<double> *v1, vector<double> *v2) {
    return inner_product((*v1).begin(), (*v1).end(), (*v2).begin(), 0);
}

template
double Helpers::get_random<double>(double, double);

template
int Helpers::get_random<int>(int, int);

template<class T>
T Helpers::get_random(T lower_bound, T upper_bound) {
    const long max_rand = 1000000L;
 
    if (!Helpers::seededRandom) {
        Helpers::seedRandom();
    }
 
    T random_double = lower_bound + (upper_bound - lower_bound) * (random() % max_rand) / max_rand;

    return random_double;
}

template
string Helpers::join_vec<double>(vector<double>*, const char*);

template<class T>
string Helpers::join_vec(vector<T> *vec, const char* delimiter) {
    string result = "";

    for (unsigned int i = 0; i < (*vec).size(); i++) {
        bool isLast = (i + 1) >= (*vec).size();

        result += to_string((*vec).at(i));

        if (!isLast) {
            result += delimiter;
        }
    }

    return result;
}

#include <iostream>
#include <vector>

#include "CustomError/CustomError.h"
#include "KnownResult/KnownResult.h"
#include "TruthTable/TruthTable.h"
#include "Helpers/Helpers.h"
#include "Perceptron/Perceptron.h"

using namespace std;

int main() {
    try {
        vector<double> inputs;

        inputs.push_back(1.0);
        inputs.push_back(2.0);

        Perceptron perceptron(&inputs);

        KnownResult kr(AND);

        for (unsigned int i = 0; i < 10; i++) {
            cout << (kr.get_random_bool() ? "true" : "false") << endl;
        }
    } catch (CustomError err) {
        err.display();
    }

    return 0;
}

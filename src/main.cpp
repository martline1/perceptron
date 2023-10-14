#include <iostream>
#include <vector>

#include "CustomError/CustomError.h"
#include "TruthTable/TruthTable.h"
#include "KnownResult/KnownResult.h"
#include "Helpers/Helpers.h"
#include "Perceptron/Perceptron.h"

using namespace std;

int main() {
    try {
        unsigned long training_amount = 1000000;
        unsigned int num_of_inputs = 2;

        Perceptron perceptron(num_of_inputs);

        // And Training
        vector<KnownResult> results;

        for (int i = 0; i < training_amount; i++) {
            results.push_back(KnownResult(TruthTable::AND));
        }

        for (KnownResult &result: results) {
            perceptron.train(&result.get_inputs(), result.get_target());
        }

        cout << "Our guess for the known values: " << endl << endl;

        KnownResult kr(TruthTable::AND);

        kr.display();

        cout << "Perceptron result = " << perceptron.process(&kr.get_inputs());
    } catch (CustomError err) {
        err.display();
    }

    return 0;
}

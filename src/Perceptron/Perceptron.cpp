#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

#include "Perceptron.h"
#include "../Helpers/Helpers.h"
#include "../CustomError/CustomError.h"

using namespace std;

void Perceptron::constructor_body(vector<double> *inputs) {
    // Generate random weight for each input
    for (unsigned int i = 0; i < (*inputs).size(); i++) {
        weights.push_back(Helpers::get_random<double>(-1.0, 1.0));
    }
}

Perceptron::Perceptron(vector<double> *inputs):
    learning_rate(0.1f)
{
    this->constructor_body(inputs);
}

Perceptron::Perceptron(vector<double> *inputs, double learning_rate):
    learning_rate(learning_rate)
{
    this->constructor_body(inputs);
}

// And operator training
void Perceptron::train(vector<double> *inputs, int target) {
    int guess = this->process(inputs);
    int error = target - guess;

    for (unsigned int i = 0; i < this->weights.size(); i++) {
        this->weights[i] += error * (*inputs)[i] * this->learning_rate;
    }

}

int sign(double result) {
    if (result >= 0) {
        return 1;
    }

    return -1;
} 

int Perceptron::process(vector<double> *inputs) {
    if (this->weights.size() != (*inputs).size()) {
        throw CustomError(
            "Perceptron::process",
            "weights and inputs len doesn't match"
        );
    }

    double result = Helpers::dot_product(&this->weights, inputs);

    return sign(result);
}

void Perceptron::display() {
    cout << "Weights:" << endl;
    cout << Helpers::join_vec(&this->weights, ", ") << endl << endl;
}

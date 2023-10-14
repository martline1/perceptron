#pragma once

#include <vector>

using namespace std;

class Perceptron {
    private:
        double learning_rate;
        vector<double> weights;

        void constructor_body(unsigned int num_of_inputs);

    public:
        Perceptron(unsigned int num_of_inputs);
        Perceptron(unsigned int num_of_inputs, double learning_rate);

        void train(vector<double> *inputs, int target);

        int process(vector<double> *inputs);

        void display();
};

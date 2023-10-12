#pragma once

#include <vector>

using namespace std;

class Perceptron {
    private:
        double learning_rate;
        vector<double> weights;

        void constructor_body(vector<double> *inputs);

    public:
        Perceptron(vector<double> *inputs);
        Perceptron(vector<double> *inputs, double learning_rate);

        void train(vector<double> *inputs, int target);

        int process(vector<double> *inputs);

        void display();
};

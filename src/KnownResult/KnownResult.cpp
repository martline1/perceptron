#include <iostream>

#include "KnownResult.h"
#include "../TruthTable/TruthTable.h"
#include "../Helpers/Helpers.h"
#include "../CustomError/CustomError.h"

KnownResult::KnownResult(TruthTable::Value table) {
    switch (table) {
        case TruthTable::AND:
            this->and_known_result();
            break;
        case TruthTable::OR:
        case TruthTable::XOR:
        default: 
            throw CustomError(
                "KnownResult::KnownResult",
                "Truth table not implemented yet"
            );
    }
}

void KnownResult::and_known_result() {
    this->inputs.clear();

    this->inputs.push_back(this->get_random_bool());
    this->inputs.push_back(this->get_random_bool());

    this->target = (this->inputs[0] == this->inputs[1])
        ? 1
        : -1;
}

bool KnownResult::get_random_bool() {
    int randomValue = Helpers::get_random<int>(0, 2);

    return !!randomValue;
}

vector<double>& KnownResult::get_inputs() {
    return this->inputs;
}

int& KnownResult::get_target() {
    return this->target;
}

void KnownResult::display() {
    cout
        << "Value 1: " << this->inputs[0]
        << endl
        << "Value 2: " << this->inputs[1]
        << endl
        << endl
        << "result = " << this->target
        << endl
        << endl;
}

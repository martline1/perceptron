#include "KnownResult.h"
#include "../TruthTable/TruthTable.h"
#include "../Helpers/Helpers.cpp"
#include "../CustomError/CustomError.h"

KnownResult::KnownResult(TruthTable table) {
    switch (table) {
        case AND:
            this->and_known_result();
            break;
        case OR:
        case XOR:
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

    int result = this->inputs[0] && this->inputs[1]
        ? 1
        : -1;
}

bool KnownResult::get_random_bool() {
    int randomValue = Helpers::get_random<int>(0, 1);

    return !!randomValue;
}

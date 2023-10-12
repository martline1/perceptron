#pragma once

#include <vector>

#include "../TruthTable/TruthTable.h"

using namespace std;

class KnownResult {
    private:
        vector<double> inputs;
        int target;

        void and_known_result();

    public:
        KnownResult(TruthTable table);

        bool get_random_bool();
};

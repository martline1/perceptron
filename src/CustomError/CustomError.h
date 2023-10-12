#pragma once

#include <string>

using namespace std;

class CustomError {
    private:
        string fn_name;
        string message;

    public:
        CustomError(string fn_name, string message);

        void display();
};

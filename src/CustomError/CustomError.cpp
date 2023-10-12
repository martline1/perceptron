#include <string>
#include <iostream>

#include "CustomError.h"

using namespace std;

CustomError::CustomError(string fn_name, string message):
    fn_name(fn_name),
    message(message)
{}

void CustomError::display() {
    cout
        << "An exception has occurred at "
        << this->fn_name
        << " error: "
        << this->message
        << endl;
}

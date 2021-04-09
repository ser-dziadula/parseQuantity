#include <iostream>

int parseQuantity(const char * input) {
    if(static_cast<int>(input[0]) < 48 || static_cast<int>(input[0]) > 57) {
        return 0;
    }
   
    int size = 0;
    while (input[size] != '\0') {
        size++;
    }
   
    char parsedInput[10];
    int parsedInputIndex = 0;
    for(int i = 0; i < size; i++) {
        if(static_cast<int>(input[i]) >= 48 && static_cast<int>(input[i]) <= 57) {
            parsedInput[parsedInputIndex++] = input[i];
            if(parsedInputIndex > 9) {
                break;
            }
        }
    }
    if(atoi(parsedInput) < 0) {
        parsedInput[9] = '\0';
    }
    return atoi(parsedInput);
}

int main()
{
    std::cout << parseQuantity("123456fdf ]p[' 7890123");
    return 0;
}


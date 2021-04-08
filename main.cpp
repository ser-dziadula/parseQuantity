 #include <iostream>

int parseQuantity(const char * input) {
    if(static_cast<int>(input[0]) < 48 || static_cast<int>(input[0]) > 57) {
        return 0;
    }

    int size = 0;
    while (input[size] != '\0') {
        size++; 
    }
   
    int counter = 0;
    for(int i = 0; i <= size; i++) {
        if(static_cast<int>(input[i]) >= 48 && static_cast<int>(input[i]) <= 57) {
            counter++;
        }
    }
   
    char parsedInput[counter];
    int parsedInputIndex = 0;
    for(int i = 0; i <= size; i++) {
        if(static_cast<int>(input[i]) >= 48 && static_cast<int>(input[i]) <= 57) {
            parsedInput[parsedInputIndex++] = input[i];
        }
    }

    int intSize = sizeof(int);
    if(intSize == 2) {
        return (atoi(parsedInput) < 0) || (counter > 5) ? 32767 : atoi(parsedInput);
    } else {
        return (atoi(parsedInput) < 0) || (counter > 10) ? 2147483647 : atoi(parsedInput);
    }
  return 0;
}

int main()
{
    std::cout << parseQuantity("21474836485");
    return 0;
}

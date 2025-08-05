#include <iostream>
#include <string>
#include <string_view> // memory safe way to avoid copying data of a string

// This function takes a std::string_view, which avoids copying the string data.
// It's a read-only view of the string.
void print_string(std::string_view text) {
    std::cout << "The string is: '" << text << "'." << std::endl;
    // We can access properties like size
    std::cout << "The length is: " << text.size() << " characters." << std::endl;
}

// Function that uses an if statement with an initializer
void find_and_print_greeting(std::string_view message) {
    // This is a C++17 feature. 'pos' is initialized and its value is
    // used as the condition for the if statement.
    if (size_t pos = message.find("Hello"); pos != std::string::npos) {
        std::cout << "Found a greeting! It starts at index " << pos << std::endl;
        // The variable 'pos' is only accessible inside this 'if' and the 'else' block.
    } else {
        std::cout << "Could not find a greeting in the message." << std::endl;
    }
    // 'pos' is not accessible here. It went out of scope.
}

int main() {
    std::cout << "--- Demonstrating std::string_view ---" << std::endl;
    
    // std::string_view can be created from a C-style string literal.
    const char* c_style_greeting = "Hello, world!";
    std::string_view greeting_view(c_style_greeting);
    print_string(greeting_view);

    // It can also be created from an std::string object, again without copying.
    std::string dynamic_string = "This is a dynamic string.";
    print_string(dynamic_string);

    std::cout << "\n--- Demonstrating if statement with initializer ---" << std::endl;

    // Call the function with a message that contains the word "Hello"
    find_and_print_greeting("This is a message with 'Hello' inside.");

    // Call the function with a message that does not contain "Hello"
    find_and_print_greeting("Goodbye, and thanks for all the fish!");

    // You can also use this feature directly in a procedural main function
    std::cout << "\n--- Using if with initializer in main() ---" << std::endl;
    std::string data = "The number is 42.";
    
    if (size_t pos = data.find("42"); pos != std::string::npos) {
        std::cout << "Found the number '42' at position: " << pos << std::endl;
    } else {
        std::cout << "Did not find the number '42'." << std::endl;
    }

    return 0;
}
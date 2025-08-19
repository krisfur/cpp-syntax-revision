#include <iostream> // for std::cout and std::cin
#include <string> // for std::string and std::string_view
#include <string_view> // memory safe way to avoid copying data of a string
#include <cmath> // for mathematical functions
#include <array> // for std::array, a safer alternative to C-style arrays
#include <vector> // for using vectors
#include <algorithm> // for algorithms like std::sort
#include <map> // for using maps (key-value pairs)
#include <random> // for random number generation
#include <fstream> // for file I/O
#include <optional> // for std::optional, which can represent a value that may or may not be present

#include "functions.hpp" // include the header file for function declarations

std::optional<std::string> find_user(int id) {
        if (id == 1) {
            return "Alice"; // Return a value
        }
        return std::nullopt; // Return an empty optional
    }

class myClass{
    public:
        myClass(float initialValue = 1.0f) : m_value(initialValue) {;} //a constructor, put in brackets things to initialise when class is called
        ~myClass() = default; //a deconstructor, the compiler will automatically generate a default destructor, can instead use ~myClass() {;} to define your own
        int publicData; //this can be accessed by anyone - bad practice, but useful for simple classes

        //class functions allow you to encapsulate behavior
        // getters and setters are used to access private data safely
        float getValue() const {
            return m_value;
        }

        void setValue(float newValue) {
            m_value = newValue;
        }

        void printValue() const {
            std::cout << "Widget value: " << m_value << std::endl;
        }

    protected:
        int privateData; //some integer to be accessed only by this class and classess which inherit this class

    private:
        //private member variable, can be used to store data specific to this class
        //it's common to prefix member variables with "m_" or a trailing "_".
        float m_value;
}; //<- need this semicolon to end the class definition
	
void read_and_write_file() {
        std::ifstream inputFile("example.txt"); // open a file for reading
        if (!inputFile) {
            std::cerr << "Error opening input file." << std::endl;
            return; // exit if the file cannot be opened
        }

        std::ofstream outputFile("example_output.txt"); // open a file for writing
        if (!outputFile) {
            std::cerr << "Error opening output file." << std::endl;
            return; // exit if the file cannot be opened
        }

        int i = 0;
        while (inputFile >> i) { // read integers from the file until EOF
            outputFile << i << std::endl; // write to the output file
        }
    }

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

    // ###########
    // Printting
    std::cout << "Hello, World!" << std::endl; //use std::endl; to end a line and flush the output buffer
	std::cout << "Hello, World!\n"; //also gives a new line, but does not flush the output buffer
	//you can use setw(int) to set the spacewidth of output
	
    // ###################
	// Declaring variables
	//int i;
	//i=10;
	//or
	int i = 10;
	//or
	//int i (10);
	bool really = 1; //0 for false, anything above 0 for true, convention is 1
    auto j = 20; //auto will automatically deduce the type of the variable based on the value assigned to it
    //auto is useful for complex types like iterators or when you want to avoid specifying the type explicitly
    //best used for types that are obvious from the context, like iterators, lambda functions, custom classes, etc.
	
    // ############
	// User input
	//std::cin >> i;
	//std::cout << "number is " << i << std::endl;
	
	//inputting strings is a bit more complicated unfortunately
	//std::string name;
	//getline(std::cin, name);
	//std::cout << name;
	//C++ has very weak in-built capabilities of working with strings - a language made for robots
	//fortunately libraries help you go around it like the <string> library
	
	// ###################
	// Casting datatypes
	std::string mystr ("1204");
	int myint = std::stoi(mystr);
    // equivalent to
    /*
    int value = 0;

    // Get pointers to the beginning and end of the string's character data
    const char* first = str.data();
    const char* last = str.data() + str.size();

    // Perform the conversion
    auto [ptr, ec] = std::from_chars(first, last, value);
    */
	
	//casting from into to float and such is relatively easy
	int notFLoat = 10;
	float isFloat = static_cast<float>(notFLoat); //static_cast is the preferred way to cast types in C++
	//now you have a float b based on value from a
	
	
	// #####
	// maths
	//you will need the <cmath> library
	//if you want to use scientific constants make sure you define it:
	//#define _USE_MATH_DEFINES
	//#include <cmath>
	double a = 3;
	double b = 4;
	double z = 5;
	double c = a+b;
	double d = z*(a+b); //everything is as simple as you think
	
	b+=3; //changes b to a value b+3
	b-=3; // changes b to a value b-3
	a++; //adds one to a, but does it after other functions thigs such as print
	++a; //also adds one to a, but does it before things such as print

	
	//using advanced functions - need to call them from cmath
	double e = std::pow(a,2); //to use powers use pow(number, power)
	double f = std::sqrt(a); //square root is sqrt(number)
	double g = std::cos(30); //using a cosine, same for tan, atan etc.
	double h = std::exp(a); //exponential
	
	//constants
	//M_PI is pi
	//M_E is e
	//so you could use std::pow(M_E,2) instead of std::exp(2)
	//those constants are NOT always there. Newer compilers usually won't have them, in new MinGW you need the #define _USE_MATH_DEFINES statement to enable them
	
	
    // #######
	// arrays

    //#include <array> // for std::array, a safer alternative to C-style arrays

    // The structure is: std::array<type, size> name = { ... };
    // The size is part of the type and must be known at compile time.
    std::array<double, 4> numbers = {1, 2.4, 3.6, 7.8};

    // You change elements in the same way:
    numbers[3] = 4.5; // We are still counting from 0.

    // Accessing elements is also the same, but the .at() method is safer
    std::cout << numbers[3] << std::endl; // Prints 4.5

    // A key benefit: an std::array knows its own size! C-style doesn't
    std::cout << "The size of the array is: " << numbers.size() << std::endl;

    // For safe access, use .at(), which checks if the index is in bounds.
    // This will throw an error if you go out of range, preventing bugs.
    try {
        std::cout << numbers.at(3) << std::endl; // OK
        std::cout << numbers.at(10) << std::endl; // This would throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // A 2D array is simply an array of arrays.
    // The structure is: std::array<std::array<type, columns>, rows> name = { ... };

    std::array<std::array<double, 3>, 2> results2d = {{
        {1, 2, 3},  // This list initializes the first inner array
        {4, 5, 6}   // This list initializes the second inner array
    }};

    // Accessing items is identical to the C-style version:
    std::cout << results2d[1][2] << std::endl; // Prints 6 (3rd element from 2nd row)
    //or safely
    try {
        std::cout << results2d.at(1).at(2) << std::endl; // Also prints 6
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
	// C-style arrays are no longer recommended, but you can still use them
	//structure is: datatype arrayName[number of things in an array] = {items, in, the, array}
	//double numbers[]={1,2.4,3.6,7.8};
	//not giving the array size makes an array just the size needed, you can declare an array without doing anything by using:
	//double numbers[]={stuff, stuff, stuff};

	//accessing array elements:
	//std::cout << numbers[3] << std::endl;
	//prints 4.5

	//declaring two-dimensional arrays
	//type name[number of rows][number of items in a row];
    //double results[2][3]={ {1,2,3}, {4,5,6} };
	//accessing items in 2d arrays:
	//std::cout << results[1][2] << std::endl; //prints 3rd element from 2nd row
	//output: 6
	
	
    // ########
	// vectors

	//vectors are like arrays, but it's hard to insert items in the middle, only the ones at the ends
	//in exchange they protect you from errors of calling an item beyond the indexes in the list
	//vectors can contain both basic-types as well as user defined types (objects)
	//need to #include<vector>
	std::vector<float> myVector; //declare with vector<type> name, no need to specify size!
	//float f = myVector[2]; //gets 3rd item in vector
	//float g = myVector.at(2); //also gets 3rd item in vector
	myVector.push_back(10.5); //adds 10.5 at the end of the vector
	size_t vectorSize = myVector.size(); //stores in k the size of the vector
    std::cout << "Size of vector: " << vectorSize << std::endl; //prints the size of the vector
	//myVector.pop_back(); //remove last item
	//myVector.resize(100); //sets the size to 100 filling with default values
	//myVector.reserve(100); //reserves 100 memory spaces without inputting numbers
	//myVector.capacity(); //tells you how much memory the vector has reserved
	myVector.clear(); //clears all items in the vector
    myVector.resize(10);
	

    // ##############################
	// Iterating over a std::vector
	//for loop - oldschool C-style loop - AVOID!
    /*
	for(int i=0;i<myVector.size();++i){
		//stuff accessing myVector[i]
	}
	*/

	//C++11 auto loop
	for(auto& item : myVector){ //get a reference to each item in the vector, consider const auto& if you don't want to modify the items
        std::cout << item << " "; //prints each item in the vector
    }
    std::cout << std::endl; //just flushes the output buffer


    // ###########
    // Algorithms

    //#include <algorithm> // for algorithms like std::sort, std::find, etc.

    std::vector<int> nums = {5, 2, 8, 1, 9};

    // Sort the vector
    std::sort(nums.begin(), nums.end());

    // Find a specific value
    auto it = std::find(nums.begin(), nums.end(), 8);
    if (it != nums.end()) {
        std::cout << "Found 8!\n";
    }


    // #####
    // Maps

    //#include <map> // for using maps (key-value pairs), like dict in Python

    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;

    std::cout << "Alice's age is " << ages["Alice"] << std::endl;

    //struture bindings
    for (const auto& [name, age] : ages) {
        std::cout << name << " is " << age << " years old.\n";
    }


    // #################
    // Lambda functions

    // Use a lambda with std::count_if to count the even numbers.
    std::vector<int> dataVec = {1, 2, 3, 4, 5, 6};
    int64_t even_count = std::count_if(dataVec.begin(), dataVec.end(), [](int n) {
        // This is the lambda function: [](...){...}
        return n % 2 == 0;
    });

    std::cout << "There are " << even_count << " even numbers.\n";
        
	
    // #############
	// Conditionals
	int valueOne = 1;
	int valueTwo = 2;

    // if (condition){}
	
	if ((valueOne==1) && (valueTwo==2)) {
		std::cout << "Nice!" << std::endl;
	} else if ((valueOne>10) || (valueTwo<10)){
		std::cout << "Kinda" << std::endl;
	} else {
		std::cout << "Fail" << std::endl;
	}

    // switch statement
    int x = 1;
    switch (x) {
    case 1: 
        std::cout << "x is 1" << std::endl;
        break; //you use break since otherwise the default case will still be executed - break makes it so it skips the default case
    case 2:
        std::cout << "x is 2" << std::endl;
        break;
    default:
        std::cout << "value of x unknown" << std::endl;
    }
	
	
    // #####
	// Loops
	
	//while loop - same as C#
	int condition=3;
	while(condition<=5){ //can use a bool set to 1 or not increment in order to get an infinite loop
		std::cout << condition << std::endl;
		condition++;
	}
	
	//do while - runs the code at least once, until while condition is met, then does other stuff
    /*
	int guessInput;
	do {
		std::cout << "Guess a number between 1 and 10: ";
		std::cin >> guessInput; //input a number
	} while (i==5); //semicolon at the end of the finish condition
    */
	
	//for loop - for(initialization; condition to keep going; increase);
	for(int i=1; i<3; i++){
		std::cout << i << std::endl;
	}
	
	//for loop for running through a set of data - like for each loop in C# or for loop in Python
	std::string str ("Hello!");
	for (char c : str){ //runs the code once for every char in that string, works with arrays as well
		std::cout << "[" << c << "]";
	}
	
	
    // ####
	// RNG
	
	// 1. Seed with a real random value, if available
    std::random_device rd;

    // 2. Create a C++ pseudo-random generator engine, seeded with the random device
    // std::mt19937 is a good general-purpose choice
    std::mt19937 gen(rd());

    // --- Example 1: Uniform Distribution (your first case) ---
    // 3. Create a distribution object for a float range [1.0, 10.0]
    std::uniform_real_distribution<float> distrib_uniform(1.0f, 10.0f);

    std::cout << "Uniform distribution [1.0, 10.0]:\n";
    for (int i = 0; i < 5; ++i) {
        // 4. Get a random number by calling the distribution with the generator
        float random_uniform = distrib_uniform(gen);
        std::cout << random_uniform << "\n";
    }

    // --- Example 2: Normal Distribution (your second case) ---
    // 3. Create a distribution object for a normal distribution
    //    Mean = 70.0, Standard Deviation = 10.0
    std::normal_distribution<float> distrib_normal(70.0f, 10.0f);

    std::cout << "\nNormal distribution (mean=70, std_dev=10):\n";
    for (int i = 0; i < 5; ++i) {
        // 4. The same generator can be used with different distributions
        float random_normal = distrib_normal(gen);
        std::cout << random_normal << "\n";
    }
	
	
	
	// ################################
	// Pointers and memory management


    // basic version - avoid when possible!

	//references
	float example = 2.0f;
	float &example2 = example; //this just creates a reference to the variable example, so example2 is just an alias for example
	
	//pointers
	float *example3 = &example; //pointer to float x - points to the address of the variable x, stored in hexadecimal format
	float example4 = *example3; //dereferencing pointer example3 - gives you back the value stored at address of example, so value of example
	
	// modern C++ uses smart pointers
    // std::unique_ptr, std::shared_ptr, std::weak_ptr

    // std::unique_ptr 
    //owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope
    // It cannot be copied, only moved.
    std::unique_ptr<float> smartPtr = std::make_unique<float>(3.14f); // creates a unique_ptr to a float initialized to 3.14
    std::cout << "Value pointed to by smartPtr: " << *smartPtr << std::endl;    


    // std::shared_ptr 
    //can share ownership of an object with other shared_ptr instances
    // It keeps a reference count of how many shared_ptr instances point to the same object.
    std::shared_ptr<float> sharedPtr = std::make_shared<float>(2.71f); // creates a shared_ptr to a float initialized to 2.71
    std::cout << "Value pointed to by sharedPtr: " << *sharedPtr << std::endl;


    // std::weak_ptr 
    //does not affect the reference count of a shared_ptr
    // It is used to break circular references between shared_ptr instances.
    std::weak_ptr<float> weakPtr = sharedPtr; // creates a weak_ptr from
    // a shared_ptr, it does not increase the reference count
    if (auto lockedPtr = weakPtr.lock()) { // lock() returns a shared_ptr if the object is still alive
        std::cout << "Value pointed to by lockedPtr: " << *lockedPtr << std::endl;
    } else {
        std::cout << "The object pointed to by weakPtr has been deleted." << std::endl;
    }

    // these are deleted automatically when they go out of scope
    // no need to manually delete them, smart pointers handle that for you

    // if you need to manually manage memory, you can still use raw pointers
    // but it's generally safer to use smart pointers in modern C++ code

    
    //"new" keyword
	//you can declare variables with the "new" keyword to store them in long-term memory/heap, when they're no longer needed remember to delete them
	float * yourFloat = new float;
	delete yourFloat;
	//if you don't delete it you will eventually cause a memeory leak which is VERY BAD!
    //things on the heap are not automatically deleted when they go out of scope, so you need to manage them manually
	

    // string_view
    // std::string_view is a non-owning view of a string, it does not own the data it points to    
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
	
	// ##########
	// Functions

	//you put them OUTSIDE of main!
	//put it before main or you will have to declare it before main - can still keep it under it, but need a declaration before
	
	//example of int function:

    /*
	int addition (int a, int b){
		int r;
		r=a+b;
		return r;
	}
	//then in main call it like:
	z = addition(5,3);
	std::cout << z << std::endl;
	
	//function of no specific type uses type void
	void printmessage ()
	{
		cout << "I'm a function!";
	}
	//then call it in main
	printmessage();
    */
	
	
	//defining functions in separate files
	//in order to put your functions in separate files you need a .cpp file which contains it AND a header .h file which declares it
	
	//inside the myFile.h file:
    /*
	#ifndef PROGRAMNAME_MYFILES_H
	#define PROGRAMNAMe_MYFILES_H
	void myFunction(variables); //ended with a semicolon ; yuo only declare that the function exist
	#endif //PROGRAMNAMe_MYFILES_H
	
	//then you need to include that header file in both your main.cpp AND your myFile.cpp
	
	//inside the myFile.cpp file:
	#include "myFile.h"
	void myFunction(variables)
	{
		//things that this method does
	}
	*/

    //#include "functions.hpp" include the header file for function declarations
    std::cout << "Function example: " << addition(5, 3) << std::endl; // calls the addition function from functions.cpp

    // !! You also need to include the functions.cpp file in your CMakeLists.txt file to compile it

    // Optional values
    // C++17 introduced std::optional, which can be used to represent a value that
    //#include <optional> // for std::optional, which can represent a value that may or may not be present

    // This function might not find a user.
    /*
    std::optional<std::string> find_user(int id) {
        if (id == 1) {
            return "Alice"; // Return a value
        }
        return std::nullopt; // Return an empty optional
    }
    */
    auto user = find_user(1);
    if (user.has_value()) { // or just 'if (user)'
        std::cout << "Found user: " << user.value() << std::endl;
    }
	

    // ##########
    // Templates

    // A single function template that works for any type supporting the '+' operator.
    /*
    template <typename T>
    T addT(T a, T b) {
        return a + b;
    }
    */

    // !! this all goes in the header file, not in the cpp file !!

    int sum_int = addT(5, 3);       // T becomes int
    double sum_double = addT(2.5, 3.7); // T becomes double
	
	// ##############
	// Stream states

	//when using a console I/O stream or a file I/O we deal with stream states
	//good - all went well, previous operation succeded, next one may proceed
	//fail - something went wrong, operations before this one may have been ok and might be readable, but this one is bad and no other ones can be good
	//bad - something went wrong, all is lost, nothing survived
	//eof - end of file, you have read the last item from a file
	
	//#include <fstream> to use file stream

    // for memory safety we want to use RAII (Resource Acquisition Is Initialization) principles
    // so we will use std::ifstream and std::ofstream for file I/O inside a function or a scope
    // this way the file will be automatically closed when the scope ends

    // Example function to read from a file and write to another file, this has to be outside main
    /*
    void read_and_write_file() {
        std::ifstream inputFile("example.txt"); // open a file for reading
        if (!inputFile) {
            std::cerr << "Error opening input file." << std::endl;
            return; // exit if the file cannot be opened
        }

        std::ofstream outputFile("example_output.txt"); // open a file for writing
        if (!outputFile) {
            std::cerr << "Error opening output file." << std::endl;
            return; // exit if the file cannot be opened
        }

        int i = 0;
        while (inputFile >> i) { // read integers from the file until EOF
            outputFile << i << std::endl; // write to the output file
        }
    }
	*/
    read_and_write_file(); // call the function to read and write files
	
	
	
	
	// Classes
	
	//create the class OUTSIDE of main (just like methods - better before to not have to pre-declare it)
    

	
	//you can put a class in a namespace to avoid calling multiple classes the same name
    /*
	Namespace MyNamespace
	{
		class myClass //...
	}
	//call it
	MyNamespace::myClass
    */


	
	//you can create objects and access their properties using dot notation:
	myClass object1; //declare a new object called object1 based on class className, default value
    myClass object2(42.5f);   // Provides a specific value

    object1.setValue(100.0f);

    std::cout << "w1 value is: " << object1.getValue() << std::endl;
    
    object2.printValue();

	object1.publicData = 3; //access public data directly
    std::cout << "Public data of object1: " << object1.publicData << std::endl;
	
	//or using pointer notation - old school way - AVOID!
	myClass * object3 = new myClass();
	float v = object3->getValue();
    delete object3;

    //modern C++ uses smart pointers to manage memory automatically
    auto smartObject = std::make_unique<myClass>(5.0f); //main use of auto - not typing out the whole type for a class object
    std::cout << "Value of smartObject: " << smartObject->getValue() << std::endl;
    // this will be deleted once it goes out of scope, no need to manually delete it
	
	
	//inheritance
    /*
	class YourNewClass: public ClassYouWantToInherit
	{
		//put some new properties of this new class here
		//all properties of the inherited class will now also be properties of the new class (unless they are private!)
	}
    */

    return 0;
}
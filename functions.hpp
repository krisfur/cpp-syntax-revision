#ifndef CPPSYNTAXREVISION_FUNCTIONS_H
#define  CPPSYNTAXREVISION_FUNCTIONS_H
int addition (int a, int b); //ended with a semicolon ; yuo only declare that the function exist

// --- Template function DEFINITION ---
// The entire template, including the body, goes in the header file.
template <typename T>
T addT(T a, T b) {
    return a + b;
}
#endif //CPPSYNTAXREVISION_FUNCTIONS_H
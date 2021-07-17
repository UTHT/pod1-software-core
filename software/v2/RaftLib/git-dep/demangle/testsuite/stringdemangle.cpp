#include "demangle.hpp"

int main() 
{
    const char * input = "_ZStL6ignore";
    auto demangled = 
#ifdef INJECT_DEMANGLE_NAMESPACE
    DEMANGLE_NAMESPACE::
#endif
    demangle(input);
    bool valid = demangled == std::string("std::ignore") || demangled == std::string(input); 
    return( valid ? 0 : -1 );
}

#include <iostream>
#include <string>

void PrintName()
{
    std::cout << "Sava Statkov!" << std::endl;
}

void PrintUniversity_Major()
{
    std::cout << "New Bulgarian University / Informatics" << std::endl;
}

void DisplayingKeywords()
{
    std::string words[] = {
        "alignas", "alignof", "asm", "auto", "bool", "break", "case", "catch",
        "char", "class", "const", "constexpr", "continue", "default", "delete", "do",
        "double", "else", "enum", "explicit", "export", "extern", "false", "float",
        "for", "friend", "goto", "if", "inline", "int", "long", "mutable",
        "namespace", "new", "noexcept", "nullptr", "operator", "private", "protected", "public",
        "register", "return", "short", "signed", "sizeof", "static", "static_assert", "struct",
        "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef",
        "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "while"
    };

    for (std::string word : words)
    {
        std::cout << word << " ";
    }

    std::cout << std::endl;
}

void PrintDefinitions()
{
    std::cout << "Lexeme - the smallest meaningful unit in a program, "
              << "such as a keyword, identifier, operator or literal." << std::endl;

    std::cout << "Literal - a fixed value written directly in the program." << std::endl;

    std::cout << "Command - an instruction that tells the program "
              << "to perform a specific action." << std::endl;
}

void PrintDirectives()
{
    std::cout << "#define - Defines a macro or symbolic constant." << std::endl;
    std::cout << "#undef - Removes a previously defined macro." << std::endl;
    std::cout << "#include - Includes the contents of another file." << std::endl;
    std::cout << "#if - Checks a condition for conditional compilation." << std::endl;
    std::cout << "#ifdef - Checks if a macro is defined." << std::endl;
    std::cout << "#ifndef - Checks if a macro is not defined." << std::endl;
    std::cout << "#else - Specifies an alternative when a condition is false." << std::endl;
    std::cout << "#elif - Checks another condition if the previous one is false." << std::endl;
    std::cout << "#endif - Ends a conditional compilation block." << std::endl;
    std::cout << "#line - Changes the line number and optionally the file name." << std::endl;
    std::cout << "#error - Generates a compilation error with a message." << std::endl;
    std::cout << "#pragma - Gives special instructions to the compiler." << std::endl;
}

int main()
{
    PrintName();
    PrintUniversity_Major();
    DisplayingKeywords();
    PrintDefinitions();
    PrintDirectives();

    return 0;
}
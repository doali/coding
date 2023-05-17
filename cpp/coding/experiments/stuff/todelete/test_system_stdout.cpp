#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

// --------------------------------------------------------------------------------
// La ressource que j'ai utilisée
// https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po
//
// Compilation
// g++ -Wall test_system_stdout.cpp -o test_system_stdout
//
// Execution
// ./test_system_stdout
//
// lun. 17 oct. 2022 11:01:58 CEST
// --------------------------------------------------------------------------------

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

int main(int argc, char** argv)
{
	const std::string my_cmd {"ls"};

	std::string stored_in_ram = exec(my_cmd.c_str());

	std::cout << stored_in_ram << std::endl;

	return 0;
}

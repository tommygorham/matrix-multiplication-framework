#pragma once
#include <string_view> // type_name() 
#include <chrono> 

// terminal output
void writeToTerminal(std::string_view declaration,
				     std::string_view value_type,
		             std::size_t bytes,
		             std::size_t elements,
		             std::chrono::duration<double, std::milli> init, 
		             std::string_view am);

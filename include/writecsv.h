#pragma once 
#include <string_view> // type_name() 
#include <fstream> // write to csv 
#include <string> //filename, args  
#include <chrono> 
void writeToCSV(std::string file_path, 
                std::string filename, 
                std::string_view value_type, 
                std::size_t elements, 
                std::size_t bytes, 
                std::chrono::duration<double,std::milli> mm_time, 
                std::string_view am);

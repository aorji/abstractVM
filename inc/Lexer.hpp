//
// Created by Anastasiia ORJI on 12/20/18.
//

#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <regex>
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <unistd.h>

class Lexer{
public:
    Lexer(int ac, char **av);
    void run();
    void read_from_file();
    void read_from_st_input();
//    bool check_for_validity(char *path);
    std::vector<std::smatch> getReadValue();

private:
    int ac_;
    char **av_;

    std::vector<void (Lexer::*)()> reader;
    std::vector<std::smatch> read_value;

    std::regex instr_with_no_value;
    std::regex instr_with_int_value;
    std::regex instr_with_fd_value;
    std::regex comment;
    std::regex empty_line;

    std::smatch result;
    std::string line;
};

#endif
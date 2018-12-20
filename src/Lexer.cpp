//
// Created by Anastasiia ORJI on 12/20/18.
//

#include <Exception.hpp>
#include "../inc/Lexer.hpp"

Lexer::Lexer(int ac, char **av):ac_(ac), av_(av) {
    instr_with_no_value = (R"(^(pop|dump|add|sub|mul|div|mod|print|exit)(\s*[;].*)*)");
    instr_with_int_value = (R"(^(push|assert)\s+(int8|int16|int32)(\()([\-]?\d+)(\))(\s*[;].*)*)");
    instr_with_fd_value = (R"(^(push|assert)\s+(float|double)(\()([\-]?\d+\.\d+)(\))(\s*[;].*)*)");
    comment = (R"(\s*[;].*)");
    empty_line = (R"(^$)");
    reader.push_back(&Lexer::read_from_st_input);    //type 0
    reader.push_back(&Lexer::read_from_file);    //type 1
}

void
Lexer::run() {
    return !(ac_ - 1) ? (this->*reader.at(0))() : (this->*reader.at(1))();
}

void
Lexer::read_from_st_input() {
    while (std::cin){
        std::getline(std::cin, line);
        if (std::regex_match(line, result,  instr_with_no_value) ||
            std::regex_match(line, result, instr_with_int_value) ||
            std::regex_match(line, result, instr_with_fd_value)  ||
            std::regex_match(line, result, empty_line)           ||
            std::regex_match(line, result, comment))
            read_value.push_back(result);
        else
            throw LexerError();
        if (line == ";;")
            break;
    }
}


void
Lexer::read_from_file() {
    for(int i = 1; i <= ac_ - 1; ++i) {
//        if (!chech_for_validity(av_[i]))
//            continue ;
        std::ifstream ifs(av_[i]);
        while (std::getline(ifs, line)) {
            if (std::regex_match(line, result, instr_with_no_value)  ||
                std::regex_match(line, result, instr_with_int_value) ||
                std::regex_match(line, result, instr_with_fd_value)  ||
                std::regex_match(line, result, empty_line)           ||
                std::regex_match(line, result, comment))
                read_value.push_back(result);
            else{
                std::cout << line << std::endl;
                throw LexerError();
            }
            if (line == "exit")
                break;
        }
        ifs.close();
    }
}

//void
//Lexer::regular_ex_match(std::string line) {
//    if (std::regex_match(line, result, instr_with_no_value)  ||
//        std::regex_match(line, result, instr_with_int_value) ||
//        std::regex_match(line, result, instr_with_fd_value)  ||
//        std::regex_match(line, result, empty_line)           ||
//        std::regex_match(line, result, comment))
//        read_value.push_back(result);
//    else{
//        std::cout << line << std::endl;
//        throw LexerError();
//    }
//}
std::vector<std::smatch>
Lexer::getReadValue() {
    return read_value;
}


//bool
//Lexer::check_for_validity(char *path) {
//    struct stat s;
//
//    if(stat(path, &s) == 0) {
//        if(s.st_mode & S_IFDIR)
//            return false;
//        else if (!(s.st_mode & S_IROTH) & !(s.st_mode & S_IRGRP) & !(s.st_mode & S_IRUSR))
//            return false;
//        else if(s.st_mode & S_IFREG)
//            return true;
//    }
//    return false;
//}

//    for(auto & v: read_value) {
//        std::cout << "\\" << std::endl;
//        for (auto &m : v)
//            std::cout <<" | "<< v[0] << std::endl;
//    }
//            for (auto &str : read_value.back())
//                std::cout <<"el: "<< str << std::endl;

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
    av_=NULL;
}

std::vector<std::smatch>
Lexer::getReadValue() {
//    for(auto & value: read_value) {
//        for (std::smatch::iterator it = value.begin(); it!=value.end(); ++it) {
//            std::cout << *it << std::endl;
//        }
//    }
    return read_value;
}
//            for (auto &str : read_value.back())
//                std::cout <<"el: "<< str << std::endl;

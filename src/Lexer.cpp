/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:52:22 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:52:29 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Exception.hpp>
#include "../inc/Lexer.hpp"

Lexer::Lexer(int ac, char **av):ac_(ac), av_(av) {
    instr_with_no_value = (R"(^(pop|dump|add|sub|mul|div|mod|print|exit)(\s*[;].*)*)");
    instr_with_int_value = (R"(^(push|assert)\s+(int8|int16|int32)(\()([\-]?\d+)(\))(\s*[;].*)*)");
    instr_with_fd_value = (R"(^(push|assert)\s+(float|double)(\()([\-]?\d+\.\d+)(\))(\s*[;].*)*)");
    comment = (R"(\s*[;].*)");
    empty_line = (R"(^$)");
    reader.push_back(&Lexer::read_from_st_input);    // at(0)
    reader.push_back(&Lexer::read_from_file);    // at(1)
}

Lexer::~Lexer() = default;

void
Lexer::run() {
    return !(ac_ - 1) ? (this->*reader.at(0))() : (this->*reader.at(1))();
}

bool
Lexer::regular_ex_match(std::string line) {
    if (std::regex_match(line, result,  instr_with_no_value) ||
        std::regex_match(line, result, instr_with_int_value) ||
        std::regex_match(line, result, instr_with_fd_value)  ||
        std::regex_match(line, result, empty_line)           ||
        std::regex_match(line, result, comment)) {
        std::map<std::string, std::string> map;
        map["cmd"] = result[1];
        map["type"] = result[2];
        map["value"] = result[4];
        read_value.push_back(map);
    }
    else
        return false;
    return true;
}

void
Lexer::read_from_st_input() {
    while (std::getline(std::cin, line)){
        if (!regular_ex_match(line))
            throw LexerError("Error: " + line);
        if (line == ";;")
            break;
    }
}

void
Lexer::read_from_file() {
        for(int i = 1; i <= ac_ - 1; ++i) {
        if (!check_file_access(av_[i])) {
            std::cerr << "Error: " << av_[i] << " has bad access" << std::endl;
            continue ;
        }
        std::ifstream ifs(av_[i]);
        while (std::getline(ifs, line)) {
            if (!regular_ex_match(line))
                throw LexerError(line);
            if (line == "exit")
                break;
        }
        ifs.close();
    }
}

bool
Lexer::check_file_access(char *path) {
    return (!access(path, 0) && !access(path, 04));
}

std::vector<std::map<std::string, std::string>>
Lexer::getReadValue() {
    return read_value;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:52:56 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:53:06 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Lexer.hpp"
#include "../inc/Operand.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Executor.hpp"

int main(int ac, char **av) {
    try {
        Lexer lexer(ac, av);
        lexer.run();
        std::vector<std::map<std::string, std::string>> result = lexer.getReadValue();

        Parser parser;
        parser.run(result);

        Executor executor;
        executor.run(result);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


}

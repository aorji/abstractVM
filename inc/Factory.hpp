/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:53:32 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:53:38 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "IOperand.hpp"
#include <string>
#include <cstdint>

class Factory {

public:
    Factory();
    Factory( Factory const & src );
    ~Factory();

    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    Factory & operator=( Factory const & rhs);

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

    std::vector<IOperand const* (Factory::*)( std::string const & ) const> creator;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 10:52:06 by aorji             #+#    #+#             */
/*   Updated: 2018/12/24 10:52:14 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Factory.hpp"
#include "../inc/Operand.hpp"

Factory::Factory() {
    creator.push_back(&Factory::createInt8);    //type 0
    creator.push_back(&Factory::createInt16);   //type 1
    creator.push_back(&Factory::createInt32);   //type 2
    creator.push_back(&Factory::createFloat);   //type 3
    creator.push_back(&Factory::createDouble);  //type 4
}

Factory::Factory ( Factory const & src ) { *this = src; }

Factory::~Factory() = default;

IOperand const * 
Factory::createOperand( eOperandType type, std::string const & value ) const {
    return (this->*creator.at(type))(value);
}

IOperand const *
Factory::createInt8( std::string const & value ) const { return new Operand<signed char>(value); }

IOperand const * 
Factory::createInt16( std::string const & value ) const { return new Operand<short>(value); }

IOperand const * 
Factory::createInt32( std::string const & value ) const { return new Operand<int>(value); }

IOperand const * 
Factory::createFloat( std::string const & value ) const { return new Operand<float>(value); }

IOperand const * 
Factory::createDouble( std::string const & value ) const { return new Operand<double>(value); }

Factory &
Factory::operator=( Factory const & rhs) {
    (void)rhs;
    return *this;
}
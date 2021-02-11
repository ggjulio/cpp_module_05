/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:57 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/11 13:02:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>

Form::Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec)
	: _name(name), _minGradeToExec(minimumGradeToExec),
	_minGradeToSign(minimumGradeToSign), _isSigned(false)
{
	validate(minimumGradeToSign);
	validate(minimumGradeToExec);
}
Form::Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec)
	: _name(name), _minGradeToExec(minimumGradeToExec),
	_minGradeToSign(minimumGradeToSign), _isSigned(false)
{
	
}
Form & Form::operator=(const Form &){}
Form::~Form(){}


std::string	Form::getName(){ return _name;}
bool 		Form::getIsSigned(){ return _isSigned;}
int			Form::getMinGradeToSign(){ return _minGradeToSign;}
int			Form::getMinGradeToExec(){ return _minGradeToExec;}

void	Form::validate(int grade){
	if (grade < 1)
		throw (::GradeTooHighException("fe"));	
	else if (grade > 150)
		throw GradeTooLowException;
	// _minGradeToSign = grade;
}
Form::GradeTooLowException::GradeTooLowException(const std::string & name){
	std::cerr << name ;
}

const char* Form::GradeTooLowException::what(const std::string & name) const throw(){
	return "Grade too Low ! This is so low...";
}

const char* Form::GradeTooHighException::what(const std::string & name) const throw(){
	return "Grade too high ! There is nothing higher than our boss ! Not even God.";
}


std::ostream & operator<<(std::ostream &os, const Form & f){
	os << f.ge;
	return os;
}

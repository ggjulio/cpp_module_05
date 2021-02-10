/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:57 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/10 20:28:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec)
	: _name(name), _minGradeToExec(minimumGradeToExec),
	_minGradeToSign(minimumGradeToSign), _isSigned(false)
{
	Validate(minimumGradeToSign);
	setminGradeToSign(minimumGradeToExec);
}
Form::Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec)
	: _name(name), _minGradeToExec(minimumGradeToExec),
	_minGradeToSign(minimumGradeToSign), _isSigned(false)
{
	
}
Form & Form::operator=(const Form &){}
Form::~Form(){}


bool 	Form::getName(){ return _name;}
bool 	Form::getIsSigned(){ return _isSigned;}
int		Form::getMinGradeToSign(){ return _minGradeToSign;}
int		Form::getMinGradeToExec(){ return _minGradeToExec;}

void	Form::Validate(int grade){
	if (grade < 1)
		throw Form::GradeTooHighException("fe");	
	else if (grade > 150)
		throw Form::GradeTooLowException("fwfw");
	// _minGradeToSign = grade;
}
void	Form::setminGradeToExec(int grade){
	
	if (grade < 1)
		throw Form::GradeTooHighException();	
	else if (grade > 150)
		throw Form::GradeTooLowException();
	// _minGradeToExec = grade;
}

const char* Form::GradeTooLowException::what(std::string std::string const &) const throw(){
	return "Grade too Low ! This is so low...";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high ! There is nothing higher than our boss ! Not even God.";
}


std::ostream & operator<<(std::ostream &os, const Form & f){
	os << f.ge;
	return os;
}

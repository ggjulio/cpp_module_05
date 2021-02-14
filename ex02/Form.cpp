/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:57 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 04:08:43 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

bool Form::_seeded = false;

Form::Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec)
: _name(name), _target(""), _minGradeToSign(minimumGradeToSign),
	_minGradeToExec(minimumGradeToExec), _isSigned(false)
{
	validateGrade(minimumGradeToSign);
	validateGrade(minimumGradeToExec);
	if (_seeded == false)
	{
	    srand(time(0));
		_seeded = true;
	}
}

Form::Form(const std::string & name, const std::string & target,
			int minimumGradeToSign, int minimumGradeToExec)
: _name(name), _target(target), _minGradeToSign(minimumGradeToSign),
	_minGradeToExec(minimumGradeToExec), _isSigned(false)
{
	validateGrade(minimumGradeToSign);
	validateGrade(minimumGradeToExec);
	if (_seeded == false)
	{
	    srand(time(0));
		_seeded = true;
	}
}
Form::Form(const Form & other)
	: _name(other._name), _minGradeToSign(other._minGradeToSign),
	_minGradeToExec(other._minGradeToExec), _isSigned(other._isSigned) {}

Form::~Form(){}


std::string const & 	Form::getName() const{ return _name;}
std::string const & 	Form::getTarget() const{ return _target;}
bool 		Form::getIsSigned() const{ return _isSigned;}
int			Form::getMinGradeToSign() const{ return _minGradeToSign;}
int			Form::getMinGradeToExec() const{ return _minGradeToExec;}

void	Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() > _minGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	Form::validateGrade(int grade) const{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}
void	Form::validateExecution(const Bureaucrat &b) const{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	if (b.getGrade() > getMinGradeToExec())
		throw GradeTooLowException();
}


const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too Low !";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high !";
}

const char* Form::FormNotSignedException::what() const throw(){
	return "Form Not Signed !";
}

std::ostream & operator<<(std::ostream &os, const Form & form){
	os << "<FORM> name:" << form.getName() 
		<< " minGradeToSign:" << form.getMinGradeToSign()
		<< " minGradeToExec:" << form.getMinGradeToExec()
		<< " isSigned:" << form.getIsSigned();
	return os;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:57 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 00:53:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>

Form::Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec)
	: _name(name), _minGradeToSign(minimumGradeToSign),
	_minGradeToExec(minimumGradeToExec), _isSigned(false)
{
	validate(minimumGradeToSign);
	validate(minimumGradeToExec);
}
Form::Form(const Form & other)
	: _name(other._name), _minGradeToSign(other._minGradeToSign),
	_minGradeToExec(other._minGradeToExec), _isSigned(other._isSigned) {}

Form::~Form(){}


std::string const & 	Form::getName() const{ return _name;}
bool 		Form::getIsSigned() const{ return _isSigned;}
int			Form::getMinGradeToSign() const{ return _minGradeToSign;}
int			Form::getMinGradeToExec() const{ return _minGradeToExec;}

void	Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= _minGradeToSign)
	{
		_isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

void	Form::validate(int grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too Low !";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high !";
}



std::ostream & operator<<(std::ostream &os, const Form & form){
	os << "<FORM> name:" << form.getName() 
		<< " minGradeToSign:" << form.getMinGradeToSign()
		<< " minGradeToExec:" << form.getMinGradeToExec()
		<< " isSigned:" << form.getIsSigned();
	return os;
}

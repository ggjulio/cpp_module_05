/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:47 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 00:37:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string & name, int grade): _name(name)
{
	setGrade(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	setGrade(other._grade);
}

Bureaucrat::~Bureaucrat(){}

std::string const &	Bureaucrat::getName() const { return _name;}
int				Bureaucrat::getGrade() const{ return _grade;}

void			Bureaucrat::setGrade(int grade){
	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();	
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void			Bureaucrat::incrementGrade(){
	setGrade(_grade-1);
}
void			Bureaucrat::decrementGrade(){
	setGrade(_grade+1);
}
void	Bureaucrat::signForm(Form &form){
	form.beSigned(*this);
}



std::ostream & operator<<(std::ostream &os, const Bureaucrat & b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade(); 
	return os;
}


const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too Low ! This is so low...";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high ! There is nothing higher than our boss ! Not even God.";
}

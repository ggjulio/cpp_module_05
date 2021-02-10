/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:47 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/10 09:29:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string & name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();	
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();	
}
Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other){
	_name = other._name;
	_grade = other._grade;
	return *this;
}
Bureaucrat::~Bureaucrat(){}

std::string const &	Bureaucrat::getName() const { return _name;}
int				Bureaucrat::getGrade() const{ return _grade;}

void			Bureaucrat::incrementGrade(){
	_grade--;	
}
void			Bureaucrat::decrementGrade(){
	_grade++;
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade(); 
	return os;
}

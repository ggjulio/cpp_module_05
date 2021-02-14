/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:21:35 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 17:35:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	
	Intern();
	Intern(const Intern &);
	Intern & operator=(const Intern &);
	~Intern();


	template<class T>
	Form* create(const std::string & target){
		return new T(target);
	};

	Form * makeForm(const std::string &, const std::string &target);
	
};

#endif

// #######################################################

// #include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern &other){
	*this = other;
}
Intern & Intern::operator=(const Intern &other){
	(void)other;
	return *this;
}
Intern::~Intern(){}

Form * Intern::makeForm(const std::string &name, const std::string &target){
	const char *forms[]
		= {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form* (Intern::*funcs[])(const std::string &)
		= {	&Intern::create<RobotomyRequestForm>,
			&Intern::create<RobotomyRequestForm>,
			&Intern::create<ShrubberyCreationForm>};

	for (size_t i = 0; i < 3; i++)
		if (name.compare(forms[i]) == 0)
			return (this->*funcs[i])(target);
	return (NULL);
}
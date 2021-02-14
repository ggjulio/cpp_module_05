/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:57:06 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 17:57:12 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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
			&Intern::create<PresidentialPardonForm>,
			&Intern::create<ShrubberyCreationForm>};

	for (size_t i = 0; i < 3; i++)
		if (name.compare(forms[i]) == 0)
			return (this->*funcs[i])(target);
	return (NULL);
}
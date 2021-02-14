/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:40:39 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 02:10:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
	: Form(name, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: Form(other.getName(),other.getMinGradeToSign(), other.getMinGradeToExec()) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const{
	if (b.getGrade() > getMinGradeToExec())
	{
		throw GradeTooLowException();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:40:39 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 04:26:21 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("PresidentialPardonForm", target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: Form(other.getName(),other.getTarget(), other.getMinGradeToSign(), other.getMinGradeToExec()) {}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(const Bureaucrat &b) const{
	validateExecution(b);
	std::cout << getTarget()
		<< " has been pardoned by zafod Beeblebrox." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:40:39 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 04:24:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("RobotomyRequestForm", target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: Form(other.getName(),other.getTarget(), other.getMinGradeToSign(), other.getMinGradeToExec()) {}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(const Bureaucrat &b) const{
	validateExecution(b);
  	if (rand() % 2)
    	std::cout << "* Brrrriii splash BrhhhiiaAAA BRRRRR * "
			<< getTarget() << " has been robotomized successfully" << std::endl;
  	else
    	std::cout << "Failed to robotomize "<< getTarget() << std::endl;
}

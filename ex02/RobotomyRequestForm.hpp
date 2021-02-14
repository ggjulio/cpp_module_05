/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:08:29 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 03:17:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"
#include  "Bureaucrat.hpp"

class RobotomyRequestForm: public Form
{
private:
	RobotomyRequestForm();
	RobotomyRequestForm & operator=(const RobotomyRequestForm &);
public:
	RobotomyRequestForm(const std::string &);
	RobotomyRequestForm(const RobotomyRequestForm &);
	~RobotomyRequestForm();
	
	virtual void execute(const Bureaucrat &) const;
};

#endif


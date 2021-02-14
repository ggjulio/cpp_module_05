/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:08:29 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 01:48:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include "Form.hpp"
#include  "Bureaucrat.hpp"

class ShrubberyCreationForm: public Form
{
private:
	
	ShrubberyCreationForm();
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm &);
public:
	ShrubberyCreationForm(const std::string &);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
	
	virtual void execute(const Bureaucrat &) const;
};

#endif


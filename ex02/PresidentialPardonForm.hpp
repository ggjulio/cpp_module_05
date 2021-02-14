/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:08:29 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 04:22:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "Form.hpp"
#include  "Bureaucrat.hpp"

class PresidentialPardonForm: public Form
{
private:
	PresidentialPardonForm();
	PresidentialPardonForm & operator=(const PresidentialPardonForm &);
public:
	PresidentialPardonForm(const std::string &);
	PresidentialPardonForm(const PresidentialPardonForm &);
	~PresidentialPardonForm();
	
	virtual void execute(const Bureaucrat &) const;
};

#endif


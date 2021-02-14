/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 05:21:35 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 17:57:01 by juligonz         ###   ########.fr       */
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

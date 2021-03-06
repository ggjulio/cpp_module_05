/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:54 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 02:12:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <exception>
#include <ostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const _name;
	int const _minGradeToSign;
	int const _minGradeToExec;
	bool _isSigned;

	Form();
	Form & operator=(const Form &);
public:
	Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec);
	Form(const Form &);
	~Form();

	std::string const & getName() const;
	int		getMinGradeToSign() const;
	int		getMinGradeToExec() const;
	bool 	getIsSigned() const;

	void	beSigned(const Bureaucrat &);
	void	validate(int grade);

	
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooHighException: public std::exception {		
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream &os, const Form & f);

#endif

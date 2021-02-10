/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:54 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/10 19:19:21 by juligonz         ###   ########.fr       */
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

	bool 	getIsSigned();
	int		getMinGradeToSign();
	int		getMinGradeToExec();
	void	setminGradeToSign(int grade);
	void	setminGradeToExec(int grade);

	void	beSigned(const Bureaucrat &);
	
	class GradeTooLowException: public std::exception {
		virtual const char* what(const std::string & name) const throw();
	};
	class GradeTooHighException: public std::exception {
		virtual const char* what()const std::string & name const throw();
	};
};

std::ostream & operator<<(std::ostream &os, const Form & f);

#endif

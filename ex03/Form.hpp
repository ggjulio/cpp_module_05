/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:52:54 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 04:06:09 by juligonz         ###   ########.fr       */
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
	std::string const _target;
	int const _minGradeToSign;
	int const _minGradeToExec;
	bool _isSigned;


	static bool _seeded;
	Form();
	Form & operator=(const Form &);
public:
	Form(const std::string & name, int minimumGradeToSign, int minimumGradeToExec);
	Form(const std::string & name, const std::string &target, int minimumGradeToSign, int minimumGradeToExec);
	Form(const Form &);
	virtual ~Form();

	std::string const & getName() const;
	std::string const & getTarget() const;
	int		getMinGradeToSign() const;
	int		getMinGradeToExec() const;
	bool 	getIsSigned() const;

	void	beSigned(const Bureaucrat &);

	void	validateGrade(int grade) const;
	void	validateExecution(const Bureaucrat &) const;

	virtual void execute(const Bureaucrat &) const = 0;
	
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
	
	class FormNotSignedException: public std::exception {		
		virtual const char* what() const throw();
	};
	
	class GradeTooHighException: public std::exception {		
		virtual const char* what() const throw();
	};
	
};

std::ostream & operator<<(std::ostream &os, const Form & f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:51 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/11 11:19:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <exception>
#include <string>
#include <ostream>

class Form;

class Bureaucrat
{
private:
	const std::string  _name;
	int _grade;
	
	Bureaucrat();
	Bureaucrat & operator=(const Bureaucrat &);
public:
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();

	std::string const &	getName() const;
	int		getGrade() const;
	void	setGrade(int grade);
	
	void	incrementGrade();
	void	decrementGrade();

	void	signForm();


	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &b);

#endif

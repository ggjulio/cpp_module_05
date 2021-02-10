/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:51 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/10 09:26:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <exception>
#include <string>
#include <ostream>


class Bureaucrat
{
private:
	// std::string const _name;
	std::string _name;
	int _grade;
	
	Bureaucrat();
public:
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat &);
	Bureaucrat & operator=(const Bureaucrat &);
	~Bureaucrat();

	std::string const &	getName() const;
	int				getGrade() const;
	
	void			incrementGrade();
	void			decrementGrade();

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw(){
			return "Something bad happened!";
		}
	};
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw(){
			return "Something bad happened!";
		}
	};
};

std::ostream & operator<<(const std::ostream &os, const Bureaucrat &b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:51 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/09 03:52:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <exception>
#include <string>

class GrageTooLowException: public std::exception {
	virtual const char* what() const throw(){
		return "Something bad happened!";
	}
};

class Bureaucrat
{
private:
	std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat & operator=(const Bureaucrat &);
	~Bureaucrat();

	std::string &	getName() const;
	int				getGrade() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:53 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/13 22:42:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "################  Test instanciation error too high ############" << std::endl;
	try{
		Bureaucrat b = Bureaucrat("Pierre Boss", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "################  Test instanciation error too low ############" << std::endl;
	try{
		Bureaucrat c = Bureaucrat("Pierre", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "################  Test increment" << std::endl;
	try
	{
		Bureaucrat b = Bureaucrat("Pierre", 5);
		while (true)
		{	
			b.incrementGrade();
			std::cout << b << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "################  Test decrement" << std::endl;
	try
	{
		Bureaucrat b = Bureaucrat("Pierre", 146);
		while (true)
		{	
			b.decrementGrade();
			std::cout << b << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "################ Test copy ctor" << std::endl;
		Bureaucrat b = Bureaucrat("Pierre", 145);
		Bureaucrat c(b);
		std::cout << b << std::endl;
		std::cout << c << std::endl;
}
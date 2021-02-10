/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:53 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/10 10:47:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "################  Instanciation tests error too high ############" << std::endl;
	try{
		Bureaucrat b = Bureaucrat("Pierre Boss", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "################  Instanciation tests error too low ############" << std::endl;
	try{
		Bureaucrat c = Bureaucrat("Pierre", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "################  Instanciation test increment" << std::endl;
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
	std::cout << "################  Instanciation test decrement" << std::endl;
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
	std::cout << "################ test copy ctor" << std::endl;
		Bureaucrat b = Bureaucrat("Pierre", 145);
		Bureaucrat c(b);
		std::cout << b << std::endl;
		std::cout << c << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:53 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 02:07:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	{
		Bureaucrat b = Bureaucrat("Pierre", 145);
		Bureaucrat c(b);
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl	<< "##################################" << std::endl
							<< "#############  ex01  #############" << std::endl
							<< "##################################" << std::endl;
	std::cout << "################  Test Grade limits Sign ############" << std::endl;
		try{Form f = Form("MyForm", 0, 5);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
		try{Form f = Form("MyForm", 151, 5);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
		try{Form f = Form("MyForm", 150, 5);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
		try{Form f = Form("MyForm", 1, 5);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
	std::cout << "################  Test Grade limits Exec ############" << std::endl;
		try{Form f = Form("MyForm", 5, 0);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
		try{Form f = Form("MyForm", 5, 151);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
		try{Form f = Form("MyForm", 5, 1);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
		try{Form f = Form("MyForm", 5, 150);} catch (std::exception &e)	{std::cout << e.what() << std::endl;}
	std::cout << "################  Test SignForm: too low ############" << std::endl;
	{
		Form f = Form("MyForm", 10, 5);
		Bureaucrat b = Bureaucrat("Pierre", 12);
		try{
			std::cout << f << std::endl;			
			b.signForm(f);
			std::cout << b.getName() << " has signed form \"" << f.getName() << "\"." << std::endl; 
		}
		catch (std::exception &e)
		{
			std::cout << b.getName()
				<< " can't sign \"" << f.getName() << "\". |actual grade:" << b.getGrade()
				<< " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;
		}
		std::cout << f << std::endl;			
	}
	std::cout << "################  Test SignForm: Ok ############" << std::endl;
	{
		Form f = Form("MyForm", 10, 5);
		Bureaucrat b = Bureaucrat("Pierre", 10);
		try{
			std::cout << f << std::endl;			
			b.signForm(f);
			std::cout << b.getName() << " has signed form \"" << f.getName() << "\"." << std::endl; 
		}
		catch (std::exception &e)
		{
			std::cout << b.getName()
				<< " can't sign \"" << f.getName() << "\". |actual grade:" << b.getGrade()
				<< " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;
		}
		std::cout << f << std::endl;			
	}

	std::cout << std::endl	<< "##################################" << std::endl
							<< "#############  ex02  #############" << std::endl
							<< "##################################" << std::endl;
	std::cout << "################  Test Shruberry ############" << std::endl;
}
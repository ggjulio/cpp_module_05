/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:53 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 04:19:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "################  Test Shrubbery  ############" << std::endl;
	{
		ShrubberyCreationForm f = ShrubberyCreationForm("Home");
		Bureaucrat s = Bureaucrat("Stagiaire", 146);
		Bureaucrat p = Bureaucrat("Pierre", 145);
		Bureaucrat cro = Bureaucrat("CRO", 138);
		Bureaucrat ceo = Bureaucrat("CEO", 137);
		std::cout << f << std::endl << std::endl;			
			try{f.execute(ceo);	std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (Form::FormNotSignedException &e){std::cout << ceo.getName() << " can't execute it ! Form \"" << f.getName() << "\" not signed !  |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{s.signForm(f); std::cout << s.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;}
			catch (std::exception &e){std::cout << s.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << s.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{p.signForm(f); std::cout << p.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;}
			catch (std::exception &e){std::cout << p.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << p.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{f.execute(cro);	std::cout << cro.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (std::exception &e){std::cout << cro.getName() << " can't execute it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{f.execute(ceo);	std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (std::exception &e){std::cout << ceo.getName() << " can't execute it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
	}
	std::cout << std::endl	<< "########################################################" << std::endl;
	std::cout 	<< "################  Test RobotomyRequestForm  ############" << std::endl;
	{
		RobotomyRequestForm f = RobotomyRequestForm("Home");
		Bureaucrat s = Bureaucrat("Stagiaire", 73);
		Bureaucrat p = Bureaucrat("Pierre", 72);
		Bureaucrat cro = Bureaucrat("CRO", 46);
		Bureaucrat ceo = Bureaucrat("CEO", 45);
		std::cout << f << std::endl << std::endl;			
			try{f.execute(ceo);	std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (Form::FormNotSignedException &e){std::cout << ceo.getName() << " can't execute it ! Form \"" << f.getName() << "\" not signed !  |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{s.signForm(f); std::cout << s.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;}
			catch (std::exception &e){std::cout << s.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << s.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{p.signForm(f); std::cout << p.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;}
			catch (std::exception &e){std::cout << p.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << p.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{f.execute(cro);	std::cout << cro.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (std::exception &e){std::cout << cro.getName() << " can't execute it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{f.execute(ceo);	std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (std::exception &e){std::cout << ceo.getName() << " can't execute it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
	}
	std::cout << std::endl	<< "########################################################" << std::endl;
	std::cout 	<< "################  Test Presidentia;PardonForm  ############" << std::endl;
	{
		RobotomyRequestForm f = RobotomyRequestForm("Home");
		Bureaucrat s = Bureaucrat("Stagiaire", 26);
		Bureaucrat p = Bureaucrat("Pierre", 25);
		Bureaucrat cro = Bureaucrat("CRO", 6);
		Bureaucrat ceo = Bureaucrat("CEO", 5);
		std::cout << f << std::endl << std::endl;			
			try{f.execute(ceo);	std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (Form::FormNotSignedException &e){std::cout << ceo.getName() << " can't execute it ! Form \"" << f.getName() << "\" not signed !  |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{s.signForm(f); std::cout << s.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;}
			catch (std::exception &e){std::cout << s.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << s.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{p.signForm(f); std::cout << p.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;}
			catch (std::exception &e){std::cout << p.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << p.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{f.execute(cro);	std::cout << cro.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (std::exception &e){std::cout << cro.getName() << " can't execute it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
		std::cout << "--------------------" << std::endl;		
			try{f.execute(ceo);	std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
			catch (std::exception &e){std::cout << ceo.getName() << " can't execute it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;}
	}
}
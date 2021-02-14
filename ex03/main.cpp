/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:06:53 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 05:35:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void testForm(Form &f, Bureaucrat &s, Bureaucrat &p, Bureaucrat &cro, Bureaucrat &ceo)
{
	std::cout << f << std::endl << std::endl;			
		try{
			ceo.executeForm(f);
			std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;
		}
		catch (Form::FormNotSignedException &e){
			std::cout << ceo.getName() << " can't execute it ! Form \"" << f.getName() << "\" not signed !  |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;
		}
	std::cout << "--------------------" << std::endl;		
		try{
			s.signForm(f);
			std::cout << s.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;
		}
		catch (std::exception &e){
			std::cout << s.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << s.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;
		}
	std::cout << "--------------------" << std::endl;		
		try{
			p.signForm(f);
			std::cout << p.getName() << " has signed form \"" << f.getName() << "\"." << std::endl;
		}
		catch (std::exception &e){
			std::cout << p.getName() << " can't sign \"" << f.getName() << "\". |actual grade:" << p.getGrade() << " | minimum needed grade:" << f.getMinGradeToSign() << std::endl;
		}
	std::cout << "--------------------" << std::endl;		
		try{
			cro.executeForm(f);
			std::cout << cro.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;
		}
		catch (std::exception &e){
			std::cout << cro.getName() << " can't execute \"" << f.getName() << "\" ! Grade too low. |actual grade:" << cro.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;
		}
	std::cout << "--------------------" << std::endl;		
		try{
			ceo.executeForm(f);
			std::cout << ceo.getName() << " executed it ! \"" << f.getName() << "\". |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;
		}
		catch (std::exception &e){
			std::cout << ceo.getName() << " can't execute \"" << f.getName() << "\" ! |actual grade:" << ceo.getGrade() << " | minimum needed grade:" << f.getMinGradeToExec() << std::endl;
		}

}

int main()
{
	Intern  someRandomIntern;
	Form*   rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl	<< "########################################################" << std::endl;
	std::cout 	<< "################  Test RobotomyRequestForm  ############" << std::endl;
	{
		Bureaucrat s = Bureaucrat("Stagiaire", 73);
		Bureaucrat p = Bureaucrat("Pierre", 72);
		Bureaucrat cro = Bureaucrat("CRO", 46);
		Bureaucrat ceo = Bureaucrat("CEO", 45);
		
		testForm(*rrf, s, p, cro, ceo);
	}

	delete rrf;
}
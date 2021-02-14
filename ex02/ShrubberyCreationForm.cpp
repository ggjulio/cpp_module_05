/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:40:39 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/14 03:14:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form("ShruberryForm", target,  145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: Form(other.getName(),other.getTarget(), other.getMinGradeToSign(), other.getMinGradeToExec()) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const{
	validateExecution(b);
	std::ofstream file;
	file.open((getTarget() + "_shrubbery").c_str());
	file <<	"The Worm's Turn\n\
\n\
             _{\\ _{\\{\\/}/}/}__\n\
            {/{/\\}{/{/\\}(\\}{/\\} _\n\
           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n\
        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n\
       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n\
      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n\
     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n\
     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n\
    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n\
     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n\
      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n\
     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n\
      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n\
        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n\
         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n\
           {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n\
            {/{\\{\\{\\/}/}{\\{\\}/}\n\
             {){/ {\\/}{\\/} \\}\\}\n\
             (_)  \\.-'.-/\n\
         __...--- |'-.-'| --...__\n\
  _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n\
-\"    ' .  . '    |.'-._| '  . .  '   jro\n\
.  '-  '    .--'  | '-.'|    .  '  . '\n\
         ' ..     |'-_.-|\n\
 .  '  .       _.-|-._ -|-._  .  '  .\n\
             .'   |'- .-|   '.\n\
 ..-'   ' .  '.   `-._.-´   .'  '  - .\n\
  .-' '        '-._______.-'     '  .\n\
       .      ~,\n\
   .       .   |\\   .    ' '-.\n\
   ___________/  \\____________\n\
  /  Why is it, when you want \\n\
 |  something, it is so damn   |\n\
 |    much work to get it?     |\n\
  \\___________________________/\n\
";
	file.close();
}

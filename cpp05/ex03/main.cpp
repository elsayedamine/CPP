/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:00:56 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/20 22:02:30 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        std::cout << "=== Bureaucrat creation ===" << std::endl;
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 149);
        Bureaucrat boss("Boss", 1);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << boss << std::endl;

        std::cout << "\n=== Form creation ===" << std::endl;
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n=== Signing forms ===" << std::endl;
        bob.signForm(shrub);     // too low
        alice.signForm(shrub);   // success

        bob.signForm(robo);      // fail
        boss.signForm(robo);     // success

        alice.signForm(pardon);  // fail
        boss.signForm(pardon);   // success

        std::cout << "\n=== Executing forms ===" << std::endl;
        try { alice.executeForm(shrub);} catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { boss.executeForm(robo); }  catch (std::exception& e) { std::cerr << e.what() << std::endl; }
        try { boss.executeForm(pardon);} catch (std::exception& e) { std::cerr << e.what() << std::endl; }

        std::cout << "\n=== Intern creating forms ===" << std::endl;
        Intern someRandomIntern;
        AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "backyard");
        AForm* f2 = someRandomIntern.makeForm("robotomy request", "HAL9000");
        AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        if (f1) { boss.signForm(*f1); boss.executeForm(*f1); delete f1; }
        if (f2) { boss.signForm(*f2); boss.executeForm(*f2); delete f2; }
        if (f3) { boss.signForm(*f3); boss.executeForm(*f3); delete f3; }

        std::cout << "\n=== Intern creating invalid form ===" << std::endl;
        AForm* f4 = someRandomIntern.makeForm("invalid nonsense", "Nobody");
        if (!f4)
            std::cout << "Intern couldn’t create that form.\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "Fatal exception: " << e.what() << std::endl;
    }

    return 0;
}

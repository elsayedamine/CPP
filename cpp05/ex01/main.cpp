/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:07:53 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/20 06:44:51 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 149);

        Form taxForm("TaxForm", 5, 10);
        std::cout << taxForm << std::endl;

        alice.signForm(taxForm); // should succeed
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);   // should fail
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        // Invalid form creation (grades out of bounds)
        Form invalidForm("InvalidForm", 0, 200);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating form: " << e.what() << std::endl;
    }

    return 0;
}

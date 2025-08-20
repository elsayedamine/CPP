/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 02:33:23 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 03:20:37 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl Gamball;

    std::cout << "=== Single calls ===\n";
    Gamball.complain("DEBUG");
    Gamball.complain("INFO");
    Gamball.complain("WARNING");
    Gamball.complain("ERROR");

    std::cout << "\n=== Repeated calls ===\n";
    Gamball.complain("DEBUG");
    Gamball.complain("DEBUG");
    Gamball.complain("INFO");
    Gamball.complain("INFO");

    std::cout << "\n=== Mixed sequence ===\n";
    std::string sequence[] = { "WARNING", "DEBUG", "ERROR", "INFO", "ERROR", "DEBUG" };
    for (int i = 0; i < 6; ++i)
        Gamball.complain(sequence[i]);

    std::cout << "\n=== Invalid levels ===\n";
    Gamball.complain("TRACE");
    Gamball.complain("CRITICAL");
    Gamball.complain("");

    std::cout << "\n=== Massive stress test ===\n";
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i < 20; ++i)
        Gamball.complain(levels[i % 4]);

    return 0;
}

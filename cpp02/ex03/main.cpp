/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:51:59 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 12:03:35 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

# define IN "Le point appartient au triangle ABC."
# define OUT "Le point n'appartient pas au triangle ABC."

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point A(0.0f, 0.0f);
    Point B(4.0f, 0.0f);
    Point C(2.0f, 3.0f);

    // 5 points inside
    Point P1(2.0f, 1.0f);
    Point P2(1.5f, 1.0f);
    Point P3(2.5f, 1.0f);
    Point P4(2.0f, 0.5f);
    Point P5(2.0f, 1.5f);

    // 2 points on vertices
    Point V1(0.0f, 0.0f);
    Point V2(4.0f, 0.0f);

    // 2 points on edges
    Point E1(2.0f, 0.0f);
    Point E2(3.0f, 1.5f);

    // 3 points outside
    Point O1(-1.0f, -1.0f);
    Point O2(5.0f, 0.0f);
    Point O3(2.0f, 4.0f);

    Point testPoints[] = {P1, P2, P3, P4, P5, V1, V2, E1, E2, O1, O2, O3};

    for (int i = 0; i < 12; i++)
    {
        if (bsp(A, B, C, testPoints[i]))
            std::cout << IN << std::endl;
        else
            std::cout << OUT << std::endl;
    }

    return 0;
}


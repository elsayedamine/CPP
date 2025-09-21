/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:16:31 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 00:16:33 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Serializer Test";
    data.value = 3.14;

    std::cout << "Original Data object:" << std::endl;
    std::cout << "  Address: " << &data << std::endl;
    std::cout << "  id: " << data.id << ", name: " << data.name << ", value: " << data.value << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\nSerialized uintptr_t: " << raw << std::endl;

    // Deserialize
    Data* restored = Serializer::deserialize(raw);
    std::cout << "\nDeserialized Data pointer:" << std::endl;
    std::cout << "  Address: " << restored << std::endl;
    std::cout << "  id: " << restored->id << ", name: " << restored->name << ", value: " << restored->value << std::endl;

    // Check equality
    if (restored == &data)
        std::cout << "\n✅ Success: The deserialized pointer matches the original." << std::endl;
    else
        std::cout << "\n❌ Failure: The deserialized pointer does not match." << std::endl;

    return 0;
}

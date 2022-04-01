#pragma once

#include <QString>
#include "GUI/models/generator.h"

namespace GoG {

    class RecursiveGenerator : public std::exception {
        virtual const char * what() const noexcept override {
            return "The generator is recursive!";
        };
    };

    /**
     * @brief Use generator to generate text
     *
     * @param generator    Generator to use
     * @param subgenerator Subgenerator to use.
     *                     Set to `NULL` (which is the default value) to use the main generator
     * @param depth        Recursion depth
     * @returns The generated string
     */
    QString Generate(GUI::Model::Generator* generator, GUI::Model::Subgenerator* subgenerator = NULL, unsigned int depth = 0);
}

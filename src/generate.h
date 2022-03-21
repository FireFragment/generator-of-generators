#pragma once

#include <QString>
#include "GUI/models/generator.h"

namespace GoG {

    /**
     * @brief Use generator to generate text
     *
     * @param generator    Generator to use
     * @param subgenerator Subgenerator to use.
     *                     Set to `NULL` (which is the default value) to use the main generator
     * @returns The generated string
     */
    QString Generate(GUI::Model::Generator* generator, GUI::Model::Subgenerator* subgenerator = NULL);
}

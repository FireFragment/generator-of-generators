#ifndef GOG_MODEL_GENERATORITEM_H
#define GOG_MODEL_GENERATORITEM_H

#include <variant>
#include "subgenerator.h"
#include "parent.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class GeneratorItem : Model::Parent
{
public:
    /**
     * @brief Type of Generator item
     *
     */
    enum Type {
        /**
         * @brief Concrete text entered by user
         */
        CustomText,
        /**
         * @brief Result of another subgenerator
         */
        SubgenInst
    };

    Type type();

    /**
     * @brief If type() is #CustomText, returns the value of the text
     *
     * Before calling, make sure the type is #CustomText, otherwise it results in undefined behavior.
     *
     * @return The text
     */
    std::string getCustomText();

    /**
     * @brief If type() is #SubgenInst, returns pointer to the subgenerator this is instance of
     *
     * Before calling, make sure the type is #SubgenInst, otherwise it results in undefined behavior.
     *
     * @return The pointer to the subgenerator this is instance of.
     */
    Subgenerator* getSbugenInst();
private:
    /**
     * @brief The own value of the Item
     *
     * | Holds          | Type of item          |
     * | -------------- | --------------------- |
     * | `std::string`  | Custom text           |
     * | `Subgenerator` | Subgenerator instance |
     */
    std::variant<std::string, Subgenerator*> value;
};

}

#endif // GOG_MODEL_GENERATORITEM_H

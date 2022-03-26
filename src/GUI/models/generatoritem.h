#ifndef GOG_MODEL_GENERATORITEM_H
#define GOG_MODEL_GENERATORITEM_H

#include <variant>
#include "parent.h"

namespace GoG::GUI::Model {

class Subgenerator;

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
    Model::Subgenerator* getSbugenInst();

    GeneratorItem(std::variant<std::string, Model::Subgenerator*> value = "") : value(value) {};
    GeneratorItem(std::string value) : value(value) {};
    void SetCustomText(std::string _value) { value = _value; };
    GeneratorItem(Model::Subgenerator* value) : value(value) {};
    void SetSubgenInst(Model::Subgenerator* _value) { value = _value; };

    void FromJSON(QJsonObject json) override;
private:
    /**
     * @brief The own value of the Item
     *
     * | Holds          | Type of item          |
     * | -------------- | --------------------- |
     * | `std::string`  | Custom text           |
     * | `Subgenerator` | Subgenerator instance |
     */
    std::variant<std::string, Model::Subgenerator*> value;
};

}

#endif // GOG_MODEL_GENERATORITEM_H

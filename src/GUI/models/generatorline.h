#ifndef MODEL_GENERATORLINE_H
#define MODEL_GENERATORLINE_H

#include "generatoritem.h"
#include "ptrvector.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class GeneratorLine : public Model::Parent
{
public:
    PtrVector<Model::GeneratorItem> items;

    GeneratorLine() {
        items << new Model::GeneratorItem;
    }

    void FromJSON(QJsonObject json) override;
    QJsonObject ToJSON() const override;
};

}

#endif // MODEL_GENERATORLINE_H

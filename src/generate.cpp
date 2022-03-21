#include "generate.h"
#include <QRandomGenerator>
#include "randomfromvec.h"

using namespace GoG;

QString GoG::Generate(GUI::Model::Generator* generator, GUI::Model::Subgenerator* subgenerator)
{
    // If subgenerator is NULL, set it to the main subgenerator.
    subgenerator = subgenerator == NULL ? &generator->mainGenerator : subgenerator;
    QString retVal = "";

    if (subgenerator->options.size() == 0)
        return "";
    for (auto item : RandomFromVec(subgenerator->options)->items) {

        if (item->type() == GUI::Model::GeneratorItem::Type::CustomText)
            retVal += QString::fromStdString(item->getCustomText());
        else
            retVal += Generate(generator, generator->subgenerators[item->getSbugenInst()]);
    };
    return retVal;
}


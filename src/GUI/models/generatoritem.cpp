#include "generatoritem.h"
#include "subgenerator.h"
#include "generator.h"

using namespace GoG::GUI;

GoG::GUI::Model::GeneratorItem::Type GoG::GUI::Model::GeneratorItem::type() const
{
    return std::holds_alternative<std::string>(value) ? CustomText : SubgenInst;
}

std::string GoG::GUI::Model::GeneratorItem::getCustomText() const
{
    return std::get<std::string>(value);
}

Model::Subgenerator* GoG::GUI::Model::GeneratorItem::getSbugenInst() const
{
    return std::get<Model::Subgenerator*>(value);
}

void GoG::GUI::Model::GeneratorItem::FromJSON(QJsonObject json, Generator* generator)
{
    if (json.value("type") == 0)
        SetCustomText(json.value("value").toString().toStdString());
    else
        SetSubgenInst(*std::find_if(generator->subgenerators.begin(), generator->subgenerators.end(), [json](const Subgenerator* subg) -> bool {
            return subg->name == json.value("value").toString();
        }));
}

QJsonObject GoG::GUI::Model::GeneratorItem::ToJSON() const
{
    QJsonObject retVal;

    switch (type()) {
        case CustomText:
            retVal.insert("value", QString::fromStdString(getCustomText()));
            retVal.insert("type", 0);
            break;
        case SubgenInst:
            retVal.insert("value", getSbugenInst()->name);
            retVal.insert("type", 1);
    }

    return retVal;
}


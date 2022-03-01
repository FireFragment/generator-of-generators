#include "generatoritem.h"

GoG::GUI::Model::GeneratorItem::Type GoG::GUI::Model::GeneratorItem::type()
{
    return std::holds_alternative<std::string>(value) ? CustomText : SubgenInst;
}

std::string GoG::GUI::Model::GeneratorItem::getCustomText()
{
    return std::get<std::string>(value);
}

GoG::GUI::Model::Subgenerator* GoG::GUI::Model::GeneratorItem::getSbugenInst()
{
    return std::get<Subgenerator*>(value);
}

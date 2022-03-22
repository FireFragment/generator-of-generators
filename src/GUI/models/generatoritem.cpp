#include "generatoritem.h"

using namespace GoG::GUI;

GoG::GUI::Model::GeneratorItem::Type GoG::GUI::Model::GeneratorItem::type()
{
    return std::holds_alternative<std::string>(value) ? CustomText : SubgenInst;
}

std::string GoG::GUI::Model::GeneratorItem::getCustomText()
{
    return std::get<std::string>(value);
}

Model::Subgenerator* GoG::GUI::Model::GeneratorItem::getSbugenInst()
{
    return std::get<Model::Subgenerator*>(value);
}

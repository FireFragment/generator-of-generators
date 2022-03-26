#include "generatorline.h"
#include <QJsonArray>

using namespace GoG::GUI::Model;

void GoG::GUI::Model::GeneratorLine::FromJSON(QJsonObject json)
{
}

QJsonObject GoG::GUI::Model::GeneratorLine::ToJSON() const
{
    QJsonObject retVal;
    QJsonArray itemsJSON;

    for (const auto item : items)
        itemsJSON << item->ToJSON();

    retVal.insert("items", itemsJSON);
    return retVal;
}



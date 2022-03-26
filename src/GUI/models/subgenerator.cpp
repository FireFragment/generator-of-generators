#include "subgenerator.h"
#include <QJsonArray>

void GoG::GUI::Model::Subgenerator::FromJSON(QJsonObject json)
{
}

QJsonObject GoG::GUI::Model::Subgenerator::ToJSON() const
{
    QJsonObject retVal;
    retVal.insert("name", name);

    QJsonArray optionsJSON;

    for (const auto option : options)
        optionsJSON << option->ToJSON();


    retVal.insert("opts", optionsJSON);

    return retVal;
}



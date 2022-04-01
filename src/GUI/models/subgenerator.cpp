#include "subgenerator.h"
#include <QJsonArray>

void GoG::GUI::Model::Subgenerator::FromJSON(QJsonObject json, Generator* parent)
{
    FromJSONEmpty(json);
    FromJSONContent(json, parent);
}

void GoG::GUI::Model::Subgenerator::FromJSONEmpty(QJsonObject json)
{
    name = json.value("name").toString();

    options = PtrVector<Model::GeneratorLine>();
}

void GoG::GUI::Model::Subgenerator::FromJSONContent(QJsonObject json, GoG::GUI::Model::Generator* parent)
{
    for (const auto lineJSON : json.value("opts").toArray()) {
        GeneratorLine* line = new GeneratorLine();
        line->FromJSON(lineJSON.toObject(), parent);
        options << line;
    }
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



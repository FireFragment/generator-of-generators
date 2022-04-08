#ifndef GOG_GUI_MODEL_GENERATOR_H
#define GOG_GUI_MODEL_GENERATOR_H

#include <QObject>
#include <QString>
#include <QJsonArray>
#include "parent.h"
#include "subgenerator.h"
#include <QString>
#include <QJsonDocument>
#include "ptrvector.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class Generator : public Model::Parent
{
    Q_OBJECT

public:
    PtrVector<Model::Subgenerator> subgenerators;
    /**
     * @brief The main generator
     *
     */
    Model::Subgenerator mainGenerator = QString("");

    QString GetShareLink() {
        return "file:///tmp/personal/web/index.html?generator=" + QUrl::toPercentEncoding(QJsonDocument(ToJSON()).toJson(QJsonDocument::Compact));
    }

    void FromJSON(QJsonObject json) {
        FromJSONEmpty(json);
        FromJSONContent(json);
    };

    /**
     * @brief Create generator from JSON, but leave items empty
     *
     * Does not create main generator
     *
     */
    void FromJSONEmpty(QJsonObject json) {
        subgenerators = PtrVector<Model::Subgenerator>();
        for (const auto subgenJSON : json.value("subgenerators").toArray()) {
            Subgenerator* subgen = new Subgenerator("");
            subgen->FromJSONEmpty(subgenJSON.toObject());
            subgenerators << subgen;
        }
    }

    void FromJSONContent(QJsonObject json) {
        QJsonArray subgensJSON = json.value("subgenerators").toArray();
        auto it = subgensJSON.begin();
        for (auto subgen: subgenerators) {
            subgen->FromJSONContent(it->toObject(), this);
            it++;
        }


        mainGenerator.FromJSON(json.value("main").toObject(), this);
    }

    QJsonObject ToJSON() const override {
        QJsonObject retVal;
        retVal.insert("main", mainGenerator.ToJSON());

        QJsonArray subgensJson;
        for (const auto subg : subgenerators)
            subgensJson << subg->ToJSON();
        retVal.insert("subgenerators", subgensJson);

        return retVal;
    };
};

}

#endif // GOG_GUI_MODEL_GENERATOR_H

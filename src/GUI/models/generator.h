#ifndef GOG_GUI_MODEL_GENERATOR_H
#define GOG_GUI_MODEL_GENERATOR_H

#include <QObject>
#include <QString>
#include "parent.h"
#include "subgenerator.h"
#include "ptrvector.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class Generator : public Model::Parent
{
    Q_OBJECT

public:
    QString name;
    PtrVector<Model::Subgenerator> subgenerators;
    /**
     * @brief The main generator
     *
     */
    Model::Subgenerator mainGenerator = QString("");

    Generator(QString name) : name(name) {};

    void FromJSON(QJsonObject json) override {};
};

}

#endif // GOG_GUI_MODEL_GENERATOR_H

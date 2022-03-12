#ifndef GOG_GUI_MODEL_SUBGENERATOR_H
#define GOG_GUI_MODEL_SUBGENERATOR_H

#include <QString>
#include <QObject>

#include "parent.h"
#include "generatorline.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class Subgenerator : public Model::Parent
{
public:
    QString name;
    PtrVector<Model::GeneratorLine> options;
    Subgenerator(QString name) : name(name) {}
};

}

#endif // GOG_GUI_MODEL_SUBGENERATOR_H

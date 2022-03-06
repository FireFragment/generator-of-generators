#ifndef GOG_GUI_MODEL_SUBGENERATOR_H
#define GOG_GUI_MODEL_SUBGENERATOR_H

#include <QString>
#include <QObject>

#include "parent.h"

namespace GoG::GUI::Model {

/**
 * @todo write docs
 */
class Subgenerator : public Model::Parent
{
public:
    QString name;
    Subgenerator(QString name) : name(name) {}
    Subgenerator(const Subgenerator& original) : name(original.name) {};
};

}

#endif // GOG_GUI_MODEL_SUBGENERATOR_H

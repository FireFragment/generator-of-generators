#ifndef GOG_GUI_MODELS_PARENT_H
#define GOG_GUI_MODELS_PARENT_H

#include <QObject>

namespace GoG::GUI::Model {

/**
 * @brief Parent for all models in Generator of generators
 */
class Parent : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief Call, when you changed any property to update all views
     *
     * Emits `Update` signal
     */
    void Changed() { emit Update(); };
signals:
    /**
     * @brief Emitted when some property changed.
     */
    void Update();

};

}

#endif // GOG_GUI_MODELS_PARENT_H

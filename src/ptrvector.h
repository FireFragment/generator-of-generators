#ifndef GOG_PTRVECTOR_H
#define GOG_PTRVECTOR_H

#include <QVector>

namespace GoG {

/**
 * \brief Vector of pointers.
 *
 * When copied, it copies also it's items
 * When deleted, deletes all items
 */
template<typename T>
class PtrVector :  public QVector<T*>
{
public:
    using QVector<T*>::QVector;

    /**
     * Copy constructor
     * Copies also all items
     */
    PtrVector(const PtrVector& other) {
        for (T* item : other) {
            append(item);
        }
    };

    /**
     * Destructor
     * Deletes all items
     */
    ~PtrVector() {
        QVectorIterator<T*> it(*this);

        while (it.hasNext())
            delete it.next();
    };

};

}

#endif // GOG_PTRVECTOR_H

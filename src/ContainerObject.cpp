#ifndef CONTAINER_CPP
#define CONTAINER_CPP

#include <vector>

#include "Component.cpp"

/* Contains a list of Components. Increments their connections
// when adding new components. Receives an event and sends it to
// all sub-components before processing it "personally".
*/
class ContainerObject : public Component {
    std::vector<Component *> components;

    void wipeComponents() {
        // just in case a component is referenced by another object, we
        // don't delete it immediately
        for (Component *cp : components) {
            cp->decrementConnections();
        }
    }

    void sendToComponents(Event *ev) {
        for (Component *cp : components) {
            cp->recieveEvent(ev);
        }
    }

    virtual void procEvent(Event * ev) {};

   public:
    void addComponent(Component *cp) {
        cp->incrementConnections();
        components.push_back(cp);
    }

    // don't override
    void recieveEvent(Event * ev) {
        sendToComponents(ev);
        procEvent(ev);
    }

    ~ContainerObject() { wipeComponents(); }
};

#endif
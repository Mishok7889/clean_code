#include <iostream>

#include "container.h"

class ServiceInterface {
public:
    virtual ~ServiceInterface() = default;
    virtual void doSomething() = 0;
};

class ServiceImpl : public ServiceInterface {
public:
    void doSomething() override {
        std::cout << "Service Implementation Doing Something" << std::endl;
    }
};

int main() {
    IoCContainer container;

    // Register types
    container.registerType<ServiceInterface, ServiceImpl>();

    // Resolve dependencies
    auto service = container.resolve<ServiceInterface>();
    service->doSomething();

    return 0;
}

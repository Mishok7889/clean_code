#pragma once
// IoCContainer.h
#pragma once
#include <memory>
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <stdexcept>

class IoCContainer {
public:
    template <typename Interface, typename Implementation>
    void registerType() {
        auto typeIndex = std::type_index(typeid(Interface));
        creators[typeIndex] = []() -> std::shared_ptr<void> {
            return std::make_shared<Implementation>();
            };
    }

    template <typename Interface>
    std::shared_ptr<Interface> resolve() {
        auto typeIndex = std::type_index(typeid(Interface));
        auto it = creators.find(typeIndex);
        if (it != creators.end()) {
            return std::static_pointer_cast<Interface>(it->second());
        }
        else {
            throw std::runtime_error("Type not registered.");
        }
    }

private:
    std::unordered_map<std::type_index, std::function<std::shared_ptr<void>()>> creators;
};

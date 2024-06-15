#pragma once
#include <string>

// Define a new service interface
class ServiceTestInterface {
public:
    virtual ~ServiceTestInterface() = default;
    virtual int calculate(int a, int b) = 0;
};

// Define a new service interface that performs an action
class ServiceTestImpl : public ServiceTestInterface {
public:
    virtual ~ServiceTestImpl() = default;
    virtual int calculate(int a, int b) { return a + b; };
};
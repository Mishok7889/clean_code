#include <gtest/gtest.h>
#include "../../IoC/service_test.hpp"
#include "../../IoC/container.h"



// Test to ensure AnotherServiceInterface can be registered and resolved
TEST(IoCContainerTest, RegisterAndResolveServiceTest) {
    IoCContainer container;
    container.registerType<ServiceTestInterface, ServiceTestImpl>();

    auto service = container.resolve<ServiceTestInterface>();
    ASSERT_NE(service, nullptr);
    ASSERT_EQ(service->calculate(2, 3), 5);
}

// Test to ensure different instances are created for AnotherServiceInterface
TEST(IoCContainerTest, ResolveServiceTestDifferentInstances) {
    IoCContainer container;
    container.registerType<ServiceTestInterface, ServiceTestImpl>();

    auto service1 = container.resolve<ServiceTestInterface>();
    auto service2 = container.resolve<ServiceTestInterface>();
    ASSERT_NE(service1, service2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
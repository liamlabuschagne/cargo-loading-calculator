cmake_minimum_required(VERSION 3.27.4)

set(This CargoLoadingCalculatorTests)

set(Sources
    CargoLoadingCalculatorTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    libCargoLoadingCalculator
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
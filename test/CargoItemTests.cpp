#include <gtest/gtest.h>
#include <memory>
#include "../src/CargoItem.cpp"

class CargoItemTest : public ::testing::Test {
 public:
    unsigned int id = 123123;
    float mass = 100;
    std::vector<float> dimensions = {1,1,1};
 protected:
  void SetUp() override { }
  void TearDown() override {}
};

TEST_F(CargoItemTest,CreateWithZeroMass){
    mass = 0;
    EXPECT_THROW(new CargoItem(id,mass,dimensions), std::invalid_argument);
}

TEST_F(CargoItemTest,CreateWithNegativeMass){
    mass = -1;
    EXPECT_THROW(new CargoItem(id,mass,dimensions), std::invalid_argument);
}


TEST_F(CargoItemTest,CreateWithMassThatExceedsLimit){
    mass = 200.1;
    EXPECT_THROW(new CargoItem(id,mass,dimensions), std::invalid_argument);
}

TEST_F(CargoItemTest,CreateWithZeroVolume){
    dimensions[0] = 0;
    EXPECT_THROW(new CargoItem(id,mass,dimensions), std::invalid_argument);
}

TEST_F(CargoItemTest,CreateWithNegativeVolume){
    dimensions[0] = -1;
    EXPECT_THROW(new CargoItem(id,mass,dimensions), std::invalid_argument);
}

TEST_F(CargoItemTest,CreateWithVolumeThatExceedsLimit){
    dimensions[0] = 1;
    dimensions[1] = 1;
    dimensions[2] = 2.1;
    EXPECT_THROW(new CargoItem(id,mass,dimensions), std::invalid_argument);
}

TEST_F(CargoItemTest,CheckIdIsRetained){
    auto cargoItem = std::make_unique<CargoItem>(id,mass,dimensions);
    EXPECT_EQ(cargoItem->getId(), id);
}

TEST_F(CargoItemTest,CheckMassIsRetained){
    auto cargoItem = std::make_unique<CargoItem>(id,mass,dimensions);
    EXPECT_EQ(cargoItem->getMass(), mass);
}

TEST_F(CargoItemTest,CheckVolumeIsRetained){
    auto cargoItem = std::make_unique<CargoItem>(id,mass,dimensions);
    EXPECT_EQ(cargoItem->getVolume(), dimensions[0]*dimensions[1]*dimensions[2]);
}
#include <gtest/gtest.h>
#include <memory>
#include "../src/Trolley.cpp"

class TrolleyTest : public ::testing::Test {
 public:
    std::unique_ptr<CargoItem> cargoItem;
    std::unique_ptr<Trolley> trolley;
    const float MAX_MASS = 2000;
 protected:
  void SetUp() override {
    std::vector<float> dimensions = {1,1,1};
    cargoItem = std::make_unique<CargoItem>(1,100,dimensions);
    trolley = std::make_unique<Trolley>();
  }
  void TearDown() override {}
};

TEST_F(TrolleyTest, AddItemAndCheckSpaceRemainingIsCorrect){
  trolley->add(cargoItem.get());
  EXPECT_EQ(trolley->getSpaceRemaining(), MAX_MASS-cargoItem->getMass());
}

TEST_F(TrolleyTest, AddsMultipleItemsAndCheckSpaceRemainingIsCorrect){
  const int iterations = 5;
  for(int i = 0; i < iterations; i++)
    trolley->add(cargoItem.get());
  EXPECT_EQ(trolley->getSpaceRemaining(), MAX_MASS-cargoItem->getMass()*iterations);
}

TEST_F(TrolleyTest, AddTooManyItemsSuchThatMaxMassIsExceeded){
  // Add 20x 100kg cargo items = 2000kg
  for(int i = 0; i < 20; i++)
    trolley->add(cargoItem.get());

  // Add one more
  EXPECT_THROW(trolley->add(cargoItem.get()), std::overflow_error);
}
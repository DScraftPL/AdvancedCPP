#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include <tuple>

bool zad2(int liczba) {
  if (liczba <= 1) {
    return false;
  }
  for (int i = 2; i < liczba; i++) {
    if (liczba % i == 0) {
      return false;
    }
  }
  return true;
}

float zad3(float liczba) {
  if (liczba == 0) {
    throw std::invalid_argument("zero");
  }
  return 1.0 / liczba;
}

class BankAccount {
private:
  std::string last_name;
  std::string account_number;
  int balance;

public:
  BankAccount(std::string _last_name, std::string _account_number, int _balance)
      : last_name(_last_name), account_number(_account_number),
        balance(_balance) {}
  void add(int number) { balance += number; }
  void withdraw(int number) { balance -= number; }
  bool isMillionaire() {
    if (balance >= 1000000) {
      return true;
    }
    return false;
  }
  void setLastName(std::string s) { last_name = s; }
  void setAccountNumber(std::string s) { account_number = s; }
  void setBalance(int b) { balance = b; }
  std::string getLastName() { return last_name; }
  std::string getAccountNumber() { return account_number; }
  int getBalance() { return balance; }
};

TEST(Zad2Test, Zadanie2) {
  EXPECT_FALSE(zad2(-1));
  EXPECT_FALSE(zad2(0));
  EXPECT_FALSE(zad2(1));
  EXPECT_TRUE(zad2(2));
  EXPECT_TRUE(zad2(3));
  EXPECT_FALSE(zad2(4));
  EXPECT_TRUE(zad2(5));
  EXPECT_TRUE(zad2(7));
  EXPECT_FALSE(zad2(9));
}

TEST(Zad3Test, Zadanie3) {
  EXPECT_FLOAT_EQ(zad3(1), 1);
  EXPECT_FLOAT_EQ(zad3(2), 0.5);
  EXPECT_FLOAT_EQ(zad3(4), 0.25);
  EXPECT_ANY_THROW(zad3(0));
  EXPECT_NO_THROW(zad3(6));
}

TEST(Zad4Test, MillionaireTest) {
  BankAccount account("Nowak", "002", 1);
  EXPECT_FALSE(account.isMillionaire());

  account.add(1000000.0);
  EXPECT_TRUE(account.isMillionaire());
}

TEST(Zad4Test, NegativeTest) {
  BankAccount account("Temp", "003", 0);
  EXPECT_EQ(account.getBalance(), 0);
  account.withdraw(5);
  EXPECT_LT(account.getBalance(), 0);
}

TEST(Zad4Test, NameTest) {
  BankAccount account("Nowak", "004", 100);
  EXPECT_EQ(account.getLastName(), "Nowak");
  account.setLastName("Kowalski");
  EXPECT_EQ(account.getLastName(), "Kowalski");
}

class Zad4TestParam : public testing::TestWithParam<std::tuple<int, bool>> {};

TEST_P(Zad4TestParam, ParametrTest) {
  int x = std::get<0>(GetParam());
  bool expect = std::get<1>(GetParam());
  BankAccount account("Kowalski", "005", x);
  EXPECT_EQ(account.isMillionaire(), expect);
}

INSTANTIATE_TEST_CASE_P(Zad4TestParam, Zad4TestParam,
                        testing::Values(std::make_tuple(10, false),
                                        std::make_tuple(1000000000, true)));

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

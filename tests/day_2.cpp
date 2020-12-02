#include <gtest/gtest.h>

#include "day_2.h"


TEST(day_2, test_day_2_main){
  int result = day_2_main("/code/tests/day_2_example.txt");
  ASSERT_EQ(result, 2);
}

struct Day2TestParams {
  std::string input_string;
  int policy_minimum;
  int policy_maximum;
  char policy_letter;
  std::string password_text;
};

class DayTwoParametrized :public ::testing::TestWithParam<Day2TestParams> {
};

TEST_P(DayTwoParametrized, test_generate_orders) {
  Day2TestParams test_params = GetParam();

  Password result = extract_password_from_string(test_params.input_string);

  ASSERT_EQ(result.policy.minimum, test_params.policy_minimum);
  ASSERT_EQ(result.policy.maximum, test_params.policy_maximum);
  ASSERT_EQ(result.policy.letter, test_params.policy_letter);
  ASSERT_EQ(result.text, test_params.password_text);
}


INSTANTIATE_TEST_SUITE_P(
  strategy,
  DayTwoParametrized,
  ::testing::Values(
      Day2TestParams {
        "1-3 a: abcde",
	1,
	3,
	'a',
	"abcde"
      },
      Day2TestParams {
        "1-3 b: cdefg",
	1,
	3,
	'b',
	"cdefg"
      },
      Day2TestParams {
        "2-9 c: ccccccccc",
	2,
	9,
	'c',
	"ccccccccc"
      },
      Day2TestParams {
        "7-13 j: tpscbbstbdjsjbtcpj",
	7,
	13,
	'j',
	"tpscbbstbdjsjbtcpj"
      }
  )
);


TEST(day_2, test_count_policy_letter_in_password_text){
  Policy policy = {1, 3, 'a'};
  Password password = {"abcdefga", policy};

  int letter_count = password.letter_count();

  ASSERT_EQ(letter_count, 2);
}


TEST(day_2, test_password_is_valid){
  std::string input_1 = "1-3 a: abcde";
  std::string input_2 = "1-3 b: cdefg";
  std::string input_3 = "2-9 c: ccccccccc";

  Password password_1 = extract_password_from_string(input_1);
  Password password_2 = extract_password_from_string(input_2);
  Password password_3 = extract_password_from_string(input_3);

  ASSERT_EQ(password_1.is_valid(), true);
  ASSERT_EQ(password_2.is_valid(), false);
  ASSERT_EQ(password_3.is_valid(), true);
}


TEST(day_2, test_load_strings_from_file){
  std::string file_path = "/code/tests/case_2.txt";
  std::vector<std::string> strings = load_strings_from_file(file_path);
  int num_strings = static_cast<int>(strings.size());

  ASSERT_EQ(num_strings, 2);
  ASSERT_EQ(strings[0], "1-3 a: abcde");
  ASSERT_EQ(strings[1], "1-3 a: hello");
}


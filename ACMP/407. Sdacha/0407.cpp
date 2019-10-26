/*

407. Sdacha

(Time limit: 1 sec. Memory limit: 16 MB Difficulty: 44%)

Когда Миша и Маша покупали подарок, возникла интересная ситуация. У них была в распоряжении только одна большая купюра, а у продавца – некоторое количество мелочи. Дело происходило утром, поэтому продавцу нужно было экономить мелочь, и он хотел отдать сдачу минимальным количеством монет. Подумав некоторое время, они точно определили, с каким количеством монет продавцу придется расстаться.

А вы сможете решить такую задачу?

Входные данные

В первой строке входного файла INPUT.TXT записано число N (1 ≤ N ≤ 10) – количество различных номиналов монет, содержащихся в кассе. Можно считать, что количество монет каждого номинала достаточно. На следующей строке содержится N целых чисел ai (0 < ai ≤ 2000) – номиналы монет. В третьей строке записано одно число K (1 ≤ K ≤ 106) – сумма, которую нужно набрать.

Выходные данные

В выходной файл OUTPUT.TXT выведите минимальное количество монет, которое придется отдать продавцу, или -1, если продавец вообще не сможет дать им сдачу.

*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>

const int int_max = std::numeric_limits<int>::max() - 100;

using namespace std;

int get_min_sum(std::vector<unsigned int>& coins, unsigned int sum) {
    std::vector<int> dp(sum + 1, int_max);

    dp[0] = 0;

    for (unsigned int i = 0; i < coins.size(); ++i) {
        for (unsigned int j = coins[i]; j <= sum; ++j) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    return dp[sum] == (int_max) ? -1 : dp[sum];
}

int main() {
    size_t count;
    std::cin >> count;

    std::vector<unsigned int> coins(count);

    for (unsigned int i = 0; i < count; ++i) {
        std::cin >> coins[i];
    }

    unsigned int sum;
    std::cin >> sum;

    std::cout << get_min_sum(coins, sum) << std::endl;

    return 0;
}

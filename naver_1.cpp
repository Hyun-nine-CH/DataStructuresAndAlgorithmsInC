#include <iostream>
#include <vector>
using namespace std;

// C++14에서는 std::gcd가 없으므로 직접 구현
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<long long> russian_roulette(const vector<int>& cylinder, long long a) {
    int n = cylinder.size();
    long long non_firing_count = 0;
    long long total_count = 0;

    for (int i = 0; i < n; ++i) {
        if (cylinder[i] == 0) {
            bool cant_fire = true;
            for (long long j = 0; j < a; ++j) {
                int next_index = (i + j + 1) % n;
                if (cylinder[next_index] == 1) {
                    cant_fire = false;
                    break;
                }
            }
            if (cant_fire) {
                non_firing_count++;
            }
            total_count++;
        }
    }

    if (non_firing_count == 0) {
        return {0, 1};
    }

    long long g = gcd(non_firing_count, total_count); // 여기서 사용자 정의 gcd 사용
    return {non_firing_count / g, total_count / g};
}

int main() {
    vector<int> cylinder = {1, 1, 0, 0, 0, 0};
    long long a = 2;

    vector<long long> result = russian_roulette(cylinder, a);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}

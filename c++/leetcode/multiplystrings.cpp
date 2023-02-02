#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();
    vector<int> result(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }
    string res = "";
    int i = 0;
    while (i < n1 + n2 && result[i] == 0) i++;
    while (i < n1 + n2) res += (result[i++] + '0');
    return res.empty() ? "0" : res;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2) << endl;
    return 0;
}

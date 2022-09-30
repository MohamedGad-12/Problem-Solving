#include <iostream>
#include <vector>
using namespace std;


int level = -1;
int add(int m) {
    if (m % 3 == 0) {
        return floor((m - 1) / 3);
    }
    else
    {
        return floor(m / 3);
    }
}
int coin_size(int n) {

    int size = 0; int m = n;

    for (int i = 0; i <= n; i++) {
        size = size + m;
        m--;
    }
    return size;
}

vector<vector<string>> insert(int n) {

    int sh = 1;
    vector<vector<string>>coin;

    for (int k = 0; k < (n); ++k) {
        vector<string> inner;
        for (int i = 0; i < (n); ++i) {
            inner.push_back("");
        }
        coin.push_back(inner);
    }
    for (int k = n; k < (2 * n); ++k) {
        vector<string> inner;
        for (int j = n; j <= (k); ++j) {
            inner.push_back("0");
        }
        for (int j = k + sh; j < (2 * n); ++j) {
            inner.push_back("");
        }
        coin.push_back(inner);
    }
    for (int k = 2 * n; k < (3 * n); ++k) {
        vector<string> inner;
        for (int i = 0; i < (n); ++i) {
            inner.push_back("");
        }
        coin.push_back(inner);
    }
    return coin;
}
vector<vector<string>> inverse(int n, int shift) {

    int sh = 0;
    vector<vector<string>>coin;

    for (int k = 0; k < (shift); ++k) {
        vector<string> inner;
        for (int j = 0; j < (n); ++j) {
            inner.push_back("");
        }
        coin.push_back(inner);
    }
    for (int k = ((n + shift)); k > (0 + shift); --k) {
        vector<string> inner;
        for (int i = (0); i < (k - shift); ++i) {
            inner.push_back("+");
        }
        for (int i = (k - shift); i < (k - shift + sh); ++i) {
            inner.push_back("");

        }
        coin.push_back(inner);
        sh++;
    }
    for (int k = (n + shift); k < (2 * n); ++k) {
        vector<string> inner;
        for (int j = 0; j < (n); ++j) {
            inner.push_back("");
        }
        coin.push_back(inner);
    }
    for (int k = (2 * n); k < (3 * n); ++k) {
        vector<string> inner;
        for (int i = 0; i < (n); ++i) {
            inner.push_back("");
        }
        coin.push_back(inner);
    }
    return coin;
}

int intersec(int n) {

    vector<vector<string>> a;   vector<vector<string>> b;
    string T = "";  int count = 0;  int check = coin_size(n);

    int s = 0;
    for (s; s <= (2 * n); s++) {
        a = insert(n);   b = inverse(n, s);
        for (int i = 0; i < (a.size()); i++) {
            for (int j = 0; j < a.at(i).size(); j++) {
                T = a.at(i).at(j) + b.at(i).at(j);
                if (T == "0") {
                    count++;
                }
            }
        }
        if (count <= check) {
            cout << count << " , ";
            check = count;
            count = 0;
            level++;
        }
        else {
            cout << "[" << count << "]" << "Break Here And Take The Previous Number." << endl;
            break;
        }
    }

    return check;
}
void print(int n) {

    vector<vector<string>> a;  vector<vector<string>> b;
    vector<string> z; string T = "";

    a = insert(n);   b = inverse(n, level);
    int str = add(n); int neg = str * -1;

    for (int i = level; i < (a.size()); i++) {
        for (int k = 0; k < str; k++) {
            z.push_back("0");
        }
        for (int j = 0; j < a.at(i).size(); j++) {
            T = a.at(i).at(j) + b.at(i).at(j);
            if (T == "0+") {
                T = "*";
                z.push_back(T);
            }
            if (T == "0") {
                T = "";
            }
            if (T == "+") {
                T = "0";
                neg++;
                if (neg > 0) {
                    z.push_back(T);
                }
            }
        }
        str--;     neg = -1 * str;
    }
    //cout << z.size() << endl;
    level = -1;
    int k, q;   int m = n;   int s = 0;  int mm = m;
    for (k = 0; k < n; k++) {
        for (int r = 0; r < (k); r++) {
            cout << " ";
        }
        for (q = s; q < mm; q++) {
            cout << " " << z.at(q) + "";
        }
        s = s + m;  m--;
        mm = mm + m;
        cout << endl;
    }
    cout << endl << "-> Symbol ""*""  Refer To The Detected intersection." << endl << endl;
    cout << "-> Symbol ""0""  Refer To The Min Number of Moved Coins." << endl << endl;
    cout << "............................. TEST END .............................." << endl << endl;
}

int main()
{
    while (1) {
        int n;
        cout << "-> Enter Number Coins: ";  cin >> n;
        cout << endl;
        cout << "-> The Improvement Sequance: ";
        if (n <= 0) {
            cout << "-> Can Not Accept Number Less Than Or Equal Zero." << endl <<endl;
            continue;
        }
        else {
            cout << endl << "-> Min Number of Moved Coins = " << intersec(n) << endl << endl;
            print(n);
        }
    }
}


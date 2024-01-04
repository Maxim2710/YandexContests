#include <iostream>
#include <string>

// Ваш код здесь

#include <vector>

std::vector<char> sum_vects(std::vector<char> a, std::vector<char> b) {
    int64_t size = std::max(a.size(), b.size());
    a.resize(size);
    b.resize(size);

    std::vector<char> res;
    char carry = 0;
    for (int64_t i = 0; i < a.size(); i++) {
        char cur_sum = a[i] + b[i] + carry;
        if (cur_sum > 9) {
            cur_sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res.push_back(cur_sum);
    }
    if (carry != 0) {
        res.push_back(carry);
    }
    return res;
}

std::vector<char> sub_vects(std::vector<char> a, std::vector<char> b) {
    int64_t size = std::max(a.size(), b.size());
    a.resize(size);
    b.resize(size);

    std::vector<char> res;
    char carry = 0;
    for (int64_t i = 0; i < a.size(); i++) {
        char cur_sum = a[i] - b[i] - carry;
        if (cur_sum < 0) {
            cur_sum += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res.push_back(cur_sum);
    }
    return res;
}

bool comp_vects(std::vector<char> a, std::vector<char> b, bool gt) {
    if (a.size() != b.size()) {
        if (gt) {
            return a.size() > b.size();
        } else {
            return a.size() < b.size();
        }
    }
    for (int64_t i = a.size() - 1; i >= 0; i--) {
        if ((gt && (a[i] > b[i])) || (!gt && (a[i] < b[i]))) {
            return true;
        } else if (a[i] == b[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

class Bigint {
public:
    bool negative;
    Bigint() {
        negative = false;
        num = {0};
    }
    Bigint(Bigint &a) {
        num = a.get_raw();
        negative = a.negative;
    }
    Bigint(std::string input) {
        negative = (input[0] == '-');
        for (const auto sym : input) {
            if (sym == '-') {
                continue;
            }
            num.insert(num.begin(), std::atoi(&sym));
        }
    }
    Bigint(int64_t input) {
        if (input == 0) {
            num = {0};
        } else {
            while (input > 0) {
                num.push_back(input % 10);
                input /= 10;
            }
        }
        negative = input < 0;
    }
    Bigint(std::vector<char> input, bool i_negative) {
        // Remove trailing zeroes
        if (input.size() > 1) {
            auto erase_cnt = 0;
            for (int64_t i = input.size() - 1; i >= 0; i--) {
                if (input[i] == 0) {
                    erase_cnt++;
                } else {
                    break;
                }
            }
            if (erase_cnt == input.size()) {
                erase_cnt--;
            }
            input.erase(input.end() - erase_cnt, input.end());
        }

        negative = (input.size() == 1 && input[0] == 0) ? false : i_negative;
        num = input;
    }

    std::vector<char> get_raw() const {
        return num;
    }

    Bigint abs() {
        Bigint temp = *this;
        temp.negative = false;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bigint& b) {
        auto raw = b.get_raw();
        if (b.negative && !(raw.size() == 1 && raw[0] == 0)) {
            out << '-';
        }
        for (std::vector<char>::reverse_iterator it = raw.rbegin(); it != raw.rend(); ++it) {
            out << std::to_string(*it);
        }
        return out;
    }

    friend bool operator<(const Bigint& a, const Bigint& b) {
        auto a_raw = a.get_raw();
        auto b_raw = b.get_raw();
        if (!a.negative && !b.negative) {
            return comp_vects(a_raw, b_raw, false);
        } else if (a.negative && b.negative) {
            return comp_vects(a_raw, b_raw, true);
        } else if (a.negative && !b.negative) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator>(const Bigint& a, const Bigint& b) {
        auto a_raw = a.get_raw();
        auto b_raw = b.get_raw();
        if (!a.negative && !b.negative) {
            return comp_vects(a_raw, b_raw, true);
        } else if (a.negative && b.negative) {
            return comp_vects(a_raw, b_raw, false);
        } else if (a.negative && !b.negative) {
            return false;
        } else {
            return true;
        }
    }
    friend bool operator==(const Bigint& a, const Bigint& b) {
        return a.negative == b.negative && a.get_raw() == b.get_raw();
    }
    friend bool operator>=(const Bigint& a, const Bigint& b) {
        return !(a < b);
    }
    friend bool operator<=(const Bigint& a, const Bigint& b) {
        return !(a > b);
    }

    Bigint operator+(Bigint b) {
        auto b_raw =  b.get_raw();
        if (negative && b.negative) {
            return Bigint(sum_vects(num, b_raw), true);
        } else if (!negative && !b.negative) {
            return Bigint(sum_vects(num, b_raw), false);
        } else {
            bool a_bigger = abs() > b.abs();
            if (a_bigger) {
                return Bigint(sub_vects(num, b_raw), negative);
            } else {
                return Bigint(sub_vects(b_raw, num), b.negative);
            }
        }
    }
    Bigint operator-(Bigint b) {
        auto b_raw = b.get_raw();
        if (negative && b.negative) {
            bool a_bigger = abs() > b.abs();
            if (a_bigger) {
                return Bigint(sub_vects(num, b_raw), negative);
            } else {
                return Bigint(sub_vects(b_raw, num), b.negative);
            }
        } else if (!negative && !b.negative) {
            bool a_bigger = abs() > b.abs();
            if (a_bigger) {
                return Bigint(sub_vects(num, b_raw), false);
            } else {
                return Bigint(sub_vects(b_raw, num), true);
            }
        } else {
            return Bigint(sum_vects(num, b_raw), negative);
        }
    }
    Bigint operator*(Bigint b) {
        auto b_raw = b.get_raw();
        char carry = 0;
        std::vector<char> res(num.size() + b_raw.size() + 1);
        for (int64_t b_idx = 0; b_idx < b_raw.size(); b_idx++) {
            int64_t res_idx = 0;
            for (int64_t i = 0; i < num.size(); i++) {
                res_idx = i + b_idx;
                char cur_sum = num[i] * b_raw[b_idx] + res[res_idx] + carry;
                if (cur_sum > 9) {
                    carry = cur_sum / 10;
                    cur_sum %= 10;
                } else {
                    carry = 0;
                }
                res[res_idx] = cur_sum;
            }
            if (carry != 0) {
                res[res_idx + 1] += carry;
                carry = 0;
            }
        }
        if (carry != 0) {
            res.push_back(carry);
        }
        return Bigint(res, negative != b.negative);
    }

    Bigint operator/(Bigint b) {
        std::vector<char> res(num.size());
        bool sign = negative != b.negative;
        negative = false;
        b.negative = false;

        auto b_raw = b.get_raw();
        int i, lgcat = 0, cc;
        int n = num.size(), m = b_raw.size();
        std::vector<char> cat(n, 0);
        Bigint t;
        for (i = n - 1; t * 10 + num[i] < b; i--){
            t = t * 10;
            t = t + num[i] ;
        }
        for (; i >= 0; i--){
            t = t * 10 + num[i];
            for (cc = 9; Bigint(cc) * b > t; cc--);
            t = t - Bigint(cc) * b;
            cat[lgcat++] = cc;
        }
        num.resize(cat.size());
        for (i = 0; i < lgcat;i++)
            num[i] = cat[lgcat - i - 1];

        num.resize(lgcat);
        negative = sign;
        return *this;

    }

private:
    std::vector<char> num;
};

int main() {
    std::string a, b;
    std::cin >> a >> b;

    Bigint first(a);
    Bigint second(b);

    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;
}

#include <iostream>
// recursion
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "knapsack.hpp"
using namespace std;

int sum_of_nums(vector<int> &v)
{
    if (v.size() == 1)
        return v[0];
    int tmp = v[v.size() - 1];
    v.pop_back();
    int res = sum_of_nums(v);
    return tmp + res;
}

int pow_of_num(int num, int num_of_times)
{
    if (num_of_times == 0)
        return 1;
    int res = pow_of_num(num, num_of_times - 1);
    return res * num;
}

int cnt_digits(int num)
{
    if (num == 0)
        return 0;
    int tmp = num / 10;
    int cnt = 1;
    int res = cnt_digits(tmp);
    return res + cnt;
}
void insert(vector<int> &v, int num)
{
    if ((v.size() == 0) || (v[v.size() - 1] <= num))
    {
        v.push_back(num);
        return;
    }
    int tmp = v[v.size() - 1];
    v.pop_back();
    insert(v, num);
    v.push_back(tmp);
}
void sort_an_array(vector<int> &v)
{
    //vector<int>res;
    if (v.size() == 1)
        return;

    int last_num = v[v.size() - 1];
    v.pop_back();
    sort_an_array(v);

    insert(v, last_num);
}

void print_subseq(string in, string op)
{
    if (in.size() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2 += in[0];
    in.erase(in.begin() + 0);
    print_subseq(in, op1);
    print_subseq(in, op2);
    return;
}

void permute(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << op << endl;
        return;
    }

    for (int i = 0; i < ip.length(); i++)
    {
        string op1 = op;
        op1.push_back(ip[i]);
        string ip1 = ip.substr(0, i) + ip.substr(i + 1, ip.size());
        permute(ip1, op1);
    }
}

void removeConsecutiveDupl(string ip, string op)

{
    if (ip.size() == 0)
    {
        cout << op << endl;
        return;
    }
    if (op.size() == 0)
    {
        op.push_back(ip[0]);
    }
    if (ip[0] != op[op.size() - 1])
    {
        op.push_back(ip[0]);
    }
    ip.erase(ip.begin() + 0);
    removeConsecutiveDupl(ip, op);
}

int calc_zeros(int num, int &cnt)
{
    if (num == 0)
    {
        return 0;
    }
    bool last_num = (num % 10 == 0);
    int res = calc_zeros(num / 10, cnt);
    return res + last_num;
}

bool check_sorted(vector<int> &v)
{
    if (v.size() == 1)
    {
        return true;
    }
    int temp = v[v.size() - 1];
    v.pop_back();

    int temp1 = v[v.size() - 1];
    v.pop_back();

    if (temp > temp1)
    {
        return true;
    }
    else
    {
        return false;
    }
    return check_sorted(v);
    //cout << "tmp res is " << res << endl;
}

void middle_elem(vector<int> &v, int k)
{
    cout << "value of k is " << k << endl;
    if (k == 0)
    {
        cout << "Middle element is " << v[v.size() - 1] << endl;
        return;
    }

    int temp = v[v.size() - 1];
    v.pop_back();
    middle_elem(v, k - 1);
    return;
}

void helper_reverse_array(vector<int> &v, int item)
{
    if (v.size() == 0 || v[v.size() - 1] <= item)
    {
        v.push_back(item);
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    helper_reverse_array(v, item);
    v.push_back(temp);
    return;
}
void reverse_array(vector<int> &v)
{
    if (v.size() == 1)
    {

        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    reverse_array(v);
    helper_reverse_array(v, temp);

    return;
}

void generate_substring(string s, string op)
{
    if (s.size() == 0)
    {
        cout << "Generate SS is " << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(s[0]);
    s.erase(s.begin() + 0);
    generate_substring(s, op1);
    generate_substring(s, op2);
    return;
}

bool check_palindrome(vector<int> &v, int begin, int end)
{
    if (v.size() == 1 || begin >= end)
    {
        return true;
    }
    cout << v[begin] << "--- " << v[end] << endl;

    if (v[begin] != v[end])
    {
        return false;
    }
    return check_palindrome(v, begin + 1, end - 1);
}
int dp[100][100];
int knapsack(vector<int> &w, vector<int> &v, int W)
{
    if (w.size() == 0 || v.size() == 0)
    {
        //op+0;
        return 0;
    }
    if (dp[v.size()][w.size()] != -1)
    {
        return dp[v.size()][w.size()];
    }
    int temp_wt = w[w.size() - 1];
    int temp_val = v[v.size() - 1];
    v.pop_back();
    w.pop_back();

    if (temp_wt <= W)
    {
        // 2options
        // 1 take it

        return dp[v.size()][w.size()] = std::max(knapsack(w, v, W - temp_wt) + temp_val,
                                                 knapsack(w, v, W));
    }
    else
    {
        return dp[v.size()][w.size()] = knapsack(w, v, W);
    }
}

// void do_stuff(vector<int>&v, int temp)
// {
//     if(v.size()==0)
//     {
//     v.push_back(temp);
//     return;
//     }
//     int temp1 = v[v.size()-1];
//     v.pop_back();
//     do_stuff(v,temp1);
//     v.push_back(temp1);
// }
void reverse_an_array(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    reverse_an_array(v);
    v.insert(v.begin(), temp);
}

bool palindrome(vector<int> &v, int begin, int end)
{
    if (v.size() == 1 || begin >= end)
    {
        return true;
    }
    if (v[begin] != v[end])
    {
        return false;
    }
    return palindrome(v, begin + 1, end - 1);
}

bool subset_sum(vector<int> v, int W)
{
    if (W == 0)
    {
        return true;
    }
    if (v.size() == 0 && W != 0)
    {
        return false;
    }

    int temp_wt = v[v.size() - 1];
    v.pop_back();
    if (temp_wt <= W)
    {
        return subset_sum(v, W - temp_wt) || subset_sum(v, W);
    }
    if (temp_wt > W)
    {
        return subset_sum(v, W);
    }
}

int knapsack_cg(vector<int> w, vector<int> v, int W)
{
    if (w.size() == 0 || v.size() == 0 || W == 0)
    {

        return 0;
    }

    // cout<< "weight "<< W << "size "<< v.size() << endl;

    int temp_wt = w[w.size() - 1];
    int temp_val = v[v.size() - 1];
    v.pop_back();
    w.pop_back();

    if (temp_wt <= W)
    {
        // 2options
        // 1 take it

        return std::max(knapsack_cg(w, v, W - temp_wt) + temp_val,
                        knapsack_cg(w, v, W));
    }
    else
    {
        return knapsack_cg(w, v, W);
    }
}

bool two_subset_eq(vector<int> v, int W)
{
    //cout << "Elemsnts size "<< v.size()<< " " << W << endl;
    if (W == 0)
    {
        return true;
    }
    if (v.size() == 0 && W > 0)
    {
        return false;
    }
    int temp_wt = v[v.size() - 1];
    v.pop_back();
    if (temp_wt <= W)
    {
        // 2 optinons take it or leave it
        return two_subset_eq(v, W - temp_wt) || two_subset_eq(v, W);
    }

    if (temp_wt > W)
    {
        // only 1 option
        return two_subset_eq(v, W);
    }
}

int main()
{
    vector<int> v{500, 200, 30};
    memset(dp, -1, sizeof(dp));
    //int res = sum_of_nums(v);
    //int res = pow_of_num(3, 3);

    //    int res= cnt_digits(12);
    //    reverse_an_array(v);
    //    for(int i :v)
    //    {
    //        cout << i<< endl;
    //    }

    //     cout << "test123"
    //          << " " << res << endl;

    // print_subseq("abcd", "");
    // int cnt =0;
    // int k = (v.size()/2)+1;
    // int fend = v.size()-k;
    // cout << "value of k and fend is " << k << " " << fend << endl;
    // middle_elem(v,fend);
    // reverse_array(v);
    // for(int i:v)
    // {
    //     cout << "Array element" << i << endl;
    // }
    //generate_substring("abc", "");
    // vector<int>v1{1,3,2,2,3,1};
    // cout << "palindrome res is "<< check_palindrome(v1,0,v1.size()-1);

    // reverse_an_array(v);
    // for(int i :v)
    // {
    //     cout << "frames are " << i << endl;
    // }

    //  vector<int> v1{1, 3, 2, 2, 3, 1};
    // cout << "palindrome res is "<< palindrome(v1,0,v1.size()-1);
    permute("ABCD", "");

    // vector<int>p{60, 100, 120};
    // vector<int>wt{10, 20, 30};
    // int W = 50;
    // cout << "knapsack res is " << knapsack_prob(wt,p, W)<< endl;
    vector<int> val{60, 100, 120};
    vector<int> wt{10, 20, 30};
    cout << knapsack_cg(wt, val, 50) << endl;

    vector<int> s{3, 1, 5, 9, 12};
    int sum = 24;
    cout << subset_sum(s, sum) << endl;

    vector<int> eq{3, 1, 1, 5, 9, 15};
    int sum_of_elems = 0;
    std::for_each(eq.begin(), eq.end(), [&](int n) {
        sum_of_elems += n;
    });

    if ((sum_of_elems % 2) == 0)
    {
        cout << "two eq sume " << two_subset_eq(eq, sum_of_elems / 2) << endl;
    }

    knapsack_call_from_main();

        return 0;
}
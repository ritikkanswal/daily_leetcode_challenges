class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        char buff;
        stringstream sso1(num1),sso2(num2),res;
        int r_num1,i_num1,r_num2,i_num2;
        sso1>>r_num1>>buff>>i_num1>>buff;
        sso2>>r_num2>>buff>>i_num2>>buff;
        res<<(r_num1*r_num2)-(i_num1*i_num2)<<"+"<<(i_num1*r_num2+r_num1*i_num2)<<"i";
        return res.str();
    }
};
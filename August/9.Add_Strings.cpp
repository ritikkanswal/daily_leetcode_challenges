class Solution {
public:
    string addStrings(string num1, string num2) {

       reverse(num1.begin(),num1.end());
       reverse(num2.begin(),num2.end());
       int i=0,j=0;
       int sum=0;
       string res;
       int carry=0;

       while(i<num1.size() and j<num2.size())
       {
           res+=(num1[i]-'0'+num2[j]-'0'+carry)%10+'0';
           carry=(num1[i]-'0'+num2[j]-'0'+carry)/10;
           i++,j++;
       }
       while(i<num1.size())
       {
           res+=(num1[i]-'0'+carry)%10+'0';
           carry=(num1[i]-'0'+carry)/10;
           i++;
       }
       while(j<num2.size())
       {
           res+=(num2[j]-'0'+carry)%10+'0';
           carry=(num2[j]-'0'+carry)/10;
           j++;
       }
       if(carry)
            res+=carry+'0';
       reverse(res.begin(),res.end());
       return res;
    }
};
        
class Solution {
public:
    string intToRoman(int num) {
        vector<int> val(13);
        vector<string> sym(13);
        val[0] = 1000,  sym[0]="M";
        val[1] = 900,   sym[1]="CM";
        val[2] = 500,   sym[2]="D";
        val[3] = 400,   sym[3]="CD";
        val[4] = 100,   sym[4]="C";
        val[5] = 90,    sym[5]="XC";
        val[6] = 50,    sym[6]="L";
        val[7] = 40,    sym[7]="XL";
        val[8] = 10,    sym[8]="X";
        val[9] = 9,     sym[9]="IX";
        val[10] = 5,    sym[10]="V";
        val[11] = 4,    sym[11]="IV";
        val[12] = 1,    sym[12]="I"; 

        string result = "";
        for(int i=0; i<13; i++){
            if(num==0){
                break;
            }
            int times = num/val[i];
            while(times--){
                result += sym[i];
            }
            num = num%val[i];
        }
        return result;
    }
};
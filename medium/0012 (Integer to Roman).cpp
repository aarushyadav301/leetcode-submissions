class Solution {
public:
    string intToRoman(int num) {

        string roman = "";

        while (num > 0) {
            if (num >= 1000) {
                roman += "M";
                num -= 1000;
                continue;
            }

            if (num >= 900) {
                roman += "CM";
                num -= 900;
                continue;
            }

            if (num >= 500) {
                roman += "D";
                num -= 500;
                continue;
            }

            if (num >= 400) {
                roman += "CD";
                num -= 400;
                continue;
            }

            if (num >= 100) {
                roman += "C";
                num -= 100;
                continue;
            }

            if (num >= 90) {
                roman += "XC";
                num -= 90;
                continue;
            }

            if (num >= 50) {
                roman += "L";
                num -= 50;
                continue;
            }

            if (num >= 40) {
                roman += "XL";
                num -= 40;
                continue;
            }

            if (num >= 10) {
                roman += "X";
                num -= 10;
                continue;
            }

            if (num >= 9) {
                roman += "IX";
                num -= 9;
            } 

            if (num >= 5) {
                roman += "V";
                num -= 5;
                continue;
            }

            if (num >= 4) {
                roman += "IV";
                num -= 4;
            }

            if (num >= 1) {
                roman += "I";
                num--;
                continue;
            }
        }

        return (roman);
    }
};
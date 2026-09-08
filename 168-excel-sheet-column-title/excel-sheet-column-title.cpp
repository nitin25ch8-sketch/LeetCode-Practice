class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";

        while (columnNumber > 0) {
            columnNumber--;

            int r = columnNumber % 26;

            title += char(r + 'A');

            columnNumber /= 26;
        }

        reverse(title.begin(), title.end());

        return title;
    }
};
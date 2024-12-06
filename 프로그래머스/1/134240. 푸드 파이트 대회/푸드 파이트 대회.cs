using System;
using System.Text;

public class Solution {
    public string solution(int[] food) {
        
            var sb = new StringBuilder("0");

            for (var i = food.Length - 1; i > 0; i--)
            {
                var repeatCnt = food[i] / 2;
                if (repeatCnt > 0)
                {
                    var fStr = i.ToString();
                    var fChar = fStr[0];
                    sb.Insert(0, i.ToString(), repeatCnt).Append(fChar, repeatCnt);
                }
            }

            return sb.ToString();
    }
}
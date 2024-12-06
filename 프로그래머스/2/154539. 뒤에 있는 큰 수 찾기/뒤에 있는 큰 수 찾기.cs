using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        
            var idxStack = new Stack<int>();

            for (var i = 0; i < numbers.Length; ++i)
            {
                while (idxStack.Count > 0 && numbers[idxStack.Peek()] < numbers[i])
                {
                    numbers[idxStack.Pop()] = numbers[i];
                }

                idxStack.Push(i);
            }

            while (idxStack.TryPop(out var idx))
            {
                numbers[idx] = -1;
            }

            return numbers;
    }
}
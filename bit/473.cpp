//find two non repeating elements

// Let us see an example.
//    arr[] = {2, 4, 7, 9, 2, 4}
// 1) Get the XOR of all the elements.
//      xor = 2^4^7^9^2^4 = 14 (1110)
// 2) Get a number which has only one set bit of the xor.
//    Since we can easily get the rightmost set bit, let us use it.
//      set_bit_no = xor & ~(xor-1) = (1110) & ~(1101) = 0010
//    Now set_bit_no will have only set as rightmost set bit of xor.
// 3) Now divide the elements in two sets and do xor of
//    elements in each set and we get the non-repeating
//    elements 7 and 9. Please see the implementation for this step.

vector<int> singleNumber(vector<int> arr)
{
   int n = arr.size();
   int Xor = arr[0];

   /* Will have only single set bit of Xor */
   int set_bit_no;
   int i;
   int x = 0;
   int y = 0;

   /* Get the Xor of all elements */
   for (i = 1; i < n; i++)
      Xor ^= arr[i];

   /* Get the rightmost set bit in set_bit_no */
   set_bit_no = Xor & ~(Xor - 1);

   /* Now divide elements in two sets by
   comparing rightmost set bit of Xor with bit
   at same position in each element. */
   for (i = 0; i < n; i++) {

      /*Xor of first set */
      if (arr[i] & set_bit_no)
         x = x ^ arr[i];
      /*Xor of second set*/
      else {
         y = y ^ arr[i];
      }
   }
   vector<int> ans;
   if (x > y)
      return {y, x};
   return {x, y};
}
//
//  One Edit Distance.h
//  leetcodeInXcode
//
//  Created by Kaiqi on 7/28/15.
//  Copyright © 2015 edu.self. All rights reserved.
//

#ifndef One_Edit_Distance_h
#define One_Edit_Distance_h

class Solution {
public:
  bool oneEditDistance(string a, string b) {
      int i = 0, j = a.length() - 1;
      int p = 0, q = b.length() - 1;
      while (i < j && p < q && a[i] == b[p]) {
          i++, p++;
      }
      i--, p--;
      
      while (i < j && p < q && a[j] == b[q]) {
          j--, q--;
      }
      j++, q++;
      
      return (j - i <= 2 && q - p <= 2);
  }
};

#endif /* One_Edit_Distance_h */

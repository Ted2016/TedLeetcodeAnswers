
   int* twoSum(int* nums, int numsSize, int target) { 
         int    i, j; 
         int*   ret; 
         ret = (int*)malloc(2*sizeof(int)); 
         for(i = 0; i < numsSize; i++) {
          for(j = i + 1; j < numsSize; j++) { 
               if((nums[i] + nums[j]) == target) { 
                   *ret = i + 1; 
                   *(ret + 1) = j + 1; 
                   return ret; 
              } 
           } 
        }
       return NULL; 
   }

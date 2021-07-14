# the algo is called MOORE'S VOTING ALGORITHM

def majorityElement(A, N):
    candidate = A[0]
    count=1
    for i in range(len(A)):
        
        if(A[i]==candidate):
            count += 1;
        else:
            count -= 1;
        
        if(count == 0):
            candidate = A[i]
            count = 1
            continue
    
    res = -1
    
    #checking if the candidate is the majority or not
    count = 0
    for num in A:
        if(num == candidate):
            count += 1
    
    if(count > N/2):
        res = candidate
        
    return res


if __name__ == "__main__":
  arr = [3,1,3,1,3,5,3,3]
  res = majorityElement(arr,8)
  print(res)

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    vector<int> unionArr;
    int i = 0, j = 0;
    int n1 = a.size(), n2 = b.size();
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            // unionArr.size() == 0 -> without checking this, it was giving error because we have not inserted anything in the
            // array and we are checking its back().
            // unionArr.back() != a[i] -> this condition is for removing duplicate elements from final result.
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    // if some elements is left in the 'a' array.
    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    // if some elements is left in the 'b' array.
    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}

// TC = O(m+n).
// 2nd solutioin, we can use set.(ordered set so that the keys will be in ascending order).
// In that case, time complexity will be O((m+n)log(m+n))

// SC = O(m+n)
// we are not using extra space for our algorithm, we are using extra space for returing answer.


    


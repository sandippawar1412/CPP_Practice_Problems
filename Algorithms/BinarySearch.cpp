
#include <bits/stdc++.h>
using namespace std;

// ---------------------
/*
Array Type:Sorted with duplicates
---------------------------------
bS_Regular:    Regular Binary Search, will return index of found element, else -1;
bS_UpperBound: Return index 1 more than last occurence, if ele not there,
               it returns its correct positon in array
bS_LowerBound: Return index of first occurence, if ele not there,
               it returns its correct positon in array
All 3 searches will return same index if ele is not there
*/

int bS_Regualr(vector<int> &A, int l, int h, int &target)
{
    if (l > h)
        return -1;           // if retured l, its correct position of ele in array
    int m = l + (h - l) / 2; //(h-l+1)/2->ceil value

    if (A[m] == target)
        return m;
    if (A[m] < target)
        return bS_Regualr(A, m + 1, h, target);
    return bS_Regualr(A, l, m - 1, target);
}

int bS_UpperBound(vector<int> &A, int l, int h, int &target)
{
    if (l > h)
        return l; //returns position 1 ahead of last occurence

    int m = l + (h - l) / 2;

    if (target >= A[m])
        return bS_UpperBound(A, m + 1, h, target);
    return bS_UpperBound(A, l, m - 1, target);
}

int bS_LowerBound(vector<int> &A, int l, int h, int &target)
{
    if (l > h)
        return l; //returns the position of first occurence

    int m = l + (h - l) / 2;

    if (target <= A[m])
        return bS_LowerBound(A, l, m - 1, target);
    return bS_LowerBound(A, m + 1, h, target);
}

int main1(int argc, char **argv)
{
    vector<int> A{1, 2, 3, 4, 4, 5, 5, 5, 6, 6, 8, 8, 9};
    int B = 5;
    if (argc > 1)
        B = atoi(argv[1]);

    cout << "Array Size : " << A.size() << endl;
    cout << "Index of<Regular> " << B << ":" << bS_Regualr(A, 0, A.size() - 1, B) << endl;
    cout << "Index of<Upper B> " << B << ":" << bS_UpperBound(A, 0, A.size() - 1, B) << endl;
    cout << "Index of<Lower B> " << B << ":" << bS_LowerBound(A, 0, A.size() - 1, B) << endl;
    cout << "Element: " << B << " Appearance count: " << bS_UpperBound(A, 0, A.size() - 1, B) - bS_LowerBound(A, 0, A.size() - 1, B) << endl;

    return 0;
}
// -----------------------------------

/*
Array Type: Rotated Sorted Array
--------------------------
Rotate Array
https://leetcode.com/problems/rotate-array/

<No Duplicates>
bS_Regualr_R        : Regular Binary Search on Rotated Sorted Array, returns index
<distinct> https://leetcode.com/problems/search-in-rotated-sorted-array
<duplicates> https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

<No Duplicates>
bS_MaximumElement_R : Finding max element in rotated array with no duplicates

<No Duplicates>
bS_MinimumElement_R : Finding min element in rotated array with no duplicates
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

<Works with duplicates>
bS_MinimumElementDup_R: Finding min element in rotated array, there might be duplicates
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii


normally in searches, seperated out == case and go search on both side
*/
int bS_Regualr_R(vector<int> &A, int l, int h, int &target)
{
    if (l > h)
        return -1;           // retured l, doesn't gurantee its correct position
    int m = l + (h - l) / 2; //(h-l+1)/2->ceil value

    if (A[m] == target)
        return m;
    /*
     * if A[m] is >= A[l] && taget in between them or
     *    A[m] is < A[l]  && target is not in between A[m] && A[h]
     */
    if (A[m] >= A[l] && target >= A[l] && target < A[m] ||   // l..m is valid, increasing
        (A[m] < A[l] && !(target > A[m] && target <= A[h]))) // m..h is valid, increasing
        return bS_Regualr_R(A, l, m - 1, target);
    //else
    return bS_Regualr_R(A, m + 1, h, target);
}

bool bS_RegualrDup_R(vector<int> &A, int B, int l, int h)
{
    if (l > h)
        return false;
    int m = (l + h) / 2;

    if (A[m] == B)
        return true;

    if (A[m] > A[l] && B >= A[l] && B < A[m] ||    // l..m is valid, increasing
        (A[m] < A[l] && !(B > A[m] && B <= A[h]))) // m..h is valid, increasing
        return bS_RegualrDup_R(A, B, l, m - 1);
    else if (A[m] < A[l])
        return bS_RegualrDup_R(A, B, m + 1, h);
    else
        return bS_RegualrDup_R(A, B, l, m - 1) || bS_RegualrDup_R(A, B, m + 1, h);
}

// Return index of maximum element of rotated array-Pivot
int bS_MaximumElement_R(vector<int> &A, int l, int h)
{
    if (l > h)
        return h; // returning l, will return +1 index of ele if array is not rotated

    int m = (l + h) / 2;

    if (m < h && A[m] > A[m + 1]) // [5,6,7,1,2] m->7, h->1/2
        return m;
    if (l < m && A[m - 1] > A[m]) // [5,6,7,1,2] l->5/6/7, m->1
        return m - 1;

    if (A[l] > A[m])
        return bS_MaximumElement_R(A, l, m - 1);
    return bS_MaximumElement_R(A, m + 1, h);
}

int bS_MinimumElement_R(vector<int> &A, int l, int h)
{
    if (l > h)
        return l;

    int m = (l + h) / 2;

    if (m < h && A[m] > A[m + 1]) // [5,6,7,1,2] m->7, h->1/2
        return m + 1;
    if (l < m && A[m - 1] > A[m]) // [5,6,7,1,2] l->5/6/7, m->1
        return m;

    if (A[h] < A[m])
        return bS_MinimumElement_R(A, m + 1, h);
    return bS_MinimumElement_R(A, l, m - 1);
}

//To Support duplicates in array
int bS_MinimumElementDup_R(vector<int> &A, int l, int h)
{
    if (l > h)
        return l;

    int m = (l + h) / 2;

    if (m < h && A[m] > A[m + 1]) // [5,6,7,1,2] m->7, h->1/2
        return m + 1;
    if (l < m && A[m - 1] > A[m]) // [5,6,7,1,2] l->5/6/7, m->1
        return m;

    if (m != h && A[h] == A[m])
    {
        int i1 = bS_MinimumElementDup_R(A, m + 1, h);
        int i2 = bS_MinimumElementDup_R(A, l, m - 1);
        if (A[i1] < A[i2])
            return i1;
        return i2;
    }

    if (A[h] < A[m])
        return bS_MinimumElementDup_R(A, m + 1, h);
    return bS_MinimumElementDup_R(A, l, m - 1);
}

// -------------------------------------

int main2(int argc, char **argv)
{
    // vector<int> A{1,2,3,4,4,5,5,5,6,6,8,8,9};
    // vector<int> A{1, 2, 3, 4, 5};
    vector<int> A{5, 6, 7, 1};
    // vector<int> A{5, 0, 0, 1, 3};

    int B = 5;
    if (argc > 1)
        B = atoi(argv[1]);

    cout << "Array Size : " << A.size() << endl;
    cout << "Index of<Regular> " << B << " : " << bS_Regualr_R(A, 0, A.size() - 1, B) << endl;
    cout << "Index of max element : " << bS_MaximumElement_R(A, 0, A.size() - 1) << endl;
    cout << "Index of min element : " << bS_MinimumElement_R(A, 0, A.size() - 1) << endl;
    return 0;
}

int main(int argc, char **argv)
{
    // main1(argc, argv);
    main2(argc, argv);
}
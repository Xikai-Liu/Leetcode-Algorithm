class Solution {
public:
    int Subsearch(vector<int>& A,int low,int high,int key){
        while (low<=high){
            int mid=low+(high-low)/2;
            if (key==A[mid]) return mid;
            if (key>A[mid]) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    double Search(vector<int>& A, vector<int>& B,int lA, int hA, int lB, int hB){
        int mid=lA+(hA-lA)/2;
        int m=A.size(); int n=B.size();
        int pos=Subsearch(B,lB,hB,A[mid]);
        int num=mid+pos;
        if (num==((m+n)/2)){
            if ((m+n)%2==1) return A[mid];
            int next1; 
            if (mid>0 && pos>0) next1=A[mid-1]>B[pos-1]?A[mid-1]:B[pos-1];
            else if (pos>0) next1=B[pos-1];
            else if (mid>0) next1=A[mid-1];
            return (A[mid]+next1)/2.0;
        }
        if (num<(m+n)/2){
            int llA=mid+1; int llB=pos;
            if (hA-llA>hB-llB) return Search(A,B,llA,hA,llB,hB);
            else return Search(B,A,llB,hB,llA,hA);
        }
        if (num>(m+n)/2){
            int hhA=mid-1; int hhB=pos-1;
            if (hhA-lA>hhB-lB) return Search(A,B,lA,hhA,lB,hhB);
            else return Search(B,A,lB,hhB,lA,hhA);
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); int n=nums2.size();
        if (m==0){
            if (n%2==0) return ((nums2[n/2-1]+nums2[(n/2)])/2.0);
            else return nums2[n/2];     
        }
        if (n==0){
            if (m%2==0) return ((nums1[m/2-1]+nums1[(m/2)])/2.0);
            else return nums1[m/2];
        }
        if (m>n){
            return Search(nums1,nums2,0,m-1,0,n-1);
        }
        else return Search(nums2,nums1,0,n-1,0,m-1);
    }
};
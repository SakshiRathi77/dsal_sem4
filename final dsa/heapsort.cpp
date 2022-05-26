#include<iostream>
using namespace std;
class heap{
    int arr[25];
    
    public:
    int n;
    heap(){
        cout<<"enter the value of n\t";
        cin>>n;
        for (int i=0;i<n;i++){
            arr[i]=0;
        }
    }
    void takeinput(){
         for (int i=0;i<n;i++){
             int a;
             cout<<"enter data :"<<endl;
             cin>>a;
            arr[i]=a;
            cout<<endl;

        }
    }
    void heapify(int arr[],int n,int root){
        int mini=root;
        int l=2*mini+1;
        int r=2*mini+2;
        if(l<n && arr[l]<arr[mini]){
            mini=l;
        }
        if(r<n&& arr[r]<arr[mini]){
            mini=r;
        }
        if(mini!=root){
            int temp=arr[root];
            arr[root]=arr[mini];
            arr[mini]=temp;
            heapify(arr,n,mini);
        }
    }
    void heapsort(){
        for(int i=n;i>=0;i--){
            heapify(arr, n,i);}
        for(int i=n-1;i>=0;i--){
          cout<<arr[0]<<" ";
          int temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
			heapify(arr,i,0);  

        }
        }
    
};
int main() {
	heap h;
	h.takeinput();
	
	h.heapsort();
	return 0;
}
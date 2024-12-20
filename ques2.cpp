#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout<<"\nenter size of array ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the values ";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    for(int i=3;i<n;i++){
        cout<<"index = "<<i<<" value = "<<arr[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"value = "<<arr[i]<<" reference = "<<&arr[i]<<endl;
    }
    
    vector<int> ans;
    cout<<"enter values of vector 0 to exit ";
    int nv;
    cin>>nv;
    ans.push_back(nv);
    while(nv!=0){
        
    cin>>nv;
    if(nv==0){
        break;
    }
    ans.push_back(nv);
    }
    cout<<"values \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}